#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct SeqListD
{
	DataType *arr;
	int capacity;//�ռ�����
	int size;//��ЧԪ�ظ���
}SeqListD, *PSeqListD;



void SeqListDInit(PSeqListD ps, int capacity);//��ʼ��
void CheckCapacity(PSeqListD ps);// ��˳���������� 
void SeqListDPushBack(PSeqListD ps, DataType data);//β��
void SeqListDPopBack(PSeqListD ps);//βɾ
void SeqListDInsert(PSeqListD ps, int pos, DataType data);//����λ�ò���
void SeqListDErase(PSeqListD ps, int pos);//����λ��ɾ��

int SeqListDSize(PSeqListD ps);// ��ȡԪ�ظ��� 

int SeqListDCapacity(PSeqListD ps);// ��ȡ˳��������
int SeqListDEmpty(PSeqListD ps);//�п�,Ϊ�շ���0��

void SeqListDClear(PSeqListD ps);// ��˳����е�Ԫ����� ע�⣺���ı�˳���ռ�Ĵ�С 
void SeqListDDestroy(PSeqListD ps);//����˳���

