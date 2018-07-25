//#include <iostream>
//#include <vector>
//using namespace std;


//void MergeData(vector<int>& arr, int left, int mid, int right, vector<int>& tmp)
//{
//	int beginL = left, endL = mid;
//	int beginR = mid, endR = right;
//	int index = left;
//
//
//	while (beginL < endL && beginR < endR)
//	{
//		if (arr[beginL] <= arr[beginR])
//			tmp[index++] = arr[beginL++];
//		else
//			tmp[index++] = arr[beginR++];
//	}
//
//	while (beginL < endL)
//		tmp[index++] = arr[beginL++];
//	while (beginR < endR)
//		tmp[index++] = arr[beginR++];
//}
//
//void _MergeSort(vector<int>&arr, int left, int right, vector<int>& tmp)
//{
//	if (left + 1 < right)
//	{
//		int mid = left + (right - left) / 2;
//
//		_MergeSort(arr, left, mid, tmp);
//		_MergeSort(arr, mid, right, tmp);
//
//		MergeData(arr, left, mid, right, tmp);
//
//		memcpy(&arr + left, &tmp + left, (right - left)*sizeof(arr[0]));
//	}
//
//}
//void MergeSort(vector<int>& arr)
//{
//	int size = arr.size();
//	vector<int> tmp(size, 0);
//
//	_MergeSort(arr, 0, size, tmp);
//}




//#include <string.h>
//int main()
//{
//	vector<int> arr = { 4, 7, 2, 5, 1, 3 };
//
//	//vector<int> tmp;
//	//tmp[2] = 1;
//
//	//arr.assign(tmp.begin() + 3, tmp.begin() + 6);
//	
//	//MergeSort(arr);
//	vector<int> tmp(6, 0);
//	memcpy(&tmp + 2, &arr + 2, sizeof(int)* 2);
//	for (int i = 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}

//#include<stack>
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//		val(x), left(NULL), right(NULL) {
//	}
//};
//
//
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		//ǰ�����������
//		if (pRoot == NULL)
//			return;
//		//��֤���ڵ�������һ��������ȥ������
//		if (pRoot->left == NULL && pRoot->right == NULL)
//			return;
//
//		stack<TreeNode*> s;
//		s.push(pRoot);
//
//		while (!s.empty())
//		{
//			//�������ڵ�
//			TreeNode* pTmp = pRoot->left;
//			pRoot->left = pRoot->right;
//			pRoot->right = pTmp;
//
//
//			if (pRoot->right)
//				s.push(pRoot->right);
//			if (pRoot->left)
//				s.push(pRoot->left);
//		}
//
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	
//
//	return 0;
//}


//class Solution {
//public:
//	vector<int> printMatrix(vector<vector<int> > matrix) {
//		int rows = matrix.size();
//		int cols = matrix[0].size();
//
//		if (rows <= 0 || cols <= 0)
//			return (vector<int>)0;
//
//		vector<int> v;
//		int start = 0;//һȦһȦ��ӡ����ʼλ��Ϊ(0,0)
//		while (cols > start * 2 && rows > start * 2)//��4*4��һ��
//		{
//			printMaCircle(matrix, cols, rows, start, v);//ÿ�δ�ӡһȦ����ӡһȦ���Ĳ�
//			++start;//��ӡ����һȦ
//		}
//
//		return v;
//	}
//
//	void printMaCircle(vector<vector<int>>& array, int cols, int rows, int start, vector<int>& v)
//	{
//		int endY = rows - 1 - start;//��ֹ�У�����ұ�����
//		int endX = cols - 1 - start;//��ֹ�У�����ұ�����
//
//		//��һ��һ��Ҫִ��
//		int i = 0;
//		for (i = start; i <= endX; ++i)
//			v.push_back(array[start][i]);
//
//		//�����ֹ�д�����ʼ�У���ִ�еڶ���
//		if (start < endY)
//		{
//			for (i = start + 1; i <= endY; ++i)
//				v.push_back(array[i][endX]);
//		}
//
//		//�����ֹ�д�����ʼ�У���ֹ�д�����ʼ�У���ִ�е�����
//		if (start < endX && start < endY)
//		{
//			for (i = endX - 1; i >= start; --i)
//			{
//				v.push_back(array[endY][i]);
//			}
//		}
//
//		//�����ֹ�д�����ʼ�в�����ֹ�д�����ʼ�м�1�������������У�
//		if (start < endX && start + 1 < endY)
//		{
//			for (i = endY - 1; i > start; --i)
//				v.push_back(array[i][start]);
//		}
//	}
//};
//
//
//int main()
//{
//	Solution s;
//
//	return 0;
//}


#include <string.h>


bool IsNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
unsigned int Continumax(char** pOutputstr, char* intputstr)
{
	if (intputstr == NULL)
	{
		pOutputstr = NULL;
		return 0;
	}

	int max = 0;
	int sum = 0;
	int begin = 0;
	int Begin = 0;
	int flag = 0;
	int len = strlen(intputstr);

	for (int i = 0; i < len; ++i)
	{
		if (IsNumber(intputstr[i]))
		{
			if (flag == 1)
				sum += 1;
			else
			{
				flag = 1;
				begin = i;
				sum = 1;
			}
		}

		if ((flag == 1 && !IsNumber(intputstr[i])) || (flag == 1 && i == len - 1))//�����ִ��г����������һ��
		{
			if (max < sum)
			{
				max = sum;
				Begin = begin;
			}
		}

	}

	*pOutputstr = intputstr + Begin;
	*(intputstr + max) = '\0';

	return max;
}

int main()
{
	int a = 10;
	int* p = &a;
	int pa = *p;


}