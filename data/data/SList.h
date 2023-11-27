#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<assert.h>
#include<stdbool.h>
typedef int SLDataType;

typedef struct SLNode
{
	SLDataType data;
	struct SLNode* next;
}SLNode;

void SLPrint(SLNode* phead);
void SLPushFront(SLNode** pphead, SLDataType x);
void SLPushiBack(SLNode** pphead, SLDataType x);
void SLPopFront(SLNode** pphead);
void SLPopBack(SLNode** pphead);
SLNode* SLFind(SLNode* phead,SLDataType a);//寻找函数，可以搭配着插入函数一起使用；
void SLPushintheFront(SLNode** pphead, SLNode* ThePos, SLDataType x);
void SLPushInTheBack(SLNode* pphead, SLNode* TheBack, SLDataType x);
void SLErase(SLNode** pphead, SLNode* Pos);
void SLEraseAfter(SLNode* Pos);
void SLDestory(SLNode* list);
SLNode* ChangeSL(SLNode* list);
SLNode* ChangeSL2(SLNode* list);
SLNode* MidSL(SLNode* list);
SLNode* LastKSL(SLNode* list, int k);
SLNode* MakeOne(SLNode* list1, SLNode* list2);
SLNode* SameForHalf(SLNode* list1, SLNode* list2);
SLNode* KickSL(SLNode* list, int x);