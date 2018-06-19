#include <sys/wait.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

void service(int sock, char* ip, int port)
{
    char buf[10240];//用一个足够大的缓冲区一次性将数据读完
    buf[0] = 0;
    read(sock, buf, sizeof(buf));
    const char* response = "HTTP/1.0 200 OK\n\n<html><head>hello world</head></html>\n";
    write(sock, response, strlen(response));
}


int StartUp(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_port = htons(port);

    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind");
        exit(3);
    }

    //设置为监听状态
    if(listen(sock, 5) < 0)
    {
        perror("listen");
        exit(4);
    }

    return sock;
}

// ./myHttp 0 9090
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s [ip] [port]\n", argv[0]);
        exit(1);
    }

    int listen_sock = StartUp(atoi(argv[2]));
    struct sockaddr_in peer;
    int len = sizeof(peer);
    socklen_t new_sock = -1;
    daemon(0, 0);
    while(1)
    {
        if((new_sock = accept(listen_sock, (struct sockaddr*)&peer, &len)) < 0)
        {
            printf("Connect faily\n");
            continue;
        }

        char ipBuf[24] = {0};
        inet_ntop(AF_INET, (struct sockaddr*)&peer, ipBuf, sizeof(ipBuf));
        int p = ntohs(peer.sin_port);
        printf("get a new connect: [%s %d]\n", ipBuf, p);

        int id = fork();
        if(id == 0)//child
        {
            close(listen_sock);
            if(fork() > 0)
            {
                close(new_sock);
                exit(0);
            }

            service(new_sock, ipBuf, p);
            close(new_sock);
            exit(0);
        }

        else if(id > 0)//father
        {
            close(new_sock);//因为父进程不通信
            waitpid(id, NULL, 0);
            continue;
        }

        else
        {
            perror("fork");
            continue;
        }
    }
}
