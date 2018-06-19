#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_run1(void* arg)
{
    const char* msg = (char*)arg;
    while(1)
    {
        printf("I am %s, ID is %d\n", msg, pthread_self());
        sleep(1);
    }
    return (void*)1;
}

void* thread_run2(void* arg)
{
    const char* msg = (char*)arg;
    while(1)
    {
        printf("I am %s, ID is %lu\n", msg, pthread_self());
        sleep(1);
    }
    return (void*)1;
}

void* thread_run3(void* arg)
{
    const char* msg = (char*)arg;
    while(1)
    {
        printf("I am %s, ID is %d\n", msg, pthread_self());
        sleep(1);
    }
    return (void*)1;
}

int main()
{
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, thread_run1, "thread1");
    pthread_create(&tid2, NULL, thread_run2, "thread2");
    pthread_create(&tid3, NULL, thread_run3, "thread3");

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
//    int a = 10;
//    int b = 20;
//
//    pid_t id = fork();
//    if(id == 0)//child
//    {
//        printf("I am child: %d, a+b = %d\n", getpid(), a+b);
//        sleep(5);
//        exit(0);
//    }
//
//    else if(id > 0)//father
//    {
//        printf("I am father: %d\n", getpid());
//        wait(NULL);
//    }
//    else
//    {
//        printf("fork error!\n");
//        exit(1);
//    }
//
    return 0;
}
