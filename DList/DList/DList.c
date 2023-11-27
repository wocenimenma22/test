#include "DList.h"
DLSnode* BeginThis()
{
	DLSnode* begin = (DLSnode*)malloc(sizeof(DLSnode));
	begin->next = begin;
	begin->prev = begin;
	return begin;
}

void DLSPrint(DLSnode* phead)//��ӡ����
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

void DLSPushFront(DLSnode* phead, SLDataType x)//ͷ�庯��
{
	DLSnode* newnode = BuyAMalloc(x);
	DLSnode* pheadNext = phead->next;
	phead->next = newnode;
	newnode->next = pheadNext;
	newnode->prev = phead;
	pheadNext->prev = newnode;
}

void DLSPushiBack(DLSnode* phead, SLDataType x)//β�庯��
{
	DLSnode* Tail = phead->prev;//tail��β������˼������ͨ���ڱ�λԪ�ص���ǰѰ��һλ
	//ֱ�Ӿ����ҵ�ĩβλ��Ԫ�أ�
	DLSnode* newnode = BuyAMalloc(x);
	Tail->next = newnode;
	newnode->prev = Tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void DLSPopFront(DLSnode* phead)//ͷɾ����
{
	assert(phead);//������Ϊ�յ�ʱ������˵����û�г�ʼ������Ϳ�ʼɾ�������
	assert(phead != phead->next);//����Ϊ�ղ���ɾ���ˡ�����Ŀ�˵���ǰ����ڱ�λһ��ɾ����
	DLSnode* pheadNext = phead->next;
	phead->next = pheadNext->next;
	pheadNext->next->prev = phead;
	free(pheadNext);
}

void DLSPopBack(DLSnode* phead)
{
	assert(phead);
	assert(phead != phead->next);//����Ϊ�ղ���ɾ���ˡ�����Ŀ�˵���ǰ����ڱ�λһ��ɾ����
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

void DLSInsert(DLSnode* pos, int x)//�����Ԫ�ص�ǰ���������
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
