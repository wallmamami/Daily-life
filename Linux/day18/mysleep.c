#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


void handler(int sig)
{

}

int mysleep(int t)
{
   struct sigaction act, oact;
   act.sa_flags = 0;
   act.sa_handler = handler;
    sigemptyset(&act.sa_mask);

    sigaction(14, &act, &oact);//捕获14号信号

    alarm(t);
    pause();

    int ret = alarm(0);//有可能闹钟提前响了，这里是取消以前设置的闹钟，返回值为以前闹钟剩余的时间
    sigaction(14, &oact, NULL);//恢复14号信号原来的sigaction，因为不能改变外层逻辑，再调用mysleep之前，对闹钟信号的处理方式为默认，调用完之后，也应该是默认。


    return ret;
}


int main()
{
    while(1)
    {
        printf("hello world\n");
        mysleep(1);
    }
}
