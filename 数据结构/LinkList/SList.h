#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int DataType;

typedef struct SNode
{
	DataType data;
	struct SNode *_pNext;//保存下个节点的地址

}SNode, *PNode;


typedef struct CSListNode
{
	DataType data;
	struct CSListNode *_pNext;
	struct CSListNode *_pRandom;

}CSListNode, *PCSLNode;

void SListInit(PNode* pHead);
// 链表的初始化 
void SListPushBack(PNode* pHead, DataType data);// 尾插 
void SListPopBack(PNode* pHead);// 尾删 
void SListPushFront(PNode* pHead, DataType data);// 头插 
void SListPopFront(PNode* pHead);// 头删 
PNode SListFind(PNode pHead, DataType data);
// 在链表中查找值为data的元素，找到后返回值为data的结点
void SListInsert(PNode* pHead, PNode pos, DataType data);
// 在pos位置插入值为data的结点 
void SListErase(PNode* pHead, PNode pos);
// 删除pos位置的结点 
int SListSize(PNode pHead);
// 获取链表中节点总数
int SListEmpty(PNode pHead);
// 判断链表是否为空 
void SListDestroy(PNode* pHead);// 销毁链表
void PrintfList(PNode pHead);//打印链表




//面试题
void PrintSListFromTail2Head(PNode pHead);
// 逆序打印单链表 
void DeleteListNotTailNode(PNode pos);
// 删除链表的非尾结点，要求：不能遍历链表 
void InesrtPosFront(PNode pos, DataType data);
// 在链表pos位置前插入值到data的结点 
PNode FindMiddleNode(PNode pHead);
// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindLastKNode(PNode pHead, int K);
// 查找链表的倒数第K个结点，要求只能遍历一次链表 
void DeleteLastKNode(PNode *pHead, int K);
// 删除链表的倒数第K个结点，要求只能遍历一次链表 
void JosephCircle(PNode* pHead, const int M);
// 用单链表实现约瑟夫环 
void ReverseSList(PNode* pHead);
// 链表的逆置--三个指针 
PNode ReverseSListOP(PNode pHead);
// 链表的逆置--头插法 
void BubbleSort(PNode pHead);
// 用冒泡排序思想对单链表进行排序 
PNode MergeSList(PNode pHead1, PNode pHead2);
// 合并两个有序单链表，合并后依然有序 
int IsSListCross(PNode pHead1, PNode pHead2);
// 判断两个单链表是否相交---链表不带环 
PNode GetCorssNode(PNode pHead1, PNode pHead2);
// 求两个单链表相交的交点---链表不带环 


//面试题(二)
PNode IsListWithCircle(PNode pHead1);
// 判断链表是否带环，返回相遇点---注意推导公式
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode);
// 获取环的入口点
int GetCircleLen(PNode pHead1, PNode pMeetNode);
// 获取环的长度
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2);
// 判断两个链表是否相交，链表可能带环
PCSLNode BuyCSNewNode(DataType data);

PCSLNode CopyComplexList(PCSLNode pHead);
 //复杂链表复制