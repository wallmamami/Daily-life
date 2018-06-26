#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__


#include <stdio.h>
#include <assert.h>
#include <malloc.h>

//哈希表中每个位置的状态
typedef enum Stat
{
	EM,  //空
	EX,  //存在
	DE   //被删除
}Stat;

typedef int DataType;
typedef size_t(*PDTInt)(DataType str);

typedef enum
{
	_IsLine,          //线性探测
	_IsNotLine		  //二次探测
}IsLine;

//哈希表每个位置包含数据和这个位置的状态
typedef struct Elem
{
	DataType _data;
	Stat stat;
}Elem;

typedef struct HashTable
{
	Elem* _table;
	int _capacity;    //容量
	int _size;        //有效元素个数
	int _total;      //有效元素和被删除的元素之和
	IsLine DetecWay;    //发生哈希冲突的探测方法
	PDTInt pDTInt;      //将数据转化为整型，函数指针
}HTable;


//处理哈希冲突的方法--线性探测
int IsLineDetec(HTable* ht, int addr);

//二次探测
int NotIsLineDetec(HTable* ht, int addr, int i);

//初始化
void HashTableInit(HTable* ht, int capacity, IsLine DetecWay, PDTInt pDtInt);
//插入元素
void HashTableInsert(HTable* ht, DataType data);

//查找元素,找到返回地址
int HashTableFind(HTable* ht, DataType data);

//删除元素
void HashTableDelete(HTable* ht, DataType data);

int HashTableSize(HTable* ht);

int HashTableEmpty(HTable* ht);

//销毁哈希表
void HashTableDestory(HTable* ht);


#endif
