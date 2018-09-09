
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//
//using namespace std;
//
//
//int main()
//{
//	int n, k, t;
//	vector<int> arr;
//	cin >> n >> k >> t;
//	int res = 0;
//	int count = 0;
//
//	while (n--)
//	{
//		int num = 0;
//		cin >> num;
//		arr.push_back(num);
//	}
//
//	int size = arr.size();
//	for (int i = 0; i < size; ++i)
//	{
//		int l = i;
//		int r = k + l - 1;
//		if (r >= size)
//			break;
//		map<int, int> map;
//		for (int j = l; j <= r; ++j)
//		{
//			++map[arr[j]];
//			if (map[arr[j]] >= t)
//			{
//				++count;
//				break;
//			}
//
//		}
//	}
//	cout << count << endl;
//	return 0;
//}
//
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//
//using namespace std;
//
//int GetRes(const vector<int>& arr, int k, int t)
//{
//	int count = 0;
//	unordered_map<int, int> map;
//	unordered_set<int> set;
//	int i = 0, j = 0;
//	for (; j<k; ++j)
//	{
//		if (map.find(arr[j]) == map.end())
//		{
//			map.insert({arr[j], 1 });
//		}
//		else
//		{
//			++map[arr[j]];
//			if (map[arr[j]] >= t && set.find(arr[j]) == set.end())
//			{
//				set.insert(arr[j]);
//			}
//		}
//	}
//	if (!set.empty())
//	{
//		++count;
//	}
//	for (i = 0, j = k; j<arr.size(); ++i, ++j)
//	{
//		--map[arr[i]];
//		if (map[arr[i]] < t)
//		{
//			map.erase(arr[i]);
//		}
//		++map[arr[j]];
//		if (map[arr[j]] >= t && set.find(arr[j]) == set.end())
//		{
//			set.insert(arr[j]);
//		}
//
//		if (!set.empty())
//		{
//			++count;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n, k, t;
//	vector<int> arr;
//	cin >> n >> k >> t;
//	int count = 0;
//	
//		while (n--)
//		{
//			int num = 0;
//			cin >> num;
//			arr.push_back(num);
//		}
//	
//	cout << GetRes(arr, k, t) << endl;
//	return 0;
//}


//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//int Partion(vector<int>& arr, int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = arr[end];
//	while (begin < end)
//	{
//		while (begin < end && arr[begin] <= key)
//			++begin;
//		while (begin < end && arr[end] >= key)
//			--end;
//		if (begin < end)
//			swap(arr[begin], arr[end]);
//	}
//
//	if (begin != right - 1)
//		swap(arr[begin], arr[right - 1]);
//
//	return begin;
//	
//}
//void _QuickSort(vector<int>& arr, int left, int right)
//{
//	if (right - left > 1)
//	{
//		int div = Partion(arr, left, right);
//		_QuickSort(arr, left, div);
//		_QuickSort(arr, div + 1, right);
//	}
//}
//void QuickSort(vector<int>& arr)
//{
//	int size = arr.size();
//	_QuickSort(arr, 0, size);
//}
//int main()
//{
//	vector<int> arr = { 4, 3, 6, 2, 8, 1 };
//	QuickSort(arr);
//	return 0;
//}

//void _AdjustDown(vector<int>& arr, int parent, int size)
//{
//	int child = parent * 2 + 1;
//	while (child < size)
//	{
//		if (child + 1 < size && arr[child] < arr[child + 1])
//			child += 1;
//		if (arr[child] > arr[parent])
//		{
//			swap(arr[child], arr[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			return;
//	}
//}
//
//int main()
//{
//	vector<int> arr = { 4, 3, 6, 2, 8, 1 };
//	int size = arr.size();
//	int root = (size - 2)/2;
//	int end = size - 1;
//	for (int i = root; i >= 0; --i)
//		_AdjustDown(arr, i, size);
//
//	while (end)
//	{
//		swap(arr[0], arr[end]);
//		_AdjustDown(arr, 0, end);
//		--end;
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	int T;
	cin >> T;
	vector<int> res;
	while (T--)
	{
		int n, X;
		cin >> n >> X;
		vector<int>arr;
		while (n--)
		{
			int i = 0;
			cin >> i;
			arr.push_back(i);
		}
		int count = 0;
		vector<int>::iterator beg = arr.begin();
		vector<int>::iterator end = arr.end();
		while (1)
		{
			sort(beg, end);
			arr[0] = 100;
			int avg = 0;
			int sum = 0;
			for (int i = 0; i < arr.size(); ++i)
			{
				sum += arr[i];
			}
			++count;
			avg = sum / arr.size();
			if (avg >= X)
				break;
		}
		res.push_back(count);
	}
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}