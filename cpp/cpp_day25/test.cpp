#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//int main()
//{
//	auto_ptr<int> ap1(new int);
//	*ap1 = 10;
//
//	if (true)
//	{
//		auto_ptr<int> ap2(ap1);
//		*ap2 = 20;
//	}
//
//	*ap1 = 100;
//
//	return 0;
//}


//void TestAuto(auto_ptr<int> ap1)
//{
//	*ap1 = 20;
//
//	return;
//}
//
//int main()
//{
//	auto_ptr<int> ap1(new int);
//	*ap1 = 10;
//
//	TestAuto(ap1);
//
//	*ap1 = 20;
//
//	return 0;
//}


//void TestShared(shared_ptr<int> spt1)
//{
//	cout << "usecount:" << spt1.use_count() << endl;
//
//	*spt1 = 10;
//	cout << "*spt1 = " << *spt1 << endl;
//
//
//	shared_ptr<int> spt2(spt1);
//	*spt2 = 20;
//	cout << "*spt2 = " << *spt2 << endl;
//	cout << "usecount:" << spt2.use_count() << endl;
//
//	shared_ptr<int> spt3 = spt1;
//	*spt3 = 30;
//	cout << "*spt3 = " << *spt3 << endl;
//	cout << "usecount:" << spt3.use_count() << endl;
//
//	return;
//}
//
//int main()
//{
//	shared_ptr<int> spt1(new int);
//	cout << "usecount:" << spt1.use_count() << endl;
//
//	TestShared(spt1);
//
//	cout << "usecount:" << spt1.use_count() << endl;
//	return 0;
//}

//struct ListNode
//{
//	ListNode()
//	: pNext(NULL)
//	, pPre(NULL)
//	{}
//
//	void test()
//	{
//		cout << "haa" << endl;
//	}
//	shared_ptr<ListNode> pNext;
//	shared_ptr<ListNode> pPre;
//	int data;
//};
//
//
//void Test()
//{
//	shared_ptr<ListNode> p1(new ListNode);
//	shared_ptr<ListNode> p2(new ListNode);
//
//	p1->pNext = p2;
//	p2->pPre = p1;
//	
//	cout << "p1 usecount: " <<p1.use_count() << endl;
//	cout << "p2 usecount: " <<p2.use_count() << endl;
//
//	return;
//}
//int main()
//{
//	Test();
//	ListNode* a = NULL;
//	a->test();
//
//	return 0;
//}
//

//int main()
//{
//	main();
//	return 0;
//}
//
//int main()
//{
//	string s;
//	string s2;
//
//	cin >> s >> s2;
//
//	cout << s << s2 << endl;
//
//	return 0;
//}



//int main()
//{
//	string s;
//	string s2;
//	vector<int> arr(256, 0);
//	cin >> s >> s2;
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		++arr[s[i]];
//	}
//
//	for (int i = 0; i < s2.size(); ++i)
//		--arr[s2[i]];
//
//	s2.clear();
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (arr[s[i]]--)
//			cout << s[i];
//	}
//	cout << endl;
//
//	return 0;
//}


//int main()
//{
//	string s;
//	string s2;
//	vector<int> arr(256, 0);
//	getline(cin, s);
//	getline(cin, s2);
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (arr[s[i]] == 0)
//			++arr[s[i]];
//	}
//
//	for (int i = 0; i < s2.size(); ++i)
//	{
//		if (arr[s2[i]] == 1)
//			--arr[s2[i]];
//	}
//
//	s2.clear();
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (arr[s[i]])
//			cout << s[i];
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> arr;
//	int tmp = 0;
//
//	while (cin >> tmp)
//		arr.push_back(tmp);
//
//	for (int i = 0; i < arr.size(); ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}


int main()
{
	vector<int> A;
	int tmp;
	int n = 0;
	int sum = 0;

	cin >> n >> sum;

	if (n < 1 || n > 1000 || sum < 1 || sum > 100)
		return 0;
	while (n--)
	{
		cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}