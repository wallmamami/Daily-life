#include <iostream>
using namespace std;

//class B
//{
//public:
//	int _b;
//};
//
//class C1 :public B
//{
//public:
//	int _c1;
//};
//
//class C2 :public B
//{
//public:
//	int _c2;
//};
//
//class D : public C1, public C2
//{
//public:
//	int _d;
//};
//
//
//int main()
//{
//	D d1;
//	cout<<sizeof(D)<<endl;
//	d1._b = 10;
//
//	return 0;
//}

//class B
//{
//public:
//	int _b;
//};
//
//class D : virtual public B
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d1;
//	d1._b = 10;
//	d1._d = 20;
//
//	return 0;
//}

class B
{
public:
	int _b;
};

class C1: virtual public B
{
public:
	int _c1;
};

class C2: virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	D d1;
	cout << sizeof(D) << endl;
	d1._b = 10;
	d1._c1 = 20;
	d1._c2 = 30;
	d1._d = 40;

	return 0;
}










