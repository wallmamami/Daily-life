#pragma once
#include <iostream>
using namespace std;


class Date
{
public:
	friend ostream& operator<< (ostream& os, const Date& d);//����<<���������Ϊ�����Ԫ����

	//���Ĭ�ϳ�Ա����
	Date(int year = 1900, int month = 1, int day = 1)//���캯��
	: _year(year)
	, _month(month)
	, _day(day)
	{
		if (_year < 1990 || _month < 1 || _day < 1 || GetMonth(_year, _month))
		{//�Ƿ�����
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

	int GetMonth(int year, int month)//��ȡ���µ�����
	{
		if (month < 1 || month > 12)
		{
			cout << "Invalid month" << endl;
			return 0;
		}

		int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (Isleap(year))//�������29��
		{
			monthday[2] = 29;
		}

		return monthday[month];
	}

	Date(const Date& d)//��������
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{

	}

	Date& operator=(const Date& d)//��ֵ���������
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}

	/*������Ļ�����������*/
	//���ڱ༭Ŷ
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);

	//���ڼ���
	Date operator+ (int day);
	Date& operator+= (int day);
	Date operator- (int day);
	Date& operator-= (int day);
	Date operator++ (int);  //����++
	Date& operator++ ();    //ǰ��++
	Date operator-- (int);
	Date& operator-- ();
	int operator- (const Date& d);//��������������������


private:
	int _year;
	int _month;
	int _day;
};