//#include <iostream>
//#include <string>
//using namespace std;
//
//struct FalseType
//{
//	static bool Get()
//	{
//		return false;
//	}
//};
//
//struct TrueType
//{
//	static bool Get()
//	{
//		return true;
//	}
//};
//
//template<class T>
//struct TypeTraits
//{
//	typedef FalseType PODTYPE;
//};
//
//template<>
//struct TypeTraits<int>
//{
//	typedef TrueType PODTYPE;
//};
//
//template<>
//struct TypeTraits<char>
//{
//	typedef TrueType PODTYPE;
//};
//
//template<>
//struct TypeTraits<double>
//{
//	typedef TrueType PODTYPE;
//};
//
//template<>
//struct TypeTraits<float>
//{
//	typedef TrueType PODTYPE;
//};
//
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	// T是否为内置类型--通过类模板的特化来实现的
//	if (TypeTraits<T>::PODTYPE::Get())
//	{
//		// memcpy是浅拷贝
//		memcpy(dst, src, sizeof(T)*size);
//	}
//	else
//	{
//		for (size_t i = 0; i < size; ++i)
//			dst[i] = src[i];
//	}
//}
//
//
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int array2[sizeof(array1) / sizeof(array1[0])];
//
//	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]));
//
//
//	string str1[] = { "1111", "2222", "3333", "4444" };
//	string str2[4];
//	Copy(str2, str1, sizeof(str1) / sizeof(str1[0]));
//
//	return 0;
//}



#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)
using namespace std;

class String
{
	friend ostream& operator<<(ostream& os, String& str);

public:
	String(char* str = "")
		: _str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (_str != s._str)
		{
			String sTmp(s);

			char* pTmp = sTmp._str;
			sTmp._str = _str;//将当前对象的空间交给tmp，让其调用析构函数释放该空间
			_str = pTmp;
		}

		return *this;
	}

	char& operator[](size_t index)
	{
		return _str[index];
	}

	const char& operator[](size_t index)const//[]操作符必须成对重载
	{
		return _str[index];
	}

	~String()
	{
		if (_str != NULL)
		{
			delete[] _str;
			_str = NULL;
		}
	}
private:
	char* _str;
};

ostream& operator<<(ostream& os, String& str)
{
	os << str._str;
	return os;
}


int main()
{
	String s1;
	String s2("hello");
	String s3(s2);
	
	String s4("world");

	s4 = s3;

	cout << s4[5] << endl;
	cout << s4 << endl;

	return 0;
}