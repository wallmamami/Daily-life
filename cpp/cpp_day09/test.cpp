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
//	virtual void TestFunc()//��virtual�ؼ��֣���Ա��������Ϊ�麯��
//	{
//		cout << "Base::TestFunc()" << endl;
//	}
//
//};
//
//class D : public B
//{
//public:
//	virtual void TestFunc()//�������ж��麯��������д��������������ֵ�������б����һ�£�
//		                   //����дʱ���������еķ����޶���������麯����ʲôӰ�죬�ҿ��Բ���virtual�ؼ���
//	{
//		cout << "Derived::TestFunc()" << endl;
//	}
//};
//
//void Test(B& b)//ͨ����������õ����麯��
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
//	virtual void TestFunc()//��virtual�ؼ��֣���Ա��������Ϊ�麯��
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
//typedef void(*PTF)();//����ָ��
//
//void PintPTF(B& b)//������������е��麯��
//{
//	PTF* ptr = (PTF*)(*(int*)(&b));//��Ϊ���ĵ�ַ�Ż�������ǰ�ĸ��ֽڣ�����ǿתΪ(int*)
//
//	while (*ptr)//��Ϊvs���������0���������Կ�����Ϊ�ж�����
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
//	virtual void TestFunc1()//��B1�е��麯��TestFunc1��д
//	{
//		cout << "Derived::TestFunc1()" << endl;
//	}
//
//	virtual void TestFunc2()
//	{
//		cout << "Derived::TestFunc2()" << endl;//��B2�е��麯��TestFunc2��д
//	}
//
//	virtual void TestFunc3()//�������Լ����е��麯��
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