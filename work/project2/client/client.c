#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

//用命令行参数将服务器主机ip端口号传进来
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s [ip] [port]\n", argv[0]);
        return 1;
    }

    //创建sock文件描述符
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        return 2;
    }

    struct sockaddr_in server;//用来设置服务器ip端口号
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("connect");
        return 3;
    }
    
    char buf[SIZE];
    while(1)
    {
        buf[0] = 0;//清空buf
        printf("Please Enter#");
        fflush(stdout);
        ssize_t s = read(0, buf, sizeof(buf)-1);//因为也会将回车读进来，所以减1
        if(s > 0)
        {
            buf[s-1] = 0;
            if(strncmp("quit", buf, 4) == 0)
            {
                printf("client quit!\n");
                break;
            }

            write(sock, buf, strlen(buf));
        }
    }

    close(sock);
    return 0;
}
