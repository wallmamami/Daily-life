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
//	Date d2;//��������β�Ҫд��d2()
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
//	//Date(const Date& d)//�������캯��
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
//	~Array()//��������
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
//	friend Date operator+(Date& d1, const Date& d2);//���ӷ����������ض���Ϊ�����Ԫ���������ܷ������˽�г�Ա����
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
//	Date& operator = (const Date& d)//��ֵ����������
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;//��������
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
//	Date& operator = (const Date& d)//��ֵ����������
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;//��������
//	}
//
//	Date& operator++()//ǰ��++
//	{
//		++_day;
//		return *this;//��������
//	}
//	const Date operator++(int)//����++��������Ϊ������ǰ������ú����������γɺ�������
//	{
//		Date d(*this);//�õ�ǰ���󿽱�������ʱ����d
//		++_day;//����ǰ��++
//
//		return d;//����ֵ����Ϊ����++����ʹ��ֵ��������
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
//	Date& operator = (const Date& d)//��ֵ����������
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;//��������
//	}
//
//	Date* operator&()//ȡ��ַ���������أ�thisָ������ΪDate* const this(ָ���ܸı�)
//	{
//		return this;
//	}
//
//	const Date* operator&()const//const���ε�ȡ��ַ���������أ�thisָ������Ϊ
//								//const Date* const this(����ָ���ܸı䣬ָ��ָ�������Ҳ���ܸı�)
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
//	cout << &d1 << endl;//����ȡ��ַ����������
//	cout <<&d2 << endl;//����const���ε�ȡ��ַ����������
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