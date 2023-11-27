#include"tree.h"
void inittree(BiTree gen)
{
	gen->left = NULL;
	gen->right = NULL;
	gen->parent = NULL;
	gen->value = 0;
}
//初始化这个树
void morebranch(BiTree now,Element a)
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
	else if (now->left!=NULL&&now->right==NULL)
	{
		now->right = branch;
	}
	else if (now->left!=NULL&&now->right!=NULL)
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
		printf("%d", gen->value);
	}
	if(gen!=NULL)
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
	int l = treedeep(gen->left)+1;
	//当这个函数递归到最后一位的时候，返回0
	int r = treedeep(gen->right)+1;
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
		printf("%d", gen->value);
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
		printf("%d", gen->value);
	}
}
//后续遍历
void level_order(BiTree gen)	
{
	Queue c;
	QueueInit(&c);
	QueuePush(&c, gen);
	BiTree new=NULL;
	while (!QueueEmpty(&c))
	{
		new = QueueFront(&c);
		//new虽然是一个地址，但是不是head的地址，而是head这个地址里面存储的地址
		if(new!=NULL)
		{
			printf("%d  ", new->value);
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
	while (p||!IsEmpty(&a))
	{
		if(p!=NULL)
		{
			StractPush(&a, p);
			p = p->left;
		}
		else
		{
			p = a.tail->a;//这里栈只能尾插尾删，所以要让他等于尾部
			StractPop(&a);
			printf("%d",p->value);
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
			printf("%d", p->value);
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
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	BiTree r = NULL;
	while (p || !IsEmpty(&a))
	{
		if (p != NULL )
		{
			StractPush(&a, p);
			p = p->left;
		}
		else//如过这个结点的左孩子为空，弹出，访问这个结点的右孩子
		{
			p = a.tail->a;//这里栈只能尾插尾删，所以要让他等于尾部
			if(p->right&&p->right!=r)//当这个元素的左孩子不为空且这个元素的左孩子没有被遍历过的时候
			{
				p = p->right;//令指针指向这个结点的右孩子
				StractPush(&a, p);//然后让这个右孩子入栈
				p = p->left;//开始让指针指向这个新结点的左孩子然后开始遍历
			}
			else //如果这个结点的右孩子为空，或者它的右孩子被访问到了
			{
				//这个时候左右孩子都为空，左右孩子都遍历了，那就要打印这个元素了
				printf("%d", p->value);
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
		printf("%d", node->value);
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
	//rear是数组中现在正在输入的元素的下标的位置
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
	while (front < rear)//当rear到头之后，rear不会增加了，知道front增加到rear的大小，结束循环
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
		//为什么rear指向的是下一层元素的最后一个结点，因为当这一层的导入完毕之后，Q内的元素总共到下一层最后一个
		// 为什么front是当前的元素的最后一个结点
		// 每次都会让last等于rear，这样当这一层的循环开始的时候，last和rear都是一样的，last指向这一层的元素的最后一个
		// rear在这一层的元素遍历完全的时候，刚好指向下一层的元素的最后一个。
		//当现在的front等于last的时候，就让last等于现在的rear，因为rear是下一层元素的最后一个结点
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

//如果让空的结点也入进去之后，那么当开始有第一个为NULL的结点后
//后面只要有一个不为空的结点，那么这个树就不是完全二叉树
//完全二叉树的所有的结点的位置和满二叉树的位置相同，
//比如
//比如有这样一个树        A
//						/   \
//					   B     C
//				      / \   / \
//					 D   E 空  F
//正常的层序遍历完全二叉树，最后一个结点就是最下面一排的最后一个结点，如果入队之后，
//完全二叉树的空的结点之后全部为空
//比如有这样一个树        A
//						/   \
//					   B     C
//				      / \   / \
//					 D   E F  空
//那么这个空后面的所有的元素的都是DEF的子结点，都是空
void judge(BiTree gen)
{
	Queue c;
	QueueInit(&c);
	QueuePush(&c, gen);
	BiTree new = NULL;
	int i = 0;
	while (!QueueEmpty(&c))
	{
		new = QueueFront(&c);
		//new虽然是一个地址，但是不是head的地址，而是head这个地址里面存储的地址
		//如果这个结点的左孩子等于空，要么，它的右孩子也为空，然后令i等于2，剩下的所有结点进入else if的判断
		//要么，它的右孩子不为空，那么这个二叉树不是完全二叉树。结束程序。
		if (new != NULL&&i<=2)
		{
			if (new->left != NULL)
			{
				QueuePush(&c, new->left);
			}
			else if (new->left == NULL)
			{
				i++;
			}
			if (i==0&&new->right != NULL)
			{
				QueuePush(&c, new->right);
			}
			else if (i == 1 && new->right != NULL)
			{
				printf("不是");
				return;
			}
			else
			{
				i++;
			}
		}
		//上面的那个结点的两个孩子都为NULL，那么下面的所有的元素肯定都为叶子结点
		//如果不是叶子结点，那么这个树就不是完全二叉树。
		else if (new != NULL && i > 2)
		{
			if (new->left != NULL)
			{
				printf("不是");
			}
			if (new->right != NULL)
			{
				printf("不是");
			}
		}
		QueuePop(&c);
	}
	printf("是");
}

BiTree PreInCreat(int A[], int B[], int l1, int h1, int l2, int h2)
{
	//11.h1 为先序的第一和最后个结点个标，12，h2 为中序的第一和最后一个结点下标
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
	root->value = A[l1];
	int i;//i是根节点所在位置的下标。
	int llen;//左子树的长度
	int rlen;//右子树的长度
	for (i = l2; B[i] != root->value; i++);
	llen = i - l2;//llen等于根结点所在位置的下标，减去初始位置的下标。
	//也就是根节点之前的元素个数
	rlen = h2 - i;//rlen就等于结束位置的下标减去根节点所在位置的下标。
	//也就是根节点之后的元素的个数。
	if (llen)
	{
		root->left = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
		//l1+1的原因是，前序遍历的数组的第一个数（也就是正在遍历的数组的根结点）
		// 已经输入进去了。现在的左子树的开始的结点应该是根结点之后的第一个结点。也就是l1+1）
		//l1+llen，就是左子树结束的位置。因为llen是左子树的长度。
		//l2表示中序遍历的开始的结点没有进入。
		//l2+llen-1的指向的是。中序遍历中的根节点前面那个位置的元素下标。
	}
	else
	{
		root->left = NULL;
	}
	if (rlen)
	{
		root->right = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
		//（h1-rlen+1表示的是，前序遍历的数组的结尾元素的下标减去右子树的长度再加一，指向的是
		// 前序遍历之中，指向根节点之后的第一个元素的下标
		// h1指向的是前序遍历数组的结尾的那个元素的下标
		// h2-rlen+1指向的是中序遍历中的，根节点之后的第一个元素的下标
		// h2指向的是中序遍历中的整个数组的最后一个数组的下标）
	}
	else
	{
		root->right = NULL;
	}
	//（对于中序遍历和前序遍历，
	// 中序遍历：左子树    根    右子树
	// 在遍历的过程中，根开始填充进入这个数，也就是从中间开始减少。
	// 前序遍历  根     左子树   右子树
	// 在遍历的过程中，根开始填充进入这个数，也就是从最左边开始减少。
	// 可以看出这连个遍历的数组的（左子树的长度加1）个元素之后就都是右子树的元素）
	//所以右子树的遍历里面，还是继续利用h1和h2。
	return root;
}


int  alevel_order(BiTree gen)
{
	Queue c;
	QueueInit(&c);
	QueuePush(&c, gen);
	BiTree new = NULL;
	int i = 0;
	while (!QueueEmpty(&c))
	{
		new = QueueFront(&c);
		//new虽然是一个地址，但是不是head的地址，而是head这个地址里面存储的地址
		if (new != NULL)
		{
			int a = 0;
			printf("%d  ", new->value);
			if (new->left != NULL)
			{
				QueuePush(&c, new->left);
				a++;
			}
			if (new->right != NULL)
			{
				QueuePush(&c, new->right);
				a++;
			}
			if (a == 2)
			{
				i++;
			}
		}
		QueuePop(&c);
	}
	printf("\n");
	return i;
}
//查看这个二叉树有多少个度为2的结点

void blevel_order(BiTree gen)
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
			BiTree a = (BiTree)malloc(sizeof(BiTNode));
			if (new->left != NULL)
			{
				QueuePush(&c, new->left);
			}
			a = new->left;
			
			if (new->right != NULL)
			{
				QueuePush(&c, new->right);
			}
			new->left = new->right;
			new->right = a;
		}
		QueuePop(&c);
	}
}
//交换这个二叉树的所有的结点的左右结点

void kpre(BiTree gen, int n)
{
	int i = 0;
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	while ((p||!IsEmpty(&a)))
	{
		if (p != NULL)
		{
			StractPush(&a, p);
			i++;
			if (i == n)
			{
				break;
			}
			p = p->left;
			
		}
		else
		{
			p = a.tail->a;
			StractPop(&a);
			p = p->right;
		}
	}
	printf("%d\n", p->value);
}

//先序遍历到第k个结点之后，停止遍历，并输出第k个值

void delpre(BiTree gen, int x)
{
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	while ((p || !IsEmpty(&a)))
	{
		if (p != NULL)
		{
			if (p->value == x)
			{
				if (p == p->parent->left)
				{
					BiTree pparent = p->parent;
					freeall(p);
					pparent->left = NULL;
				}
				else
				{
					BiTree pparent = p->parent;
					freeall(p);
					pparent->right = NULL;
				}
				p = NULL;
			}
			else
			{
				StractPush(&a, p);
				p = p->left;
			}
		}
		else
		{
			p = a.tail->a;
			StractPop(&a);
			p = p->right;
		}
	}
}
//找到值为x的结点，删除以它为根的子树，并释放所有的子结点的空间

void freeall(BiTree gen)
{
	if (gen->left != NULL)
	{
		freeall(gen->left);
		gen->left = NULL;
	}
	if (gen->right != NULL)
	{
		freeall(gen->right);
		gen->right = NULL;
	}
	free(gen);
}
//释放以gen为根节点的树的空间

void xparent(BiTree gen, int x)
{
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	BiTree r=NULL;
	while (p != NULL || !IsEmpty(&a))
	{
		if (p != NULL)
		{
			StractPush(&a, p);
			p = p->left;
		}
		else
		{
			p = a.tail->a;
			if (p->right != NULL && p->right != r)
			{
				p = p->right;
			}
			else
			{
				//printf("%d", p->value);
				StractPop(&a);
				if (p->value == x)
				{
					while (!IsEmpty(&a))
					{
						p = a.tail->a;
						printf("%d", p->value);
						StractPop(&a);
					}
					return;
				}
				r = p;
				p = NULL;
			}
		}
	}
}
//找到值为x的结点的所有祖先

void ownparent(BiTree gen, BiTree r, BiTree p)
{
	int* arr1[10];
	int* arr2[10];
	int i = 0;;
	forpraent(gen, r,&arr1);
	forpraent(gen, p,&arr2);
	while (arr1[i] != NULL)
	{
		int j = 0;
		while (arr2[j] != NULL)
		{
			if (arr2[j] == arr1[i])
			{
				BiTree new = arr1[i];
				printf("距离他们两个最近的祖先节点为%d,存储的数据为%d", arr1[i], new->value);
				return;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
}
//找到两个结点共同的祖先

void forpraent (BiTree gen, BiTree d,int *arr[])
{
	Stracts a;
	Initializes(&a);
	BiTree p = gen;
	BiTree r = NULL;
	while (p != NULL || !IsEmpty(&a))
	{
		if (p != NULL)
		{
			StractPush(&a, p);
			p = p->left;
		}
		else
		{
			p = a.tail->a;
			if (p->right != NULL && p->right != r)
			{
				p = p->right;
			}
			else
			{
				//printf("%d", p->value);
				StractPop(&a);
				if (p == d)
				{
					int i = 0;
					while (!IsEmpty(&a))
					{
						p = a.tail->a;
						//printf("%d", p->value);
						arr[i] = p;
						i++;
						StractPop(&a);
					}
					arr[i] = NULL;
					return;
				}
				r = p;
				p = NULL;
			}
		}
	}
}
//找到一个结点的所有祖先的地址，并把他们按顺序放入到arr中去

void longest(BiTree gen)
{
	
	if (!gen)
	{
		return;
	}
	int front = -1, rear = -1, last = 0, width = 0;
	int max = 0;
	//这里的front记录的是现在这一层的最后一个元素在数组中的下标位置
	//rear是数组中现在正在输入的元素的下标的位置
	//last指向的是最底下一层的的最后一个元素的下标的的位置
	//level是层数
	//比如这样一个二叉树
	BiTree Q[100];
	Q[++rear] = gen;
	BiTree p;
	while (front<rear)
	{
		p = Q[++front];//这里要先++front，不然会出错的
		if (p->left != NULL)
		{
			width++;
			Q[++rear] = p->left;
		}
		if (p->right != NULL)
		{
			width++;
			Q[++rear] = p->right;
		}
		if (front == last)
		{
			if (max < width)
			{
				max = width;
			}
			last = rear;
			width = 0;
		}
	}
	printf("%d", max);
}
//计算出整个树中最宽的一层的长度


BiTree PretoFai(int arr[], int sz)
{
	BiTree gen = (BiTree)malloc(sizeof(BiTNode));
	gen->value = arr[0];
	gen->left = NULL;
	gen->right = NULL;
	
	if((sz-1)/2>0)
	{
		int i = 0;
		int j = 0;
		int* arr1 = (int*)malloc(sizeof(int) * (sz - 1) / 2);
		int* arr2 = (int*)malloc(sizeof(int) * (sz - 1) / 2);
		for (i = 0; i < (sz - 1) / 2; i++)
		{
			arr1[i] = arr[i + 1];
		}
		for (j = 0; j < (sz - 1) / 2; j++)
		{
			arr2[j] = arr[((sz + 1) / 2)+j];
		}
		gen->left = PretoFai(arr1, (sz - 1) / 2);
		gen->right = PretoFai(arr2, (sz - 1) / 2);
	}
	return gen;
}
//将一个满二叉树的前序序列转变为后序序列
void printfFai(int arr[], int sz)
{
	BiTree gen = PretoFai(arr, sz);
	FaiOrder(gen);
}


void PretoFai2(int arr[], int sz,int* sz2,int arrover[])
{
	arrover[(*sz2) - 1] = arr[0];
	(*sz2)--;
	if ((sz - 1) / 2 > 0)
	{
		int i = 0;
		int j = 0;
		int* arr1 = (int*)malloc(sizeof(int) * (sz - 1) / 2);
		int* arr2 = (int*)malloc(sizeof(int) * (sz - 1) / 2);
		for (i = 0; i < (sz - 1) / 2; i++)
		{
			arr1[i] = arr[i + 1];
		}
		for (j = 0; j < (sz - 1) / 2; j++)
		{
			arr2[j] = arr[((sz + 1) / 2) + j];
		}
		PretoFai2(arr2, (sz - 1) / 2, sz2, arrover);
		PretoFai2(arr1, (sz - 1) / 2, sz2, arrover);

	}
	return ;
}
//将一个满二叉树的前序序列转变为后序序列2
void printfFai2(int arr[], int sz, int arr2[])
{
	int sz2 = sz;
	PretoFai2(arr, sz, &sz2, arr2);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr2[i]);
	}
}
