#include "StackAndInterview.h"
//������5
//һ������ʵ������ջ(����ջ)
/////////////////////////////////////////
void StackInit(PSStack s)
{
	assert(s);

	s->Top1 = 0;//ż��ջ��0��ʼ
	s->Top2 = 1;//����ջ��1��ʼ
}

void StackPush(PSStack s, int flag, DataType data)
{
	assert(s);

	if (flag == 1)//�뵽ż��ջ
	{
		if (s->Top1 == MAX_SIZE)
		{
			printf("ջ����!\n");
			return;
		}

		s->arr[s->Top1] = data;
		s->Top1 += 2;
	}

	else
	{
		if (s->Top1 > MAX_SIZE)
		{
			printf("ջ����!\n");
			return;
		}

		s->arr[s->Top2] = data;
		s->Top2 += 2;
	}
}

void StackPop(PSStack s, int flag)
{
	assert(s);

	if (flag == 1)//��ջ1
	{
		if (s->Top1 == 0)
		{
			printf("ջ�ѿ�!\n");
			return;
		}

		s->Top1 -= 2;
	}

	else
	{
		if (s->Top2 == 1)
		{
			printf("ջ�ѿ�!!!\n");
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
			printf("ջ�ѿ�!\n");
			return 0;
		}

		return s->arr[s->Top1 - 2];
	}

	else
	{
		if (s->Top2 == 1)
		{
			printf("ջ�ѿ�!\n");
			return 0;
		}

		return s->arr[s->Top2 - 2];
	}
}












//������4
//һ������ʵ������ջ(����ջ��
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
//		printf("ջ�ѿ�\n");
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
//	//���������С����һ�����϶����Ϸ�
//	if (size != size2)
//		return 0;
//
//	while (index < size)
//	{
//		//������������е����ݲ���ȣ�����arr�е�Ԫ����ջ
//		if (arr[index] != arr2[outdex] && index < size)
//		{
//			StackPush(&s, arr[index]);
//			index++;
//		}
//
//		//���
//		if (arr[index] == arr2[outdex])
//		{
//			index++;
//			outdex++;
//		}
//	}
//	
//	while (!StackEmpty(&s))
//	{
//		//�������arr�������ˣ�����ջ��Ԫ��
//		if (StackTop(&s) == arr2[outdex])
//		{
//			StackPop(&s);
//			outdex++;
//		}
//
//		//û����if�϶����Ϸ�
//		return 0;
//	}
//
//	if (outdex >= size2)
//		return 1;
//	else
//		return 0;
//}
//












//������3
//ʹ����������ʵ��һ��ջ
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "StackAndInterview.h"
//
//
////�����½ڵ�
//Node* BuyNewNode(DataType data)
//{
//	Node* ptr;
//
//	ptr = (Node*)malloc(sizeof(Node));
//	if (NULL == ptr)
//	{
//		printf("�ڵ�����ʧ��!!!\n");
//		return NULL;
//	}
//
//	ptr->_data = data;
//	ptr->_pNext = NULL;
//	return ptr;
//}
//
////��ʼ��ջ
//void StackInit(PStack s)
//{
//	assert(s);
//
//	//�ֱ��������г�ʼ��
//	s->q1->_pHead = s->q1->_pTail = BuyNewNode(0);
//	s->q2->_pHead = s->q2->_pTail = BuyNewNode(0);
//}
//
//
////�����
//void QueuePush(Queue* q, DataType data)
//{
//	assert(q);
//
//	//�Ӷ�β���룬���ÿ��Ƕ���Ϊ��ʱ����Ϊ�տ�ʼͷ�ڵ��β�ڵ�ָ��ͬһ���ڵ�
//	q->_pTail->_pNext = BuyNewNode(data);
//	q->_pTail = q->_pTail->_pNext;
//}
//
////��ջ
//void StackPush(PStack s, DataType data)
//{
//	assert(s);
//
//	//ֱ�Ӷ�q1���������
//	QueuePush(s->q1, data);
//}
//
////������
//void QueuePop(Queue* q)
//{
//	assert(q);
//	Node* pDelete = q->_pHead->_pNext;
//
//	if (q->_pHead->_pNext == NULL)
//	{
//		printf("����Ϊ�գ�����ʧ��!!!\n");
//		return;
//	}
//
//	//�Ӷ�ͷ������
//	//���ֻʣһ���ڵ㣬����С����������_pHead��ָ��NULL����_pTail����ָ�����һ���ڵ�
//	q->_pHead->_pNext = q->_pHead->_pNext->_pNext;
//	if (pDelete->_pNext == NULL)
//		q->_pTail = q->_pHead;
//	free(pDelete);
//}
//
////�����п�
//int QueueEmpty(Queue* q)
//{
//	assert(q);
//
//	if (q->_pHead->_pNext == NULL)
//		return 1;
//	return 0;
//}
//
////��ȡ��ͷԪ��
//DataType QueueFront(Queue* q)
//{
//	assert(q);
//
//	if (q->_pHead->_pNext == NULL)
//	{
//		printf("����Ϊ�գ�����ʧ�ܣ�\n");
//		return 0;
//	}
//
//	return q->_pHead->_pNext->_data;
//}
//
////��ջ
//void StackPop(PStack s)
//{
//	assert(s);
//	Node* ptr2 = NULL;
//
//	//���q1��Ϊ�գ�q2Ϊ�գ���q1Ԫ�ذ��Ƶ�q2ֻʣһ����q1��ͷ����ջ��ջ��
//	if (!QueueEmpty(s->q1) && QueueEmpty(s->q2))
//	{
//		Node* ptr = s->q1->_pHead->_pNext;//q1�ĵ�һ����Ч�ڵ�
//
//		while (ptr->_pNext)
//		{
//			DataType data = QueueFront(s->q1);
//			QueuePop(s->q1);
//			QueuePush(s->q2, data);
//			ptr = s->q1->_pHead->_pNext;//����ӣ�������Ϊ�ͷ���ptr��ptr�´ξͽ�������
//		}
//
//		//��ʱ��q1�н�ʣһ��Ԫ�أ���Ϊջ��Ԫ��
//		QueuePop(s->q1);
//	}
//
//	ptr2 = s->q2->_pHead->_pNext;//q2�ĵ�һ����Ч�ڵ�
//	//����֮��q2�е�Ԫ�����ƻ�ȥ��֤��q2ʼ��Ϊ��
//	while (ptr2)
//	{
//		DataType data = QueueFront(s->q2);
//		QueuePop(s->q2);
//		QueuePush(s->q1, data);
//		ptr2 = s->q2->_pHead->_pNext;//����ӣ�������Ϊ�ͷ���ptr��ptr�´ξͽ�������
//	}
//	
//}
//
//
////��ȡջ��Ԫ��
//DataType StackTop(PStack s)
//{
//	assert(s);
//	DataType Top = 0;
//	Node* ptr2 = NULL;
//
//	if (QueueEmpty(s->q1) && QueueEmpty(s->q2))
//	{
//		printf("ջ�ѿ�!!!\n");
//		return 0;
//	}
//
//	//���q1��Ϊ�գ�q2Ϊ�գ���q1Ԫ�ذ��Ƶ�q2ֻʣһ����q1��ͷ����ջ��ջ��
//	if (!QueueEmpty(s->q1) && QueueEmpty(s->q2))
//	{
//		Node* ptr = s->q1->_pHead->_pNext;//q1�ĵ�һ����Ч�ڵ�
//
//		while (ptr->_pNext)
//		{
//			DataType data = QueueFront(s->q1);
//			QueuePop(s->q1);
//			QueuePush(s->q2, data);
//			ptr = s->q1->_pHead->_pNext;//����ӣ�������Ϊ�ͷ���ptr��ptr�´ξͽ�������
//		}
//
//		//��ʱ��q1�н�ʣһ��Ԫ�أ���Ϊջ��Ԫ��
//		Top = QueueFront(s->q1);
//		QueuePop(s->q1);
//		QueuePush(s->q2, Top);
//	}
//
//	ptr2 = s->q2->_pHead->_pNext;//q2�ĵ�һ����Ч�ڵ�
//	//����֮��q2�е�Ԫ�����ƻ�ȥ��֤��q2ʼ��Ϊ��
//	while (ptr2)
//	{
//		DataType data = QueueFront(s->q2);
//		QueuePop(s->q2);
//		QueuePush(s->q1, data);
//		ptr2 = s->q2->_pHead->_pNext;//����ӣ�������Ϊ�ͷ���ptr��ptr�´ξͽ�������
//	}
//
//	return Top;
//}





















//������2
//ʹ������ջʵ��һ������
////////////////////////////////////////////////////////////////////////////////////////////
//#include "StackAndInterview.h"
//
//
//��ʼ������
//void QueueInit(PQueue q)
//{
//	assert(q);
//
//	������ջ���г�ʼ��
//	q->s1._size = 0;
//	q->s2._size = 0;
//}
//
//��ջ
//void StackPush(Stack* s, DataType data)
//{
//	assert(s);
//
//	if (s->_size == MAX_SIZE)
//	{
//		printf("ջ����!!!\n");
//		return;
//	}
//
//	s->_arr[s->_size] = data;
//	s->_size++;
//}
//
//�����,�뵽ջs1
//void QueuePush(PQueue q, DataType data)
//{
//	assert(q);
//
//	if (q->s1._size == MAX_SIZE)
//	{
//		���s2Ϊ�գ����ܽ�s1�е�Ԫ�ذ��Ƶ�s2���򣬶�ͷ�;��Ҳ�����
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
//			printf("��������!!!\n");
//			return;
//		}
//		
//	}
//
//	��s1������ջ����
//	StackPush(&(q->s1), data);
//}
//
//
//����ջ��Ԫ��
//DataType StackTop(Stack* s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("ջ�ѿգ�\n");
//		return 0;
//	}
//
//	return s->_arr[s->_size - 1];
//}
//
//��ջ
//void StackPop(Stack* s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("ջΪ�գ�����ʧ��!!!\n");
//		return;
//	}
//
//	s->_size--;
//}
//
//������
//void QueuePop(PQueue q)
//{
//	assert(q);
//	
//	���s2��Ϊ�գ���ôs2��ջ��Ԫ�ؾ��Ƕ�ͷ��ֱ�ӳ�����
//	if (q->s2._size > 0)
//	{
//		StackPop(&(q->s2));
//		return;
//	}
//
//	���s2Ϊ��
//	else
//	{
//		���s1ҲΪ�գ�����Ϊ��
//		if (q->s1._size == 0)
//		{
//			printf("����Ϊ�գ�����ʧ��!!!\n");
//			return;
//		}
//
//		���s1��Ϊ�գ���s1�����ݵ�����
//		else
//		{
//			while (q->s1._size != 0)
//			{
//				DataType data = StackTop(&(q->s1));
//				StackPop(&(q->s1));
//				StackPush(&(q->s2), data);
//			}
//			
//			��ʱ��s2��ջ�����Ƕ�ͷ
//			StackPop(&(q->s2));
//		}
//
//	}
//}
//
//
//��ȡ��ͷԪ��
//DataType QueueFront(PQueue q)
//{
//	assert(q);
//
//	���s1��s2��Ϊ�գ�˵������Ϊ��
//	if (q->s1._size == 0 && q->s2._size == 0)
//	{
//		printf("����Ϊ�գ�����ʧ��!!!\n");
//		return 0;
//	}
//
//	���s2��Ϊ�գ���ô��ͷ����s2��ջ�������򣬾���s1��ջ��
//	if (q->s2._size != 0)
//		return StackTop(&(q->s2));
//	else
//		return q->s1._arr[0];
//
//}
//
//��ȡ��βԪ��
//DataType QueueBack(PQueue q)
//{
//	assert(q);
//
//	���s1��s2��Ϊ�գ�˵������Ϊ��
//	if (q->s1._size == 0 && q->s2._size == 0)
//	{
//		printf("����Ϊ�գ�����ʧ��!!!\n");
//		return 0;
//	}
//
//	���s1��Ϊ�գ���ô��β����s1��ջ�������򣬾���s2��ջ��
//	if (q->s1._size != 0)
//		return StackTop(&(q->s1));
//	else
//		return q->s2._arr[0];
//
//}

















































//������1����2
//ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ�临�Ӷ�ΪO(1)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "StackAndInterview.h"
//
////��ʼ��ջ
//void InitStack(PStack s)
//{
//	assert(s);
//	
//	//������ջ�ֱ��ʼ��
//	s->s1._size = 0;
//
//	s->s2._size = 0;
//}
//
////��ջ
//void StackPush(PStack s, DataType data)
//{
//	assert(s);
//
//	if (s->s1._size == MAX_SIZE)
//	{
//		printf("ջ����!!!\n");
//		return;
//	}
//
//	//��ջΪ�գ�ֱ����ջ
//	if (s->s1._size == 0)
//	{
//		s->s1._arr[0] = data;
//		s->s2._arr[0] = data;
//		s->s1._size++;
//		s->s2._size++;
//	}
//	else
//	{
//		//���dataС�ڣ�s2ջ�е�ջ��Ԫ�أ���data��ջ��S2
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
////��ȡջ��Ԫ��
//DataType StackTop(Stack2* s2)
//{
//	assert(s2);
//
//	if (s2->_size == 0)
//	{
//		printf("ջ�ѿ�!!!\n");
//		return 0;
//	}
//
//	return s2->_arr[s2->_size - 1];
//}
//
////��ջ
//void StackPop(PStack s)
//{
//	assert(s);
//
//	if (s->s1._size == 0)
//	{
//		printf("ջ�ѿ�!\n");
//		return;
//	}
//
//	//�������ջջ��Ԫ����ȣ�����ջ
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
////��ȡ��Сֵ
//DataType StackMindata(PStack s)
//{
//	assert(s);
//
//	if (s->s1._size == 0)
//	{
//		printf("ջ�ѿ�!!!\n");
//		return 0;
//	}
//
//	return StackTop(&(s->s2));
//}



























////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//������1����1
//#include "StackAndInterview.h"
//
////��ʼ��ջ
//void InitStack(PStack s)
//{
//	assert(s);
//
//	//��ʼ��ֻ�轫��ЧԪ������
//	s->_size = 0;
//}
//
//
////��ջ������Ԫ��
//void StackPush(PStack s, int data)
//{
//	assert(s);
//
//	int size = s->_size;
//
//	if (size == MAX_SIZE)
//	{
//		printf("ջ����!!!\n");
//		return;
//	}
//
//	//���ջ�ǿյģ���ô��Сdata��data����data
//	if (size == 0)
//	{
//		s->_arr->data = s->_arr->Mindata = data;
//		s->_size++;
//		return;
//	}
//
//	//���ջ��Ϊ�գ��Ƚ�data��ջ����СԪ�أ�1.��dataС����ô��data������СԪ��
//	if ((s->_arr + size - 1)->Mindata >= data)
//	{
//		(s->_arr + size)->Mindata = (s->_arr + size)->data = data;
//		s->_size++;
//		return;
//	}
//	//2.��ջ����СԪ��С���²����data����data��Mindata��ԭջ�е�Mindata����
//	else
//	{
//		(s->_arr + size)->Mindata = (s->_arr + size - 1)->Mindata;
//		(s->_arr + size)->data = data;
//		s->_size++;
//	}
//
//}
//
////��ջ����ջ
//void StackPop(PStack s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("ջ�ѿ�!!!\n");
//		return;
//	}
//
//	s->_size--;
//}
//
////����ջ��СԪ��
//int StackMindata(PStack s)
//{
//	assert(s);
//
//	if (s->_size == 0)
//	{
//		printf("ջ�ѿգ�����ʧ��!!!\n");
//		return 0;
//	}
//
//	return (s->_arr + (s->_size - 1))->Mindata;
//}