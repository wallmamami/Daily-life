#include <iostream>
using namespace std;


//class Base
//{
//public:
//	void TestFunc()
//	{
//		cout << "Base::TestFunc()" << endl;
//	}
//
//private:
//	int _b;
//};
//
//class Derived :public Base
//{
//public:
//	void TestFunc2()
//	{
//		cout << "Derived:TestFunc()" << endl;
//	}
//private:
//	int _d;
//};
//
//int main()
//{
//
//}

//class Base
//{
//protected:
//	int _b1;
//private:
//	int _b2;
//};
//
//class Derived : public Base
//{
//public:
//	void SetValue()
//	{
//		_b1 = 10;
//		_b2 = 20;
//	}
//};

//class Base
//{
//public:
//	int _b;
//};
//
//class Derived : public Base
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	Derived d;
//	d._b = 10;
//	d._d = 20;
//}

//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base::Base()" << endl;
//	}
//
//	~Base()
//	{
//		cout << "Base::~Base()" << endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	Derived()
//	{
//		cout << "Derived::Derived()" << endl;
//	}
//
//	~Derived()
//	{
//		cout << "Derived::~Derived()" << endl;
//	}
//};
//
//
//void TestFunc()
//{
//	Derived d;
//
//}
//
//int main()
//{
//	TestFunc();
//
//	return 0;
//}

class Base
{
public:
	void Test()
	{
		cout << "Base::Test()" << endl;
	}
	int _b;
	int _a;
};


class Derived : public Base
{
public:
	void Test()
	{
		cout << "Derived::Derived()" << endl;
	}

	int _a;
};


void TestFunc()
{
	Derived d;
	d._a = 10;

	d.Test();
}

int main()
{
	TestFunc();

	return 0;
}