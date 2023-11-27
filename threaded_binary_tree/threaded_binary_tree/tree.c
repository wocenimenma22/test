#include"tree.h"
BiTree pre = NULL;
void inittree(BiTree gen)
{
	gen->left = NULL;
	gen->right = NULL;
	gen->parent = NULL;
	gen->value = 0;
	gen->ltag = 0;
	gen->rtag = 0;
}
//初始化这个树
void morebranch(BiTree now, Element a)
{
	BiTree branch = (BiTree)malloc(sizeof(BiTNode));
	branch->left = NULL;
	branch->right = NULL;
	branch->parent = now;
	branch->value = a;
	branch->ltag = 0;
	branch->rtag = 0;
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

void midthreaded(BiTree p)//中序遍历，通过递归的方式
{
	if (p)
	{
		
		midthreaded(p->left);
		
		//比如有这样一个树       A
		//						/ \
		//					   B   C
		//				      / \   \
		//					 D   E   F
		//(最开始pre=NULL，p指向A，令这个p为p1，然后向左遍历，让p指向B，令这个p为p2（这里的p1，p2
		// 纯粹为了我自己好区分，在代码中不存在），在向左遍历，让p指向D，令这个p为p3，然后再向左遍历，
		// 发现D的左孩子为空，就让D的左孩子指向pre，然后令ltag等于1。因为pre现在等于NULL，所以不对他进行操作
		// 。然后令pre等于D，以为D已经被遍历过了，然后开始遍历D的右孩子，发现D的右孩子为空，跳出。
		// 然后跳出本次在p3内的循环，)
		//（跳出p3的循环之后，pre等于D，然后现在的p指向B，也就是p2的循环
		// B的left是D，不等于NULL，所以不执行对它的左孩子的操作。然后pre现在指向的是D，所以他不为而且它的右孩子为空
		// 所以现在让它的右孩子指向现在正在遍历的元素p（p2，B）(因为上一层遍历的是D，所以在最后的时候让pre指向D表示D为上一个访问的元素)
		// 然后让pre指向B。开始访问B的右孩子，然后令p指向E，令这个p为p4，开始进入E结点，E结点的左孩子为空，所以让E的left等于B（也就是pre）
		// 因为pre的右孩子不为空，所以不对pre（B）进行操作，然后令pre等于E。进入遍历E的右孩子，发现E的右孩子为空
		// 跳出这个循环）
		//（pre等于E现在，从对E的右孩子的遍历跳出来之后，p为p4，然后再往下执行一步，这次对函数也就是对
		// p4遍历的执行也就完毕了，所以，跳出一层的递归。现在来到p2遍历，对p2执行的这次遍历刚执行midthreaded(p->right);这一步
		// 再执行下一步就结束这一层的递归了。然后p就再次指向p1这一层了 ）
		//（来到p1这一层，现在p指向的是A，而pre指向的是E，p的left不等于NULL，所以不执行这一步if里面的内容，然后pre为E，E不为空
		// 而且E的右孩子为空所以令pre（E）的left等于A，再令pre等于A。然后在p1的这一层递归执行到了midthreaded(p->right);这一步，开始对C进行
		// 遍历，进入下一层递归，p等于C，令这个p等于p5.发现p5的左孩子为空，所以跳出遍历，然后p5的left等于空，所以让他的left指向pre（A）
		// ，然后pre（A）的right不为空，所以不对它进行操作，pre等于C，，开始遍历p5的右子树，令p等于F，令这个p的等于p6.）
		//（进入对p6（F）的这一层递归，F的左子树为NULL，不对它进行遍历，pre的右子树不为空，不对它进行操作。pre等于F，pre的右子树为空
		// 不对它进行遍历。）、
		//遍历整个结束

		if (p->left==NULL)
		{
			p->ltag = 1;
			p->left = pre;
		}
		//当这个元素的左孩子的为空的时候，令这个元素的ltag等于1，然后左孩子的位置存储上一个访问的节点也就是pre
		if(pre&& pre->right == NULL)
		{
			pre->rtag = 1;
			pre->right = p;
			
		}
		//当pre元素本身不为空，且它的右孩子为空的时候，令pre元素的rtag等于1，然后右孩子孩子的位置存储下一个要访问的节点也就是p
		pre = p;//每次pre里面的内容更改完毕之后，就让pre指向现在的指针p，然后对p的右孩子进行下一次操作。
		//因为pre指向的是p的前面的一个指针，而p在最开始的时候就已经遍历过一次，所以p就是上一个指针，而p的right就是下一个指针。
		midthreaded(p->right);
	}
}//中序遍历
//中序遍历，通过递归的方式
void ordthreaded(BiTree p)
{
	//(
	//比如有这样一个树       A
	//						/ \
	//					   B   C
	//				      / \   \
	//					 D   E   F
	//最开始的时候，p指向A，令这个时候的p为p1，pre等于NULL。开始遍历p，因为p的左孩子不为空，所以不对它有操作
	// 因为pre为空，所以不对它有操作。然后让pre指向A，如果A的左孩子真的是它的左孩子，也就是ltag=0那么让p指向B，
	// 令这个p为p2，递归进入B的那一层 )
	//（发现B的左孩子也不为空，所以不对B进行任何操作，发现pre（A）的右孩子不为空，所以不对它有操作，
	// 然后让pre指向B，如果B的左孩子真的是它的左孩子，让p指向D，令这个p为p3，递归进入到D的那一层。然后发现D的左孩子为空
	// 所以令D的左孩子存储它的前驱结点，也就是让他等于pre（B）。
	// 然后发现pre（B）的右孩子不为空，所以不对它进行操作。     然后让pre的等于D，      虽然D的左孩子结点存储的
	// 不为NULL,但是D的ltag=1，所以不对它的左孩子进行遍历，执行	ordthreaded(p->right);发现这个也是空的，所以本层的
	// 递归结束（这也是第一个结束的递归）。然后就回到了上一层的递归，这个时候的p为p2也就是B，开始遍历B的右孩子
	// 令p等于E，令这一层的p为p4，此时的pre等于D,发现E的左孩子为空，所以让他的左孩子等于pre（D）,然后发现pre的右孩子为空
	// 所以让他的右孩子等于p，也就是p4（E）。    然后让pre等于E，         再继续遍历，p（E）的ltag等于1，
	// 所以不对它的左孩子进行操作，
	// p的右孩子为空，所以不对它的右孩子进行操作。至此对于p4这一层的遍历完结。跳出这一层遍历。）
	//跳出对于p4这一层的遍历的时候，返回到p2这一层的遍历，然后发现p2也要执行完毕了，所以再跳出一层遍历
	//（现在的p指向的是p1（A），已经执行到了	ordthreaded(p->right);这一步，开始对A的右子树进行遍历，令p指向C
	// 令这个p为p5，发现它的左子树为空，所以让它的左子树指向pre（E），然后发现E的右子树为空，所以让他的右子树等于
	// p（p5，C）,然后pre等于C，然后发现令p等于F，令这个p为p6，进入对于F的遍历的递归，然后发现F的左子树为空，
	// 所以让它的左子树的等于pre（C），pre的右子树不为空，所以不对pre进行操作。
	// 然后让pre等于F，然后因为p（F）的ltag等于1，所以不对它的左子树进行遍历，
	// 因为p的右子树为空，所以不对它进行遍历。循环结束。）
	if (p)
	{
		if (!p->left)
		{
			p->ltag = 1;
			p->left = pre;
		}
		if (pre)
		{
			if (!pre->right)
			{
				pre->rtag = 1;
				pre->right = p;
			}
		}
		pre = p;
		if(p->ltag==0)
		{
			ordthreaded(p->left);
		}
		if(p->rtag==0)
		{
			ordthreaded(p->right);
		}
	}

}
//先序遍历，通过递归的方式
void faithreaded(BiTree p)
{
	if (p)
	{
		//比如有这样一个树       A
		//						/ \
		//					   B   C
		//				      / \   \
		//					 D   E   F
		//(首先p指向A，令这里的p为p1，然后pre指向的是NULL，开始向A的左孩子递归，进入B这一层的递归
		// 这时候让p指向B，令这一层的p为p2.然后再次进入对p的左孩子，进入D这一层的递归，这时候让p指向D，
		// 令这一层的p为p3.然后发现p的左孩子为空，结束向下一步的遍历。开始对D的右孩子进行遍历
		// 发现B的右孩子为空，不对他进行遍历继续向下执行。p的左孩子为空，所以令它的left等于pre（NULL）
		// 因为pre为空，所以不对pre做什么操作。然后令pre等于p（p3，D）。然后这一层遍历的代码走完了
		// 返回上一层的递归，此时的p为p2（B），然后开始执行  faithreaded(p->right);  这个操作
		// 令p指向B的右子树，进入右子树之后发现E的左子树的左孩子为空，所以不对它进行遍历操作，
		// 右孩子也为空，所以不对它进行遍历操作。然后因为E的左孩子为空，所以让它的左孩子存储它的
		// 前驱结点。left等于pre（D），因为pre不为空，而且pre的右子树为空，所以令pre的右子树的为p
		// （E），然后令pre等于p（E），结束这次的递归，退出这一层的递归。p等于p2（B），然后B的左子树不为空，
		// 所以不做任何操作。pre不为空且pre的右孩子结点为空，所以，令pre的右孩子等于p（E）。
		// 然后令pre等于p（B）这一层的遍历结束，返回上一层。p等于A（p1）.开始对A的右孩子进行遍历。
		// 进入下一层的遍历。p等于C，令这个p为p5.发现p5的左子树为空，所以不对p5的左子树进行遍历
		// 然后发现p5的右子树不为空，进入对C的右子树的遍历，令p指向f，令这个p为p6.
		// 进入对F的遍历，发现F的左子树和右子树为空。因为F的左子树为空，所以现在让F的左子树
		// 等于pre（B）然后因为pre的右孩子不为空，所以不对它的做处理，令pre等于p（F）结束这一层遍历
		// 然后现在回到p5这一层的递归。进行到    if (!p->left)   这一步，发现它的left为空，所以令C的左子树
		// 等于pre（F）。pre的右子树为空，所以令pre的右子树等于p（C），然后令pre等于p，结束这一层的递归。
		// 回到p1（A）。这一层的递归。发现A的左子树不为空，所以不进行操作。然后因为pre（C）的右子树不为空，
		// 所以不进行操作。令pre等于A。结束整个程序)
		if(p->ltag==0)
		{
			//只有当这个元素里面存放的孩子节点不是线索元素的时候，才能进入下一个递归，否则就不执行。
			faithreaded(p->left);
		}
		if(p->rtag==0)
		{
			faithreaded(p->right);
		}
		if (!p->left)
		{
			p->ltag = 1;
			p->left = pre;
		}
		if (pre)
		{
			if (!pre->right)
			{
				pre->rtag = 1;
				pre->right = p;
			}
		}
		pre = p;
	}
}

void nofaithread(BiTree p)
{
	Stracts a;
	Initializes(&a);
	BiTree r = NULL;
	BiTree pre = NULL;
	BiTree gen = p;
	

	while (gen ||!IsEmpty(&a))
	{
		//当gen不为空的时候或者a不为空的时候，进入
		//当gen为空的时候，a也为空的时候，出去
		//第一次进入的时候，是因为gen，后面gen等于NULL了，但是a不为空，所以能继续循环
		//最后的时候，gen又等于NULL，但是a里面的数据也删除完毕了，所以退出循环
		//!IsEmpty(&a)不是它第一次进入的条件，而是后面gen=NULL的时候，它能继续下去的条件。
		if (gen != NULL)
		{
			StractPush(&a, gen);
			gen = gen->left;
		}
		else
		{
			gen = a.tail->a;
			if (gen->right != NULL && gen->right != r)
			{
				gen = gen->right;
			}
			else
			{
				StractPop(&a);//这个pop放置的位置无所谓只要是在这个else里面就行。
				if(gen->left==NULL)
				{
					gen->left = pre;
					gen->ltag = 1;
				}
				if (pre != NULL&&pre->right==NULL)
				{
					pre->rtag = 1;
					pre->right = gen;
				}
				pre = gen;
				r = gen;
				gen = NULL;//最后，把gen置为null，为了方便再次进入循环的时候再次得到栈顶元素，因为这个子树已经遍历完了。
			}
		}
	}
}


void real_mid(BiTree p)
{
	midthreaded(p);
	pre->right = NULL;
	pre->rtag = 1;
	pre = NULL;//方便下一次的使用
}
void real_ord(BiTree p)
{
	ordthreaded(p);
	//结束之后，pre等于F，让F的rtag为1，表示它有后继结点
	//再让他的right等于NULL，表示它的后继为空，也就是说他就是结尾。
	pre->right = NULL;
	pre->rtag = 1;
	//释放pre1以便下次使用。
	pre = NULL;
}
void real_fai(BiTree p)
{
	faithreaded(p);
	pre = NULL;
}

BiTree first(BiTree p)
{
	while (p->ltag == 0)
	{
		p = p->left;
	}
	return p;
	//找到这个结点的最左下方的子孙结点。while里面的条件的意思是
	//当p的ltag为0的时候，左孩子的结点就是它的左孩子。当ltag为1的时候，就代表
	//它的上一个元素，这样就会循环回去。（也不是循环回去，就是到别的地方）
	// 这个函数就是单纯的寻找p结点的最左下方的结点
	//最开始，就是寻找整个遍历过程的第一个开始结点的时候，最左下方的元素的p的ltag等于1，但是left等于NULL。
}
BiTree next(BiTree p)//这个函数就是寻找p元素下一个要遍历的元素的
{
	if (p->rtag == 1)
	{
		return p->right;
		//如果p的rtag等于1，说明它的右孩子结点存放的这个元素的后继结点；直接返回这个后继节点就行。
	}
	else
	{
		//这里为什么要放入p的right而不是p的left
		//因为当p指向现在的结点的时候，p是以一个根结点去寻找这个元素下一个子节点的，而在根结点被遍历之前，根的左孩子结点就
		//已经被遍历了，所以直接遍历右孩子结点。而且如果它是根结点，他下一个访问的结点一定不会在它的左子树里面。
		return first(p->right);
		//当这个右子树没有左边的那一部分的时候，就会直接返回p->right这个结点本身。
		//如果p的rtag等于0，说明它的右孩子结点存放的是这个元素的真正的右孩子。就要返回这个元素的右子树的最左下角的元素，
		// 就是下一个要遍历的元素。如果p的right的左子树为空，就会直接返回这个p的right，这就是他下一个最先要访问的元素
	}
}
void midrun(BiTree p)
{
	for (BiTree gen = first(p); gen != NULL; gen = next(gen))
	{
		//最开始BiTree gen = midfirst(p)找到这个元素的最开始要访问的元素
		//然后开始访问（打印，完毕之后，gen等于下一个要访问的值，直到gen等于NULL为止。
		printf("%d",gen->value);
	}
	printf("\n");
}
void ordrun(BiTree p)
{
	BiTree gen=p;
	while (gen)
	{
		printf("%d", gen->value);
		if (gen->rtag == 1)
		{
			gen = gen->right;
		}
		else if (gen->left!=NULL && gen->ltag == 0)
		{
			gen = gen->left;
		}
		else
		{
			gen = gen->right;
		}
	}
}
void fairun(BiTree p)
{	//这个判断要通过双亲结点，否则很难完成
	assert(p);
	BiTree gen = p;
	if (gen->left!=NULL||gen->right!=NULL)
	{
		if (gen->left != NULL && gen->ltag == 0)
		{
			gen = first(gen);
		}
		else
		{
			gen = gen->right;
			while ((gen->left != NULL && gen->ltag == 0) || (gen->right != NULL && gen->rtag == 0))
			{
				//当这个gen节点的左子树不为空，或者它的右子树不为空，
				// //或者两个都不为空的时候，继续这个循环。
				//当这个结点的左节点不为空的时候就访问它的左节点。
				if (gen->left != NULL && gen->ltag == 0)
				{
					gen = gen->left;
				}
				//当这个结点的有左节点为空，而它的右节点不为空的时候，访问它的右节点
				else if (gen->left == NULL && gen->right != NULL && gen->rtag == 0)
				{
					gen = gen->right;
				}
			}
		}
	}
	else
	{
		printf("%d", gen->value);
		return;
	}
	while (gen!=p)
	{
		printf("%d", gen->value);
		if (gen->rtag==1)
		{
			//如果这个元素的rtag为1，那么这个元素的right就是它的后继结点
			gen = gen->right;
		}
		else 
		{
			//否则，这个元素的后继结点就要找
			if (((gen == gen->parent->left)&&(gen->parent->right==NULL))||gen==gen->parent->right)
			{
				//如果这个元素为它的双亲结点的右子树并且它的双亲结点的右子树为空，这个结点就等是它的
				//双亲结点的右节点，那么后继结点就是这个双亲结点
				gen = gen->parent;
			}
			else if ((gen == gen->parent->left) && gen->parent->right != NULL)
			{
				//当这个元素为其双亲结点左节点而且它的双亲结点的右节点不为空的时候
				//那么这个结点的后继结点就在它的双亲结点的右子树那部分寻找
				gen = gen->parent->right;
				while ((gen->left!=NULL&&gen->ltag==0)||(gen->right!=NULL&&gen->rtag==0))
				{
					//当这个gen节点的左子树不为空，或者它的右子树不为空，
					// //或者两个都不为空的时候，继续这个循环。
					//当这个结点的左节点不为空的时候就访问它的左节点。
					if (gen->left != NULL && gen->ltag == 0)
					{
						gen = gen->left;
					}
					//当这个结点的有左节点为空，而它的右节点不为空的时候，访问它的右节点
					else if (gen->left == NULL && gen->right != NULL&&gen->rtag==0)
					{
						gen = gen->right;
					}
				}
			}
		}
	}
	printf("%d", gen->value);
}




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