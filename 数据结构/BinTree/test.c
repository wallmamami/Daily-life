#include "BInTree.h"
#include <Windows.h>


void Test1()
{
	BTNode Root;//���ڵ�
	PBTNode pRoot = &Root;
	PBTNode pNewRoot = NULL;//�������¶�����
	const BTDataType* ptr = "ABD###CE##F";//����ǰ�������˳�������������data
	

	CreateBinTree(&pRoot, ptr, strlen(ptr), '#');
	printf("ǰ�����:\n");
	PreOrder(pRoot);//ǰ������ݹ�
	printf("\n");
	PreOrderNor(pRoot);//ǰ������ǵݹ�(��ջ)
	printf("\n");
	PreOrderNor2(pRoot);//ǰ������ǵݹ飨�ȱ�����������
	printf("\n");

	printf("�������:\n");
	InOrder(pRoot);//��������ݹ�
	printf("\n");

	printf("��������ǵݹ�:\n");
	InOrderNor(pRoot);//��������ǵݹ�
	printf("\n");

	printf("�������:\n");
	PostOrder(pRoot);//��������ݹ�
	printf("\n");

	printf("��������ǵݹ�:\n");
	PostOrderNor(pRoot);//��������ݹ�
	printf("\n");

	printf("�������:\n");
	MirrorBinTreeNor(pRoot);//����������ǵݹ�
	MirrorBinTree(pRoot);// �������ľ���ݹ� 
	LevelOrder(pRoot);//�������
	printf("\n");

	printf("pNewRoot�������:\n");
	pNewRoot = CopyBinTree(pRoot);//����������(�ݹ飬ǰ��)
	LevelOrder(pNewRoot);//�������
	printf("\n");

	printf("size = %d\n", BinTreeSize(pRoot));//��������Ľڵ�
	printf("Count = %d\n", GetLeafCount(pRoot));//�������Ҷ�ӽڵ����
	printf("K��ڵ����Ϊ��%d\n", GetKLevelNode(pRoot, 4));// ���������K����ĸ��� 
	printf("High = %d\n", Hight(pRoot->_pLeft->_pLeft->_pLeft));

	DestroyBinTree(&pRoot);//���ٶ���������ΪҪ�ı���ָ�����Դ�����ָ��
	DestroyBinTree(&pNewRoot);
}

int main()
{
	Test1();//���Զ�����
	
	system("pause");
	return 0;
}