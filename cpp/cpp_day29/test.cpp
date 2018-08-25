//#include <iostream>
//#include <stdio.h>
//
////饿汉模式的单例
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
////懒汉模式的单例
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
//			if (obj == NULL)//只进行一次if判断的话，有线程安全问题
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
	int n = 0;//表示约束条件的个数
	int m = 0;//表示需要查询的个数
	std::cin >> n >> m;
	std::cin.clear();

	std::vector<std::string> Restrain; //表示保存约束条件
	std::vector<std::string> Query; //表示保存查询
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
//	int t = 0; //测试组数
//	std::vector<std::vector<std::string>> arr;//每一个一维数组表示一组
//	std::cin >> t;
//	std::cout << "t = " << t << std::endl;
//	while (t--)
//	{
//		std::vector<std::string> group;
//		std::string s;
//		int n = 0;//每组的字符串个数
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