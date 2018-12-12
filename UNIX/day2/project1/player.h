#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define MAX_VALUE 10000    //HP与MP的最大值
#define MAX_MONEY 2000000000 //金钱的默认最大值
#define MAX_SIZE 8  //包裹的最大格子数
#define MAX_GOODS_SIZE 5000 //每个格子内最大存放物品数量
#define MAX_CAPACITY 32   //包裹的最大容量
#define MIN_VALUE 200    //使用毒药后HP与MP最少减少的值


//物品类
class Goods
{
  public:
    Goods();
    Goods(int id, string& describe, int expend, int income, string& effect);
    Goods(const Goods& g);
    Goods operator=(const Goods& g);
    void SetMember(int id, string& describe, int expend, int income, string& effect);

    int id_; //物品ID
    string describe_; //物品描述
    int expend_; //购买该物品的花费
    int income_; //售出该户品的输入
    string effect_; //该物品的使用效果 
};




//0-10000
class HP
{
  public:
    HP();
    HP(HP& h);
    HP operator+(int value);
    HP operator-(int value);

    int value_;
};


//0-10000
class MP
{
  public:
    MP();
    MP(MP& m);
    MP operator+(int value);
    MP operator-(int value);

    int value_;

};


//0-2000 000 000
//int最大范围2147 483 647
class Money
{
  public:
    Money();
    Money operator+(int value);
    Money operator-(int value);

    int value_;
};


class Bag
{
  public:
    Bag();

    int size_;  //当前背包剩余容量
    int capacity_;  //当前背包总容量
    vector<vector<Goods>> value_;
};

class Person
{
  public:
    Person();  
    void Dump(); //输出玩家属性
    void Buy(int id, int count, unordered_map<int, Goods>& list_map); //购买物品
    void Sell(int index, int count); //卖出物品
    void TrimBagExchange(int index1, int index2); //整理包裹--交换
    void TrimBagMove(int index1, int index2); //整理包裹--移动
    void GetMoney(int much); //获得金钱
    void AddCapacity(int new_cap); //增加包裹容量
    void UseGoods(int index); //使用物品
  
  private:
    bool IsUseful(int id);
    bool IsUseOne(int id);
    void UseOne(int id);
    int UseNotOne(int id, vector<Goods>& arr);
  private:
    Money m_;
    Bag bag_;
    HP hp_;
    MP mp_;
};
