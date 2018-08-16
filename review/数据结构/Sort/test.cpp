#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//��������
//ֱ�Ӳ���
//ʱ�临�Ӷȣ�O(n^2) ��������O(n)
//�ռ临�Ӷȣ�O(1)
//���ó������������٣����ݽӽ�����
//�ȶ��ԣ��ȶ�
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

//ϣ������(��С)
//�Ƕ�ֱ�Ӳ�����Ż�
//ʱ�临�Ӷ� ���O(n^1.25~1.6n^1.25)
//�ռ临�Ӷ� O(1)
//���ó�������������
//�ȶ��ԣ����ȶ�
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

//ѡ������
//ֱ��ѡ��
//ʱ�临�Ӷ� O(n^2)
//�ռ临�Ӷ� O(1)
//�ȶ��� ���ȶ�
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

//������
//ʱ�临�Ӷȣ�O(nlogn)
//�ռ临�Ӷȣ�O(1)
//�ȶ��ԣ����ȶ�
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

//ð������
//ʱ�临�Ӷ�O(n^2) ������O(n��
//�ռ临�Ӷ�O(1)
//ʹ�ó���:�����������
//�ȶ��ԣ��ȶ�
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


//��������
//ʱ�临�Ӷȣ�O(n^2) ������� O(nlogn)
//�ռ临�Ӷȣ�O(n) �������O(logn)
//�������ݱȽ����
//�ȶ��ԣ����ȶ�
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


//�鲢����
//ʱ�临�Ӷȣ�O(nlogn)
//�ռ临�Ӷȣ�O(n)
//���������ⲿ����
//�ȶ��ԣ��ȶ�
void MergeData(vector<int>& arr, int left, int mid, int right, vector<int>& tmpV)
{
	int beginL = left, endL = mid - 1;
	int beginR = mid, endR = right - 1;
	int index = left;//�������������ռ�

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

//��������
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(M)MΪ���ݵķ�Χ
//ʹ�÷�Χ��������һ����Χ��
//�ȶ��ԣ��ȶ�
void CountSort(vector<int>& arr)
{
	int size = arr.size();
	if (size <= 0)
		return;
	int min = arr[0];//���������С��
	int max = arr[0];//������������

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