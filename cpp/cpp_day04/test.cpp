
//int main()
//{
//	const int a = 10;
//	int arr[a];//��c++�У���Ϊa�Ѿ��ǳ���������c�����Ǳ������ᱨ��
//}


//class Date
//{
//public:
//	Date(int year = 2018, int month = 6, int day = 23)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	const int& GetDay()const //��const���κ�thisָ�����ʹ�Date* const this-->const Date* const this
//	{
//		return _day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	cout << d1.GetDay() << endl;
//}

//class Date
//{
//public:
//	Date(int year = 2018, int month = 6, int day = 23)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	const int& GetDay()const //��const���κ�thisָ�����ʹ�Date* const this-->const Date* const this
//	{
//		_day++;
//		return _day;
//	}
//private:
//	int _year;
//	int _month;
//	mutable int _day;
//};
//
//int main()
//{
//	Date d1;
//	cout << d1.GetDay() << endl;
//}
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	const int a = 10;
//	int* p = NULL;
//	cout << "�޸�ǰ��" << a << endl;
//
//	p = (int*)&a;
//	*p = 20;
//	cout << "�޸ĺ�" << a << endl;
//	
//	return 0;
//}

//#include <stdio.h>
//
//
//int main()
//{
//	const int a = 10;
//	int* p = NULL;
//
//	printf("�޸�ǰ��%d\n", a);
//
//	p = (int*)&a;
//	*p = 20;
//	
//	printf("�޸ĺ�%d\n", a);
//}


#include <iostream>

using namespace std;

class A
{
public:

	A(int v)
		: val(v)
		, str(NULL)
	{
		str =(char*) malloc(10);
	}
	~A()
	{
		cout << this << endl;
		free(str);
	}
private:
	int val;
	char* str;
};

void testfunc()
{
	A* pa = new A(10);

	delete []pa;
}
int main()
{

	testfunc();

	return 0;
}