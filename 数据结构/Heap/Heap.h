#ifndef __HEAP_H__
#define __HEAP_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int DataType;
typedef int(*Compare)(DataType left, DataType right);//�ȽϷ����ĺ���ָ��

//�ѵ�����
typedef struct Heap
{
	DataType* arr;//�����Ĵ洢�ռ�
	int _Capacity;//�ռ�������
	int _size;//��ЧԪ�ظ���
	Compare com;
}Heap;


//��ʼ����
void HeapInit(Heap* hp, Compare com);

//�ȽϷ���
//���
int Greater(DataType left, DataType right);
//С��
int Less(DataType left, DataType right);
void _Swap(DataType* left, DataType* right);
//�ѵĴ���
void CreateHeap(Heap* hp, DataType* arr, int size);

//����Ԫ��
void InsertHeap(Heap* hp, DataType data);

//ɾ���Ѷ�Ԫ��
void DeleteHeap(Heap* hp);

//�鿴�Ѷ�Ԫ��
DataType HeapTop(Heap* hp);

//�鿴����Ԫ�ظ���
int HeapSize(Heap* hp);

//���п�
int EmptyHeap(Heap* hp);

//���ٶ�
void DestoryHeap(Heap* hp);

//����
void HeapSort(int* arr, int size);

#endif