#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode* SDataType;//栈节点类型

#define MAX_SIZE 10
typedef struct Stack
{
	SDataType arr[MAX_SIZE];
	int size;
}Stack, *PStack;


typedef struct BTNode* QDataType;//队列节点data类型

//队列的节点
typedef struct QNode
{
	QDataType _data;
	struct QNode* _pNext;
}QNode;

//队列
typedef struct Queue
{
	struct QNode* _pHead;
	struct QNode* _pTail;
}Queue, *PQueue;

typedef char BTDataType;//二叉树节点data类型

//二叉树节点
typedef struct BTNode
{
	BTDataType _data;
	struct BTNode* _pLeft;//树的左子树
	struct BTNode* _pRight;//树的右子树
}BTNode, *PBTNode;








// 构建二叉树的结点 
PBTNode BuyBinTreeNode(BTDataType data);

// 创建二叉树 
void _CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, int* index, BTDataType invalid);
void CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, BTDataType invalid);

// 拷贝二叉树 
PBTNode CopyBinTree(PBTNode pRoot);

// 销毁二叉树 
void DestroyBinTree(PBTNode *pRoot);

// 前序遍历递归 
void PreOrder(PBTNode pRoot);
// 前序遍历非递归 
void PreOrderNor(PBTNode pRoot);
//前序遍历非递归（先遍历左子树）
void PreOrderNor2(PBTNode pRoot);

// 中序遍历递归 
void InOrder(PBTNode pRoot);

//中序遍历非递归
void InOrderNor(PBTNode pRoot);

// 后续遍历递归 
void PostOrder(PBTNode pRoot);

//后序遍历非递归
void PostOrderNor(PBTNode pRoot);

// 层序遍历 
void LevelOrder(PBTNode pRoot);

// 二叉树的镜像递归 
void MirrorBinTree(PBTNode pRoot);

// 二叉树的镜像非递归 
void MirrorBinTreeNor(PBTNode pRoot);


// 求二叉树中结点的个数 
int BinTreeSize(PBTNode pRoot);

// 获取二叉树中叶子结点的个数 
int GetLeafCount(PBTNode pRoot);

// 求二叉树中K层结点的个数 
int GetKLevelNode(PBTNode pRoot, int K);

// 求二叉树的高度 
int Hight(PBTNode pRoot);

