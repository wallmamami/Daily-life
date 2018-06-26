#include "stack.h"
#include "Maze.h"
#include <windows.h>

//void TestStack(ps)
//{
//
//	StackInit(ps, 3);
//	StackPush(ps, 2);// 入栈 
//	StackPush(ps, 4);
//	StackPop(ps);//出栈
//	StackPop(ps);//出栈
//	printf("%d\n", StackEmpty(ps));
//	PrintStack(ps);
//}
//
//void Test1(ps)
//{
//	StackInit(ps, 10);
//	//char a[] = "(())abc{[(])}"; 
//	//char a[] = "(()))abc{[]}";
//	//char a[] = "(()()abc{[]}";
//	//char a[] = "(())abc{[]()}";
//	//IsMach(a, ps);//测试是否匹配
//	char a[] = "12 3 4 + * 6 - 8 2 / +";//后缀表达式
//	printf("%s\n", a);
//	Calculate(a, ps);
//	printf("%d\n", StackTop(ps));
//}

void TestMaze(PStack ps)
{
	int i = 0;
	Position entry;
	Maze m;
	PMaze pm = &m;
	StackInit(ps, 10);
	/*int map[6][6] = { { 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 } };*/

	int map[4][4] = { { 0, 0, 0, 0 },
	                  { 0, 1, 1, 0 },
	                  { 0, 1, 1, 1 },
	                  { 0, 1, 0, 0 }};
	InitMaze(pm, map);
	PrintMaze(pm, map);
	entry._x = 3;
	entry._y = 1;
	//PassMaze(pm, entry, ps);//简单迷宫循环
	//PassMaze(pm, entry, ps);//简单迷宫递归
	 PassMaze(pm, entry, ps);//带环迷宫递归
	printf("\n");
	PrintMaze(pm, map);

		
}
int main()
{
	Stack s;
	PStack ps = &s;
	//TestStack(ps);
	//Test1(ps);//括号匹配，逆波兰表达式
	TestMaze(ps);//测试迷宫

	system("pause");
	return 0;
}

