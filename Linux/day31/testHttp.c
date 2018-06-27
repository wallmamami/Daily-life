#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>


void service(int sock)
{
    char buf[10240];//用一个足够大的缓冲区一次性将数据读完
    buf[0] = 0;
    read(sock, buf, sizeof(buf));
    const char* response = "HTTP/1.0 200 OK\n\n<html><head>hello world</head></html>\n";
    write(sock, response, strlen(response));
}

int StartUp(char* ip, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    struct sockaddr_in local;
    local.sin_family = INADDR_ANY;
    local.sin_port = htons(port);
    local.sin_addr.s_addr = inet_addr(ip);

    //将网络信息与sock进行绑定
    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind");
        exit(3);
    }

    //将当前套接字设置为监听状态
    if(listen(sock, 5) < 0)
    {
        perror("listen");
        exit(4);
    }

    return sock;
}

//命令行参数将ip port传进来
//./testHttp 0 8080
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s [ip] [port]\n", argv[0]);
        exit(1);
    }

    int listen_sock = StartUp(argv[1], atoi(argv[2]));
    
    struct sockaddr_in peer;
    socklen_t len = sizeof(peer);
    int new_sock;
    char ipBuf[24];
    
    daemon(0, 0);
    while(1)
    {
        if((new_sock = accept(listen_sock, (struct sockaddr*)&peer, &len) < 0))
        {
            perror("accept");
            continue;
        }

        int p = ntohs(peer.sin_port);
        inet_ntop(AF_INET, (struct sockaddr*)&peer, ipBuf, sizeof(ipBuf));
        printf("get a connect, [%s %d]\n", ipBuf, p);

        int id = fork();
        if(id == 0)//child
        {
            close(listen_sock);
            if(fork() > 0)
            {
                close(new_sock);
                exit(0);
            }

            service(new_sock);
            close(new_sock);
        }
        else if(id > 0)//father
        {
            close(new_sock);
            waitpid(id, NULL, 0);
            continue;
        }
        else
            continue;
        
    }

    return 0;
}
