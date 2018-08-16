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


//��β��ͷ��ӡ����
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

//�����������ͷָ���һ���ڵ�ָ�룬����һ��������O(1)ʱ��ɾ���ýڵ㡣
void DelNode(ListNode* pHead, ListNode* pDel)
{
	if (pHead == NULL || pDel == NULL)
		return;

	//���һ��pDel����β�ڵ�
	if (pDel->next != NULL)
	{
		ListNode* pPre = pDel;
		pDel = pPre->next;
		pPre->val = pDel->val;
		pPre->next = pDel->next;

		delete pDel;
	}

	//�������ֻ��һ���ڵ㣬��pDelΪβ�ڵ�
	else if (pHead == pDel && pHead->next == NULL)
		delete pDel;

	//��������ж���ڵ㣬pDelΪβ�ڵ�
	else
	{
		//��ΪpDelΪβ�ڵ㣬���Բ��ܲ��ý���ֵ�ð취ɾ����ֻ��
		//���������ҵ���ǰһ���ڵ㣬����ƽ��ʱ�临�ӶȻ���βO(1)
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

//����һ����������������е�����k����㡣(��1��ʼ)
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

//����һ��������ת��������������ı�ͷ��
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

//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
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


//��������ø���
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
		//��һ��������ÿһ���ڵ���������ͬ�Ľڵ�
		while (pCur)
		{
			pNewNode = new RandomListNode(pCur->label);
			pNewNode->next = pCur->next;
			pCur->next = pNewNode;

			//pCur������һ����������һ���ڵ�
			pCur = pNewNode->next;
		}

		//�ڶ����������ƵĽڵ��randomָ�븳ֵ������ָ��ԭ�ڵ��randomָ��ָ��ڵ����һ���ڵ�
		pCur = pHead;
		while (pCur)
		{
			pNewNode = pCur->next;
			if (pCur->random)
				pNewNode->random = pCur->random->next;

			pCur = pNewNode->next;
		}

		//�������������ƵĽڵ�������в�ֳ���
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