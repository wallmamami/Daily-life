#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;



//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//
//class Solution {
//public:
//	vector<vector<int> > Print(TreeNode* pRoot) {
//
//		if (pRoot == NULL)
//			return (vector<vector<int>>)0;
//
//		//使用两个栈一个用来保存奇数行的子节点（子节点处于偶数行）（先左后右）
//		//一个栈用来保存偶数行的子节点（先右后左）
//		stack<TreeNode*> s1;//保存奇数行的子节点（偶数）
//		stack<TreeNode*> s2;//保存偶数行的子节点（奇数）
//
//		vector<vector<int>> AllLine;
//		vector<int> Line;
//
//		int line = 1;//标识奇偶
//		s2.push(pRoot);
//
//		while (!s1.empty() || !s2.empty())
//		{
//			TreeNode* pCur = NULL;
//			if (line % 2 == 1)//奇数行
//			{
//				//先遍历栈中的元素,因为是奇数行，所以它的元素在s2，它的子节点是偶数行，保存在s1
//				pCur = s2.top();
//				s2.pop();
//				Line.push_back(pCur->val);
//
//				if (pCur->left)
//					s1.push(pCur->left);
//				if (pCur->right)
//					s1.push(pCur->right);
//			}
//			else//偶数行
//			{
//				pCur = s1.top();
//				s1.pop();
//
//				Line.push_back(pCur->val);
//
//				if (pCur->right)
//					s2.push(pCur->right);
//				if (pCur->left)
//					s2.push(pCur->left);
//			}
//
//			//判断一行是否遍历完
//			if (line % 2 == 1 && s2.empty())
//			{
//				++line;
//				AllLine.push_back(Line);
//				Line.clear();
//			}
//
//			else if (line % 2 == 0 && s1.empty())
//			{
//				++line;
//				AllLine.push_back(Line);
//				Line.clear();
//			}
//
//		}
//		return AllLine;
//	}
//
//};



//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//
//class Solution {
//public:
//	vector<vector<int> > Print(TreeNode* pRoot) {
//
//		if (pRoot == NULL)
//			return (vector<vector<int>>)0;
//		//层序遍历，用队列
//		queue<TreeNode*> q;
//		vector<int> Level;
//		vector<vector<int>> AllLevel;
//
//		//因为每层打印一行，就需要标记出，当前层与下一层的个数，遍历一个当前层，数目-1，如果减为0，当前层就打印完了，当前层数目等于下一层
//		int nextLevel = 0;//标记下一层的个数
//		int curLevel = 1;//从第一层开始，第一层只有跟节点，所以个数为一
//		q.push(pRoot);
//
//		while (!q.empty())
//		{
//			TreeNode* pCur = q.front();
//			q.pop();
//			--curLevel;
//
//			Level.push_back(pCur->val);
//
//			if (pCur->left)
//			{
//				++nextLevel;
//				q.push(pCur->left);
//			}
//
//			if (pCur->right)
//			{
//				++nextLevel;
//				q.push(pCur->right);
//			}
//
//			if (curLevel == 0)//表示当前层遍历完了
//			{
//				curLevel = nextLevel;
//				nextLevel = 0;
//				AllLevel.push_back(Level);
//				Level.clear();
//			}
//		}
//
//		return AllLevel;
//
//	}
//
//};
//
//void SetTree(TreeNode*& pRoot)
//{
//	pRoot = new TreeNode(1);
//	pRoot->left = new TreeNode(2);
//	pRoot->right = new TreeNode(3);
//	pRoot->left->left = new TreeNode(4);
//	pRoot->left->right = new TreeNode(5);
//	pRoot->right->left = new TreeNode(6);
//	pRoot->right->right = new TreeNode(7);
//}
//int main()
//{
//	TreeNode* pRoot = NULL;
//	SetTree(pRoot);
//
//	Solution s;
//	vector<vector<int>> arr;
//
//	arr = s.Print(pRoot);
//	
//	for (int i = 0; i < arr.size(); ++i)
//	{
//		for (int j = 0; j < arr[i].size(); ++j)
//			cout << arr[i][j] << " ";
//		cout << endl;
//	}
//
//	return 0;
//}


//class Solution {
//public:
//	void Insert(int num)
//	{
//		if (((Min.size() + Max.size()) & 1) == 0)//总数为偶数，放在小堆
//		{
//			//如果这个数比大堆堆顶元素小，就放在大堆，否则，放在小堆
//			if (!Max.empty() && num < Max[0])
//			{
//				Max.push_back(num);
//				push_heap(Max.begin(), Max.end(), less<int>());//如果不传默认为大堆（即最大元素在堆顶）
//
//				//重新调整为堆后，将大堆顶元素从堆顶元素删除
//				num = Max[0];
//
//				pop_heap(Max.begin(), Max.end(), less<int>());//将堆顶元素放在end位置，重新调整堆
//				Max.pop_back();
//			}
//
//			//将num元素插入到小堆中
//			Min.push_back(num);
//			push_heap(Min.begin(), Min.end(), greater<int>());
//		}
//		else//如果总数为偶数，放在大堆
//		{
//			//如果num比小堆的堆顶元素大，就放在小堆
//			if (!Min.empty() && num > Min[0])
//			{
//				Min.push_back(num);
//				push_heap(Min.begin(), Min.end(), greater<int>());
//
//				//调整为堆后，将小堆的堆顶元素删除，插入到大堆中
//				num = Min[0];
//
//				pop_heap(Min.begin(), Min.end(), greater<int>());
//				Min.pop_back();
//			}
//
//			//将num插入到大堆中
//			Max.push_back(num);
//			push_heap(Max.begin(), Max.end(), less<int>());
//		}
//	}
//
//	double GetMedian()
//	{
//		if (Min.size() + Max.size() <= 0)
//			return (double)0;
//
//		if (((Min.size() + Max.size()) & 1) == 1)//如果总数为奇数，因为就是小堆堆顶
//			return (double)Min[0];
//		else
//			return ((Min[0] + Max[0]) / 2.0);
//	}
//
//	//可以给两个堆，大堆放总数为偶数的新数据，小堆放奇数的数据，大堆的所有数都小于小堆
//	//还有保证两个堆中的大小相差不超过1
//private:
//	vector<int> Min;
//	vector<int> Max;
//};


class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		//还可以使用O(n)算法，用两个队列，一个用来保存当前最小值
		int numOfsize = num.size();
		if (numOfsize < size)
			return (vector<int>)0;

		vector<int> res;
		deque<int> dq;
		int index = size;
		//将将滑动窗口大小的数据插入到队列当中
		for (int i = 0; i < size; ++i)
			dq.push_back(num[i]);

		//滑动窗口开始滑动
		for (int i = index; i < numOfsize; ++i)
		{
			//先对滑动窗口进行排序，找到最大值
			//因为sort排序会改变本身的值，所以需要临时变量
			deque<int> tmp = dq;
			sort(tmp.begin(), tmp.end());//默认升序

			//将最大值保存在数组中
			res.push_back(tmp.back());

			//滑动滑动窗口
			dq.pop_front();
			dq.push_back(num[i]);
		}

		//没有将最后一次的滑动窗口最大值插入到res中
		sort(dq.begin(), dq.end());
		res.push_back(dq.back());
		return res;
	}
};

int main()
{

	Solution s;
	vector<int> arr;
	vector<int> num = { 2, 3, 4, 2, 6, 2, 5, 1 };
	arr = s.maxInWindows(num, 3);


	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
//int main()
//{
//	string s;
//
//	s.push_back(1);
//	s.push_back(2);
//	s.push_back(3);
//	s.push_back(4);
//	s.push_back(5);
//
//
//	int* buf = new int[20];
//
//	cout << str << endl;
//
//	return 0;
//}