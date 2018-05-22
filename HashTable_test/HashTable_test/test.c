#include "comm.h"
#include "HashTable.h"
#include "HashBucket.h"



void TestHashTable()
{
	HTable ht;
	HashTableInit(&ht, 5, _IsLine, IntToInt);//初始化
	printf("%d\n", HashTableEmpty(&ht));
	HashTableInsert(&ht, 20);//插入
	HashTableInsert(&ht, 2);
	HashTableInsert(&ht, 5);
	HashTableInsert(&ht, 100);
	HashTableInsert(&ht, 55);
	HashTableInsert(&ht, 1);
	HashTableInsert(&ht, 10);
	printf("size = %d\n", HashTableSize(&ht));

	printf("Find:%d\n", ht._table[HashTableFind(&ht, 20)]._data);//查找

	HashTableDelete(&ht, 55);//删除
	printf("size = %d\n", HashTableSize(&ht));
	HashTableDestory(&ht);
}

void TestHashBucket()
{
	HBucket ht;

	HashBucketInit(&ht, 10, IntToInt);

	HashBucketInsertUnique(&ht, 2);//插入元素，data唯一
	HashBucketInsertUnique(&ht, 4);
	HashBucketInsertUnique(&ht, 6);
	HashBucketInsertUnique(&ht, 12);
	HashBucketDeleteUnique(&ht, 6);//删除data
	printf("HashBucketSize:%d\n", HashBucketSize(&ht));
	printf("HashBucketCount:%d\n", HashBucketCount(&ht));
	printf("HashBucketBucketSize:%d\n", HashBucketBucketSize(&ht, 2));


	HashBucketInsertEqual(&ht, 2);//插入元素，data不唯一
	printf("HashBucketSize:%d\n", HashBucketSize(&ht));
	printf("HashBucketCount:%d\n", HashBucketCount(&ht));
	printf("HashBucketBucketSize:%d\n", HashBucketBucketSize(&ht, 2));
	HashBucketDeleteEqual(&ht, 2);//删除所有值为data的元素
	printf("HashBucketBucketSize:%d\n", HashBucketBucketSize(&ht, 2));

	HashBucketDestroy(&ht);
}

int main()
{
	//TestHashTable();//动态闭散列哈希表
	TestHashBucket();//开散列哈希桶
}