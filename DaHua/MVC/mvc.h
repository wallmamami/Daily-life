#include <iostream>
#include <string>

//我们将创建一个作为模型的 Student 对象。StudentView 是一个把学生
//详细信息输出到控制台的视图类，StudentController 是负责存储数据到 
//Student 对象中的控制器类，并相应地更新视图 StudentView。

//M
class Student final
{
public:
  Student(std::string name, std::string num) : name_(name), num_(num) {}
  
  //M就是实现一系列函数
  void SetName(std::string name) { name_ = name; }
  std::string GetName()const { return name_; }

  void SetNum(std::string num) { num_ = num; }
  std::string GetNum()const { return num_; }

private:
    std::string name_;
    std::string num_;
};


//V
class StudentView final
{
public:
  //V简单的来说就是将数据输
  //出在屏幕上，如打印
  void Print(std::string name, std::string num)const 
  { 
    std::cout << "Student: " << std::endl;
    std::cout << "Num: " << num << std::endl;
    std::cout << "Name: " << name << std::endl;
  }
};



//C
class StudentController final
{
  
public:
  StudentController(Student* m, StudentView* v) : model_(m), view_(v) {};

  //C最主要就是调用V
  //和M实现的函数
  void SetName(std::string name) { model_->SetName(name); }
  std::string GetName()const { return model_->GetName(); }

  void SetNum(std::string num) { model_->SetNum(num); }
  std::string GetNum()const { return model_->GetNum(); }

  //当M发生变化时，C要更新V
  void UpdataView()const { view_->Print(model_->GetName(), model_->GetNum()); }
private:
  Student* model_;
  StudentView* view_;
};














