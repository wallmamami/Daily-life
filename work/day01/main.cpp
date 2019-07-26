#include <iostream>
using namespace std;

void fun(char* c)
{
  cout << c << "进入char" << endl;
}

void fun(int num)
{
  cout << num << "进入int" << endl;
}

int main()
{
  char* ptr = nullptr;
  fun(ptr);

  return 0;
}
