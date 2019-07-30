#include <iostream>

int main()
{
  //数组名表示首元素地址，两种情况除外
  //一是sizeof(arr)，此时数组名表示这个类型，即结果为20
  //二是&arr，此时表示整个数组的地址，这与数组首地址值相同但意思不同
  int a = 10;
  std::cout << a << std::endl;
  int arr[] = {1, 2, 3, 4, 5};

  std::cout << sizeof(arr) << std::endl;
  std::cout << arr << std::endl;
  return 0;
}
