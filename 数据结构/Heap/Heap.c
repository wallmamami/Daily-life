#include "Heap.h"



//初始化堆
void HeapInit(Heap* hp, Compare com)
{
	assert(hp);

	hp->arr = (DataType*)malloc(sizeof(DataType)*3);
	if (NULL == hp->arr)
	{
		assert(0);
		return;
	}
	//申请成功
	hp->_Capacity = 3;
	hp->_size = 0;
	hp->com = com;

}


//比较方法
//大堆
int Greater(DataType left, DataType right)
{
	if (left > right)
		return 1;
	return 0;
}

//小堆
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

//向下调整法
void _AdjustDown(Heap* hp, int parent)
{
	assert(hp);

	int child = (parent << 1) + 1;//默认左孩子较小

	while (child < hp->_size)
	{
		//先要保证有右孩子
		//如果右孩子比左孩子还小，重新标记
		if (child + 1 < hp->_size && hp->com(hp->arr[child + 1], hp->arr[child]))
			child += 1;

		//如果双亲比孩子大，交换
		if (hp->com(hp->arr[child], hp->arr[parent]))
		{
			_Swap(&(hp->arr[child]), &(hp->arr[parent]));

			//向下走，因为调整之后可能会破坏下面的堆、
			parent = child;
			child = (parent << 1) + 1;
		}

		//说明已经是堆
		else
			return;
	}
}

//堆的创建
void CreateHeap(Heap* hp, DataType* arr, int size)
{
	int i = 0;
	int root = (size - 2) / 2;//标记第一个非叶子节点
	assert(hp);

	//先给堆申请空间
	hp->arr = (DataType*)realloc(hp->arr, sizeof(DataType)*size);
	if (NULL == arr)
	{
		assert(0);
		return;
	}
	//申请成功
	hp->_Capacity = size;
	hp->_size = size;

	//将数组元素放入堆中
	for (; i < size; i++)
		hp->arr[i] = arr[i];

	//用向下调整法调整堆
	for (i = root; i >= 0; i--)
		_AdjustDown(hp, i);
}

void _CheckCapacity(Heap* hp)
{
	assert(hp);

	if (hp->_Capacity == hp->_size)//说明空间已满
	{
		hp->arr = (DataType*)realloc(hp->arr, sizeof(DataType)*(hp->_Capacity) * 2);//扩容位原空间2倍
		if (NULL == hp->arr)
		{
			assert(0);
			return;
		}

		hp->_Capacity = 2 * hp->_Capacity;
	}
}

//向上调整法
void _AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;
	assert(hp);

	while (child != 0)
	{
		//如果孩子小于双亲，交换
		if (hp->com(hp->arr[child], hp->arr[parent]))
		{
			_Swap(&(hp->arr[child]), &(hp->arr[parent]));

			//朝上走，因为交换完可能破坏上面的堆
			child = parent;
			parent = (child - 1) >> 1;
		}

		//说明已经是堆
		else
			return;
	}
}

//插入元素
void InsertHeap(Heap* hp, DataType data)
{
	assert(hp);

	//检查空间
	_CheckCapacity(hp);

	//在堆尾插入元素
	hp->arr[hp->_size++] = data;

	//用向上调整法调整堆
	_AdjustUp(hp, hp->_size - 1);
}

//删除堆顶元素
void DeleteHeap(Heap* hp)
{
	assert(hp);

	//判断堆是否为空
	if (EmptyHeap(hp))
		return;

	//先将堆顶元素和堆尾元素交换,并删除堆尾元素
	_Swap(&(hp->arr[0]), &hp->arr[hp->_size - 1]);
	hp->_size--;

	//用向下调整法调整队列
	_AdjustDown(hp, 0);
	
}

//查看堆顶元素
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

//查看堆总元素个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}

//堆判空
int EmptyHeap(Heap* hp)
{
	assert(hp);

	if (hp->_size == 0)
		return 1;

	return 0;
}

//销毁堆
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
//堆排
//升序--大堆
//降序--小堆
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
	
	//建堆
	for (i = root; i >= 0; i--)
		AdjustHeap(arr, size, i);

	//排序--将堆顶元素“删除”
	while (end)
	{
		_Swap(arr + 0, arr + end);
		AdjustHeap(arr, end, 0);

		end--;

	}
}