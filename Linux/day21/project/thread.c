#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_run(void *arg)
{
    int i = 5;
    while(i--)
    {
        printf("I am %s\n", (char*)arg);
        sleep(1);
    }

    //终止线程
    //return (void *)1;//方式2
    pthread_exit((void*)1);//方式3
}

int main()
{
    pthread_t tid;

    //创建线程
    pthread_create(&tid, NULL, thread_run, "thread1");

    void *ret;

    //等待线程
    pthread_join(tid, &ret);
    printf("main thread: %d\n", (int)ret);
}
