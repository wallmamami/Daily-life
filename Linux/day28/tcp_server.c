#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

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

        //多进程版本--子进程提供服务, 父进程一直接收请求
        //因为父进程一直不会退出，而子进程提供完服务之后就可能会退出
        //就会成为僵尸进程，造成内存泄露
       pid_t id = fork();
       if(id == 0)//child
       {
            close(listen_sock);
            //这里可以在子进程中再创建子进程，子进程退出，
            //孙子进程成为孤儿进程，孙子进程提供服务，退出后由
            //1号进程回收，不会造成内存泄露
            if(fork() == 0)
            {
                service(new_sock, ipBuf, p);
                close(new_sock);//因为子进程也有自己的文件描述符表，关闭不会对父进程造成影响，所以这里一定要关闭
                exit(0);
            }
       }
       else if(id > 0)//father
       {
           close(new_sock);
           waitpid(id, NULL, 0);
       }
       else
       {
           perror("fork");
           continue;
       }
    }

    return 0;
}
