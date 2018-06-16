#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>



//void handler(int sig)
//{
//    int ret = 0;
//    while((ret = waitpid(-1, NULL, WNOHANG)) > 0)//非阻塞式等待多个子进程
//    {
//        if(ret > 0)
//        {
//            printf("wait success, child pid is %d\n", ret);
//        }
//    }
//}


int main()
{

    pid_t id = fork();
    if(id == 0)//子进程
    {
        int i = 10;
        while(i)
        {
            printf("i am child, pid: %d, ppid %d\n", getpid(), getppid());
            sleep(1);
            i--;
        }
    }
    else if(id < 0)
    {
        printf("fork error!\n");
        exit(1);
    }

    else//父进程
    {

        struct sigaction act, oact;
        act.sa_flags = 0;
        act.sa_handler = SIG_IGN;
        sigemptyset(&act.sa_mask);
        sigaction(SIGCHLD, &act, &oact);
        while(1);
    }
}
