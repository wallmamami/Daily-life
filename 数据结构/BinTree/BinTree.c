#include "BInTree.h"



// 构建二叉树的结点 
PBTNode BuyBinTreeNode(BTDataType data)
{
	PBTNode PNewNode = NULL;

	PNewNode = (PBTNode)malloc(sizeof(BTNode));

	if (PNewNode == NULL)
	{
		printf("空间申请失败!!!\n");
		return NULL;
	}

	PNewNode->_data = data;
	PNewNode->_pLeft = NULL;
	PNewNode->_pRight = NULL;

	return PNewNode;
}

//正真用来创建二叉树
//这里的思路就是将二叉树的每个节点当作一颗新树，创建新树的跟节点，
//然后创建跟节点的左子树，最后创建右子树，这样就将问题规模缩小，可以递归起来
void _CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, int* index, BTDataType invalid)
{
	assert(pRoot);
	//如果arr[*index]不等于'#'，且索引index没有越界，那就创建跟节点
	if (arr[*index] != invalid && *index < size)
	{
		//创建跟节点
		*pRoot = BuyBinTreeNode(arr[*index]);

		//创建左子树
		//注意：这里的(*index++)是在你要创建的时候去++，而不是再创建之后
		(*index)++;
		_CreateBinTree(&((*pRoot)->_pLeft), arr, size, index, invalid);

		//创建右子树
		(*index)++;
		_CreateBinTree(&((*pRoot)->_pRight), arr, size, index, invalid);
	}
	
}

//给用户的接口
void CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, BTDataType invalid)
{
	int index = 0;//用来索引传过来的字符串
	assert(pRoot);
	if (arr == NULL)
		return;

	_CreateBinTree(pRoot, arr, size, &index, invalid);//因为要在另一个函数内部改变index的值，所以传地址
}

//前序遍历二叉树：根-->左子树-->右子树
//递归
void PreOrder(PBTNode pRoot)
{

	//如果根节点不为空，遍历
	if (pRoot)
	{
		printf("%c ", pRoot->_data);

		//如果左子树不为空，遍历
		//判断是为了减少递归次数
		if (pRoot->_pLeft)
			PreOrder(pRoot->_pLeft);

		//如果右子树存在，遍历
		if (pRoot->_pRight)
			PreOrder(pRoot->_pRight);
	}
}
//初始化栈
void StackInit(PStack s)
{
	assert(s);

	s->size = 0;
}

//入栈
void StackPush(PStack s, SDataType data)
{
	assert(s);

	if (s->size == MAX_SIZE)
	{
		printf("栈已满!\n");
		return;
	}

	s->arr[s->size] = data;
	s->size++;
}

//出栈
void StackPop(PStack s)
{
	assert(s);

	if (s->size == 0)
	{
		printf("栈已空!\n");
		return;
	}

	s->size--;
}

//获取栈顶元素
SDataType StackTop(PStack s)
{
	assert(s);

	if (s->size == 0)
	{
		printf("栈已空!\n");
		return NULL;
	}

	return s->arr[s->size - 1];
}

//栈判空
int StackEmpty(PStack s)
{
	assert(s);

	if (s->size == 0)
		return 1;
	return 0;
}

// 前序遍历非递归 (用栈)
void PreOrderNor(PBTNode pRoot)
{
	Stack s;
	StackInit(&s);

	if (NULL == pRoot)
		return;

	//将跟节点入栈
	StackPush(&s, pRoot);

	while (!StackEmpty(&s))
	{
		//取栈顶元素
		PBTNode pCur = StackTop(&s);

		//遍历,出栈
		printf("%c ", pCur->_data);
		StackPop(&s);
		
		//如果右子树存在，入栈
		if (pCur->_pRight)
			StackPush(&s, pCur->_pRight);

		//如果左子树存在，入栈
		if (pCur->_pLeft)
			StackPush(&s, pCur->_pLeft);

	}
}

//前序遍历非递归（先遍历左子树）
void PreOrderNor2(PBTNode pRoot)
{
	Stack s;
	StackInit(&s);
	PBTNode pCur = NULL;
	if (NULL == pRoot)
		return;

	//将根节点入栈
	StackPush(&s, pRoot);

	while (!StackEmpty(&s))
	{
		pCur = StackTop(&s);
		StackPop(&s);

		while (pCur)
		{
			//先遍历
			printf("%c ", pCur->_data);

			//如果有右子树，再将右子树入栈
			if (pCur->_pRight)
				StackPush(&s, pCur->_pRight);

			//一直走左子树
			pCur = pCur->_pLeft;
		}

	}
}

// 中序遍历递归 :左子树-->根-->右子树
void InOrder(PBTNode pRoot)
{
	//判断树是否为空
	if (pRoot)
	{
		//先遍历左子树
		if (pRoot->_pLeft)
			InOrder(pRoot->_pLeft);

		//遍历根节点
		printf("%c ", pRoot->_data);

		//如果右节点存在，遍历
		if (pRoot->_pRight)
			InOrder(pRoot->_pRight);
	}
}

//中序遍历非递归
void InOrderNor(PBTNode pRoot)
{
	Stack s;
	PBTNode pCur = pRoot;
	if (NULL == pRoot)
		return;

	//使用栈之前一定要初始化
	StackInit(&s);

	while (pCur || !StackEmpty(&s))
	{
		//先找到跟节点最左侧的节点并保存这条路径上的所有节点
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		//到这，说明pCur为空，回退走到最左侧节点，遍历之后，再到右子树
		pCur = StackTop(&s);
		StackPop(&s);
		printf("%c ", pCur->_data);
		pCur = pCur->_pRight;
	}
}

// 后续遍历递归 ：左子树-->右子树-->根
void PostOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		//如果左子树存在，遍历
		if (pRoot->_pLeft)
			PostOrder(pRoot->_pLeft);

		//如果右子树存在，遍历
		if (pRoot->_pRight)
			PostOrder(pRoot->_pRight);

		//最后遍历根节点
		printf("%c ", pRoot->_data);

	}
}

//后序遍历非递归
void PostOrderNor(PBTNode pRoot)
{
	Stack s;
	PBTNode pCur = pRoot;
	PBTNode pTop = NULL;
	PBTNode pPre = NULL;//用来保存最近一次遍历的节点
	if (NULL == pRoot)
		return;

	StackInit(&s);

	while (pCur || !StackEmpty(&s))
	{
		//先找到以pCur为跟节点的最左侧节点，并保存路径上所有的节点
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		//
		pTop = StackTop(&s);

		//如果pTop没有右子树，或者右子树被遍历过了才能遍历跟节点
		if (!pTop->_pRight || pPre == pTop->_pRight)
		{
			StackPop(&s);
			printf("%c ", pTop->_data);
			pPre = pTop;
		}

		//如果pTop都被遍历过了，那么他的右子树一定被遍历过了，所以不用在朝右子树走
		else
			pCur = pTop->_pRight;
	}


}

//队列申请节点
QNode* BuyQNewNode(QDataType data)
{
	QNode* PNewNode = NULL;
	PNewNode = (QNode*)malloc(sizeof(QNode));
	
	if (NULL == PNewNode)
	{
		printf("空间申请失败!\n");
		return NULL;
	}

	PNewNode->_data = data;
	PNewNode->_pNext = NULL;
	return PNewNode;
}

//初始化队列,带头节点
void QueueInit(PQueue q)
{
	assert(q);

	q->_pHead = q->_pTail = BuyQNewNode(0);
}

//入队列
void QueuePush(PQueue q, QDataType data)
{
	assert(q);

	//尾插
	q->_pTail->_pNext = BuyQNewNode(data);
	q->_pTail = q->_pTail->_pNext;
}

//出队列
void QueuePop(PQueue q)
{
	assert(q);
	QNode* pDelete = q->_pHead->_pNext;

	if (q->_pHead->_pNext == NULL)
	{
		printf("队列已空！\n");
		return;
	}

	q->_pHead->_pNext = q->_pHead->_pNext->_pNext;
	if (q->_pHead->_pNext == NULL)
		q->_pTail = q->_pHead;
	free(pDelete);
}

//队列判空
int QueueEmpty(PQueue q)
{
	assert(q);

	if (q->_pHead->_pNext == NULL)
		return 1;
	return 0;
}

//取队头元素
QDataType QueueFront(PQueue q)
{
	assert(q);

	if (q->_pHead->_pNext == NULL)
	{
		printf("队列为空\n");
		return 0;
	}

	return q->_pHead->_pNext->_data;
}

// 层序遍历 
void LevelOrder(PBTNode pRoot)
{
	Queue q;
	QueueInit(&q);

	if (NULL == pRoot)
		return;

	//将跟节点入队列
	QueuePush(&q, pRoot);

	while (!QueueEmpty(&q))
	{
		//取队头元素
		PBTNode pCur = QueueFront(&q);

		//遍历,出队列
		printf("%c ", pCur->_data);
		QueuePop(&q);

		//如果左子树存在，入队列
		if (pCur->_pLeft)
		QueuePush(&q, pCur->_pLeft);

		//如果右子树存在，入队列
		if (pCur->_pRight)
		QueuePush(&q, pCur->_pRight);
	}

}

// 拷贝二叉树(递归),前序
PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode pNewRoot = NULL;

	//如果根不为空，就进入
	if (pRoot)
	{
		//先拷贝根节点
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		//如果左子树存在，拷贝
		if (pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		//如果右子树存在，拷贝
		if (pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewRoot;
}

// 销毁二叉树 
//要用后续遍历，因为如果先销毁根就找不到，左右子树了
void DestroyBinTree(PBTNode *pRoot)
{
	assert(pRoot);

	if (*pRoot)
	{
		//如果左子树存在，先销毁左子树
		if ((*pRoot)->_pLeft)
			DestroyBinTree(&((*pRoot)->_pLeft));//这里要传左子树指针的地址

		//如果右子树存在，再销毁右子树
		if ((*pRoot)->_pRight)
			DestroyBinTree(&((*pRoot)->_pRight));//这里要传右子树指针的地址

		//最后销毁跟节点
		free(*pRoot);
		*pRoot = NULL;//赋空，防止野指针产生
	}
}

void Swap(PBTNode* pLeft, PBTNode* pRight)
{
	PBTNode pTmp = NULL;
	pTmp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTmp;
}


// 二叉树的镜像递归 （前序）
void MirrorBinTree(PBTNode pRoot)
{
	if (pRoot)
	{
		//先镜像根
		Swap(&(pRoot->_pLeft), &(pRoot->_pRight));

		//如果右左子树，镜像
		if (pRoot->_pLeft)
			MirrorBinTree(pRoot->_pLeft);

		//如果有右子树，镜像
		if (pRoot->_pRight)
			MirrorBinTree(pRoot->_pRight);
	}
}

// 二叉树的镜像非递归 
void MirrorBinTreeNor(PBTNode pRoot)
{
	Stack s;
	StackInit(&s);
	PBTNode pCur = NULL;
	if (NULL == pRoot)
		return;

	//将根节点入栈
	StackPush(&s, pRoot);

	while (!StackEmpty(&s))
	{
		pCur = StackTop(&s);
		StackPop(&s);

		while (pCur)
		{
			//先镜像根
			Swap(&(pCur->_pLeft), &(pCur->_pRight));

			//如果有右子树，再将右子树入栈
			if (pCur->_pRight)
				StackPush(&s, pCur->_pRight);

			//一直走左子树
			pCur = pCur->_pLeft;
		}

	}

}

// 求二叉树中结点的个数 
//将每个节点看作一个新树，然后求新树的左右子树节点，最后加上跟节点
int BinTreeSize(PBTNode pRoot)
{
	if (NULL == pRoot)
		return 0;

	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
}

// 获取二叉树中叶子结点的个数 
int GetLeafCount(PBTNode pRoot)
{
	//如果树都不存在返回0
	if (NULL == pRoot)
		return 0;

	//如果没有左子树也没有右子树，就是叶子节点返回1
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	//比较复杂的树，求左子树叶子节点加上右子树叶子节点个数
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}


// 求二叉树中K层结点的个数 
int GetKLevelNode(PBTNode pRoot, int K)
{
	//如果树不存在或者K<1,返回0，因为最低都为1层
	if (NULL == pRoot || K < 1)
		return 0;

	if (1 == K)
		return 1;

	//根的第K层，就是左子树和右子树的第K-1层，求K层的节点个数，
	//就是求它左子树和右子树K-1层的节点数之和
	return GetKLevelNode(pRoot->_pLeft, K - 1) + GetKLevelNode(pRoot->_pRight, K - 1);
}

// 求二叉树的高度 
int Hight(PBTNode pRoot)
{
	int LeftHigh = 0;
	int RightHigh = 0;
	//如果树不存在，说明高度为0
	if (NULL == pRoot)
		return 0;

	//如果树没有左子树和右子树，高度就是他自己，为1
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	LeftHigh = Hight(pRoot->_pLeft);
	RightHigh = Hight(pRoot->_pRight);

	//复杂的树就是先求出它左子树高度，再求出右子树高度，大的加1就是树的高度
	return LeftHigh > RightHigh ? LeftHigh + 1 : RightHigh + 1;

}

//判断一棵二叉树是否有数据为data的节点，并返回该节点
PBTNode IsExitData(PBTNode pRoot, BTDataType data)
{
	PBTNode pRet = NULL;
	if (NULL == pRoot)
		return NULL;

	//前序，从跟节点开始找
	if (pRoot->_data == data)
		return pRoot;

	//去左子树找
	if (pRet = IsExitData(pRoot->_pLeft, data))
		return pRet;

	//去右子树找
	return IsExitData(pRoot->_pRight, data);
}

//判断一个节点是否在一棵二叉树中
int IsExitPBTNode(PBTNode pRoot, PBTNode Node)
{
	if (NULL == pRoot)
		return 0;

	//前序，从跟节点开始找
	if (pRoot == Node)
		return 1;

	//去左子树找
	if (IsExitPBTNode(pRoot->_pLeft, Node))
		return pRoot->_pLeft;

	//去右子树找
	return IsExitData(pRoot->_pRight, Node);
}

//判断一棵二叉树是否是完全二叉树：层序遍历
int IsCompleteBTree(PBTNode pRoot)
{
	int flag = 0;//用来标记关键节点
	Queue q;
	PBTNode pCur = pRoot;

	//空树是完全二叉树
	if (NULL == pRoot)
		return 1;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while (!QueueEmpty(&q))
	{
		pCur = QueueFront(&q);
		QueuePop(&q);

		//如果flag等于1，说明已经找到关键点，此时关键点之后的所有节点都必须是叶子节点
		if (flag == 1)
		{
			if (pCur->_pLeft || pCur->_pRight)
				return 0;
		}

		//先要找到那个关键节点，如果有左子树且有右子树，为正常节点
		else if (pCur->_pLeft && pCur->_pRight)
		{
			//左子树入队列
			QueuePush(&q, pCur->_pLeft);

			//右子树入队列
			QueuePush(&q, pCur->_pRight);
		}

		//如果只有左子树，就是关键节点，从这个节点之后的所有节点都不能有子树
		else if (pCur->_pLeft)
		{
			flag = 1;//标记位置为1

			//左子树入队列
			QueuePush(&q, pCur->_pLeft);
		}

		//如果只有右子树，就一定不是完全二叉树
		else if (pCur->_pRight)
			return 0;

		//如果既没有左子树也没有右子树，这个节点也是关键点
		else
			flag = 1;
	}
}