#ifndef __HASHBUCKET_H__
#define __HASHBUCKET_H__


#include <stdio.h>
#include <assert.h>
#include <malloc.h>



typedef int DataType;

typedef size_t(*PDTInt)(DataType str);


//��ϣͰ��ÿ���ڵ�����
typedef struct HashBucketNode
{
	DataType _data;
	struct HashBucketNode* _pNext;
}HBN;


//��ϣͰ����
typedef struct HushBucket
{
	HBN** _table;    //��ϣͰ�ռ�--�ŵ��ǽڵ�ĵ�ַ�������Ƕ���ָ��
	int _capacity;    //�ռ�����
	int _size;       //���ж��ٸ���ЧԪ��--�ܽڵ����
	PDTInt pDTInt;   //����������ת��Ϊ���Σ���Ϊ��ϣ��������������
}HBucket;



//��ʼ��
void HashBucketInit(HBucket* ht, int capacity, PDTInt pDTInt);

//������ϣͰ�ڵ�
HBN* BuyHushBucketNode(DataType data);

//����Ԫ�� -- dataΨһ
void HashBucketInsertUnique(HBucket* ht, DataType data);

//ɾ��Ԫ��--dataΨһ
void HashBucketDeleteUnique(HBucket* ht, DataType data);

//����Ԫ��--data��Ψһ
void HashBucketInsertEqual(HBucket* ht, DataType data);

//ɾ������ֵΪdata�Ľڵ�
void HashBucketDeleteEqual(HBucket* ht, DataType data);

//��ϣͰ�й��ж��ٸ��ڵ�
int HashBucketSize(HBucket* ht);

//�п�
int HashBucketEmpty(HBucket* ht);

//��ϣͰ�й��ж��ٸ�Ͱ
int HashBucketCount(HBucket* ht);

//��Ͱ��ΪBucketNO��Ͱ���ж��ٸ��ڵ�
int HashBucketBucketSize(HBucket* ht, int BucketNo);

//��ӡ��ϣͰ
void PrintHashBucket(HBucket* ht);

//���ٹ�ϣͰ
void HashBucketDestroy(HBucket* ht);


#endif