#include"momo.h"
void inittree(BiTree gen)
{
	gen->left = NULL;
	gen->right = NULL;
	gen->parent = NULL;
	gen->value = 'A';
}
//��ʼ�������
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
//�����µ�Ԫ��
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
//�������
int treedeep(BiTree gen)
{
	if (gen == NULL)
	{
		return 0;
	}
	int l = treedeep(gen->left) + 1;
	//����������ݹ鵽���һλ��ʱ�򣬷���0
	int r = treedeep(gen->right) + 1;
	//�ݹ��㷨���þ�û��ʹ���ˡ���������һ��
	if (l > r)
	{
		return l;
	}
	else
	{
		return r;
	}
}
//�����������
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
//�������
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
//��������
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
		//new��Ȼ��һ����ַ�����ǲ���head�ĵ�ַ������head�����ַ����洢�ĵ�ַ
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
//�������
void noMidOrder(BiTree gen)
{
	//һֱѭ����������
	//��������Ĺ��̣���һֱ��������������������һ����ջһ���������������Ϊ�յ�ʱ�򣬵������ʲ�ɾ��ջ�е�ջ��Ԫ��
	//��ָ��ָ�����Ԫ�أ�Ȼ��������Ԫ�ص��Һ��ӣ������û���Һ��ӣ��������ʲ�ɾ��ջ�����ڵ�ջ��Ԫ�ء������ջ��Ԫ��ִ��ͬ���Ĳ���
	// ��������Һ�����������ô�ظ��ʼ�Ĳ�����������������Һ��ӣ������û���Һ���
	//��������Ԫ��Ϊ�գ���ô����ջ�е���һ��Ԫ��,���ڷ��������Ԫ��֮����ָ��pָ�����Ԫ�ص��Һ��ӣ�
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
			p = a.tail->a;//����ջֻ��β��βɾ������Ҫ��������β��
			StractPop(&a);
			printf("%c", p->value);
			p = p->right;
		}
		//Ҫ�㣺��������Ԫ��Ϊ�գ���ô����ջ�е���һ��Ԫ��,���ڷ��������Ԫ��֮�󣨷��������˼���ǣ���ӡ�����Ԫ�ص�ֵ����
		// ��ָ��pָ�����Ԫ�ص��Һ��ӣ�
		//����Ԫ�ز�Ϊ�յ�ʱ���һֱ�����������Ӿ���

		//��Ϊ��������������������ʵ���ײ�Ԫ�ص�ʱ�򣬷�����������Ϊ�գ�Ȼ���ڷ��������Һ���֮ǰ����ӡ��
		//�������Һ��ӻ��ڷ��ʵ������Һ��ӵ�����Ϊ�յ�ʱ���ӡ��Ȼ���ٷ��������Һ��ӵ��Һ���Ϊ�գ��͵���ջ�е�һ��Ԫ��

		//���ʵ�����Ϊ�յ�ʱ��else��Ϊ�˵���ջ�е�Ԫ�أ�Ȼ����������Һ��ӵ�
		//���ʵ��Һ���Ϊ�յ�ʱ��else�������ϵ���һ��Ԫ�أ���ʼ���ʱ��
		//����������һ����       A
		//						/ \
		//					   B   C
		//				      / \   \
		//					 D   E   F
		//�����ʵ�D������Ϊ�յ�ʱ�򣬵�����Ϊ�˷���D��Ȼ���ӡD��
		//�����ʵ�D���Һ���Ϊ�յ�ʱ�򣬵�����Ϊ�˷���B��Ȼ���ӡB��
		//Ȼ���ٷ���B���Һ��ӣ�����ΪE���ٷ���E�����ӣ�����Ϊ�գ�����E��Ȼ���ӡE
		//�����ʵ�E���Һ���Ϊ�յ�ʱ�򣬵�����Ϊ�˷���A��Ȼ���ӡA

	}
}
//����Ҫ�ݹ���������
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
			//����ʹ�ӡ����ΪҪ�����ӵ��Ŀ϶�����ÿ�����ĸ��ڵ㡣
			//������ʱ���ֱ�Ӱ�����ӡ�ˣ��������������������ڴ�ӡ��ʱ��ͬ��������������˳������ͬ��
			p = p->left;
		}
		else
		{
			p = a.tail->a;//����ջֻ��β��βɾ������Ҫ��������β��
			StractPop(&a);

			p = p->right;
		}
	}
}
//����Ҫ�ݹ���������
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
		else//��������������Ϊ�գ�������������������Һ���
		{
			p = a.tail->a;//����ջֻ��β��βɾ������Ҫ��������β��
			if (p->right && p->right != r)//�����Ԫ�ص����Ӳ�Ϊ�������Ԫ�ص�����û�б���������ʱ��
			{
				p = p->right;//��ָ��ָ����������Һ���
				StractPush(&a, p);//Ȼ��������Һ�����ջ
				p = p->left;//��ʼ��ָ��ָ������½�������Ȼ��ʼ����
			}
			else //�����������Һ���Ϊ�գ����������Һ��ӱ����ʵ���
			{
				//���ʱ�����Һ��Ӷ�Ϊ�գ����Һ��Ӷ������ˣ��Ǿ�Ҫ��ӡ���Ԫ����
				printf("%c", p->value);
				i++;
				StractPop(&a);
				//��ӡ�����ݲ�ɾ�����Ԫ��
				//Ȼ����r����p����ʾ�ոձ�����p������
				r = p;
				//��Ϊ�Ѿ���ӡ�ˣ����Ա�ʾ�����ˡ�
				p = NULL;
				//��p=null��Ϊ���ٽ���������ڣ�Ȼ�󵯳���һ��ջ���е�Ԫ�ء�
			}
			//����������һ����       A
			//						/ \
			//					   B   C
			//				      / \   \
			//					 D   E   F
			//����A��ջ,����A�����ӣ�Ȼ��B��ջ��Ȼ�����B�����ӣ�Ȼ��D��ջ��Ȼ�����D������
			//����D������Ϊ�գ���ʱ��ָ��pָ���ΪNULL�����Դ�ʱ��ʼִ�е�һ��else����������ݣ�
			//��p����ջ����Ԫ��D�����D���Һ��Ӵ��ڣ���ô������������D���Һ��Ӳ����ڣ�����ִ�еڶ���else
			//��������ݣ���ӡD��ֵ��Ȼ���ջ��ɾ��D������r=D������ոշ��ʵ�Ԫ����D��p=NULL��������
			// ִ�е�ʱ��ͻ����ջ��Ԫ�ص�B����Ȼ����B���Һ���ΪE����pָ��E,��E��ջ��E��ջ֮����
			// pָ��E�����ӣ�����p����NULL��Ȼ����ѭ����ʱ�򣬾ͻ�����һ��else���ͻ��ٴ���pָ��E
			// ָ��E֮�󣬷���E���Һ���ҲΪ�գ��ͽ���ڶ���else��ɾ��ջ��Ԫ��E����ӡ���Ԫ�ص�ֵ
			// Ȼ��r=E����ʾ���ʹ����Ԫ�أ�p=NULL��Ȼ������ٴν���ѭ����ʱ�򣬾ͻ�����һ��else
			// Ȼ����p����ջ����Ԫ��B����p����Ԫ��B֮����Ϊr=E�������Ѿ�������B���Һ����ˣ��ٴν�
			//��ڶ���else��ɾ�����ջ��Ԫ�أ���ӡ���Ԫ��B��ֵ��Ȼ��r=B��p=NULL��Ȼ����ѭ����ʱ�����
			// ��һ��else��pָ��A��pָ��A֮�󣬽���ڶ���if��C��ջ������Cû�����ӣ��Ϳ�ʼ����C���Һ���
			//����Fû�����ӣ���ʼ����F���Һ��ӣ�Ҳû�У��ʹ�ӡF��ֵ��r=FȻ��pָ��NULL�������ٳ�����ʱ��
			// �ٽ���else��pָ��C��C֮�󣬷���F�Ѿ����������ˣ���ӡɾ����r=C��p=NULL��ʣ�µĹ���ͬ�ϡ�
		}
	}
	printf("\n%d\n", i);
}
//����Ҫ�ݹ�ĺ������
// 
// 
//���еĻ�������
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
void QueuePush(Queue* pq, QDataType x)//�������������
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
//���еĻ�������

void Initializes(Stracts* pa)
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void StractPush(Stracts* pa, BiTree gen)//ջֻ��β��βɾ
{
	assert(pa);
	if (IsFull(pa) == true)
	{
		printf("�޷�����\n");
		return;
	}
	Stract* newnode = (Stract*)malloc(sizeof(Stract));//����һ���µ��ڴ�ռ�Ϊ�µ�Ԫ��
	newnode->a = gen;//��Ԫ�ش洢�����ݵ����ݵ���x
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

BiTree StractFind(Stracts* pa, int x)
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
		//new��Ȼ��һ����ַ�����ǲ���head�ĵ�ַ������head�����ַ����洢�ĵ�ַ
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
	//�����front��¼����������һ������һ��Ԫ���������е��±�λ��
	//rear��������ָ���Ԫ���������е��±��λ��
	//lastָ����������һ��ĵ����һ��Ԫ�ص��±�ĵ�λ��
	//level�ǲ���
	//��������һ��������
	BiTree Q[100];
	//����������һ����       A
	//						/ \
	//					   B   E
	//				      / \   \
	//					 C   D   F
	//front�ʼ��-1��Ȼ��rear��-1.last��level����0
	//��Q�ĵڣ�rear+1=��0��Ԫ�ص��ڶ������ĸ��ڵ�A��
	//Ȼ����front�����ڵ�rearС�����Ծ���p����Q�ĵڣ�rear+1��=0��Ԫ��A
	//Ȼ����Ϊp���Ӳ�Ϊ�գ���Q�ĵڣ�rear+1��=1��Ԫ�ص���p������
	//�Һ���ͬ��
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
		//�����ڵ�front����last��ʱ�򣬾���last�������ڵ�rear����Ϊrear����һ��Ԫ�ص����һ�����
		//front�Ǹռ�������Һ����Ƿ�Ϊ�գ��Լ��������Ԫ�ص��±꣬���ԣ����������last��ʱ��
		//�ʹ������һ���Ԫ�ؼ������
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
		//new��Ȼ��һ����ַ�����ǲ���head�ĵ�ַ������head�����ַ����洢�ĵ�ַ
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
	//�����pre��mid���ַ������ȿ϶���һ���ģ��������ifֻ��Ҫ�ж�pre����mid�е�һ��
	//��preֻ��һ���ַ���ʱ�򣬴�������ַ�����ʣ�µ�Ψһ�Ľ�㡣ֱ�Ӱ�������뵽p��ȥ���С�
	if (pre[1] == '\0' && pre[0] != NULL)
	{
		morebranch(p, pre[0]);
	}
	//���򣬵������Ϊ�ն�������ֹ��һ���ַ���ʱ�򣬾ͻ��ܲ�
	else if(pre[0]!='\0'&&mid[0]!='\0')
	{	
		char* a = mid;
		//�Ȱ�mid�ĵ�ַ��a��������a���в����Ͳ���Ӱ��mid��ֵ��
		while (*a != pre[0])
		{
			a++;
			//�ҵ�ͷ�ڵ�����������ַ����е�λ��
		}
		if(yesorno==1)
		{
			//���ڵ�û�취ֱ�Ӳ��룬�������������������Ǹ�����ֱ���޸�gen��ֵ��
			//Ȼ����һ������0���������Ϊ0��ʱ�򣬴����ǵ�һ�ν�������ݹ飬
			//��Ϊ���ڵ�����ֵ������ֱ����������������һ����Ȼ��������ֵ��Ϊ1
			//����ÿһ������1����Ҫ�������ֵ��
			if(abc==1)
			{
				morebranch(p, pre[0]);
				//�����ͷ�ڵ�����ȥ������Ҫע�������ɺ��ǽ������������ǽ���������
				//���Ե�������һ������abc��ȷ���ǽ�������������������
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
		//��������Ҫ��Ԫ��
		char leftmid[10];
		//Ӧ�ÿ���ʹ��malloc���ڴ�ռ�����Ż�
		//�洢��������ĸ��ڵ����ߵ��ַ���
		leftmid[0] = '\0';
		char rightmid[10];
		//�洢��������ĸ��ڵ���ұߵ��ַ���
		rightmid[0] = '\0';
		//��foright�Ӹ�������һ��������
		char* foright = a + 1;
		char* mid2 = mid;
		//����һ����midһ����Ԫ�أ����ڽ�����һ������
		int i = 0;
		int j = 0;
		while (*mid2 != *a)
		{
			//������������ַ������ʼ����ѭ��
			//�õ����ڵ�֮ǰ�������ַ���
			leftmid[i] = *mid2;
			mid2++;
			i++;
		}
		leftmid[i] = '\0';
		while (*foright != '\0')
		{
			//�õ����������������еĸ��ڵ�֮����ַ���
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
		//���������ַ������±������
		int prei = 0;
		int prej = 0;
		if (leftmid[0] != NULL)
		{
			while (*pre2 !=NULL)//��pre2ʱ��������leftmid����
				//Ѱ���Ƿ���ƥ����ַ���������У��ͼ��������û�þͿ�ʼ�˳�
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
				//����һ���ַ����Ľ�β��ʼ
				rightpre[prej] = *(pre2+1);
				prej++;
				pre2++;
			}
			rightpre[prej] = '\0';
		}
		if (leftmid[0] != NULL)
		{
			//�������ַ���������������ַ����ĸ��ڵ��������ַ�����Ϊ��
			//��ʾ���Ԫ�ش������������ٴν��������������������ַ����ĸ��ڵ���뵽�������Ӵ�
			//����pָ��������ӣ�������ʼ����
			zhangdatou(&leftpre, &leftmid,p,yesorno,1);
		}
		else
		{
			//���������ܲ������ӣ�Ϊ�˱�֤�Һ����������룬���ﴫ��NULL��p������
			//������������p�����ӵ�ֵ����NULL��Ҳ����'\0'�������ӵĵ�ַ����NULL��������ӵĵ�ַ����
			//NULL����ô��һ�����ǻ���뵽p���������档Ȼ�󣬽�����������֮��ͨ���������
			//�����еġ�\0����ֵ�ĵ�ַת��ΪNULL
			morebranch(p, NULL);
		}
		if (rightmid[0] != NULL)
		{
			//������Һ��Ӳ�Ϊ�գ��ǾͲ����Һ���
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
