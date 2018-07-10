#include "Date.h"

ostream& operator<< (ostream& os, const Date& d)//输出<<重载函数
{
	os << d._year << "/";
	os << d._month << "/";
	os << d._day << endl;
	return os;
}

/*日期比较*/
bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
	{
		return true;
	}

	return false;
}
bool Date::operator!=(const Date& d)
{
	if (*this == d)	
	{
		return false;
	}

	return true;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}

bool Date::operator>=(const Date& d)
{
	//等于或者大于都是大于等于
	if (*this > d)
	{
		return true;
	}
	else if (*this == d)
	{
		return true;
	}

	return false;
}
bool Date::operator<(const Date& d)
{
	if (*this >= d)//只要不是大于等于，就一定是小于
	{
		return false;
	}

	return true;
}

bool Date::operator<=(const Date& d)
{
	if (*this > d)//只要不是大于，就一定是小于等于
	{
		return false;
	}

	return true;
}


/*日期计算*/
Date Date::operator+(int day)
{
	//有可能传负值
	if (day < 0)
	{
		day = -day;
		return (*this - day);//调用-运算符重载
	}

	Date tmp(*this);
	tmp._day += day;
	
	int GetDay = GetMonth(tmp._year, tmp._month);
	while (tmp._day > GetDay)
	{
		tmp._day -= GetDay;
		if (tmp._month == 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
		else
		{
			tmp._month++;
		}
		GetDay = GetMonth(tmp._year, tmp._month);
	}

}
Date& Date:: operator+=(int day)
{
	Date tmp(*this);
	tmp = (*this) + day;
	*this = tmp;

	return *this;
}

Date Date::operator-(int day)
{
	//有可能传负值
	if (day < 0)
	{
		day = -day;
		return (*this+day);//调用+运算符重载
	}

	Date tmp(*this);
	tmp._day -= day;

	int GetDay = GetMonth(tmp._year, tmp._month);
	while (tmp._day <= 0)
	{
		tmp._day += GetDay;
		if (tmp._month == 1)
		{
			tmp._year--;
			tmp._month = 12;
		}
		else
		{
			tmp._month--;
		}
		GetDay = GetMonth(tmp._year, tmp._month);
	}

}

Date& Date:: operator-=(int day)
{
	Date tmp(*this);
	tmp = (*this) - day;
	*this = tmp;

	return *this;
}

Date Date::operator++ (int)  //后置++
{
	Date tmp(*this);
	(*this) += 1;//调用+=运算符重载函数
	return tmp;
}
Date& Date::operator++ ()  //前置++
{
	(*this) += 1;
	return *this;
}
Date Date::operator-- (int)  //后置--
{
	Date tmp(*this);
	(*this) -= 1;
	return tmp;
}

Date& Date::operator-- ()  //前置--
{
	(*this) -= 1;
	return *this;
}

int Date::operator- (const Date& d)    //计算两个日期相差的天数
{
	Date tmp = *this;
	Date ret = d;
	int day = 0, flag = 0;
	if (tmp < ret)
	{
		tmp = d;
		ret = *this;
		flag = 1;
	}//tmp是较大的日期，ret是较小的日期
	while (ret != tmp)
	{
		ret += 1;
		day++;
	}
	if (flag)
	{//说明*this比d小，相减的天数应为负数
		day = -day;
	}
	return day;
}