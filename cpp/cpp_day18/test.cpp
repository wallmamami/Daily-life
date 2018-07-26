//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//void MergeData(vector<int>& arr, int left, int mid, int right, vector<int>& tmpV)
//{
//	int beginL = left, endL = mid;
//	int beginR = mid, endR = right;
//	int index = left;
//
//	while (beginL < endL && beginR < endR)
//	{
//		if (arr[beginL] < arr[beginR])
//			tmpV[index++] = arr[beginL++];
//		else
//			tmpV[index++] = arr[beginR++];
//	}
//
//	while (beginL < endL)
//		tmpV[index++] = arr[beginL++];
//
//	while (beginR < endR)
//		tmpV[index++] = arr[beginR++];
//
//	for (int i = left; i < right; ++i)
//		arr[i] = tmpV[i];
//}
//
//void _MergeSort(vector<int>& arr, int left, int right, vector<int>& tmpV)
//{
//	if (left + 1 < right)
//	{
//		int mid = left + (right - left) / 2;
//		_MergeSort(arr, left, mid, tmpV);
//		_MergeSort(arr, mid, right, tmpV);
//		MergeData(arr, left, mid, right, tmpV);
//	}
//}
//
//void MergeSort(vector<int>& arr)
//{
//	int size = arr.size();
//	vector<int> tmpV(size, 0);
//
//	_MergeSort(arr, 0, size, tmpV);
//
//}
//
//
//int main()
//{
//	vector<int> arr = { 4, 5, 2, 7, 1, 8, 0 };
//	MergeSort(arr);
//
//	return 0;
//}


//void PreOrder(BTNode* pRoot)
//{
//	if (pRoot == NULL)
//		return;
//
//	cout << pRoot->data << " ";
//
//	if (pRoot->left)
//		Inorder(pRoot->left);
//	if (pRoot->right)
//		Inorder(pRoot->right);
//
//}
//
//void PreOrderNor(BTNode* pRoot)
//{
//	if (pRoot == NULL)
//		return;
//
//	stack<BTNode*> s;
//	s.push(pRoot);
//
//	while (!s.empty())
//	{
//		BTNode* pCur = s.top();
//		cout << pCur->data;
//		s.pop();
//
//		if (pCur->right)
//			s.push(pCur->right);
//		if (pCur->left)
//			s.push(pCur->left);
//	}
//}
//
////中序
//void InOrder(BTNode* pRoot)
//{
//	if (pRoot == NULL)
//		return 0;
//
//	if (pRoot->left)
//		InOrder(pRoot->left);
//
//	cout << pRoot->data;
//
//	if (pRoot->right)
//		InOrder(pRoot->right);
//}
//
//
//void InOrderNor(BTNode* pRoot)
//{
//	if (pRoot == NULL)
//		return 0;
//
//	stack<BTNode*> s;
//	BTNode* pCur = pRoot;
//
//	while (pCur || !s.empty())
//	{
//		while (pCur)
//		{
//			s.push(pCur);
//			pCur = pCur->left;
//		}
//
//		pCur = s.top();
//		cout << pCur->data;
//		s.pop();
//		pCur = pCur->right;
//	}
//}
//
//
//void PostOrder(BTNode* pRoot)
//{
//	if (pRoot == NULL)
//		return 0;
//
//	if (pRoot->left)
//		PreOrder(pRoot->left);
//
//	if (pRoot->right)
//		PreOrder(pRoot->right);
//
//	cout << pRoot->data;
//}
//
//
//void PostOrderNor(BTNode* pRoot)
//{
//	if (pRoot == NULL)
//		return;
//
//	stack<BTNode*> s;
//	BTNode* pCur = pRoot;
//	BTNode* pPre = NULL;
//	BTNode* pTop = NULL;
//
//	while (pCur || !s.empty())
//	{
//		while (pCur)
//		{
//			s.push(pCur);
//			pCur = pCur->left;
//		}
//
//		pTop = s.top();
//
//		if (!pTop->right || pPre == pTop->right)
//		{
//			cout << pTop->data;
//			s.pop();
//			pPre = pTop;
//		}
//		else
//			pCur = pTop->right;
//	}
//
//}
//
//void LevelOrder(BTNode* pRoot)
//{
//	if (pRoot = NULL)
//		return;
//
//	queue<BTNode*> q;
//	q.push(pRoot);
//
//	while (!q.empty())
//	{
//		BTNode* pCur = q.top();
//		cout << pCur->data;
//
//		q.pop();
//
//		if ()
//		q.push(pCur->left);
//
//	}
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//void CountSort(vector<int>& arr)
//{
//	int MinData = 0;
//	int MaxData = 0;
//	int size = arr.size();
//
//
//	for (int i = 0; i < size; ++i)
//	{
//		if (arr[i] < MinData)
//			MinData = arr[i];
//		if (arr[i] > MaxData)
//			MaxData = arr[i];
//	}
//
//	int range = MaxData - MinData + 1;
//	vector<int> count(range, 0);
//
//	for (int i = 0; i < size; ++i)
//	{
//		count[arr[i] - MinData]++;
//	}
//
//	int index = 0;
//	for (int i = 0; i < range; ++i)
//	{
//		while (count[i]--)
//			arr[index++] = i + MinData;
//	}
//}
//
//int main()
//{
//	vector<int> arr = { 1, 2, 3, 5, 3, 4, 1 };
//
//	CountSort(arr);
//	for (int i = 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}


//class Solution {
//public:
//	bool VerifySquenceOfBST(vector<int> sequence) {
//		//45327896
//		int size = sequence.size();
//		if (size == 0)
//			return false;
//
//		bool result = VSOfBST(sequence, size);
//		return result;
//	}
//
//	bool VSOfBST(vector<int>& arr, int size)
//	{
//		if (size <= 0)
//			return false;
//
//		//后序遍历根结点一定时最后一个
//		int root = arr[size - 1];
//
//		//在前面去找他的左子树和右子树
//		int i = 0;
//		for (i = 0; i < size - 1; ++i)
//		{
//			if (arr[i] > root)
//				break;
//		}
//
//		int j = i;//再从i的位置去找右子树,右子树如果里面有比跟节点小的，那么这个序列一定是错了
//		for (j = i; j < size - 1; ++j)
//		{
//			if (arr[j] < root)
//				return false;
//		}
//
//		//如果i>0，说明一定有左子树，且i的值位左子树的长度，再去看他左子树的序列对不对
//		bool left = true;//如果没有左子树或右子树，序列也是正确的
//		if (i > 0)
//			left = VSOfBST(arr, i);
//		//如果i<size-1说明右子树一定存在，长度为size-i-1，不包含跟节点
//		bool right = true;
//		if (i < size - 1)
//			right = VSOfBST(arr, size - i - 1);
//
//		return (left && right);
//	}
//
//};


//#include <vector>
//#include <iostream>
//using namespace std;
//
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//
//
//class Solution {
//public:
//	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
//		if (root == NULL)
//			return (vector<vector<int>>)0;
//		vector<vector<int>> PATH;//存储所有值为exNumber的路径
//		vector<int> path;//存储当前路径
//		int CurSum = 0;
//		FindPath(root, expectNumber, PATH, path, CurSum);
//	}
//
//	//因为都是从根节点开始遍历，所以使用前序遍历二叉树
//	void FindPath(TreeNode* root, int exNumber, vector<vector<int>>& PATH, vector<int>& path, int CurSum)
//	{
//		CurSum += root->val;
//		path.push_back(root->val);
//
//		//如果加完之后值等于输入的整数并且当前节点为叶子节点，则打印该节点并保存路径
//		bool isLeaf = root->left == NULL && root->right == NULL;
//		if (CurSum == exNumber && isLeaf)
//		{
//			//先将当前路径存储到PATH中
//			PATH.push_back(path);
//		}
//
//		//如果不是叶子节点，就去遍历他的子节点
//		if (root->left)
//			FindPath(root->left, exNumber, PATH, path, CurSum);
//		if (root->right)
//			FindPath(root->right, exNumber, PATH, path, CurSum);
//
//		//在回退到父节点之前，先从path中删除当前节点，并且CurSum减去当前值
//		path.pop_back();
//		CurSum -= root->val;
//	}
//};
//
//
//int main()
//{
//	vector<vector<int>> 
//}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//先对数组进行排序
		int size = numbers.size();
		if (size <= 0)
			return 0;
		QuickSort(numbers, 0, size);

		//由于数组的特性，如果某数字出现次数比一半还多，那么arr[size/2]一定是该数字
		int result = numbers[size / 2];
		if (DoseExist(numbers, result))
			return result;
		return false;
	}

	bool DoseExist(vector<int>& arr, int result)
	{
		int count = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] == result)
				++count;
		}

		if (count >(arr.size() / 2))
			return true;
		return false;
	}

	void QuickSort(vector<int>& arr, int left, int right)
	{
		if (left + 1 < right)
		{
			int div = Partion(arr, left, right);
			QuickSort(arr, left, div);
			QuickSort(arr, div + 1, right);//不用再包含div了
		}
	}

	int GetMidData(vector<int>& arr, int left, int right)
	{
		int mid = left + (right - left) / 2;
		if (arr[left] < arr[right])
		{
			if (arr[mid] < arr[left])
				return left;
			else if (arr[mid] > arr[right])
				return right;
			else
				return mid;
		}
		else
		{
			if (arr[mid] < arr[right])
				return right;
			else if (arr[mid] > arr[left])
				return left;
			else
				return mid;
		}
	}
	int Partion(vector<int>& arr, int left, int right)
	{
		int begin = left;
		int end = right - 1;
		int midIndex = GetMidData(arr, left, end);
		if (midIndex != end)
		{
			int tmp = arr[midIndex];
			arr[midIndex] = arr[end];
			arr[end] = tmp;
		}

		int key = arr[end];
		while (begin < end)
		{
			//从前往后找比key大的
			while (begin < end && key >= arr[begin])
				++begin;
			while (begin < end && key <= arr[end])
				--end;

			if (begin < end)
			{
				int tmp = arr[begin];
				arr[begin] = arr[end];
				arr[end] = tmp;
			}
		}

		if (begin != right - 1)
		{
			int tmp = arr[begin];
			arr[begin] = arr[end];
			arr[end] = tmp;
		}
		return begin;
	}
};


int main()
{
	Solution s;
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };

	cout << s.MoreThanHalfNum_Solution(arr) << endl;

	return 0;
}