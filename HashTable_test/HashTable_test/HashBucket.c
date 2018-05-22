#include "HashBucket.h"
#include "comm.h"


//��ϣ����
static int HashFunc(HBucket* ht, int data)
{
	assert(ht);

	return ht->pDTInt(data) % (ht->_capacity);
}


//��ʼ��
void HashBucketInit(HBucket* ht, int capacity, PDTInt pDTInt)
{
	assert(ht);

	capacity = GetCapacity(capacity);
	//calloc�г�ʼ������ÿ��ָ���ʼ��ΪNULL
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

//������ϣͰ�ڵ�
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

//����Ԫ�� -- dataΨһ
void HashBucketInsertUnique(HBucket* ht, DataType data)
{
	int BucketNo = -1;  
	HBN* pCur = NULL;
	assert(ht);

	BucketNo = HashFunc(ht, data);//�ù�ϣ��������������ݵ�Ͱ��

	//���ж�Ͱ����ָ���������Ƿ��Ѿ�����data
	pCur = ht->_table[BucketNo];
	while (pCur)
	{
		//����Ѿ����ھͷ���
		if (pCur->_data == data)
			return;

		pCur = pCur->_pNext;
	}

	//������ֱ��ͷ��
	pCur = BuyHushBucketNode(data); //�����½ڵ�
	pCur->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pCur;
	ht->_size++;
}

//ɾ��Ԫ��--dataΨһ
void HashBucketDeleteUnique(HBucket* ht, DataType data)
{
	int BucketNo = -1;
	HBN* pCur = NULL;
	HBN* pPre = NULL;
	assert(ht);

	BucketNo = HashFunc(ht, data);//�ù�ϣ��������������ݵ�Ͱ��

	//�ҵ�data
	pCur = ht->_table[BucketNo];
	while (pCur)
	{
		
		if (pCur->_data == data)
		{
			//Ϊ��һ�����ڵ�
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

//����Ԫ��--data��Ψһ
void HashBucketInsertEqual(HBucket* ht, DataType data)
{
	int BucketNo = -1;
	HBN* pCur = NULL;

	assert(ht);
	BucketNo = HashFunc(ht, data);

	//ֱ��ͷ��
	pCur = BuyHushBucketNode(data);
	pCur->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pCur;
	ht->_size++;
}

//ɾ������ֵΪdata�Ľڵ�
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
			//��һ���ڵ�
			if (pCur == ht->_table[BucketNo])
			{
				ht->_table[BucketNo] = pCur->_pNext;
				free(pCur);
				
				//��ͷ��ʼ������
				pCur = ht->_table[BucketNo];
			}

			else
			{
				pPre->_pNext = pCur->_pNext;
				free(pCur);
				
				//���¸��ڵ������
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

//��ϣͰ�й��ж��ٸ��ڵ�
int HashBucketSize(HBucket* ht)
{
	assert(ht);
	return ht->_size;
}

//�п�
int HashBucketEmpty(HBucket* ht)
{
	assert(ht);
	return 0 == ht->_size;
}

//��ϣͰ�й��ж��ٸ�Ͱ
int HashBucketCount(HBucket* ht)
{
	assert(ht);
	return ht->_capacity;
}

//��Ͱ��ΪBucketNO��Ͱ���ж��ٸ��ڵ�
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

//���ٹ�ϣͰ
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

//��ӡ��ϣͰ
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