#include "Sort.h"


//1.插入排序：时间复杂度：O(n^2),空间复杂度O(1),稳定
//特点：数据越少，越接近有序，搬移元素越少，效率越高
void InsertSort(int *arr, int size)
{
	int i = 0;

	//因为一个数据一定有序
	for (i = 1; i < size; i++)
	{
		int key = arr[i];//每次拿到一个数据，朝前面插
		int end = i - 1;

		//升序
		//循环里面就是找位置，搬移元素
		while (end >= 0 && key < arr[end])
		{
			arr[end + 1] = arr[end];//如果key比arr[end]小，就要将end位置的元素朝后搬移，给key腾地方
			--end;
		}

		//出来说明已经找到key的插入位置
		arr[end + 1] = key;
	}
}

//优化：因为上面的方法中，主要就是找位置和搬移元素，但是，每次找位置都是在有
//序数据中找，所以这里可以将找位置和搬移元素分开，用二分查找找位置。--时间复杂度O(n^2)
void InsertSort_OP(int *arr, int size)
{
	int i = 0;

	for (i = 1; i < size; i++)
	{
		int key = arr[i];
		int end = i - 1;
		int left = 0;
		int right = end;

		//利用二分查找找位置
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (key < arr[mid])
				right = mid - 1;

			//为了使排序稳定，所以这里大于等于都是右边
			else
				left = mid + 1;
		}

		//将left到end间所有元素向后搬移
		while (end >= left)
		{
			arr[end + 1] = arr[end];//如果key比arr[end]小，就要将end位置的元素朝后搬移，给key腾地方
			--end;
		}

		//插入位置就是left
		arr[left] = key;
	}
}

//2.希尔排序--当数据量非常大的时候，因为插入排序的特性，处理起来就会很麻烦，这里我们可以将数据按照一定的
//间隔进行分组，然后分别对每组用插入排序的思想进行排序，然后减小间隔，再继续，这就是希尔排序
//不稳定--隔着区间插入，空间复杂度O(1)，时间复杂度大概O(n^1.25 ~ 1.6n^1.25),应用于数据量大
void ShellSort(int *arr, int size)
{
	int i = 0;
	//int gap = 3;//间隔大小
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3  + 1;

		//从gap位置开始
		//这里++i而不是i+=gap，因为先处理第一组，再处理第二组.....
		for (i = gap; i < size; i++)
		{
			int key = arr[i];//每次拿到一个数据，朝前面插
			int end = i - gap;//前一个位置就是减gap

			//升序
			//循环里面就是找位置，搬移元素
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];//如果key比arr[end]小，就要将end位置的元素朝后搬移，给key腾地方
				end -= gap;
			}

			//出来说明已经找到key的插入位置
			arr[end + gap] = key;
		}
		
		//--gap;
	}
}

void static Swap(int *left, int *right)
{
	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}

//3.选择排序
//时间复杂度--O(n^2),空间复杂度--O(1)
void SelectSort(int *arr, int size)
{
	int i = 0;
	
	for (i = 0; i < size - 1; i++)
	{
		int j = 1;
		int maxPos = 0;
		for (; j < size - i; j++)
		{
			if (arr[maxPos] < arr[j])
				maxPos = j;
		}

		//如果一趟走完，maxpos不在最后一个，交换
		if (maxPos != size - i)
			Swap(arr + maxPos, arr + size - i -1);
	}
}

//优化--每一趟既要找出最大值，又要找出最小值，将最大值放到最后，将最小值放到开始
////时间复杂度--O(n^2),空间复杂度--O(1)
void SelectSort_OP(int *arr, int size)
{
	int start = 0;
	int end = size - 1;
	while (start < end)
	{
		int maxPos = start;
		int minPos = start;
		int j = start + 1;
		while (j <= end)
		{
			if (arr[maxPos] < arr[j])
				maxPos = j;
			if (arr[minPos] > arr[j])
				minPos = j;
			++j;
		}

		if (maxPos != end)
			Swap(arr + maxPos, arr + end);

		//如果minPos恰好标记end位置，就要将minPos标记maxPos
		if (minPos == end)
			minPos = maxPos;
		if (minPos != start)
			Swap(arr + minPos, arr + start);

		++start;
		--end;
	}
}

void _AdjustDown(int* arr, int parent, int size)
{
	int child = child = parent * 2 + 1;//默认左孩子为较大值

	while (child < size)
	{
		if (child + 1 < size && arr[child] < arr[child + 1])
			child += 1;

		if (arr[parent] < arr[child])
			Swap(arr + parent, arr + child);

		//朝下走
		parent = child;
		child = parent * 2 + 1;//默认左孩子为较大值
	}

}

//4.堆排--时间复杂度O(nlog2^n)不稳定
void HeapSort(int *arr, int size)
{
	int i = 0;
	int root = (size - 2) / 2;//从第一个非叶子节点开始
	int end = size - 1;

	//建堆
	for (i = root; i >= 0; i--)
		_AdjustDown(arr, i, size);

	while (end)
	{
		//“删除”堆顶元素
		Swap(arr, arr + end);
		_AdjustDown(arr, 0, end);
		--end;
	}
}

//5.冒泡排序--O(n^2)稳定
void BubbleSort(int* arr, int size)
{
	int i = 0;

	for (; i < size - 1; i++)
	{
		int j = 0;
		int flag = 0;
		for (; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr + j, arr + j + 1);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}

//6.快速排序--先将整个大区间按照给定的基准值，分为左半区间和右半区间，左区间都是小于基准值，右区间
//都是大于基准值（升序），然后左区间也按照这种思想，右区间同样，这样就可以将原数据排好。
//时间复杂度O(n^2),最好情况为O(nlog2^n),适用于给定的数据比较随机,不稳定

//三数取中法--因为快速排序是按照给出的基准值进行切分区间，给出的基准值如果是极值(最大值或最小值)就会造成
//类似于二叉搜索树的单只树，这样效率会大大降低，这里可以采用三数取中法获取基准值，进而对其进行优化
int GetMiddleData(int *arr, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (arr[left] < arr[right])
	{
		if (arr[mid] < arr[left])
			return left;
		else if (arr[mid] > arr[right])
			return right;
		else
			return mid;
	}

	else
	{
		if (arr[mid] < arr[right])
			return right;
		else if (arr[mid] > arr[left])
			return left;
		else
			return mid;
	}
}

//交换法--两个索引，一个从前找比基准值大的，一个从后找比基准小的，
//最后交换，停下来的位置，就是基准值应该放的位置。
int Partion1(int *arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = 0;
	int midIdx = GetMiddleData(arr, left, end);
	if (midIdx != end)
		Swap(arr + midIdx, arr + end);

	//这里给出的基准值每次都取区间的最后一个元素
	key = arr[end];

	while (begin < end)
	{
		//从前往后找比基准值大的元素
		while (begin < end && arr[begin] <= key)
			++begin;

		//从后往前找比基准值小的元素
		while (begin < end && arr[end] >= key)
			--end;

		//比基准值小的放到前面，比基准值大的放到后面(升序)
		if (begin < end)
			Swap(arr + begin, arr + end);
	}

	//出了循环，begin这个位置如果不是在最后，就将最后一个元素(基准值)和begin上的
	//元素交换，这样，begin之前的元素都小于基准值，begin之后的元素都大于基准值
	if (begin != right -1)
		Swap(arr + begin, arr + right -1);

	return begin;
}


//挖坑法--从前往后找比基准值大的元素，找到后交给end(end上的数据已经保存在key)，再从后
//往前找比基准值小的，找到后交给begin（begin上的数据已经保存在end），一直持续上过程
int Partion2(int *arr, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = 0;
	int midIdx = GetMiddleData(arr, left, end);
	if (midIdx != end)
		Swap(arr + midIdx, arr + end);

	key = arr[end];

	while (begin < end)
	{
		//从前往后找比基准值大的元素
		while (begin < end && arr[begin] <= key)
			++begin;

		if (begin < end)
		{
			arr[end] = arr[begin];
			--end;
		}

		//从后往前找比基准值小的元素
		while (begin < end && arr[end] >= key)
			--end;

		if (begin < end)
		{
			arr[begin] = arr[end];
			++begin;
		}
	}

	arr[begin] = key;
	return begin;
}

int Partion3(int *arr, int left, int right)
{
	int cur = left;
	int pre = left - 1;
	int end = right - 1;
	int key = 0;

	int midIdx = GetMiddleData(arr, left, end);
	if (midIdx != end)
		Swap(arr + midIdx, arr + end);

	key = arr[end];

	while (cur < right)
	{
		if (arr[cur] < key)
		{
			//当pre和cur相等时，说明前边元素都小于基准值
			pre++;
			//如果pre不等于cur，说明下标为pre的值大于基准值
			//交换下标为pre，cur的值
			if (pre != cur)
				Swap(arr + cur, arr + pre);

		}
		++cur;
	}

	//这时cur已经走到right，如果pre不等于cur，pre指向的是小于基准值的值
	//说明下标大于pre的值都大于基准值
	//++pre交换，将基准值放到这个位置
	if (++pre != right)
		Swap(arr + pre, arr + right-1);

	return pre;
}
//递归
void _QuickSort(int *arr, int left, int right)
{
	//只有一个数据一定有序
	if (right - left > 1)
	{
		int div = Partion3(arr, left, right);
		_QuickSort(arr, left, div);
		_QuickSort(arr, div + 1, right);
	}
}

//非递归--栈
//void QuickSortNor(int *arr, int size)
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, size);
//	StackPush(&s, 0);
//
//	while (!StackEmpty)
//	{
//		int left = 0, right = 0;
//		left = StackTop(&s);
//		StackPos(&s);
//
//		right = StackTop(&s);
//		StackPop(&s);
//
//		right = Stack(&s);
//		StackPos(&s);
//
//		if (left < right)
//		{
//			int div = Partion1(arr, left, right);
//			StackPush(&s, right);
//			
//			//div+1可能越界
//			StackPush(&s, div + 1);
//			StackPush(&s, div);
//			StackPush(&s, left);
//		}
//	}
//}
void QuickSort(int *arr, int size)
{
	//区间为左闭右开
	_QuickSort(arr, 0, size);
}

//7.归并排序--将有序的两组数据归并为一组有序的数据,属于外部排序，适用于数据量大的情况
//时间复杂度O(nlog2^n), 空间复杂度O(n)，稳定；
void MergeData(int *arr, int left, int mid, int right, int* tmp)
{
	//区间为左闭右开
	int beginL = left, endL = mid;
	int beginR = mid, endR = right;
	int index = left;//用于索引辅助空间

	while (beginL < endL && beginR < endR)
	{
		if (arr[beginL] <= arr[beginR])
			tmp[index++] = arr[beginL++];
		else
			tmp[index++] = arr[beginR++];
	}

	//左区间没有搬移完
	while (beginL < endL)
		tmp[index++] = arr[beginL++];

	//右区间没有搬移完
	while (beginR < endR)
		tmp[index++] = arr[beginR++];
}

void _MergeSort(int *arr, int left, int right, int *tmp)
{
	if (left+1 < right)
	{
		//每次进来都对数据进行平均切分区间，因为归并必须是两组有序的
		//数据，所以，切分到只剩一个数据时才是有序，才能进行归并.
		int mid = left + (right - left) / 2;

		//数据均分为两个区间(左闭右开)，左区间和右区间，先排左区间
		_MergeSort(arr, left, mid, tmp);

		//排右区间
		_MergeSort(arr, mid, right, tmp);

		//走到这里说明左右两个区间都已经有序，在进行归并
		MergeData(arr, left, mid, right, tmp);

		//将辅助空间已经排好序的数据拷贝到arr
		memcpy(arr + left, tmp + left, (right - left)*sizeof(arr[0]));

	}
}

//递归
void MergeSort(int *arr, int size)
{
	int *tmp = (int*)malloc(sizeof(int)*size);
	if (NULL == tmp)
		return;

	//区间为左闭右开
	_MergeSort(arr, 0, size, tmp);

	free(tmp);
}

//非递归
void MergeSortNor(int *arr, int size)
{
	int gap = 1;//划分区间，第一次就是一个元素为一个区间
	int *tmp = (int*)malloc(size*sizeof(arr[0]));
	if (NULL == tmp)
		return;

	while (gap < size)
	{
		int i = 0;
		for (; i < size; i += 2*gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			//有可能最后一组没有那么多元素，加gap可能会越界
			if (mid > size)
				mid = size;

			if (right > size)
				right = size;
			MergeData(arr, left, mid, right, tmp);
		}

		memcpy(arr, tmp, sizeof(arr[0])*size);
		gap *= 2;
	}
	free(tmp);
}

//8.计数排序：计数排序又称为鸽巢原理，是对哈希直接定址法的变形应用。
//1.统计相同元素出现次数 2.根据统计的结果将序列回收到原来的序列中  
//时间复杂度--O(N)N为数据个数  空间复杂度--O(M)M为数据的范围
void CountSort(int *arr, int size)
{
	int range = 0;//用来标识这组数据的范围
	int index = 0;
	int MaxValue = arr[0];//用来标识数据的最大值
	int MinValue = arr[0];
	int i = 0;
	int *count = NULL;//用来计数的空间

	for (i = 1; i < size; i++)
	{
		if (arr[i] > MaxValue)
			MaxValue = arr[i];

		if (arr[i] < MinValue)
			MinValue = arr[i];
	}

	//计算范围，这里一定要+1
	range = MaxValue - MinValue + 1;

	//这里用calloc是为了将空间元素初始化为0
	count = (int*)calloc(range, sizeof(arr[0]));
	if (NULL == count)
		return;

	//统计每个元素出现次数
	for (i = 0; i < size; i++)
	{
		//arr[i]-MinValue为count数组的下标
		count[arr[i] - MinValue]++;
	}

	//回收元素
	for (i = 0; i < size; i++)
	{
		//只要count[i]不为0，说明里面还有i+MinValue这个元素
		while (count[i]--)
			arr[index++] = i + MinValue;
	}

	free(count);
}