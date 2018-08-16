#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};


//从尾到头打印链表
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		if (head == NULL)
			return (vector<int>)0;
		vector<int> v;
		stack<int> s;
		ListNode* pCur = head;

		while (pCur)
		{
			s.push(pCur->val);
			pCur = pCur->next;
		}

		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			v.push_back(s.top());
			s.pop();
		}

		return v;
	}
};

//给定单链表的头指针和一个节点指针，定义一个函数再O(1)时间删除该节点。
void DelNode(ListNode* pHead, ListNode* pDel)
{
	if (pHead == NULL || pDel == NULL)
		return;

	//情况一：pDel不是尾节点
	if (pDel->next != NULL)
	{
		ListNode* pPre = pDel;
		pDel = pPre->next;
		pPre->val = pDel->val;
		pPre->next = pDel->next;

		delete pDel;
	}

	//情况二：只有一个节点，即pDel为尾节点
	else if (pHead == pDel && pHead->next == NULL)
		delete pDel;

	//情况三：有多个节点，pDel为尾节点
	else
	{
		//因为pDel为尾节点，所以不能采用交换值得办法删除，只能
		//遍历链表找到它前一个节点，但是平均时间复杂度还是尾O(1)
		ListNode* pCur = pHead;
		while (pCur->next != pDel)
		{
			pCur = pCur->next;
		}

		pCur->next = pDel->next;
		delete pDel;
		pDel = NULL;
	}

}

//输入一个链表，输出该链表中倒数第k个结点。(从1开始)
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* pFast = pListHead;

		if (pListHead == NULL || k <= 0)
			return NULL;
		while (--k)
		{
			pFast = pFast->next;
			if (pFast == NULL)
				return NULL;
		}

		ListNode* pCur = pListHead;
		while (pFast->next)
		{
			pFast = pFast->next;
			pCur = pCur->next;
		}

		return pCur;
	}
};

//输入一个链表，反转链表后，输出新链表的表头。
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {

		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* pPre = NULL;
		ListNode* pCur = pHead;
		ListNode* pNext = NULL;

		while (pCur)
		{
			pNext = pCur->next;
			pCur->next = pPre;
			pPre = pCur;
			pCur = pNext;
		}

		return pPre;
	}
};

//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL && pHead2 == NULL)
			return NULL;
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;

		ListNode* pNewHead = NULL;
		if (pHead1->val < pHead2->val)
		{
			pNewHead = pHead1;
			pNewHead->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			pNewHead = pHead2;
			pNewHead->next = Merge(pHead1, pHead2->next);
		}

		return pNewHead;
	}

};


//复杂链表得复制
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		RandomListNode* pNewNode = NULL;
		RandomListNode* pCur = pHead;

		if (pHead == NULL)
			return NULL;
		//第一步，先在每一个节点后面插入相同的节点
		while (pCur)
		{
			pNewNode = new RandomListNode(pCur->label);
			pNewNode->next = pCur->next;
			pCur->next = pNewNode;

			//pCur朝后走一步，插入下一个节点
			pCur = pNewNode->next;
		}

		//第二部，给复制的节点的random指针赋值，让其指向原节点的random指针指向节点的下一个节点
		pCur = pHead;
		while (pCur)
		{
			pNewNode = pCur->next;
			if (pCur->random)
				pNewNode->random = pCur->random->next;

			pCur = pNewNode->next;
		}

		//第三部，将复制的节点从链表中拆分出来
		pCur = pHead;
		RandomListNode* pNewHead = pHead->next;

		while (pCur->next)
		{
			pNewNode = pCur->next;
			pCur->next = pNewNode->next;
			pCur = pNewNode;
		}

		return pNewHead;
	}
};