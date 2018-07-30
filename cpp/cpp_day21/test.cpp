#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;


//int main()
//{
//	string s1 = "abcdef";
//	cout << s1.length() << endl;
//
//	cout << s1.back() << endl;
//	s1.pop_back();
//	cout << s1.length() << endl;
//	cout << s1.front() << endl;
//
//
//	return 0;
//}


//class Solution {
//public:
//	string ReverseSentence(string str) {
//		int len = str.length();
//		string s;
//		if (len <= 0)
//			return s;
//
//		int i = 0;
//
//		for (; i < len; ++i)
//		{
//			char c = str.back();
//			s.push_back(c);
//			str.pop_back();
//		}
//
//		return s;
//	}
//};


//class Solution {
//public:
//	string ReverseSentence(string str) {
//		//首先反转整体，然后反转每个单词
//
//		int len = str.length();
//		string s;
//		if (len <= 0)
//			return s;
//
//		//1.反转整体
//		Reverse(str, 0, len - 1);
//		int start = 0;
//		int end = 0;
//		bool flag = false;
//
//		while (end < len && start < len)
//		{
//			if (str[end] != ' ')
//			{
//				if (flag)
//					end++;
//				else
//				{
//					flag = true;
//					end++;
//				}
//			}
//
//			if ((flag && str[end] == ' ') || (flag && end == len - 1))
//			{
//				if (str[end] == ' ')
//					end = end - 1;
//				Reverse(str, start, end);
//				flag = false;
//				start = end + 2;
//				end = start;
//			}
//		}
//
//		return str;
//	}
//
//	void Reverse(string& str, int begin, int end)//左闭右闭
//	{
//
//		while (begin < end)
//		{
//			char tmp = str[begin];
//			str[begin] = str[end];
//			str[end] = tmp;
//
//			++begin, --end;
//		}
//	}
//};

//#include <vector>
//
//void CountSort(vector<int>& arr)
//{
//	int MinData = arr[0];
//	int MaxData = arr[0];
//	int size = arr.size();
//
//	int i = 0;
//	for (i = 0; i < size; ++i)
//	{
//		if (arr[i] < MinData)
//			MinData = arr[i];
//		if (arr[i] > MaxData)
//			MaxData = arr[i];
//	}
//
//	//根据最大最小值计算出范围
//	int range = MaxData - MinData + 1;
//
//	//根据范围申请空间
//	vector<int> Count(range, 0);
//
//	for (i = 0; i < size; ++i)//将待排序数组中的数据对应Count数组的下标，值+1
//		++Count[arr[i] - MinData];
//
//	int index = 0;
//	//最后将数据在搬运到原数组
//	for (i = 0; i < range; ++i)
//	{
//		while (Count[i]--)
//			arr[index++] = i + MinData;
//	}
//}
//
//int main()
//{
//	
//	vector<int> arr = { 9, 2, 3, 5, 1, 0 };
//	CountSort(arr);
//
//	int i = 0;
//	for (i = 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}


//class Solution {
//public:
//	bool IsContinuous(vector<int> numbers) {
//		//numbers就是抽到的5张牌，判断这5张牌是否连续
//
//		//0代表大小王，可以代替任何数字
//		//先对数组进行排序
//		CountSort(numbers);
//		int size = numbers.size();
//
//		if (size < 5)
//			return false;
//		//统计出0的个数，即最多可以“间隔”几个1， 3， 4， 5这里1和3就是间隔1个，也就是必须有一个0（即大小王）才能算连续
//		int countzero = 0;
//		int i = 0;
//		while (i < size && numbers[i] == 0)//因为已经有序了,后面的为了防止特殊情况
//		{
//			++countzero;
//			++i;
//		}
//
//		//计算序列中相邻元素的总间隔数
//		int count = 0;
//		int begin = countzero;//从第一个不为0的数据开始
//		int end = countzero + 1;
//
//		while (begin < size && end < size)
//		{
//			//如果有“对子”，肯定不是连续的
//			if (numbers[begin] == numbers[end])
//				return false;
//			count += numbers[end] - numbers[begin] - 1;
//			++begin;
//			++end;
//		}
//
//		//如果0的个数小于间隔总数，则不连续
//		if (countzero >= count)
//			return true;
//		return false;
//	}
//
//	void CountSort(vector<int>& arr)
//	{
//		int MinData = arr[0];
//		int MaxData = arr[0];
//		int size = arr.size();
//
//		int i = 0;
//		for (i = 0; i < size; ++i)
//		{
//			if (arr[i] < MinData)
//				MinData = arr[i];
//			if (arr[i] > MaxData)
//				MaxData = arr[i];
//		}
//
//		//根据最大最小值计算出范围
//		int range = MaxData - MinData + 1;
//
//		//根据范围申请空间
//		vector<int> Count(range, 0);
//
//		for (i = 0; i < size; ++i)//将待排序数组中的数据对应Count数组的下标，值+1
//			++Count[arr[i] - MinData];
//
//		int index = 0;
//		//最后将数据在搬运到原数组
//		for (i = 0; i < range; ++i)
//		{
//			while (Count[i]--)
//				arr[index++] = i + MinData;
//		}
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int> numbers = { 0, 1, 3, 0, 5 };
//
//	cout << s.IsContinuous(numbers) << endl;
//
// 	return 0;
//}


//void CountSort(vector<int>& arr)
//{
//	int MinData = arr[0];
//	int MaxData = arr[0];
//	int size = arr.size();
//
//	int i = 0;
//	for (i = 0; i < size; ++i)
//	{
//		if (arr[i] < MinData)
//			MinData = arr[i];
//		if (arr[i] > MaxData)
//			MaxData = arr[i];
//	}
//
//	//根据最大最小值计算出范围
//	int range = MaxData - MinData + 1;
//
//	//根据范围申请空间
//	vector<int> Count(range, 0);
//
//	for (i = 0; i < size; ++i)//将待排序数组中的数据对应Count数组的下标，值+1
//		++Count[arr[i] - MinData];
//
//	int index = 0;
//	//最后将数据在搬运到原数组
//	for (i = 0; i < range; ++i)
//	{
//		while (Count[i]--)
//			arr[index++] = i + MinData;
//	}
//}
//
//int main()
//{
//	vector<int> arr = { 0, 0, 0, 0, 0, 0, 0 };
//
//	CountSort(arr);
//
//	for (int i = 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}


//class Solution {
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		if (n <= 0)
//			return 0;
//
//		list<int> Circle;
//		//将节点插到链表中
//		for (int i = 0; i < n; ++i)
//			 Circle.push_back(i);
//
//		list<int>::iterator Cur = Circle.begin();
//
//		while (Circle.size() > 1)
//		{
//			for (int i = 1; i < m; ++i)//注意是从1开始，自己数链表去
//			{
//				++Cur;
//				if (Cur == Circle.end())//因为list不是环形链表，所以每次走到这就让它从开始继续走
//					Cur = Circle.begin();
//
//			}
//			//保存Cur的下个节点，删除Cur后，下次就从下一个节点开始数
//			list<int>:: iterator next = ++Cur;
//			if (next == Circle.end())
//				next = Circle.begin();
//
//			--Cur;
//			Circle.erase(Cur);
//
//			Cur = next;//一定要重新再给Cur赋值，之前指的节点已经释放了
//		}
//
//		return Circle.front();
//	}
//};


//class Temp
//{
//public:
//	Temp()
//	{
//		++_n;
//		_sum += _n;
//	}
//
//	int GetSum()
//	{
//		return _sum;
//	}
//private:
//	static int _n;
//	static int _sum;
//};
//
//int Temp::_n = 0;
//int Temp::_sum = 0;
//
//class Solution {
//public:
//
//	int Sum_Solution(int n) {
//		//利用构造函数，将需要累加的数字放到构造函数中，然后创建n个该对象，就可以
//		Temp* t = new Temp[n];
//		int sum = t->GetSum();
//		delete[]t;//记得要释放空间
//		t = NULL;
//
//		return sum;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.Sum_Solution(5) << endl; 
//
//	return 0;
//}


int main()
{
	cout << sizeof(long) << endl;
	string s;
	cout << s.size() << endl;

	return 0;
}