#include "Sort.h"

int main()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	//InsertSort(arr, size);//��������
	//InsertSort_OP(arr, size);

	//ShellSort(arr, size);//ϣ������

	//SelectSort(arr, size);//ѡ������
	//SelectSort_OP(arr, size);

	//HeapSort(arr, size);//����

	//BubbleSort(arr, size);//ð������

	//QuickSort(arr, size);//��������

	//MergeSort(arr, size);//�鲢����
	//MergeSortNor(arr, size);

	CountSort(arr, size);
	for (; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}