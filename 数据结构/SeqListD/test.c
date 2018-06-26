#include "SeqListD.h"
#include <Windows.h>

void print(PSeqListD ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

int main()
{
	int capacity = 10;
	int size = 0;
	SeqListD List;
	PSeqListD ps = &List;

	SeqListDInit(ps, capacity);//初始化
	CheckCapacity(ps);// 对顺序表进行增容 
	SeqListDPushBack(ps, 10);//尾插
	SeqListDPushBack(ps, 20);
	SeqListDPushBack(ps, 10);
	//SeqListDPopBack(ps);//尾删
	SeqListDInsert(ps, 2, 50);//任意位置插入
	//SeqListDErase(ps, 2);//任意位置删除
	size = SeqListDSize(ps);// 获取元素个数 
	capacity = SeqListDCapacity(ps);// 获取顺序表的容量
	printf("size = %d\ncapacity = %d\n", size, capacity);
	
	//SeqListDEmpty(ps);//判空,为空返回0，

	//SeqListDClear(ps);// 将顺序表中的元素清空 注意：不改变顺序表空间的大小 
	//SeqListDDestroy(ps);//销毁顺序表
	print(ps);//打印顺序表

	system("pause");
	return 0;
}