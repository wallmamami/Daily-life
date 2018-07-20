//#include <vector>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	vector<int> s;
//	s.push_back(1);
//	s.push_back(2);
//	s.push_back(3);
//	s.push_back(4);
//	s.push_back(5);
//
//	int i = 0;
//	for (; i < s.size(); i++)
//		cout << s[i] << " ";
//	cout << endl;
//
//	//定义迭代器，用来遍历
//	vector<int> ::iterator itor = s.begin();
//	for (; itor != s.end(); itor++)
//		cout << *itor << " ";
//	cout << endl;
//	return 0;
//}
//
//

#include <iostream>
#include <string>
using namespace std;

//void PrintLongest(string& s)
//{
//	string::iterator itor = s.begin();
//	int count1 = 0;
//	int count2 = 0;
//
//	for (; itor < s.end(); itor++)
//	{
//		if ((*itor) + 1 == *(itor + 1))
//			count2++;
//	}
//	
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//
//	cout << s << endl;
//
//	PrintLongest(s);
//	return 0;
//}


//struct ex
//{
//	int x;
//	int y;
//}v1;
//
//int main()
//{
//	struct ex v1 = {5};
//	cout << v1.x << endl;
//
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

bool IsNumbre(char& c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

void max_number_str(string& s)
{
	int size = s.size();
	int i = 0;
	int flag = 0;//用来标记是否是刚遇到数字串
	int Begin = 0;//用来标记最大数字串的首位置
	int begin = 0;
	int end = 0;
	int max = 0;
	for (; i < size; i++)
	{
		if (IsNumbre(s[i]))
		{
			if (flag == 1)
				end = i;
			else//刚进入数字串
			{
				flag = 1;
				begin = i;
			}

		}
		if ((flag == 1 && !IsNumbre(s[i])) || (flag == 1 && i == size-1))//表示从数字串中出来, 或者是最后一个数字类的元素，因为它没机会出来
		{
			flag = 0;
			if (max < end - begin)
			{
				max = end - begin;
				Begin = begin;
			}	
		}
	}
	if (begin != end)//排除全是字符串
	{
		for (i = Begin; i <= Begin + max; i++)
			cout << s[i] << " ";
		cout << endl;
	}
}

int main()
{
	string s;
	cin >> s;
	max_number_str(s);

	return 0;
}
