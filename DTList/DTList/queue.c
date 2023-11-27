#include"queue.h"
QueneNode* Buynode(QDataType x)
{
	QueneNode* newnode = (QueneNode*)malloc(sizeof(QueneNode));
	newnode->a = x;
	return newnode ;
}
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	QueneNode* cur = pq->head;
	while (cur)
	{
		QueneNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
void QueuePush(Queue* pq, QDataType x)//向链表插入数据
{
	assert(pq);
	QueneNode* newnode = Buynode(x);
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		(pq->tail)->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueneNode* head = pq->head;
	pq->head = head->next;
	free(head);
	
}
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return (pq->head)->a;
}
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return (pq->tail)->a;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int a = 0;
	QueneNode* cur = pq->head;
	while (cur)
	{
		a++;
		cur = cur->next;
	}
	return a;
}
bool QueueEmpty(Queue* pq)
{
	if(pq->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printttt(Queue* pq)
{
	QueneNode* cur = pq->head;
	while (cur)
	{
		printf("%d  ",cur->a);
		cur = cur->next;
	}
	printf("\n");
}
