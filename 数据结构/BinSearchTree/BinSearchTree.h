#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>





typedef int DataType;

typedef struct BinSearchTree
{
	DataType _data;
	struct BinSearchTree* _pLeft;
	struct BinSearchTree* _pRight;
}BSTree, *PBSTree;



//初始化
void BSTreeInit(PBSTree* pRoot);

//创建新节点
PBSTree BuyNewNode(DataType data);

//插入元素
void BSTreeInsert(PBSTree* pRoot, DataType data);

//二叉树中序遍历
void InOrder(PBSTree pRoot);

//查找元素
PBSTree BSTreeFind(PBSTree pRoot, DataType data);

//二叉搜索树删除
void BSTreeDelete(PBSTree* pRoot, DataType data);

//销毁--中序递归
void BSTreeDestory(PBSTree* pRoot);
