#include <pthread.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

typedef struct
{
    int sock;
    char ip[24];
    int port;
}net_info_t;

void service(int new_sock, char* ip, int port)
{
    char buf[SIZE];
    while(1)
    {
        buf[0] = 0;//清空buf
        //先从new_sock上读取内容
        ssize_t s = read(new_sock, buf, sizeof(buf)-1);
        if(s > 0)
        {
            buf[s] = 0;
            printf("[%s %d] say# %s\n", ip, port, buf);
            //再将原内容返回给客户端
            write(new_sock, buf, strlen(buf));
        }
        else if(s == 0)//表示对方已经断开连接
        {
            printf("client [%s %d] quit!\n", ip, port);
            break;
        }
        else
        {
            break;
        }
    }
}

void* thread_serevice(void* arg)
{
    net_info_t* info = (net_info_t*)arg;
    
    service(info->sock, info->ip, info->port);

    //服务完之后一定要关闭文件描述符
    close(info->sock);

    //因为info是在堆上动态申请的,所以一定要释放info
    free(info);
}

int StartUp(char* ip, int port)
{
    //创建套接字文件描述符
    //第一个参数为ip地址类型，第二个(tcp->SOCK_STREAM, udp->SOCK_DGRAM),最后一个参数设0
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_sock < 0)
    {
        perror("socket");
        exit(2);
    }

    //设置本地网络信息
    struct sockaddr_in local;
    local.sin_family = AF_INET;//地址类型
    local.sin_addr.s_addr = inet_addr(ip);//设置ip地址
    //local.sin_addr.s_addr = htonl(INADDR_ANY);//设置为INADDR_ANY(其实就是0)表示可以在所有的ip地址(服务器可能有多个网卡)上监听
    local.sin_port = htons(port);

    //将设置好的信息于listen_sock绑定
    if(bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind");
        exit(3);
    }
    //将listen_sock设置为监听状态
    //第二个参数为等待队列长度，不能为0，也不能太长(5-10)
    if(listen(listen_sock, 5) < 0)
    {
        perror("listen");
        exit(4);
    }

    return listen_sock;
}


//用命令行参数将启动服务器的主机网络信息传进来
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s [ip] [port]\n", argv[0]);
        exit(1);
    }

    int listen_sock = StartUp(argv[1], atoi(argv[2]));

    struct sockaddr_in peer;//用来保存客户端的网络信息
    char ipBuf[24];
    int p;
    while(1)
    {
        ipBuf[0] = 0;//清空buf
        int new_sock;//真正用来通信的套接字
        socklen_t len = sizeof(peer);
        if((new_sock = accept(listen_sock, (struct sockaddr*)&peer, &len)) < 0)
        {
            perror("accept");
            continue;//连接失败重新连接新的客户端
        }

        inet_ntop(AF_INET, (const void*)&peer.sin_addr, ipBuf, sizeof(ipBuf));//将整数类型ip转化为字符串风格
        p = ntohs(peer.sin_port);//将网络字节序的port转化为主机字节序

        printf("Get a new connect: [%s %d]\n", ipBuf, p);

        net_info_t *info = (net_info_t*)malloc(sizeof(net_info_t));
        if(info == NULL)
        {
            perror("malloc");
            close(new_sock);//一定要关闭文件描述符
            continue;
        }

        strcpy(info->ip, ipBuf);
        info->port = p;
        info->sock = new_sock;

        pthread_t tid;
        pthread_create(&tid, NULL, thread_serevice, info);

        //在主线程中将新线程分离就不用等
        pthread_detach(tid);
    }

    return 0;
}
