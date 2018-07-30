#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;


//int main()
//{
//	string s1 = "abcdef";
//	cout << s1.length() << endl;
//
//	cout << s1.back() << endl;
//	s1.pop_back();
//	cout << s1.length() << endl;
//	cout << s1.front() << endl;
//
//
//	return 0;
//}


//class Solution {
//public:
//	string ReverseSentence(string str) {
//		int len = str.length();
//		string s;
//		if (len <= 0)
//			return s;
//
//		int i = 0;
//
//		for (; i < len; ++i)
//		{
//			char c = str.back();
//			s.push_back(c);
//			str.pop_back();
//		}
//
//		return s;
//	}
//};


//class Solution {
//public:
//	string ReverseSentence(string str) {
//		//���ȷ�ת���壬Ȼ��תÿ������
//
//		int len = str.length();
//		string s;
//		if (len <= 0)
//			return s;
//
//		//1.��ת����
//		Reverse(str, 0, len - 1);
//		int start = 0;
//		int end = 0;
//		bool flag = false;
//
//		while (end < len && start < len)
//		{
//			if (str[end] != ' ')
//			{
//				if (flag)
//					end++;
//				else
//				{
//					flag = true;
//					end++;
//				}
//			}
//
//			if ((flag && str[end] == ' ') || (flag && end == len - 1))
//			{
//				if (str[end] == ' ')
//					end = end - 1;
//				Reverse(str, start, end);
//				flag = false;
//				start = end + 2;
//				end = start;
//			}
//		}
//
//		return str;
//	}
//
//	void Reverse(string& str, int begin, int end)//����ұ�
//	{
//
//		while (begin < end)
//		{
//			char tmp = str[begin];
//			str[begin] = str[end];
//			str[end] = tmp;
//
//			++begin, --end;
//		}
//	}
//};

//#include <vector>
//
//void CountSort(vector<int>& arr)
//{
//	int MinData = arr[0];
//	int MaxData = arr[0];
//	int size = arr.size();
//
//	int i = 0;
//	for (i = 0; i < size; ++i)
//	{
//		if (arr[i] < MinData)
//			MinData = arr[i];
//		if (arr[i] > MaxData)
//			MaxData = arr[i];
//	}
//
//	//���������Сֵ�������Χ
//	int range = MaxData - MinData + 1;
//
//	//���ݷ�Χ����ռ�
//	vector<int> Count(range, 0);
//
//	for (i = 0; i < size; ++i)//�������������е����ݶ�ӦCount������±ֵ꣬+1
//		++Count[arr[i] - MinData];
//
//	int index = 0;
//	//��������ڰ��˵�ԭ����
//	for (i = 0; i < range; ++i)
//	{
//		while (Count[i]--)
//			arr[index++] = i + MinData;
//	}
//}
//
//int main()
//{
//	
//	vector<int> arr = { 9, 2, 3, 5, 1, 0 };
//	CountSort(arr);
//
//	int i = 0;
//	for (i = 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}


//class Solution {
//public:
//	bool IsContinuous(vector<int> numbers) {
//		//numbers���ǳ鵽��5���ƣ��ж���5�����Ƿ�����
//
//		//0�����С�������Դ����κ�����
//		//�ȶ������������
//		CountSort(numbers);
//		int size = numbers.size();
//
//		if (size < 5)
//			return false;
//		//ͳ�Ƴ�0�ĸ������������ԡ����������1�� 3�� 4�� 5����1��3���Ǽ��1����Ҳ���Ǳ�����һ��0������С��������������
//		int countzero = 0;
//		int i = 0;
//		while (i < size && numbers[i] == 0)//��Ϊ�Ѿ�������,�����Ϊ�˷�ֹ�������
//		{
//			++countzero;
//			++i;
//		}
//
//		//��������������Ԫ�ص��ܼ����
//		int count = 0;
//		int begin = countzero;//�ӵ�һ����Ϊ0�����ݿ�ʼ
//		int end = countzero + 1;
//
//		while (begin < size && end < size)
//		{
//			//����С����ӡ����϶�����������
//			if (numbers[begin] == numbers[end])
//				return false;
//			count += numbers[end] - numbers[begin] - 1;
//			++begin;
//			++end;
//		}
//
//		//���0�ĸ���С�ڼ��������������
//		if (countzero >= count)
//			return true;
//		return false;
//	}
//
//	void CountSort(vector<int>& arr)
//	{
//		int MinData = arr[0];
//		int MaxData = arr[0];
//		int size = arr.size();
//
//		int i = 0;
//		for (i = 0; i < size; ++i)
//		{
//			if (arr[i] < MinData)
//				MinData = arr[i];
//			if (arr[i] > MaxData)
//				MaxData = arr[i];
//		}
//
//		//���������Сֵ�������Χ
//		int range = MaxData - MinData + 1;
//
//		//���ݷ�Χ����ռ�
//		vector<int> Count(range, 0);
//
//		for (i = 0; i < size; ++i)//�������������е����ݶ�ӦCount������±ֵ꣬+1
//			++Count[arr[i] - MinData];
//
//		int index = 0;
//		//��������ڰ��˵�ԭ����
//		for (i = 0; i < range; ++i)
//		{
//			while (Count[i]--)
//				arr[index++] = i + MinData;
//		}
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int> numbers = { 0, 1, 3, 0, 5 };
//
//	cout << s.IsContinuous(numbers) << endl;
//
// 	return 0;
//}


//void CountSort(vector<int>& arr)
//{
//	int MinData = arr[0];
//	int MaxData = arr[0];
//	int size = arr.size();
//
//	int i = 0;
//	for (i = 0; i < size; ++i)
//	{
//		if (arr[i] < MinData)
//			MinData = arr[i];
//		if (arr[i] > MaxData)
//			MaxData = arr[i];
//	}
//
//	//���������Сֵ�������Χ
//	int range = MaxData - MinData + 1;
//
//	//���ݷ�Χ����ռ�
//	vector<int> Count(range, 0);
//
//	for (i = 0; i < size; ++i)//�������������е����ݶ�ӦCount������±ֵ꣬+1
//		++Count[arr[i] - MinData];
//
//	int index = 0;
//	//��������ڰ��˵�ԭ����
//	for (i = 0; i < range; ++i)
//	{
//		while (Count[i]--)
//			arr[index++] = i + MinData;
//	}
//}
//
//int main()
//{
//	vector<int> arr = { 0, 0, 0, 0, 0, 0, 0 };
//
//	CountSort(arr);
//
//	for (int i = 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}


//class Solution {
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		if (n <= 0)
//			return 0;
//
//		list<int> Circle;
//		//���ڵ�嵽������
//		for (int i = 0; i < n; ++i)
//			 Circle.push_back(i);
//
//		list<int>::iterator Cur = Circle.begin();
//
//		while (Circle.size() > 1)
//		{
//			for (int i = 1; i < m; ++i)//ע���Ǵ�1��ʼ���Լ�������ȥ
//			{
//				++Cur;
//				if (Cur == Circle.end())//��Ϊlist���ǻ�����������ÿ���ߵ���������ӿ�ʼ������
//					Cur = Circle.begin();
//
//			}
//			//����Cur���¸��ڵ㣬ɾ��Cur���´ξʹ���һ���ڵ㿪ʼ��
//			list<int>:: iterator next = ++Cur;
//			if (next == Circle.end())
//				next = Circle.begin();
//
//			--Cur;
//			Circle.erase(Cur);
//
//			Cur = next;//һ��Ҫ�����ٸ�Cur��ֵ��֮ǰָ�Ľڵ��Ѿ��ͷ���
//		}
//
//		return Circle.front();
//	}
//};


//class Temp
//{
//public:
//	Temp()
//	{
//		++_n;
//		_sum += _n;
//	}
//
//	int GetSum()
//	{
//		return _sum;
//	}
//private:
//	static int _n;
//	static int _sum;
//};
//
//int Temp::_n = 0;
//int Temp::_sum = 0;
//
//class Solution {
//public:
//
//	int Sum_Solution(int n) {
//		//���ù��캯��������Ҫ�ۼӵ����ַŵ����캯���У�Ȼ�󴴽�n���ö��󣬾Ϳ���
//		Temp* t = new Temp[n];
//		int sum = t->GetSum();
//		delete[]t;//�ǵ�Ҫ�ͷſռ�
//		t = NULL;
//
//		return sum;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.Sum_Solution(5) << endl; 
//
//	return 0;
//}


int main()
{
	cout << sizeof(long) << endl;
	string s;
	cout << s.size() << endl;

	return 0;
}