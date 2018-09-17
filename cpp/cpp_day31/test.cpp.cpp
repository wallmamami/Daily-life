//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//int Partion(vector<int>&arr, int left, int right)
//{
//	int beg = left;
//	int end = right - 1;
//	int key = arr[end];
//	while (beg < end)
//	{
//		while (beg < end && arr[beg] <= key)
//			++beg;
//		while (beg < end && arr[end] >= key)
//			--end;
//		if (beg < end)
//			swap(arr[beg], arr[end]);
//	}
//
//	if (beg != right - 1)
//		swap(arr[beg], arr[right - 1]);
//	return beg;
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
//void QuickSort(vector<int>& arr)
//{
//	int size = arr.size();
//	_QuickSort(arr, 0, size);
//}
//
//int main()
//{
//
//	vector<int> arr = { 3, 1, 2, 6, 0, 5 };
//
//	QuickSort(arr);
//	for (int i = 0; i < arr.size(); ++i)
//		cout << arr[i];
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;


struct Position
{
	int x_;
	int y_;
};



int GetMin(Position in, Position out)
{
	vector<vector<int>> arr(8, vector<int>(8, 0));
	_GetMin(arr, in, out);
}

int main()
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	Position in;
	in.x_ = x1;
	in.y_ = y1;

	Position out;
	out.x_ = x2;
	out.y_ = y2;

	cout << GetMin(in, out) << endl;
	return 0;
}