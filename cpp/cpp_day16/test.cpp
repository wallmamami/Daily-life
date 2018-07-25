//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//void SelectSort(vector<int>& arr)
//{
//	int size = arr.size();
//	int start = 0;
//	int end = size - 1;
//
//	while (start < end)
//	{
//		int j = start + 1;
//		int minPos = start;
//		int maxPos = start;
//
//		for (; j <= end; ++j)
//		{
//			if (arr[minPos] > arr[j])
//				minPos = j;
//			if (arr[maxPos] < arr[j])
//				maxPos = j;
//		}
//
//		if (maxPos != end)
//			Swap(arr[maxPos], arr[end]);
//		if (minPos == end)
//			minPos = maxPos;
//
//		if (minPos != start)
//			Swap(arr[minPos], arr[start]);
//
//		++start;
//		--end;
//	}
//}
//
//
//void Adjustdown(vector<int>& arr, int size, int parent)
//{
//	int child = 2 * parent + 1;
//
//	while (child < size)
//	{
//		if (child + 1 < size && arr[child + 1] > arr[child])
//			child += 1;
//		if (arr[parent] < arr[child])
//		{
//			Swap(arr[parent], arr[child]);
//
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			return;
//	}
//}
//
//void HeapSort(vector<int>& arr)
//{
//	int size = arr.size();
//	int root = (size - 2) / 2;
//	int i = root;
//
//	for (; i >= 0; --i)
//		Adjustdown(arr, size, i);
//
//	int end = size - 1;
//	while (end)
//	{
//		Swap(arr[0], arr[end]);
//		Adjustdown(arr, end, 0);
//
//		--end;
//	}
//}
//
//int main()
//{
//	vector<int> arr = { 1, 5, 6, 3, 2, 7, 4 };
//	SelectSort(arr);
//	
//	int i = 0;
//	for (; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//
//	HeapSort(arr);
//	for (i= 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <unordered_set>
//
//
//using namespace std;
//
//
//int main()
//{
//	
//	string s = "abcd";
//	unordered_set<char> htable;
//	s.clear();
//	cout << s.size() << endl;
//	//htable.insert(s[3]);
//
//
//	cout << htable.size() << endl;
//
//	unordered_set<char>::iterator itr;
//	for (itr = htable.begin(); itr != htable.end(); ++itr)
//		cout << *itr << " ";
//	cout << endl;
//	return 0;
//}

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//string& UniqueOutput(string& s)
//{
//	int i = 0;
//	set<char> htable;
//	for(; i < s.size(); ++i)
//	{
//		htable.insert(s[i]);
//	}
//	s.clear();
//	set<char>::iterator ite = htable.begin();
//	for (; ite != htable.end(); ++ite)
//		s.push_back(*ite);
//	return s;
//}

//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		vector<int> arr(122, 0);
//		string str2;
//		int i = 0;
//		for (; i < str.size(); ++i)
//		{
//			if (arr[str[i]] == 0)
//			{
//				arr[str[i]]++;
//				str2.push_back(str[i]);
//			}
//		}
//		
//		cout << str2 << endl;
//	}
//
//
//	return 0;
//}


//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//void BubbleSort(vector<int>& arr)
//{
//	int size = arr.size();
//	int i = 0;
//	for (; i < size - 1; ++i)
//	{
//		int j = 0;
//		int flag = 0;
//		for (; j < size - i - 1; ++j)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				Swap(arr[j], arr[j + 1]);
//				flag = 1;
//			}
//		}
//
//		if (flag == 0)
//			break;
//
//	}
//	
//}
//
//int main()
//{
//	vector<int> arr = { 2, 5, 3, 7, 1 };
//
//	BubbleSort(arr);
//	
//	for (i = 0; i < arr.size(); i++)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//int GetMidData(vector<int>& arr, int left, int right)
//{
//	int mid = left + (right - left) / 2;
//	if (arr[left] > arr[right])
//	{
//		if (arr[mid] > arr[left])
//			return left;
//		else if (arr[mid] < arr[right])
//			return right;
//		else
//			return mid;
//	}
//
//	else
//	{
//		if (arr[mid] > arr[right])
//			return right;
//		else if (arr[mid] < arr[left])
//			return left;
//		else
//			return mid;
//	}
//}
//
//int Partion(vector<int>& arr, int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int midIndex = GetMidData(arr, begin, end);
//	if (midIndex != end)
//		Swap(arr[midIndex], arr[end]);
//
//	int key = arr[end];
//	while (begin < end)
//	{
//		while (begin < end && arr[begin] <= key)
//			++begin;
//		while (begin < end && arr[end] >= key)
//			--end;
//
//		if (begin < end)
//			Swap(arr[begin], arr[end]);
//	}
//
//	//因为begin最后肯定指的使比key大的值
//	//if (begin != end)千万不能用end
//	if (begin != right - 1)
//		Swap(arr[begin], arr[right - 1]);
//	return begin;
//}
//
//void _QuickSort(vector<int>& arr, int left, int right)
//{
//	if (right - left > 1)
//	{
//		int div = Partion(arr, left, right);
//		_QuickSort(arr, left, div);
//		_QuickSort(arr, div + 1, right);
//	}
//}
//
//
//
//void QuickSort(vector<int>& arr)
//{
//
//	_QuickSort(arr, 0, arr.size());
//}

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		vector<int> result;
//		int num = array.size();
//		for (int i = 0; i<num; i++)
//		{
//			if (array[i] % 2 == 1)
//				result.push_back(array[i]);
//		}
//		for (int i = 0; i<num; i++)
//		{
//			if (array[i] % 2 == 0)
//				result.push_back(array[i]);
//		}
//		array = result;
//	}
//};
//
//
//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		int size = array.size();
//		vector<int> result;
//
//		for (int i = 0; i < size; ++i)
//		{
//			if ((array[i] & 1) != 0)
//				result.push_back(array[i]);
//		}
//
//		for (int i = 0; i < size; ++i)
//		{
//			if (array[i] % 2 == 0)
//			{
//				result.push_back(array[i]);
//			}
//		}
//
//		array = result;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> arr = { 2, 5, 3, 7, 1 };
//
//	s.reOrderArray(arr);
//	int i = 0;
//	for (i = 0; i < arr.size(); i++)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}



//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//class Solution {
//public:
//	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//	{
//
//		if (pRoot1 == NULL || pRoot2 == NULL)
//			return false;
//
//		bool result = false;//如果跟节点相同但是其他节点不相同还要继续找
//		//首先遍历树，找到与root2相等的跟节点，再去看他们的其他节点是否相同
//		if (pRoot1->val == pRoot2->val)
//			result = DoseTree1HasTree2(pRoot1, pRoot2);
//
//		//如果已经发现tree1有tree2了就不用找了，否则，继续遍历tree1
//		if (!result)
//			//遍历左子树
//			HasSubtree(pRoot1->left, pRoot2);
//		if (!result)
//			//右子树
//			HasSubtree(pRoot1->right, pRoot2);
//
//		return result;
//	}
//
//	//当在tree1中找到了与tree2的跟节点相同后，用来判断后序的是否相同
//	bool DoseTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
//	{
//		//如果tree2递归完了，说明之前都相等
//		if (pRoot2 == NULL)
//			return true;
//		if (pRoot1 == NULL)
//			return false;
//		if (pRoot1->val != pRoot2->val)
//			return false;
//
//		//跟节点相等，再去看做子树和右子树
//		return DoseTree1HasTree2(pRoot1->left, pRoot2->left) && DoseTree1HasTree2(pRoot1->right, pRoot2->right);
//	}
//};
//
//
//int main()
//{
//	string{ 8, 8, 7, 9, 2, #, #, #, #, 4, 7 },
//}

