//#include <iostream>
//using namespace std;


//class B
//{
//public:
//	virtual void TestFunc()
//	{
//		cout << "Base::TestFunc()" << endl;
//	}
//	int _b;
//};
//
//int main()
//{
//	B b;
//	cout << sizeof(B) << endl;
//
//	return 0;
//}

//class B
//{
//public:
//	virtual void TestFunc()//加virtual关键字，成员函数将作为虚函数
//	{
//		cout << "Base::TestFunc()" << endl;
//	}
//
//};
//
//class D : public B
//{
//public:
//	virtual void TestFunc()//派生类中对虚函数进行重写，函数名、返回值、参数列表必须一致，
//		                   //在重写时，派生类中的访问限定符不会对虚函数有什么影响，且可以不加virtual关键字
//	{
//		cout << "Derived::TestFunc()" << endl;
//	}
//};
//
//void Test(B& b)//通过基类的引用调用虚函数
//{
//	b.TestFunc();
//}
//
//int main()
//{
//	D d;
//	B b;
//
//	Test(d);
//	Test(b);
//
//	return 0;
//}




//class B
//{
//public:
//	virtual void TestFunc()//加virtual关键字，成员函数将作为虚函数
//	{
//		cout << "Base::TestFunc()" << endl;
//	}
//
//	int _b;
//};
//
//class D : public B
//{
//public:
//	virtual void TestFunc()
//	{
//		cout << "Derived::TestFunc()" << endl;
//	}
//
//	int _d;
//};
//
//typedef void(*PTF)();//函数指针
//
//void PintPTF(B& b)//用来调用虚表中的虚函数
//{
//	PTF* ptr = (PTF*)(*(int*)(&b));//因为虚表的地址放基类对象的前四个字节，所以强转为(int*)
//
//	while (*ptr)//因为vs中虚表是以0结束，所以可以作为判定条件
//	{
//		(*ptr)();
//		ptr++;
//	}
//
//	cout << endl;
//}
//
//
//int main()
//{
//	D d;
//	d._b = 1;
//	d._d = 2;
//
//	cout << sizeof(d) << endl;
//	PintPTF(d);
//
//	return 0;
//}


//class B1
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "Base1::TestFunc1()" << endl;
//	}
//
//	int _b1;
//};
//
//class B2
//{
//public:
//	virtual void TestFunc2()
//	{
//		cout << "Base2::TestFunc2()" << endl;
//	}
//
//	int _b2;
//};
//
//class D: public B1, public B2
//{
//public:
//	virtual void TestFunc1()//对B1中的虚函数TestFunc1重写
//	{
//		cout << "Derived::TestFunc1()" << endl;
//	}
//
//	virtual void TestFunc2()
//	{
//		cout << "Derived::TestFunc2()" << endl;//对B2中的虚函数TestFunc2重写
//	}
//
//	virtual void TestFunc3()//派生类自己特有的虚函数
//	{
//		cout << "Derived::TestFunc3()" << endl;
//	}
//
//
//	int _d;
//};
//
//
//int main()
//{
//	D d;
//	d._b1 = 1;
//	d._b2 = 2;
//	d._d = 3;
//
//	cout << sizeof(D) << endl;
//
//	return 0;
//}

#include <stdio.h>

int main()
{
	int arr[5] = { 0, 1, 2, 3, 4 };
	printf("arr = %x\n&arr = %x\n", arr, &arr);

	return 0;
}