#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 128

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:%s [ip] [port]", argv[0]);
        exit(1);
    }

    //创建socket文件描述符
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    
    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("connect");
        exit(3);
    }

    char buf[SIZE];
    while(1)
    {
        buf[0] = 0;//清空缓冲区
        printf("Please Enter:");
        fflush(stdout);
        ssize_t s = read(0, buf, sizeof(buf));
        if(s > 0)
        {
            buf[s-1] = 0;
            if(strncmp("quit", buf, 4) == 0)
            {
                printf("client quit!\n");
                break;
            }

            write(sock, buf, strlen(buf));
            s = read(sock, buf, sizeof(buf)-1);
            buf[s] = 0;
            printf("Server Echo# %s\n", buf);
        }
    }

    close(sock);
    return 0;
}
