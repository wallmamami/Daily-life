//#include <iostream>
//#pragma warning (disable:4996)
//using namespace std;

//class A
//{
//private:
//	void* operator new(size_t size)
//	{}
//	void operator delete(void* ptr)
//	{}
//public:
//	A()
//	{}
//	~A()
//	{}
//};

//class String
//{
//public:
//	String(char *ptr = "")
//		:_ptr(new char[strlen(ptr) + 1])
//	{
//		strcpy(_ptr, ptr);
//	}
//
//	String(const String& s)
//		:_ptr(new char[strlen(s._ptr)+1])
//	{
//		strcpy(_ptr, s._ptr);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char *pTmp = new char[strlen(s._ptr) + 1];
//			strcpy(pTmp, s._ptr);
//			delete[] _ptr;
//			_ptr = pTmp;
//		}
//
//		return *this;
//	}
//
//private:
//	char *_ptr;
//};
//
//template<typename T1, typename T2>
//class Data<T1*, T2*>
//{
//	T1 d1;
//	T2 d2;
//	T1* d3;
//	T2* d4;
//}


#include <iostream>
using namespace std;


struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template <class T>
struct TypeTraits
{
	typedef FalseType PodType;
};

template <>
struct TypeTraits<int>
{
	typedef TrueType PodType;
};

template <>
struct TypeTraits<char>
{
	typedef TrueType PodType;
};

template <>
struct TypeTraits<float>
{
	typedef TrueType PodType;
};

template <>
struct TypeTraits<double>
{
	typedef TrueType PodType;
};

class A
{
	int a;
};


class A
{
public:
	static A* Create()
	{
		return new A;
	}
	static void DestTroy(A* pa)
	{
		if (pa != NULL)
			delete pa;
	}
private:
	A()
	{}
	~A()
	{}
};

class B :public A
{
public:
	int _b;
};
int main()
{
	A* pa = A::Create();
	A::DestTroy(pa);
	B b;
	/*if (TypeTraits<A>::PodType::Get())
	{
	cout << "int" << endl;
	}
	else
	cout << "false" << endl;*/

	/*const int a = 10;
	int *p = const_cast<int *>(&a);*/


	/*auto_ptr<int> ptr(new int);*/
	return 0;
}