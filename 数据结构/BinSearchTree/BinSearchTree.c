#include "BinSearchTree.h"


//初始化
void BSTreeInit(PBSTree* pRoot)
{
	assert(pRoot);

	*pRoot = NULL;
}

//创建新节点
PBSTree BuyNewNode(DataType data)
{
	PBSTree ptr = NULL;
	ptr = (PBSTree)malloc(sizeof(BSTree));
	if (NULL == ptr)
	{
		assert(0);
		return NULL;
	}

	ptr->_data = data;
	ptr->_pLeft = NULL;
	ptr->_pRight = NULL;

	return ptr;
}


//插入，查找，删除非递归

//插入元素
void BSTreeInsert(PBSTree* pRoot, DataType data)
{
	PBSTree pCur = *pRoot;
	PBSTree pParent = NULL;
	assert(pRoot);

	//先判断是否为空树
	if (NULL == *pRoot)
	{
		*pRoot = BuyNewNode(data);
		return;
	}

	//找到插入位置，并保存插入位置的双亲结点
	while (pCur)
	{
		//插到左边
		if (pCur->_data > data)
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}

		//插到右边
		else if (pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}

		//数据相等
		else
			return;
	}

	if (data > pParent->_data)
		pParent->_pRight = BuyNewNode(data);

	if (data < pParent->_data)
		pParent->_pLeft = BuyNewNode(data);


}

//查找元素
PBSTree BSTreeFind(PBSTree pRoot, DataType data)
{
	PBSTree pCur = pRoot;

	if (pRoot == NULL)
	{
		printf("树已空，操作失败!\n");
		return NULL;
	}

	while (pCur)
	{
		if (pCur->_data == data)
			return pCur;

		else if (data > pCur->_data)
			pCur = pCur->_pRight;

		else
			pCur = pCur->_pLeft;
	}

	printf("没有该节点!\n");
	return NULL;
}


//二叉搜索树删除
void BSTreeDelete(PBSTree* pRoot, DataType data)
{
	PBSTree pCur = *pRoot;
	PBSTree pParent = NULL;
	assert(pRoot);

	//如果为空树，直接返回
	if (NULL == pRoot)
		return;

	//查找值为data的节点
	while (pCur)
	{
		if (pCur->_data == data)
			break;

		else if (data > pCur->_data)
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}

		else
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}
	}

	//如果pCur为空，说明树中没有该节点
	if (NULL == pCur)
		return;

	else
	{
		//如果待删节点没有右子树或左右子树都没有
		//直接删
		if (!pCur->_pRight)
		{
			//判断待删节点是其双亲节点的什么节点
			if (pCur->_data > pParent->_data)//右
				pParent->_pRight = pCur->_pLeft;

			else
				pParent->_pLeft = pCur->_pLeft;

		}

		//如果待删节点没有左子树
		//直接删
		else if (!pCur->_pLeft)
		{
			if (pCur->_data > pParent->_data)//右
				pParent->_pRight = pCur->_pRight;

			else
				pParent->_pLeft = pCur->_pRight;

		}

		//如果待删节点左右子树都存在
		//不能直接删
		else
		{
			//先在待删节点左子树或右子树找代替节点
			//右子树--找最小节点--即最左节点
			//左子树--找最大节点--即最右节点
			
			//在右子树找最小节点来替换，走之前先将双亲节点挪过来
			PBSTree ptr = pCur;//用来保存待删节点
			pParent = pCur;//用来保存代替节点的双亲
			pCur = pCur->_pRight;

			while (pCur->_pLeft)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}

			//先将待删节点data与代替节点data交换
			ptr->_data = pCur->_data;

			//判断代替节点是其双亲的什么节点
			if(pCur == pParent->_pLeft)//左
				pParent->_pLeft = pCur->_pRight;//因为代替节点是右子树最小的，所以一定没有左子树

			else
				pParent->_pRight = pCur->_pRight;

		}
	}

	free(pCur);
}

//查找、插入、删除递归


//插入元素
void BSTreeInsert(PBSTree* pRoot, DataType data)
{
	assert(pRoot);

	if(NULL == *pRoot)
		*pRoot = BuyNewNode(data);

	else
	{
		if (data > (*pRoot)->_data)
			BSTreeInsert(&(*pRoot)->_pRight, data);

		else if (data < (*pRoot)->_data)
			BSTreeInsert(&(*pRoot)->_pLeft, data);

		//不处理二叉树已经有data的情况
		else
			return;

	}
}

//查找元素
PBSTree BSTreeFind(PBSTree pRoot, DataType data)
{

	if (NULL == pRoot)
		return NULL;

	else
	{
		//如果data小于pRoot的data，就到t它左子树找
		if (data < pRoot->_data)
			return BSTreeFind(pRoot->_pLeft, data);

		//如果data大于pRoot的data，就到t它右子树找
		else if (data > pRoot->_data)
			return BSTreeFind(pRoot->_pRight, data);

		//等于，直接返回节点
		else
			return pRoot;
	}
}

//二叉搜索树删除
void BSTreeDelete(PBSTree* pRoot, DataType data)
{
	assert(pRoot);

	//空树直接返回
	if (NULL == *pRoot)
		return;

	else
	{	
		//先找到待删除节点
		//如果小，到左子树找
		if (data < (*pRoot)->_data)
			BSTreeDelete(&(*pRoot)->_pLeft, data);

		//如果大，到右子树找
		else if (data >(*pRoot)->_data)
			BSTreeDelete(&(*pRoot)->_pRight, data);

		//说明找到了
		else
		{
			//如果没有右子树或者左右子树都没有
			//直接删
			PBSTree pDel = *pRoot;
			if (!(*pRoot)->_pRight)
			{
				*pRoot = pDel->_pLeft;
				free(pDel);
			}

			//如果没有左子树，也直接删
			else if (!(*pRoot)->_pLeft)
			{
				*pRoot = pDel->_pRight;
				free(pDel);
			}
			
			//如果左右子树都存在
			else
			{
				//到*pRoot右子树找最小节点--最左边
				pDel = (*pRoot)->_pRight;

				while (pDel->_pLeft)
					pDel = pDel->_pLeft;

				//将代替节点的值交给*pRoot
				(*pRoot)->_data = pDel->_data;

				//在*pRoot的右子树删除值为pDel->data的节点
				BSTreeDelete(&(*pRoot)->_pRight, pDel->_data);

			}
		}
	}
}




//二叉树中序遍历
void InOrder(PBSTree pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%d ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

//销毁--中序递归
void BSTreeDestory(PBSTree* pRoot)
{
	assert(pRoot);

	if (*pRoot)
	{
		//先销毁左子树
		BSTreeDestory(&(*pRoot)->_pLeft);

		//再销毁右子树
		BSTreeDestory(&(*pRoot)->_pRight);

		//销毁跟节点
		free(*pRoot);
		*pRoot = NULL;
	}

}

