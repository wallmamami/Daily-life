#include <string.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX 128

static void SetNonBlock(int fd)
{
    //获取文件描述符状态
    int fl = fcntl(fd, F_GETFL);
    if(fl < 0)
    {
        perror("fcntl");
        return;
    }

    //将当前文件描述符设置为非阻塞
    fcntl(fd, F_SETFL, O_NONBLOCK | fl);
}

int startup(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }
    //解决服务器主动断开连接造成time_wait问题而不能立即绑定端口号
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    //将该文件描述符设置为非阻塞状态
    SetNonBlock(sock);

    //设置网络信息
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

static my_accept(int fd, int epfd)
{
    struct epoll_event ev;
    do
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);

        int new_sock = accept(fd, (struct sockaddr*)&client, &len);//因为已经将listen_sock设置为非阻塞模式，所以这里连接完之后不会“卡”在这里
        if(new_sock < 0)
        {
            break;
        }

        printf("get a new client [%s:%d]\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        //将新连接设置为ET模式，并添加到红黑树当中
        ev.events = EPOLLIN | EPOLLET;
        ev.data.fd = fd;
        epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);

    }while(1);
}

static my_read(int fd, char* buf, int size)
{
    int total = 0;
    ssize_t s = 0;
    while((s = read(fd, buf, size-total)) > 0)
    {
        total += s;
    }

    return total;
}

static serviceIO(int epfd, struct epoll_event* recvs, int size, int listen_sock)
{
    int i = 0;
    struct epoll_event ev;
    for(; i < size; i++)
    {
        int fd = recvs[i].data.fd;
        if(recvs[i].events & EPOLLIN)//read
        {
            if(fd == listen_sock)
            {
                //因为是ET模式，所以要保证一次读完，所以不能直接调用accept
                //ET模式下，一定要是非阻塞模式，因为有可能这次恰好读完，下次再读就会阻塞
                my_accept(fd, epfd);
                printf("accept quit!\n");
            }
            else
            {
                printf("enter read!\n");
                char buf[10240];//假设缓冲区一定能够接收完

                //也要保证一次读完
                int s = my_read(fd, buf, sizeof(buf)-1);
                if(s > 0)
                {
                    buf[s] = 0;
                    printf("client# %s\n", buf);

                    //读完之后，再将关心的事件设置为写，表示读完客户端发的消息，再回显给他
                    SetNonBlock(fd);

                    ev.events = EPOLLIN | EPOLLET;//这里虽然是修改，但是也一定要记得加EPOLLET
                    ev.data.fd = fd;
                    epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
                }
                else if(s == 0)
                {
                    printf("client quit\n");

                    //这里不仅要关闭fd，还要再红黑树中删除该“节点”
                    close(fd);
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                }
                else
                {
                    perror("read");
                    //这里不仅要关闭fd，还要再红黑树中删除该“节点”
                    close(fd);
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                }
            }
        }

        if(recvs[i].events & EPOLLOUT)//write
        {
            const char* msg = "HTTP/1.0 200 OK\r\n\r\n<html><h1>HELLO WROLD:)</h1></html>";
            write(fd, msg, strlen(msg));
            close(fd);
            epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
        }
    }
}

//./epoll_ET_server 9090
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    int listen_sock = startup(atoi(argv[1]));

    //创建epoll模型
    int epfd = epoll_create(256);
    if(epfd < 0)
    {
        perror("epoll_create");
        exit(5);
    }

    //设置关系那个文件描述符的那些事，并将epoll工作模式设置为ET
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = listen_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev);

    //创建用来保存内核返回的就绪事件数组，和数组元素个数
    struct epoll_event recvs[MAX];
    int size = 0;
    while(1)
    {
        switch((size = epoll_wait(epfd, recvs, MAX-1, -1)))
        {
        case -1:
            perror("epoll_wait");
            break;
        case 0:
            printf("timeout....\n");
            break;
        default:
            serviceIO(epfd, recvs, size, listen_sock);
        }
    }

}
