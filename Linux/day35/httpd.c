#include <sys/sendfile.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX 1024
#define HOME_PAGE "index.html"

static int startup(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    //为了解决因为服务器主动断开连接造成time_wait而不能立即绑定的问题
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

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

static void usage(char* ptr)
{
    printf("Usage: %s [port]\n", ptr);
}

//因为客户端有很有很多种，所以换行有可能是以下几种\n \r\n \r,因为我们是c语言，所以全都换成\n,
//这个函数的作用就是读取一行放在line中，并且将换行统一换作\n
int get_line(int sock, char line[], int size)
{
    int c = 'a';
    int i = 0;
    ssize_t s = 0;

    //为了给最后一个放'\0'，所以是size-1
    while(i < size-1 && c != '\n')
    {
        s = recv(sock, &c, 1, 0);
        if(s > 0)
        {
            if(c == '\r')
            {
                //有两种情况，一种\r 一种\r\n
                recv(sock, &c, 1, MSG_PEEK);//只“看看”接收缓冲区中的东西，不“拿”出来
                if(c != '\n')
                {
                    c = '\n';
                }
                else
                {
                    //读出来
                    recv(sock, &c, 1, 0);//c == '\n'
                }
            }

            //此时，c如果是换行符，一定是'\n'
            line[i++] = c;
        }
        else
            break;
    }

    line[i] = '\0';
    return i;
}


void clear_header(int sock)
{
    char line[MAX];

    do
    {
        get_line(sock, line, sizeof(line));

    }while(strcmp(line, "\n") != 0);//读到空行表示读完HTTP请求，因为GET方法一般是没有正文的
}

static void show_404(int sock)
{
    clear_header(sock);
    
    char line[MAX];
    //响应也需要响应标准格式(响应行, 响应报头)
    sprintf(line, "HTTP/1.0 200 OK\r\n");
    send(sock, line, strlen(line), 0);
    sprintf(line, "Content-Type: text/html\r\n");
    send(sock, line, strlen(line), 0);

    sprintf(line, "\r\n");//一定注意，还有空行
    send(sock, line, strlen(line), 0);

    const char* err = "wwwroot/error/404.html";
    int fd = open(err, O_RDONLY);
    struct stat st;
    stat(err, &st);

    sendfile(sock, fd, NULL, st.st_size);
    close(fd);

}
static void echo_error(int errCode, int sock)
{
    switch(errCode)
    {
    case 403:
        break;
    case 404:
        show_404(sock);
        break;
    case 501:
        break;
    case 503:
        break;
    default:
        break;
    }
}

void echo_www(int sock, char path[], int size, int* err)
{
    //进入这里，说明一定是GET方法，之前只是读了HTTP请求的请求行
    //在响应之前一定要保证读完HTTP请求
    clear_header(sock);

    int fd = open(path, O_RDONLY);
    if(fd < 0)
    {
        *err = 404;
        return;
    }

    char line[MAX];

    //响应也需要响应标准格式(响应行, 响应报头)
    sprintf(line, "HTTP/1.0 200 OK\r\n");
    send(sock, line, strlen(line), 0);
    sprintf(line, "Content-Type: text/html\r\n");
    send(sock, line, strlen(line), 0);

    sprintf(line, "\r\n");//一定注意，还有空行
    send(sock, line, strlen(line), 0);

    sendfile(sock, fd, NULL, size);
    close(fd);
}

static void* handler_request(void* arg)
{
    int sock = (int)arg;//因为指针和sock都是4字节，所以可以直接强转
    char line[MAX];
    int errCode = 200;
    char method[MAX/32];//保存请求行中的方法GET/POST
    char url[MAX];//路径,如果是GET方法,可能会有浏览器提交的参数
    int cgi = 0;//标记时是否按照cgi方式运行
    char* query_string = NULL;//用来指向GET方法中url的参数信息
    char path[MAX];//用来保存路径

#ifdef Debug
    do
    {
        get_line(sock, line, sizeof(line));
        printf("%s", line);

    }while(strcmp(line, "\n") != 0);//读到空行退出,只拿到请求行和请求报头
#else

    //分析请求行信息--只读了一行
    if(get_line(sock, line, sizeof(line)) < 0)
    {
        errCode = 404;
        goto end;
    }

    //line[] = GET /index.php?a=100&&b=200 HTTP/1.1
    //将line中的信息分离，分别保存到method\url

    int i = 0;
    int j = 0;
    while(i < sizeof(method)-1 && j < sizeof(line) && !isspace(line[j]))
    {
        method[i] = line[j];
        i++;
        j++;
    }
    method[i] = '\0';

    if(strcasecmp(method, "GET") == 0)//比较不区分大小写
    {}
    else if(strcasecmp(method, "POST") == 0)
    {
        //按照cgi方式运行i,因为POST方法,浏览器一定向服务器提交参数了
        cgi = 1;
    }
    else
    {
        errCode = 404;
        goto end;
    }

    //因为在请求行中是以空格分隔的,所以这里要跳过空格
    while(j < sizeof(line) && isspace(line[j]))
    {
        j++;
    }

    i = 0;
    while(i < sizeof(url)-1 && j < sizeof(line) && !isspace(line[j]))
    {
        url[i] = line[j];
        i++;
        j++;
    }
    url[i] = '\0';

    //分析url中的信息,如果是GET方法,就一定会将参数添加到url中
    if(strcasecmp(method, "GET") == 0)
    {
        query_string = url;
        while(*query_string)
        {
            if(*query_string == '?')//如果有参数,会以?分隔,前面的为路径,后面的为参数,并且要以cgi方式运行
            {
                *query_string = '\0';//将路径和参数分隔开
                query_string++;
                cgi = 1;
                break;
            }

            query_string++;
        }
    }

    //因为http请求中的路径的根目录就是服务器的根目录就是这里的wwwroot,所以将其添加进去
    sprintf(path, "wwwroot%s", url);

    //如果请求中url为某个目录,默认响应"首页"
    if(path[strlen(path)-1] == '/')
    {
        strcat(path, HOME_PAGE);
    }

    //判断文件是否存在以及属性信息
    struct stat st;
    if(stat(path, &st) < 0)
    {
        errCode = 404;
        goto end;
    }

    else
    {
        if(S_ISDIR(st.st_mode))
        {
            strcat(path, HOME_PAGE);
        }
        else
        {
            //如果任何一个人有执行权限都要以cgi模式运行
            if(st.st_mode & S_IXUSR || st.st_mode & S_IXGRP || st.st_mode & S_IXOTH)
            {
                cgi = 1;
            }
        }
        if(cgi)
        {
            //exe_cgi();
        }

        else
        {
            printf("path = %s\n", path);
            echo_www(sock, path, st.st_size, &errCode);
        }
    }


#endif
end:
    if(errCode != 200)
    {
        echo_error(errCode, sock);
    }
    close(sock);
}

//./http 8080
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        usage(argv[0]);
        exit(1);
    }

    int listen_sock = startup(atoi(argv[1]));

    //多线程版
    while(1)
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int new_sock = -1;

        if((new_sock = accept(listen_sock, (struct sockaddr*)&client, &len))< 0)
        {
            perror("accept");
            continue;
        }

        //创建线程
        pthread_t tid;
        pthread_create(&tid, NULL, handler_request, (void*)new_sock);

        //为了不等待，将其设置为分离状态
        pthread_detach(tid);
    }
}
