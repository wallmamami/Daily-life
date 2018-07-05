#include <netinet/in.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX 128

void serviceIO(int epfd, struct epoll_event* revs, int size, int listen_sock)
{
    int i = 0;
    struct epoll_event ev;
    for(; i < size; i++)
    {
        int fd = revs[i].data.fd;
        if(revs[i].events & EPOLLIN)//关心读事件
        {
            if(fd == listen_sock)//accept
            {
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                
                int new_sock = accept(fd, (struct sockaddr*)&client, &len);
                if(new_sock < 0)
                {
                    perror("accept");
                    continue;
                }

                printf("get a new client[%s:%d]", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
                //将新连接添加到红黑树当中
                ev.events = EPOLLIN;
                ev.data.fd = new_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, new_sock, &ev);

            }
            else//常规文件描述符--read
            {
                char buf[1024];
                ssize_t s = read(fd, buf, sizeof(buf)-1);
                if(s > 0)
                {
                    buf[s] = 0;
                    printf("client# %s\n", buf);

                    //读完之后再将事件修改为EPOLLOUT，表示不再关心这个文件描述符
                    //的读事件，而是关心写事件，效果就是客户端发一条消息，服务器回显
                    ev.events = EPOLLOUT;
                    ev.data.fd = fd;
                    epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
                }
                else if(s == 0)
                {
                    printf("client quit\n");
                    close(fd);

                    //将该“节点”从红黑树中删除
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                }
                else
                {
                    perror("read");
                    close(fd);

                    //将该“节点”从红黑树中删除
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                }
            }
        }
        
        if(revs[i].events & EPOLLOUT)//写事件就绪，这里不要写else if，因为有可能读和写都关心
        {
            const char* msg = "HTTP/1.0 200 OK\r\n\r\n<html><h1>EPOLL SUCCESS:)</h1></html>\r\n";
            write(fd, msg, strlen(msg));

            //写完关闭连接，并从红黑树中将该“节点”删除
            close(fd);
            epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
        }
    }
}


int startup(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    //绑定网络信息
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind");
        exit(3);
    }

    if(listen(sock, 5) < 0)
    {
        perror("listen");
        exit(4);
    }

    return sock;
}

//./epoll_server 9999
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    int listen_sock = startup(atoi(argv[1]));

    //创建epoll模型
    //>>在内核中创建空的红黑树
    //>>创建啊就绪队列
    //>>建立回调机制
    int epfd = epoll_create(256);
    if(epfd < 0)
    {
        perror("epoll_create");
        exit(5);
    }

    struct epoll_event ev;
    ev.events = EPOLLIN;//读事件
    ev.data.fd = listen_sock;

    //首先，将listen_sock添加到红黑树当中(红黑树中的节点表示关心那些文件描述符的那些事件)
    epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev);

    struct epoll_event revs[MAX];//用来保存内核返回的就绪事件
    int size = 0;//用来保存放回的就绪事件的个数

    while(1)
    {
        switch((size = epoll_wait(epfd, revs, MAX-1, -1)))
        {
        case -1:
            perror("epoll_wait");
            break;
        case 0:
            printf("timeout....\n");
            break;
        default:
            serviceIO(epfd, revs, size, listen_sock);
            break;
        }
    }
}

