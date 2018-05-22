#include "comm.h"
#include "HashTable.h"
#include "HashBucket.h"



void TestHashTable()
{
	HTable ht;
	HashTableInit(&ht, 5, _IsLine, IntToInt);//��ʼ��
	printf("%d\n", HashTableEmpty(&ht));
	HashTableInsert(&ht, 20);//����
	HashTableInsert(&ht, 2);
	HashTableInsert(&ht, 5);
	HashTableInsert(&ht, 100);
	HashTableInsert(&ht, 55);
	HashTableInsert(&ht, 1);
	HashTableInsert(&ht, 10);
	printf("size = %d\n", HashTableSize(&ht));

	printf("Find:%d\n", ht._table[HashTableFind(&ht, 20)]._data);//����

	HashTableDelete(&ht, 55);//ɾ��
	printf("size = %d\n", HashTableSize(&ht));
	HashTableDestory(&ht);
}

void TestHashBucket()
{
	HBucket ht;

	HashBucketInit(&ht, 10, IntToInt);

	HashBucketInsertUnique(&ht, 2);//����Ԫ�أ�dataΨһ
	HashBucketInsertUnique(&ht, 4);
	HashBucketInsertUnique(&ht, 6);
	HashBucketInsertUnique(&ht, 12);
	HashBucketDeleteUnique(&ht, 6);//ɾ��data
	printf("HashBucketSize:%d\n", HashBucketSize(&ht));
	printf("HashBucketCount:%d\n", HashBucketCount(&ht));
	printf("HashBucketBucketSize:%d\n", HashBucketBucketSize(&ht, 2));


	HashBucketInsertEqual(&ht, 2);//����Ԫ�أ�data��Ψһ
	printf("HashBucketSize:%d\n", HashBucketSize(&ht));
	printf("HashBucketCount:%d\n", HashBucketCount(&ht));
	printf("HashBucketBucketSize:%d\n", HashBucketBucketSize(&ht, 2));
	HashBucketDeleteEqual(&ht, 2);//ɾ������ֵΪdata��Ԫ��
	printf("HashBucketBucketSize:%d\n", HashBucketBucketSize(&ht, 2));

	HashBucketDestroy(&ht);
}

int main()
{
	//TestHashTable();//��̬��ɢ�й�ϣ��
	TestHashBucket();//��ɢ�й�ϣͰ
}