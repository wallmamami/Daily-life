#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode* SDataType;//ջ�ڵ�����

#define MAX_SIZE 10
typedef struct Stack
{
	SDataType arr[MAX_SIZE];
	int size;
}Stack, *PStack;


typedef struct BTNode* QDataType;//���нڵ�data����

//���еĽڵ�
typedef struct QNode
{
	QDataType _data;
	struct QNode* _pNext;
}QNode;

//����
typedef struct Queue
{
	struct QNode* _pHead;
	struct QNode* _pTail;
}Queue, *PQueue;

typedef char BTDataType;//�������ڵ�data����

//�������ڵ�
typedef struct BTNode
{
	BTDataType _data;
	struct BTNode* _pLeft;//����������
	struct BTNode* _pRight;//����������
}BTNode, *PBTNode;








// �����������Ľ�� 
PBTNode BuyBinTreeNode(BTDataType data);

// ���������� 
void _CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, int* index, BTDataType invalid);
void CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, BTDataType invalid);

// ���������� 
PBTNode CopyBinTree(PBTNode pRoot);

// ���ٶ����� 
void DestroyBinTree(PBTNode *pRoot);

// ǰ������ݹ� 
void PreOrder(PBTNode pRoot);
// ǰ������ǵݹ� 
void PreOrderNor(PBTNode pRoot);
//ǰ������ǵݹ飨�ȱ�����������
void PreOrderNor2(PBTNode pRoot);

// ��������ݹ� 
void InOrder(PBTNode pRoot);

//��������ǵݹ�
void InOrderNor(PBTNode pRoot);

// ���������ݹ� 
void PostOrder(PBTNode pRoot);

//��������ǵݹ�
void PostOrderNor(PBTNode pRoot);

// ������� 
void LevelOrder(PBTNode pRoot);

// �������ľ���ݹ� 
void MirrorBinTree(PBTNode pRoot);

// �������ľ���ǵݹ� 
void MirrorBinTreeNor(PBTNode pRoot);


// ��������н��ĸ��� 
int BinTreeSize(PBTNode pRoot);

// ��ȡ��������Ҷ�ӽ��ĸ��� 
int GetLeafCount(PBTNode pRoot);

// ���������K����ĸ��� 
int GetKLevelNode(PBTNode pRoot, int K);

// ��������ĸ߶� 
int Hight(PBTNode pRoot);

