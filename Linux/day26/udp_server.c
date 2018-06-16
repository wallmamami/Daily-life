#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 128


void service(int sock)
{
    char buf[SIZE];
    while(1)
    {
        //用来接收发送主机的网络信息
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);

        buf[0] = 0;//清空缓冲区

        //接收消息
        ssize_t s = recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr*)&peer, &len);//-1是因为回车也会被输入
        if(s > 0)
        {
            buf[s] = 0;
            printf("[%s:%d]# %s\n",inet_ntoa(peer.sin_addr), ntohs(peer.sin_port), buf); 
        }

        //发送消息
        sendto(sock, buf, sizeof(buf), 0, (struct sockaddr*)&peer, len);

    }
}


//要用命令行参数将启动服务器的主机的IP地址和端口号传过来
// ./udp_server 192.168.17.130 8080 
int main(int argc, char* argv[])
{
    //检测传参个数是否正确
    if(argc != 3)
    {
        printf("Usage: %s [ip] [port]\n", argv[0]);
        exit(1);
    }

    //创建socket文件描述符
    int sock = socket(AF_INET, SOCK_DGRAM, 0);//这里返回的sock就是文件描述符
    if(sock < 0)
    {
        perror("sock");
        exit(2);
    }

    struct sockaddr_in local;
    local.sin_family = AF_INET;//设置地址类型
    local.sin_port = htons(atoi(argv[2]));//设置端口号
    local.sin_addr.s_addr = inet_addr(argv[1]);//设置IP地址--先将字符串风格的IP地址转化为整数

    //将文件描述符与网络相关信息(local)绑定,并绑定端口号
    //因为IPv4的结构类型为sockaddr_in，所以需要强转
    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind");
        exit(3);
    }

    //do some server
    service(sock);

    close(sock);
    return 0;
    
}
