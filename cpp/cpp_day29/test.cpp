//#include <iostream>
//#include <stdio.h>
//
////����ģʽ�ĵ���
//class Singleton
//{
//private:
//	class Object
//	{
//	private:
//		int data;
//	};
//
//	static Object obj;
//public:
//	static Object* Instance()
//	{
//		return &obj;
//	}
//};
//
////����ģʽ�ĵ���
//class Singleton
//{
//private:
//	class Object
//	{
//	private:
//		int data;
//	};
//
//	volatile static Object* obj;
//
//public:
//	static Object* Instance()
//	{
//		if (obj == NULL)
//		{
//			lock();
//			if (obj == NULL)//ֻ����һ��if�жϵĻ������̰߳�ȫ����
//			{
//				obj = new Object();
//			}
//
//			unlock();
//		}
//
//		return obj;
//	}
//};


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int n = 0;//��ʾԼ�������ĸ���
	int m = 0;//��ʾ��Ҫ��ѯ�ĸ���
	std::cin >> n >> m;
	std::cin.clear();

	std::vector<std::string> Restrain; //��ʾ����Լ������
	std::vector<std::string> Query; //��ʾ�����ѯ
	std::string s;

	while (n--)
	{
		getline(std::cin, s);
		Restrain.push_back(s);
		s.clear();
	}

	while (m--)
	{
		getline(std::cin, s);
		Query.push_back(s);
		s.clear();
	}



	return 0;
}

//#include <iostream>
//#include <vector>
//#include <string>

//int main()
//{
//	int t = 0; //��������
//	std::vector<std::vector<std::string>> arr;//ÿһ��һά�����ʾһ��
//	std::cin >> t;
//	std::cout << "t = " << t << std::endl;
//	while (t--)
//	{
//		std::vector<std::string> group;
//		std::string s;
//		int n = 0;//ÿ����ַ�������
//		std::cin >> n;
//		std::cout << "n = " << n << std::endl;
//		while (n--)
//		{
//			getline(std::cin, s);
//			group.push_back(s);
//			s.clear();
//		}
//
//		arr.push_back(group);
//	}
//
//	for (int i = 0; i < arr.size(); ++i)
//	{
//		for (int j = 0; j < arr[0].size(); ++j)
//		{
//			std::cout << arr[i][j] << " ";
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	std::string s;
//	int a = 2;
//
//	std::cin >> a;
//	while (a--)
//	{
//		getline(std::cin, s);
//	}
//	return 0;
//}