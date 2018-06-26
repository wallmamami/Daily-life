#include "stack.h"
#include "Maze.h"

//初始化栈，有效元素清空，分配起始空间
void StackInit(PStack ps, int capacity)
{
	if (NULL == ps)
		return;

	ps->arr = (DataType *)malloc(sizeof(DataType)*capacity);

	if (NULL == ps->arr)
	{
		printf("申请空间失败!!!\n");
		return;
	}

	ps->capacity = capacity;//空间容量改变
	ps->size = 0;//有效元素清空

}

void AddCapacity(PStack ps)
{
	if (NULL == ps)
		return;

	ps->arr = (DataType *)realloc(ps->arr, sizeof(DataType)*(ps->capacity) * 2);//扩增位原空间大小二倍

	if (NULL == ps->arr)
	{
		printf("空间扩增失败!!!\n");
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

//入栈，就是对表进行尾插
void StackPush(PStack ps, DataType data)
{
	if (NULL == ps)
		return;

	if (ps->size == ps->capacity)//说明空间已满，要申请空间
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
		//printf("栈已空，操作失败!!!\n");
		return;
	}

	ps->size--;
}

// 获取栈顶元素,栈顶就是表的尾部
DataType StackTop(PStack ps)
{
	//if (NULL == ps)
	//{
	//	printf("栈不存在!!!\n");
	//	return 0;
	//}

	//if (ps->size == 0)
	//{
	//	printf("栈已空!!!\n");
	//	return 0;
	//}

	return ps->arr[ps->size - 1];
}

// 获取栈中元素个数 
int StackSize(PStack ps)
{
	if (NULL == ps)
	{
		printf("栈不存在!!!\n");
		return 0;
	}

	return ps->size;
}

// 检测栈是否为空 
int StackEmpty(PStack ps)
{
	if (NULL == ps)
	{
		printf("栈不存在!!!\n");
		return 0;
	}
	
	if (ps->size)
		return 0;
	return 1;

}

//判断是否是括号
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
////括号匹配问题
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
//			//如果是左括号，入栈
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
//					printf("右括号比左多!!!\n");
//					return;
//				}
//				else
//				{
//					char top = StackTop(ps);
//					if ((top == '(' && a[i] == ')') ||
//						(top == '[' && a[i] == ']') ||
//						(top == '{' && a[i] == '}'))//匹配成功，出栈
//						StackPop(ps);
//					else
//					{
//						printf("括号次序不正确!!!\n");
//						return;
//					}
//				}
//			}
//		}
//	}
//
//	//循环完成，如果栈里还有元素说明左括号太多
//	if (StackEmpty(ps))
//	{
//		printf("括号匹配!!!\n");
//		return;
//	}
//	else
//		printf("左比右多!!!\n");
//}
//
////计算逆波兰表达式
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
//		//如果是字符类的数字，那就将其转换为数字
//		if (a[i] >= '0' && a[i] <= '9')
//		{
//			num = num * 10 + a[i] - '0';
//			flag = 1;//为了区分操作符后面的空格
//		}
//
//		//如果是空格，就先将num入栈，然后num清零
//		else if (a[i] == ' ' && flag == 1)
//		{
//			StackPush(ps, num);
//			num = 0;
//			flag = 0;//每次都将flag置零
//		}
//
//		//如果是操作符，就将栈顶上的数字取出计算，最上为右操作数
//		else
//		{
//			int left = 0;
//			int right = 0;
//			//排除操作符后面的空格
//			if (a[i] == ' ')
//				continue;
//			//取出左右操作数
//			right = StackTop(ps);
//			StackPop(ps);
//			left = StackTop(ps);
//			StackPop(ps);
//
//			//将计算的结果入栈
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