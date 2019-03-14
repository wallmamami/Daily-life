#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define MAX_MP_AND_HP 10000    //HP与MP的最大值
#define MAX_MONEY 2000000000 //金钱的默认最大值
#define MAX_BAG_SIZE 8  //包裹的最大格子数
#define MAX_GOODS_SIZE 5000 //每个格子内最大存放物品数量
#define MAX_CAPACITY 32   //包裹的最大容量
#define MIN_MP_AND_HP_REDUCE 200    //使用毒药后HP与MP最少减少的值


//物品类
class Goods
{
  public:
    Goods()
    {}
    Goods(int id, string& describe, int expend, int income, string& effect);
    Goods(const Goods& g);
    Goods operator=(const Goods& g);

    int id_; //物品ID
    string describe_; //物品描述
    int expend_; //购买该物品的花费
    int income_; //售出该户品的输入
    string effect_; //该物品的使用效果 
};



class Bag
{
public:
    Bag();

    int size_;  //当前背包剩余容量
    int capacity_;  //当前背包总容量
    vector<vector<Goods>> value_;
};

class Player
{
public:
    Player();  
    void Dump(); //输出玩家属性
    void Buy(int id, int count, unordered_map<int, Goods>& list_map); //购买物品
    void Sell(int index, int count); //卖出物品
    void TrimBagExchange(int index1, int index2); //整理包裹--交换
    void TrimBagMove(int index1, int index2); //整理包裹--移动
    void AddMoney(int much); //获得金钱
    void AddCapacity(int new_cap); //增加包裹容量
    void UseGoods(int index); //使用物品
  
private:
    bool IsUseful(int id);
    bool IsUseOne(int id);
    void UseOne(int id);
    int UseNotOne(int id, vector<Goods>& arr);
private:
    int money_;
    Bag bag_;
    int hp_;
    int mp_;
};
