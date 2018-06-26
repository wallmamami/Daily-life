#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int DataType;

typedef struct SNode
{
	DataType data;
	struct SNode *_pNext;//�����¸��ڵ�ĵ�ַ

}SNode, *PNode;


typedef struct CSListNode
{
	DataType data;
	struct CSListNode *_pNext;
	struct CSListNode *_pRandom;

}CSListNode, *PCSLNode;

void SListInit(PNode* pHead);
// ����ĳ�ʼ�� 
void SListPushBack(PNode* pHead, DataType data);// β�� 
void SListPopBack(PNode* pHead);// βɾ 
void SListPushFront(PNode* pHead, DataType data);// ͷ�� 
void SListPopFront(PNode* pHead);// ͷɾ 
PNode SListFind(PNode pHead, DataType data);
// �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ��
void SListInsert(PNode* pHead, PNode pos, DataType data);
// ��posλ�ò���ֵΪdata�Ľ�� 
void SListErase(PNode* pHead, PNode pos);
// ɾ��posλ�õĽ�� 
int SListSize(PNode pHead);
// ��ȡ�����нڵ�����
int SListEmpty(PNode pHead);
// �ж������Ƿ�Ϊ�� 
void SListDestroy(PNode* pHead);// ��������
void PrintfList(PNode pHead);//��ӡ����




//������
void PrintSListFromTail2Head(PNode pHead);
// �����ӡ������ 
void DeleteListNotTailNode(PNode pos);
// ɾ������ķ�β��㣬Ҫ�󣺲��ܱ������� 
void InesrtPosFront(PNode pos, DataType data);
// ������posλ��ǰ����ֵ��data�Ľ�� 
PNode FindMiddleNode(PNode pHead);
// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindLastKNode(PNode pHead, int K);
// ��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
void DeleteLastKNode(PNode *pHead, int K);
// ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
void JosephCircle(PNode* pHead, const int M);
// �õ�����ʵ��Լɪ�� 
void ReverseSList(PNode* pHead);
// ���������--����ָ�� 
PNode ReverseSListOP(PNode pHead);
// ���������--ͷ�巨 
void BubbleSort(PNode pHead);
// ��ð������˼��Ե������������ 
PNode MergeSList(PNode pHead1, PNode pHead2);
// �ϲ��������������ϲ�����Ȼ���� 
int IsSListCross(PNode pHead1, PNode pHead2);
// �ж������������Ƿ��ཻ---�������� 
PNode GetCorssNode(PNode pHead1, PNode pHead2);
// �������������ཻ�Ľ���---�������� 


//������(��)
PNode IsListWithCircle(PNode pHead1);
// �ж������Ƿ����������������---ע���Ƶ���ʽ
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode);
// ��ȡ������ڵ�
int GetCircleLen(PNode pHead1, PNode pMeetNode);
// ��ȡ���ĳ���
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2);
// �ж����������Ƿ��ཻ��������ܴ���
PCSLNode BuyCSNewNode(DataType data);

PCSLNode CopyComplexList(PCSLNode pHead);
 //����������