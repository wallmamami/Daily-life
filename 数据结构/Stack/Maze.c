#include "stack.h"
#include "Maze.h"



//////////////////////////////////////////////���Թ�ѭ��
////��ӡ�Թ�
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
////�Թ���ʼ��,���ǽ���ͼ�е�ֵ�����Թ�
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
////����Թ�����Ƿ�Ϸ�
//int IsValidEntry(PMaze pm, Position entry)
//{
//	assert(pm);
//
//	//����λ���Թ��߽���ֵΪ1
//	if ((entry._x == 0 || entry._y == 0 || entry._x == MAX_ROW - 1
//		|| entry._y == MAX_COL - 1) && (pm->_map[entry._x][entry._y] == 1))
//		return 1;
//	return 0;
//}
//
//// ���curλ���Ƿ���ͨ· 
//int IsPass(PMaze pm, Position cur)
//{
//	assert(pm);
//
//	//ֵΪ1�Ҳ���Խ��
//	if ((cur._x >= 0 && cur._x <= MAX_ROW-1) && 
//		(cur._y >= 0 && cur._y <= MAX_COL-1) &&
//		 pm->_map[cur._x][cur._y] == 1)
//		return 1;
//
//	return 0;
//
//}
//
//// ���Cur�Ƿ��ڳ��� 
//int IsExit(PMaze pm, Position cur, Position entry)
//{
//	assert(pm);
//	
//	//����λ�þ��Ǵ��ڱ߽�ֵΪ1�Ҳ��������
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
//	//�������Ƿ�Ϸ�
//	if (!IsValidEntry(pm, entry))
//	{
//		printf("�Թ���ڲ��Ϸ�!!!\n");
//		return;
//	}
//
//	//�߽����,��ջ
//	StackPush(ps, entry);
//
//	while (!StackEmpty(ps))
//	{
//		cur = StackTop(ps);
//
//		//�ڱ��֮ǰ���Ҫ��Ȼ��curλ��ֵ��Ϊ1
//		if (IsExit(pm, cur, entry))
//		{
//			pm->_map[cur._x][cur._y] = 2;
//			printf("���ҵ�����!!!\n");
//			return;
//		}
//		pm->_map[cur._x][cur._y] = 2;
//
//		//�����ж����������Ƿ������ͨ
//		//��
//		next = cur;
//		next._x -= 1;
//
//		//�ж��Ƿ������ͨ
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//��
//		next = cur;
//		next._y -= 1;
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//��
//		next = cur;
//		next._y += 1;
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//��
//		next = cur;
//		next._x += 1;
//		if (IsPass(pm, next))
//		{
//			StackPush(ps, next);
//			continue;
//		}
//
//		//����������Ҷ�������ͨ����ô˵��cur�ߴ��ˣ����Ϊ3����ջ
//		pm->_map[cur._x][cur.y];
//		StackPop(ps);
//	}
//
//	//�ߵ��⣬˵���Ҳ����Թ�����
//	printf("�Թ�û�г���!!!\n");
//}







////////////////////////////////////////////////////���Թ��ݹ�

//#include "stack.h"
//#include "Maze.h"
//
////��ӡ�Թ�
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
////�Թ���ʼ��,���ǽ���ͼ�е�ֵ�����Թ�
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
////����Թ�����Ƿ�Ϸ�
//int IsValidEntry(PMaze pm, Position entry)
//{
//	assert(pm);
//
//	//����λ���Թ��߽���ֵΪ1
//	if ((entry._x == 0 || entry._y == 0 || entry._x == MAX_ROW - 1
//		|| entry._y == MAX_COL - 1) && (pm->_map[entry._x][entry._y] == 1))
//		return 1;
//	return 0;
//}
//
//// ���curλ���Ƿ���ͨ· 
//int IsPass(PMaze pm, Position cur)
//{
//	assert(pm);
//
//	//ֵΪ1�Ҳ���Խ��
//	if ((cur._x >= 0 && cur._x <= MAX_ROW - 1) &&
//		(cur._y >= 0 && cur._y <= MAX_COL - 1) &&
//		pm->_map[cur._x][cur._y] == 1)
//		return 1;
//
//	return 0;
//
//}
//
//// ���Cur�Ƿ��ڳ��� 
//int IsExit(PMaze pm, Position cur, Position entry)
//{
//	assert(pm);
//
//	//����λ�þ��Ǵ��ڱ߽�ֵΪ1�Ҳ��������
//	if ((cur._x == 0 || cur._y == 0 || cur._x == MAX_ROW - 1
//		|| cur._y == MAX_COL - 1) && (pm->_map[cur._x][cur._y] == 1)
//		&& ((cur._x != entry._x) || (cur._y != entry._y)))
//		return 1;
//
//	return 0;
//}
//
//// �������Թ����� 
//int _PassMaze(PMaze pm, Position entry, Position cur, PStack ps)
//{
//
//	Position next;
//	assert(pm);
//	assert(ps);
//
//	//���жϵ�ǰλ���Ƿ���ͨ·
//		if (IsPass(pm, cur))
//		{
//			//����ջ�����ж��ǲ��ǳ��ڣ�����ǣ���Ϊ����ǳ��ڣ������Ͳ���1
//			StackPush(ps, cur);
//			if (IsExit(pm, cur, entry))
//			{
//				pm->_map[cur._x][cur._y] = 2;
//				return 1;
//			}
//			pm->_map[cur._x][cur._y] = 2;
//	
//			// up��ֱ���ߣ����뺯�������ж��Ƿ�����ͨ
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
//			//�ĸ������߲�ͨ��˵��cur�ߴ��ˣ����λ3��ջ
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
////�ṩ���û�ʹ�õ����Թ����������ϸ����Թ������������ǣ��û�����ȥ����ǰ����ֻ��Ҫ����ھ���
//void PassMaze(PMaze pm, Position entry, PStack ps)
//{
//	assert(pm);
//	assert(ps);
//
//	//�������Ƿ�Ϸ�
//	if (!IsValidEntry(pm, entry))
//	{
//		printf("�Թ���ڲ��Ϸ�!!!\n");
//		return;
//	}
//
//	//�Ϸ��������Թ�
//	_PassMaze(pm, entry, entry, ps);
//}


////////////////////////////////////////////////////�����Թ��ݹ�

#include "stack.h"
#include "Maze.h"


//��ӡ�Թ�
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

//�Թ���ʼ��,���ǽ���ͼ�е�ֵ�����Թ�
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


//����Թ�����Ƿ�Ϸ�
int IsValidEntry(PMaze pm, Position entry)
{
	assert(pm);

	//����λ���Թ��߽���ֵΪ1
	if ((entry._x == 0 || entry._y == 0 || entry._x == MAX_ROW - 1
		|| entry._y == MAX_COL - 1) && (pm->_map[entry._x][entry._y] == 1))
		return 1;
	return 0;
}

int IsPass(PMaze pm, Position cur, Position next)
{
	assert(pm);

	//nextֵΪ1�Ҳ���Խ��
	if ((next._x >= 0 && next._x <= MAX_ROW - 1) &&
		(next._y >= 0 && next._y <= MAX_COL - 1) &&
		pm->_map[next._x][next._y] == 1)
		return 1;
	//nextֵ����curֵ�Ҳ���Խ��
	if ((cur._x >= 0 && cur._x <= MAX_ROW - 1) &&
		(cur._y >= 0 && cur._y <= MAX_COL - 1) &&
		pm->_map[cur._x][cur._y] < pm->_map[next._x][next._y])
		return 1;

	return 0;

}

//����Ƿ��ǳ���
int IsExit(PMaze pm, Position cur, Position entry)
{
	assert(pm);

	//��Ϊ֮ǰ�Ѿ��߹��ˣ�����ֻҪ���ڱ߽��Ҳ�����ڿ϶��ǳ���
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

	//ջ���Ϊ��˵�������������
	if (!StackSize(PPath))
		pm->_map[cur._x][cur._y] = 2;
	StackPush(PPath, cur);

	//�ж��Ƿ�Ϊ����
	if (IsExit(pm, cur, entry))
	{
		//�������·��:1.PShortPathΪ��2.PShortPath��size����PPath��size
		if (StackEmpty(PShortPath))
			UpdatePath(PPath, PShortPath);
		if (StackSize(PPath) < StackSize(PShortPath))
			UpdatePath(PPath, PShortPath);

		//��PPath�е�ջ��Ԫ�س�ջ��������·��
		StackPop(PPath);
	}

	//��
	next = cur;
	next._x -= 1;
	if (IsPass(pm, cur, next))
	{
		//����cur��ֵ��1���nextλ�ã�����next
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//��
	next = cur;
	next._y -= 1;
	if (IsPass(pm, cur, next))
	{
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//��
	next = cur;
	next._y += 1;
	if (IsPass(pm, cur, next))
	{
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//��
	next = cur;
	next._x += 1;
	if (IsPass(pm, cur, next))
	{
		pm->_map[next._x][next._y] = pm->_map[cur._x][cur._y] + 1;
		_PassMaze(pm, entry, next, PPath, PShortPath);
	}

	//˵��cur�ߴ���
	StackPop(PPath);
	return 0;
}

void PassMaze(PMaze pm, Position entry, PStack ps)
{
	Stack PShortPath;

	assert(pm);
	assert(ps);

	//���ж��Թ�����Ƿ�Ϸ�
	if (!IsValidEntry(pm, entry))
	{
		printf("�Թ���ڷǷ�!!!\n");
		return;
	}

	//��ʼ����߽����
	_PassMaze(pm, entry, entry, ps, &PShortPath);
}