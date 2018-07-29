#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.length();

		if (len <= 0 || n <= 0 || n > len)
			return (string)0;

		//1��תǰ��n���ַ�����2��תʣ�µ��ַ�����3������ת
		Reverse(str, 0, n - 1);//����ұ�
		Reverse(str, n, len - 1);
		Reverse(str, 0, len - 1);

		return str;
	}

	void Reverse(string& str, int begin, int end)
	{
		if (begin < 0 || end >= str.length())
			return;

		while (begin <= end)
		{
			char tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;

			++begin, --end;
		}
	}
};


int main()
{
	string s = "abcXYZdef";

	Solution S;
	cout << S.LeftRotateString(s, 3) << endl;

	return 0;
}