#include "Queue.h"
#include <Windows.h>


void TestQueue()
{
	struct Queue q;

	InitQueue(&q);
	QueueEmpty(&q);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 1);
	QueuePush(&q, 2);

	QueuePop(&q);
	QueueEmpty(&q);
	QueueFront(&q);
	QueueBack(&q);
	QueueSize(&q);
	
}

int main()
{
	TestQueue();//

	system("pause");
	return 0;
}