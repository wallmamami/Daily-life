#include "stack.h"
#include "Maze.h"

//��ʼ��ջ����ЧԪ����գ�������ʼ�ռ�
void StackInit(PStack ps, int capacity)
{
	if (NULL == ps)
		return;

	ps->arr = (DataType *)malloc(sizeof(DataType)*capacity);

	if (NULL == ps->arr)
	{
		printf("����ռ�ʧ��!!!\n");
		return;
	}

	ps->capacity = capacity;//�ռ������ı�
	ps->size = 0;//��ЧԪ�����

}

void AddCapacity(PStack ps)
{
	if (NULL == ps)
		return;

	ps->arr = (DataType *)realloc(ps->arr, sizeof(DataType)*(ps->capacity) * 2);//����λԭ�ռ��С����

	if (NULL == ps->arr)
	{
		printf("�ռ�����ʧ��!!!\n");
		return;
	}

	ps->capacity = 2 * (ps->capacity);

}

void PrintStack(PStack ps)
{
	int i = 0;
	if (NULL == ps)
		return;

	for (; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//��ջ�����ǶԱ����β��
void StackPush(PStack ps, DataType data)
{
	if (NULL == ps)
		return;

	if (ps->size == ps->capacity)//˵���ռ�������Ҫ����ռ�
		AddCapacity(ps);

	ps->arr[ps->size] = data;
	ps->size++;

}

void StackPop(PStack ps)
{
	if (NULL == ps)
		return;

	if (ps->size == 0)
	{
		//printf("ջ�ѿգ�����ʧ��!!!\n");
		return;
	}

	ps->size--;
}

// ��ȡջ��Ԫ��,ջ�����Ǳ��β��
DataType StackTop(PStack ps)
{
	//if (NULL == ps)
	//{
	//	printf("ջ������!!!\n");
	//	return 0;
	//}

	//if (ps->size == 0)
	//{
	//	printf("ջ�ѿ�!!!\n");
	//	return 0;
	//}

	return ps->arr[ps->size - 1];
}

// ��ȡջ��Ԫ�ظ��� 
int StackSize(PStack ps)
{
	if (NULL == ps)
	{
		printf("ջ������!!!\n");
		return 0;
	}

	return ps->size;
}

// ���ջ�Ƿ�Ϊ�� 
int StackEmpty(PStack ps)
{
	if (NULL == ps)
	{
		printf("ջ������!!!\n");
		return 0;
	}
	
	if (ps->size)
		return 0;
	return 1;

}

//�ж��Ƿ�������
//int IsBrackets(char *ptr)
//{
//	if (NULL == ptr)
//		return 0;
//	if (*ptr == '(' || *ptr == ')' ||
//		*ptr == '[' || *ptr == ']' ||
//		*ptr == '{' || *ptr == '}')
//		return 1;
//	else
//		return 0;
//}
//
////����ƥ������
//void IsMach(char *a, PStack ps)
//{
//	int i = 0;
//	int len = strlen(a);
//
//	if (NULL == ps)
//		return;
//	
//	if (NULL == a)
//		return;
//
//	for (; i < len; ++i)
//	{
//		if (IsBrackets(a + i))
//		{
//			//����������ţ���ջ
//			if (a[i] == '(' || a[i] == '[' || a[i] == '{')
//			{
//				StackPush(ps, a[i]);
//				continue;
//
//			}
//			else
//			{
//				if (StackEmpty(ps))
//				{
//					printf("�����ű����!!!\n");
//					return;
//				}
//				else
//				{
//					char top = StackTop(ps);
//					if ((top == '(' && a[i] == ')') ||
//						(top == '[' && a[i] == ']') ||
//						(top == '{' && a[i] == '}'))//ƥ��ɹ�����ջ
//						StackPop(ps);
//					else
//					{
//						printf("���Ŵ�����ȷ!!!\n");
//						return;
//					}
//				}
//			}
//		}
//	}
//
//	//ѭ����ɣ����ջ�ﻹ��Ԫ��˵��������̫��
//	if (StackEmpty(ps))
//	{
//		printf("����ƥ��!!!\n");
//		return;
//	}
//	else
//		printf("����Ҷ�!!!\n");
//}
//
////�����沨�����ʽ
//void Calculate(char *a, PStack ps)
//{
//	int i = 0;
//	int len = 0;
//	int num = 0;
//	int flag = 0;
//
//	if (NULL == a)
//		return;
//
//	if (NULL == ps)
//		return;
//	
//	len = strlen(a);
//	for (; i < len; ++i)
//	{
//		//������ַ�������֣��Ǿͽ���ת��Ϊ����
//		if (a[i] >= '0' && a[i] <= '9')
//		{
//			num = num * 10 + a[i] - '0';
//			flag = 1;//Ϊ�����ֲ���������Ŀո�
//		}
//
//		//����ǿո񣬾��Ƚ�num��ջ��Ȼ��num����
//		else if (a[i] == ' ' && flag == 1)
//		{
//			StackPush(ps, num);
//			num = 0;
//			flag = 0;//ÿ�ζ���flag����
//		}
//
//		//����ǲ��������ͽ�ջ���ϵ�����ȡ�����㣬����Ϊ�Ҳ�����
//		else
//		{
//			int left = 0;
//			int right = 0;
//			//�ų�����������Ŀո�
//			if (a[i] == ' ')
//				continue;
//			//ȡ�����Ҳ�����
//			right = StackTop(ps);
//			StackPop(ps);
//			left = StackTop(ps);
//			StackPop(ps);
//
//			//������Ľ����ջ
//			switch (a[i])
//			{
//			case '+':
//				StackPush(ps, left + right);
//				break;
//			case '-':
//				StackPush(ps, left - right);
//				break;
//			case '*':
//				StackPush(ps, left * right);
//				break;
//			case '/':
//				StackPush(ps, left / right);
//				break;
//			default:
//				break;
//			}
//		}
//		
//	}
//
//}