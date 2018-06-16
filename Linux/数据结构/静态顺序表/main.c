#include "SeqList.h"


int main()
{
    SeqList ps;
    SeqListInit(&ps);//初始化
    SeqListPushBack(&ps, 5);
    SeqListPushBack(&ps, 6);

    SeqListPushFront(&ps, 4);
    SeqListPushFront(&ps, 4);
    
    SeqListPopFront(&ps);

    SeqListPushPos(&ps, 2, 0);
    SeqListPushPos(&ps, 3, 1);
    SeqListPopPos(&ps, 2);

    int i = 0;
    for(; i < ps.size; i++)
        printf("%d ", ps.arr[i]);

    printf("\n");
    printf("Size = %d\n", ps.size);
    printf("Size = %d\n", SeqListSize(&ps));
    printf("Empty? %d\n", SeqListEmpty(&ps));
}
