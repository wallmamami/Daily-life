#include "player.h"

Goods::Goods()
{}

Goods::Goods(int id, string& describe, int expend, int income, string& effect)
  : id_(id)
  , describe_(describe)
  , expend_(expend)
  , income_(income)
    , effect_(effect)
{}

Goods::Goods(const Goods& g)
  : id_(g.id_)
  , describe_(g.describe_)
  , expend_(g.expend_)
  , income_(g.income_)
    , effect_(g.effect_)
{}



Goods Goods::operator=(const Goods& g)
{
  id_ = g.id_;
  describe_ = g.describe_;
  expend_ = g.expend_;
  income_ = g.income_;
  effect_ = g.effect_;

  return *this;
}

void Goods::SetMember(int id, string& describe, int expend, int income, string& effect)
{
  id_ = id;
  describe_ = describe;
  expend_ = expend;
  income_ = income;
  effect_ = effect;
}


//HP初始值为10000
HP::HP()
  : value_(MAX_VALUE)
{}

HP::HP(HP& h)
  : value_(h.value_)
{}


HP HP::operator+(int value)
{
  value_ += value;
  if(value_ > MAX_VALUE)
  {
    value_ = MAX_VALUE;
  }

  return *this;
}

HP HP::operator-(int value)
{
  value_ -= value;
  if(value_ < 0)
  {
    value_ = 0;
  }

  return *this;
}


//MP初始值为10000
MP::MP()
  : value_(10000)
{}

MP::MP(MP& m)
  : value_(m.value_)
{}


MP MP::operator+(int value)
{
  value_ += value;
  if(value_ > MAX_VALUE)
  {
    value_ = MAX_VALUE;
  }

  return *this;
}


MP MP::operator-(int value)
{

  value_ -= value;
  if(value_ < 0)
  {
    value_ = 0;
  }

  return *this;
}


Money::Money()
  : value_(0)
{}



Money Money::operator+(int value)
{
  //这里考虑到直接相加可能会越界
  long long tmp = value_;
  tmp += value;
  if(tmp > MAX_MONEY)
  {
    tmp = MAX_MONEY;
  }
  value_ = (int)tmp;

  return *this;
}

Money Money::operator-(int value)
{
  value_ -= value;
  if(value_ < 0)
  {
    value_ = 0;
  }

  return *this;
}


Bag::Bag()
  : size_(MAX_SIZE)
  , capacity_(MAX_SIZE)
    , value_(capacity_, vector<Goods>())
{}


Person::Person()
  : m_()
  , bag_()
  , hp_()
    , mp_()
{}



void Person::Dump()
{
  cout << "Money " << m_.value_ << endl;
  cout << "HP " << hp_.value_ << endl;
  cout << "MP " << mp_.value_ << endl;

  cout << "Inventory capacity " << bag_.capacity_ << endl;  

  for(int i = 0; i < bag_.capacity_; ++i)
  {
    //首先判断改格子是否为空
    //为空的包裹格不输出
    if(bag_.value_[i].size() == 0)
      break;

    cout << "Inventory index " << i << "," << "item" << bag_.value_[i][0].id_ \
      << "," << "count " << bag_.value_[i].size() << endl;
  }

  cout << "+OK" << endl;
}


void Person::Buy(int id, int count, unordered_map<int, Goods>& list_map)
{
  unordered_map<int, Goods>::iterator it = list_map.find(id);
  if(it == list_map.end())
  {
    cout << "-ERR 没有该物品" << endl;
    return;
  }

  if(count <= 0 || count > MAX_GOODS_SIZE * bag_.size_)
  {
    cout << "-ERR 购买数量输入错误" << endl;
    return;
  }

  long long total_value = it->second.expend_ * count;
  if(total_value > m_.value_)
  {
    cout << "-ERR 金钱不够" << endl;
    return;
  }

  if(bag_.size_ == 0)
  {
    cout << "-ERR 背包已满" << endl;
    return;
  }

  //先找存放该物品格子的下标
  //1.优先找到存放同类的物品下标
  //  这里有可能有多个格子是相同
  //  的物品，所以应该全部找到
  //2.若没有，依次找到空格子的下标
  vector<int> Index;

  for(int i = 0; i < bag_.capacity_; ++i)
  {
    if(bag_.value_[i].size() != 0 && bag_.value_[i][0].id_ == id)
    {
      Index.push_back(i);
      continue;
    }
  }

  //这里如果背包之前就有该类物品，找到后
  //放入，如果该格子满了，则在Index数组
  //找下一个格子，如果没有，找个空格子继续放
  if(Index.size() != 0)
  {
    int size = Index.size();
    for(int i = 0; i < size; ++i)
    {
      //开始购买物品！
      while(count)
      {
        if(bag_.value_[Index[i]].size() >= MAX_GOODS_SIZE)
        {
          break;
        }
        bag_.value_[Index[i]].push_back(it->second);
        m_ = m_ - it->second.expend_;
        --count;
        if(count == 0)
        {
          cout << "+OK" << endl;
          return;
        }
      }
    }
  }

  //走到这里要找空格子继续放
  Index.clear();
  for(int i = 0; i < bag_.capacity_; ++i)
  {
    if(bag_.value_[i].size() == 0)
    {
      Index.push_back(i);
    }
  }

  if(Index.size() == 0)
  {
    cout << "-ERR 包裹容量不足" << endl;
    return;
  }

  int size = Index.size();
  for(int i = 0; i < size; ++i)
  {
    //开始购买物品！
    while(count)
    {
      if(bag_.value_[Index[i]].size() >= MAX_GOODS_SIZE)
      {
        break;
      }
      bag_.value_[Index[i]].push_back(it->second);
      m_ = m_ - it->second.expend_;
      --count;
      if(count == 0)
        break;
    }

    //由于使用的是空格子，所以当前容量-=1
    bag_.size_ -= 1;
    if(count == 0)
    {
      cout << "+OK" << endl;
      return;
    }
  }

  cout << "-ERR 包裹容量不足" << count << endl;
}


void Person::Sell(int index, int count)
{
  if(index > bag_.capacity_ - 1 || index < 0)
  {
    cout << "-ERR 包裹格索引输入错误" << endl;
    return;
  }

  int size = bag_.value_[index].size();
  if(count > size || count <= 0)
  {
    cout << "-ERR 物品数量输入错误" << endl;
    return;
  }

  //如果count=size表示卖完了该类物品
  //所以包裹当前容量+=1
  if(size == count)
  {
    bag_.size_ += 1;
  }

  Goods tmp = bag_.value_[index][0];
  long long money = m_.value_;
  while(count--)
  {
    bag_.value_[index].pop_back();
    //卖了之后金钱就会增加
    money += tmp.income_; 
  }

  if(money > MAX_MONEY)
  {
    money = MAX_MONEY;
  }
  m_.value_ = money;

  cout << "+OK" << endl;
}


//整理包裹--交换
void Person::TrimBagExchange(int index1, int index2)
{
  if(index1 >= bag_.capacity_ || index1 < 0 ||
      index2 >= bag_.capacity_ || index2 < 0 ||
      index1 == index2)
  {
    cout << "-ERR 包裹格索引输入错误" << endl;
    return;
  }

  vector<Goods> tmp(bag_.value_[index1]);
  bag_.value_[index1] = bag_.value_[index2];
  bag_.value_[index2] = tmp;

  cout << "+OK" << endl;
}


//整理包裹--移动
void Person::TrimBagMove(int index1, int index2)
{
  if(index1 >= bag_.capacity_ || index1 < 0 ||
      index2 >= bag_.capacity_ || index2 < 0 ||
      index1 == index2)
  {
    cout << "-ERR 包裹格索引输入错误" << endl;
    return;
  }

  if(bag_.value_[index1].size() == 0)
  {
    cout << "-ERR 源包裹格中没有物品" << endl;
    return;
  }

  if(bag_.value_[index2].size() == MAX_GOODS_SIZE)
  {
    cout << "-ERR 目的包裹格已满" << endl;
    return;
  }

  int size = bag_.value_[index1].size();
  Goods tmp = bag_.value_[index1][0];
  //目的包裹格为空就直接放
  if(bag_.value_[index2].size() == 0)
  {
    while(size--)
    {
      bag_.value_[index1].pop_back();
      bag_.value_[index2].push_back(tmp);
    }

    cout << "+OK" << endl;
    return;
  }

  int id1 = bag_.value_[index1][0].id_;
  int id2 = bag_.value_[index2][0].id_;
  if(id1 != id2)
  {
    cout << "-ERR 目的包裹格与源包裹格物品种类不同" << endl;
    return;
  }

  //到这里说明，目的包裹格中物品与源
  //包裹格相同，直接将其放满MAX_GOODS_SIZE
  while(size)
  {
    bag_.value_[index1].pop_back();
    bag_.value_[index2].push_back(tmp);
    --size;

    if(bag_.value_[index2].size() >= MAX_GOODS_SIZE)
      break;
  }

  cout << "+OK" << endl;
}


void Person::GetMoney(int much)
{
  if(much <= 0)
  {
    cout << "-ERR 金钱数量输入错误" << endl;
    return;
  }

  if(much >= MAX_MONEY)
  {
    m_.value_ = MAX_MONEY;
  }
  else
  {
    long long money = m_.value_;
    money += much;
    if(money > MAX_MONEY)
      money = MAX_MONEY;

    m_.value_ = money;
  }

  cout << "+OK" << endl;
}


//增加包裹容量
void Person::AddCapacity(int new_cap)
{
  if(new_cap < bag_.capacity_ || new_cap > MAX_CAPACITY)
  {
    cout << "-ERR 包裹新容量输入错误" << endl;
    return;
  }

  vector<vector<Goods>> new_bag(new_cap, vector<Goods>());
  vector<vector<Goods>> tmp(bag_.value_);
  bag_.value_ = new_bag;
  bag_.capacity_ = new_cap;

  //到这容量已经扩增完毕，但是还要
  //把原来bag中的数据搬移过来
  int size = tmp.size();
  for(int i = 0; i < size; ++i)
  {
    bag_.value_[i] = tmp[i];
  }

  cout << "+OK" << endl;
}

bool Person::IsUseful(int id)
{
  if(id == 1 || id == 3214 || id == 18273 || id == 20193 || id == 30000)
    return false;
  return true;
}

bool Person::IsUseOne(int id)
{
  if(id == 145 || id == 1264)
    return false;
  return true;
}

void Person::UseOne(int id)
{
  switch(id)
  {
    case 7:
      {
        hp_.value_ += 1000;
        if(hp_.value_ > MAX_VALUE)
        {
          hp_.value_ = MAX_VALUE;
        }
        break;
      }
    case 23:
      {
        hp_.value_ += 2000;
        if(hp_.value_ > MAX_VALUE)
        {
          hp_.value_ = MAX_VALUE;
        }
        break;
      }
    case 146:
      {
        mp_.value_ += 1000;
        if(mp_.value_ > MAX_VALUE)
        {
          mp_.value_ = MAX_VALUE;
        }
        break;
      }
    case 147:
      {
        mp_.value_ += 2000;
        if(mp_.value_ > MAX_VALUE)
        {
          mp_.value_ = MAX_VALUE;
        }
        break;
      }
    case 3215:
      {
        int half = hp_.value_ / 2;
        if(half < MIN_VALUE)
        {
          hp_.value_ -= MIN_VALUE;
          if(hp_.value_ < 0)
          {
            hp_.value_ = 0;
          }

          break;
        }
        hp_.value_ = half;
        break;
      }
    case 3216:
      {
        int half = mp_.value_ / 2;
        if(half < MIN_VALUE)
        {
          mp_.value_ -= MIN_VALUE;
          if(mp_.value_ < 0)
          {
            mp_.value_ = 0;
          }

          break;
        }
        mp_.value_ = half;
        break;
      }
    case 4501:
      {
        long long money = m_.value_;
        money += 200000;
        if(money > MAX_MONEY)
        {
          money = MAX_MONEY;
        }

        m_.value_ = money;
        break;
      }
    default:
      break;
  }
}

int Person::UseNotOne(int id, vector<Goods>& arr)
{
  int count = 0;
  if(id == 145)
  {
    if(hp_.value_ >= MAX_VALUE)
      return count;
    else
    {
      while(arr.size() > 0)
      {
        hp_.value_ += 1;
        arr.pop_back();
        ++count;
        if(hp_.value_ >= MAX_VALUE)
          break;
      }
    }
  }

  if(id == 1264)
  {
    if(mp_.value_ == MAX_VALUE)
      return count;
    else
    {
      while(arr.size() > 0)
      {
        mp_.value_ += 1;
        arr.pop_back();
        ++count;
        if(mp_.value_ >= MAX_VALUE)
          break;
      }
    }
  }

  return count;
}

void Person::UseGoods(int index)
{
  if(index < 0 || index >= bag_.capacity_)
  {
    cout << "-ERR 包裹索引输入错误" << endl;
    return;
  }

  if(bag_.value_[index].size() == 0)
  {
    cout << "-ERR 该包裹格中没有物品" << endl;
    return;
  }

  Goods g = bag_.value_[index][0];
  if(!IsUseful(g.id_))
  {
    cout << "-ERR 该物品不能使用" << endl;
    return;
  }

  int count = 0;
  if(IsUseOne(g.id_))
  {
    count = 1;
    UseOne(g.id_);
    bag_.value_[index].pop_back();
  }
  else
  {
    count = UseNotOne(g.id_, bag_.value_[index]);
    if(count == 0)
    {
      if(g.id_ == 145)
      {
        cout << "-ERR 人物HP已到系统上限" << endl;
        return;
      }
      else
      {
        cout << "-ERR 人物MP已到系统上限" << endl;
        return;
      }
    }
  }

  cout << "+OK 使用了" << count << "个物品" << endl;
}
























