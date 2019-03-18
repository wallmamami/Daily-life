#include <iostream>
#include <string>

//简单工厂模式:
// 它提供了一种创建对象的最佳方式创建对象时不会对客户端暴露创建逻辑，并且是
// 通过使用一个共同的接口来指向新创建的对象如果使用工厂模式，就需要引入一个
// 工厂类, 工厂类其实就是根据用户的需求，生产不同的产品，各个产品继承于一个
// 父类，工厂类只需要一个父类的指针，就可以通过多态的方式生产不同的产品

//产品共同的父类
class Operation
{
public:
  void SetA(double A) { _numA = A; }
  double GetA()const { return _numA; }

  void SetB(double B) { _numB = B; }
  double GetB()const { return _numB; }

  virtual double GetResut();
  
private:
    double _numA;
    double _numB;
};

//产品A，以后如果有新产品，加一个类就可以了
//开放-封闭原则
class Add final : public Operation
{
public:
  double GetResut() override
  {
    return GetA() + GetB();
  }
};

//产品B
class Sub final : public Operation
{ 
public:
  double GetResut() override
  {
    return GetA() - GetB();
  }
};


//产品C
class Mul final : public Operation
{ 
public:
  double GetResut() override
  {
    return GetA() * GetB();
  }
};


class Div final : public Operation
{ 
public:
  double GetResut() override
  {
    if(GetB() == 0)
      return 0.0f;

    return GetA() / GetB();
  }
};


class OperationFactory final
{
public:
  //只有一个静态方法，根据参数来创建不同的“产品”
  static Operation* CreateOperate(std::string operate)
  {
    Operation* oper = NULL;
    if(operate == "+")
    {
      oper = new Add();
    }
    else if(operate == "-")
    {
      oper = new Sub();
    }
    else if(operate == "*")
    {
      oper = new Mul();
    }
    else
    {
      oper = new Div();
    }
    
    return oper;
  }

};
