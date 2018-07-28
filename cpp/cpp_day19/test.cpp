//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int InversePairs(vector<int> data) {
//		//使用归并排序
//		int size = data.size();
//		if (size <= 0)
//			return 0;
//
//		vector<int> tmp(size, 0);
//		int count = 0;
//		MergeSort(data, 0, size, tmp, count);
//
//		count %= 1000000007;
//		return count;
//	}
//
//	void MergeSort(vector<int>& data, int left, int right, vector<int>& tmp, int& count)
//	{
//		if (left + 1 < right)
//		{
//			int mid = left + (right - left) / 2;
//			MergeSort(data, left, mid, tmp, count);
//			MergeSort(data, mid, right, tmp, count);
//			MergeData(data, left, mid, right, tmp, count);
//
//			//将tmp中的值赋给data
//			for (int i = left; i < right; ++i)
//				data[i] = tmp[i];
//		}
//	}
//
//	void MergeData(vector<int>& data, int left, int mid, int right, vector<int>& tmp, int& count)
//	{
//		int beginL = left, endL = mid - 1;
//		int beginR = mid, endR = right - 1;
//		int index = right - 1;//从后朝前放
//
//		while (beginL <= endL && beginR <= endR)
//		{
//			if (data[endL] > data[endR])//逆序对
//			{
//				count += endR - beginR + 1;
//				tmp[index--] = data[endL--];
//			}
//			else
//				tmp[index--] = data[endR--];
//		}
//
//		while (beginL <= endL)
//			tmp[index--] = data[endL--];
//		while (beginR <= endR)
//			tmp[index--] = data[endR--];
//	}
//
//
//};
//
//
//int main()
//{
//	Solution s;
//
//	vector<int> data = { 7, 5, 6, 4 };
//
//	cout << s.InversePairs(data);
//
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;


//class Solution {
//public:
//	int GetNumberOfK(vector<int> data, int k) {
//		int count = 0;
//		int size = data.size();
//
//		if (size <= 0)
//			return 0;
//
//		//分别用二分查找找到第一个K和最后一个k
//		int First = GetFirstK(data, 0, size - 1, size, k);//这里还要传size
//		int Last = GetLastK(data, 0, size - 1, size, k);
//
//		if (First == -1 || Last == -1)
//			return 0;
//
//		return (Last - First + 1);
//	}
//
//	int GetFirstK(vector<int>& data, int left, int right, int size, int key)
//	{
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (data[mid] == key)
//			{
//				//看是不是第一个
//				if ((mid > 0 && data[mid - 1] != key) || mid == left)
//					return mid;
//				else
//					//在左半区间找
//					right = mid - 1;
//			}
//
//			else if (data[mid] < key)
//				left = mid + 1;
//			else
//				right = mid - 1;
//		}
//
//		return -1;
//	}
//
//	int GetLastK(vector<int>& data, int left, int right, int size, int key)
//	{
//
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (data[mid] == key)
//			{
//				if ((mid < size - 1 && data[mid + 1] != key) || mid == size - 1)
//					return mid;
//				else
//					left = mid + 1;
//			}
//			else if (data[mid] > key)
//				right = mid - 1;
//			else
//				left = left + mid;
//		}
//
//		return -1;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int> data = { 1, 2, 3, 3, 3, 3, 4, 5, 6 };
//
//	cout << s.GetNumberOfK(data, 3) << endl;
//
//	return 0;
//}


struct position
{
	int _x;
	int _y;
};

int main()
{
	position s;
	s.dsf 
}









