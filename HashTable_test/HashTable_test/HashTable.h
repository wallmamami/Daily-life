#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__


#include <stdio.h>
#include <assert.h>
#include <malloc.h>

//��ϣ����ÿ��λ�õ�״̬
typedef enum Stat
{
	EM,  //��
	EX,  //����
	DE   //��ɾ��
}Stat;

typedef int DataType;
typedef size_t(*PDTInt)(DataType str);

typedef enum
{
	_IsLine,          //����̽��
	_IsNotLine		  //����̽��
}IsLine;

//��ϣ��ÿ��λ�ð������ݺ����λ�õ�״̬
typedef struct Elem
{
	DataType _data;
	Stat stat;
}Elem;

typedef struct HashTable
{
	Elem* _table;
	int _capacity;    //����
	int _size;        //��ЧԪ�ظ���
	int _total;      //��ЧԪ�غͱ�ɾ����Ԫ��֮��
	IsLine DetecWay;    //������ϣ��ͻ��̽�ⷽ��
	PDTInt pDTInt;      //������ת��Ϊ���ͣ�����ָ��
}HTable;


//�����ϣ��ͻ�ķ���--����̽��
int IsLineDetec(HTable* ht, int addr);

//����̽��
int NotIsLineDetec(HTable* ht, int addr, int i);

//��ʼ��
void HashTableInit(HTable* ht, int capacity, IsLine DetecWay, PDTInt pDtInt);
//����Ԫ��
void HashTableInsert(HTable* ht, DataType data);

//����Ԫ��,�ҵ����ص�ַ
int HashTableFind(HTable* ht, DataType data);

//ɾ��Ԫ��
void HashTableDelete(HTable* ht, DataType data);

int HashTableSize(HTable* ht);

int HashTableEmpty(HTable* ht);

//���ٹ�ϣ��
void HashTableDestory(HTable* ht);


#endif
