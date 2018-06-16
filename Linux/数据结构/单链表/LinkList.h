#pragma once

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


typedef int DataType;

typedef struct LinkNode
{
    DataType data;
    struct LinkNode _pNext;
}Node, *PNode;



void LinkListInit(PNode* pHead);
void LinkLilstPushBack(PNode* pHead, DataType data);
