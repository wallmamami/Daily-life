#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void *pthread_th1(void *arg)
{
    while(1)
    {
        printf("I am thread1\n");
        sleep(1);
    }
}


int main()
{
   // printf("run /....!\n");
    pthread_t tid;

    pthread_create(&tid, NULL, pthread_th1, NULL);


 //   void *ret;
//    pthread_join(tid, &ret);
   // printf("run /....!\n");
}
