#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig)
{
    printf("get a signal: %d\n", sig);
}

int main()
{
    struct sigaction act, oact;
    act.sa_flags = 0;
    act.sa_handler = handler;

    sigemptyset(&act.sa_mask);
    sigaction(2, &act, &oact);//捕获2号进程

    while(1);

}
//void showpending(sigset_t* pending)
//{
//    int i = 1;
//    for(; i < 32; i++)
//    {
//        if(sigismember(pending, i))
//        {
//            printf("1");
//        }
//        else
//            printf("0");
//    }
//    printf("\n");
//}
//
//int main()
//{
//    sigset_t set, oset;
//    sigset_t pending;
//    sigemptyset(&set);//初始化set信号集
//    sigaddset(&set, 2);//将2号信号添加到set信号集中
//
//    sigprocmask(SIG_SETMASK, &set, &oset);//将set信号集设置为新的信号屏蔽集，将原来的保存到oset信号集中
//
//    while(1)
//    {
//        sigpending(&pending);//将当前进程处于未决的信号保存在pending信号集中
//        showpending(&pending);
//        sleep(1);
//    }
//
//}
