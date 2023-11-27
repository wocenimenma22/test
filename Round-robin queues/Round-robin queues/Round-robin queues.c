#include"Round-robin queues.h"
void print(SqQueue* a)
{
	if (IsEmpty(a) == true)
	{
		printf("�����ѿգ��޷���ӡ\n");
		return;
	}
	int cur = a->front;
	int last = a->tail;
	while (cur != last)
	{
		printf("%d\n", a->data[cur]);
		cur = (cur + 1) % MAX;
	}
}
void InitQueue(SqQueue* a)
{
	a->data;
	a->front = a->tail = 0;
}
void QueuePush(SqQueue* a, queuedata x)
{
	if (IsFull(a) == true)
	{
		printf("�����Ѿ����ˣ��޷�����\n");
		return;
	}
	a->data[a->tail] = x;
	a->tail++;
}
void QueuePop(SqQueue* a)
{
	if (IsEmpty(a) == true)
	{
		printf("�����Ѿ����ˣ��޷�ɾ��\n");
		return;
	}
	a->front = (a->front + 1)%MAX;
}
bool IsFull(SqQueue* a)
{
	if (a->front == ((a->tail+1) % (MAX)))
	{
		return true;
	}
	return false;
}
bool IsEmpty(SqQueue* a)
{
	if (a->front == a->tail)
	{
		return true;
	}
	return false;
}
