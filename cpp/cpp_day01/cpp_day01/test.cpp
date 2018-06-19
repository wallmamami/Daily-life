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
//	cin>> a;//这里和c最大的不同就是不用&，与c相同的是如果cin后面有空格，输入也要输入空格
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
//	int& rra = a;//多个引用可以引用同一个实体
//	int& ra = b;//但是引用一旦引用一个实体，就不能再引用其他实体
//
//	cout << a << endl;
//	cout << ra << endl;
//}



//int main()
//{
//	const int a = 10;
//	//int& ra = a; //编译时会出错，因为a是常量
//	
//	const int& ra = a;//如果a是常量，要引用的话，必须加const
//	const int& rb = 10;//10也是常量，所以也要加cosnt
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
//	int (&ra)[10] = a;//引用一个数组
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
//int a = 1000;//全局变量
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
//	cout << a << endl;//不加命名空间名的话，按照就近原则
//	cout << N1::a << endl;//访问N1命名空间中的a
//	cout << N2::a << endl;
//	cout << ::a << endl;//访问全局命名空间中的a
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
//using namespace N1;//将命名空间N1中的所有成员全局化
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
//	student s1;//这里再定义结构体变量时不像c语言那样还要加struct
//	s1.age = 10;
//	student2 s2;
//	s2.age = 20;//这里编译器会报错
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

	s1.SetStudentInfo("王二狗", "女", 12);
	s2.SetStudentInfo("哈哈", "男", 8);
	s3.SetStudentInfo("呵呵", "男", 9);

	cout << sizeof(s1) << endl;

	return 0;
}






