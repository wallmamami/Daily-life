#include "SeqList.h"

//初始化
void SeqListInit(PSqList ps)
{
    assert(ps);

    ps->size = 0;
}


//尾插
void SeqListPushBack(PSqList ps, DataType data)
{
    assert(ps);

    if(ps->size == MAX_SIZE)
    {
        printf("表已满，操作失败!\n");
        return;
    }

    ps->arr[ps->size] = data;
    ps->size++;
}

//尾删
void SeqListPopBack(PSqList ps)
{
    assert(ps);

    if(ps->size == 0)
    {
        printf("表已空!\n");
        return;
    }

    ps->size--;
}

//头插
void SeqListPushFront(PSqList ps, DataType data)
{
    assert(ps);

    if(ps->size == MAX_SIZE)
    {
        printf("表满!\n");
        return;
    }

    int i = ps->size;
    for(; i >= 1; i--)
    {
       ps->arr[i] = ps->arr[i-1];
    }

    ps->arr[0] = data;
    ps->size++;
}

//头删
void SeqListPopFront(PSqList ps)
{
    assert(ps);

    if(ps->size == 0)
    {
        printf("表空!\n");
        return;
    }

    int i = 0;
    for(; i < ps->size-1; i++)
    {
        ps->arr[i] = ps->arr[i+1];
    }

    ps->size--;
}

//在pos位置上插入元素
void SeqListPushPos(PSqList ps, DataType data, int pos)
{
    assert(ps);

    if(ps->size == MAX_SIZE)
        return;

    if(!(pos >= 0 && pos <= ps->size))
        return;

    int i = ps->size;

    for(; i>pos; i--)
    {
        ps->arr[i] = ps->arr[i-1];
    }

    ps->arr[pos] = data;
    ps->size++;

}

//在pos位置上删除元素
void SeqListPopPos(PSqList ps, int pos)
{
    assert(ps);

    if(ps->size == 0)
        return;

    if(!(pos >= 0 && pos < ps->size))
        return;

    int i = pos;
    for(; i < ps->size-1; i++)
    {
        ps->arr[i] = ps->arr[i+1];
    }

    ps->size--;
}


//查找值为data的元素
int FindData(PSqList ps, DataType data)
{
    assert(ps);

    int i = 0;
    for(; i<ps->size; i++)
    {
        if(ps->arr[i] == data)
            return i;
    }

    return -1;
}

//删除第一个值为data的元素
void RemoveData(PSqList ps, DataType data)
{
    assert(ps);

    int pos = FindData(ps, data);
    SeqListPopPos(ps, pos);
}

//删除所有值为data的元素
void RemoveAllData(PSqList ps, DataType data)
{
    assert(ps);

    int count = 0;//用来统计共有多少data
    int i = 0;

    for(; i<ps->size; i++)
    {
        if(ps->arr[i] == data)
            count++;
        else
            ps->arr[i-count] = ps->arr[i];//朝前搬移count位
        
    }

    ps->size -= count;
}


//有效元素个数
int SeqListSize(PSqList ps)
{
    assert(ps);
    return ps->size;
}

//判空
int SeqListEmpty(PSqList ps)
{
    return ps->size == 0;
}














