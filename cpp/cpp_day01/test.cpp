//#include <iostream> 
//#include <string>
//using namespace std; 

//int main()
//{
//	int a = 10;
//	char b = 'c';
//	char arr[] = "abcdef";
//
//	cout << a << " " << b << endl;
//	cout << arr << endl;
//
//}

//int main()
//{
//	int a = 0;
//
//	cin>> a;//�����c���Ĳ�ͬ���ǲ���&����c��ͬ�������cin�����пո�����ҲҪ����ո�
//	cout << a << " "<< endl;
//	
//
//}

//void func(char a)
//{
//
//}
//void func(int a)
//{
//	cout << "a = "<< a << endl;
//	cout << "b = "<< b << endl;
//	cout << "b = "<< c << endl;
//	return;
//}
//
//int main()
//{
//	//func();
//	func(10);
//	return 0;
//}

//int add(int left, int right)
//{
//	return left + right;
//}
//double add(double left, double right)
//{
//	return left + right;
//}
//
//long add(long left, long right)
//{
//	return left + right;
//}
//
//int main()
//{
//	add(10, 20);
//	add(10.0, 20.0);
//	add(10l, 20l);
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& ra = a;
//	int& rra = a;//������ÿ�������ͬһ��ʵ��
//	int& ra = b;//��������һ������һ��ʵ�壬�Ͳ�������������ʵ��
//
//	cout << a << endl;
//	cout << ra << endl;
//}



//int main()
//{
//	const int a = 10;
//	//int& ra = a; //����ʱ�������Ϊa�ǳ���
//	
//	const int& ra = a;//���a�ǳ�����Ҫ���õĻ��������const
//	const int& rb = 10;//10Ҳ�ǳ���������ҲҪ��cosnt
//
//}


//void Swap(int& ra, int& rb)
//{
//	int tmp = 0;
//
//	tmp = ra;
//	ra = rb;
//	rb = tmp;
//}
//
//int main()
//{
//	int i = 0;
//	int a[10] = { 0 };
//	int b = 20;
//	int (&ra)[10] = a;//����һ������
//
//	for (; i < 10; i++)
//		cout << ra[i] << " ";
//	cout << endl;
//
//	return 0;
//}

//int& add(int& ra)
//{
//	ra += 10;
//	return ra;
//}
//
//int main()
//{
//	int a = 10;
//	add(a);
//
//	cout << a << endl;
//
//	return 0;
//}

//int add(int& left, int& right)
//{
//	return left + right;
//}
//
//int add(int* left, int* right)
//{
//	return *left + *right;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int& ra = a;
//	 int* const pa = &a;
//
//	pa = &b;
//}

//int main()
//{
//	int a = 10;
//	int& ra = NULL;
//}


//#include <iostream>
//using namespace std;
//
//int a = 1000;//ȫ�ֱ���
//
//namespace N1
//{
//	int a = 10;
//}
//
//namespace N2
//{
//	int a = 1;
//}
//
//int main()
//{
//	int a = 100;
//
//	cout << a << endl;//���������ռ����Ļ������վͽ�ԭ��
//	cout << N1::a << endl;//����N1�����ռ��е�a
//	cout << N2::a << endl;
//	cout << ::a << endl;//����ȫ�������ռ��е�a
//
//	return 0;
//}



//#include <iostream>
//using namespace std;

//namespace N1
//{
//	int a = 10;
//	int b = 20;
//
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//}
//
//using namespace N1;//�������ռ�N1�е����г�Աȫ�ֻ�
//
//namespace N2
//{
//	void print()
//	{
//		cout << a << endl;
//	}
//}
//
//int main()
//{
//	cout << a << endl;
//	cout << "a + b = " << add(a, b) <<endl;
//}


//#include <iostream>
//using namespace std;


//struct student
//{
//	char name[20];
//	char gender[3];
//	int age;
//};
//
//class student2
//{
//	char name[20];
//	char gender[3];
//	int age;
//
//	int add(int left, int right)
//	{
//		return left + right;
//	}
//};
//
//int main()
//{
//	student s1;//�����ٶ���ṹ�����ʱ����c����������Ҫ��struct
//	s1.age = 10;
//	student2 s2;
//	s2.age = 20;//����������ᱨ��
//
//}



#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;


class student
{
public:
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

private:
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	student s1, s2, s3;

	s1.SetStudentInfo("������", "Ů", 12);
	s2.SetStudentInfo("����", "��", 8);
	s3.SetStudentInfo("�Ǻ�", "��", 9);

	cout << sizeof(s1) << endl;

	return 0;
}






