#include"queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printttt(&q);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printttt(&q);
	printttt(&q);



	QDataType a = QueueFront(&q);
	QDataType b = QueueBack(&q);
	printf("%d", a);
	printf("%d", b);

	int c = QueueSize(&q);
	printf("%d", c);
	return 0;
}