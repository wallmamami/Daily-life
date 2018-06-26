#include "Heap.h"



//��ʼ����
void HeapInit(Heap* hp, Compare com)
{
	assert(hp);

	hp->arr = (DataType*)malloc(sizeof(DataType)*3);
	if (NULL == hp->arr)
	{
		assert(0);
		return;
	}
	//����ɹ�
	hp->_Capacity = 3;
	hp->_size = 0;
	hp->com = com;

}


//�ȽϷ���
//���
int Greater(DataType left, DataType right)
{
	if (left > right)
		return 1;
	return 0;
}

//С��
int Less(DataType left, DataType right)
{
	if (left < right)
		return 1;
	return 0;
}

void _Swap(DataType* left, DataType* right)
{
	DataType tmp = 0;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

//���µ�����
void _AdjustDown(Heap* hp, int parent)
{
	assert(hp);

	int child = (parent << 1) + 1;//Ĭ�����ӽ�С

	while (child < hp->_size)
	{
		//��Ҫ��֤���Һ���
		//����Һ��ӱ����ӻ�С�����±��
		if (child + 1 < hp->_size && hp->com(hp->arr[child + 1], hp->arr[child]))
			child += 1;

		//���˫�ױȺ��Ӵ󣬽���
		if (hp->com(hp->arr[child], hp->arr[parent]))
		{
			_Swap(&(hp->arr[child]), &(hp->arr[parent]));

			//�����ߣ���Ϊ����֮����ܻ��ƻ�����Ķѡ�
			parent = child;
			child = (parent << 1) + 1;
		}

		//˵���Ѿ��Ƕ�
		else
			return;
	}
}

//�ѵĴ���
void CreateHeap(Heap* hp, DataType* arr, int size)
{
	int i = 0;
	int root = (size - 2) / 2;//��ǵ�һ����Ҷ�ӽڵ�
	assert(hp);

	//�ȸ�������ռ�
	hp->arr = (DataType*)realloc(hp->arr, sizeof(DataType)*size);
	if (NULL == arr)
	{
		assert(0);
		return;
	}
	//����ɹ�
	hp->_Capacity = size;
	hp->_size = size;

	//������Ԫ�ط������
	for (; i < size; i++)
		hp->arr[i] = arr[i];

	//�����µ�����������
	for (i = root; i >= 0; i--)
		_AdjustDown(hp, i);
}

void _CheckCapacity(Heap* hp)
{
	assert(hp);

	if (hp->_Capacity == hp->_size)//˵���ռ�����
	{
		hp->arr = (DataType*)realloc(hp->arr, sizeof(DataType)*(hp->_Capacity) * 2);//����λԭ�ռ�2��
		if (NULL == hp->arr)
		{
			assert(0);
			return;
		}

		hp->_Capacity = 2 * hp->_Capacity;
	}
}

//���ϵ�����
void _AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;
	assert(hp);

	while (child != 0)
	{
		//�������С��˫�ף�����
		if (hp->com(hp->arr[child], hp->arr[parent]))
		{
			_Swap(&(hp->arr[child]), &(hp->arr[parent]));

			//�����ߣ���Ϊ����������ƻ�����Ķ�
			child = parent;
			parent = (child - 1) >> 1;
		}

		//˵���Ѿ��Ƕ�
		else
			return;
	}
}

//����Ԫ��
void InsertHeap(Heap* hp, DataType data)
{
	assert(hp);

	//���ռ�
	_CheckCapacity(hp);

	//�ڶ�β����Ԫ��
	hp->arr[hp->_size++] = data;

	//�����ϵ�����������
	_AdjustUp(hp, hp->_size - 1);
}

//ɾ���Ѷ�Ԫ��
void DeleteHeap(Heap* hp)
{
	assert(hp);

	//�ж϶��Ƿ�Ϊ��
	if (EmptyHeap(hp))
		return;

	//�Ƚ��Ѷ�Ԫ�غͶ�βԪ�ؽ���,��ɾ����βԪ��
	_Swap(&(hp->arr[0]), &hp->arr[hp->_size - 1]);
	hp->_size--;

	//�����µ�������������
	_AdjustDown(hp, 0);
	
}

//�鿴�Ѷ�Ԫ��
DataType HeapTop(Heap* hp)
{
	assert(hp);

	if (hp->_size == 0)
	{
		assert(0);
		return 0;
	}

	return hp->arr[0];
}

//�鿴����Ԫ�ظ���
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}

//���п�
int EmptyHeap(Heap* hp)
{
	assert(hp);

	if (hp->_size == 0)
		return 1;

	return 0;
}

//���ٶ�
void DestoryHeap(Heap* hp)
{
	assert(hp);

	hp->_size = 0;
	hp->_Capacity = 0;
	free(hp->arr);
	hp->arr = NULL;
	
	return;
}


/////////////////////////
//����
//����--���
//����--С��
void AdjustHeap(int* arr, int size, int parent)
{
	int child = (parent << 1) + 1;
	assert(arr);

	while (child < size)
	{
		if (child + 1 < size && arr[child] > arr[child + 1])
			child += 1;

		if (arr[parent] > arr[child])
		{
			_Swap(arr + parent, arr + child);
			parent = child;
			child = (parent << 1) + 1;
		}

		else
			return;
	}
}
void HeapSort(int* arr, int size)
{
	int root = (size - 2) >> 1;
	int i = 0;
	int end = size - 1;

	assert(arr);
	
	//����
	for (i = root; i >= 0; i--)
		AdjustHeap(arr, size, i);

	//����--���Ѷ�Ԫ�ء�ɾ����
	while (end)
	{
		_Swap(arr + 0, arr + end);
		AdjustHeap(arr, end, 0);

		end--;

	}
}