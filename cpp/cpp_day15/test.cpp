//#include <iostream>
//#include <vector>
//
//using namespace std;

//int main()
//{
//	std::vector<int> foo(3, 100);   // three ints with a value of 100
//	std::vector<int> bar(5, 200);   // five ints with a value of 200
//
//	foo.swap(bar);
//
//	std::cout << "foo contains:";
//	for (unsigned i = 0; i<foo.size(); i++)
//		std::cout << ' ' << foo[i];
//	std::cout << '\n';
//
//	std::cout << "bar contains:";
//	for (unsigned i = 0; i<bar.size(); i++)
//		std::cout << ' ' << bar[i];
//	std::cout << '\n';
//
//	return 0;
//}


//void ShellSort(vector<int>& v)
//{
//	int size = v.size();
//	int gap = size;
//	
//	while (gap > 1)
//	{
//		gap = gap / 3 - 1;
//		int i = gap;
//
//		for (; i < size; ++i)
//		{
//			int end = i - 1;
//			int key = v[i];
//
//			while (end >= 0 && key < v[end])
//			{
//				v[end + gap] = v[end];
//				end -= gap;
//			}
//			v[end + gap] = key;
//		}
//	}
//
//	int i = 0;
//	for (; i < size; ++i)
//		cout << " " << v[i];
//	cout << endl;
//}
//
//void swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//void SelectSort(vector<int>& v)
//{
//	int size = v.size();
//	int start = 0;
//	int end = v.size()-1;
//
//	while (start < end)
//	{
//		int minPos = start;
//		int maxPos = start;
//		int j = start + 1;
//
//		while (j <= end)
//		{
//			if (v[maxPos] < v[j])
//				maxPos = j;
//			if (v[minPos] > v[j])
//				minPos = j;
//			j++;
//		}
//
//		if (maxPos != end)
//			swap(v[maxPos], v[end]);
//
//		if (minPos == end)
//			minPos = maxPos;
//
//		if (minPos != start)
//			swap(v[minPos], v[start]);
//
//		++start;
//		--end;
//	}
//
//	int i = 0;
//	for (; i < size; ++i)
//		cout << " " << v[i];
//	cout << endl;
//}
//int main()
//{
//	vector<int> v = { 1, 5, 3, 8, 4, 0 };
//
//	ShellSort(v);
//	SelectSort(v);
//
//	return 0;
//}


//#include <iostream>
//#include <stack>
//using namespace std;
//
//class Solution
//{
//public:
//	void push(int node) {
//		//stack1用来插入元素
//		stack1.push(node);
//	}
//
//	int pop() {
//		//stack2用来出队列
//		int top = 0;
//		if (stack2.size() == 0)
//		{
//			if (stack1.size() == 0)
//			{
//				std::cout << "队列为空" << endl;
//				return -1;
//			}
//
//			else
//			{
//				int i = 0;
//				for (; i <= stack1.size(); ++i)
//				{
//					//将stack1中的元素搬移到stack2
//					stack2.push(stack1.top());
//					stack1.pop();
//				}
//			}
//		}
//		top = stack2.top();
//		stack2.pop();
//		return top;
//	}
//
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};
//
//int main()
//{
//	Solution q;
//	q.pop();
//	q.push(1);
//	q.push(2);
//	cout << q.pop() << endl;
//	q.push(3);
//	cout << q.pop() << endl;
//	q.push(4);
//
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		int size = rotateArray.size();
//		vector<int>& v = rotateArray;
//		if (size <= 0)
//			return 0;
//		int left = 0;
//		int right = size - 1;
//		int mid = left;
//
//		while (v[left] >= v[right])//避免旋转之后还是原来的1，2，3， 4， 5
//		{
//			if (right - left == 1)
//			{
//				mid = right;
//				break;
//			}
//			mid = (left + right) / 2;
//			//有可能数组里面有重复的数字或者只有一个数字
//			//这种情况只能顺序查找，如1，1，1，1，0，1
//			if (v[left] == v[mid] && v[mid] == v[right])
//			{
//				return MinNumber(v, left, right);
//			}
//			if (v[mid] >= v[left])//说明mid在值较大的子数组里面
//				left = mid;
//			else if (v[mid] <= v[right])
//				right = mid;
//		}
//		return v[mid];
//	}
//
//	int MinNumber(vector<int> v, int left, int right)
//	{
//		int i = left;
//		int min = v[left];
//		for (; i <= right; ++i)
//		{
//			if (v[i] < min)
//				min = v[i];
//		}
//		return min;
//	}
//
//};
//
//
//int main()
//{
//	Solution s;
//
//	vector<int> v = { 3, 4, 5, 1, 2 };
//	cout << s.minNumberInRotateArray(v) << endl;
//
//	return 0;
//}

//#include <iostream>
////using namespace std;
//
//class Solution {
//public:
//	int  NumberOf1(int n) {
//		int count = 0;
//		unsigned int flag = 1;
//		//while (n)//如果n是负数，就会造成死循环，因为负数在右移的时候最高为回补符号位(1)
//		while (flag)//fla移32次就变成0了
//		{
//			//if (n&1)
//			if (n & flag)
//				count++;
//			flag <<= 1;
//		}
//		return count;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	std::cout << s.NumberOf1(1) << std::endl;
// 	std::cout << s.NumberOf1(-1) << std::endl;
//
//	return 0;
//}



//#include <stdio.h>
//#include <malloc.h>
//
//
//int main()
//{
//	char* p, *q;
//	p = (char*)malloc(sizeof(char)* 20);
//	q = p;
//	scanf("%s%s", p, q);
//	printf("%s %s\n", p, q);
//
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "abcd";
	cout << s.length() << endl;
	cout << s.size() << endl;

	cout << s[0] << endl;

	cout << s[4] << endl;

	return 0;
}