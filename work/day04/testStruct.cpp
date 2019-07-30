#include <iostream>


//最后一个变量的偏移量+最后一个元素大小，还要可以整除最大sizeof值
//8 + 4因为可以整除4 所以=12
struct A
{
  char c;
  short a;
  short b;
  int size;
};

//因为已1对齐，所以直接加=9
#pragma pack(1)
struct B 
{
  char c;
  short a;
  short b;
  int size;
};
#pragma pack()

int main()
{
  std::cout << "A size = " << sizeof(A) << "B size = " << sizeof(B) << std::endl;

  return 0;
}
