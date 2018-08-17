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


//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//因为二叉搜索树中序遍历可以得到有序的序列，所以采用中序遍历
		if (pRootOfTree == NULL)
			return NULL;

		TreeNode* pPre = NULL;//用来保存上一个节点

		Convert(pRootOfTree, pPre);//pCur要传引用,因为是递归

		//递归完成后，pPre指向的是链表的尾节点，所以还需找到头节点
		TreeNode* pHead = pPre;
		while (pHead != NULL && pHead->left != NULL)
			pHead = pHead->left;

		return pHead;

	}

	void Convert(TreeNode* pRoot, TreeNode*& pPre)
	{
		if (pRoot == NULL)
			return;
		//左
		if (pRoot->left)
			Convert(pRoot->left, pPre);

		//根
		//先让根的左节点指向pCur
		pRoot->left = pPre;
		//如果pPre存在，pCur的
		if (pPre)
			pPre->right = pRoot;
		//pPre保存跟节点，每一次遍历完，都能分配好上次递归的跟节点
		pPre = pRoot;

		//右
		if (pRoot->right)
			Convert(pRoot->right, pPre);
	}
};

//输入两个链表，找出它们的第一个公共结点。
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;

		//先分别算出两个链表的长度
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

//约瑟夫环问题
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0)
			return -1;

		//方法二：公式last = （last+m）%i
		int last = 0;
		for (int i = 2; i <= n; ++i)
			last = (last + m) % i;

		return last;
		//方法一：
		//list<int> Circle;
		//将节点插到链表中
		//for (int i = 0; i < n; ++i)
		//Circle.push_back(i);

		//list<int>::iterator Cur = Circle.begin();

		//while (Circle.size() > 1)
		//{
		//for (int i = 1; i < m; ++i)//注意是从1开始，自己数链表去
		//{
		//++Cur;
		//if (Cur == Circle.end())//因为list不是环形链表，所以每次走到这就让它从开始继续走
		//Cur = Circle.begin();

		//}
		//保存Cur的下个节点，删除Cur后，下次就从下一个节点开始数，
		//list中只重载了++/--,所以这里不能直接+11，
		//list<int>:: iterator next = ++Cur;
		//if (next == Circle.end())
		//next = Circle.begin();

		//--Cur;
		//Circle.erase(Cur);

		//Cur = next;//一定要重新再给Cur赋值，之前指的节点已经释放了'
		//}

		//return Circle.front();
	}
};

//链表带环，求环得入口节点
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		//1.先判断是否带环，可以采用一块一慢指针，如果相遇则代换，且相遇点一定在环中
		ListNode* pMeetNode = IsCircle(pHead);
		if (pMeetNode == NULL)
			return NULL;

		//2.计算环的长度--用相遇点计算
		int count = GetCountOfCircle(pMeetNode);

		//得到了环的长度，就相当于求两个链表的交点--先让一个指针走count步，然后两个指针一块走
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
		int count = 1;//从1开始
		ListNode* pCur = pMeetNode->next;//一定不能初始化为pMeetNode
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
			pFast = pFast->next->next;//一次走两步
			pSlow = pSlow->next;//一次走一步

			if (pFast == pSlow)
				return pFast;
		}

		return NULL;
	}
};


//删除链表中重复节点
class Solution {
public:
	ListNode* deleteDuplication(ListNode*& pHead)//有可能重复的节点为头节点，所以要传引用
	{
		if (pHead == NULL)
			return NULL;

		ListNode* pCur = pHead;
		ListNode* pPre = NULL;

		while (pCur)
		{
			//因为有可能一直重复，所以不能直接删
			bool IsDel = false;
			ListNode* pNext = pCur->next;

			if (pNext != NULL && pNext->val == pCur->val)
				IsDel = true;

			if (IsDel)
			{
				//一次删一个，所以需要把节点的值保存起来，用来下次判断
				int value = pCur->val;
				while (pCur != NULL && pCur->val == value)
				{
					pNext = pCur->next;
					delete pCur;
					pCur = pNext;
				}

				if (pPre == NULL)//头删
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