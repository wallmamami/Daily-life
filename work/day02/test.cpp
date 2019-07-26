#include <iostream>




int main()
{
  char mask = 0;
  int colour[] = {0, 1, 1, 3, 4, 5};
  int size = sizeof(colour) / sizeof(int);
  std::cout << size << std::endl;
  for(int i = 0; i < size; ++i)
  {
    int c = colour[i];
    if(c >= 0 && c < 4)
    {
      mask |= (1 << c);
    }
  }

  std::cout << "mask = " << (int)mask << std::endl;
  int count = 1;
  for(int i = 0; i < 4; ++i)
  {
    if(mask & (1 << i))
    {
      switch(i)
      {
        case 0:
        case 1:
          {
            count += 1;
            break;
          }
        case 2:
        case 3:
          {
            count += 3;
            break;
          }
        default:
          break;
      }

    }
  }

  std::cout << "count = " << count << std::endl;
  return 0;
}
