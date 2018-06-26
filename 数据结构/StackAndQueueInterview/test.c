#include "StackAndInterview.h"
#include <Windows.h>


//void Test1()
//{
//	Stack s;
//
//	InitStack(&s);
//
//	StackPush(&s, 5);
//	StackPush(&s, 4);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 7);
//	StackPush(&s, 9);
//	StackPush(&s, 1);
//
//	StackPop(&s);
//	printf("Mindata:%d\n", StackMindata(&s));

//void Test2()
//{
//	Stack s;
//
//	InitStack(&s);
//	StackPop(&s);
//	StackPush(&s, 5);
//	StackPush(&s, 4);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 7);
//	StackPush(&s, 9);
//	StackPush(&s, 1);
//
//	StackPop(&s);
//	printf("Mindata:%d\n", StackMindata(&s));
//}



//void Test3()
//{
//	Queue q;
//
//	QueueInit(&q);
//
//	QueuePush(&q, 5);
//	QueuePush(&q, 4);
//	QueuePush(&q, 1);
//	QueuePush(&q, 3);
//	printf("Front:%d\n", QueueFront(&q));
//	QueuePop(&q);
//
//	//获取队头元素
//	printf("Front:%d\n",QueueFront(&q));
//	//获取队尾元素
//	printf("Back:%d\n",QueueBack(&q));
//
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//
//	printf("Front:%d\n", QueueFront(&q));
//	printf("Back:%d\n", QueueBack(&q));
//}

//void Test4()
//{
//	Stack s;
//	Queue q1;//先给两个队列
//	Queue q2;
//	s.q1 = &q1;
//	s.q2 = &q2;
//	StackInit(&s);
//	printf("Top:%d\n",StackTop(&s));
//
//	StackPush(&s, 5);
//	StackPush(&s, 4);
//	StackPush(&s, 3);
//	printf("Top:%d\n", StackTop(&s));
//
//	StackPop(&s);
//	printf("Top:%d\n", StackTop(&s));
//	StackPush(&s, 7);
//	StackPush(&s, 8);
//	StackPush(&s, 9);
//	printf("Top:%d\n", StackTop(&s));
//}

//void Test5()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 4, 5, 3, 2, 1 };
//
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int size2 = sizeof(arr2) / sizeof(arr2[0]);
//
//	printf("%d\n", StackIsLegal(arr, size, arr2, size2));
//
//}


void Test6()
{
	SStack s;

	StackInit(&s);
	StackPush(&s, 1, 1);
	StackPush(&s, 1, 3);
	StackPush(&s, 1, 5);
	StackPush(&s, 1, 7);
	StackPush(&s, 1, 9);
	printf("S1Top = %d\n", StackTop(&s, 1));
	StackPush(&s, 2, 2);
	StackPush(&s, 2, 4);
	StackPush(&s, 2, 6);
	StackPush(&s, 2, 8);
	StackPush(&s, 2, 10);
	printf("S2Top = %d\n", StackTop(&s, 2));

	StackPop(&s, 1);
	printf("S1Top = %d\n", StackTop(&s, 1));
	printf("S1Size = %d\n", StackSize(&s, 1));
	printf("S2Size = %d\n", StackSize(&s, 2));
	
}

int main()
{
	//Test1();//面试题1方法1
	//Test2();//面试题方法2
	//Test3();//面试题2
	//Test4();//面试题3
	//Test5();//面试题4
	Test6();//面试题5
	system("pause");
	return 0;
}