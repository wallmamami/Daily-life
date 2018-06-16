#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int ticket = 50000;

void *buy_ticket(void *arg)
{
    const char *id = (const char*)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);//进入临界区上锁
        if(ticket > 0)
        {
            printf("%s get a ticket: %d\n", id, ticket);
            --ticket;
            pthread_mutex_unlock(&mutex);//出临界区解锁
            
        } 
        else{
            pthread_mutex_unlock(&mutex);
            break;
        }  
    }
}

int main()
{
    pthread_t tid1, tid2, tid3, tid4;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid1, NULL, buy_ticket, "thread_1");
    pthread_create(&tid2, NULL, buy_ticket, "thread_2");
    pthread_create(&tid3, NULL, buy_ticket, "thread_3");
    pthread_create(&tid4, NULL, buy_ticket, "thread_4");


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);

    pthread_mutex_destroy(&mutex);
}
