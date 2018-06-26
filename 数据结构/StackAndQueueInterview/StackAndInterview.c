#include "StackAndInterview.h"
//面试题5
//一个数组实现两个栈(共享栈)
/////////////////////////////////////////
void StackInit(PSStack s)
{
	assert(s);

	s->Top1 = 0;//偶数栈从0开始
	s->Top2 = 1;//奇数栈从1开始
}

void StackPush(PSStack s, int flag, DataType data)
{
	assert(s);

	if (flag == 1)//入到偶数栈
	{
		if (s->Top1 == MAX_SIZE)
		{
			printf("栈已满!\n");
			return;
		}

		s->arr[s->Top1] = data;
		s->Top1 += 2;
	}

	else
	{
		if (s->Top1 > MAX_SIZE)
		{
			printf("栈已满!\n");
			return;
		}

		s->arr[s->Top2] = data;
		s->Top2 += 2;
	}
}

void StackPop(PSStack s, int flag)
{
	assert(s);

	if (flag == 1)//出栈1
	{
		if (s->Top1 == 0)
		{
			printf("栈已空!\n");
			return;
		}

		s->Top1 -= 2;
	}

	else
	{
		if (s->Top2 == 1)
		{
			printf("栈已空!!!\n");
			return;
		}

		s->Top2 -= 2;
	}
}

int StackSize(PSStack s, int flag)
{
	assert(s);

	if (flag == 1)
		return s->Top1 / 2;
	else
		return s->Top2 / 2;
}

int StackEmpty(PSStack s, int flag)
{
	assert(s);

	if (flag == 1)
	{
		if (s->Top1 == 0)
			return 1;
		return 0;
	}

	else
	{
		if (s->Top2 == 1)
			return 1;

		else
			return 0;
	}
}

DataType StackTop(PSStack s, int flag)
{
	assert(s);

	if (flag == 1)
	{
		if (s->Top1 == 0)
		{
			printf("栈已空!\n");
			return 0;
		}

		return s->arr[s->Top1 - 2];
	}

	else
	{
		if (s->Top2 == 1)
		{
			printf("栈已空!\n");
			return 0;
		}

		return s->arr[s->Top2 - 2];
	}
}












//面试题4
//一个数组实现两个栈(共享栈）
/////////////////////////////////////////////////////////////////////////////////////////////
//#include "StackAndInterview.h"
//
//void StackInit(PStack s)
//{
//	assert(s);
//
//	s->Top = 0;
//}
//
//void StackPush(PStack s, DataType data)
//{
//	assert(s);
//
//	if (s->Top == MAX_SIZE)
//		return;
//
//	s->arr[s->Top] = data;
//	s->Top++;
//}
//
//void StackPop(PStack s)
//{
//	assert(s);
//
//	if (s->Top == 0)
//		return;
//	s->Top--;
//
//}
//
//DataType StackTop(PStack s)
//{
//	assert(s);
//
//	if (s->Top == 0)
//	{
//		printf("栈已空\n");
//		return 0;
//	}
//
//	return s->arr[s->Top - 1];
//}
//
//int StackEmpty(PStack s)
//{
//	assert(s);
//
//	if (s->Top == 0)
//		return 1;
//
//	return 0;
//}
//
//int StackIsLegal(int* arr, int size, int* arr2, int size2)
//{
//	Stack s;
//	StackInit(&s);
//	int index = 0;
//	int outdex = 0;
//
//	assert(arr);
//	assert(arr2);
//
//	//两个数组大小都不一样，肯定不合法
//	if (size != size2)
//		return 0;
//
//	while (index < size)
//	{
//		//如果两个数组中的内容不相等，就让arr中的元素入栈
//		if (arr[index] != arr2[outdex] && index < size)
//		{
//			StackPush(&s, arr[index]);
//			index++;
//		}
//
//		//相等
//		if (arr[index] == arr2[outdex])
//		{
//			index++;
//			outdex++;
//		}
//	}
//	
//	while (!StackEmpty(&s))
//	{
//		//如果数组arr访问完了，就拿栈顶元素
//		if (StackTop(&s) == arr2[outdex])
//		{
//			StackPop(&s);
//			outdex++;
//		}
//
//		//没进入if肯定不合法
//		return 0;
//	}
//
//	if (outdex >= size2)
//		return 1;
//	else
//		return 0;
//}
//












//面试题3
//使用两个队列实现一个栈
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "StackAndInterview.h"
//
//
////创建新节点
//Node* BuyNewNode(DataType data)
//{
//	Node* ptr;
//
//	ptr = (Node*)malloc(sizeof(Node));
//	if (NULL == ptr)
//	{
//		printf("节点申请失败!!!\n");
//		return NULL;
//	}
//
//	ptr->_data = data;
//	ptr->_pNext = NULL;
//	return ptr;
//}
//
////初始化栈
//void StackInit(PStack s)
//{
//	assert(s);
//
//	//分别将两个队列初始化
//	s->q1->_pHead = s->q1->_pTail = BuyNewNode(0);
//	s->q2->_pHead = s->q2->_pTail = BuyNewNode(0);
//}
//
//
////入队列
//void QueuePush(Queue* q, DataType data)
//{
//	assert(q);
//
//	//从队尾插入，不用考虑队列为空时，因为刚开始头节点和尾节点指向同一个节点
//	q->_pTail->_pNext = BuyNewNode(data);
//	q->_pTail = q->_pTail->_pNext;
//}
//
////入栈
//void StackPush(PStack s, DataType data)
//{
//	assert(s);
//
//	//直接对q1进行入队列
//	QueuePush(s->q1, data);
//}
//
////出队列
//void QueuePop(Queue* q)
//{
//	assert(q);
//	Node* pDelete = q->_pHead->_pNext;
//
//	if (q->_pHead->_pNext == NULL)
//	{
//		printf("队列为空，操作失败!!!\n");
//		return;
//	}
//
//	//从队头出队列
//	//如果只剩一个节点，按照小面这样做，_pHead就指向NULL，而_pTail还是指向最后一个节点
//	q->_pHead->_pNext = q->_pHead->_pNext->_pNext;
//	if (pDelete->_pNext == NULL)
//		q->_pTail = q->_pHead;
//	free(pDelete);
//}
//
////队列判空
//int QueueEmpty(Queue* q)
//{
//	assert(q);
//
//	if (q->_pHead->_pNext == NULL)
//		return 1;
//	return 0;
//}
//
////获取队头元素
//DataType QueueFront(Queue* q)
//{
//	assert(q);
//
//	if (q->_pHead->_pNext == NULL)
//	{
//		printf("队列为空，操作失败！\n");
//		return 0;
//	}
//
//	return q->_pHead->_pNext->_data;
//}
//
////出栈
//void StackPop(PStack s)
//{
//	assert(s);
//	Node* ptr2 = NULL;
//
//	//如果q1不为空，q2为空，将q1元素搬移到q2只剩一个，q1队头就是栈的栈顶
//	if (!QueueEmpty(s->q1) && QueueEmpty(s->q2))
//	{
//		Node* ptr = s->q1->_pHead->_pNext;//q1的第一个有效节点
//
//		while (ptr->_pNext)
//		{
//			DataType data = QueueFront(s->q1);
//			QueuePop(s->q1);
//			QueuePush(s->q2, data);
//			ptr = s->q1->_pHead->_pNext;//必须加，否则因为释放了ptr，ptr下次就进不来了
//		}
//
//		//此时，q1中仅剩一个元素，且为栈顶元素
//		QueuePop(s->q1);
//	}
//
//	ptr2 = s->q2->_pHead->_pNext;//q2的第一个有效节点
//	//出完之后将q2中的元素再移回去保证，q2始终为空
//	while (ptr2)
//	{
//		DataType data = QueueFront(s->q2);
//		QueuePop(s->q2);
//		QueuePush(s->q1, data);
//		ptr2 = s->q2->_pHead->_pNext;//必须加，否则因为释放了ptr，ptr下次就进不来了
//	}
//	
//}
//
//
////获取栈顶元素
//DataType StackTop(PStack s)
//{
//	assert(s);
//	DataType Top = 0;
//	Node* ptr2 = NULL;
//
//	if (QueueEmpty(s->q1) && QueueEmpty(s->q2))
//	{
//		printf("栈已空!!!\n");
//		return 0;
//	}
//
//	//如果q1不为空，q2为空，将q1元素搬移到q2只剩一个，q1队头就是栈的栈顶
//	if (!QueueEmpty(s->q1) && QueueEmpty(s->q2))
//	{
//		Node* ptr = s->q1->_pHead->_pNext;//q1的第一个有效节点
//
//		while (ptr->_pNext)
//		{
//			DataType data = QueueFront(s->q1);
//			QueuePop(s->q1);
//			QueuePush(s->q2, data);
//			ptr = s->q1->_pHead->_pNext;//必须加，否则因为释放了ptr，ptr下次就进不来了
//		}
//
//		//此时，q1中仅剩一个元素，且为栈顶元素
//		Top = QueueFront(s->q1);
//		QueuePop(s->q1);
//		QueuePush(s->q2, Top);
//	}
//
//	ptr2 = s->q2->_pHead->_pNext;//q2的第一个有效节点
//	//出完之后将q2中的元素再移回去保证，q2始终为空
//	while (ptr2)
//	{
//		DataType data = QueueFront(s->q2);
//		QueuePop(s->q2);
//		QueuePush(s->q1, data);
//		ptr2 = s->q2->_pHead->_pNext;//必须加，否则因为释放了ptr，ptr下次就进不来了
//	}
//
//	return Top;
//}





















//面试题2
//使用两个栈实现一个队列
////////////////////////////////////////////////////////////////////////////////////////////
//#include "StackAndInterview.h"
//
//
//初始化队列
//void QueueInit(PQueue q)
//{
//	assert(q);
//
//	对两个栈进行初始化
//	q->s1._size = 0;
//	q->s2._size = 0;
//}
//
//入栈
//void StackPush(Stack* s, DataType data)
//{
//	assert(s);
//
//	if (s->_size == MAX_SIZE)
//	{
//		printf("栈已满!!!\n");
//		return;
//	}
//
//	s->_arr[s->_size] = data;
//	s->_size++;
//}
//
//入队列,入到栈s1
//void QueuePush(PQueue q, DataType data)
//{
//	assert(q);
//
//	if (q->s1._size == MAX_SIZE)
//	{
//		如果s2为空，才能将s1中的元素搬移到s2否则，队头和就找不到了
//		if (q->s2._size == 0)
//		{
//
//			while (q->s1._size != 0)
//			{
//				DataType data = StackTop(&(q->s1));
//				StackPop(&(q->s1));
//				StackPush(&(q->s2), data);
//			}
//		}
//		else
//		{
//			printf("队列已满!!!\n");
//			return;
//		}
//		
//	}
//
//	对s1进行入栈操作
//	StackPush(&(q->s1), data);
//}
//
//
//返回栈顶元素
//DataType StackTop(Stack* s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("栈已空！\n");
//		return 0;
//	}
//
//	return s->_arr[s->_size - 1];
//}
//
//出栈
//void StackPop(Stack* s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("栈为空，操作失败!!!\n");
//		return;
//	}
//
//	s->_size--;
//}
//
//出队列
//void QueuePop(PQueue q)
//{
//	assert(q);
//	
//	如果s2不为空，那么s2的栈顶元素就是队头，直接出队列
//	if (q->s2._size > 0)
//	{
//		StackPop(&(q->s2));
//		return;
//	}
//
//	如果s2为空
//	else
//	{
//		如果s1也为空，队列为空
//		if (q->s1._size == 0)
//		{
//			printf("队列为空，操作失败!!!\n");
//			return;
//		}
//
//		如果s1不为空，将s1的数据倒过来
//		else
//		{
//			while (q->s1._size != 0)
//			{
//				DataType data = StackTop(&(q->s1));
//				StackPop(&(q->s1));
//				StackPush(&(q->s2), data);
//			}
//			
//			此时，s2的栈顶就是队头
//			StackPop(&(q->s2));
//		}
//
//	}
//}
//
//
//获取队头元素
//DataType QueueFront(PQueue q)
//{
//	assert(q);
//
//	如果s1和s2都为空，说明队列为空
//	if (q->s1._size == 0 && q->s2._size == 0)
//	{
//		printf("队列为空，操作失败!!!\n");
//		return 0;
//	}
//
//	如果s2不为空，那么队头就是s2的栈顶，否则，就是s1的栈底
//	if (q->s2._size != 0)
//		return StackTop(&(q->s2));
//	else
//		return q->s1._arr[0];
//
//}
//
//获取队尾元素
//DataType QueueBack(PQueue q)
//{
//	assert(q);
//
//	如果s1和s2都为空，说明队列为空
//	if (q->s1._size == 0 && q->s2._size == 0)
//	{
//		printf("队列为空，操作失败!!!\n");
//		return 0;
//	}
//
//	如果s1不为空，那么队尾就是s1的栈顶，否则，就是s2的栈底
//	if (q->s1._size != 0)
//		return StackTop(&(q->s1));
//	else
//		return q->s2._arr[0];
//
//}

















































//面试题1方法2
//实现一个栈，要求实现Push(出栈)、Pop(入栈)、Min(返回最小值)的时间复杂度为O(1)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "StackAndInterview.h"
//
////初始化栈
//void InitStack(PStack s)
//{
//	assert(s);
//	
//	//将两个栈分别初始化
//	s->s1._size = 0;
//
//	s->s2._size = 0;
//}
//
////入栈
//void StackPush(PStack s, DataType data)
//{
//	assert(s);
//
//	if (s->s1._size == MAX_SIZE)
//	{
//		printf("栈已满!!!\n");
//		return;
//	}
//
//	//若栈为空，直接入栈
//	if (s->s1._size == 0)
//	{
//		s->s1._arr[0] = data;
//		s->s2._arr[0] = data;
//		s->s1._size++;
//		s->s2._size++;
//	}
//	else
//	{
//		//如果data小于，s2栈中的栈顶元素，将data入栈到S2
//		if (data <= StackTop(&(s->s2)))
//		{
//			s->s2._arr[s->s2._size] = data;
//			s->s2._size++;
//		}
//		s->s1._arr[s->s1._size] = data;
//		s->s1._size++;
//	}
//	
//}
//
//
////获取栈顶元素
//DataType StackTop(Stack2* s2)
//{
//	assert(s2);
//
//	if (s2->_size == 0)
//	{
//		printf("栈已空!!!\n");
//		return 0;
//	}
//
//	return s2->_arr[s2->_size - 1];
//}
//
////出栈
//void StackPop(PStack s)
//{
//	assert(s);
//
//	if (s->s1._size == 0)
//	{
//		printf("栈已空!\n");
//		return;
//	}
//
//	//如果两个栈栈顶元素相等，都出栈
//	if (s->s1._arr[s->s1._size - 1] == StackTop(&(s->s2)))
//	{
//		s->s1._size--;
//		s->s2._size--;
//	}
//
//	else
//		s->s1._size--;
//}
//
////获取最小值
//DataType StackMindata(PStack s)
//{
//	assert(s);
//
//	if (s->s1._size == 0)
//	{
//		printf("栈已空!!!\n");
//		return 0;
//	}
//
//	return StackTop(&(s->s2));
//}



























////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//面试题1方法1
//#include "StackAndInterview.h"
//
////初始化栈
//void InitStack(PStack s)
//{
//	assert(s);
//
//	//初始化只需将有效元素清零
//	s->_size = 0;
//}
//
//
////给栈顶插入元素
//void StackPush(PStack s, int data)
//{
//	assert(s);
//
//	int size = s->_size;
//
//	if (size == MAX_SIZE)
//	{
//		printf("栈已满!!!\n");
//		return;
//	}
//
//	//如果栈是空的，那么最小data和data都是data
//	if (size == 0)
//	{
//		s->_arr->data = s->_arr->Mindata = data;
//		s->_size++;
//		return;
//	}
//
//	//如果栈不为空，比较data与栈的最小元素，1.若data小，那么用data更新最小元素
//	if ((s->_arr + size - 1)->Mindata >= data)
//	{
//		(s->_arr + size)->Mindata = (s->_arr + size)->data = data;
//		s->_size++;
//		return;
//	}
//	//2.若栈的最小元素小，新插入的data还是data，Mindata用原栈中的Mindata更新
//	else
//	{
//		(s->_arr + size)->Mindata = (s->_arr + size - 1)->Mindata;
//		(s->_arr + size)->data = data;
//		s->_size++;
//	}
//
//}
//
////从栈顶出栈
//void StackPop(PStack s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("栈已空!!!\n");
//		return;
//	}
//
//	s->_size--;
//}
//
////返回栈最小元素
//int StackMindata(PStack s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("栈已空，操作失败!!!\n");
//		return 0;
//	}
//
//	return (s->_arr + (s->_size - 1))->Mindata;
//}