#include "HashTable.h"
#include "comm.h"


//��ϣ����
static int HashFunc(HTable* ht, int data)
{
	assert(ht);

	return ht->pDTInt(data) % (ht->_capacity);
}


//�����ϣ��ͻ�ķ���--����̽��
int IsLineDetec(HTable* ht, int addr)
{

	addr = addr + 1;
	if (addr == ht->_capacity)//���Խ��
		addr = 0;

	return addr;
}

//����̽��
int NotIsLineDetec(HTable* ht, int addr, int i)
{
	addr = addr + 2 * i + 1;

	//���Խ�粻��ֱ�����㣬��Ϊ�п���i��ֵ���������ۼӱ����Ѿ���������
	if (addr >= ht->_capacity)
		addr %= ht->_capacity;
	return addr;
}
//��ʼ��
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

//�������
void CheckCapacity(HTable* ht)
{
	assert(ht);
	if ((ht->_total) * 10 / (ht->_capacity) >= 7)//��������
	{
		int i = 0;
		//�����¹�ϣ��
		HTable NewHt;

		//��ʼ���¹�ϣ��
		HashTableInit(&NewHt, ht->_capacity*2, ht->DetecWay, ht->pDTInt);

		//��ԭ��ϣ���е���ЧԪ��(EX)�嵽�¹�ϣ��Ŀռ�
		for (; i < ht->_capacity; i++)
		{
			if (EX == ht->_table[i].stat)
				HashTableInsert(&NewHt, ht->_table[i]._data);
		}

		//�����¾ɹ�ϣ��
		Swap(&NewHt, ht);

		//�����¹�ϣ��
		HashTableDestory(&NewHt);
	}

}

//����Ԫ��
void HashTableInsert(HTable* ht, DataType data)
{
	int addr = 0;
	int i = 0;
	assert(ht);

	//�������
	CheckCapacity(ht);

	addr = HashFunc(ht, data);

	//���������ĵ�ַ���ǿգ���Ҫһֱ���µ�ַ
	while (EM != ht->_table[addr].stat)
	{
		//��ƵĹ�ϣ���е�����Ψһ
		if (ht->_table[addr].stat == EX)
		{
			if (ht->_table[addr]._data == data)
				return;
		}

		//������ĵ�ַ����ʹ�ã�������ϣ��ͻ
		if (ht->DetecWay == _IsLine)
			addr = IsLineDetec(ht, addr);
		else
			addr = NotIsLineDetec(ht, addr, ++i);
	}

	//˵��״̬Ϊ�գ�����ֱ�Ӳ���
	ht->_table[addr].stat = EX;
	ht->_table[addr]._data = data;
	ht->_size++;
	ht->_total++;
}

//����Ԫ��,�ҵ����ص�ַ
int HashTableFind(HTable* ht, DataType data)
{
	int addr = 0;
	int startaddr = 0;
	int i = 0;
	assert(ht);
	
	addr = HashFunc(ht, data);
	startaddr = addr;

	//���������ĵ�ַ���ǿգ���Ҫһֱ���µ�ַ
	while (EM != ht->_table[addr].stat)
	{
		//��ƵĹ�ϣ���е�����Ψһ
		if (ht->_table[addr].stat == EX)
		{
			if (ht->_table[addr]._data == data)
				return addr;
		}

		//������ĵ�ַ����ʹ�ã�������ϣ��ͻ
		if (ht->DetecWay == _IsLine)

		{
			addr = IsLineDetec(ht, addr);
			//���ת��һȦ��û�ҵ����Ϳ϶�û��
			if (addr == startaddr)
				return -1;

		}
		else
			addr = NotIsLineDetec(ht, addr, ++i);

	}

	return -1;
}


//ɾ��Ԫ��
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

//���ٹ�ϣ��
void HashTableDestory(HTable* ht)
{
	assert(ht);
	free(ht->_table);
	ht->_table = NULL;
	ht->_capacity = 0;
	ht->_size = 0;
	ht->_total = 0;
}