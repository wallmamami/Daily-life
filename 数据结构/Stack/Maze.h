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

//1. ��ջ�Լ��Թ�������⣬�Թ�ֻ��һ������
//����ѭ����ʽʵ��
// ջ�ĳ�ʼ�� 
//void InitMaze(PMaze pm, int map[][MAX_COL]);
//
// �������Ƿ�Ϊ��Ч��� 
//int IsValidEntry(PMaze pm, Position entry);
//
// ���curλ���Ƿ���ͨ· 
//int IsPass(PMaze pm, Position cur);
//
// ���Cur�Ƿ��ڳ��� 
//int IsExit(PMaze pm, Position cur, Position entry);
//
// ���Թ� 
//void PassMaze(PMaze pm, Position entry, PStack ps);
//
// ��ӡ�Թ� 
//void PrintMaze(PMaze m, int map[][MAX_COL]);
//
//2. �õݹ鷽ʽʵ�ּ��Թ�����ֻ��һ�������Թ�
//void InitMaze(PMaze pm, int map[][MAX_COL]);
//int IsValidEntry(PMaze pm, Position entry);
//int IsPass(PMaze pm, Position cur);
//int IsExit(PMaze pm, Position cur, Position entry);
//
// �������Թ����� 
//int _PassMaze(PMaze pm, Position entry, Position cur, PStack ps);
//
// �ṩ���û�ʹ�õ����Թ������������ϸ����Թ������������ǣ��û�����ȥ����ǰ����ֻ��Ҫ����ھ��� 
//void PassMaze(PMaze pm, Position entry, PStack ps);
//void PrintMaze(PMaze pm, int map[][MAX_COL]);

//3. ����Թ��ж���·�ڣ�����·��û�й��ɻ�����ô�����·��
//4�� ������·�ڹ��ɻ�����������·��-- - ����ڵ����Լ��ȳ���ȥд


/////////////////////�����Թ�

void InitMaze(PMaze pm, int map[][MAX_COL]);//��ʼ��
int _PassMaze(PMaze pm, Position entry, Position cur, PStack PPath, PStack PShortPath);//�������Թ�
int IsExit(PMaze pm, Position cur, Position entry);//����Ƿ��ǳ���
int IsValidEntry(PMaze pm, Position entry);//�������Ƿ�Ϸ�
void PassMaze(PMaze pm, Position entry, PStack ps);//�ṩ���û������Թ�����
void PrintMaze(PMaze pm, int map[][MAX_COL]);//��ӡ�Թ�