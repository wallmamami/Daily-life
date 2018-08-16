#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//插入排序
//直接插入
//时间复杂度：O(n^2) 最好情况：O(n)
//空间复杂度：O(1)
//适用场景：数据量少，数据接近有序
//稳定性：稳定
void InsertSort(vector<int>& arr)
{
	int size = arr.size();

	for (int i = 1; i < size; ++i)
	{
		int end = i - 1;
		int k = arr[i];
		
		while (end >= 0 && arr[end] > k)
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = k;
	}

}

//希尔排序(缩小)
//是对直接插入的优化
//时间复杂度 大概O(n^1.25~1.6n^1.25)
//空间复杂度 O(1)
//适用场景：数据量大
//稳定性：不稳定
void ShellSort(vector<int>& arr)
{
	int size = arr.size();
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; ++i)
		{
			int end = i - gap;
			int k = arr[i];

			while (end >= 0 && arr[end] > k)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}

			arr[end + gap] = k;
		}
	}
}

//选择排序
//直接选择
//时间复杂读 O(n^2)
//空间复杂度 O(1)
//稳定性 不稳定
void SelectSort(vector<int>& arr)
{
	int size = arr.size();
	int begin = 0;
	int end = size - 1;

	while (begin < end)
	{
		int minPos = begin;
		int maxPos = begin;
		
		for (int j = begin + 1; j <= end; ++j)
		{
			if (arr[minPos] > arr[j])
				minPos = j;
			if (arr[maxPos] < arr[j])
				maxPos = j;
		}

		if (maxPos != end)
			swap(arr[maxPos], arr[end]);
		if (minPos == end)
			minPos = maxPos;
		if (minPos != begin)
			swap(arr[minPos], arr[begin]);

		++begin, --end;
	}
}

//堆排序
//时间复杂度：O(nlogn)
//空间复杂度：O(1)
//稳定性：不稳定
void AdjustDown(vector<int>& arr, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && arr[child] < arr[child + 1])
			child += 1;

		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;

	}
}

void HeapSort(vector<int>& arr)
{
	int size = arr.size();
	int root = (size - 2) / 2;

	for (int i = root; i >= 0; --i)
		AdjustDown(arr, size, i);

	int end = size - 1;
	while (end)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}
}

//冒泡排序
//时间复杂度O(n^2) 最好情况O(n）
//空间复杂度O(1)
//使用场景:数据相对有序
//稳定性：稳定
void BubbleSort(vector<int>& arr)
{
	int size = arr.size();

	for (int i = 0; i < size - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}


//快速排序
//时间复杂度：O(n^2) 最优情况 O(nlogn)
//空间复杂度：O(n) 最优情况O(logn)
//适用数据比较随机
//稳定性：不稳定
int GetMidData(const vector<int>& arr, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (arr[left] > arr[right])
	{
		if (arr[mid] > arr[left])
			return left;
		else if (arr[mid] < arr[right])
			return right;
		else
			return mid;
	}
	else
	{
		if (arr[mid] > arr[right])
			return right;
		else if (arr[mid] < arr[left])
			return left;
		else
			return mid;
	}

}

int Partion(vector<int>& arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int MidIndex = GetMidData(arr, left, end);
	if (MidIndex != end)
		swap(arr[MidIndex], arr[end]);

	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			++begin;
		while (end > begin && arr[end] >= key)
			--end;

		if (begin < end)
			swap(arr[begin], arr[end]);
	}

	if (begin != right - 1)
		swap(arr[begin], arr[right - 1]);

	return begin;
}

void _QuickSort(vector<int>& arr, int left, int right)
{
	if (right - left > 1)
	{
		int div = Partion(arr, left, right);
		_QuickSort(arr, left, div);
		_QuickSort(arr, div + 1, right);
	}
}


void QuickSort(vector<int>& arr)
{
	int size = arr.size();
	_QuickSort(arr, 0, size);
}


//归并排序
//时间复杂度：O(nlogn)
//空间复杂度：O(n)
//数据量大，外部排序
//稳定性：稳定
void MergeData(vector<int>& arr, int left, int mid, int right, vector<int>& tmpV)
{
	int beginL = left, endL = mid - 1;
	int beginR = mid, endR = right - 1;
	int index = left;//用来索引辅助空间

	while (beginL <= endL && beginR <= endR)
	{
		if (arr[beginL] <= arr[beginR])
			tmpV[index++] = arr[beginL++];
		else
			tmpV[index++] = arr[beginR++];

	}

	while (beginL <= endL)
		tmpV[index++] = arr[beginL++];
	while (beginR <= endR)
		tmpV[index++] = arr[beginR++];

	for (int i = left; i < right; ++i)
		arr[i] = tmpV[i];
}

void _MergeSort(vector<int>& arr, int left, int right, vector<int>& tmpV)
{
	if (right - left > 1)
	{
		int mid = left + (right - left) / 2;
		_MergeSort(arr, left, mid, tmpV);
		_MergeSort(arr, mid, right, tmpV);
		MergeData(arr, left, mid, right, tmpV);
	}
}

void MergeSort(vector<int>& arr)
{
	int size = arr.size();
	vector<int> tmpV(size, 0);
	_MergeSort(arr, 0, size, tmpV);
}

//计数排序
//时间复杂度：O(n)
//空间复杂度：O(M)M为数据的范围
//使用范围：数据再一定范围内
//稳定性：稳定
void CountSort(vector<int>& arr)
{
	int size = arr.size();
	if (size <= 0)
		return;
	int min = arr[0];//用来标记最小数
	int max = arr[0];//用来标记最大数

	for (int i = 1; i < size; ++i)
	{
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	int range = max - min + 1;
	vector<int> Count(range, 0);

	for (int i = 0; i < size; ++i)
	{
		++Count[arr[i] - min];
	}

	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (Count[i]--)
			arr[index++] = i + min;
	}
}
int main()
{
	vector<int> arr = { 4, 6, 3, 1, 9, 7, 5 };
	//vector<int> tmp(1, 10);
	//cout << tmp.size() << endl;
	//BubbleSort(arr);
	//InsertSort(arr);
	//ShellSort(arr);
	//SelectSort(arr);
	//HeapSort(arr);
	//QuickSort(arr);
	//MergeSort(arr);
	CountSort(arr);
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
	

	return 0;
}