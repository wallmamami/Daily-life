#include "Date.h"

ostream& operator<< (ostream& os, const Date& d)//���<<���غ���
{
	os << d._year << "/";
	os << d._month << "/";
	os << d._day << endl;
	return os;
}

/*���ڱȽ�*/
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
	//���ڻ��ߴ��ڶ��Ǵ��ڵ���
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
	if (*this >= d)//ֻҪ���Ǵ��ڵ��ڣ���һ����С��
	{
		return false;
	}

	return true;
}

bool Date::operator<=(const Date& d)
{
	if (*this > d)//ֻҪ���Ǵ��ڣ���һ����С�ڵ���
	{
		return false;
	}

	return true;
}


/*���ڼ���*/
Date Date::operator+(int day)
{
	//�п��ܴ���ֵ
	if (day < 0)
	{
		day = -day;
		return (*this - day);//����-���������
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
	//�п��ܴ���ֵ
	if (day < 0)
	{
		day = -day;
		return (*this+day);//����+���������
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

Date Date::operator++ (int)  //����++
{
	Date tmp(*this);
	(*this) += 1;//����+=��������غ���
	return tmp;
}
Date& Date::operator++ ()  //ǰ��++
{
	(*this) += 1;
	return *this;
}
Date Date::operator-- (int)  //����--
{
	Date tmp(*this);
	(*this) -= 1;
	return tmp;
}

Date& Date::operator-- ()  //ǰ��--
{
	(*this) -= 1;
	return *this;
}

int Date::operator- (const Date& d)    //��������������������
{
	Date tmp = *this;
	Date ret = d;
	int day = 0, flag = 0;
	if (tmp < ret)
	{
		tmp = d;
		ret = *this;
		flag = 1;
	}//tmp�ǽϴ�����ڣ�ret�ǽ�С������
	while (ret != tmp)
	{
		ret += 1;
		day++;
	}
	if (flag)
	{//˵��*this��dС�����������ӦΪ����
		day = -day;
	}
	return day;
}