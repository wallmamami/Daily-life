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
	Derived()//����֮�����ڳ�ʼ���б��е��û���Ĺ��캯��
		:_d(10)
	{
		_a = 10;//�������п��Է��ʻ����е�protected��Ա
		//_b = 20;//�������в����Է��ʻ����е�private��Ա
	}

	~Derived()
	{
		//������ʱ�������ȴ����ĺ����٣�������ִ����������Ĵ������ȥ���ü��ҵ���������
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