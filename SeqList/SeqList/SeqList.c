#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListexpand(SL* ps)//��չ˳���Ĵ洢�ռ��С
{
	if (ps->capacity == 0)
	{
		//�ʼ������洢�ռ�Ϊ�գ���ô����ֱ�Ӹ��ĸ�
		ps->capacity = 4;
		SLDataType* ptr = (SLDataType*)malloc(sizeof(SLDataType) * ps->capacity);
		//�����Ȱ��Ǹ�capacity��Ϊʵ��Ҫ�ĵĴ�С��
		//Ȼ�����ڴ�ռ�����ʵ�ʴ�С���ڴ�
		if (ptr != NULL)
		{
			ps->a = ptr;
			printf("���ݳɹ�\n");
			//��һ��ֻ����֤�����ڴ�ָ���Ƿ�ɹ���һ������²���ʧ��
		}
		//���￪�ٵĶ�̬�ڴ�ֻ��aռ�õ�
		//size��capacity�洢�������ĵط�
		//Ҳ����ʵ�ʵ����ݴ洢��һ�����飬��������ھ�̬�ڴ�������ڣ�Ҫ��malloc������ܵõ�������һ��ռ�
		//��size ��capacity�Ǵ洢�ڶ�̬�ڴ��е�
		else if (ptr == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
			//ͬ��if
		}
	}
	
	else if (ps->capacity == ps->size && ps->capacity > 0)
	{
		//�����ʱ�����size��capacity����ˣ���ô��ʱ��˵��������Ŀռ�������
		ps->capacity *= 2;
		//������Ȼ���������
		SLDataType* ptr = (SLDataType*)realloc(ps->a, sizeof(SL) * ps->capacity);
		//����ʹ��realloc��realloc����ԭ���ڴ�ռ�Ļ���������һ���ַ�����������չ
		if (ptr != NULL)
		{
			ps->a = ptr;
			printf("���ݳɹ�\n");
		}
		//����Ƿ����ݳɹ�
	}
}
void SeqListPushBack(SL* ps, SLDataType x)//β�庯��
{
	SeqListexpand(ps);
 	ps->a[ps->size]=x;
	ps->size++;
	printf("β��ɹ�\n");
	//ֱ����a����ĵ�size��Ԫ�ص���x
}

void SeqListPopBack(SL* ps)//β��ɾ������
{
	printf("ɾ���ɹ�\n");
	ps->size--;
	//���ﲻ�����ɾ�����Ԫ�أ�ֱ��size--������������
}

void SeqListFind(SL* ps)//�ҵ�һ��Ԫ��
{
	SLDataType x = 0;
	printf("����������Ҫ�ҵ�����:");
	scanf("%lf", &x);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			//������������Ѱ�����Ԫ��
			printf("�ҵ��ˣ��������Ϊa[%d]",i);
			break;	
		}
	}

}

void SeqListPushFront(SL* ps, SLDataType x)//ͷ�庯��
{
	SeqListexpand(ps);
	int end = ps->size-1;
	while (end >= 0)
	{

		ps->a[end+1] = ps->a[end];
		end--;
	}
	//�Ȱ����������Ԫ�������һλ�������ú�һ������ǰһ��
	//��Ȼ�ᷢ�����ݵĶ�ʧ
	printf("ͷ��ɹ�\n");
	ps->a[0] = x;
	//����õ�һ��Ԫ�ص���x
	ps->size++;
}
//Ϊ�˱�֤����ǰ�������ֵ�������ʱ������ȷ��ֵ������Ҫ�Ӻ�����ǰ�渳ֵ

void SeqListPopFront(SL* ps)//ͷɾ����
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	//����������ǰһλ��size--���һλ���ù�
	//�����ʱ��Ҫ����Ļ������Զ�����һλ���ǡ�
	ps->size--;
	printf("ɾ���ɹ�\n");
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%lf\n", ps->a[i]);
	}
	//������ӡ
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
	printf("����������Ҫ���ĵ�����:");
	scanf("%lf", &x);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			//�������飬�ҵ����Ԫ�أ�Ȼ����иı�
			printf("�ҵ��ˣ��������Ϊa[%d]", i);
			SLDataType Change = 0;
			printf("����������Ҫ��������ĳ�ʲô:");
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
		printf("��������ķ�Χ���޷�����\n");
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
		printf("����ɹ�");
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