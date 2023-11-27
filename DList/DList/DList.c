#include "DList.h"
DLSnode* BeginThis()
{
	DLSnode* begin = (DLSnode*)malloc(sizeof(DLSnode));
	begin->next = begin;
	begin->prev = begin;
	return begin;
}

void DLSPrint(DLSnode* phead)//打印函数
{
	assert(phead);
	assert(phead != phead->next);
	DLSnode* next = phead->next;
	while (next != phead)
	{
		printf("%d ", next->data);
		next = next->next;
	}
	printf("\n");
}

DLSnode* BuyAMalloc(int x)
{
	DLSnode* newnode = (DLSnode*)malloc(sizeof(DLSnode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void DLSPushFront(DLSnode* phead, SLDataType x)//头插函数
{
	DLSnode* newnode = BuyAMalloc(x);
	DLSnode* pheadNext = phead->next;
	phead->next = newnode;
	newnode->next = pheadNext;
	newnode->prev = phead;
	pheadNext->prev = newnode;
}

void DLSPushiBack(DLSnode* phead, SLDataType x)//尾插函数
{
	DLSnode* Tail = phead->prev;//tail是尾部的意思，这里通过哨兵位元素的向前寻找一位
	//直接就能找到末尾位的元素；
	DLSnode* newnode = BuyAMalloc(x);
	Tail->next = newnode;
	newnode->prev = Tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void DLSPopFront(DLSnode* phead)//头删函数
{
	assert(phead);//链表本身为空的时候，这里说的是没有初始化链表就开始删除的情况
	assert(phead != phead->next);//链表为空不能删除了。这里的空说的是包括哨兵位一起删除了
	DLSnode* pheadNext = phead->next;
	phead->next = pheadNext->next;
	pheadNext->next->prev = phead;
	free(pheadNext);
}

void DLSPopBack(DLSnode* phead)
{
	assert(phead);
	assert(phead != phead->next);//链表为空不能删除了。这里的空说的是包括哨兵位一起删除了
	DLSnode* godie = phead->prev;
	DLSnode* thePrev = godie->prev;
	thePrev->next = phead;
	phead->prev = thePrev;
	free(godie);
}

DLSnode* FindDLS(DLSnode* phead, SLDataType x)
{
	assert(phead);
	assert(phead != phead->next);
	DLSnode* next = phead->next;
	while (next)
	{
		if (next->data == x)
		{
			return next;
		}
		next = next->next;
	}
	return NULL;
}

void DLSInsert(DLSnode* pos, int x)//在这个元素的前面插入数据
{
	DLSnode* newnode = BuyAMalloc(x);
	DLSnode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void DLSErase(DLSnode* pos)
{
	DLSnode* prev = pos->prev;
	DLSnode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
