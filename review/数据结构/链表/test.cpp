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


//����һ�ö��������������ö���������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//��Ϊ��������������������Եõ���������У����Բ����������
		if (pRootOfTree == NULL)
			return NULL;

		TreeNode* pPre = NULL;//����������һ���ڵ�

		Convert(pRootOfTree, pPre);//pCurҪ������,��Ϊ�ǵݹ�

		//�ݹ���ɺ�pPreָ����������β�ڵ㣬���Ի����ҵ�ͷ�ڵ�
		TreeNode* pHead = pPre;
		while (pHead != NULL && pHead->left != NULL)
			pHead = pHead->left;

		return pHead;

	}

	void Convert(TreeNode* pRoot, TreeNode*& pPre)
	{
		if (pRoot == NULL)
			return;
		//��
		if (pRoot->left)
			Convert(pRoot->left, pPre);

		//��
		//���ø�����ڵ�ָ��pCur
		pRoot->left = pPre;
		//���pPre���ڣ�pCur��
		if (pPre)
			pPre->right = pRoot;
		//pPre������ڵ㣬ÿһ�α����꣬���ܷ�����ϴεݹ�ĸ��ڵ�
		pPre = pRoot;

		//��
		if (pRoot->right)
			Convert(pRoot->right, pPre);
	}
};

//�������������ҳ����ǵĵ�һ��������㡣
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;

		//�ȷֱ������������ĳ���
		ListNode* pCur1 = pHead1;
		int count1 = 0;
		while (pCur1)
		{
			++count1;
			pCur1 = pCur1->next;
		}

		ListNode* pCur2 = pHead2;
		int count2 = 0;
		while (pCur2)
		{
			++count2;
			pCur2 = pCur2->next;
		}

		int gap = 0;
		int flag = 0;
		if (count1 > count2)
		{
			gap = count1 - count2;
			flag = 1;
		}
		else
			gap = count2 - count1;

		pCur1 = pHead1;
		pCur2 = pHead2;
		if (flag == 1)
		{
			while (gap--)
				pCur1 = pCur1->next;
		}
		else
		{
			while (gap--)
				pCur2 = pCur2->next;
		}

		while (pCur1 && pCur2)
		{
			if (pCur1 == pCur2)
				break;
			pCur1 = pCur1->next;
			pCur2 = pCur2->next;
		}

		if (pCur1 == NULL || pCur2 == NULL)
			return NULL;
		return pCur1;
	}
};

//Լɪ������
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0)
			return -1;

		//����������ʽlast = ��last+m��%i
		int last = 0;
		for (int i = 2; i <= n; ++i)
			last = (last + m) % i;

		return last;
		//����һ��
		//list<int> Circle;
		//���ڵ�嵽������
		//for (int i = 0; i < n; ++i)
		//Circle.push_back(i);

		//list<int>::iterator Cur = Circle.begin();

		//while (Circle.size() > 1)
		//{
		//for (int i = 1; i < m; ++i)//ע���Ǵ�1��ʼ���Լ�������ȥ
		//{
		//++Cur;
		//if (Cur == Circle.end())//��Ϊlist���ǻ�����������ÿ���ߵ���������ӿ�ʼ������
		//Cur = Circle.begin();

		//}
		//����Cur���¸��ڵ㣬ɾ��Cur���´ξʹ���һ���ڵ㿪ʼ����
		//list��ֻ������++/--,�������ﲻ��ֱ��+11��
		//list<int>:: iterator next = ++Cur;
		//if (next == Circle.end())
		//next = Circle.begin();

		//--Cur;
		//Circle.erase(Cur);

		//Cur = next;//һ��Ҫ�����ٸ�Cur��ֵ��֮ǰָ�Ľڵ��Ѿ��ͷ���'
		//}

		//return Circle.front();
	}
};

//����������󻷵���ڽڵ�
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		//1.���ж��Ƿ���������Բ���һ��һ��ָ�룬����������������������һ���ڻ���
		ListNode* pMeetNode = IsCircle(pHead);
		if (pMeetNode == NULL)
			return NULL;

		//2.���㻷�ĳ���--�����������
		int count = GetCountOfCircle(pMeetNode);

		//�õ��˻��ĳ��ȣ����൱������������Ľ���--����һ��ָ����count����Ȼ������ָ��һ����
		ListNode* pFront = pHead;
		ListNode* pBack = pHead;

		while (count--)
			pFront = pFront->next;

		while (pBack != pFront)
		{
			pFront = pFront->next;
			pBack = pBack->next;
		}

		return pBack;
	}

	int GetCountOfCircle(ListNode*& pMeetNode)
	{
		int count = 1;//��1��ʼ
		ListNode* pCur = pMeetNode->next;//һ�����ܳ�ʼ��ΪpMeetNode
		while (pCur != pMeetNode)
		{
			++count;
			pCur = pCur->next;
		}
		return count;
	}
	ListNode* IsCircle(ListNode*& pHead)
	{
		ListNode* pFast = pHead;
		ListNode* pSlow = pHead;

		while (pSlow != NULL && pFast != NULL && pFast->next != NULL)
		{
			pFast = pFast->next->next;//һ��������
			pSlow = pSlow->next;//һ����һ��

			if (pFast == pSlow)
				return pFast;
		}

		return NULL;
	}
};


//ɾ���������ظ��ڵ�
class Solution {
public:
	ListNode* deleteDuplication(ListNode*& pHead)//�п����ظ��Ľڵ�Ϊͷ�ڵ㣬����Ҫ������
	{
		if (pHead == NULL)
			return NULL;

		ListNode* pCur = pHead;
		ListNode* pPre = NULL;

		while (pCur)
		{
			//��Ϊ�п���һֱ�ظ������Բ���ֱ��ɾ
			bool IsDel = false;
			ListNode* pNext = pCur->next;

			if (pNext != NULL && pNext->val == pCur->val)
				IsDel = true;

			if (IsDel)
			{
				//һ��ɾһ����������Ҫ�ѽڵ��ֵ���������������´��ж�
				int value = pCur->val;
				while (pCur != NULL && pCur->val == value)
				{
					pNext = pCur->next;
					delete pCur;
					pCur = pNext;
				}

				if (pPre == NULL)//ͷɾ
					pHead = pNext;
				else
					pPre->next = pNext;
			}
			else
			{
				pPre = pCur;
				pCur = pNext;
			}
		}
		return pHead;
	}
};