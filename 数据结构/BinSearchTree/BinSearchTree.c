#include "BinSearchTree.h"


//��ʼ��
void BSTreeInit(PBSTree* pRoot)
{
	assert(pRoot);

	*pRoot = NULL;
}

//�����½ڵ�
PBSTree BuyNewNode(DataType data)
{
	PBSTree ptr = NULL;
	ptr = (PBSTree)malloc(sizeof(BSTree));
	if (NULL == ptr)
	{
		assert(0);
		return NULL;
	}

	ptr->_data = data;
	ptr->_pLeft = NULL;
	ptr->_pRight = NULL;

	return ptr;
}


//���룬���ң�ɾ���ǵݹ�

//����Ԫ��
void BSTreeInsert(PBSTree* pRoot, DataType data)
{
	PBSTree pCur = *pRoot;
	PBSTree pParent = NULL;
	assert(pRoot);

	//���ж��Ƿ�Ϊ����
	if (NULL == *pRoot)
	{
		*pRoot = BuyNewNode(data);
		return;
	}

	//�ҵ�����λ�ã����������λ�õ�˫�׽��
	while (pCur)
	{
		//�嵽���
		if (pCur->_data > data)
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}

		//�嵽�ұ�
		else if (pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}

		//�������
		else
			return;
	}

	if (data > pParent->_data)
		pParent->_pRight = BuyNewNode(data);

	if (data < pParent->_data)
		pParent->_pLeft = BuyNewNode(data);


}

//����Ԫ��
PBSTree BSTreeFind(PBSTree pRoot, DataType data)
{
	PBSTree pCur = pRoot;

	if (pRoot == NULL)
	{
		printf("���ѿգ�����ʧ��!\n");
		return NULL;
	}

	while (pCur)
	{
		if (pCur->_data == data)
			return pCur;

		else if (data > pCur->_data)
			pCur = pCur->_pRight;

		else
			pCur = pCur->_pLeft;
	}

	printf("û�иýڵ�!\n");
	return NULL;
}


//����������ɾ��
void BSTreeDelete(PBSTree* pRoot, DataType data)
{
	PBSTree pCur = *pRoot;
	PBSTree pParent = NULL;
	assert(pRoot);

	//���Ϊ������ֱ�ӷ���
	if (NULL == pRoot)
		return;

	//����ֵΪdata�Ľڵ�
	while (pCur)
	{
		if (pCur->_data == data)
			break;

		else if (data > pCur->_data)
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}

		else
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}
	}

	//���pCurΪ�գ�˵������û�иýڵ�
	if (NULL == pCur)
		return;

	else
	{
		//�����ɾ�ڵ�û��������������������û��
		//ֱ��ɾ
		if (!pCur->_pRight)
		{
			//�жϴ�ɾ�ڵ�����˫�׽ڵ��ʲô�ڵ�
			if (pCur->_data > pParent->_data)//��
				pParent->_pRight = pCur->_pLeft;

			else
				pParent->_pLeft = pCur->_pLeft;

		}

		//�����ɾ�ڵ�û��������
		//ֱ��ɾ
		else if (!pCur->_pLeft)
		{
			if (pCur->_data > pParent->_data)//��
				pParent->_pRight = pCur->_pRight;

			else
				pParent->_pLeft = pCur->_pRight;

		}

		//�����ɾ�ڵ���������������
		//����ֱ��ɾ
		else
		{
			//���ڴ�ɾ�ڵ����������������Ҵ���ڵ�
			//������--����С�ڵ�--������ڵ�
			//������--�����ڵ�--�����ҽڵ�
			
			//������������С�ڵ����滻����֮ǰ�Ƚ�˫�׽ڵ�Ų����
			PBSTree ptr = pCur;//���������ɾ�ڵ�
			pParent = pCur;//�����������ڵ��˫��
			pCur = pCur->_pRight;

			while (pCur->_pLeft)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}

			//�Ƚ���ɾ�ڵ�data�����ڵ�data����
			ptr->_data = pCur->_data;

			//�жϴ���ڵ�����˫�׵�ʲô�ڵ�
			if(pCur == pParent->_pLeft)//��
				pParent->_pLeft = pCur->_pRight;//��Ϊ����ڵ�����������С�ģ�����һ��û��������

			else
				pParent->_pRight = pCur->_pRight;

		}
	}

	free(pCur);
}

//���ҡ����롢ɾ���ݹ�


//����Ԫ��
void BSTreeInsert(PBSTree* pRoot, DataType data)
{
	assert(pRoot);

	if(NULL == *pRoot)
		*pRoot = BuyNewNode(data);

	else
	{
		if (data > (*pRoot)->_data)
			BSTreeInsert(&(*pRoot)->_pRight, data);

		else if (data < (*pRoot)->_data)
			BSTreeInsert(&(*pRoot)->_pLeft, data);

		//������������Ѿ���data�����
		else
			return;

	}
}

//����Ԫ��
PBSTree BSTreeFind(PBSTree pRoot, DataType data)
{

	if (NULL == pRoot)
		return NULL;

	else
	{
		//���dataС��pRoot��data���͵�t����������
		if (data < pRoot->_data)
			return BSTreeFind(pRoot->_pLeft, data);

		//���data����pRoot��data���͵�t����������
		else if (data > pRoot->_data)
			return BSTreeFind(pRoot->_pRight, data);

		//���ڣ�ֱ�ӷ��ؽڵ�
		else
			return pRoot;
	}
}

//����������ɾ��
void BSTreeDelete(PBSTree* pRoot, DataType data)
{
	assert(pRoot);

	//����ֱ�ӷ���
	if (NULL == *pRoot)
		return;

	else
	{	
		//���ҵ���ɾ���ڵ�
		//���С������������
		if (data < (*pRoot)->_data)
			BSTreeDelete(&(*pRoot)->_pLeft, data);

		//����󣬵���������
		else if (data >(*pRoot)->_data)
			BSTreeDelete(&(*pRoot)->_pRight, data);

		//˵���ҵ���
		else
		{
			//���û����������������������û��
			//ֱ��ɾ
			PBSTree pDel = *pRoot;
			if (!(*pRoot)->_pRight)
			{
				*pRoot = pDel->_pLeft;
				free(pDel);
			}

			//���û����������Ҳֱ��ɾ
			else if (!(*pRoot)->_pLeft)
			{
				*pRoot = pDel->_pRight;
				free(pDel);
			}
			
			//�����������������
			else
			{
				//��*pRoot����������С�ڵ�--�����
				pDel = (*pRoot)->_pRight;

				while (pDel->_pLeft)
					pDel = pDel->_pLeft;

				//������ڵ��ֵ����*pRoot
				(*pRoot)->_data = pDel->_data;

				//��*pRoot��������ɾ��ֵΪpDel->data�Ľڵ�
				BSTreeDelete(&(*pRoot)->_pRight, pDel->_data);

			}
		}
	}
}




//�������������
void InOrder(PBSTree pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%d ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

//����--����ݹ�
void BSTreeDestory(PBSTree* pRoot)
{
	assert(pRoot);

	if (*pRoot)
	{
		//������������
		BSTreeDestory(&(*pRoot)->_pLeft);

		//������������
		BSTreeDestory(&(*pRoot)->_pRight);

		//���ٸ��ڵ�
		free(*pRoot);
		*pRoot = NULL;
	}

}

