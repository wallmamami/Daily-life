#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;


//class String
//{
//public:
//	String(const char* ptr = "")//���캯��,ȱʡ��'\0'
//		:_ptr(new char[strlen(ptr) + 1])//strlen������ĳ��Ȳ���\0
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
//			_str = new char[4+1];//������һ��int�����洢������
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
//		GetCount(_str) = 1;//����������ʼֵ����Ϊ1
//	}
//
//	String(const String& s)//��������
//		:_str(s._str)
//	{
//		GetCount(_str)++;
//	}
//
//	//s1=s2
//	String& operator=(const String& s)//��ֵ����������
//	{
//		if (_str != s._str)
//		{
//			//1.��s1�����ü���Ϊ1ʱ
//			//���ͷſռ�
//			//�ڸı�s1ָ���ָ��
//			//��s2�����ü�����1
//			Release();
//			//��s1�����ü�������1ʱ
//			//��s1�����ü�����1
//			//ͬ�Ϣڢ�
//
//			_str = s._str;
//			++GetCount(_str);//���ü���+1
//		}
//
//		return *this;
//	}
//
//	~String()//��������
//	{
//		Release();
//	}
//
//private:
//	int& GetCount(char* str)
//	{
//		return *(int*)(str - 4);//��Ϊ����ڴ�����Ϊchar
//	}
//
//	void Release()
//	{
//		if (_str != NULL && (--GetCount(_str)) == 0)
//		{
//			delete [](_str - 4);//һ��Ҫ�ͷŴ洢�������Ŀռ�
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
//			_str = new char[4 + 1];//������һ��int�����洢������
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
//		GetCount() = 1;//����������ʼֵ����Ϊ1
//	}
//
//	String(const String& s)//��������
//		:_str(s._str)
//	{
//		GetCount()++;
//	}
//
//	//s1=s2
//	String& operator=(const String& s)//��ֵ����������
//	{
//		if (_str != s._str)
//		{
//			Release();
//
//			_str = s._str;
//			++GetCount();//���ü���+1
//		}
//
//		return *this;
//	}
//
//	char& operator[](size_t index)//���Բ����±�ķ�ʽ����String��
//	{
//		if (GetCount() > 1)
//		{
//			--GetCount();
//			char* pTmp = new char[strlen(_str) + 1 + 4];
//			pTmp += 4;
//			strcpy(pTmp, _str);
//			_str = pTmp;
//			GetCount() = 1;//���¿ռ�ֵ��1
//		}
//
//		return _str[index];
//	}
//
//	const char& operator[](size_t index)const//[]����������ɶ�����
//	{
//		return _str[index];
//	}
//
//	~String()//��������
//	{
//		Release();
//	}
//
//private:
//	int& GetCount()
//	{
//		return *(int*)(_str - 4);//��Ϊ����ڴ�����Ϊchar
//	}
//
//	void Release()
//	{
//		if (_str != NULL && (--GetCount()) == 0)
//		{
//			delete[](_str - 4);//һ��Ҫ�ͷŴ洢�������Ŀռ�
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

	String(const String& s)//���
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	//��ֵ����������
	//����һ
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];
	//		strcpy(_str, s._str);
	//	}
	//	return *this;//Ϊ��֧����ʽ����
	//}

	//���������ţ�
	String& operator=(const String& s)
	{
		if (this != &s)//�Լ����ܿ����Լ�
		{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
		}
		return *this;//Ϊ��֧����ʽ����
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


