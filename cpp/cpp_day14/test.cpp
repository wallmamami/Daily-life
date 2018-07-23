//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//
//
//void ShellSort(vector<int>& v)
//{
//	int size = v.size();
//	int gap = size;
//
//	while (gap > 1)
//	{
//		int i = 0;
//		gap = gap / 3 - 1;
//
//		for (i = gap; i < size; ++i)
//		{
//			int key = v[i];
//			int end = i - gap;
//
//			while (end >= 0 && key < v[end])
//			{
//				v[end + gap] = v[end];
//				end -= gap;
//			}
//
//			v[end + gap] = key;
//		}
//	}
//}
//
//int main()
//{
//	vector<int> v = { 2, 1, 8, 3, 6, 5, 4 };
//	int i = 0;
//	ShellSort(v);
//
//	for (; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	return 0;
//
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//int main()
//{
//	vector<vector<int>> arr = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
//
//	cout << arr[0].size() << endl;
//
//
//	return 0;
//}

//#include <string>
//#include <iostream>
//using namespace std;
//
//
//class Solution {
//public:
//	void replaceSpace(char *str, int length) {
//		int count = 0;
//		int i = 0;
//		int index = 0;
//
//		for (; i < length; ++i)
//		{
//			if (str[i] == ' ')
//				count++;
//		}
//
//		count *= 2;
//		index = length + count;
//
//		for (i = length; i >= 0; --i)
//		{
//			if (str[i] == ' ')
//			{
//				str[index] = '0';
//				index--;
//				str[index] = '2';
//				index--;
//				str[index] = '%';
//			}
//			else
//				str[index] = str[i];
//			index--;
//		}
//
//	}
//};
//
//int main()
//{
//	string s = "abcrf";
//
//	s[5] = '2';
//	cout << s[5] << endl;
//
//	return 0;
//
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//ListNode* BuyNode(int data)
//{
//	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
//	if (NewNode)
//	{
//		NewNode->next = NULL;
//		NewNode->val = data;
//	}
//
//	return NewNode;
//}
//void push_back(ListNode** head, int data)
//{
//	if (head == NULL)
//		return;
//	ListNode* pHead = *head;
//	ListNode* pPre = NULL;
//	ListNode* pNewNode = BuyNode(data);
//
//	if (pHead == NULL)
//	{
//		*head = pNewNode;
//		return;
//	}
//
//	while (pHead)
//	{
//		pPre = pHead;
//		pHead = pHead->next;
//	}
//	pPre->next = pNewNode;
//}
//
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//
//		vector<int> v;
//		struct ListNode* Pre = NULL;
//		struct ListNode* Cur = head;
//		struct ListNode* Next = NULL;
//
//		while (Cur)
//		{
//			Next = Cur->next;
//			Cur->next = Pre;
//			Pre = Cur;
//			Cur = Next;
//		}
//
//		head = Pre;//Pre为新的头节点
//		while (head)
//		{
//			v.push_back(head->val);
//			head = head->next;
//		}
//		int i = 0;
//		for (; i < v.size(); i++)
//			cout << v[i] << " ";
//		cout << endl;
//
//		return v;
//	}
//};
//int main()
//{
//	Solution s;
//	ListNode* head = NULL;
//	push_back(&head, 67);
//	push_back(&head, 0);
//	push_back(&head, 24);
//	push_back(&head, 58);
//
//	vector<int> v = s.printListFromTailToHead(head);
//	int i = 0;
//	for (; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//	int* pb = *ppa;
//
//	*pa = 20;
//	*pb = 30;
//	cout << a << endl;
//
//	return 0;
//}

#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#include <iostream>

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() <= 0 || vin.size() <= 0)
			return NULL;//序列有错误
		return CreateBinTree(0, pre.size() - 1, 0, vin.size() - 1, pre, vin);
	}

	TreeNode* CreateBinTree(int startPre, int endPre, int startIn, int endIn, vector<int>& pre, vector<int>& vin)
	{
		//拿到根节点的值
		int rootVal = pre[startPre];//肯定是前序遍历的第一个

		//构建跟节点
		TreeNode* root = new TreeNode(rootVal);

		//判断是不是最后一个节点
		if (startPre == endPre)
		{
			if (startIn == endIn && pre[startPre] == vin[startIn])
			{
				return root;
			}
			else
				return NULL;//序列有错误
		}

		//在中序遍历序列中找跟节点
		int i = 0;
		for (i = startIn; i <= endIn; i++)
		{
			if (rootVal == vin[i])//找到，前面为左， 后面为右
				break;
		}
		if (vin[i] != rootVal)
			return NULL;//序列有错误
		//构建左子树
		int leftLen = i - startIn;
		if (leftLen > 0)
		{
			root->left = CreateBinTree(startPre + 1, startPre + leftLen, startIn, startIn + leftLen - 1, pre, vin);
		}
		if (leftLen < endIn - startIn)//总长度比左子树长说明右右子树
		{
			root->right = CreateBinTree(startPre + leftLen +1 , endPre, startIn + leftLen + 1, endIn, pre, vin);
		}
		return root;
	}
	
};


int main()
{
	vector<int> pre = { 1, 2, 4, 3, 5, 6 }; 
	vector<int> vin = { 4, 2, 1, 5, 3, 6 };

	Solution s;
	TreeNode* root = s.reConstructBinaryTree(pre, vin);


	return 0;

}
//
//
//
//[3, 2, 4, 1, 6, 5, 7]
//
//
//[3, 2, 4, 1, 6, 5, 7]



//
//
//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//		if (pre.size() != vin.size())
//			return NULL;
//		if (pre.size() == 0)
//			return NULL;
//
//		int pos = 0;
//		for (; pos < vin.size(); ++pos)
//		{
//			if (vin[pos] == pre[0])
//				break;
//		}
//
//		vector<int> _leftin;
//		vector<int> _rightin;
//		vector<int> _leftpre;
//		vector<int> _rightpre;
//		for (size_t i = 0; i < vin.size(); ++i)
//		{
//			if (i < pos)
//				_leftin.push_back(vin[i]);
//			else if (i == pos)
//				continue;
//			else
//				_rightin.push_back(vin[i]);
//		}
//		for (size_t i = 1; i<pre.size(); ++i)
//		{
//			if (i <= _leftin.size())
//				_leftpre.push_back(pre[i]);
//			else
//				_rightpre.push_back(pre[i]);
//		}
//
//
//		TreeNode* root = new TreeNode(pre[0]);
//		root->left = reConstructBinaryTree(_leftpre, _leftin);
//		root->right = reConstructBinaryTree(_rightpre, _rightin);
//
//		return root;
//	}
//};
//
