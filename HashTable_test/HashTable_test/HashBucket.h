#ifndef __HASHBUCKET_H__
#define __HASHBUCKET_H__


#include <stdio.h>
#include <assert.h>
#include <malloc.h>



typedef int DataType;

typedef size_t(*PDTInt)(DataType str);


//哈希桶的每个节点类型
typedef struct HashBucketNode
{
	DataType _data;
	struct HashBucketNode* _pNext;
}HBN;


//哈希桶类型
typedef struct HushBucket
{
	HBN** _table;    //哈希桶空间--放的是节点的地址，所以是二级指针
	int _capacity;    //空间容量
	int _size;       //共有多少个有效元素--总节点个数
	PDTInt pDTInt;   //将数据类型转化为整形，因为哈希函数除留余数法
}HBucket;



//初始化
void HashBucketInit(HBucket* ht, int capacity, PDTInt pDTInt);

//创建哈希桶节点
HBN* BuyHushBucketNode(DataType data);

//插入元素 -- data唯一
void HashBucketInsertUnique(HBucket* ht, DataType data);

//删除元素--data唯一
void HashBucketDeleteUnique(HBucket* ht, DataType data);

//插入元素--data不唯一
void HashBucketInsertEqual(HBucket* ht, DataType data);

//删除所有值为data的节点
void HashBucketDeleteEqual(HBucket* ht, DataType data);

//哈希桶中共有多少个节点
int HashBucketSize(HBucket* ht);

//判空
int HashBucketEmpty(HBucket* ht);

//哈希桶中共有多少个桶
int HashBucketCount(HBucket* ht);

//在桶号为BucketNO的桶中有多少个节点
int HashBucketBucketSize(HBucket* ht, int BucketNo);

//打印哈希桶
void PrintHashBucket(HBucket* ht);

//销毁哈希桶
void HashBucketDestroy(HBucket* ht);


#endif