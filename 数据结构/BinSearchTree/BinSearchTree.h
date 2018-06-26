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



//��ʼ��
void BSTreeInit(PBSTree* pRoot);

//�����½ڵ�
PBSTree BuyNewNode(DataType data);

//����Ԫ��
void BSTreeInsert(PBSTree* pRoot, DataType data);

//�������������
void InOrder(PBSTree pRoot);

//����Ԫ��
PBSTree BSTreeFind(PBSTree pRoot, DataType data);

//����������ɾ��
void BSTreeDelete(PBSTree* pRoot, DataType data);

//����--����ݹ�
void BSTreeDestory(PBSTree* pRoot);
