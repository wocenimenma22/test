#include"tree.h"
void inittree(BiTree gen)
{
	gen->left = NULL;
	gen->right = NULL;
	gen->parent = NULL;
	gen->value = 0;
}
//��ʼ�������
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
//�����µ�Ԫ��
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
//�������
int treedeep(BiTree gen)
{
	if (gen == NULL)
	{
		return 0;
	}
	int l = treedeep(gen->left)+1;
	//����������ݹ鵽���һλ��ʱ�򣬷���0
	int r = treedeep(gen->right)+1;
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
		printf("%d", gen->value);
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
		printf("%d", gen->value);
	}
}
//��������
void level_order(BiTree gen)	
{
	Queue c;
	QueueInit(&c);
	QueuePush(&c, gen);
	BiTree new=NULL;
	while (!QueueEmpty(&c))
	{
		new = QueueFront(&c);
		//new��Ȼ��һ����ַ�����ǲ���head�ĵ�ַ������head�����ַ����洢�ĵ�ַ
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
	while (p||!IsEmpty(&a))
	{
		if(p!=NULL)
		{
			StractPush(&a, p);
			p = p->left;
		}
		else
		{
			p = a.tail->a;//����ջֻ��β��βɾ������Ҫ��������β��
			StractPop(&a);
			printf("%d",p->value);
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
			printf("%d", p->value);
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
		else//��������������Ϊ�գ�������������������Һ���
		{
			p = a.tail->a;//����ջֻ��β��βɾ������Ҫ��������β��
			if(p->right&&p->right!=r)//�����Ԫ�ص����Ӳ�Ϊ�������Ԫ�ص�����û�б���������ʱ��
			{
				p = p->right;//��ָ��ָ����������Һ���
				StractPush(&a, p);//Ȼ��������Һ�����ջ
				p = p->left;//��ʼ��ָ��ָ������½�������Ȼ��ʼ����
			}
			else //�����������Һ���Ϊ�գ����������Һ��ӱ����ʵ���
			{
				//���ʱ�����Һ��Ӷ�Ϊ�գ����Һ��Ӷ������ˣ��Ǿ�Ҫ��ӡ���Ԫ����
				printf("%d", p->value);
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
	//�����front��¼����������һ������һ��Ԫ���������е��±�λ��
	//rear���������������������Ԫ�ص��±��λ��
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
	while (front < rear)//��rear��ͷ֮��rear���������ˣ�֪��front���ӵ�rear�Ĵ�С������ѭ��
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
		//Ϊʲôrearָ�������һ��Ԫ�ص����һ����㣬��Ϊ����һ��ĵ������֮��Q�ڵ�Ԫ���ܹ�����һ�����һ��
		// Ϊʲôfront�ǵ�ǰ��Ԫ�ص����һ�����
		// ÿ�ζ�����last����rear����������һ���ѭ����ʼ��ʱ��last��rear����һ���ģ�lastָ����һ���Ԫ�ص����һ��
		// rear����һ���Ԫ�ر�����ȫ��ʱ�򣬸պ�ָ����һ���Ԫ�ص����һ����
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

//����ÿյĽ��Ҳ���ȥ֮����ô����ʼ�е�һ��ΪNULL�Ľ���
//����ֻҪ��һ����Ϊ�յĽ�㣬��ô������Ͳ�����ȫ������
//��ȫ�����������еĽ���λ�ú�����������λ����ͬ��
//����
//����������һ����        A
//						/   \
//					   B     C
//				      / \   / \
//					 D   E ��  F
//�����Ĳ��������ȫ�����������һ��������������һ�ŵ����һ����㣬������֮��
//��ȫ�������ĿյĽ��֮��ȫ��Ϊ��
//����������һ����        A
//						/   \
//					   B     C
//				      / \   / \
//					 D   E F  ��
//��ô����պ�������е�Ԫ�صĶ���DEF���ӽ�㣬���ǿ�
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
		//new��Ȼ��һ����ַ�����ǲ���head�ĵ�ַ������head�����ַ����洢�ĵ�ַ
		//�������������ӵ��ڿգ�Ҫô�������Һ���ҲΪ�գ�Ȼ����i����2��ʣ�µ����н�����else if���ж�
		//Ҫô�������Һ��Ӳ�Ϊ�գ���ô���������������ȫ����������������
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
				printf("����");
				return;
			}
			else
			{
				i++;
			}
		}
		//������Ǹ������������Ӷ�ΪNULL����ô��������е�Ԫ�ؿ϶���ΪҶ�ӽ��
		//�������Ҷ�ӽ�㣬��ô������Ͳ�����ȫ��������
		else if (new != NULL && i > 2)
		{
			if (new->left != NULL)
			{
				printf("����");
			}
			if (new->right != NULL)
			{
				printf("����");
			}
		}
		QueuePop(&c);
	}
	printf("��");
}

BiTree PreInCreat(int A[], int B[], int l1, int h1, int l2, int h2)
{
	//11.h1 Ϊ����ĵ�һ�����������꣬12��h2 Ϊ����ĵ�һ�����һ������±�
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
	root->value = A[l1];
	int i;//i�Ǹ��ڵ�����λ�õ��±ꡣ
	int llen;//�������ĳ���
	int rlen;//�������ĳ���
	for (i = l2; B[i] != root->value; i++);
	llen = i - l2;//llen���ڸ��������λ�õ��±꣬��ȥ��ʼλ�õ��±ꡣ
	//Ҳ���Ǹ��ڵ�֮ǰ��Ԫ�ظ���
	rlen = h2 - i;//rlen�͵��ڽ���λ�õ��±��ȥ���ڵ�����λ�õ��±ꡣ
	//Ҳ���Ǹ��ڵ�֮���Ԫ�صĸ�����
	if (llen)
	{
		root->left = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
		//l1+1��ԭ���ǣ�ǰ�����������ĵ�һ������Ҳ�������ڱ���������ĸ���㣩
		// �Ѿ������ȥ�ˡ����ڵ��������Ŀ�ʼ�Ľ��Ӧ���Ǹ����֮��ĵ�һ����㡣Ҳ����l1+1��
		//l1+llen������������������λ�á���Ϊllen���������ĳ��ȡ�
		//l2��ʾ��������Ŀ�ʼ�Ľ��û�н��롣
		//l2+llen-1��ָ����ǡ���������еĸ��ڵ�ǰ���Ǹ�λ�õ�Ԫ���±ꡣ
	}
	else
	{
		root->left = NULL;
	}
	if (rlen)
	{
		root->right = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
		//��h1-rlen+1��ʾ���ǣ�ǰ�����������Ľ�βԪ�ص��±��ȥ�������ĳ����ټ�һ��ָ�����
		// ǰ�����֮�У�ָ����ڵ�֮��ĵ�һ��Ԫ�ص��±�
		// h1ָ�����ǰ���������Ľ�β���Ǹ�Ԫ�ص��±�
		// h2-rlen+1ָ�������������еģ����ڵ�֮��ĵ�һ��Ԫ�ص��±�
		// h2ָ�������������е�������������һ��������±꣩
	}
	else
	{
		root->right = NULL;
	}
	//���������������ǰ�������
	// ���������������    ��    ������
	// �ڱ����Ĺ����У�����ʼ�������������Ҳ���Ǵ��м俪ʼ���١�
	// ǰ�����  ��     ������   ������
	// �ڱ����Ĺ����У�����ʼ�������������Ҳ���Ǵ�����߿�ʼ���١�
	// ���Կ�������������������ģ��������ĳ��ȼ�1����Ԫ��֮��Ͷ�����������Ԫ�أ�
	//�����������ı������棬���Ǽ�������h1��h2��
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
		//new��Ȼ��һ����ַ�����ǲ���head�ĵ�ַ������head�����ַ����洢�ĵ�ַ
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
//�鿴����������ж��ٸ���Ϊ2�Ľ��

void blevel_order(BiTree gen)
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
//������������������еĽ������ҽ��

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

//�����������k�����֮��ֹͣ�������������k��ֵ

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
//�ҵ�ֵΪx�Ľ�㣬ɾ������Ϊ�������������ͷ����е��ӽ��Ŀռ�

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
//�ͷ���genΪ���ڵ�����Ŀռ�

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
//�ҵ�ֵΪx�Ľ�����������

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
				printf("��������������������Ƚڵ�Ϊ%d,�洢������Ϊ%d", arr1[i], new->value);
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
//�ҵ�������㹲ͬ������

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
//�ҵ�һ�������������ȵĵ�ַ���������ǰ�˳����뵽arr��ȥ

void longest(BiTree gen)
{
	
	if (!gen)
	{
		return;
	}
	int front = -1, rear = -1, last = 0, width = 0;
	int max = 0;
	//�����front��¼����������һ������һ��Ԫ���������е��±�λ��
	//rear���������������������Ԫ�ص��±��λ��
	//lastָ����������һ��ĵ����һ��Ԫ�ص��±�ĵ�λ��
	//level�ǲ���
	//��������һ��������
	BiTree Q[100];
	Q[++rear] = gen;
	BiTree p;
	while (front<rear)
	{
		p = Q[++front];//����Ҫ��++front����Ȼ������
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
//�����������������һ��ĳ���


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
//��һ������������ǰ������ת��Ϊ��������
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
//��һ������������ǰ������ת��Ϊ��������2
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
