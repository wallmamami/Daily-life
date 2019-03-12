#include <iostream>
#include <string>
#include <set>

//观察者模式定义了一种一对多的依赖关系，让多个观察者对象
//同事监听某一个主题对象（通知者）。这个主题对象在状态发
//生变化时，会通知所有登记过的观察者对象，使他们能够自动
//更新自己


//前置声明
class Subject;

//抽象观察者类
class Observer
{
public:
  Observer(std::string name, Subject* sub) : name_(name), sub_(sub) {}
  virtual void Update() noexcept = 0; 

protected:
  std::string name_;
  Subject* sub_;  //哪一个通知者
};

//抽象通知者
class Subject
{
public:
  virtual void Attach(Observer* observer){}
  virtual void Detach(Observer* observer){}
  virtual void Notify() const {}
  virtual void SetSubjectState(std::string value){}
  virtual std::string GetSubjectState() const {}

};

//实现抽象观察者接口
//观察者1 看股票的同事
class StockObserver : public Observer
{
public:
  StockObserver(std::string name, Subject* sub) : Observer(name, sub){}

  void Update() noexcept
  {
    std::cout << sub_->GetSubjectState() << name_ << "关闭股票行情， 继续工作" << std::endl;
  }
};

//观察者2 看NBA的同事
class NBAObserver : public Observer
{
  
public:
  NBAObserver(std::string name, Subject* sub) : Observer(name, sub){}
  void Update() noexcept
  {
    std::cout << sub_->GetSubjectState() << name_ << "关闭NBA直播，继续工作" << std::endl;
  }
};


//实现抽象通知者接口
//通知者1 老板
class Boss final: public Subject
{
private:
  //同事列表
  std::set<Observer*> observers;
  std::string action;
  
public:
  //同事列表中增加
  void Attach(Observer* observer) override { observers.insert(observer); }

  //减少
  void Detach(Observer* observer) override
  { 
    observers.erase(observer);
  }

  //通知每个登记的观察者
  void Notify() const override
  {
    for(auto it : observers)
    {
      it->Update();
    }

  }

  //老板状态
  void SetSubjectState(std::string value) { action = value; }
  std::string GetSubjectState() const { return action; }
  
};
