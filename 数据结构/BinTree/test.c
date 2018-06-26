#include "BInTree.h"
#include <Windows.h>


void Test1()
{
	BTNode Root;//根节点
	PBTNode pRoot = &Root;
	PBTNode pNewRoot = NULL;//拷贝的新二叉树
	const BTDataType* ptr = "ABD###CE##F";//按照前序遍历的顺序给出二叉树的data
	

	CreateBinTree(&pRoot, ptr, strlen(ptr), '#');
	printf("前序遍历:\n");
	PreOrder(pRoot);//前序遍历递归
	printf("\n");
	PreOrderNor(pRoot);//前序遍历非递归(用栈)
	printf("\n");
	PreOrderNor2(pRoot);//前序遍历非递归（先遍历左子树）
	printf("\n");

	printf("中序遍历:\n");
	InOrder(pRoot);//中序遍历递归
	printf("\n");

	printf("中序遍历非递归:\n");
	InOrderNor(pRoot);//中序遍历非递归
	printf("\n");

	printf("后序遍历:\n");
	PostOrder(pRoot);//后序遍历递归
	printf("\n");

	printf("后序遍历非递归:\n");
	PostOrderNor(pRoot);//后序遍历递归
	printf("\n");

	printf("层序遍历:\n");
	MirrorBinTreeNor(pRoot);//二叉树镜像非递归
	MirrorBinTree(pRoot);// 二叉树的镜像递归 
	LevelOrder(pRoot);//层序遍历
	printf("\n");

	printf("pNewRoot层序遍历:\n");
	pNewRoot = CopyBinTree(pRoot);//拷贝二叉树(递归，前序)
	LevelOrder(pNewRoot);//层序遍历
	printf("\n");

	printf("size = %d\n", BinTreeSize(pRoot));//求二叉树的节点
	printf("Count = %d\n", GetLeafCount(pRoot));//求二叉树叶子节点个数
	printf("K层节点个数为：%d\n", GetKLevelNode(pRoot, 4));// 求二叉树中K层结点的个数 
	printf("High = %d\n", Hight(pRoot->_pLeft->_pLeft->_pLeft));

	DestroyBinTree(&pRoot);//销毁二叉树，因为要改变结点指向，所以传二级指针
	DestroyBinTree(&pNewRoot);
}

int main()
{
	Test1();//测试二插树
	
	system("pause");
	return 0;
}