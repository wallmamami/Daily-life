#include "observer.h"
#include <iostream>
using namespace std;

int main()
{
  //老板胡汉三
  Boss* huhansan = new Boss();

  //看股票的同事
  StockObserver* tongshi1 = new StockObserver("wangjia", huhansan);

  huhansan->Attach(tongshi1);

  //老板回来了
  huhansan->SetSubjectState("wo hui laile ");
  //发出通知
  huhansan->Notify();
  return 0;
}
