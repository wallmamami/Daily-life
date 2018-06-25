#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;


//class String
//{
//public:
//	String(const char* ptr = "")//构造函数,缺省放'\0'
//		:_ptr(new char[strlen(ptr) + 1])//strlen计算出的长度不加\0
//	{
//		strcpy(_ptr, ptr);
//	}
//
//	~String()
//	{
//		if (_ptr)
//		{
//			cout << "~String()" << this << endl;
//			delete[] _ptr;
//		}
//	}
//
//private:
//	char* _ptr;
//};
//
//int main()
//{
//	String s1("hello");
//	String s2(s1);
//
//	return 0;
//}



//class String
//{
//public:
//	String()
//	{}
//
//	String(const char* str )
//	{
//		if (str == NULL)
//		{
//			_str = new char[4+1];//多申请一个int用来存储计数器
//			_str += 4;
//			_str = '\0';
//		}
//		else
//		{
//			_str = new char[strlen(str) + 1 + 4];
//			_str += 4;
//			strcpy(_str, str);
//		}
//
//		GetCount(_str) = 1;//将计数器初始值设置为1
//	}
//
//	String(const String& s)//拷贝构造
//		:_str(s._str)
//	{
//		GetCount(_str)++;
//	}
//
//	//s1=s2
//	String& operator=(const String& s)//赋值操作符重载
//	{
//		if (_str != s._str)
//		{
//			//1.当s1的引用计数为1时
//			//①释放空间
//			//②改变s1指针的指向
//			//③s2的引用计数加1
//			Release();
//			//当s1的引用计数大于1时
//			//①s1的引用计数减1
//			//同上②③
//
//			_str = s._str;
//			++GetCount(_str);//引用计数+1
//		}
//
//		return *this;
//	}
//
//	~String()//析构函数
//	{
//		Release();
//	}
//
//private:
//	int& GetCount(char* str)
//	{
//		return *(int*)(str - 4);//因为这块内存类型为char
//	}
//
//	void Release()
//	{
//		if (_str != NULL && (--GetCount(_str)) == 0)
//		{
//			delete [](_str - 4);//一定要释放存储计数器的空间
//		}
//	}
//
//private:
//	char* _str;
//};
//
//
//int main()
//{
//	String s1("hello");
//	String s2(s1);
//	
//	String s3("world");
//	String s4(s3);
//	String s5(s3);
//
//	s1 = s3;
//
//}


//class String
//{
//public:
//	String()
//	{}
//
//	String(const char* str)
//	{
//		if (str == NULL)
//		{
//			_str = new char[4 + 1];//多申请一个int用来存储计数器
//			_str += 4;
//			_str = '\0';
//		}
//		else
//		{
//			_str = new char[strlen(str) + 1 + 4];
//			_str += 4;
//			strcpy(_str, str);
//		}
//
//		GetCount() = 1;//将计数器初始值设置为1
//	}
//
//	String(const String& s)//拷贝构造
//		:_str(s._str)
//	{
//		GetCount()++;
//	}
//
//	//s1=s2
//	String& operator=(const String& s)//赋值操作符重载
//	{
//		if (_str != s._str)
//		{
//			Release();
//
//			_str = s._str;
//			++GetCount();//引用计数+1
//		}
//
//		return *this;
//	}
//
//	char& operator[](size_t index)//可以采用下标的方式访问String类
//	{
//		if (GetCount() > 1)
//		{
//			--GetCount();
//			char* pTmp = new char[strlen(_str) + 1 + 4];
//			pTmp += 4;
//			strcpy(pTmp, _str);
//			_str = pTmp;
//			GetCount() = 1;//将新空间值赋1
//		}
//
//		return _str[index];
//	}
//
//	const char& operator[](size_t index)const//[]操作符必须成对重载
//	{
//		return _str[index];
//	}
//
//	~String()//析构函数
//	{
//		Release();
//	}
//
//private:
//	int& GetCount()
//	{
//		return *(int*)(_str - 4);//因为这块内存类型为char
//	}
//
//	void Release()
//	{
//		if (_str != NULL && (--GetCount()) == 0)
//		{
//			delete[](_str - 4);//一定要释放存储计数器的空间
//		}
//	}
//
//private:
//	char* _str;
//};
//
//
//int main()
//{
//	String s1("hello");
//	String s2(s1);
//	String s3(s1);
//	s3[1] = 'a';
//
//	return 0;
//}



class String
{
public:

	String(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	String(const String& s)//深拷贝
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	//赋值操作符重载
	//方法一
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];
	//		strcpy(_str, s._str);
	//	}
	//	return *this;//为了支持链式访问
	//}

	//方法二（优）
	String& operator=(const String& s)
	{
		if (this != &s)//自己不能拷贝自己
		{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
		}
		return *this;//为了支持链式访问
	}

	~String()
	{
		if (_str != NULL)
		{
			delete[]_str;
		}
	}

private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2(s1);

	String s3("world");
	s1 = s3;
}


