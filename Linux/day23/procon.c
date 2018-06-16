#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

typedef int DataType;

typedef struct Node
{
    DataType _data;
    struct Node* _pNext;
}Node, *PNode;

//创建新节点
PNode BuyNewNode(DataType data)
{
    PNode ptr = NULL;

    ptr = (PNode)malloc(sizeof(Node));
    if(NULL == ptr)
    {
        assert(0);
        return NULL;
    }

    ptr->_data = data;
    ptr->_pNext = NULL;
    return ptr;
}

//头插
void ListPushFront(PNode *pHead, DataType data)
{
    PNode pNewNode = NULL;
    assert(pHead);

    pNewNode = BuyNewNode(data);

    pNewNode->_pNext = *pHead;
    *pHead = pNewNode;
}

//头删
void ListPopFront(PNode *pHead)
{
    assert(pHead);
    if(NULL == *pHead)
        return;

    PNode pDeNode = NULL;

    pDeNode = *pHead;
    *pHead = (*pHead)->_pNext;

    free(pDeNode);
}

//判空
int ListEmpty(PNode pHead)
{
    if(pHead == NULL)
        return 1;

    return 0;
}

//打印链表
void PrintList(PNode pHead)
{
    while(pHead)
    {
        printf("%d-->", pHead->_data);
        pHead = pHead->_pNext;
    }

    printf("NULL\n");
}

//获取链接节点个数
int ListSize(PNode pHead)
{
    int size = 0;
    while(pHead)
    {
        size++;
        pHead = pHead->_pNext;
    }

    return size;
}

PNode pHead = NULL;
//互斥锁
pthread_mutex_t mutex;
//条件变量--
pthread_cond_t cond1;
pthread_cond_t cond2;


//生产者
void* producer(void *arg)
{
    //向链表中插入节点
    while(1)
    {
        //访问临界资源之前先上锁
        pthread_mutex_lock(&mutex);

        //如果链表中已经有一个节点了，就不能再生产，需要在该条件变量下等待消费者消费，并且释放锁
        if(ListSize(pHead) == 1)
        {
            pthread_cond_wait(&cond2, &mutex);
        }
        //生产者生产
        ListPushFront(&pHead, 5);
        printf("I product:\n");
        PrintList(pHead);
        //唤醒消费者
        //这里一定是先唤醒正在等待的消费者，再释放锁，因为假设有多个消费者如果先释放锁，
        //再去唤醒等待的消费者，可能在这之间被”切走“，假设是另一个消费者”挤走它“那么该消费者消费后，
        //假设生产者再次被调度，执行”唤醒“等待操作，这时消费者再去消费就会出错。
        pthread_cond_signal(&cond1);
        pthread_mutex_unlock(&mutex);

        //这里用时间来表示优先级
        sleep(1);
    }
}


//消费者
void *consumer(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);

        //如果链表为空，消费者就不能消费，要在该条件变量下等待，并释放锁
        if(ListEmpty(pHead))
        {
            pthread_cond_wait(&cond1, &mutex);
        }

        //消费者消费
        ListPopFront(&pHead);
        printf("I consume:\n");
        PrintList(pHead);
        
        //唤醒生产者
        pthread_cond_signal(&cond2);
        //释放锁
        pthread_mutex_unlock(&mutex);
        sleep(3);
    }
}

int main()
{
    pthread_t tid1, tid2;

    //初始化互斥锁与条件变量
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond1, NULL);
    pthread_cond_init(&cond2, NULL);

    //创建生产者和消费者线程
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}
