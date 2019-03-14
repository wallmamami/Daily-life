#include <netinet/in.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include "threadpool.h"


#define SLEEP_TIME 3610   //定时时间
#define MAX_OPEN_FILE_SIZE 1024    //当前系统下一个进程所能打开文件描述符的总数
#define MAX_COL 15

int epfd = -1;     //epoll的句柄
int file_fd = -1;  //日志文件
char IPSTR[MAX_OPEN_FILE_SIZE][MAX_COL];  //类似与文件描述符与IP地址的hash
//由于处于多线程环境下，且
//file_fd属于临界资源所以
//访问时需要加互斥锁
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void get_time(char* name, int flag)
{
  time_t timep;
  struct tm *p;
  time(&timep);

  p=localtime(&timep);
  if(1 == flag)//精确到秒
  {
    sprintf(name, "%d-%02d-%02d %02d:%02d:%02d ", (1900 + p->tm_year),(1 + p->tm_mon),p->tm_mday,(p->tm_hour+12),p->tm_min,p->tm_sec);
  }
  else
  {
    sprintf(name, "./wwwroot/pw%d%02d%02d-%02d.log", (1900 + p->tm_year),(1 + p->tm_mon),p->tm_mday,(p->tm_hour));
  }
}
void create_file()
{
  char path[20] = {}; 
  get_time(path, 0);
  file_fd = open(path, O_WRONLY|O_CREAT|O_APPEND, 0666);

  if(file_fd < 0)
  {
    printf("create file fail\n"); 
    return;
  }
}

//自定义的信号处理函数
void handler(int sig)
{
  printf("GET YOU sig = %d\n", sig);
  alarm(SLEEP_TIME);
  //在创建新的日志文件之前，首先先关闭原来的日志文件
  if(file_fd > 0)
    close(file_fd);
  create_file();
}


void BuildFile(int fd, char* buff, char* Buff)
{
  if(NULL == Buff || NULL == buff)
    return;
  
  int index1 = 0;
  int index2 = 0;
  get_time(Buff, 1);
  while(Buff[index1])
    ++index1;

  while(IPSTR[fd][index2])
  {
    Buff[index1] = IPSTR[fd][index2];
    ++index1;
    ++index2;
  }

  index2 = 0;
  int index = 0;
  while(buff[index])
  {
    //这里不知道为什么'\n'被当作两个字符
    if(92 == buff[index] && 110 == buff[index+1])
    {
      Buff[index1++] = '\n';
      get_time(Buff+index1, 1);
      while(Buff[index1])
        ++index1;

      while(IPSTR[fd][index2])
      {
        Buff[index1] = IPSTR[fd][index2];
        ++index1;
        ++index2;
      }
      index += 2;
    }
    else
    {
      Buff[index1] = buff[index];
      ++index1;
      ++index;
    }
  }
  
  Buff[index1] = '\n';
  Buff[index1+1] = '\0';
}

void* handler_request(void* arg)
{

  int fd = (int)arg;
  char buff[MAX_OPEN_FILE_SIZE * 8] = {};
  char Buff[MAX_OPEN_FILE_SIZE * 10] = {};
  ssize_t s = read(fd, buff, sizeof(buff)-1);

  if(s > 0)
  {
    buff[s] = 0;
    BuildFile(fd, buff, Buff);
    
    pthread_mutex_lock(&mutex);
    write(file_fd, Buff, strlen(Buff));
    pthread_mutex_unlock(&mutex);

    //读完后，重新关心该fd的读事件
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = fd;
    epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
  }
  else if(0 == s)
  {
    printf("client quit\n");
    close(fd);

  }
  else
  {
    perror("read");
    close(fd);
  }

  return (void*)0;
}
void serviceIO(threadpool_t* pool, struct epoll_event* revs, int size, int listen_sock)
{
  int i = 0;
  struct epoll_event ev;
  for(; i < size; i++)
  {
    int fd = revs[i].data.fd;
    if(revs[i].events & EPOLLIN)//关心读事件
    {
      if(listen_sock == fd)//accept
      {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);

        int new_sock = accept(fd, (struct sockaddr*)&client, &len);
        if(new_sock < 0)
        {
          perror("accept");
          continue;
        }

        //printf("get a new client[%s:%d]\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        sprintf(IPSTR[new_sock], "%s ", inet_ntoa(client.sin_addr));
        //将新连接添加到红黑树当中
        ev.events = EPOLLIN;
        ev.data.fd = new_sock;
        epoll_ctl(epfd, EPOLL_CTL_ADD, new_sock, &ev);

      }
      else//常规文件描述符--read
      {
        //将任务交给线程池去具体处理
        //任务，主线程只负责I/O
        threadpool_add_task(pool, handler_request, (void*)fd);

        //这里要将该fd设置为不关心其读事件
        //否则，主线程永远等待就绪的都是该
        //文件描述符
        ev.events &= ~EPOLLIN;
        ev.data.fd = fd;
        epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
      }
    }
  }
}


int startup(int port)
{
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0)
  {
    perror("socket");
    exit(2);
  }

  //绑定网络信息
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


//./epoll_server 9999
int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("Usage: %s [port]\n", argv[0]);
    exit(1);
  }

  //用alarm和信号实现简单
  //的定时器
  alarm(SLEEP_TIME);
  signal(SIGALRM, handler);
  //创建日志文件
  create_file();

  //创建线程池并初始化
  threadpool_t pool;
  //创建8个空闲线程,线程池
  //最多可以有10个线程
  threadpool_init(&pool, 8, 10);
  int listen_sock = startup(atoi(argv[1]));

  //创建epoll模型
  //>>在内核中创建空的红黑树
  //>>创建啊就绪队列
  //>>建立回调机制
  epfd = epoll_create(256);
  if(epfd < 0)
  {
    perror("epoll_create");
    exit(5);
  }

  struct epoll_event ev;
  ev.events = EPOLLIN;//读事件
  ev.data.fd = listen_sock;

  //首先，将listen_sock添加到红黑树当中(红黑树中的节点表示关心那些文件描述符的那些事件)
  epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev);

  struct epoll_event revs[128];//用来保存内核返回的就绪事件
  int size = 0;//用来保存放回的就绪事件的个数

  while(1)
  {
    switch((size = epoll_wait(epfd, revs, 128-1, -1)))
    {
      case -1:
        perror("epoll_wait");
        break;
      case 0:
        printf("timeout....\n");
        break;
      default:
        serviceIO(&pool, revs, size, listen_sock);
        break;
    }
  }

  //销毁线程池
  threadpool_destroy(&pool);
  return 0;
}

