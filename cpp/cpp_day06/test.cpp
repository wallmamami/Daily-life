#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base::Base()" << endl;
	}
	void SetDate(int a = 10, int b = 20)
	{
		_a = a;
		_b = b;
	}
	void PrintDate()
	{
		cout << "_a = " << _a << endl;
		cout << "_b = " << _b << endl;
	}

	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
protected:
	int _a;

private:
	int _b;
};

class Derived :public Base
{
public:
	Derived()//进入之后先在初始化列表中调用基类的构造函数
		:_d(10)
	{
		_a = 10;//派生类中可以访问基类中的protected成员
		//_b = 20;//派生类中不可以访问基类中的private成员
	}

	~Derived()
	{
		//在销毁时，满足先创建的后销毁，所以在执行完派生类的代码后，再去调用激烈的析构函数
	}

private:
	int _d;
};


int main()
{
	Derived d;
	cout << sizeof(d) << endl;

	return 0;
}