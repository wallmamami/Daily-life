//#include <string>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n = 0;//塔的数量
//	int k = 0;//最大操作数
//	string s;
//	vector<int> arr;
//	vector<int> num;//保存每一次搬移的下标
//
//	cin >> n >> k;
//
//	getline(cin, s);//表示i最塔 的初始高度
//	for (int i = 0; i < s.size(); ++i)
//		arr.push_back(s[i]);
//
//	for (int i = 1; i <= k; ++i)
//	{
//		int maxInd = 0;
//		int minInd = 0;
//
//		//每趟找出最大值和最小值的下标
//		for (int j = 1; j < arr.size(); ++j)
//		{
//			if (arr[maxInd] < arr[j])
//				maxInd = j;
//			if (arr[minInd] > arr[j])
//				minInd = j;
//		}
//
//		if (maxInd != minInd && arr[minInd] != 0)
//		{
//			++arr[minInd];
//			--arr[maxInd];
//			num.push_back(maxInd);
//			num.push_back(minInd);
//		}
//	}
//
//	return 0;
//}


//class Test
//{
//	Test()
//	{
//		_id++;
//	}
//
//	~Test()
//	{
//		_id--;
//	}
//private:
//	static int _id;
//};
//
//int Test::_id = 0;


//#include <iostream>
//#include <string>
//#include <cstdio>
//#include <vector>
//#pragma warning (disable: 4996)
//
//using namespace std;
//
//
//struct Position
//{
//	int _x;
//	int _y;
//};
//
//bool IsUnlawful(vector<vector<char>>& arr, Position& cur)
//{
//	if (cur._x <= 0 || cur._x >= arr.size() || cur._y <= 0 || cur._y >= arr[0].size())
//		return true;
//	return false;
//}
//
//bool IsPass(vector<vector<char>>& arr, Position& next)
//{
//	if (!IsUnlawful)
//	{
//		if (arr[next._x][next._y] == 1)
//			return true;
//	}
//
//	return false;
//}
//void GetPAndQ(vector<vector<char>>& arr, Position& cur, int& Qmax, int& Pnum, int& max)
//{
//	if (IsUnlawful(arr, cur))//判断当前步是否越界
//		return;
//
//	Position next = cur;
//	bool IsTrue = false; //只要有意一个方向能走通，队伍数量就加一
//
//	//上
//	next._x -= 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//下
//	next._x += 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//左
//	next._y -= 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//右
//	next._y += 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//左上
//	next._y -= 1;
//	next._x -= 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//左下
//	next._y -= 1;
//	next._x += 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//右上
//	next._y += 1;
//	next._x -= 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//右下
//	next._y += 1;
//	next._x += 1;
//	if (IsPass(arr, next))
//	{
//		IsTrue = true;
//		max += 1;//只要走通，当前人数就加1
//
//		arr[next._x][next._y] = 0;
//		GetPAndQ(arr, next, Qmax, Pnum, max);
//	}
//
//	//只要右一个方向走通，球队数+1
//	if (IsTrue)
//	{
//		Pnum += 1;
//		if (max > Qmax)
//			Qmax = max;
//	}
//
//	//走到这说明都不同，或者一个球队访问完了，
//	if (cur._y == arr[0].size() - 1)//按照行来访问
//	{
//		cur._x += 1;
//		cur._y = 0;
//	}
//	else
//		cur._y += 1;
//	GetPAndQ(arr, cur, Qmax, Pnum, max);
//
//}
//int main()
//{
//	int M, N;//M行N列
//	string s;//用来保存每一行
//	vector<vector<char>> arr; //用来保存所有输入，包含','
//
//	cin >> M >> N;
//	scanf("%d,%d", &M, &N);
//
//	if (M <= 0 || M >= 1000 || N <= 0 || N >= 1000)
//		return 0;
//
//	for (int i = 0; i < M; ++i)
//	{
//		vector<char> line;
//		getline(cin, s);
//		for (int j = 0; j < s.size(); ++j)
//		{
//			if (s[j] != ',')
//				line.push_back(s[j]);
//		}
//		arr.push_back(line);
//	}
//
//	Position entry = { 0, 0 };
//	int Qmax = 0;//用来标记最大球队群体人数
//	int Pnum = 0;//用来表示球队群体个数
//	int max = 0; // 用来标记当前球队群体人数
//
//	GetPAndQ(arr, entry, Qmax, Pnum, max);
//	cout << Pnum << Qmax<< endl;
//
//	return 0;
//}


#include <iostream>
#pragma warning (disable:4996)
using namespace std;

//class A
//{
//private:
//	void* operator new(size_t size)
//	{}
//	void operator delete(void* ptr)
//	{}
//public:
//	A()
//	{}
//	~A()
//	{}
//};

class String
{
public:
	String(char *ptr = "")
		:_ptr(new char[strlen(ptr) + 1])
	{
		strcpy(_ptr, ptr);
	}

	String(const String& s)
		:_ptr(new char[strlen(s._ptr)+1])
	{
		strcpy(_ptr, s._ptr);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char *pTmp = new char[strlen(s._ptr) + 1];
			strcpy(pTmp, s._ptr);
			delete[] _ptr;
			_ptr = pTmp;
		}

		return *this;
	}

private:
	char *_ptr;
};

int main()
{
	String s("hello");
	String s2(s);
	String s3("world");

	s2 = s = s3;


	return 0;
}