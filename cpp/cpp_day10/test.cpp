#include <iostream>
using namespace std;

//class B
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "B::TestFunc1()" << endl;
//	}
//	virtual void TestFunc2()
//	{
//		cout << "B::TestFunc2()" << endl;
//	}
//
//	virtual void TestFunc3()
//	{
//		cout << "B::TestFunc3()" << endl;
//	}
//
//	int _b;
//};
//
//class C1 : public B
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "C1::TestFunc1()" << endl;
//	}
//	int _c1;
//};
//
//class C2 : public B
//{
//public:
//	virtual void TestFunc2()
//	{
//		cout << "B::TestFunc2()" << endl;
//	}
//
//	int _c2;
//};
//
//class D : public C1, public C2
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "D::TestFunc()" << endl;
//	}
//
//	int _d;
//};
//
//int main()
//{
//	D d;
//	cout << sizeof(D) << endl;
//
//	return 0;
//}

//class B
//{
//public:
//	virtual void TestFunc()
//	{
//		cout << "B::TestFunc()" << endl;
//	}
//
//	int _b;
//};
//
//class D : virtual public B
//{
//public:
//	virtual void TestFunc()
//	{
//		cout << "D::TestFunc()" << endl;
//	}
//
//	int _d;
//};
//
//int main()
//{
//	D d;
//	
//	cout << sizeof(D) << endl;
//	d._b = 1;
//	d._d = 2;
//
//	return 0;
//}

//class B
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "B::TestFunc1()" << endl;
//	}
//
//	int _b;
//};
//
//class D : virtual public B
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "D::TestFunc1()" << endl;
//	}
//	virtual void TestFunc2()
//	{
//		cout << "D::TestFunc2()" << endl;
//	}
//
//	int _d;
//};
//
//int main()
//{
//	D d;
//
//	cout << sizeof(D) << endl;
//	d._b = 1;
//	d._d = 2;
//
//	return 0;
//}

//class B
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "B::TestFunc1()" << endl;
//	}
//
//	virtual void TestFunc2()
//	{
//		cout << "B::TestFunc2()" << endl;
//	}
//
//	virtual void TestFunc3()
//	{
//		cout << "B::TestFunc3()" << endl;
//	}
//
//	int _b;
//};
//
//class C1 : virtual public B
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "C1::TestFunc1()" << endl;
//	}
//	int _c1;
//};
//
//class C2 : virtual public B
//{
//public:
//	virtual void TestFunc2()
//	{
//		cout << "C2::TestFunc2()" << endl;
//	}
//	int _c2;
//};
//
//class D : public C1, public C2
//{
//public:
//	virtual void TestFunc3()
//	{
//		cout << "D::TestFunc3()" << endl;
//	}
//
//	int _d;
//};
//
//
//int main()
//{
//	D d;
//
//	cout << sizeof(C1) << endl;
//	cout << sizeof(D) << endl;
//	d._b = 1;
//	d._c1 = 2;
//	d._c2 = 3;
//	d._d = 4;
//
//	return 0;
//}


class B
{
public:
	B()
		:_b(1)
	{
		cout << "B::B()" << endl;
	}

	virtual ~B()
	{
		cout << "B::~B()" << endl;
	}
	int _b;
};

class D: public B
{
public:
	D()
		:_ptr(new char[10])
	{
		cout << "D::D()" << endl;
	}

	virtual ~D()
	{
		if (_ptr)
		{
			delete[] _ptr;
		}

		cout << "D::~D()" << endl;
	}

	char* _ptr;
};

void TestFunc()
{
	B* pb;

	pb = new D;//���ڸ�ֵ���ݹ��򣬻���ָ�����ָ���������������ͻ����D�Ĺ��캯������ռ�
	delete pb;//�����ǻ������͵�ָ�룬����deleteֻ����û������������������ͻ�����ڴ�й©
}

int main()
{
	TestFunc();

	return 0;
}