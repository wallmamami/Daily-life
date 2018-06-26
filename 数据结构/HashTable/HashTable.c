#include "HashTable.h"
#include "comm.h"


//哈希函数
static int HashFunc(HTable* ht, int data)
{
	assert(ht);

	return ht->pDTInt(data) % (ht->_capacity);
}


//处理哈希冲突的方法--线性探测
int IsLineDetec(HTable* ht, int addr)
{

	addr = addr + 1;
	if (addr == ht->_capacity)//如果越界
		addr = 0;

	return addr;
}

//二次探测
int NotIsLineDetec(HTable* ht, int addr, int i)
{
	addr = addr + 2 * i + 1;

	//如果越界不能直接置零，因为有可能i的值经过不断累加本身已经大于容量
	if (addr >= ht->_capacity)
		addr %= ht->_capacity;
	return addr;
}
//初始化
void HashTableInit(HTable* ht, int capacity, IsLine DetecWay, PDTInt pDtInt)
{
	int i = 0;
	assert(ht);

	capacity = GetCapacity(capacity);
	ht->_table = (Elem*)malloc(sizeof(Elem)*capacity);

	if (NULL == ht->_table)
		return;

	for (; i < capacity; i++)
		ht->_table[i].stat = EM;

	ht->_capacity = capacity;
	ht->_size = 0;
	ht->_total = 0;
	ht->DetecWay = DetecWay;
	ht->pDTInt = pDtInt;
}

void _Swap(int* left, int* right)
{
	assert(left);
	assert(right);

	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}

void Swap(HTable* lht, HTable* rht)
{
	assert(lht);
	assert(rht);

	_Swap(&(lht->_capacity), &(rht->_capacity));
	_Swap(&(lht->_size), &(rht->_size));
	_Swap((int*)&(lht->_table), (int*)&(rht->_table));
	_Swap(&(lht->_total), &(rht->_total));
}

//检测容量
void CheckCapacity(HTable* ht)
{
	assert(ht);
	if ((ht->_total) * 10 / (ht->_capacity) >= 7)//负载因子
	{
		int i = 0;
		//创建新哈希表
		HTable NewHt;

		//初始化新哈希表
		HashTableInit(&NewHt, ht->_capacity*2, ht->DetecWay, ht->pDTInt);

		//将原哈希表中的有效元素(EX)插到新哈希表的空间
		for (; i < ht->_capacity; i++)
		{
			if (EX == ht->_table[i].stat)
				HashTableInsert(&NewHt, ht->_table[i]._data);
		}

		//交换新旧哈希表
		Swap(&NewHt, ht);

		//销毁新哈希表
		HashTableDestory(&NewHt);
	}

}

//插入元素
void HashTableInsert(HTable* ht, DataType data)
{
	int addr = 0;
	int i = 0;
	assert(ht);

	//检查容量
	CheckCapacity(ht);

	addr = HashFunc(ht, data);

	//如果计算出的地址不是空，就要一直找新地址
	while (EM != ht->_table[addr].stat)
	{
		//设计的哈希表中的数据唯一
		if (ht->_table[addr].stat == EX)
		{
			if (ht->_table[addr]._data == data)
				return;
		}

		//计算出的地址不能使用，发生哈希冲突
		if (ht->DetecWay == _IsLine)
			addr = IsLineDetec(ht, addr);
		else
			addr = NotIsLineDetec(ht, addr, ++i);
	}

	//说明状态为空，可以直接插入
	ht->_table[addr].stat = EX;
	ht->_table[addr]._data = data;
	ht->_size++;
	ht->_total++;
}

//查找元素,找到返回地址
int HashTableFind(HTable* ht, DataType data)
{
	int addr = 0;
	int startaddr = 0;
	int i = 0;
	assert(ht);
	
	addr = HashFunc(ht, data);
	startaddr = addr;

	//如果计算出的地址不是空，就要一直找新地址
	while (EM != ht->_table[addr].stat)
	{
		//设计的哈希表中的数据唯一
		if (ht->_table[addr].stat == EX)
		{
			if (ht->_table[addr]._data == data)
				return addr;
		}

		//计算出的地址不能使用，发生哈希冲突
		if (ht->DetecWay == _IsLine)

		{
			addr = IsLineDetec(ht, addr);
			//如果转了一圈都没找到，就肯定没有
			if (addr == startaddr)
				return -1;

		}
		else
			addr = NotIsLineDetec(ht, addr, ++i);

	}

	return -1;
}


//删除元素
void HashTableDelete(HTable* ht, DataType data)
{
	int ret = 0;
	assert(ht);

	if (-1 == ret)
		return;

	ht->_table[ret].stat = DE;
	ht->_size--;
}

int HashTableSize(HTable* ht)
{
	return ht->_size;
}

int HashTableEmpty(HTable* ht)
{
	return ht->_size == 0;
}

//销毁哈希表
void HashTableDestory(HTable* ht)
{
	assert(ht);
	free(ht->_table);
	ht->_table = NULL;
	ht->_capacity = 0;
	ht->_size = 0;
	ht->_total = 0;
}