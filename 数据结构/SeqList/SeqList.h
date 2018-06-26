#pragma once
#include <stdio.h>
#define MAX_SIZE 10 

typedef struct SeqList
{
	int arr[MAX_SIZE];
	int size; // ��ʾ˳�������ЧԪ�صĸ��� 
}SeqList, *PSeqList;




// ˳���ĳ�ʼ�� 
void SeqListInit(PSeqList ps);

// ˳����β�� 
void SeqListPushBack(PSeqList ps, int data);

// ˳����βɾ 
void SeqListPopBack(PSeqList ps);

// ˳����ͷ�� 
void SeqListPushFront(PSeqList ps, int data);

// ˳����ͷɾ 
void SeqListPopFront(PSeqList ps);

// ˳���posλ�ò���Ԫ��data 
void SeqListInsert(PSeqList ps, int pos, int data);

// ɾ��˳���posλ��Ԫ�� 
void SeqListErase(PSeqList ps, int pos);

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void Remove(PSeqList ps, int data);

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void RemoveAll(PSeqList ps, int data);

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е�λ�ã����򷵻�-1 
int SeqListFind(PSeqList ps, int data);

// ��ȡ˳�����Ԫ�صĸ��� 
int SeqListSize(PSeqList ps);
//�������� 
// ��ӡ˳��� 
void PrintSeqList(PSeqList ps);

// ʹ��ð�������˳����е�Ԫ�ؽ������� 
void BubbleSort(PSeqList ps);

//ʹ��ѡ�������˳����е�Ԫ�ؽ������� 
void SelectSort(PSeqList ps);

