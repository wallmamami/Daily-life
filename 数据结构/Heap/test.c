#include "Heap.h"
#include "PriorityQueue.h"

void Test1()
{
	int i = 0;
	Heap hp;
	DataType arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(arr) / sizeof(arr[0]);

	HeapInit(&hp, Less);//��ʼ����
	CreateHeap(&hp, arr, size);//������,���һ�������Ǻ���ָ�����ͣ�ѡ�񴴽���ѻ�С��
	InsertHeap(&hp, 11);//��Ѳ���Ԫ��
	DeleteHeap(&hp);//ɾ���Ѷ�Ԫ��
	printf("Top = %d  Size = %d\n", HeapTop(&hp), HeapSize(&hp));

	DestoryHeap(&hp);//���ٶ�


}

void Test2()
{
	PriorityQueue q;

	PriorityQueueInit(&q);
	PriorityQueuePush(&q, 53);
	PriorityQueuePush(&q, 17);
	PriorityQueuePush(&q, 78);
	PriorityQueuePush(&q, 9);
	PriorityQueuePush(&q, 45);
	PriorityQueuePush(&q, 65);
	PriorityQueuePush(&q, 87);
	PriorityQueuePush(&q, 23);
	PriorityQueuePush(&q, 31);
	printf("Front = %d Back = %d Size = %d\n", PriorityQueueFront(&q), PriorityQueueBack(&q), PriorityQueueSize(&q));
	PriorityQueuePop(&q);
	printf("Front = %d Back = %d Size = %d\n", PriorityQueueFront(&q), PriorityQueueBack(&q), PriorityQueueSize(&q));
	
	PriorityQueueDestory(&q);
}

void Test3()
{
	int i = 0;
	int arr[] = { 8, 9, 2, 78, 54, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr, size);
	for (; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	//Test1();//���Զ�
	//Test2();//�������ȼ�����
	Test3();//���Զ���
}