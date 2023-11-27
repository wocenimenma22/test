#include"DList.h"
int main()
{
	DLSnode* dlist = BeginThis();
	/*DLSPushiBack(dlist, 2);
	DLSPushiBack(dlist, 3);
	DLSPushiBack(dlist, 5);
	DLSPushiBack(dlist, 7);
	DLSPushiBack(dlist, 4);
	DLSPushiBack(dlist, 7);
	DLSPushiBack(dlist, 7);*/
	DLSPushFront(dlist, 5);
	DLSPushFront(dlist, 4);
	DLSPushFront(dlist, 3);
	DLSPushFront(dlist, 2);
	DLSPushFront(dlist, 1);
	DLSPushFront(dlist, 0);
	/*DLSPopBack(dlist);
	DLSPopBack(dlist);
	DLSPopBack(dlist);*/
	DLSPrint(dlist);
	/*DLSnode* pos = FindDLS(dlist, 4);*/
	DLSnode* pos = FindDLS(dlist, 3);
	DLSInsert(pos, 3);
	DLSPrint(dlist);
	DLSPopFront(dlist);
	DLSPopFront(dlist);
	DLSPopFront(dlist);
	/*DLSErase(pos);*/
	DLSPrint(dlist);
	return 0;
}