#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_run(void *arg)
{
    while(1)
    {
        printf("I am thread 1\n");
        sleep(1);
    }
}


int main(void)
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread_run, NULL);

    sleep(5);
//    pthread_cancel(tid);

    return 0;
}
