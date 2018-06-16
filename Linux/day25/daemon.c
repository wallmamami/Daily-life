#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>


void mydaemon()
{
    //调用umask将文件模式创建屏蔽字设置为0
    umask(0);

    //调用fork()，父进程退出，保证子进程不是一个进程组的组长进程
    pid_t id = fork();
    if(id < 0)
    {
        perror("fork");
    }

    else if(id > 0)//father
    {
        exit(0);
    }

    //调用setsid创建新会话，并且成为话首进程
    //创建了新进程组，成为组长进程
    //与终端失去关联
    setsid();

    struct sigaction act;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = SIG_IGN;
    //忽略SIGCHLD信号，为了不用回收子进程
    sigaction(SIGCHLD, &act, NULL);

    //将当前工作目录改为根目录
    chdir("/");

    //关闭不再需要的文件描述符
    close(0);
    close(1);
    close(2);
}

int main()
{
    mydaemon();

    while(1)
    {
        //do some service
        sleep(1);
    }
}
