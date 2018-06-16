#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//定义读写锁
pthread_rwlock_t rwlock;

int counter = 0;


//写者线程
void *write_thread(void *arg)
{
    //表示几号线程
    int number = (int)arg;
    int tmp = 0;
    while(1)
    {
        //写之前先申请锁
        pthread_rwlock_wrlock(&rwlock);

        tmp = counter;
        ++counter;

        printf("I am thread %d, old data is %d, now is %d\n", number, tmp, counter);

        //释放锁
        pthread_rwlock_unlock(&rwlock);

        sleep(1);
    }
}

//读者线程
void *read_thread(void *arg)
{
    //表示几号线程
    int number = (int)arg;
    while(1)
    {
        //读之前先申请锁
        pthread_rwlock_rdlock(&rwlock);

        printf("I am thread %d, now data is %d\n", number, counter);
        //释放锁
        pthread_rwlock_unlock(&rwlock);

        sleep(2);
    }

}

int main()
{
    int i = 0;
    pthread_t tid[8];
    
    //初始化读写锁
    pthread_rwlock_init(&rwlock, NULL);
    //创建三个写者线程
    for(; i < 3; i++)
    {
        pthread_create(tid+i, NULL, write_thread, (void *)i);
    }
    //创建5个写者线程
    for(; i < 8; i++)
    {
        pthread_create(tid+i, NULL, read_thread, (void *)i);
    }

    for(i = 0; i < 8; i++)
    {
        pthread_join(tid[i], NULL);
    }

    //销毁读写锁
    pthread_rwlock_destroy(&rwlock);
}
