#pragma once
#define MAX_ROW 4
#define MAX_COL 4

typedef struct Position
{
	int _x;
	int _y;
}Position;

typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];

}Maze, *PMaze;

//1. 用栈对简单迷宫进行求解，迷宫只有一个出口
//采用循环方式实现
// 栈的初始化 
//void InitMaze(PMaze pm, int map[][MAX_COL]);
//
// 检测入口是否为有效入口 
//int IsValidEntry(PMaze pm, Position entry);
//
// 检测cur位置是否是通路 
//int IsPass(PMaze pm, Position cur);
//
// 检测Cur是否在出口 
//int IsExit(PMaze pm, Position cur, Position entry);
//
// 走迷宫 
//void PassMaze(PMaze pm, Position entry, PStack ps);
//
// 打印迷宫 
//void PrintMaze(PMaze m, int map[][MAX_COL]);
//
//2. 用递归方式实现简单迷宫：即只有一个出口迷宫
//void InitMaze(PMaze pm, int map[][MAX_COL]);
//int IsValidEntry(PMaze pm, Position entry);
//int IsPass(PMaze pm, Position cur);
//int IsExit(PMaze pm, Position cur, Position entry);
//
// 真正走迷宫函数 
//int _PassMaze(PMaze pm, Position entry, Position cur, PStack ps);
//
// 提供给用户使用的走迷宫函数，与上上个走迷宫函数的区别是：用户不用去传当前步，只需要给入口就行 
//void PassMaze(PMaze pm, Position entry, PStack ps);
//void PrintMaze(PMaze pm, int map[][MAX_COL]);

//3. 如果迷宫有多条路口，但是路口没有构成环，怎么求最短路径
//4、 如果多个路口构成环，如何求最短路径-- - 大家在底下自己先尝试去写


/////////////////////带环迷宫

void InitMaze(PMaze pm, int map[][MAX_COL]);//初始化
int _PassMaze(PMaze pm, Position entry, Position cur, PStack PPath, PStack PShortPath);//真正走迷宫
int IsExit(PMaze pm, Position cur, Position entry);//检测是否是出口
int IsValidEntry(PMaze pm, Position entry);//检测入口是否合法
void PassMaze(PMaze pm, Position entry, PStack ps);//提供给用户的走迷宫函数
void PrintMaze(PMaze pm, int map[][MAX_COL]);//打印迷宫