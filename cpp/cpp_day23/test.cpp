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
//		//ʹ������ջһ���������������е��ӽڵ㣨�ӽڵ㴦��ż���У���������ң�
//		//һ��ջ��������ż���е��ӽڵ㣨���Һ���
//		stack<TreeNode*> s1;//���������е��ӽڵ㣨ż����
//		stack<TreeNode*> s2;//����ż���е��ӽڵ㣨������
//
//		vector<vector<int>> AllLine;
//		vector<int> Line;
//
//		int line = 1;//��ʶ��ż
//		s2.push(pRoot);
//
//		while (!s1.empty() || !s2.empty())
//		{
//			TreeNode* pCur = NULL;
//			if (line % 2 == 1)//������
//			{
//				//�ȱ���ջ�е�Ԫ��,��Ϊ�������У���������Ԫ����s2�������ӽڵ���ż���У�������s1
//				pCur = s2.top();
//				s2.pop();
//				Line.push_back(pCur->val);
//
//				if (pCur->left)
//					s1.push(pCur->left);
//				if (pCur->right)
//					s1.push(pCur->right);
//			}
//			else//ż����
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
//			//�ж�һ���Ƿ������
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
//		//����������ö���
//		queue<TreeNode*> q;
//		vector<int> Level;
//		vector<vector<int>> AllLevel;
//
//		//��Ϊÿ���ӡһ�У�����Ҫ��ǳ�����ǰ������һ��ĸ���������һ����ǰ�㣬��Ŀ-1�������Ϊ0����ǰ��ʹ�ӡ���ˣ���ǰ����Ŀ������һ��
//		int nextLevel = 0;//�����һ��ĸ���
//		int curLevel = 1;//�ӵ�һ�㿪ʼ����һ��ֻ�и��ڵ㣬���Ը���Ϊһ
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
//			if (curLevel == 0)//��ʾ��ǰ���������
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
//		if (((Min.size() + Max.size()) & 1) == 0)//����Ϊż��������С��
//		{
//			//���������ȴ�ѶѶ�Ԫ��С���ͷ��ڴ�ѣ����򣬷���С��
//			if (!Max.empty() && num < Max[0])
//			{
//				Max.push_back(num);
//				push_heap(Max.begin(), Max.end(), less<int>());//�������Ĭ��Ϊ��ѣ������Ԫ���ڶѶ���
//
//				//���µ���Ϊ�Ѻ󣬽���Ѷ�Ԫ�شӶѶ�Ԫ��ɾ��
//				num = Max[0];
//
//				pop_heap(Max.begin(), Max.end(), less<int>());//���Ѷ�Ԫ�ط���endλ�ã����µ�����
//				Max.pop_back();
//			}
//
//			//��numԪ�ز��뵽С����
//			Min.push_back(num);
//			push_heap(Min.begin(), Min.end(), greater<int>());
//		}
//		else//�������Ϊż�������ڴ��
//		{
//			//���num��С�ѵĶѶ�Ԫ�ش󣬾ͷ���С��
//			if (!Min.empty() && num > Min[0])
//			{
//				Min.push_back(num);
//				push_heap(Min.begin(), Min.end(), greater<int>());
//
//				//����Ϊ�Ѻ󣬽�С�ѵĶѶ�Ԫ��ɾ�������뵽�����
//				num = Min[0];
//
//				pop_heap(Min.begin(), Min.end(), greater<int>());
//				Min.pop_back();
//			}
//
//			//��num���뵽�����
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
//		if (((Min.size() + Max.size()) & 1) == 1)//�������Ϊ��������Ϊ����С�ѶѶ�
//			return (double)Min[0];
//		else
//			return ((Min[0] + Max[0]) / 2.0);
//	}
//
//	//���Ը������ѣ���ѷ�����Ϊż���������ݣ�С�ѷ����������ݣ���ѵ���������С��С��
//	//���б�֤�������еĴ�С������1
//private:
//	vector<int> Min;
//	vector<int> Max;
//};


class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		//������ʹ��O(n)�㷨�����������У�һ���������浱ǰ��Сֵ
		int numOfsize = num.size();
		if (numOfsize < size)
			return (vector<int>)0;

		vector<int> res;
		deque<int> dq;
		int index = size;
		//�����������ڴ�С�����ݲ��뵽���е���
		for (int i = 0; i < size; ++i)
			dq.push_back(num[i]);

		//�������ڿ�ʼ����
		for (int i = index; i < numOfsize; ++i)
		{
			//�ȶԻ������ڽ��������ҵ����ֵ
			//��Ϊsort�����ı䱾���ֵ��������Ҫ��ʱ����
			deque<int> tmp = dq;
			sort(tmp.begin(), tmp.end());//Ĭ������

			//�����ֵ������������
			res.push_back(tmp.back());

			//������������
			dq.pop_front();
			dq.push_back(num[i]);
		}

		//û�н����һ�εĻ����������ֵ���뵽res��
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