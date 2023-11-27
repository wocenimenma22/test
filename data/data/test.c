#include"SList.h"
//int removeDup(int *a,int *size)
//{
//	if (a == NULL)
//	{
//		exit(-1);
//	}
//	int str = 0;
//	int i = 0, j = 0;
//	while (j < size)
//	{
//		if (a[i] == a[j])
//		{
//			j++;
//		}
//		else
//		{
//			a[str] = a[i];
//			i = j;
//			str++;
//		}
//		
//	}
//	a[str] = a[i];
//	++str;
//	return str;
//
//}
//
//int main()
//{
//	int a[10] = {1,1,2,2,3,3,4,4,5,5};
//	int size = sizeof(a) / sizeof(a[0]);
//	int size2=removeDup(a, size);
//	printf("%d", size2);
//	return 0;
//}

//void megre(int* arr, int size, int* arr2, int size2)
//{
//	int end = size + size2;
//	while (size >= 0 && size2 >= 0)
//	{
//		if (arr[size-1] > arr2[size2 - 1])
//		{
//			arr[end-1] = arr[size-1];
//			end--;
//			size--;
//		}
//		else
//		{
//			arr[end - 1] = arr2[size2 - 1];
//			end--;
//			size2--;
//		}
//	}
//	while (size2>=0)
//	{
//		arr[end - 1]; arr2[size2 - 1];
//		end--, size2--;
//	}
//}
//
//
//int main()
//{
//	int arr1[6] = { 1,2,6,0,0,0 };
//	int arr2[3] = { 3,4,5 };
//	int size = sizeof(arr1) / sizeof(arr1[0])- sizeof(arr2) / sizeof(arr2[0]);
//	int size2 = sizeof(arr2) / sizeof(arr2[0]);
//	megre(arr1, size, arr2, size2);
//	int i = 0;
//	for(i=0;i<size+size2;i++)
//	{
//		printf("%d", arr1[i]);
//	}
//	return 0;
//}

 bool BackAndFirst(SLNode* list)
{
	 SLNode*mid=MidSL(list);
	 mid = ChangeSL(mid);
	 //printf("反转后的");
	 //SLPrint(mid);
	 //printf("反转前的");
	 //SLPrint(list);
	 while (mid)
	 {
		 if (mid->data != list->data)
		 {
			 return false;
		 }
		 else
		 {
			 mid = mid->next;
			 list = list->next;
		 }
	 }
	 return true;
 }


int main()
{
	SLNode *list=NULL;
	//SLPushFront(&list, 2);
	//SLPushFront(&list, 3);
	//SLPushFront(&list, 4);
	//SLPushFront(&list, 5);
	//SLNode* list2 = NULL;

	SLPushiBack(&list, 1);
	SLPushiBack(&list, 2);
	SLPushiBack(&list, 3);
	SLPushiBack(&list, 4);
	SLPushiBack(&list, 5);
	SLPushiBack(&list, 4);
	SLPushiBack(&list, 3);
	SLPushiBack(&list, 2);
	SLPushiBack(&list, 1);

	bool a = BackAndFirst(list);
	//SLNode* new = ChangeSL2(list);
	/*SLPushiBack(&list2, 1);
	SLPushiBack(&list2, 4);
	SLPushiBack(&list2, 5);
	SLPushiBack(&list2, 7);
	SLPushiBack(&list2, 9);
	SLPushiBack(&list2, 10);*/
	/*SLNode* pos ;
	int i = 1;
	while (pos != NULL)
	{
		pos=SLFind(pos,9)
		;
	}
	SLErase(&list, pos);*/
	//SLNode* pos = SLFind(list, 2);
	//SLEraseAfter(pos);
	/*printf("%p->%d\n", pos, pos->data);
	SLPushInTheBack(list, pos, 3);*/
	//SLPopBack(&list);
	//SLPopBack(&list);
	//SLPopBack(&list);
	//SLPopBack(&list);
	/*SLPopFront(&list);
	SLPopFront(&list);
	SLPopFront(&list);
	SLPopFront(&list);*/
	/*SLNode*pos= SLFind(list, 4);
	printf("%p->%d\n", pos, pos->data);
	SLNode* pos2 = SLFind(list, 3);
	printf("%p->%d\n", pos2, pos2->data);
	SLNode* pos5 = SLFind(list, 31);*/
	//这里的list是结构体的一个指针，再取一次地址，所以传递的是地址的地址
	//这里打印，因为定义的时候list就是一个地址，只要把这个地址传入进去，就能直到下一个元素的地址
	//然后就能遍历整个数组
	//list = ChangeSL2(list);
	
	//SLPrint(list);

	//list = MidSL(list);

	//SLNode* new = MakeOne(list, list2);
	//SLPrint(list);
	//SLPrint(list2);
	printf("%d",a);
	//SLPrint(new);
	SLDestory(list);
	//SLDestory(list2);

	//SLDestory(new);
	return 0;
}

