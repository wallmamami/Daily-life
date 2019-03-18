#include "strategy.h"
using namespace std;


int main()
{
 //注意：这里的判断一般不会让client去写，一般将其放在
 //      context中，client越简单越好,使用的是策略于简单
 //      工厂结合的方式
 // //第一步，要根据不同需求创建不同的策略
 // CashSuper* cs = NULL;
 // string cmd("打8折");
 // if(cmd == "正常收费")
 // {
 //   cs = new CashNormal();
 // }
 // else if(cmd == "打8折")
 // {
 //   cs = new CashRebate(0.8);
 // }
 // 
 // //第二步，传入策略创建context对象
 // CashContext cc(cs);
 // cout << cc.GetResut(100) << endl;


  //而简单工厂模式于策略相结合相较于简单工厂模式
  //也有所不同，比如这里client只认识CashContext(factory)类
  //不像工厂类的client除了认识factory类，还有operation(产品的父类)
  //这样的好处就是耦合更加降低
  CashContext cc("打8折");
  cout << cc.GetResut(100) << endl;

  return 0;
}
