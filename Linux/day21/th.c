#include <sys/syscall.h>
#include <stdio.h>
#include <pthread.h>


void *pthread_th1(void *arg)
{
    while(1)
    {
        printf("%s\n", (char*)arg);
        pid_t tid = syscall(SYS_gettid);
        printf("%d\n", tid);
        sleep(1);
    }
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, pthread_th1, "thread1");

    void *ret = 0;
    pthread_join(tid, &ret);
}
