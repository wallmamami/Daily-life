//#include <iostream>
//using namespace std;
//
//
//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void PrintDate()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1, d2, d3;
//	d1.SetDate(2018, 6, 15);
//	d2.SetDate(2011, 6, 21);
//	d3.SetDate(1996, 9, 1);
//
//	d1.PrintDate();
//	d2.PrintDate();
//	d3.PrintDate();
//
//	return 0;
//}

#include <stdio.h>

struct Date
{
	int _year;
	int _month;
	int _day;
};

void SetDate(struct Date* d, int year, int month, int day)
{
	d->_year = year;
	d->_month = month;
	d->_day = day;
}

void PrintDate(struct Date* d)
{
	printf("%d/%d/%d\n", d->_year, d->_month, d->_day);
}

int main()
{
	struct Date d1, d2, d3;
	SetDate(&d1, 2018, 6, 15);//要设置哪个对象就必须将对象的地址传进去
	SetDate(&d2, 2011, 6, 21);
	SetDate(&d3, 1996, 9, 1);

	PrintDate(&d1);
	PrintDate(&d2);
	PrintDate(&d3);

	return 0;
}