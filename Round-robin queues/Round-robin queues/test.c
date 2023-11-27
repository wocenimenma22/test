#include"Round-robin queues.h"
//队列只能进行尾插和头删
int main()
{
	SqQueue a;
	InitQueue(&a);
	QueuePush(&a, 1);
	QueuePush(&a, 2);
	QueuePush(&a, 3);
	QueuePush(&a, 4);
	QueuePush(&a, 5);
	QueuePush(&a, 6);
	QueuePush(&a, 7);
	QueuePush(&a, 8);
	QueuePush(&a, 9);
	print(&a);
	QueuePop(&a);
	QueuePop(&a);
	QueuePop(&a);
	QueuePop(&a);
	QueuePop(&a);
	print(&a);
	return 0;
}