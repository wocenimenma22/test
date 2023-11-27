#include"hhh.h"
void Initializes(Stracts* pa)
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void StractPush(Stracts* pa, stractdata x)//ջֻ��β��βɾ
{
	assert(pa);
	if (IsFull(pa) == true)
	{
		printf("�޷�����\n");
		return;
	}
	Stract* newnode = (Stract*)malloc(sizeof(Stract));//����һ���µ��ڴ�ռ�Ϊ�µ�Ԫ��
	newnode->a = x;//��Ԫ�ش洢�����ݵ����ݵ���x
	newnode->next = NULL;//��Ԫ�ش洢����һ��Ԫ�صĵ�ַ����Ϊnull
	if (pa->head == NULL)//������ջΪ��
	{
		//printf("3");
		pa->head = pa->tail = newnode;//���ջ��ͷ��β����������������Ԫ��
		//pa->head->next = pa->tail;//��Ԫ�ص�ͷ����һ��Ԫ�ص������β���������޸ľͱ����ѭ������
		//pa->tail->prev = pa->head;//��Ԫ�ص�β����һ��Ԫ��Ϊ���ͷ���������޸ľͱ����ѭ������
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
		printf("ջ�ڿռ�Ϊ�����ڣ�����ɾ��");
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

bool IsFull(Stracts* pa)//�����ջһ�㲻Ϊ�հ��������������µ��ڴ�ռ�
//�����������������Ϳ��Բ���
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
			printf("ջ������");
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
		printf("Խ��");
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
