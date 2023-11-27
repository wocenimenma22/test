#include "SList.h"

void SLPrint(SLNode* phead)//��ӡ����
{
	if (phead == NULL)
	{
		printf("�ýṹ�廹û�в���Ԫ�أ�����²���");
		exit(-1);
	}
	SLNode* cur = phead;
	//���ԣ���Ϊphead��һ��ָ�룬Ҫ��һ��curָ��ȥ���գ���Ϊ���ܶԽ��յĽṹ���ָ�����ֱ�Ӳ���
	while (cur != NULL)
	{
		if(cur->next!=NULL)
		{
			printf("%d   ", cur->data);
			cur = cur->next;
		}
		else
		{
			printf("%d\n", cur->data);
			cur = cur->next;

		}
	}
}

void SLPushiBack(SLNode** pphead,SLDataType x)//β�����뺯��
{
	//�����pphead��������Ԫ�صĵ�ַ�ĵ�ַ
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));//�ȶ���һ��newnode�����洢����µ�Ԫ��
	//�����newnode��һ��ָ�룬���ң�ע���Ƕ��ң�����ǰ��˵��ͬ����Ҫ���ⲻ��һ��������ӣ�
	//newnode��һ��ָ�룬���治��ʹ��.�������ṹ�������Ԫ�أ�Ҫʹ��->
	newnode->data = x;//��¼
	newnode->next = NULL;//������β�壬����nextҪ����ΪNULL
	if (*pphead == NULL)
	{
		//�����*ppheadֻ��������һ�Σ����Ա�ʾ����������Ԫ�صĵ�ַ
		*pphead = newnode;
		//����������Ԫ�صĵ�ַΪ�վͱ�ʾ�������Ļ�δ���壬ֱ�Ӱ�����������Ԫ�صĵ�ַ��Ϊnewnode�Ϳ���
	}
	else
	{	
		SLNode* tail = *pphead;
		while (tail->next!=NULL)
		{
			//�����ȸ�һ���ṹ���ָ�룬��������*pphead
			//Ȼ������tail���в�����һֱ�ȵ�tail����ṹ������һ��Ԫ��
			tail = tail->next;
		}
		//�ҵ�����ṹ������һ��Ԫ��֮�����Ԫ�ص���Я�����Ǹ�ָ���ó�newnode����Ϊnewnode�������һ���ṹ���ָ��
		//��Ϊtail��һ��ָ�룬���Զ�tail���еĲ���Ҳ��Ӱ��**pphead���Ǹ��ṹ��
		tail->next=newnode;
		//�������ͨ��tailָ�������ṹ���nextָ����newnode�ģ���Ӱ�쵽�ʼ�����ָ�롣
	}
}

void SLPopFront(SLNode** pphead)//ͷ��ɾ������
{
	if (*pphead == NULL)
	{
		printf("�ýṹ�廹û�в���Ԫ�أ�����²���");
		exit(-1);
	}
	//assert(*pphead != NULL);
	//ɾ�������������ǰ�������
	SLNode* cur = *pphead;
	//�������ֵ������һ��
	//ǰ���*����˵������һ��һ��ָ������ݣ���������*������������pphead�ģ���Ϊpphead��һ������ָ�룬Ҫ������һ�βű��һ��ָ��
	*pphead = cur->next;
	//��Ϊ��ͷɾ����������ѵڶ���Ԫ�صĵ�ַ��ֵ����һ��Ԫ�صĵ�ַ
	free(cur);
	//Ȼ���ͷ������һ��Ԫ�صĵ�ַ����Ϊ����cur��һ����ַ������ɾ���ľ�����������ϵ�����Ԫ��
	cur->next = NULL;
	cur = NULL;
}

void SLPopBack(SLNode** pphead)//β��ɾ������
{
	if (*pphead == NULL)
	{
		printf("�ýṹ�廹û�в���Ԫ�أ�����²���");
		exit(-1);
	}
	else if ((*pphead)->next == NULL)//ע���������һ�����ž�������ʹ����
	{
		free(*pphead);
		*pphead = NULL;
		//��ֻ��һ��Ԫ�ص�ʱ��ֱ��������ٽ�����һ��������ᱨ��
	}
	else
	{
		SLNode* cur = NULL;
		SLNode* tail = *pphead;
		//�����������ָ�룬һ��ָ�����һ����һ��ָ�����ڶ������ڱ����Ĺ����֣�����һ����Զ�������һ��Ԫ��һ����ַ
		//��������������ܵõ����Ԫ�ص�ǰһλ�ĵ�ַ������������next��Ϊ��
		while (tail->next != NULL)
		{
			//�����ȸ�һ���ṹ���ָ�룬��������*pphead
			//Ȼ������tail���в�����һֱ�ȵ�tail����ṹ������һ��Ԫ��
			cur = tail;
			tail = tail->next;
		}
		//����һ�����ʼ��ʱ���ٶ���һ��ָ�룬ÿ�����һ��
		cur->next = NULL;
		//��������ֱ��next��next
		//tail->neat->next
	}
}

SLNode* SLFind(SLNode* phead, SLDataType a)//Ѱ��һ��������
{
	if (phead == NULL)
	{
		printf("�ýṹ�廹û�в���Ԫ�أ�����²���");
		exit(-1);
	}
	SLNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == a)
		{
			return cur;
		}
		//��Ϊ����������������ͷ�ĵ�ַ���и��ģ�����������ݵ��ǵ���Ԫ��
		else
		{
			cur = cur->next;
		}
	}
	/*if (cur->data == a)
	{
		printf("%d",cur->data);
		return cur;
	}*/
	printf("û�����Ԫ��\n");
	return NULL;
}

void SLPushintheFront(SLNode** pphead, SLNode* ThePos, SLDataType x)//��һ������ǰ����뺯��
{
	if (*pphead == ThePos)
	{
		SLPushFront(pphead,x);
	}
	//����ǵ�һ��Ԫ�غ�Ҫ����ǰ��Ԫ����ͬ�Ļ�����ͷ�壬ֱ�ӵ���ͷ�庯����
	//��Ϊpphead�������SLNode**���������ﲻ��Ҫ�����������ͣ�x�����������������������Ϊͬ��
	else
	{
		SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
		newnode->data = x;
		newnode->next = NULL;
		SLNode* cur = *pphead;
		while (cur->next != ThePos)
		{
			cur = cur->next;
			//cur������һ����ַ��ͬʱcur->nextҲ��һ����ַ�����Կ�������ʹ�ã�
			// ��Ϊcur��һ����ַ��������Ҫ��->������.
		}
		cur->next = newnode;
		//ֱ�Ӹ����У����ù��Ⱥ�˳����Ϊ֪��������Ǹ��ĵ�ַ
		//Ҳ����ThePos
		newnode->next = ThePos;
	}
}

void SLPushInTheBack(SLNode* pphead, SLNode* TheBack, SLDataType x)//��һ������β�����뺯��
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;
	//������һ���ַ
	SLNode* cur = pphead;
	while (cur!= TheBack)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
}

void SLErase(SLNode** pphead, SLNode* Pos)//ɾ���������Ԫ�صĺ���
{
	if (*pphead == Pos)
	{
		SLPopFront(pphead);
		return;
		//�����һ��Ԫ�صĵ�ַ������Ҫɾ����Ԫ�صĵ�ַ���ʹ�������һ��ͷɾ��
		// ��ֱ�ӵ���ͷɾ����������Ϊ���Ҫ����ͷ
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur->next != Pos)
		{
			cur = cur->next;
		}
		cur->next = Pos->next;
		free(Pos);
	}
}

void SLEraseAfter(SLNode* Pos)//ɾ���������Ԫ�غ����Ԫ�صĺ��������������Բ�����ɾ����һ��Ԫ�أ����Ժ�������Ԫ�صĵ�ַ����ı�
{
	SLNode* tmp = Pos->next;
	Pos->next = tmp->next;
	//��ֱ�Ӱ�pos��Ӧ����һλ�ĵ�ַ��ת��Ϊ����һλ��
	free(tmp);
	//ʱ�临�Ӷ�Ϊo��1�������ǱȽϺõ�
}

void SLDestory(SLNode* list)
{
	assert(list);
	while (list->next != NULL)
	{
		SLNode* tmp = list->next;
		//������һ��tmpָ��list����һ��Ԫ�صĵ�ַ
		list->next = tmp->next;
		//Ȼ����list���������Ǹ���ַ�ĳ�list����ĵڶ���Ԫ�صĵ�ַ
		free(tmp);
		//tmp�Ǹ���ַ���ͷŵ���tmp�����ַ
		//tmp��list�ʼ�ĺ�����ŵĵ�һ��Ԫ�صĵ�ַ�����������ͷ����Ԫ�صĵ�ַ
	}
	free(list);
	//ֱ��list����ĵ�ַԪ��Ϊ�գ�����ѭ�����ͷ�list����list�Ǹ���ַ������Ԫ�صĵ�ַ
	printf("\n���ٳɹ�");
}

SLNode* ChangeSL(SLNode* list)//�������˳��ת��
{
	//���������ú�����ԭ���������ƻ��ˡ���ʱ��дһ��ChangeSL3�ڲ�����ԭ���������£��õ��µ�����
	//�����ͷ��ڴ��ʱ��ֻҪ�ͷűȽϳ��ĸ��Ǹ����С���Ϊ�����Ǹ������̵ġ�
	SLNode* prev = NULL;//���ڲ�����Ԫ�ص�ǰһλ��Ԫ�أ���nowΪ��Ԫ�ص���ʱ�����Ϊ��
	SLNode* now = list;//���ڲ�����Ԫ�أ�
	SLNode* next = list->next;//���ڲ�����Ԫ�ص���һλԪ�ء�
	while (now)
	{
		//��now��Ϊ�յ�ʱ�򣬲��ϵ�ѭ�������޸�·��
		if(next!=NULL)
		{
			//��next�����ڿյ�ʱ��ִ���������Ϊnext = next->next;Ҫ��next��Ϊ��
			now->next = prev;
			//���������ڲ�����Ԫ��now��next���������ĵ�ַָ������ǰһλ��ͬʱ����next�ﱾ���洢��
			//��һλԪ�صĵ�ַ������next������˵��nextָ����Ԫ��next������
			prev = now;
			//��prew����������ڲ�����Ԫ�أ�����Ϊprev�Ǹ���ַ���������ַ��ֵ
			// ������xx010203103ʲô�ģ��Ѿ������뵽now->next����ȥ�ˣ������������ֱ��������Ϊnow�ĵ�ַ
			//Ҳ������Ϊprev��now����ͬ����������ֻ�ǵ�ַ������prev��now�������ֶ���ȫһ����
			//���ڵ�prev->next�͵���prev
			now = next;
			//�������ڲ�����Ԫ�ص���һλԪ�س�ΪҪ���ڲ�����Ԫ�ء�
			next = next->next;
			//����Ҫ������Ԫ�������չ�����һ�Σ�next����ĵ�ַΪ�ա�
		}
		else
		{
			//��next����NULL��ʱ������������Ͳ���ִ��next = next->next;��һ��������
			now->next = prev;
			//���������ڲ�����Ԫ��now��next���������ĵ�ַָ������ǰһλ��
			prev = now;
			//��prev��Ϊ���ڲ�����Ԫ�ء�
			now = next;
			//��Ϊ���ʱ��nextΪ�գ���now��Ϊ�գ��˳�ѭ��
		}
	}
	//ѭ������������prev������Ԫ�صĵ�ַ
	return prev;
}

SLNode* ChangeSL2(SLNode* list)//�������˳��ת
{
	SLNode* new=NULL ;
	SLNode* phead = list;
	while (phead)
	{
		SLNode* tmp = new;
		//��new�ȴ洢һ�£���new������������޸ģ����������ڴ��ַ�����޸�
		new = phead;
		//��new��ֵΪphead�ĵ�ַ����������data�͵���phead��data��ͬʱ���ĵ�ַҲ����phead
		//���ǣ�ͬʱ��Ϊphead��ֵ����ֵ��new���������������ǵ�ַ�����ԣ���new���еĲ�����ı�phead��Ҳ����new��next����
		//phead��next
		SLNode* tmp2 = phead->next;
		//����Ҫ�ȴ洢һ�£�phead->next����Ȼ��phead��ֵ��new֮��
		// ��new->next���в�����ʹphead������Ҳ�ı�
		//Ȼ��ᷢ����ʧ
		new->next = tmp;
		//��new��>next�����ݸ�Ϊtmp��Ҳ������һ��new����ַ��
		phead = tmp2;
		//phead=tmp2�������tmp2���������phead->next��
	}
	return new;
}

SLNode* MidSL(SLNode* list)//���м����
{
	/*int i = 0;
	SLNode* temp = list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	i = (i + 1) / 2;
	for (i; i > 1; i--)
	{
		list = list->next;
	}
	return list;*/

	//����ָ�룬���ÿ�ν�����������ÿ�ν�һ��������������ʱ�����ĸպ���һ��
	SLNode* slow = list;
	SLNode* fast = list;
	while (fast != NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//�����ͷŵ�ַ����Ϊ����ĵ�ַ����list����ĵ�ַ
	return slow;
}

SLNode* LastKSL(SLNode* list, int k)//������k������ʼ������
{
	if (k <= 0)
	{
		printf("k�����Ǹ���");
		return list;
	}
	SLNode* slow = list;
	SLNode* fast = list;
	//���ƿ���ָ��
	//���ÿ��ָ����ǰ��k����Ȼ������ָ��ͬʱ��ǰ��
	//����ָ�붼��ÿ��ֻ��һ���������ܹ�����n-k��������ָ��͵��˵�����k��
	//�����Ӧ����while��һ��
	while (k --)
	{
		fast = fast->next;
		/*if (fast == NULL)
		{
			return NULL;
		}*/
		if (fast == NULL && k > 0)
		{
			printf("Խ����,���β�����Ч\n");
			return list;
		}
	}
	while(fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

SLNode* MakeOne(SLNode* list1, SLNode* list2)
{
	//���������б�ϳ�Ϊһ���б�
	

	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	//�����һ������Ϊ�գ�ֱ�ӷ�������һ�������õ���������Ϊ�յ����
	//�����һ��ҲΪ�գ����ص�ҲΪ��
	SLNode* phead = (SLNode*)malloc(sizeof(SLNode));
	//����һ���ַ��Ϊͷ
	SLNode* tmp = phead;
	//�������ͷ��λ�ã�������������в���
	SLNode* tmp2 = phead;
	//�������ͷ��λ�ã������ͷ������
	while (list1 && list2)
	{
		SLNode* dataput = (SLNode*)malloc(sizeof(SLNode));
		//����һ����ַ���洢����
		if (list1->data > list2->data)
		{
			dataput->data = list2->data;
			//data��ֵ��data
			tmp->next = dataput;
			tmp = tmp->next;
			list2 = list2->next;
			//��ֵ����tmp��Я����ָ��ָ�����data���ٰ����tmp
			//����
			//�����ṩֵ��ָ���
		}
		else
		{
			dataput->data = list1->data;
			tmp->next = dataput;
			tmp = tmp->next;
			list1 = list1->next;
			//ͬ��
		}
	}
	if (list1)
	{
		while (list1)
		{
			SLNode* dataput = (SLNode*)malloc(sizeof(SLNode));
			dataput->data = list1->data;
			tmp->next = dataput;
			tmp = tmp->next;
			list1 = list1->next;
			//ִ�е������ʱ������һ������Ϊ�գ�����ÿ������һ����ַ
			//�洢
		}
	}
	if (list2)
	{
		while (list2)
		{
			SLNode* dataput = (SLNode*)malloc(sizeof(SLNode));
			dataput->data = list2->data;
			tmp->next = dataput;
			tmp = tmp->next;
			list2 = list2->next;
		}
	}
	tmp->next = NULL;
	//��������������β��λ��ָ��
	phead = phead->next;
	free(tmp2);
	return phead;
}

SLNode* SameForHalf(SLNode* list1, SLNode* list2)
{
	//������������Ƿ��н����
	//��������ﲻ����
	int lenlist1 = 1;
	while (list1)
	{
		lenlist1++;
		list1 = list1->next;
	}
	int lenlist2 = 1;
	while (list2)
	{
		lenlist2++;
		list2 = list2->next;
	}
	int len = abs(lenlist1 - lenlist2);
	SLNode* fast = list1;
	SLNode* slow = list2;
	if (lenlist1 > lenlist2)
	{
		fast = list2;
		slow = list1;
	}
	while (len)
	{
		fast = fast->next;
		len--;
	}
	while (fast)
	{
		if (fast == slow)
		{
			return fast;
		}
		else
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	return NULL;
}

SLNode* KickSL(SLNode* list, int x)//�������ΪС��x�ģ��ʹ���x�ġ�Ȼ��ϲ���һ������
{
	SLNode* pheadlitter = (SLNode*)malloc(sizeof(SLNode));
	SLNode* pheadbigger = (SLNode*)malloc(sizeof(SLNode));
	SLNode* curbig = pheadbigger;
	SLNode* curbig2 = pheadbigger;
	SLNode* curlitter = pheadlitter;
	SLNode* curlitter2 = pheadlitter;
	while (list)
	{
		if (list->data > x)
		{
			SLNode* tmpbig = (SLNode*)malloc(sizeof(SLNode));
			tmpbig->data = list->data;
			curbig->next = tmpbig;
			curbig = tmpbig;
			list = list->next;
		}
		else
		{
			SLNode* tmplitter = (SLNode*)malloc(sizeof(SLNode));
			tmplitter->data = list->data;
			curlitter->next = tmplitter;
			curlitter = tmplitter;
			list = list->next;
		}
	}
	curbig->next = NULL;
	pheadlitter = pheadlitter->next;
	pheadbigger = pheadbigger->next;
	curlitter->next = pheadbigger;
	free(curbig2);
	free(curlitter2);
	return pheadlitter ;
}

void SLPushFront(SLNode** pphead,SLDataType x)//ͷ�����뺯��
{
	//С�˼�������дע�Ͱ�
	//���ﴫ��Ļ��ǽṹ��ĵ�ַ�ĵ�ַ�������Ƚ�����һ�£��õ��ṹ��ĵ�ַ
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;
	
	if (*pphead == NULL)
	{
		//�����*ppheadֻ��������һ�Σ����Ա�ʾ����������Ԫ�صĵ�ַ
		*pphead = newnode;
		//����������Ԫ�صĵ�ַΪ�վͱ�ʾ�������Ļ�δ���壬ֱ�Ӱ�����������Ԫ�صĵ�ַ��Ϊnewnode�Ϳ���
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;//ע�⣬�����*���ǽ����ã���Ϊpphead��һ������ָ�룬��newnode��һ��һ��ָ�롣
		//�����newnode��ֵ��*pphead
		//��Ϊ����ʱ��pphead��һ������ָ�룬��������ı�ֱ���ܴ�������
	}
}