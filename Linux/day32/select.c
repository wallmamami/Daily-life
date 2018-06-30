#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_FD 1024 //大小取决于sizeof(rfds)位图的大小 1024 = 128*4
#define INIT -1

void arr_init(int fd_arr[], int num)
{
    int i = 0;
    for(; i < num; i++)
    {
        fd_arr[i] = INIT;
    }
}

int arr_add(int fd_arr[], int num, int fd)
{
    int i = 0;
    for(; i < num; i++)
    {
        if(fd_arr[i] == INIT)
        {
            fd_arr[i] = fd;
            return 0;
        }
    }

    return -1;//说明数组满了
}

int set_rfds(int fd_arr[], int num, fd_set* rfds)
{
   int i = 0;
   int max_fd;
   for(; i < num; i++)
   {
       if(fd_arr[i] > INIT)
        FD_SET(fd_arr[i], rfds);

       if(fd_arr[i] > max_fd)
           max_fd = fd_arr[i];
   }

   return max_fd;
}

void arr_del(int fd_arr[], int num, int index)
{
    if(index > 0 && index < num)
        fd_arr[index] = INIT;
}

void service(int fd_arr[], int num, fd_set* rfds)
{
    int i = 0;
    //这里我们只知道有事件就绪了，但是并不知道是那个文件描述符
    //所以，要在数组中遍历查看
    for(; i < num; i++)
    {
        int fd = fd_arr[i];
        if(fd > INIT && FD_ISSET(fd, rfds))//表示文件描述符是“我’关心的，并且被设立到集合中
        {
            if(i == 0)//默认将listen_sock放到数组下标为0
            {
                //listen_sock就绪表明有新连接来了，可以请求连接了
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                
                int new_sock = accept(fd, (struct sockaddr*)&client, &len);
                if(new_sock < 0)
                {
                    perror("accept");
                    continue;
                }

                //new_sock现在不一定就绪，因为有可能只是连接，不发消息，所以现在只是将其添加到数组中，等待下次就绪
                printf("get a new connect: [%s:%d]", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
                if(arr_add(fd_arr, MAX_FD, fd) < 0)
                {
                    printf("service are too busy!\n");
                    close(new_sock);
                }
            }
            else//如果是其他文件描述符就绪，表示可以读取
            {
                char buf[1024] = {0};
                ssize_t s = read(fd, buf, sizeof(buf));
                if(s > 0)
                {
                    buf[s-1] = 0;
                    printf("client# %s\n", buf);
                }
                
                else if(s == 0)//表示对方关闭，这时也会发送消息，所以也有可能就绪
                {
                    close(fd);
                    printf("client quit\n");
                    arr_del(fd_arr, num, i);//一定删除，否则，下次还会将该fd添加到读事件集
                }
                else
                {
                    perror("read");
                    close(fd);
                    arr_del(fd_arr, num, i);
                }
            }
        }
    }
}

int startup(int port)
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

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

//通过命令行参数将端口号传进来
//./select port
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s [port]", argv[0]);
        exit(1);
    }

    int listen_sock = startup(atoi(argv[1]));
    
    fd_set rfds;//读事件集

    //因为select的第二（三、四）个参数为输入输出型参数，在输出的时候设置的值会改变集合中原本的值，
    //所以要借助第三方数组来将需要关心的文件描述符保存起来，并且每一轮都要用数组重新设置集合
    int fd_arr[MAX_FD];

    arr_init(fd_arr, MAX_FD);
    arr_add(fd_arr, MAX_FD, listen_sock);//我们要一直关心listen_sock的读事件，所以默认将其放到0号下标的位置

    int max_fd = 0;//用来保存集合中值最大的文件描述符+1
    while(1)
    {
        struct timeval timeout = {5, 0};//表示如果5后没有事件就绪，select超时返回
        FD_ZERO(&rfds);//清空读事件集

        max_fd = set_rfds(fd_arr, MAX_FD, &rfds);

        switch(select(max_fd+1, &rfds, NULL, NULL, &timeout))
        {
        case 0:
            printf("timeout......\n");
            break;
        case -1:
            perror("select");
            break;
        default://表示执行成功，返回值为事件就绪文件描述符的个数
            service(fd_arr, MAX_FD, &rfds);
            break;
        }
    }

}
