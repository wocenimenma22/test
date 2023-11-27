#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<assert.h>
#include<stdbool.h>
typedef int SLDataType;
//双向链表，不带头尾节点的
typedef struct DLSnode
{
	SLDataType data;
	struct DLSnode* next;
	struct DLSnode* prev;
}DLSnode;

DLSnode* BeginThis();
void DLSPrint(DLSnode* phead);
DLSnode* BuyAMalloc(int x);
void DLSPushFront(DLSnode*phead, SLDataType x);
void DLSPushiBack(DLSnode* phead, SLDataType x);
void DLSPopFront(DLSnode* phead);
void DLSPopBack(DLSnode* phead);
DLSnode* FindDLS(DLSnode* phead, SLDataType x);
void DLSInsert(DLSnode* pos, int x);
void DLSErase(DLSnode* pos);