#include "BInTree.h"



// �����������Ľ�� 
PBTNode BuyBinTreeNode(BTDataType data)
{
	PBTNode PNewNode = NULL;

	PNewNode = (PBTNode)malloc(sizeof(BTNode));

	if (PNewNode == NULL)
	{
		printf("�ռ�����ʧ��!!!\n");
		return NULL;
	}

	PNewNode->_data = data;
	PNewNode->_pLeft = NULL;
	PNewNode->_pRight = NULL;

	return PNewNode;
}

//������������������
//�����˼·���ǽ���������ÿ���ڵ㵱��һ�����������������ĸ��ڵ㣬
//Ȼ�󴴽����ڵ������������󴴽��������������ͽ������ģ��С�����Եݹ�����
void _CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, int* index, BTDataType invalid)
{
	assert(pRoot);
	//���arr[*index]������'#'��������indexû��Խ�磬�Ǿʹ������ڵ�
	if (arr[*index] != invalid && *index < size)
	{
		//�������ڵ�
		*pRoot = BuyBinTreeNode(arr[*index]);

		//����������
		//ע�⣺�����(*index++)������Ҫ������ʱ��ȥ++���������ٴ���֮��
		(*index)++;
		_CreateBinTree(&((*pRoot)->_pLeft), arr, size, index, invalid);

		//����������
		(*index)++;
		_CreateBinTree(&((*pRoot)->_pRight), arr, size, index, invalid);
	}
	
}

//���û��Ľӿ�
void CreateBinTree(PBTNode* pRoot, const BTDataType* arr, int size, BTDataType invalid)
{
	int index = 0;//�����������������ַ���
	assert(pRoot);
	if (arr == NULL)
		return;

	_CreateBinTree(pRoot, arr, size, &index, invalid);//��ΪҪ����һ�������ڲ��ı�index��ֵ�����Դ���ַ
}

//ǰ���������������-->������-->������
//�ݹ�
void PreOrder(PBTNode pRoot)
{

	//������ڵ㲻Ϊ�գ�����
	if (pRoot)
	{
		printf("%c ", pRoot->_data);

		//�����������Ϊ�գ�����
		//�ж���Ϊ�˼��ٵݹ����
		if (pRoot->_pLeft)
			PreOrder(pRoot->_pLeft);

		//������������ڣ�����
		if (pRoot->_pRight)
			PreOrder(pRoot->_pRight);
	}
}
//��ʼ��ջ
void StackInit(PStack s)
{
	assert(s);

	s->size = 0;
}

//��ջ
void StackPush(PStack s, SDataType data)
{
	assert(s);

	if (s->size == MAX_SIZE)
	{
		printf("ջ����!\n");
		return;
	}

	s->arr[s->size] = data;
	s->size++;
}

//��ջ
void StackPop(PStack s)
{
	assert(s);

	if (s->size == 0)
	{
		printf("ջ�ѿ�!\n");
		return;
	}

	s->size--;
}

//��ȡջ��Ԫ��
SDataType StackTop(PStack s)
{
	assert(s);

	if (s->size == 0)
	{
		printf("ջ�ѿ�!\n");
		return NULL;
	}

	return s->arr[s->size - 1];
}

//ջ�п�
int StackEmpty(PStack s)
{
	assert(s);

	if (s->size == 0)
		return 1;
	return 0;
}

// ǰ������ǵݹ� (��ջ)
void PreOrderNor(PBTNode pRoot)
{
	Stack s;
	StackInit(&s);

	if (NULL == pRoot)
		return;

	//�����ڵ���ջ
	StackPush(&s, pRoot);

	while (!StackEmpty(&s))
	{
		//ȡջ��Ԫ��
		PBTNode pCur = StackTop(&s);

		//����,��ջ
		printf("%c ", pCur->_data);
		StackPop(&s);
		
		//������������ڣ���ջ
		if (pCur->_pRight)
			StackPush(&s, pCur->_pRight);

		//������������ڣ���ջ
		if (pCur->_pLeft)
			StackPush(&s, pCur->_pLeft);

	}
}

//ǰ������ǵݹ飨�ȱ�����������
void PreOrderNor2(PBTNode pRoot)
{
	Stack s;
	StackInit(&s);
	PBTNode pCur = NULL;
	if (NULL == pRoot)
		return;

	//�����ڵ���ջ
	StackPush(&s, pRoot);

	while (!StackEmpty(&s))
	{
		pCur = StackTop(&s);
		StackPop(&s);

		while (pCur)
		{
			//�ȱ���
			printf("%c ", pCur->_data);

			//��������������ٽ���������ջ
			if (pCur->_pRight)
				StackPush(&s, pCur->_pRight);

			//һֱ��������
			pCur = pCur->_pLeft;
		}

	}
}

// ��������ݹ� :������-->��-->������
void InOrder(PBTNode pRoot)
{
	//�ж����Ƿ�Ϊ��
	if (pRoot)
	{
		//�ȱ���������
		if (pRoot->_pLeft)
			InOrder(pRoot->_pLeft);

		//�������ڵ�
		printf("%c ", pRoot->_data);

		//����ҽڵ���ڣ�����
		if (pRoot->_pRight)
			InOrder(pRoot->_pRight);
	}
}

//��������ǵݹ�
void InOrderNor(PBTNode pRoot)
{
	Stack s;
	PBTNode pCur = pRoot;
	if (NULL == pRoot)
		return;

	//ʹ��ջ֮ǰһ��Ҫ��ʼ��
	StackInit(&s);

	while (pCur || !StackEmpty(&s))
	{
		//���ҵ����ڵ������Ľڵ㲢��������·���ϵ����нڵ�
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		//���⣬˵��pCurΪ�գ������ߵ������ڵ㣬����֮���ٵ�������
		pCur = StackTop(&s);
		StackPop(&s);
		printf("%c ", pCur->_data);
		pCur = pCur->_pRight;
	}
}

// ���������ݹ� ��������-->������-->��
void PostOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		//������������ڣ�����
		if (pRoot->_pLeft)
			PostOrder(pRoot->_pLeft);

		//������������ڣ�����
		if (pRoot->_pRight)
			PostOrder(pRoot->_pRight);

		//���������ڵ�
		printf("%c ", pRoot->_data);

	}
}

//��������ǵݹ�
void PostOrderNor(PBTNode pRoot)
{
	Stack s;
	PBTNode pCur = pRoot;
	PBTNode pTop = NULL;
	PBTNode pPre = NULL;//�����������һ�α����Ľڵ�
	if (NULL == pRoot)
		return;

	StackInit(&s);

	while (pCur || !StackEmpty(&s))
	{
		//���ҵ���pCurΪ���ڵ�������ڵ㣬������·�������еĽڵ�
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		//
		pTop = StackTop(&s);

		//���pTopû�����������������������������˲��ܱ������ڵ�
		if (!pTop->_pRight || pPre == pTop->_pRight)
		{
			StackPop(&s);
			printf("%c ", pTop->_data);
			pPre = pTop;
		}

		//���pTop�����������ˣ���ô����������һ�����������ˣ����Բ����ڳ���������
		else
			pCur = pTop->_pRight;
	}


}

//��������ڵ�
QNode* BuyQNewNode(QDataType data)
{
	QNode* PNewNode = NULL;
	PNewNode = (QNode*)malloc(sizeof(QNode));
	
	if (NULL == PNewNode)
	{
		printf("�ռ�����ʧ��!\n");
		return NULL;
	}

	PNewNode->_data = data;
	PNewNode->_pNext = NULL;
	return PNewNode;
}

//��ʼ������,��ͷ�ڵ�
void QueueInit(PQueue q)
{
	assert(q);

	q->_pHead = q->_pTail = BuyQNewNode(0);
}

//�����
void QueuePush(PQueue q, QDataType data)
{
	assert(q);

	//β��
	q->_pTail->_pNext = BuyQNewNode(data);
	q->_pTail = q->_pTail->_pNext;
}

//������
void QueuePop(PQueue q)
{
	assert(q);
	QNode* pDelete = q->_pHead->_pNext;

	if (q->_pHead->_pNext == NULL)
	{
		printf("�����ѿգ�\n");
		return;
	}

	q->_pHead->_pNext = q->_pHead->_pNext->_pNext;
	if (q->_pHead->_pNext == NULL)
		q->_pTail = q->_pHead;
	free(pDelete);
}

//�����п�
int QueueEmpty(PQueue q)
{
	assert(q);

	if (q->_pHead->_pNext == NULL)
		return 1;
	return 0;
}

//ȡ��ͷԪ��
QDataType QueueFront(PQueue q)
{
	assert(q);

	if (q->_pHead->_pNext == NULL)
	{
		printf("����Ϊ��\n");
		return 0;
	}

	return q->_pHead->_pNext->_data;
}

// ������� 
void LevelOrder(PBTNode pRoot)
{
	Queue q;
	QueueInit(&q);

	if (NULL == pRoot)
		return;

	//�����ڵ������
	QueuePush(&q, pRoot);

	while (!QueueEmpty(&q))
	{
		//ȡ��ͷԪ��
		PBTNode pCur = QueueFront(&q);

		//����,������
		printf("%c ", pCur->_data);
		QueuePop(&q);

		//������������ڣ������
		if (pCur->_pLeft)
		QueuePush(&q, pCur->_pLeft);

		//������������ڣ������
		if (pCur->_pRight)
		QueuePush(&q, pCur->_pRight);
	}

}

// ����������(�ݹ�),ǰ��
PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode pNewRoot = NULL;

	//�������Ϊ�գ��ͽ���
	if (pRoot)
	{
		//�ȿ������ڵ�
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		//������������ڣ�����
		if (pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		//������������ڣ�����
		if (pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewRoot;
}

// ���ٶ����� 
//Ҫ�ú�����������Ϊ��������ٸ����Ҳ���������������
void DestroyBinTree(PBTNode *pRoot)
{
	assert(pRoot);

	if (*pRoot)
	{
		//������������ڣ�������������
		if ((*pRoot)->_pLeft)
			DestroyBinTree(&((*pRoot)->_pLeft));//����Ҫ��������ָ��ĵ�ַ

		//������������ڣ�������������
		if ((*pRoot)->_pRight)
			DestroyBinTree(&((*pRoot)->_pRight));//����Ҫ��������ָ��ĵ�ַ

		//������ٸ��ڵ�
		free(*pRoot);
		*pRoot = NULL;//���գ���ֹҰָ�����
	}
}

void Swap(PBTNode* pLeft, PBTNode* pRight)
{
	PBTNode pTmp = NULL;
	pTmp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTmp;
}


// �������ľ���ݹ� ��ǰ��
void MirrorBinTree(PBTNode pRoot)
{
	if (pRoot)
	{
		//�Ⱦ����
		Swap(&(pRoot->_pLeft), &(pRoot->_pRight));

		//�����������������
		if (pRoot->_pLeft)
			MirrorBinTree(pRoot->_pLeft);

		//�����������������
		if (pRoot->_pRight)
			MirrorBinTree(pRoot->_pRight);
	}
}

// �������ľ���ǵݹ� 
void MirrorBinTreeNor(PBTNode pRoot)
{
	Stack s;
	StackInit(&s);
	PBTNode pCur = NULL;
	if (NULL == pRoot)
		return;

	//�����ڵ���ջ
	StackPush(&s, pRoot);

	while (!StackEmpty(&s))
	{
		pCur = StackTop(&s);
		StackPop(&s);

		while (pCur)
		{
			//�Ⱦ����
			Swap(&(pCur->_pLeft), &(pCur->_pRight));

			//��������������ٽ���������ջ
			if (pCur->_pRight)
				StackPush(&s, pCur->_pRight);

			//һֱ��������
			pCur = pCur->_pLeft;
		}

	}

}

// ��������н��ĸ��� 
//��ÿ���ڵ㿴��һ��������Ȼ�������������������ڵ㣬�����ϸ��ڵ�
int BinTreeSize(PBTNode pRoot)
{
	if (NULL == pRoot)
		return 0;

	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
}

// ��ȡ��������Ҷ�ӽ��ĸ��� 
int GetLeafCount(PBTNode pRoot)
{
	//������������ڷ���0
	if (NULL == pRoot)
		return 0;

	//���û��������Ҳû��������������Ҷ�ӽڵ㷵��1
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	//�Ƚϸ��ӵ�������������Ҷ�ӽڵ����������Ҷ�ӽڵ����
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}


// ���������K����ĸ��� 
int GetKLevelNode(PBTNode pRoot, int K)
{
	//����������ڻ���K<1,����0����Ϊ��Ͷ�Ϊ1��
	if (NULL == pRoot || K < 1)
		return 0;

	if (1 == K)
		return 1;

	//���ĵ�K�㣬�������������������ĵ�K-1�㣬��K��Ľڵ������
	//����������������������K-1��Ľڵ���֮��
	return GetKLevelNode(pRoot->_pLeft, K - 1) + GetKLevelNode(pRoot->_pRight, K - 1);
}

// ��������ĸ߶� 
int Hight(PBTNode pRoot)
{
	int LeftHigh = 0;
	int RightHigh = 0;
	//����������ڣ�˵���߶�Ϊ0
	if (NULL == pRoot)
		return 0;

	//�����û�������������������߶Ⱦ������Լ���Ϊ1
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	LeftHigh = Hight(pRoot->_pLeft);
	RightHigh = Hight(pRoot->_pRight);

	//���ӵ���������������������߶ȣ�������������߶ȣ���ļ�1�������ĸ߶�
	return LeftHigh > RightHigh ? LeftHigh + 1 : RightHigh + 1;

}

//�ж�һ�ö������Ƿ�������Ϊdata�Ľڵ㣬�����ظýڵ�
PBTNode IsExitData(PBTNode pRoot, BTDataType data)
{
	PBTNode pRet = NULL;
	if (NULL == pRoot)
		return NULL;

	//ǰ�򣬴Ӹ��ڵ㿪ʼ��
	if (pRoot->_data == data)
		return pRoot;

	//ȥ��������
	if (pRet = IsExitData(pRoot->_pLeft, data))
		return pRet;

	//ȥ��������
	return IsExitData(pRoot->_pRight, data);
}

//�ж�һ���ڵ��Ƿ���һ�ö�������
int IsExitPBTNode(PBTNode pRoot, PBTNode Node)
{
	if (NULL == pRoot)
		return 0;

	//ǰ�򣬴Ӹ��ڵ㿪ʼ��
	if (pRoot == Node)
		return 1;

	//ȥ��������
	if (IsExitPBTNode(pRoot->_pLeft, Node))
		return pRoot->_pLeft;

	//ȥ��������
	return IsExitData(pRoot->_pRight, Node);
}

//�ж�һ�ö������Ƿ�����ȫ���������������
int IsCompleteBTree(PBTNode pRoot)
{
	int flag = 0;//������ǹؼ��ڵ�
	Queue q;
	PBTNode pCur = pRoot;

	//��������ȫ������
	if (NULL == pRoot)
		return 1;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while (!QueueEmpty(&q))
	{
		pCur = QueueFront(&q);
		QueuePop(&q);

		//���flag����1��˵���Ѿ��ҵ��ؼ��㣬��ʱ�ؼ���֮������нڵ㶼������Ҷ�ӽڵ�
		if (flag == 1)
		{
			if (pCur->_pLeft || pCur->_pRight)
				return 0;
		}

		//��Ҫ�ҵ��Ǹ��ؼ��ڵ㣬�����������������������Ϊ�����ڵ�
		else if (pCur->_pLeft && pCur->_pRight)
		{
			//�����������
			QueuePush(&q, pCur->_pLeft);

			//�����������
			QueuePush(&q, pCur->_pRight);
		}

		//���ֻ�������������ǹؼ��ڵ㣬������ڵ�֮������нڵ㶼����������
		else if (pCur->_pLeft)
		{
			flag = 1;//���λ��Ϊ1

			//�����������
			QueuePush(&q, pCur->_pLeft);
		}

		//���ֻ������������һ��������ȫ������
		else if (pCur->_pRight)
			return 0;

		//�����û��������Ҳû��������������ڵ�Ҳ�ǹؼ���
		else
			flag = 1;
	}
}