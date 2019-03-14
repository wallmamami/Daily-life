#include "player.h"
#include <sstream>
#include <string>
#include <cstring>
#include <functional>

using namespace std;



//物品清单，相当于是物品ID与物品属性的哈希
unordered_map<int, Goods> list_map;


void InitListMap()
{ 
  string s1, s2;
  s1 = "普通物品";
  s2 = "不可使用";
  {
    Goods g(1, s1, 1, 0, s2);
    list_map[1] = g;
  }

  s1 = "HP药剂1";
  s2 = "每次使用一个, HP怎加1000";
  {
    Goods g(7, s1, 4, 2, s2);
    list_map[7] = g;
  }

  s1= "HP药剂2";
  s2= "每次使用一个, HP增加2000";
  {
    Goods g(23, s1, 23, 25, s2);
    list_map[23] = g;
  }

  s1 = "HP药剂3";
  s2 = "增加HP, 每一个物品增加一点HP, 每一次使用尽可能多的增加HP, 但HP不会超过系统上限";
  {
    Goods g(145, s1, 100, 25, s2);
    list_map[145] = g;
  }

  s1 = "MP药剂1";
  s2 = "每次使用一个, MP增加1000";
  {
    Goods g(146, s1, 348, 100, s2);
    list_map[146] = g;
  }

  s1 = "MP药剂2";    
  s2 = "每次使用一个, MP增加2000";    
  {
    Goods g(147, s1, 2314, 400, s2);
    list_map[147] = g;
  }

  s1 = "MP药剂3";    
  s2 = "增加MP, 每一个物品增加一点MP, 每一次使用尽可能多的增加MP, 但MP不会超过系统上限";    
  {
    Goods g(1246, s1, 9827, 2000, s2);
    list_map[1246] = g;
  }

  s1 = "普通物品";    
  s2 = "不可使用";    
  {
    Goods g(3214, s1, 34167, 8000, s2);
    list_map[3214] = g;
  }

  s1 = "毒药1";    
  s2 = "每次使用一个, HP成为当前的一半, 最少减少200点HP";    
  {
    Goods g(3215, s1, 78900, 20000, s2);
    list_map[3215] = g;
  }

  s1 = "毒药2";    
  s2 = "每次使用一个, MP成为当前的一半, 最少减少200点MP";    
  {
    Goods g(3216, s1, 250000, 1000, s2);
    list_map[3216] = g;
  }

  s1 = "元宝";    
  s2 = "每次使用一个, 增加200000金钱";    
  {
    Goods g(4501, s1, 423948, 100000, s2);
    list_map[4501] = g;
  }

  s1 = "普通物品";    
  s2 = "不可使用";    
  {
    Goods g(18273, s1, 1643490, 100, s2);
    list_map[18273] = g;
  }

  {
    Goods g(20193, s1, 2436695, 100, s2);
    list_map[20193] = g;
  }

  {
    Goods g(30000, s1, 50938245, 100, s2);
    list_map[30000] = g;
  }
}



void Split(vector<string>& arr, string& input)
{
  string word;
  istringstream stream(input);
  while(stream>>word)
  {
    arr.push_back(word);
  }
}


void DoIt(vector<string>& arr, Player& p)
{
  if(strncmp(arr[0].c_str(), "dump", 4) == 0)
  {
    p.Dump(); 
  }
  else if(strncmp(arr[0].c_str(), "buy", 3) == 0)
  {
    if(arr.size() != 3)
    {
      cout << "-ERR 输入个数错误" << endl;
      return;
    }

    p.Buy(atoi(arr[1].c_str()), atoi(arr[2].c_str()), list_map);
  }
  else if(strncmp(arr[0].c_str(), "sell", 4) == 0)
  {
    if(arr.size() != 3)
    {
      cout << "-ERR 输入个数错误" << endl;
      return;
    }

    p.Sell(atoi(arr[1].c_str()), atoi(arr[2].c_str()));
  }
  else if(strncmp(arr[0].c_str(), "exchange", 8) == 0)
  {
    if(arr.size() != 3)
    {
      cout << "-ERR 输入个数错误" << endl;
      return;
    }

    p.TrimBagExchange(atoi(arr[1].c_str()), atoi(arr[2].c_str()));
  }
  else if(strncmp(arr[0].c_str(), "move", 4) == 0)
  {
    if(arr.size() != 3)
    {
      cout << "-ERR 输入个数错误" << endl;
      return;
    }

    p.TrimBagMove(atoi(arr[1].c_str()), atoi(arr[2].c_str()));
  }
  else if(strncmp(arr[0].c_str(), "money", 5) == 0)
  {

    if(arr.size() != 2)
    {
      cout << "-ERR 输入个数错误" << endl;
      return;
    }

    p.AddMoney(atoi(arr[1].c_str()));
  }
  else if(strncmp(arr[0].c_str(), "capacity", 8) == 0)
  {

    if(arr.size() != 2)
    {
      cout << "-ERR 输入个数错误" << endl;
      return;
    }

    p.AddCapacity(atoi(arr[1].c_str()));
  }
  else if(strncmp(arr[0].c_str(), "use", 3) == 0)
  {

    if(arr.size() != 2)
    {
      cout << "-ERR 输入个数错误" << endl;
      return;
    }

    p.UseGoods(atoi(arr[1].c_str()));
  }
}

void Analyze(string& input, Player& p)
{
  //cout << input << endl;
  //先将input按照空格划分，将每一个词保存在arr中
  vector<string> arr;
  Split(arr, input);

  if(arr.size() == 0)
  {
      cout << "-ERR 输入错误" << endl;
      return;
  }
  
  DoIt(arr, p);

}

void Console(Player& p)
{
  string input;
  while(1)
  {
    getline(cin, input);
    if(strncmp(input.c_str(), "exit", 4) == 0)
      break;

    Analyze(input, p);
  }
}




























