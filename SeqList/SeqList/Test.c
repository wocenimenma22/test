#include "SeqList.h"

int main()
{
	SL ps;
	SeqListInit(&ps);
	SeqListexpand(&ps);
	SeqListPushBack(&ps, 10);
	SeqListPushBack(&ps, 30);
	SeqListPushBack(&ps, 40);
	SeqListPushFront(&ps, 20);
	SeqListPushFront(&ps, 210);
	SeqListPushFront(&ps, 110);
	SeqListPushFront(&ps, 10);
	SeqListInsert(&ps, 8, 2003);
	//printf("5");
	/*SeqListPopFront(&ps);
	SeqListPopBack(&ps);
	SeqListPopBack(&ps);
	SeqListPopFront(&ps);
	SeqListPopFront(&ps);*/

	SeqListPrint(&ps);
	//SeqListFind(&ps);
	//printf("%d", ps.size);
	SeqListDestory(&ps);
	return 0;
}