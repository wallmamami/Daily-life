#include "HashBucket.h"
#include "comm.h"


//哈希函数
static int HashFunc(HBucket* ht, int data)
{
	assert(ht);

	return ht->pDTInt(data) % (ht->_capacity);
}


//初始化
void HashBucketInit(HBucket* ht, int capacity, PDTInt pDTInt)
{
	assert(ht);

	capacity = GetCapacity(capacity);
	//calloc有初始化，将每个指针初始化为NULL
	ht->_table = (HBN**)calloc(capacity, sizeof(HBN*));

	if (NULL == ht->_table)
	{
		assert(0);
		return;
	}

	ht->_size = 0;
	ht->_capacity = capacity;
	ht->pDTInt = pDTInt;
}

//创建哈希桶节点
HBN* BuyHushBucketNode(DataType data)
{
	HBN* pNewNode = NULL;
	pNewNode = (HBN*)malloc(sizeof(HBN));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

//插入元素 -- data唯一
void HashBucketInsertUnique(HBucket* ht, DataType data)
{
	int BucketNo = -1;  
	HBN* pCur = NULL;
	assert(ht);

	BucketNo = HashFunc(ht, data);//用哈希函数算出插入数据的桶号

	//先判断桶号所指的链表中是否已经存在data
	pCur = ht->_table[BucketNo];
	while (pCur)
	{
		//如果已经存在就返回
		if (pCur->_data == data)
			return;

		pCur = pCur->_pNext;
	}

	//不存在直接头插
	pCur = BuyHushBucketNode(data); //创建新节点
	pCur->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pCur;
	ht->_size++;
}

//删除元素--data唯一
void HashBucketDeleteUnique(HBucket* ht, DataType data)
{
	int BucketNo = -1;
	HBN* pCur = NULL;
	HBN* pPre = NULL;
	assert(ht);

	BucketNo = HashFunc(ht, data);//用哈希函数算出插入数据的桶号

	//找到data
	pCur = ht->_table[BucketNo];
	while (pCur)
	{
		
		if (pCur->_data == data)
		{
			//为第一个个节点
			if (pCur == ht->_table[BucketNo])
				ht->_table[BucketNo] = pCur->_pNext;

			else
				pPre->_pNext = pCur->_pNext;
			
			free(pCur);
			ht->_size--;
			return;
		}


		else
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
			
	}

	
}

//插入元素--data不唯一
void HashBucketInsertEqual(HBucket* ht, DataType data)
{
	int BucketNo = -1;
	HBN* pCur = NULL;

	assert(ht);
	BucketNo = HashFunc(ht, data);

	//直接头插
	pCur = BuyHushBucketNode(data);
	pCur->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pCur;
	ht->_size++;
}

//删除所有值为data的节点
void HashBucketDeleteEqual(HBucket* ht, DataType data)
{
	int BucketNo = -1;
	HBN* pCur = NULL;
	HBN* pPre = NULL;

	assert(ht);
	BucketNo = HashFunc(ht, data);
	pCur = ht->_table[BucketNo];
	while (pCur)
	{
		if (pCur->_data == data)
		{
			//第一个节点
			if (pCur == ht->_table[BucketNo])
			{
				ht->_table[BucketNo] = pCur->_pNext;
				free(pCur);
				
				//从头开始继续找
				pCur = ht->_table[BucketNo];
			}

			else
			{
				pPre->_pNext = pCur->_pNext;
				free(pCur);
				
				//从下个节点继续找
				pCur = pPre->_pNext;
			}

			ht->_size--;
		
		}

		else
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
	}
}

//哈希桶中共有多少个节点
int HashBucketSize(HBucket* ht)
{
	assert(ht);
	return ht->_size;
}

//判空
int HashBucketEmpty(HBucket* ht)
{
	assert(ht);
	return 0 == ht->_size;
}

//哈希桶中共有多少个桶
int HashBucketCount(HBucket* ht)
{
	assert(ht);
	return ht->_capacity;
}

//在桶号为BucketNO的桶中有多少个节点
int HashBucketBucketSize(HBucket* ht, int BucketNo)
{
	int count = 0;
	HBN* pCur = NULL;
	assert(ht);

	pCur = ht->_table[BucketNo];
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

//销毁哈希桶
void HashBucketDestroy(HBucket* ht)
{
	int i = 0;
	HBN* pCur;
	assert(ht);

	for (; i < ht->_capacity; i++)
	{
		pCur = ht->_table[i];

		while (pCur)
		{
			ht->_table[i] = pCur->_pNext;
			free(pCur);
			pCur = ht->_table[i];
		}
	}

	ht->_capacity = 0;
	ht->_size = 0;
	free(ht->_table);
	ht->_table = NULL;
}

//打印哈希桶
void PrintHashBucket(HBucket* ht)
{
	assert(ht);
	int i = 0;

	for (; i < ht->_capacity; i++)
	{
		HBN* pCur = ht->_table[i];
		printf("HashTable[%d]:", i);
		while (pCur)
		{
			printf("%d-->", pCur->_data);
			pCur = pCur->_pNext;
		}

		printf("\n");
	}
}