#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListexpand(SL* ps)//拓展顺序表的存储空间大小
{
	if (ps->capacity == 0)
	{
		//最开始，如果存储空间为空，那么就线直接给四个
		ps->capacity = 4;
		SLDataType* ptr = (SLDataType*)malloc(sizeof(SLDataType) * ps->capacity);
		//这里先把那个capacity改为实际要改的大小，
		//然后向内存空间申请实际大小的内存
		if (ptr != NULL)
		{
			ps->a = ptr;
			printf("增容成功\n");
			//这一步只是验证申请内存指令是否成功，一般情况下不会失败
		}
		//这里开辟的动态内存只是a占用的
		//size和capacity存储在其他的地方
		//也就是实际的数据存储是一个数组，这个数组在静态内存上面存在，要用malloc申请才能得到这样的一块空间
		//而size 和capacity是存储在动态内存中的
		else if (ptr == NULL)
		{
			printf("增容失败\n");
			exit(-1);
			//同上if
		}
	}
	
	else if (ps->capacity == ps->size && ps->capacity > 0)
	{
		//后面的时候，如果size和capacity相等了，那么这时候说明，申请的空间用完了
		ps->capacity *= 2;
		//翻倍，然后继续操作
		SLDataType* ptr = (SLDataType*)realloc(ps->a, sizeof(SL) * ps->capacity);
		//这里使用realloc，realloc会在原来内存空间的基础上申请一块地址，或者向后拓展
		if (ptr != NULL)
		{
			ps->a = ptr;
			printf("增容成功\n");
		}
		//检测是否增容成功
	}
}
void SeqListPushBack(SL* ps, SLDataType x)//尾插函数
{
	SeqListexpand(ps);
 	ps->a[ps->size]=x;
	ps->size++;
	printf("尾插成功\n");
	//直接零a数组的第size个元素等于x
}

void SeqListPopBack(SL* ps)//尾部删除函数
{
	printf("删除成功\n");
	ps->size--;
	//这里不用真的删除这个元素，直接size--，就舍弃掉了
}

void SeqListFind(SL* ps)//找到一个元素
{
	SLDataType x = 0;
	printf("请输入你想要找的数字:");
	scanf("%lf", &x);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			//遍历整个数组寻找这个元素
			printf("找到了，这个数的为a[%d]",i);
			break;	
		}
	}

}

void SeqListPushFront(SL* ps, SLDataType x)//头插函数
{
	SeqListexpand(ps);
	int end = ps->size-1;
	while (end >= 0)
	{

		ps->a[end+1] = ps->a[end];
		end--;
	}
	//先把整个数组的元素向后走一位，是先让后一个等于前一个
	//不然会发生数据的丢失
	printf("头插成功\n");
	ps->a[0] = x;
	//最后，让第一个元素等于x
	ps->size++;
}
//为了保证数组前面的数赋值给后面的时候是正确的值，函数要从后面往前面赋值

void SeqListPopFront(SL* ps)//头删函数
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	//整个数组向前一位；size--最后一位不用管
	//如果到时候还要插入的话，会自动把这一位覆盖。
	ps->size--;
	printf("删除成功\n");
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%lf\n", ps->a[i]);
	}
	//遍历打印
}



void SeqListDestory(SL* ps)
{
		free(ps->a);
		ps->a = NULL;
		ps->capacity = ps->size = 0;
}

void SeqListChange(SL* ps)
{
	SLDataType x = 0;
	printf("请输入你想要更改的数字:");
	scanf("%lf", &x);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			//遍历数组，找到这个元素，然后进行改变
			printf("找到了，这个数的为a[%d]", i);
			SLDataType Change = 0;
			printf("请输入你想要把这个数改成什么:");
			scanf("%lf", &Change);
			ps->a[i] = Change;
			break;
		}
	}
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListexpand(ps);
	if (pos > ps->size+1||pos<0)
	{
		printf("超出插入的范围，无法插入\n");
		return;
	}
	else 
	{
		int i = ps->size;
		while (i > pos - 1)
		{
			ps->a[i] = ps->a[i - 1];
			i--;
		}
		ps->a[pos - 1] = x;
		ps->size++;
		printf("插入成功");
	}
}

void SeqListErase(SL* ps, int pos, SLDataType x)
{
	int i = 0;
	for (i = pos-1; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}