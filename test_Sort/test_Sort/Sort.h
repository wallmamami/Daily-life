#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>




//��������
void InsertSort(int *arr, int size);
void InsertSort_OP(int *arr, int size);

//ϣ������
void ShellSort(int *arr, int size);

//ѡ������
void SelectSort(int *arr, int size);
void SelectSort_OP(int *arr, int size);


//����
void HeapSort(int *arr, int size);

//ð������
void BubbleSort(int* arr, int size);

//��������
void QuickSort(int *arr, int size);

//�鲢����
void MergeSort(int *arr, int size);
//�ǵݹ�
void MergeSortNor(int *arr, int size);

//��������
void CountSort(int *arr, int size);

