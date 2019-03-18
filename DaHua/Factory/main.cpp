#include <iostream>
#include "factory.h"
using namespace std;



int main()
{
  //1.根据参数，来在工厂中创建不同的产品
  Operation* oper;
  oper = OperationFactory::CreateOperate("/");
  
  oper->SetA(10);
  oper->SetB(20.5);

  cout << oper->GetResut() << endl;
  return 0;
}
