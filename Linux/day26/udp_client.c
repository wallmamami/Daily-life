#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//用命令行参数来接收服务器主机的IP地址和端口号
// ./udp_client 192.168.17.130
int main(int argc, char* argv[])
{
    //判断参数个数是否正确
    if(argc != 3)
    {
        printf("Usage: %s [IP][port]", argv[0]);
        exit(1);
    }

    //创建socket文件描述符
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        printf("sock error!\n");
        exit(2);
    }

    char buf[128];
    struct sockaddr_in server;//用来设置服务器相关信息
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    int len = sizeof(server);//因为式UDP,发送和接收的单位都是数据报
    while(1)
    {
        buf[0] = 0;//清空缓冲区

        //从标准输入读取数据放在buf
        ssize_t s = read(0, buf, sizeof(buf)-1);
        if(s > 0)
        {
            buf[s-1] = 0;

            //向服务器发送消息
            sendto(sock, buf, sizeof(buf), 0, (struct sockaddr*)&server, len);
            //接收服务器消息
           s = recvfrom(sock, buf, sizeof(buf)-1, 0, NULL, NULL);
           if(s > 0)
           {
               buf[s] = 0;
               printf("server echo# %s\n", buf);
           }
        }
    }

}
