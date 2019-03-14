#include <iostream>
#include "mvc.h"
using namespace std;


int main()
{
  //M一般从数据库读取内容
  //但是这里为了方便直接赋值值
  Student m("wangjia", "158290");

  //创建一个视图，把学生
  //信息输出到控制台
  StudentView v;
  StudentController c(&m, &v);

  //由C调用V中的函数，将数据
  //输出到V，即显示在屏幕
  c.UpdataView();

  //当M中数据发生变化时，C
  //还要将这些变化更新到V中
  m.SetName("zhangz");
  m.SetNum("11720");
  
  c.UpdataView();

  return 0;
}
