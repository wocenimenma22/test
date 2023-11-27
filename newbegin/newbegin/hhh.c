#include"hhh.h"
void Initializes(Stracts* pa)
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void StractPush(Stracts* pa, stractdata x)//栈只能尾插尾删
{
	assert(pa);
	if (IsFull(pa) == true)
	{
		printf("无法插入\n");
		return;
	}
	Stract* newnode = (Stract*)malloc(sizeof(Stract));//申请一块新的内存空间为新的元素
	newnode->a = x;//新元素存储的数据的内容等于x
	newnode->next = NULL;//新元素存储的下一个元素的地址先置为null
	if (pa->head == NULL)//如果这个栈为空
	{
		//printf("3");
		pa->head = pa->tail = newnode;//这个栈的头和尾都等于申请的这个新元素
		//pa->head->next = pa->tail;//新元素的头的下一个元素等于这个尾，后面再修改就变成了循环链表
		//pa->tail->prev = pa->head;//新元素的尾的下一个元素为这个头，后面再修改就变成了循环链表
	}
	else
	{
		newnode->prev = pa->tail;
		pa->tail->next = newnode;
		pa->tail = newnode;
	}
}

void StractPop(Stracts* pa)
{
	if (IsEmpty(pa) == 1)
	{
		printf("栈内空间为空现在，不能删除");
		return;
	}
	if(pa->head!=pa->tail)
	{
		Stract* pop = pa->tail;
		Stract* prev = pa->tail->prev;
		prev->next = NULL;
		pa->tail = prev;
		free(pop);
	}
	else
	{
		Stract* pop = pa->tail;
		free(pop);
		pa->head = pa->tail = NULL;
	}

}

bool IsEmpty(Stracts* pa)
{
	assert(pa);
	if (!pa->head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsFull(Stracts* pa)//链表的栈一般不为空啊，总是能增加新的内存空间
//如果设置最大容量，就可以查满
{
	int i = 1;
	int max = MAX;
	Stract* now = pa->head;
	while (now != (pa->tail))
	{
		now = now->next;
		i++;
		if (i == max)
		{
			printf("栈是满的");
			return true;
		}
	}
	return false;
}

stractdata StractFind(Stracts* pa, int x)
{
	int max = MAX;
	if (x > max)
	{
		printf("越界");
	}
	int i = 1;
	Stract* now = pa->head;
	while (i != x)
	{
		now = now->next;
		i++;
	}
	return now->a;
}

void print(Stracts* pa)
{
	Stract* now = pa->head;
	while (now)
	{
		printf("%d  ", now->a);
		now = now->next;
	}
	printf("\n");
}
