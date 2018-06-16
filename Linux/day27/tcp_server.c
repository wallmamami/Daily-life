#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 128

int startup(char* ip, int port)
{    
    //创建socket文件描述符
    //这里使用的是tcp协议，所以类型是SOCK_STREAM
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    //设置sock相关网络信息
    struct sockaddr_in local;
    local.sin_family = AF_INET;//将地址类型设置为IPv4
    local.sin_port = htons(port);//将字节序转化为网络字节序
    local.sin_addr.s_addr = inet_addr(ip);//将字符串风格ip地址转化为整数

    //将网络信息和sock绑定
    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind");
        exit(3);
    }

    //将sock设置为监听状态
    //第二个参数为等待队列的长度,通常设置为5-10
    if(listen(sock, 5) < 0)
    {
        perror("listen");
        exit(4);
    }

    return sock;
}

void service(int sock, char* ip, int port)
{
    char buf[SIZE];
    while(1)
    {
        //因为tcp协议面向字节流，所以可以直接用read和write
        ssize_t s = read(sock, buf, sizeof(buf)-1);//减1是因为输入也会将回车输进来
        if(s > 0)//表示读成功，实际读的大小为s
        {
            buf[s] = 0;//将\0设置进去
            printf("[%s:%d] say#%s\n", ip, port, buf);
            write(sock, buf, strlen(buf));
        }
        else if(s = 0)//表示对方已关闭,断开连接
        {
            printf("client [%s:%d] quit\n", ip, port);
            break;
        }
        else
        {
            perror("read");
            break;
        }
    }
}


//测试的时候可以使用本地回环地址127.0.0.1
//用命令行参数将启动服务器的IP地址和端口号传进来
// ./tcp_server 127.0.0.1 8080
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s [ip] [port]", argv[0]);
        exit(1);
    }

    int listen_sock = startup(argv[1], atoi(argv[2]));

    struct sockaddr_in peer;
    char ipBuf[24];
    while(1)
    {
        ipBuf[0] = 0;//清空缓冲区
        socklen_t len = sizeof(peer);

        //请求连接，反回真正用来通信的socket文件描述符
        //因为listen_sock一直处于监听状态，如果有客户端想要建立连接，
        //就会由listen_sock将客户端信息传过来，等到连接成功或失败，它就继续去监听
        //第二个参数用来返回客户机的信息
        int new_sock = accept(listen_sock, (struct sockaddr*)&peer, &len);

        //如果请求连接失败，继续
        if(new_sock < 0)
        {
            perror("accept");
            continue;
        }

        inet_ntop(AF_INET, (struct sockaddr*)&peer.sin_addr, ipBuf, sizeof(ipBuf));
        printf("get a new connect,[%s:%d]\n", ipBuf, ntohs(peer.sin_port));

        service(new_sock, ipBuf, ntohs(peer.sin_port));
        close(new_sock);
    }

    return 0;
}
