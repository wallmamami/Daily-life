#pragma once
#include <iostream>
using namespace std;


class Date
{
public:
	friend ostream& operator<< (ostream& os, const Date& d);//定义<<运算符重载为类的友元函数

	//类的默认成员函数
	Date(int year = 1900, int month = 1, int day = 1)//构造函数
	: _year(year)
	, _month(month)
	, _day(day)
	{
		if (_year < 1990 || _month < 1 || _day < 1 || GetMonth(_year, _month))
		{//非法日期
			cout << "Invalid Date " << endl;
		}
	}

	bool Isleap(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}

	int GetMonth(int year, int month)//获取该月的天数
	{
		if (month < 1 || month > 12)
		{
			cout << "Invalid month" << endl;
			return 0;
		}

		int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (Isleap(year))//瑞年二月29天
		{
			monthday[2] = 29;
		}

		return monthday[month];
	}

	Date(const Date& d)//拷贝构造
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{

	}

	Date& operator=(const Date& d)//赋值运算符重载
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}

	/*日期类的基本操作函数*/
	//日期编辑哦
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);

	//日期计算
	Date operator+ (int day);
	Date& operator+= (int day);
	Date operator- (int day);
	Date& operator-= (int day);
	Date operator++ (int);  //后置++
	Date& operator++ ();    //前置++
	Date operator-- (int);
	Date& operator-- ();
	int operator- (const Date& d);//计算两个日期相差的天数


private:
	int _year;
	int _month;
	int _day;
};