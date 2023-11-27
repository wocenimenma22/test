#include "SList.h"

void SLPrint(SLNode* phead)//打印函数
{
	if (phead == NULL)
	{
		printf("该结构体还没有插入元素，请从新插入");
		exit(-1);
	}
	SLNode* cur = phead;
	//所以，因为phead是一个指针，要拿一个cur指针去接收，因为不能对接收的结构体的指针进行直接操作
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

void SLPushiBack(SLNode** pphead,SLDataType x)//尾部插入函数
{
	//这里的pphead是链表首元素的地址的地址
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));//先定义一个newnode用来存储这个新的元素
	//这里的newnode是一个指针，而且，注意是而且（所以前面说的同样重要，这不是一个因果句子）
	//newnode是一个指针，下面不能使用.来解析结构体里面的元素，要使用->
	newnode->data = x;//记录
	newnode->next = NULL;//这里是尾插，所以next要定义为NULL
	if (*pphead == NULL)
	{
		//这里的*pphead只解引用了一次，所以表示的是链表首元素的地址
		*pphead = newnode;
		//如果链表的首元素的地址为空就表示这个链表的还未定义，直接把这个链表的首元素的地址置为newnode就可以
	}
	else
	{	
		SLNode* tail = *pphead;
		while (tail->next!=NULL)
		{
			//这里先给一个结构体的指针，用来接收*pphead
			//然后对这个tail进行操作，一直等到tail到达结构体的最后一个元素
			tail = tail->next;
		}
		//找到这个结构体的最后一个元素之后，这个元素的所携带的那个指针置成newnode，因为newnode本身就是一个结构体的指针
		//因为tail是一个指针，所以对tail进行的操作也会影响**pphead的那个结构体
		tail->next=newnode;
		//所以最后通过tail指针把这个结构体的next指针置newnode的，会影响到最开始定义的指针。
	}
}

void SLPopFront(SLNode** pphead)//头部删除函数
{
	if (*pphead == NULL)
	{
		printf("该结构体还没有插入元素，请从新插入");
		exit(-1);
	}
	//assert(*pphead != NULL);
	//删除这个函数的最前面的数据
	SLNode* cur = *pphead;
	//把这个赋值给另外一个
	//前面的*号是说明这是一个一级指针的数据，后面的这个*是用来解引用pphead的，因为pphead是一个二级指针，要解引用一次才变成一级指针
	*pphead = cur->next;
	//因为是头删，所以这里把第二个元素的地址赋值给第一个元素的地址
	free(cur);
	//然后释放这个第一个元素的地址，因为传入cur是一个地址，所以删除的就是这个链表上的数据元素
	cur->next = NULL;
	cur = NULL;
}

void SLPopBack(SLNode** pphead)//尾部删除函数
{
	if (*pphead == NULL)
	{
		printf("该结构体还没有插入元素，请从新插入");
		exit(-1);
	}
	else if ((*pphead)->next == NULL)//注意这里，加上一个括号就能正常使用了
	{
		free(*pphead);
		*pphead = NULL;
		//当只有一个元素的时候，直接清除不再进入下一步，否则会报错
	}
	else
	{
		SLNode* cur = NULL;
		SLNode* tail = *pphead;
		//这里给出两个指针，一个指向最后一个，一个指向倒数第二个，在遍历的过程种，其中一个永远落后另外一个元素一个地址
		//这样遍历到最后还能得到这个元素的前一位的地址，用来把他的next置为空
		while (tail->next != NULL)
		{
			//这里先给一个结构体的指针，用来接收*pphead
			//然后对这个tail进行操作，一直等到tail到达结构体的最后一个元素
			cur = tail;
			tail = tail->next;
		}
		//方法一：在最开始的时候再定义一个指针，每次落后一个
		cur->next = NULL;
		//方法二：直接next的next
		//tail->neat->next
	}
}

SLNode* SLFind(SLNode* phead, SLDataType a)//寻找一个数函数
{
	if (phead == NULL)
	{
		printf("该结构体还没有插入元素，请从新插入");
		exit(-1);
	}
	SLNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == a)
		{
			return cur;
		}
		//因为这个不会对这个链表的头的地址进行更改，所以这个传递的是单个元素
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
	printf("没有这个元素\n");
	return NULL;
}

void SLPushintheFront(SLNode** pphead, SLNode* ThePos, SLDataType x)//在一个数的前面插入函数
{
	if (*pphead == ThePos)
	{
		SLPushFront(pphead,x);
	}
	//如果是第一个元素和要出入前的元素相同的话就是头插，直接调用头插函数。
	//因为pphead定义的是SLNode**，所以这里不需要输入数据类型，x这个数不输入数据类型是因为同理
	else
	{
		SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
		newnode->data = x;
		newnode->next = NULL;
		SLNode* cur = *pphead;
		while (cur->next != ThePos)
		{
			cur = cur->next;
			//cur本身是一个地址，同时cur->next也是一个地址，所以可以这样使用，
			// 因为cur是一个地址所以这里要用->而不是.
		}
		cur->next = newnode;
		//直接给就行，不用管先后顺序，因为知道后面的那个的地址
		//也就是ThePos
		newnode->next = ThePos;
	}
}

void SLPushInTheBack(SLNode* pphead, SLNode* TheBack, SLDataType x)//在一个数的尾部插入函数
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;
	//先申请一块地址
	SLNode* cur = pphead;
	while (cur!= TheBack)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
}

void SLErase(SLNode** pphead, SLNode* Pos)//删除这个输入元素的函数
{
	if (*pphead == Pos)
	{
		SLPopFront(pphead);
		return;
		//如果第一个元素的地址，等于要删除的元素的地址，就代表这是一个头删，
		// 就直接调用头删除函数，因为这个要重置头
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

void SLEraseAfter(SLNode* Pos)//删除这个输入元素后面的元素的函数，这样做绝对不可能删除第一个元素，所以函数的首元素的地址不会改变
{
	SLNode* tmp = Pos->next;
	Pos->next = tmp->next;
	//先直接吧pos对应的下一位的地址，转换为下下一位的
	free(tmp);
	//时间复杂度为o（1），算是比较好的
}

void SLDestory(SLNode* list)
{
	assert(list);
	while (list->next != NULL)
	{
		SLNode* tmp = list->next;
		//先命名一个tmp指向list的下一个元素的地址
		list->next = tmp->next;
		//然后让list的所带的那个地址改成list后面的第二个元素的地址
		free(tmp);
		//tmp是个地址，释放的是tmp这个地址
		//tmp是list最开始的后面跟着的第一个元素的地址，所以这里释放这个元素的地址
	}
	free(list);
	//直到list后面的地址元素为空，跳出循环，释放list本身。list是个地址，是首元素的地址
	printf("\n销毁成功");
}

SLNode* ChangeSL(SLNode* list)//将链表的顺序反转。
{
	//这两个逆置函数把原来的链表破坏了。有时间写一个ChangeSL3在不打乱原链表的情况下，得到新的链表。
	//这样释放内存的时候只要释放比较长的个那个就行。因为长的那个包含短的。
	SLNode* prev = NULL;//正在操作的元素的前一位的元素，当now为首元素的是时候，这个为空
	SLNode* now = list;//正在操作的元素，
	SLNode* next = list->next;//正在操作的元素的下一位元素。
	while (now)
	{
		//当now不为空的时候，不断地循环进行修改路径
		if(next!=NULL)
		{
			//当next不等于空的时候，执行这个，因为next = next->next;要求next不为空
			now->next = prev;
			//让现在正在操作的元素now的next，所包含的地址指向它的前一位，同时它的next里本来存储的
			//下一位元素的地址保存在next（这里说的next指的是元素next）里面
			prev = now;
			//让prew变成现在正在操作的元素；，因为prev是个地址，它这个地址的值
			// （比如xx010203103什么的）已经被存入到now->next里面去了，所以这里可以直接让他成为now的地址
			//也就是因为prev和now都相同，而且他们只是地址，所以prev和now除了名字都完全一样。
			//现在的prev->next就等于prev
			now = next;
			//再让正在操作的元素的下一位元素成为要正在操作的元素。
			next = next->next;
			//再让要操作的元素向后伸展，最后一次，next后面的地址为空。
		}
		else
		{
			//当next等于NULL的时候，运行这个，就不再执行next = next->next;这一步操作了
			now->next = prev;
			//让现在正在操作的元素now的next，所包含的地址指向它的前一位。
			prev = now;
			//让prev成为正在操作的元素。
			now = next;
			//因为这个时候next为空，把now置为空，退出循环
		}
	}
	//循环结束，返回prev当作首元素的地址
	return prev;
}

SLNode* ChangeSL2(SLNode* list)//将链表的顺序反转
{
	SLNode* new=NULL ;
	SLNode* phead = list;
	while (phead)
	{
		SLNode* tmp = new;
		//把new先存储一下，对new这个变量进行修改，不会对这个内存地址进行修改
		new = phead;
		//把new赋值为phead的地址，这样它的data就等于phead的data，同时它的地址也等于phead
		//但是，同时因为phead的值被赋值给new，而他们两个都是地址，所以，对new进行的操作会改变phead，也就是new的next等于
		//phead的next
		SLNode* tmp2 = phead->next;
		//这里要先存储一下，phead->next，不然吧phead赋值给new之后，
		// 对new->next进行操作会使phead的内容也改变
		//然后会发生丢失
		new->next = tmp;
		//是new—>next的内容改为tmp，也就是上一个new（地址）
		phead = tmp2;
		//phead=tmp2，这里的tmp2等于上面的phead->next。
	}
	return new;
}

SLNode* MidSL(SLNode* list)//求中间的数
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

	//快慢指针，快的每次进两个，慢的每次进一个，当快的走完的时候，慢的刚好走一半
	SLNode* slow = list;
	SLNode* fast = list;
	while (fast != NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//无需释放地址，因为这里的地址都是list里面的地址
	return slow;
}

SLNode* LastKSL(SLNode* list, int k)//求倒数第k个数开始的链表
{
	if (k <= 0)
	{
		printf("k不能是负数");
		return list;
	}
	SLNode* slow = list;
	SLNode* fast = list;
	//类似快慢指针
	//先让快的指针先前进k步，然后两个指针同时向前走
	//两个指针都是每次只走一个，这样总共走了n-k步。慢的指针就到了倒数第k个
	//这里对应的是while这一步
	while (k --)
	{
		fast = fast->next;
		/*if (fast == NULL)
		{
			return NULL;
		}*/
		if (fast == NULL && k > 0)
		{
			printf("越界了,本次操作无效\n");
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
	//连个升序列表合成为一个列表
	

	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	//如果有一个链表为空，直接返回另外一个。不用担心两个都为空的情况
	//如果另一个也为空，返回的也为空
	SLNode* phead = (SLNode*)malloc(sizeof(SLNode));
	//申请一块地址作为头
	SLNode* tmp = phead;
	//保存这个头的位置，后续对这个进行操作
	SLNode* tmp2 = phead;
	//保存这个头的位置，后续释放用这个
	while (list1 && list2)
	{
		SLNode* dataput = (SLNode*)malloc(sizeof(SLNode));
		//申请一个地址，存储内容
		if (list1->data > list2->data)
		{
			dataput->data = list2->data;
			//data赋值给data
			tmp->next = dataput;
			tmp = tmp->next;
			list2 = list2->next;
			//赋值后，让tmp所携带的指针指向这个data，再把这个tmp
			//置新
			//最后把提供值的指针后传
		}
		else
		{
			dataput->data = list1->data;
			tmp->next = dataput;
			tmp = tmp->next;
			list1 = list1->next;
			//同上
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
			//执行到这里的时候，另外一个链表为空，这里每次申请一个地址
			//存储
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
	//最后把这个新链表的尾定位空指针
	phead = phead->next;
	free(tmp2);
	return phead;
}

SLNode* SameForHalf(SLNode* list1, SLNode* list2)
{
	//检测连个链表是否有交叉项。
	//这个在这里不能用
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

SLNode* KickSL(SLNode* list, int x)//把链表分为小于x的，和大于x的。然后合并成一个链表
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

void SLPushFront(SLNode** pphead,SLDataType x)//头部插入函数
{
	//小菜鸡还是先写注释把
	//这里传入的还是结构体的地址的地址。所以先接引用一下，得到结构体的地址
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;
	
	if (*pphead == NULL)
	{
		//这里的*pphead只解引用了一次，所以表示的是链表首元素的地址
		*pphead = newnode;
		//如果链表的首元素的地址为空就表示这个链表的还未定义，直接把这个链表的首元素的地址置为newnode就可以
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;//注意，这里的*号是解引用，因为pphead是一个二级指针，而newnode是一个一级指针。
		//这里把newnode赋值给*pphead
		//因为传的时候pphead是一个二级指针，所以这个改变直接能带到外面
	}
}