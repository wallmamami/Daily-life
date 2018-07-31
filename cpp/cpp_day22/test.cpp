#include <iostream>
#include <vector>
using namespace std;

//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) :
//val(x), next(NULL) {
//}
//};
//
//class Solution {
//public:
//	ListNode* EntryNodeOfLoop(ListNode* pHead)
//	{
//		//1.先判断是否带环，可以采用一块一慢指针，如果相遇则代换，且相遇点一定在环中
//		ListNode* pMeetNode = IsCircle(pHead);
//		if (pMeetNode == NULL)
//			return NULL;
//
//		//2.计算环的长度--用相遇点计算
//		int count = GetCountOfCircle(pMeetNode);
//
//		//得到了环的长度，就相当于求两个链表的交点--先让一个指针走count步，然后两个指针一块走
//		ListNode* pFront = pHead;
//		ListNode* pBack = pHead;
//
//		while (count--)
//			pFront = pFront->next;
//
//		while (pBack != pFront)
//		{
//			pFront = pFront->next;
//			pBack = pBack->next;
//		}
//
//		return pBack;
//	}
//
//	int GetCountOfCircle(ListNode*& pMeetNode)
//	{
//		int count = 1;//从1开始
//		ListNode* pCur = pMeetNode->next;//一定不能初始化为pMeetNode
//		while (pCur != pMeetNode)
//		{
//			++count;
//			pCur = pCur->next;
//		}
//		return count;
//	}
//	ListNode* IsCircle(ListNode*& pHead)
//	{
//		ListNode* pFast = pHead;
//		ListNode* pSlow = pHead;
//
//		while (pSlow != NULL && pFast != NULL && pFast->next != NULL)
//		{
//			pFast = pFast->next->next;//一次走两步
//			pSlow = pSlow->next;//一次走一步
//
//			if (pFast == pSlow)
//				return pFast;
//		}
//
//		return NULL;
//	}
//};
//
//void SetCircle(ListNode*& pHead)
//{
//	//1,2 3, 4 ,5
//	int count = 2;
//	ListNode* pCur = NULL;
//	ListNode* pTail = NULL;
//	ListNode* p2 = NULL;
//
//	pHead = new ListNode(1);
//	pTail = pHead;
//
//	while (count <= 5)
//	{
//		
//		pCur = new ListNode(count);
//		if (count == 2)
//			p2 = pCur;
//		pTail->next = pCur;
//		pTail = pCur;
//		++count;
//	}
//
//	pTail->next = p2;
//}
//
//int main()
//{
//	ListNode* pHead;
//	SetCircle(pHead);
//	Solution s;
//	cout << s.EntryNodeOfLoop(pHead)->val << endl;
//
//	return 0;
//}



struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;

		TreeLinkNode* pNext = NULL;
		//从跟节点开始考虑
		//1.当前节点有右子树，则下一个节点为右子树的最左边的节点
		if (pNode->right)
		{
			TreeLinkNode* pLeft = pNode->right;
			while (pLeft->left)
				pLeft = pLeft->left;
			pNext = pLeft;
		}

		//2.当前节点没有右子树，但是他是它父节点的左子节点
		else if (pNode->next != NULL && pNode->next->left == pNode)
			pNext = pNode->next;

		//3.当前节点既没有右子树，也不是它父节点的左子节点
		//找到这样的节点，它是它父节点的左子节点，找到后，这个节点的父节点就是下一个节点
		else
		{
			TreeLinkNode* pCur = pNode;
			TreeLinkNode* pParent = NULL;
			while (pCur)
			{
				pParent = pCur->next;
				if (pParent != NULL && pCur == pParent->left)//这里必须先保证pParent不为空
					break;
				pCur = pCur->next;
			}

			if (pCur == NULL)
				pNext = NULL;
			else
				pNext = pParent;
		}

		return pNext;
	}
};

void SetTree(TreeLinkNode*& pRoot)
{
	pRoot = new TreeLinkNode(1);
	pRoot->left = new TreeLinkNode(2);
	pRoot->left->next = pRoot;
	pRoot->right = new TreeLinkNode(3);
	pRoot->right->next = pRoot;
	pRoot->left->left = new TreeLinkNode(4);
	pRoot->left->left->next = pRoot->left;
	pRoot->left->right = new TreeLinkNode(5);
	pRoot->left->right->next = pRoot->left;
	pRoot->right->left = new TreeLinkNode(6);
	pRoot->right->left->next = pRoot->right;
	pRoot->right->right = new TreeLinkNode(7);

	pRoot->right->right->next = pRoot->right;
	
}
int main()
{
	Solution s;
	TreeLinkNode* pRoot = NULL;

	SetTree(pRoot);

	if (s.GetNext(pRoot->right->right) == NULL)
		cout << "caoniama" << endl;
	return 0;
}

//class Solution
//{
//public:
//	//构造函数初始化
//	Solution()
//		: hash(256, 0)
//	{}
//	//Insert one char from stringstream
//	void Insert(char ch)
//	{
//		++hash[ch];
//		arr.push_back(ch);
//	}
//	//return the first appearence once char in current stringstream
//	char FirstAppearingOnce()
//	{
//		for (int i = 0; i < arr.size(); ++i)
//		{
//			if (hash[arr[i]] == 1)
//				return arr[i];
//		}
//
//		return '#';
//	}
//
//private:
//	vector<int> hash;
//	vector<int> arr;
//};
//
//int main()
//{
//	Solution s;
//	s.Insert('a');
//	s.Insert('b');
//	s.Insert('a');
//	s.Insert('a');
//	s.Insert('c');
//	s.Insert('c');
//	s.Insert('b');
//
//	cout << s.FirstAppearingOnce() << endl;
//	return 0;
//}