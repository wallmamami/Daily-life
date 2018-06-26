#include "SList.h"

//��ʼ�����ǽ�����ͷָ�븳�գ�
//ע������Ҫ��ͷָ��ĵ�ַ���ܸı�ͷָ���ֵ
void SListInit(PNode* pHead)
{
	assert(pHead);//�ж������Ƿ����
	*pHead = NULL;
}
//�����½ڵ�
PNode BuyNewNode(DataType data)
{
	PNode ptr = NULL;
	ptr = (PNode)malloc(sizeof(DataType)+sizeof(PNode));

	if (NULL == ptr)
	{
		printf("BuyNewNode failed!!!\n");
		return NULL;
	}
	//����ɹ�	
	ptr->data = data;
	ptr->_pNext = NULL;
	return ptr;
}

//��ӡ����
void PrintfList(PNode pHead)
{
	PNode ptr = pHead;
	if (pHead == NULL)
		return;
	while (ptr)
	{
		printf("%d-->", ptr->data);
		ptr = ptr->_pNext;
	}
	printf("NULL\n");

}

//β��
void SListPushBack(PNode* pHead, DataType data)
{
	PNode pCur = NULL;
	assert(pHead);//�ж������Ƿ����

	if (*pHead == NULL)//�ж������Ƿ�Ϊ��
	{
		*pHead = BuyNewNode(data);//�վ���ͷ�ڵ�ָ���½ڵ�
		return;
	}

	//1.���ҵ��������һ���ڵ�
	pCur = *pHead;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;//������һ��
	}
	pCur->_pNext = BuyNewNode(data);

}

//βɾ
void SListPopBack(PNode* pHead)
{
	assert(pHead);
	PNode pPre = *pHead;
	PNode pCur = *pHead;

	if (*pHead == NULL)
	{
		printf("�����ѿգ�ɾ��ʧ��!!!\n");
		return;
	}

	//1.ֻ��һ���ڵ�
	if (pCur->_pNext == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		return;
	}
	//2.��һ�����Ͻڵ�
	while (pCur->_pNext)
	{
		pPre = pCur;//��ΪҪ�ҵ������ڶ����ڵ㣬����ÿ��һ��֮ǰ�ȱ���
		pCur = pCur->_pNext;
	}
	free(pPre->_pNext);
	pPre->_pNext = NULL;
}

//ͷ��
void SListPushFront(PNode* pHead, DataType data)
{
	PNode ptr = NULL;
	assert(pHead);
	
	ptr = *pHead;//�ȱ����һ���ڵ��ַ
	*pHead = BuyNewNode(data);//ͷָ��ָ���½ڵ�
	(*pHead)->_pNext = ptr;//�½ڵ��_pNextָ��ԭ����ͷ�ڵ�

}

//ͷɾ
void SListPopFront(PNode* pHead)// ͷɾ
{
	assert(pHead);
	PNode ptr = NULL;
	if (NULL == pHead)
	{
		printf("�����ѿգ�ɾ��ʧ��!!!\n");
		return;
	}

	ptr = *pHead;//�ȱ���ͷ�ڵ��ַ
	*pHead = (*pHead)->_pNext;//ͷָ�볯����һ����
	free(ptr);//�ͷ�ԭͷ�ڵ�ռ�
}
//����Ϊdata�Ľڵ�
PNode SListFind(PNode pHead, DataType data)
{
	PNode ptr = pHead;
	if (NULL == pHead)
	{
		printf("�Բ���Ϊ������!!!\n");
		return NULL;
	}

	while ((ptr) && (ptr->data != data))//ptr�е�data����Ҫ�ҵ��Ҳ�Ϊ�վͽ���ѭ��
	{
		ptr = ptr->_pNext;
	}

    //1.ptrΪ�գ�֤���Ҳ���
	if (NULL == ptr)
	{
		printf("�Բ����Ҳ���!!!\n");
		return NULL;
	}
	else
		return ptr;
}

int SListSize(PNode pHead)
{
	int count = 0;
	while (pHead)
	{
		pHead = pHead->_pNext;
		count++;
	}
	return count;
}

void SListInsert(PNode* pHead, PNode pos, DataType data)
{
	assert(pHead);
	
	//1.����Ϊ��
	if (NULL == *pHead)
	{
		//1.�������Ϊ�գ�����λ����ͷ�ڵ��ַ����ͬ����ôλ�ò��Ϸ�
		if (pos == *pHead)
		{
			*pHead = BuyNewNode(data);
			return;
		}
		else
		{
			printf("λ�ò��Ϸ�������ʧ��!!!\n");
			return;
		}
	}

	//2.����Ϊ��
	//(1)ͷ��:pos��ͷ�ڵ��ַ���
	if (pos == *pHead)
		SListPushFront(pHead, data);
	//(2)pos��ͷ�ڵ�λ�ò����
	else
	{
		PNode pPre = *pHead;
		PNode pCur = *pHead;
		while ((pCur) && (pCur->_pNext != pos))
		{
			pCur = pCur->_pNext;
		}
		if (pCur == NULL)
		{
			printf("�Բ����Ҳ����ýڵ�!!!\n");
			return;
		}
		else
		{
			pCur->_pNext = BuyNewNode(data);//�����½ڵ�
			pCur->_pNext->_pNext = pos;//�½ڵ�����pos���Ľڵ�
			pos = pCur->_pNext;//posָ���½ڵ�
		}

	}
}


// ɾ��posλ�õĽ�� 
void SListErase(PNode* pHead, PNode pos)
{
	assert(pHead);
	PNode ptr = *pHead;

	if (NULL == *pHead)
	{
		printf("�����ѿգ�ɾ��ʧ��!!!\n");
		return;
	}

	//1.ֻ��һ���ڵ�
	if ((*pHead)->_pNext == NULL)
	{
		if (*pHead == pos)
		{
			free(pos);
			*pHead = NULL;
			return;
		}

		else
		{
			printf("λ�ò��Ϸ���ɾ��ʧ��!!!\n");
			return;
		}
	}

	//2.��һ�����Ͻڵ�
	//(1)���pos��ͷ�ڵ�
	if (pos == *pHead)
	{
		*pHead = (*pHead)->_pNext;
		free(pos);
		return;
	}

	//(2)����ͷ���
	while ((ptr) && (ptr->_pNext != pos) && (pos))
	{
		ptr = ptr->_pNext;
	}

	if ((ptr == NULL) || (pos == NULL))
	{
		printf("�ڵ㲻���ڣ�ɾ��ʧ��!!!\n");
		return;
	}
	else
	{
		ptr->_pNext = pos->_pNext;//������pos���¸��ڵ�
		free(pos);
	}
}
// �ж������Ƿ�Ϊ�� 
int SListEmpty(PNode pHead)
{
	if (pHead)
		return 0;
	return 1;
}

// ��������
void SListDestroy(PNode* pHead)
{
	assert(pHead);
	PNode ptr = *pHead;
	PNode pMsg = *pHead;
	
	while (ptr)
	{
		ptr = ptr->_pNext;//ptr������
		free(pMsg);//�ͷ�pMsgָ��Ŀռ�
		pMsg = ptr;//pMsg����ptr��
	}
	*pHead = NULL;
}
//�����ӡ����
//1.�õݹ�Ƚϼ�
void PrintSListFromTail2Head(PNode pHead)
{
	if (pHead->_pNext != NULL)
	{
		PrintSListFromTail2Head(pHead->_pNext);
	}
		
	printf("%d ", pHead->data);
	return;
}

// ɾ������ķ�β��㣬Ҫ�󣺲��ܱ������� 
//1.��Ϊ�Ƿ�β�ڵ㣬�Ҳ��ܱ������������Ҳ���posǰ����Ǹ��ڵ㣬
//  ֻ��ɾ��pos����Ľڵ㣬���Ѻ�������ݸ��ǵ�pos
void DeleteListNotTailNode(PNode pos)
{
	PNode pNext = pos->_pNext;
	pos->data = pNext->data;//�Ƚ����ݸ���pos
	pos->_pNext = pNext->_pNext;//�����Ӻ���Ľڵ�
	free(pNext);//�ͷŽڵ�
	pNext = NULL;

}

// ������posλ��ǰ����ֵ��data�Ľ�� 
//1.��Ϊû��ͷ�ڵ㣬���Բ������ҵ�posǰ��Ľڵ�
//ֻ���ҵ�����Ľڵ㣬Ȼ������֮������½ڵ㣬��
//���½ڵ��������pos����(��Ϊ�˼��ò嵽posλ��)
void InesrtPosFront(PNode pos, DataType data)
{
	PNode Next = pos->_pNext;//�ȱ���pos����һ���ڵ�
	pos->_pNext = BuyNewNode(pos->data);//���½ڵ����ӵ�pos���棬��pos��dataΪ�˱����Ժ��ٽ���
	pos->_pNext->_pNext = Next;//��pos֮ǰ���¸��ڵ����ӵ��½ڵ����
	pos->data = data;//����������data����ԭdata
}

// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
//1.���Դ�������ָ�������һ���������һ���߿�㣬
//һ����������������ĵĶ��������������ʱ�����ĸպ�ͣ���м�λ��
PNode FindMiddleNode(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	PNode pPre = pHead;

	//��һ������Ϊ�˱�֤�����ߵڶ�����
	//�ڶ�������Ϊ�˱�֤�����߳���һ��
	while ((pFast) && (pFast->_pNext))//ǰ�������һ��Ҫ��pFast
	{
		pPre = pSlow;
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}
	if (pFast == NULL)//ż������ʱpFastΪ�գ�����pFast->_NextΪ��
		return pPre;//���ؽ�С���м�ڵ�

	return pSlow;//��������Ϊż�������ص��ǽϴ���м�ڵ�
}

// ��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������
//1.������˼·һ�£����Դ�������ָ�룬һ��ָ������k����
//��������ָ��һ���ߣ�����ָ���ߵ�NULLʱ����ָ���ͣ�ڵ�����k��
PNode FindLastKNode(PNode pHead, int K)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	if (NULL == pHead || (K <= 0))
	{
		printf("K���Ϸ�!!!\n");
		return NULL;
	}
	//��pFast����K��
	while (K--)
	{
		//K���������нڵ�ĸ���
		if (NULL == pFast)
			return NULL;
		pFast = pFast->_pNext;
	}

	while (pFast)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}

	return pSlow;
}

// ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������
void DeleteLastKNode(PNode *pHead, int K)
{
	assert(pHead);
	PNode pFast = *pHead;
	PNode pSlow = *pHead;
	PNode pPre = *pHead;

	if (NULL == pHead || (K <= 0))
	{
		printf("K���Ϸ�!!!\n");
		return;
	}
	//��pFast����K��
	while (K--)
	{
		//K���������нڵ�ĸ���
		if (NULL == pFast)
			return;
		pFast = pFast->_pNext;
	}

	while (pFast)
	{
		pFast = pFast->_pNext;
		pPre = pSlow;//pSlow����֮ǰ���ȱ��棬�����Ժ�ɾ��
		pSlow = pSlow->_pNext;

	}

	//�ǵ�һ���ڵ�
	if (pSlow == pPre)
	{
		*pHead = pSlow->_pNext;
		free(pSlow);
		return;
	}
	//���ǵ�һ���ڵ�
	pPre->_pNext = pSlow->_pNext;
	free(pSlow);

}

// �õ�����ʵ��Լɪ�� 
void JosephCircle(PNode* pHead, const int M)
{
	assert(pHead);

	while ((*pHead)->_pNext != *pHead)//����˵��ֻʣһ���ڵ�
	{
		PNode pCur = *pHead;
		PNode pPre = *pHead;
		int count = M;

		while (--count)//ע�⣬������ǰ��--
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		pPre->_pNext = pCur->_pNext;//��������
		*pHead = pCur->_pNext;//�ı�ͷָ��λ��
		free(pCur);
	}
}

// ���������--����ָ�� 
//���ǽ�ԭ��Next��ָ����һ������ָ����һ���������������
void ReverseSList(PNode* pHead)
{
	assert(pHead);
	PNode pPre = NULL;
	PNode pCur = *pHead;
	PNode pNext = NULL;

	if (NULL == *pHead)
		return;

	while (pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pPre;//��Nextָ����ָ����һ���ڵ�
		pPre = pCur;
		pCur = pNext;
	}

	*pHead = pPre;//pPre��Ϊ�µ�ͷ�ڵ�

}

// ���������--ͷ�巨 
//����һ����ͷ����Ȼ�������еĽڵ��ǰ����ʹ��ͷ�巨�嵽��ͷ����
PNode ReverseSListOP(PNode pHead)
{
	PNode pCur = pHead;
	PNode pNewHead = NULL;

	while (pHead)
	{
		pCur = pHead;//��������pCurָ��ͷ��
		pHead = pHead->_pNext;//ͷ�����һ��
		pCur->_pNext = pNewHead;//pCur�嵽��ͷ��ǰ
		pNewHead = pCur;//��ͷΪpCur
	}

	return pNewHead;
}


// �ϲ��������������ϲ�����Ȼ���� 
//�����С�����������
PNode MergeSList(PNode pHead1, PNode pHead2)
{
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;
	PNode pNewHead = NULL;
	PNode pTail = NULL;//������¼�ϲ�����������һ���ڵ�

	if (NULL == pHead1)
		return pHead2;
	if (NULL == pHead2)
		return pHead1;
	//��pNewHead
	if (pCur1->data < pCur2->data)
	{
		pNewHead = pCur1;
		pCur1 = pCur1->_pNext;
	}

	else if (pCur1->data >= pCur2->data)
	{
		pNewHead = pCur2;
		pCur2 = pCur2->_pNext;
	}
	//�������н�С�Ľڵ�β�嵽pNewHead
	pTail = pNewHead;
	while (pCur1 && pCur2)//ֻҪ��һ������Ϊ�վͳ���
	{
		if (pCur1->data < pCur2->data)
		{
			pTail->_pNext = pCur1;
			pCur1 = pCur1->_pNext;	
		}
		else if (pCur1->data >= pCur2->data)
		{
			pTail->_pNext = pCur2;
			pCur2 = pCur2->_pNext;
		}
		pTail = pTail->_pNext;

	}

	if (pCur1)//˵��pCur2Ϊ��
		pTail->_pNext = pCur1;

	else
		pTail->_pNext = pCur2;
		
	return pNewHead;
}

// �ж������������Ƿ��ཻ---�������� 
int IsSListCross(PNode pHead1, PNode pHead2)
{
	//1.�����������һ��Ϊ����ô�϶����ཻ
	if (NULL == pHead1)
		return 0;
	if (NULL == pHead2)
		return 0;

	//2.����������ཻ����ô�������һ���ڵ�϶���ͬ
	while (pHead1->_pNext)
	{
		pHead1 = pHead1->_pNext;
	}

	while (pHead2->_pNext)
	{
		pHead2 = pHead2->_pNext;
	}

	if (pHead1 == pHead2)
		return 1;
	else
		return 0;
}

// �������������ཻ�Ľ���---�������� 
PNode GetCorssNode(PNode pHead1, PNode pHead2)
{
	PNode pCur1 = NULL;
	PNode pCur2 = NULL;
	int size1 = 0;
	int size2 = 0;
	int gap = 0;
	//1.���ж����������Ƿ��ཻ
	if (!IsSListCross(pHead1, pHead2))
		return NULL;
	pCur1 = pHead1;
	pCur2 = pHead2;

	//2.���������ȵĲ�ֵgap
	while (pCur1->_pNext)
	{
		size1++;
		pCur1 = pCur1->_pNext;
	}
	while (pCur2->_pNext)
	{
		size2++;
		pCur2 = pCur2->_pNext;
	}
	gap = size1 - size2;

	//3.�ýϳ��������ͷ������gap��
	pCur1 = pHead1;
	pCur2 = pHead2;
	if (gap > 0)//˵������1�ϳ�
	{
		while (gap--)
		{
			pCur1 = pCur1->_pNext;
		}
	}

	else
	{
		while (gap++)
		{
			pCur2 = pCur2->_pNext;
		}
	}

	//4.��ָ��һ���ߣ�ֱ����Ȼ�Ϊ��
	while (pCur1 && pCur2 && (pCur1 != pCur2))
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;
	}

	if ((pCur1 == NULL) || (pCur2 == NULL))
		return NULL;
	else
		return pCur1;
}

// �ж������Ƿ����������������---ע���Ƶ���ʽ
//������ָ�룬һ��һ��(ע���������ֵ�պ��ǻ��ĳ��ȣ�����)
//��������������Ǳض�����
PNode IsListWithCircle(PNode pHead1)
{
	PNode pFast = pHead1;
	PNode pSlow = pHead1;

	if (NULL == pHead1)
		return NULL;

	while (pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;

		if (pFast == pSlow)//����������϶�����
			return	pSlow;
	}

	return NULL;
}

// ��ȡ������ڵ�
//���������������ô��������ָ�룬һ��������ͷ����ʼ�ߣ�
//һ���������㿪ʼ�ߣ���ô���ǵ�������ض��ǻ������
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode)
{
	PNode pCur1 = NULL;
	PNode pCur2 = NULL;

	if (NULL == pMeetNode || NULL == pMeetNode)//������������
		return NULL;

	pCur1 = pHead1;
	pCur2 = pMeetNode;
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;
	}

	return pCur1;
}

// ��ȡ���ĳ���
//����һ��ָ���������һֱ�ߣ�ֱ���ٴ��ߵ�������
int GetCircleLen(PNode pHead1, PNode pMeetNode)
{
	PNode ptr = NULL;
	int len = 0;
	pMeetNode = IsListWithCircle(pHead1);

	if (!pMeetNode)
		return 0;

	ptr = pMeetNode;
	while (ptr->_pNext != pMeetNode)//��Ϊ���¸��ڵ㣬��������ĳ�����һ
	{
		len++;
		ptr = ptr->_pNext;
	}

	return len + 1;
}

// �ж����������Ƿ��ཻ��������ܴ���
//��Ϊ���������1.����������2.��������3.������һ����(�϶����ཻ����������)
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2)
{
	PNode pMeetNode1 = NULL;
	PNode pMeetNode2 = NULL;

	if (NULL == pHead1)
		return 0;
	if (NULL == pHead2)
		return 0;

	//1.�ж����������Ƿ����
	pMeetNode1 = IsListWithCircle(pHead1);
	pMeetNode2 = IsListWithCircle(pHead2);

	if (NULL == pMeetNode1 && NULL == pMeetNode2)//������������
	{
		PNode pTail1 = pHead1;
		PNode pTail2 = pHead2;

		while (pTail1->_pNext)
			pTail1 = pTail1->_pNext;
		while (pTail2->_pNext)
			pTail2 = pTail2->_pNext;

		if (pTail1 == pTail2)
			return 1;
	}

	else if (pMeetNode1 && pMeetNode2)//����������
	{
		//1.�����ཻ
		//2.�����ཻ(��������ķ�ʽ����)
		//һ��ָ��ָ��һ�������㣬���ָ��
		//�ƻ�һ��û�к���һ����������ô�Ͳ��ཻ
		PNode pCur = pMeetNode1;

		while (pCur->_pNext != pMeetNode1)
		{
			if (pCur == pMeetNode2)
				return 2;
			pCur = pCur->_pNext;
		}

		//����ڶ���������ǡ�������һ���ڵ㣬���洦����
		if (pCur == pMeetNode2)
			return 2;

	}

	return 0;
}

//����������
PCSLNode CopyComplexList(PCSLNode pHead)
{
	PCSLNode pCur = pHead;
	PCSLNode pNewNode = NULL;
	PCSLNode pNewHead = NULL;
	if (NULL == pHead)
		return NULL;

	//1.������������ֵ��ͬ���½ڵ�
	while (pCur)
	{
		pNewNode = BuyCSNewNode(pCur->data);
		pNewNode->_pNext = pCur->_pNext;
		pCur->_pNext = pNewNode;
		pCur = pNewNode->_pNext;
	}
	pCur = pHead;

	//2.���½ڵ�����ָ����ֵ
	//�����ָ����ָ��ԭ�ڵ����ָ��ָ����¸��ڵ�
	while (pCur)
	{
		pNewNode = pCur->_pNext;
		if (pCur->_pRandom)
		{
			pNewNode->_pRandom = pCur->_pRandom->_pNext;
		}
		pCur = pNewNode->_pNext;
		
	}

	//3.���½ڵ��ԭ�����в�����
	pCur = pHead;
	pNewHead = pHead->_pNext;
	while (pCur->_pNext)
	{
		pNewNode = pCur->_pNext;
		pCur->_pNext = pNewNode->_pNext;
		pCur = pNewNode;

	}
	
	return pNewHead;
}

PCSLNode BuyCSNewNode(DataType data)
{
	PCSLNode ptr = NULL;
	ptr = (PCSLNode)malloc(sizeof(CSListNode));
	if (ptr != NULL)
	{
		ptr->data = data;
		ptr->_pNext = NULL;
		ptr->_pRandom = NULL;
		return ptr;
	}
	return NULL;
}