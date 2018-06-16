#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//队列最大容量
#define M 5

//队列
int ring[M];

//信号量
sem_t semBlank;//"空间资源"
sem_t semData;//"数据资源"


//生产者
void *producer(void *arg)
{
    int i = 0;
    while(1)
    {
        //保证数据在1-100内
        int data = rand() % 100 + 1;
        
        //生产前先P(semBlank)
        sem_wait(&semBlank);
        //生产
        ring[i] = data;
        printf("I am producer,I product data is:%d\n", data);
        //保证数据不会越界
        i++;
        i %= M;

        //生产完后，就多一个“数据”资源，V(semData)
        sem_post(&semData);
        sleep(1);
    }
}


//消费者
void *consumer(void *arg)
{
    int i = 0;
    while(1)
    {
        //消费前先看有没有数据资源P(semData)
        sem_wait(&semData);

        //消费
        int data = ring[i];
        i++;
        i %= M;
        printf("I am consumer, I consume data is: %d\n", data);

        //消费完了，就多一个“空间”资源，V(semBlank)
        sem_post(&semBlank);

    }
}


int main()
{
    pthread_t tid1, tid2;
    srand((unsigned int)time(NULL));

    //初始化信号量
    sem_init(&semBlank, 0, M);    
    sem_init(&semData, 0, 0); 

    //创建生产者消费者线程
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);


    //线程分离
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    //销毁信号量
    sem_destroy(&semBlank);
    sem_destroy(&semData);
    
}
