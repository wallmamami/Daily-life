//#include <iostream>
//using namespace std;


//class Time
//{
//public:
//	Time(int hour, int minute, int day)
//	{
//
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int, int, int)" << this << endl;
//	}
//
//	Date(int year, int month)
//		:_year(year)
//		,_month(month)
//	{
//		cout << "Date(int, int)" << this << endl;
//	}
//
//	Date()
//	{
//		cout << "Date()" << this << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};

//int main()
//{
//	Date d3(2018, 8, 15);
//	Date d1(2018, 8);
//	Date d2;//如果不传参不要写成d2()
//
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date()const
//		:_year(2018)
//		, _month(9)
//		, _day(10)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	//Date(const Date& d)//拷贝构造函数
//	//	:_year(d._year)
//	//	, _month(d._month)
//	//	, _day(d._day)
//	//{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2018, 9, 10);
//	Date d2(d1);
//
//	return 0;
//}


//#include <iostream>
//#include <malloc.h>
//using namespace std;
//
//class Array
//{
//public:
//	Array(int capacity)
//		:_arr(NULL)
//		,_capacity(capacity)
//		, _size(0)
//	{
//		cout << "Array()" << this << endl;
//		_arr = (int*)malloc(sizeof(int)*capacity);
//	}
//
//	~Array()//析构函数
//	{
//		cout << "~Array()" << this << endl;
//		free(_arr);
//		_capacity = _size = 0;
//	}
//
//private:
//	int* _arr;
//	int _capacity;
//	int _size;
//};
//
//int main()
//{
//	
//	Array arr(10);
//
//	return 0;
//}

#include <iostream>
using namespace std;


//class Date
//{
//	friend Date operator+(Date& d1, const Date& d2);//将加法操作符重载定义为类的友元，这样就能访问类的私有成员变量
//
//public:
//	Date(int year = 2018, int month = 6, int day = 20)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{}
//	Date& operator = (const Date& d)//赋值操作符重载
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;//返回引用
//	}
//	
//
//	~Date()
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date operator+(Date& d1, const Date& d2)
//{
//	Date d3;
//	d3._day = d1._day + d2._day;
//
//	return d3;
//}
//
//
//int main()
//{
//	Date d1;
//	Date d2(2019, 6, 5);
//	Date d3;
//
//	d3 = d1 + d2;
//
//	return 0;
//}


//class Date
//{
//
//public:
//	Date(int year = 2018, int month = 6, int day = 20)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{}
//	Date& operator = (const Date& d)//赋值操作符重载
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;//返回引用
//	}
//
//	Date& operator++()//前置++
//	{
//		++_day;
//		return *this;//返回引用
//	}
//	const Date operator++(int)//后置++，这里是为了区别前置与后置函数的区别，形成函数重载
//	{
//		Date d(*this);//用当前对象拷贝构造临时变量d
//		++_day;//利用前置++
//
//		return d;//返回值，因为后置++是先使用值，再自增
//	}
//
//
//	~Date()
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	Date d2(2019, 6, 5);
//	Date d3;
//
//	d3 = d2++;
//	d3 = ++d1;
//	return 0;
//}


//class Date
//{
//
//public:
//	Date(int year = 2018, int month = 6, int day = 20)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{}
//	Date& operator = (const Date& d)//赋值操作符重载
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;//返回引用
//	}
//
//	Date* operator&()//取地址操作符重载，this指针类型为Date* const this(指向不能改变)
//	{
//		return this;
//	}
//
//	const Date* operator&()const//const修饰的取地址操作符重载，this指针类型为
//								//const Date* const this(除了指向不能改变，指针指向的内容也不能改变)
//	{
//		return this;
//	}
//
//	~Date()
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	const Date d2(2019, 6, 5);
//
//	cout << &d1 << endl;//调用取地址操作符重载
//	cout <<&d2 << endl;//调用const修饰的取地址操作符重载
//	return 0;
//}
class Time
{
public:
	Time(int hour, int minute, int day)
	{

	}

private:
	int _hour;
	int _minute;
	int _second;
};


class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1(2018, 9, 10);
	Date d2(d1);

	return 0;
}