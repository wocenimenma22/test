#include"momo.h"
void inittree(BiTree gen)
{
	gen->left = NULL;
	gen->right = NULL;
	gen->parent = NULL;
	gen->value = 'A';
}
//初始化这个树
void morebranch(BiTree now, Element a)
{
	BiTree branch = (BiTree)malloc(sizeof(BiTNode));
	branch->left = NULL;
	branch->right = NULL;
	branch->parent = now;
	branch->value = a;
	if (now->left == NULL)
	{
		now->left = branch;
	}
	else if (now->left != NULL && now->right == NULL)
	{
		now->right = branch;
	}
	else if (now->left != NULL && now->right != NULL)
	{
		free(branch);
		printf("error,this is full");
	}
}
//插入新的元素
void PreOrder(BiTree gen)
{
	if (gen != NULL)
	{
		printf("%c", gen->value);
	}
	if (gen != NULL)
	{
		PreOrder(gen->left);
	}
	if (gen != NULL)
	{
		PreOrder(gen->right);
	}
}
//先序遍历
int treedeep(BiTree gen)
{
	if (gen == NULL)
	{
		return 0;
	}
	int l = treedeep(gen->left) + 1;
	//当这个函数递归到最后一位的时候，返回0
	int r = treedeep(gen->right) + 1;
	//递归算法，好久没有使用了。可以重温一下
	if (l > r)
	{
		return l;
	}
	else
	{
		return r;
	}
}
//测量数的深度
void MidOrder(BiTree gen)
{

	if (gen != NULL)
	{
		MidOrder(gen->left);
	}
	if (gen != NULL)
	{
		printf("%c", gen->value);
	}
	if (gen != NULL)
	{
		MidOrder(gen->right);
	}
}
//中序遍历
void FaiOrder(BiTree gen)
{

	if (gen != NULL)
	{
		FaiOrder(gen->left);
	}
	if (gen != NULL)
	{
		FaiOrder(gen->right);
	}
	if (gen != NULL)
	{
		printf("%c", gen->value);
	}
}
//后续遍历
BiTree level_order(BiTree gen,int j)
{
	Queue c;
	QueueInit(&c);
	QueuePush(&c, gen);
	BiTree new = NULL;
	int i = 0;
	while (!QueueEmpty(&c)&&i<=j)
	{
		new = QueueFront(&c);
		//new虽然是一个地址，但是不是head的地址，而是head这个地址里面存储的地址
		if (new != NULL)
		{
			i++;
			if (new->left != NULL)
			{
				QueuePush(&c, new->left);
			}
			if (new->right != NULL)
			{
				QueuePush(&c, new->right);
			}
		}
		QueuePop(&c);
	}
	return new;
}
//层序遍历
void noMidOrder(BiTree gen)
{
	//一直循环的条件是
	//中序遍历的过程，先一直访问它的左子树，遇到一个入栈一个，当这个左子树为空的时候，弹出访问并删除栈中的栈顶元素
	//让指针指向这个元素，然后访问这个元素的右孩子，如果它没有右孩子，弹出访问并删除栈中现在的栈顶元素。对这个栈顶元素执行同样的操作
	// 如果它的右孩子有左孩子那么重复最开始的操作，否则访问它的右孩子，如果它没有右孩子
	//这里，如果有元素为空，那么就在栈中弹出一个元素,并在访问完这个元素之后，让指针p指向这个元素的右孩子；
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	while (p || !IsEmpty(&a))
	{
		if (p != NULL)
		{
			StractPush(&a, p);
			p = p->left;
		}
		else
		{
			p = a.tail->a;//这里栈只能尾插尾删，所以要让他等于尾部
			StractPop(&a);
			printf("%c", p->value);
			p = p->right;
		}
		//要点：这里，如果有元素为空，那么就在栈中弹出一个元素,并在访问完这个元素之后（访问完的意思就是，打印出这个元素的值），
		// 让指针p指向这个元素的右孩子；
		//而当元素不为空的时候就一直遍历它的左孩子就行

		//因为这里是中序遍历，当访问到最底层元素的时候，发现它的左孩子为空，然后在访问它的右孩子之前，打印它
		//当它的右孩子会在访问到它的右孩子的左孩子为空的时候打印，然后再访问它的右孩子的右孩子为空，就弹出栈中的一个元素

		//访问到左孩子为空的时候，else是为了弹出栈中的元素，然后访问它的右孩子的
		//访问到右孩子为空的时候，else就再网上弹出一层元素，开始访问别的
		//比如有这样一个树       A
		//						/ \
		//					   B   C
		//				      / \   \
		//					 D   E   F
		//当访问到D的左孩子为空的时候，弹出是为了返回D，然后打印D，
		//当访问到D的右孩子为空的时候，弹出是为了返回B，然后打印B，
		//然后再访问B的右孩子，发现为E，再访问E的左孩子，发现为空，返回E，然后打印E
		//当访问到E的右孩子为空的时候，弹出是为了返回A，然后打印A

	}
}
//不需要递归的先序遍历
void noPreOrder(BiTree gen)
{
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	while (p || !IsEmpty(&a))
	{
		if (p != NULL)
		{
			StractPush(&a, p);
			if (p->value == '\0')
			{
				p->parent->left = NULL;
			}
			//插入就打印，因为要先连接到的肯定都是每个树的根节点。
			//进来的时候就直接把他打印了，和中序遍历的区别就在于打印的时候不同，走完整个树的顺序是相同的
			p = p->left;
		}
		else
		{
			p = a.tail->a;//这里栈只能尾插尾删，所以要让他等于尾部
			StractPop(&a);

			p = p->right;
		}
	}
}
//不需要递归的中序遍历
void noFaiOrder(BiTree gen)
{
	int i = 0;
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	BiTree r = NULL;
	while (p || !IsEmpty(&a))
	{
		if (p != NULL)
		{
			StractPush(&a, p);
			p = p->left;
		}
		else//如过这个结点的左孩子为空，弹出，访问这个结点的右孩子
		{
			p = a.tail->a;//这里栈只能尾插尾删，所以要让他等于尾部
			if (p->right && p->right != r)//当这个元素的左孩子不为空且这个元素的左孩子没有被遍历过的时候
			{
				p = p->right;//令指针指向这个结点的右孩子
				StractPush(&a, p);//然后让这个右孩子入栈
				p = p->left;//开始让指针指向这个新结点的左孩子然后开始遍历
			}
			else //如果这个结点的右孩子为空，或者它的右孩子被访问到了
			{
				//这个时候左右孩子都为空，左右孩子都遍历了，那就要打印这个元素了
				printf("%c", p->value);
				i++;
				StractPop(&a);
				//打印出数据并删除这个元素
				//然后让r等于p，表示刚刚遍历了p这个结点
				r = p;
				//因为已经打印了，所以表示遍历了。
				p = NULL;
				//让p=null是为了再进入这个窗口，然后弹出下一个栈顶中的元素。
			}
			//比如有这样一个树       A
			//						/ \
			//					   B   C
			//				      / \   \
			//					 D   E   F
			//这里A入栈,遍历A的左孩子，然后B入栈，然后遍历B的左孩子，然后D入栈，然后遍历D的左孩子
			//发现D的左孩子为空，此时的指针p指向的为NULL，所以此时开始执行第一个else里买的呢内容，
			//让p等于栈顶的元素D，如果D的右孩子存在，那么访问他，但是D的右孩子不存在，所以执行第二个else
			//里面的内容，打印D的值，然后从栈顶删除D。再让r=D，代表刚刚访问的元素是D，p=NULL（这样再
			// 执行的时候就会访问栈顶元素的B，）然后发现B的右孩子为E，让p指向E,让E入栈，E入栈之后，让
			// p指向E的左孩子，这样p等于NULL，然后再循环的时候，就会进入第一个else，就会再次让p指向E
			// 指向E之后，发现E的右孩子也为空，就进入第二个else，删除栈顶元素E，打印这个元素的值
			// 然后r=E，表示访问过这个元素，p=NULL（然后这个再次进行循环的时候，就会进入第一个else
			// 然后让p等于栈顶的元素B），p等于元素B之后，因为r=E，代表已经遍历过B的右孩子了，再次进
			//入第二个else，删除这个栈顶元素，打印这个元素B的值，然后r=B，p=NULL（然后再循环的时候进入
			// 第一个else，p指向A）p指向A之后，进入第二个if，C入栈，发现C没有左孩子，就开始遍历C的右孩子
			//发现F没有左孩子，开始遍历F的右孩子，也没有，就打印F的值，r=F然后p指向NULL（这样再出来的时候，
			// 再进入else，p指向C）C之后，发现F已经被遍历过了，打印删除，r=C，p=NULL。剩下的过程同上。
		}
	}
	printf("\n%d\n", i);
}
//不需要递归的后序遍历
// 
// 
//队列的基础操作
QueneNode* Buynode(QDataType x)
{
	QueneNode* newnode = (QueneNode*)malloc(sizeof(QueneNode));
	newnode->a = x;
	return newnode;
}
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	QueneNode* cur = pq->head;
	while (cur)
	{
		QueneNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
void QueuePush(Queue* pq, QDataType x)//向链表插入数据
{
	assert(pq);
	QueneNode* newnode = Buynode(x);
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		(pq->tail)->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueneNode* head = pq->head;
	pq->head = head->next;
	free(head);

}
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return (pq->head)->a;
}
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return (pq->tail)->a;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int a = 0;
	QueneNode* cur = pq->head;
	while (cur)
	{
		a++;
		cur = cur->next;
	}
	return a;
}
bool QueueEmpty(Queue* pq)
{
	if (pq->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//队列的基础操作

void Initializes(Stracts* pa)
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void StractPush(Stracts* pa, BiTree gen)//栈只能尾插尾删
{
	assert(pa);
	if (IsFull(pa) == true)
	{
		printf("无法插入\n");
		return;
	}
	Stract* newnode = (Stract*)malloc(sizeof(Stract));//申请一块新的内存空间为新的元素
	newnode->a = gen;//新元素存储的数据的内容等于x
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
	if (pa->head != pa->tail)
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

BiTree StractFind(Stracts* pa, int x)
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

void fanlevel_order(BiTree gen)
{
	Stracts a;
	Initializes(&a);
	Queue c;
	QueueInit(&c);
	QueuePush(&c, gen);
	BiTree new = NULL;
	while (!QueueEmpty(&c))
	{
		new = QueueFront(&c);
		//new虽然是一个地址，但是不是head的地址，而是head这个地址里面存储的地址
		if (new != NULL)
		{
			StractPush(&a, new);
			if (new->left != NULL)
			{
				QueuePush(&c, new->left);
			}
			if (new->right != NULL)
			{
				QueuePush(&c, new->right);
			}
		}
		QueuePop(&c);
	}
	while (!IsEmpty(&a))
	{
		BiTree node = a.tail->a;
		printf("%s", node->value);
		StractPop(&a);
	}
}

int Btdepth(BiTree T)
{
	if (!T)
	{
		return 0;
	}
	int front = -1, rear = -1, last = 0, level = 0;
	//这里的front记录的是现在这一层的最后一个元素在数组中的下标位置
	//rear是现在所指向的元素在数组中的下标的位置
	//last指向的是最底下一层的的最后一个元素的下标的的位置
	//level是层数
	//比如这样一个二叉树
	BiTree Q[100];
	//比如有这样一个树       A
	//						/ \
	//					   B   E
	//				      / \   \
	//					 C   D   F
	//front最开始是-1，然后rear是-1.last和level都是0
	//让Q的第（rear+1=）0个元素等于二叉树的根节点A；
	//然后发现front比现在的rear小，所以就让p等于Q的第（rear+1）=0个元素A
	//然后因为p左孩子不为空，让Q的第（rear+1）=1个元素等于p的左孩子
	//右孩子同理。
	Q[++rear] = T;
	BiTree p;
	while (front < rear)
	{
		p = Q[++front];
		if (p->left)
		{
			Q[++rear] = p->left;
		}
		if (p->right)
		{
			Q[++rear] = p->right;
		}
		//当现在的front等于last的时候，就让last等于现在的rear，以为rear是下一层元素的最后一个结点
		//front是刚检查完左右孩子是否为空，以及入数组的元素的下标，所以，当这个来到last的时候
		//就代表这个一层的元素检查完了
		if (front == last)
		{
			level++;
			last = rear;
		}

	}
	return level;
}

void reallevel_order(BiTree gen)
{
	Queue c;
	QueueInit(&c);
	QueuePush(&c, gen);
	BiTree new = NULL;
	while (!QueueEmpty(&c))
	{
		new = QueueFront(&c);
		//new虽然是一个地址，但是不是head的地址，而是head这个地址里面存储的地址
		if (new != NULL)
		{
			printf("%c", new->value);
			if (new->left != NULL)
			{
				QueuePush(&c, new->left);
			}
			if (new->right != NULL)
			{
				QueuePush(&c, new->right);
			}
		}
		QueuePop(&c);
	}
}

void zhangmo(char *a)
{
	BiTree gen = (BiTree)malloc(sizeof(BiTNode));
	inittree(gen);
	BiTree p = gen;
	p->value = a[0];
	int i = 1;
	int j = 0;
	int front = -1, rear = -1, last = 0;
	while (a[i] != NULL)
	{
		j++;
		if (a[i] != NULL)
		{
			morebranch(p, a[i++]);
		}
		if(a[i]!= NULL)
		{
			morebranch(p, a[i++]);
		}
		p = level_order(gen, j);
	}
	noPreOrder(gen);
	printf("\n");
	noMidOrder(gen);
	printf("\n");
	noFaiOrder(gen);
	printf("\n");
	int dep = Btdepth(gen);
	printf("%d", dep);
}

void zhangdatou(char* pre, char* mid, BiTree p,int yesorno,int abc)
{
	//输入的pre和mid的字符串长度肯定是一样的，所以这个if只需要判断pre或者mid中的一个
	//当pre只有一个字符的时候，代表这个字符就是剩下的唯一的结点。直接把这个插入到p中去就行。
	if (pre[1] == '\0' && pre[0] != NULL)
	{
		morebranch(p, pre[0]);
	}
	//否则，当这个不为空而且它不止有一个字符的时候，就还能拆
	else if(pre[0]!='\0'&&mid[0]!='\0')
	{	
		char* a = mid;
		//先把mid的地址给a，这样对a进行操作就不会影响mid的值。
		while (*a != pre[0])
		{
			a++;
			//找到头节点在中序遍历字符串中的位置
		}
		if(yesorno==1)
		{
			//根节点没办法直接插入，所以在这个函数外面的那个函数直接修改gen的值。
			//然后传入一个数字0，当这个数为0的时候，代表是第一次进入这个递归，
			//因为根节点有数值，所以直接跳过插入数据这一步，然后把这个数值改为1
			//后面每一步都是1，都要插入这个值。
			if(abc==1)
			{
				morebranch(p, pre[0]);
				//把这个头节点插入进去，但是要注意插入完成后，是进入左子树还是进入右子树
				//所以单独传入一个参数abc来确定是进入左子树还是右子树
				p = p->left;
			}
			if (abc == 0)
			{
				morebranch(p, pre[0]);
				p = p->right;
			}
		}
		else
		{
			yesorno = 1;
		}
		//命名所需要的元素
		char leftmid[10];
		//应该可以使用malloc对内存空间进行优化
		//存储中序遍历的根节点的左边的字符串
		leftmid[0] = '\0';
		char rightmid[10];
		//存储中序遍历的根节点的右边的字符串
		rightmid[0] = '\0';
		//令foright从根结点的下一个结点出发
		char* foright = a + 1;
		char* mid2 = mid;
		//定义一个和mid一样的元素，便于进行下一步遍历
		int i = 0;
		int j = 0;
		while (*mid2 != *a)
		{
			//从中序遍历的字符串的最开始进行循环
			//得到根节点之前的所有字符串
			leftmid[i] = *mid2;
			mid2++;
			i++;
		}
		leftmid[i] = '\0';
		while (*foright != '\0')
		{
			//得到中序遍历里面的所有的根节点之后的字符串
			rightmid[j] = *foright;
			j++;
			foright++;
		}
		rightmid[j] = '\0';
		char leftpre[10];
		char rightpre[10];
		leftpre[0] = '\0';
		rightpre[0] = '\0';
		char* pre2 = pre;
		int wwc = 0;
		//用来调整字符串的下标的数字
		int prei = 0;
		int prej = 0;
		if (leftmid[0] != NULL)
		{
			while (*pre2 !=NULL)//当pre2时，在整个leftmid里面
				//寻找是否有匹配的字符串，如果有，就继续，如果没用就开始退出
			{
				int wc = 0;
				int wzdcl = 0;
				while (leftmid[wc] != '\0')
				{
					if (*(pre2+1) == leftmid[wc])
					{
						wzdcl = 1;
						break;
					}
					wc++;
				}
				if (wzdcl == 0)
				{
					break;
				}
				leftpre[prei] = *(pre2+1);
				prei++;
				pre2++;
			}
			leftpre[prei] = '\0';
		}
		if(rightmid[0]!=NULL)
		{
			while (*(pre2+1) != '\0')
			{
				//从上一个字符串的结尾开始
				rightpre[prej] = *(pre2+1);
				prej++;
				pre2++;
			}
			rightpre[prej] = '\0';
		}
		if (leftmid[0] != NULL)
		{
			//如果这个字符串的中序遍历的字符串的根节点的左面的字符串不为空
			//表示这个元素存在左子树，再次进入这个函数，将这个新字符串的根节点插入到它的左孩子处
			//并让p指向这个左孩子，继续开始遍历
			zhangdatou(&leftpre, &leftmid,p,yesorno,1);
		}
		else
		{
			//如果这个不能插入左孩子，为了保证右孩子正常插入，这里传入NULL给p的左孩子
			//但是这里是让p的左孩子的值等于NULL，也就是'\0'不是左孩子的地址等于NULL；如果左孩子的地址等于
			//NULL，那么下一步还是会插入到p的左孩子上面。然后，结束整个函数之后，通过先序遍历
			//把所有的‘\0’的值的地址转换为NULL
			morebranch(p, NULL);
		}
		if (rightmid[0] != NULL)
		{
			//如果是右孩子不为空，那就插入右孩子
			zhangdatou(&rightpre, &rightmid,p,yesorno,0);
		}
		else
		{
			morebranch(p, NULL);
		}
	}
}

void realzhang(char* pre, char* mid)
{
	BiTree gen = (BiTree)malloc(sizeof(BiTNode));
	inittree(gen);
	BiTree p = gen;
	gen->value = pre[0];
	zhangdatou(pre, mid, p,0,0);
	noPreOrder(gen);
	noFaiOrder(gen);
	reallevel_order(gen);
}
