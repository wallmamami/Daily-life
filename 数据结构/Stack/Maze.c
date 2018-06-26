#include "stack.h"
#include "Maze.h"



//////////////////////////////////////////////简单迷宫循环
////打印迷宫
//void PrintMaze(PMaze pm)
//{
//	int i = 0;
//	assert(pm);
//
//	for (; i < MAX_ROW; ++i)
//	{
//		int j = 0;
//		for (; j < MAX_COL; ++j)
//		{
//			printf("%d ", pm->_map[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//
////迷宫初始化,就是将地图中的值赋给迷宫
//void InitMaze(PMaze pm, int map[][MAX_COL])
//{
//	int i = 0;
//	assert(pm);
//
//	for (; i < MAX_ROW; ++i)
//	{
//		int j = 0;
//		for (; j < MAX_COL; ++j)
//		{
//			pm->_map[i][j] = map[i][j];
//		}
//	}
//}
//
////检测迷宫入口是否合法
//int IsValidEntry(PMaze pm, Position entry)
//{
//	assert(pm);
//
//	//必须位于迷宫边界且值为1
//	if ((entry._x == 0 || entry._y == 0 || entry._x == MAX_ROW - 1
//		|| entry._y == MAX_COL - 1) && (pm->_map[entry._x][entry._y] == 1))
//		return 1;
//	return 0;
//}
//
//// 检测cur位置是否是通路 
//int IsPass(PMaze pm, Position cur)
//{
//	assert(pm);
//
//	//值为1且不能越界
//	if ((cur._x >= 0 && cur._x <= MAX_ROW-1) && 
//		(cur._y >= 0 && cur._y <= MAX_COL-1) &&
//		 pm->_map[cur._x][cur._y] == 1)
//		return 1;
//
//	return 0;
//
//}
//
//// 检测Cur是否在出口 
//int IsExit(PMaze pm, Position cur, Position entry)
//{
//	assert(pm);
//	
//	//出口位置就是处于边界值为1且不能是入口
//	if ((cur._x == 0 || cur._y == 0 || cur._x == MAX_ROW - 1
//		|| cur._y == MAX_COL - 1) && (pm->_map[cur._x][cur._y] == 1)
//		&& ((cur._x != entry._x) || (cur._y != entry._y)))
//		return 1;
//
//	return 0;
//}
//
//void PassMaze(PMaze pm, Position entry, PStack ps)
//{
//	Position cur;
//	Position next;
//	assert(pm);
//	assert(ps);
//
//	//检测入口是否合法
//	if (!IsValidEntry(pm, entry))
//	{
//		printf("迷宫入口不合法!!!\n");
//		return;
//	}
//
//	//走进入口,入栈
//	StackPush(ps, entry);
//
//	while (!StackEmpty(ps))
//	{
//		cur = StackTop(ps);
//
//		//在标记之前检测要不然，cur位置值不为1
//		if (IsExit(pm, cur, entry))
//		{
//			pm->_map[cur._x][cur._y] = 2;
//			printf("已找到出口!!!\n");
//			return;
//		}
//		pm->_map[cur._x][cur._y] = 2;
//
//		//依次判断上下左右是否可以走通
//		//上
//		next = cur;
//		next._x -= 1;
//
//		//判断是否可以走通
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//左
//		next = cur;
//		next._y -= 1;
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//右
//		next = cur;
//		next._y += 1;
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//下
//		next = cur;
//		next._x += 1;
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//如果上下左右都不能走通，那么说明cur走错了，标记为3，出栈
//		pm->_map[cur._x][cur.y];
//		StackPop(ps);
//	}
//
//	//走到这，说明找不到迷宫出口
//	printf("迷宫没有出口!!!\n");
//}







////////////////////////////////////////////////////简单迷宫递归

//#include "stack.h"
//#include "Maze.h"
//
////打印迷宫
//void PrintMaze(PMaze pm)
//{
//	int i = 0;
//	assert(pm);
//
//	for (; i < MAX_ROW; ++i)
//	{
//		int j = 0;
//		for (; j < MAX_COL; ++j)
//		{
//			printf("%d ", pm->_map[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//
////迷宫初始化,就是将地图中的值赋给迷宫
//void InitMaze(PMaze pm, int map[][MAX_COL])
//{
//	int i = 0;
//	assert(pm);
//
//	for (; i < MAX_ROW; ++i)
//	{
//		int j = 0;
//		for (; j < MAX_COL; ++j)
//		{
//			pm->_map[i][j] = map[i][j];
//		}
//	}
//}
//
////检测迷宫入口是否合法
//int IsValidEntry(PMaze pm, Position entry)
//{
//	assert(pm);
//
//	//必须位于迷宫边界且值为1
//	if ((entry._x == 0 || entry._y == 0 || entry._x == MAX_ROW - 1
//		|| entry._y == MAX_COL - 1) && (pm->_map[entry._x][entry._y] == 1))
//		return 1;
//	return 0;
//}
//
//// 检测cur位置是否是通路 
//int IsPass(PMaze pm, Position cur)
//{
//	assert(pm);
//
//	//值为1且不能越界
//	if ((cur._x >= 0 && cur._x <= MAX_ROW - 1) &&
//		(cur._y >= 0 && cur._y <= MAX_COL - 1) &&
//		pm->_map[cur._x][cur._y] == 1)
//		return 1;
//
//	return 0;
//
//}
//
//// 检测Cur是否在出口 
//int IsExit(PMaze pm, Position cur, Position entry)
//{
//	assert(pm);
//
//	//出口位置就是处于边界值为1且不能是入口
//	if ((cur._x == 0 || cur._y == 0 || cur._x == MAX_ROW - 1
//		|| cur._y == MAX_COL - 1) && (pm->_map[cur._x][cur._y] == 1)
//		&& ((cur._x != entry._x) || (cur._y != entry._y)))
//		return 1;
//
//	return 0;
//}
//
//// 真正走迷宫函数 
//int _PassMaze(PMaze pm, Position entry, Position cur, PStack ps)
//{
//
//	Position next;
//	assert(pm);
//	assert(ps);
//
//	//先判断当前位置是否是通路
//		if (IsPass(pm, cur))
//		{
//			//先入栈，再判断是不是出口，最后标记，因为如果是出口，标记完就不是1
//			StackPush(ps, cur);
//			if (IsExit(pm, cur, entry))
//			{
//				pm->_map[cur._x][cur._y] = 2;
//				return 1;
//			}
//			pm->_map[cur._x][cur._y] = 2;
//	
//			// up，直接走，进入函数后再判断是否能走通
//			next = cur;
//			next._x -= 1;
//			if (_PassMaze(pm, entry, next, ps))
//				return 1;
//	
//			// left
//			next = cur;
//			next._y -= 1;
//			if (_PassMaze(pm, entry, next, ps))
//				return 1;
//	
//			// right
//			next = cur;
//			next._y += 1;
//			if (_PassMaze(pm, entry, next, ps))
//				return 1;
//	
//			// down
//			next = cur;
//			next._x += 1;
//			if (_PassMaze(pm, entry, next, ps))
//				return 1;
//			
//			//四个方向都走不通，说明cur走错了，标记位3出栈
//			pm->_map[cur._x][cur._y] = 3;
//			StackPop(ps);
//		}
//	
//		return 0;
//
//}
//
//
//
////提供给用户使用的走迷宫函数，与上个走迷宫函数的区别是：用户不用去传当前步，只需要给入口就行
//void PassMaze(PMaze pm, Position entry, PStack ps)
//{
//	assert(pm);
//	assert(ps);
//
//	//检测入口是否合法
//	if (!IsValidEntry(pm, entry))
//	{
//		printf("迷宫入口不合法!!!\n");
//		return;
//	}
//
//	//合法就走入迷宫
//	_PassMaze(pm, entry, entry, ps);
//}


////////////////////////////////////////////////////带环迷宫递归

#include "stack.h"
#include "Maze.h"


//打印迷宫
void PrintMaze(PMaze pm)
{
	int i = 0;
	assert(pm);

	for (; i < MAX_ROW; ++i)
	{
		int j = 0;
		for (; j < MAX_COL; ++j)
		{
			printf("%d ", pm->_map[i][j]);
		}
		printf("\n");
	}

}

//迷宫初始化,就是将地图中的值赋给迷宫
void InitMaze(PMaze pm, int map[][MAX_COL])
{
	int i = 0;
	assert(pm);

	for (; i < MAX_ROW; ++i)
	{
		int j = 0;
		for (; j < MAX_COL; ++j)
		{
			pm->_map[i][j] = map[i][j];
		}
	}
}


//检测迷宫入口是否合法
int IsValidEntry(PMaze pm, Position entry)
{
	assert(pm);

	//必须位于迷宫边界且值为1
	if ((entry._x == 0 || entry._y == 0 || entry._x == MAX_ROW - 1
		|| entry._y == MAX_COL - 1) && (pm->_map[entry._x][entry._y] == 1))
		return 1;
	return 0;
}

int IsPass(PMaze pm, Position cur, Position next)
{
	assert(pm);

	//next值为1且不能越界
	if ((next._x >= 0 && next._x <= MAX_ROW - 1) &&
		(next._y >= 0 && next._y <= MAX_COL - 1) &&
		pm->_map[next._x][next._y] == 1)
		return 1;
	//next值大于cur值且不能越界
	if ((cur._x >= 0 && cur._x <= MAX_ROW - 1) &&
		(cur._y >= 0 && cur._y <= MAX_COL - 1) &&
		pm->_map[cur._x][cur._y] < pm->_map[next._x][next._y])
		return 1;

	return 0;

}

//检测是否是出口
int IsExit(PMaze pm, Position cur, Position entry)
{
	assert(pm);

	//因为之前已经走过了，所以只要处于边界且不是入口肯定是出口
	if ((cur._x == 0 || cur._x == MAX_ROW - 1 ||
		cur._y == 0 || cur._y == MAX_COL - 1) &&
		((cur._x != entry._x) || (cur._y != entry._y)))
		return 1;
	return 0;

}

void UpdatePath(PStack PPath, PStack PShortPath)
{
	int i = 0;
	int size = 0;
	assert(PPath);
	assert(PShortPath);

	PShortPath->size = PPath->size;
	size = PPath->size;

	for (; i < size; i++)
		PShortPath->arr[i] = PPath->arr[i];
}

int _PassMaze(PMaze pm, Position entry, Position cur, PStack PPath, PStack PShortPath)
{
	Position next;

	assert(pm);
	assert(PPath);
	assert(PShortPath);

	//栈如果为空说明进来的是入口
	if (!StackSize(PPath))
		pm->_map[cur._x][cur._y] = 2;
	StackPush(PPath, cur);

	//判断是否为出口
	if (IsExit(pm, cur, entry))
	{
		//更新最短路径:1.PShortPath为空2.PShortPath的size大于PPath的size
		if (StackEmpty(PShortPath))
			UpdatePath(PPath, PShortPath);
		if (StackSize(PPath) < StackSize(PShortPath))
			UpdatePath(PPath, PShortPath);

		//将PPath中的栈顶元素出栈，继续找路径
		StackPop(PPath);
	}

	//上
	next = cur;
	next._x -= 1;
	if (IsPass(pm, cur, next))
	{
		//先用cur的值加1标记next位置，再走next
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//左
	next = cur;
	next._y -= 1;
	if (IsPass(pm, cur, next))
	{
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//右
	next = cur;
	next._y += 1;
	if (IsPass(pm, cur, next))
	{
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//下
	next = cur;
	next._x += 1;
	if (IsPass(pm, cur, next))
	{
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//说明cur走错了
	StackPop(PPath);
	return 0;
}

void PassMaze(PMaze pm, Position entry, PStack ps)
{
	Stack PShortPath;

	assert(pm);
	assert(ps);

	//先判断迷宫入口是否合法
	if (!IsValidEntry(pm, entry))
	{
		printf("迷宫入口非法!!!\n");
		return;
	}

	//开始真的走进入口
	_PassMaze(pm, entry, entry, ps, &PShortPath);
}