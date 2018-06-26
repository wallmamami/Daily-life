#include "SList.h"

//初始化就是将链表头指针赋空，
//注意这里要传头指针的地址才能改变头指针的值
void SListInit(PNode* pHead)
{
	assert(pHead);//判断链表是否存在
	*pHead = NULL;
}
//创建新节点
PNode BuyNewNode(DataType data)
{
	PNode ptr = NULL;
	ptr = (PNode)malloc(sizeof(DataType)+sizeof(PNode));

	if (NULL == ptr)
	{
		printf("BuyNewNode failed!!!\n");
		return NULL;
	}
	//申请成功	
	ptr->data = data;
	ptr->_pNext = NULL;
	return ptr;
}

//打印链表
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

//尾插
void SListPushBack(PNode* pHead, DataType data)
{
	PNode pCur = NULL;
	assert(pHead);//判断链表是否存在

	if (*pHead == NULL)//判断链表是否为空
	{
		*pHead = BuyNewNode(data);//空就让头节点指向新节点
		return;
	}

	//1.先找到链表最后一个节点
	pCur = *pHead;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;//朝后走一步
	}
	pCur->_pNext = BuyNewNode(data);

}

//尾删
void SListPopBack(PNode* pHead)
{
	assert(pHead);
	PNode pPre = *pHead;
	PNode pCur = *pHead;

	if (*pHead == NULL)
	{
		printf("链表已空，删除失败!!!\n");
		return;
	}

	//1.只有一个节点
	if (pCur->_pNext == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		return;
	}
	//2.有一个以上节点
	while (pCur->_pNext)
	{
		pPre = pCur;//因为要找到倒数第二个节点，所以每走一步之前先保存
		pCur = pCur->_pNext;
	}
	free(pPre->_pNext);
	pPre->_pNext = NULL;
}

//头插
void SListPushFront(PNode* pHead, DataType data)
{
	PNode ptr = NULL;
	assert(pHead);
	
	ptr = *pHead;//先保存第一个节点地址
	*pHead = BuyNewNode(data);//头指针指向新节点
	(*pHead)->_pNext = ptr;//新节点的_pNext指向原来的头节点

}

//头删
void SListPopFront(PNode* pHead)// 头删
{
	assert(pHead);
	PNode ptr = NULL;
	if (NULL == pHead)
	{
		printf("链表已空，删除失败!!!\n");
		return;
	}

	ptr = *pHead;//先保存头节点地址
	*pHead = (*pHead)->_pNext;//头指针朝后走一步；
	free(ptr);//释放原头节点空间
}
//查找为data的节点
PNode SListFind(PNode pHead, DataType data)
{
	PNode ptr = pHead;
	if (NULL == pHead)
	{
		printf("对不起，为空链表!!!\n");
		return NULL;
	}

	while ((ptr) && (ptr->data != data))//ptr中的data不是要找的且不为空就进入循环
	{
		ptr = ptr->_pNext;
	}

    //1.ptr为空，证明找不到
	if (NULL == ptr)
	{
		printf("对不起，找不到!!!\n");
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
	
	//1.链表为空
	if (NULL == *pHead)
	{
		//1.如果链表为空，插入位置与头节点地址不相同，那么位置不合法
		if (pos == *pHead)
		{
			*pHead = BuyNewNode(data);
			return;
		}
		else
		{
			printf("位置不合法，插入失败!!!\n");
			return;
		}
	}

	//2.链表不为空
	//(1)头插:pos与头节点地址相等
	if (pos == *pHead)
		SListPushFront(pHead, data);
	//(2)pos与头节点位置不相等
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
			printf("对不起，找不到该节点!!!\n");
			return;
		}
		else
		{
			pCur->_pNext = BuyNewNode(data);//插入新节点
			pCur->_pNext->_pNext = pos;//新节点链接pos处的节点
			pos = pCur->_pNext;//pos指向新节点
		}

	}
}


// 删除pos位置的结点 
void SListErase(PNode* pHead, PNode pos)
{
	assert(pHead);
	PNode ptr = *pHead;

	if (NULL == *pHead)
	{
		printf("链表已空，删除失败!!!\n");
		return;
	}

	//1.只有一个节点
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
			printf("位置不合法，删除失败!!!\n");
			return;
		}
	}

	//2.有一个以上节点
	//(1)如果pos是头节点
	if (pos == *pHead)
	{
		*pHead = (*pHead)->_pNext;
		free(pos);
		return;
	}

	//(2)不是头结点
	while ((ptr) && (ptr->_pNext != pos) && (pos))
	{
		ptr = ptr->_pNext;
	}

	if ((ptr == NULL) || (pos == NULL))
	{
		printf("节点不存在，删除失败!!!\n");
		return;
	}
	else
	{
		ptr->_pNext = pos->_pNext;//链接起pos的下个节点
		free(pos);
	}
}
// 判断链表是否为空 
int SListEmpty(PNode pHead)
{
	if (pHead)
		return 0;
	return 1;
}

// 销毁链表
void SListDestroy(PNode* pHead)
{
	assert(pHead);
	PNode ptr = *pHead;
	PNode pMsg = *pHead;
	
	while (ptr)
	{
		ptr = ptr->_pNext;//ptr朝后走
		free(pMsg);//释放pMsg指向的空间
		pMsg = ptr;//pMsg跟着ptr走
	}
	*pHead = NULL;
}
//逆序打印链表
//1.用递归比较简单
void PrintSListFromTail2Head(PNode pHead)
{
	if (pHead->_pNext != NULL)
	{
		PrintSListFromTail2Head(pHead->_pNext);
	}
		
	printf("%d ", pHead->data);
	return;
}

// 删除链表的非尾结点，要求：不能遍历链表 
//1.因为是非尾节点，且不能遍历链表，所以找不到pos前面的那个节点，
//  只能删除pos后面的节点，并把后面的内容覆盖到pos
void DeleteListNotTailNode(PNode pos)
{
	PNode pNext = pos->_pNext;
	pos->data = pNext->data;//先将数据覆盖pos
	pos->_pNext = pNext->_pNext;//再链接后面的节点
	free(pNext);//释放节点
	pNext = NULL;

}

// 在链表pos位置前插入值到data的结点 
//1.因为没有头节点，所以不可能找到pos前面的节点
//只能找到后面的节点，然后在那之间插入新节点，最
//后将新节点的内容与pos交换(因为人家让插到pos位置)
void InesrtPosFront(PNode pos, DataType data)
{
	PNode Next = pos->_pNext;//先保存pos的下一个节点
	pos->_pNext = BuyNewNode(pos->data);//将新节点链接到pos后面，传pos的data为了避免以后再交换
	pos->_pNext->_pNext = Next;//将pos之前的下个节点连接到新节点后面
	pos->data = data;//将传过来的data覆盖原data
}

// 查找链表的中间结点，要求只能遍历一次链表 
//1.可以创建两个指针变量，一起遍历链表，一个走快点，
//一个走慢，快的是慢的的二倍，当快的走完时，慢的刚好停在中间位置
PNode FindMiddleNode(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	PNode pPre = pHead;

	//第一个条件为了保证可以走第二步，
	//第二个条件为了保证可以走出第一步
	while ((pFast) && (pFast->_pNext))//前面的条件一定要放pFast
	{
		pPre = pSlow;
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}
	if (pFast == NULL)//偶数出来时pFast为空，奇数pFast->_Next为空
		return pPre;//返回较小的中间节点

	return pSlow;//若链表长度为偶数，返回的是较大的中间节点
}

// 查找链表的倒数第K个结点，要求只能遍历一次链表
//1.与上题思路一致，可以创建两个指针，一个指针先走k步，
//再让俩个指针一起走，当快指针走到NULL时，慢指针就停在倒数第k个
PNode FindLastKNode(PNode pHead, int K)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	if (NULL == pHead || (K <= 0))
	{
		printf("K不合法!!!\n");
		return NULL;
	}
	//让pFast先走K步
	while (K--)
	{
		//K大于链表中节点的个数
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

// 删除链表的倒数第K个结点，要求只能遍历一次链表
void DeleteLastKNode(PNode *pHead, int K)
{
	assert(pHead);
	PNode pFast = *pHead;
	PNode pSlow = *pHead;
	PNode pPre = *pHead;

	if (NULL == pHead || (K <= 0))
	{
		printf("K不合法!!!\n");
		return;
	}
	//让pFast先走K步
	while (K--)
	{
		//K大于链表中节点的个数
		if (NULL == pFast)
			return;
		pFast = pFast->_pNext;
	}

	while (pFast)
	{
		pFast = pFast->_pNext;
		pPre = pSlow;//pSlow在走之前，先保存，方便以后删除
		pSlow = pSlow->_pNext;

	}

	//是第一个节点
	if (pSlow == pPre)
	{
		*pHead = pSlow->_pNext;
		free(pSlow);
		return;
	}
	//不是第一个节点
	pPre->_pNext = pSlow->_pNext;
	free(pSlow);

}

// 用单链表实现约瑟夫环 
void JosephCircle(PNode* pHead, const int M)
{
	assert(pHead);

	while ((*pHead)->_pNext != *pHead)//等于说明只剩一个节点
	{
		PNode pCur = *pHead;
		PNode pPre = *pHead;
		int count = M;

		while (--count)//注意，这里是前置--
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		pPre->_pNext = pCur->_pNext;//链接链表
		*pHead = pCur->_pNext;//改变头指针位置
		free(pCur);
	}
}

// 链表的逆置--三个指针 
//就是将原本Next域指向下一个换成指向上一个，就完成了逆置
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
		pCur->_pNext = pPre;//将Next指针域指向上一个节点
		pPre = pCur;
		pCur = pNext;
	}

	*pHead = pPre;//pPre成为新的头节点

}

// 链表的逆置--头插法 
//创建一个新头部，然后将链表中的节点从前到后使用头插法插到新头部中
PNode ReverseSListOP(PNode pHead)
{
	PNode pCur = pHead;
	PNode pNewHead = NULL;

	while (pHead)
	{
		pCur = pHead;//进来就让pCur指向头部
		pHead = pHead->_pNext;//头向后走一步
		pCur->_pNext = pNewHead;//pCur插到新头部前
		pNewHead = pCur;//新头为pCur
	}

	return pNewHead;
}


// 合并两个有序单链表，合并后依然有序 
//假设从小到大进行排序
PNode MergeSList(PNode pHead1, PNode pHead2)
{
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;
	PNode pNewHead = NULL;
	PNode pTail = NULL;//用来记录合并后链表的最后一个节点

	if (NULL == pHead1)
		return pHead2;
	if (NULL == pHead2)
		return pHead1;
	//放pNewHead
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
	//两链表中较小的节点尾插到pNewHead
	pTail = pNewHead;
	while (pCur1 && pCur2)//只要有一个链表为空就出来
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

	if (pCur1)//说明pCur2为空
		pTail->_pNext = pCur1;

	else
		pTail->_pNext = pCur2;
		
	return pNewHead;
}

// 判断两个单链表是否相交---链表不带环 
int IsSListCross(PNode pHead1, PNode pHead2)
{
	//1.如果俩链表有一个为空那么肯定不相交
	if (NULL == pHead1)
		return 0;
	if (NULL == pHead2)
		return 0;

	//2.如果两链表相交，那么它们最后一个节点肯定相同
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

// 求两个单链表相交的交点---链表不带环 
PNode GetCorssNode(PNode pHead1, PNode pHead2)
{
	PNode pCur1 = NULL;
	PNode pCur2 = NULL;
	int size1 = 0;
	int size2 = 0;
	int gap = 0;
	//1.先判断两个链表是否相交
	if (!IsSListCross(pHead1, pHead2))
		return NULL;
	pCur1 = pHead1;
	pCur2 = pHead2;

	//2.求两链表长度的差值gap
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

	//3.让较长的链表从头部先走gap步
	pCur1 = pHead1;
	pCur2 = pHead2;
	if (gap > 0)//说明链表1较长
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

	//4.两指针一起走，直到相等或为空
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

// 判断链表是否带环，返回相遇点---注意推导公式
//创建俩指针，一快一慢(注：如果俩差值刚好是环的长度，则不行)
//如果带环，则他们必定相遇
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

		if (pFast == pSlow)//如果带环，肯定相遇
			return	pSlow;
	}

	return NULL;
}

// 获取环的入口点
//假设链表带环，那么创建两个指针，一个从链表头部开始走，
//一个从相遇点开始走，那么他们的相遇点必定是环的入口
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode)
{
	PNode pCur1 = NULL;
	PNode pCur2 = NULL;

	if (NULL == pMeetNode || NULL == pMeetNode)//若不带环返回
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

// 获取环的长度
//创建一个指针从相遇点一直走，直到再次走到相遇点
int GetCircleLen(PNode pHead1, PNode pMeetNode)
{
	PNode ptr = NULL;
	int len = 0;
	pMeetNode = IsListWithCircle(pHead1);

	if (!pMeetNode)
		return 0;

	ptr = pMeetNode;
	while (ptr->_pNext != pMeetNode)//因为是下个节点，所以求出的长度少一
	{
		len++;
		ptr = ptr->_pNext;
	}

	return len + 1;
}

// 判断两个链表是否相交，链表可能带环
//分为四种情况，1.两个都不带2.两个都带3.两个有一个带(肯定不相交，不用讨论)
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2)
{
	PNode pMeetNode1 = NULL;
	PNode pMeetNode2 = NULL;

	if (NULL == pHead1)
		return 0;
	if (NULL == pHead2)
		return 0;

	//1.判断两个链表是否带环
	pMeetNode1 = IsListWithCircle(pHead1);
	pMeetNode2 = IsListWithCircle(pHead2);

	if (NULL == pMeetNode1 && NULL == pMeetNode2)//两链表都不带环
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

	else if (pMeetNode1 && pMeetNode2)//两个都带环
	{
		//1.环内相交
		//2.环外相交(都用下面的方式处理)
		//一个指针指向一个相遇点，如果指针
		//绕环一周没有和另一个相遇，那么就不相交
		PNode pCur = pMeetNode1;

		while (pCur->_pNext != pMeetNode1)
		{
			if (pCur == pMeetNode2)
				return 2;
			pCur = pCur->_pNext;
		}

		//如果第二个相遇点恰好在最后一个节点，上面处理不了
		if (pCur == pMeetNode2)
			return 2;

	}

	return 0;
}

//复杂链表复制
PCSLNode CopyComplexList(PCSLNode pHead)
{
	PCSLNode pCur = pHead;
	PCSLNode pNewNode = NULL;
	PCSLNode pNewHead = NULL;
	if (NULL == pHead)
		return NULL;

	//1.在链表后面插入值相同的新节点
	while (pCur)
	{
		pNewNode = BuyCSNewNode(pCur->data);
		pNewNode->_pNext = pCur->_pNext;
		pCur->_pNext = pNewNode;
		pCur = pNewNode->_pNext;
	}
	pCur = pHead;

	//2.给新节点的随机指针域赋值
	//让随机指针域指向原节点随机指针指向的下个节点
	while (pCur)
	{
		pNewNode = pCur->_pNext;
		if (pCur->_pRandom)
		{
			pNewNode->_pRandom = pCur->_pRandom->_pNext;
		}
		pCur = pNewNode->_pNext;
		
	}

	//3.将新节点从原链表中拆下来
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