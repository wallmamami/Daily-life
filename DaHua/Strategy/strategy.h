#include <iostream>
#include <string>
using namespace std;


//策略模式：
// 策略模式主要是用来封装一组可以互相替代的算法族，
// 并且可以根据需要动态地去替换 Context 使用的算法。
// 看完策略模式，我们会发现策略模式跟之前的简单工厂
// 模式很相似，但其实仔细看，还是会发现他们之间的区别

//区别：
// 工厂模式中的”产品“就类似于策略模式中的”策略“工厂模
// 式中的factory类就相当于策略模式中的Context类，在工
// 厂模式中，我们只需要传入条件，共工厂就会给我们生产
// 出相应的产品，我们再调用产品中的某个方法但在策略模
// 式中，我们需要自己创建策略（产品），然后将其传给
// Context（factory），再由Context调用不同的方法

//实现一个商场的收费软件, 不同的收费方式就为一种策略
//如：正常收费、满300减100等



//不同算法族共同的父类
class CashSuper 
{
  public:
    //每个子类需要实现的算法
    virtual double AcceptCash(double money) { return money; }
};

//策略一：
//正常收费
class CashNormal final : public CashSuper 
{
  double AcceptCash(double money)override { return money; }
};


//策略二：
//打折收费
class CashRebate final : public CashSuper 
{
  //维护一个折扣率
  private:
    double _moneyRebate;

  public:
    CashRebate(double moneyRebate) : _moneyRebate(moneyRebate) {}
    double AcceptCash(double money)override { return money*_moneyRebate; }
};


//Context，用一个具体的strategy来配置，
//维护一个strategy对象的指针。
class CashContext final
{
  //这里需要维护一个strategy对象的指针
  private:
    CashSuper* _cs; 

  public:
    //这里需要根据传来的策略对象来给_cs赋值
    //但是这里使用的是策略于简单工厂结合
    //所以需要传的是收费类型，根据收费类型
    //去创建不同的策略
    CashContext(string type) 
    {
     if(type == "正常收费")
      {
        _cs = new CashNormal();
      }
      else if(type == "打8折")
      {
        _cs = new CashRebate(0.8);
      }
    } 

    //根据不同策略调用不同的算法
    double GetResut(double money) { return _cs->AcceptCash(money); }
};
