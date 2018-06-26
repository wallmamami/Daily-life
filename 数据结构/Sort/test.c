#include "Sort.h"

int main()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	//InsertSort(arr, size);//≤Â»Î≈≈–Ú
	//InsertSort_OP(arr, size);

	//ShellSort(arr, size);//œ£∂˚≈≈–Ú

	//SelectSort(arr, size);//—°‘Ò≈≈–Ú
	//SelectSort_OP(arr, size);

	//HeapSort(arr, size);//∂—≈≈

	//BubbleSort(arr, size);//√∞≈›≈≈–Ú

	//QuickSort(arr, size);//øÏÀŸ≈≈–Ú

	//MergeSort(arr, size);//πÈ≤¢≈≈–Ú
	//MergeSortNor(arr, size);

	CountSort(arr, size);
	for (; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}