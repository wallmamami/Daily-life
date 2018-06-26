#include "BinSearchTree.h"


void Test1()
{
	int i = 0;
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PBSTree pRoot;

	BSTreeInit(&pRoot);
	for (; i < size; i++)
		BSTreeInsert(&pRoot, arr[i]);
	InOrder(pRoot);

	printf("\n");
	BSTreeDelete(&pRoot, 5);
	InOrder(pRoot);

	BSTreeDelete(&pRoot, 8);
	printf("\n");
	InOrder(pRoot);

	BSTreeDelete(&pRoot, 2);
	printf("\n");
	InOrder(pRoot);
}

int main()
{
	Test1();//²âÊÔ¶þ²æËÑË÷Ê÷
}