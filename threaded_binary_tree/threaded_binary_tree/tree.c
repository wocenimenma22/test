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
//��ʼ�������
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

void midthreaded(BiTree p)//���������ͨ���ݹ�ķ�ʽ
{
	if (p)
	{
		
		midthreaded(p->left);
		
		//����������һ����       A
		//						/ \
		//					   B   C
		//				      / \   \
		//					 D   E   F
		//(�ʼpre=NULL��pָ��A�������pΪp1��Ȼ�������������pָ��B�������pΪp2�������p1��p2
		// ����Ϊ�����Լ������֣��ڴ����в����ڣ����������������pָ��D�������pΪp3��Ȼ�������������
		// ����D������Ϊ�գ�����D������ָ��pre��Ȼ����ltag����1����Ϊpre���ڵ���NULL�����Բ��������в���
		// ��Ȼ����pre����D����ΪD�Ѿ����������ˣ�Ȼ��ʼ����D���Һ��ӣ�����D���Һ���Ϊ�գ�������
		// Ȼ������������p3�ڵ�ѭ����)
		//������p3��ѭ��֮��pre����D��Ȼ�����ڵ�pָ��B��Ҳ����p2��ѭ��
		// B��left��D��������NULL�����Բ�ִ�ж��������ӵĲ�����Ȼ��pre����ָ�����D����������Ϊ���������Һ���Ϊ��
		// ���������������Һ���ָ���������ڱ�����Ԫ��p��p2��B��(��Ϊ��һ���������D������������ʱ����preָ��D��ʾDΪ��һ�����ʵ�Ԫ��)
		// Ȼ����preָ��B����ʼ����B���Һ��ӣ�Ȼ����pָ��E�������pΪp4����ʼ����E��㣬E��������Ϊ�գ�������E��left����B��Ҳ����pre��
		// ��Ϊpre���Һ��Ӳ�Ϊ�գ����Բ���pre��B�����в�����Ȼ����pre����E���������E���Һ��ӣ�����E���Һ���Ϊ��
		// �������ѭ����
		//��pre����E���ڣ��Ӷ�E���Һ��ӵı���������֮��pΪp4��Ȼ��������ִ��һ������ζԺ���Ҳ���Ƕ�
		// p4������ִ��Ҳ������ˣ����ԣ�����һ��ĵݹ顣��������p2��������p2ִ�е���α�����ִ��midthreaded(p->right);��һ��
		// ��ִ����һ���ͽ�����һ��ĵݹ��ˡ�Ȼ��p���ٴ�ָ��p1��һ���� ��
		//������p1��һ�㣬����pָ�����A����preָ�����E��p��left������NULL�����Բ�ִ����һ��if��������ݣ�Ȼ��preΪE��E��Ϊ��
		// ����E���Һ���Ϊ��������pre��E����left����A������pre����A��Ȼ����p1����һ��ݹ�ִ�е���midthreaded(p->right);��һ������ʼ��C����
		// ������������һ��ݹ飬p����C�������p����p5.����p5������Ϊ�գ���������������Ȼ��p5��left���ڿգ�����������leftָ��pre��A��
		// ��Ȼ��pre��A����right��Ϊ�գ����Բ��������в�����pre����C������ʼ����p5������������p����F�������p�ĵ���p6.��
		//�������p6��F������һ��ݹ飬F��������ΪNULL�����������б�����pre����������Ϊ�գ����������в�����pre����F��pre��������Ϊ��
		// ���������б���������
		//������������

		if (p->left==NULL)
		{
			p->ltag = 1;
			p->left = pre;
		}
		//�����Ԫ�ص����ӵ�Ϊ�յ�ʱ�������Ԫ�ص�ltag����1��Ȼ�����ӵ�λ�ô洢��һ�����ʵĽڵ�Ҳ����pre
		if(pre&& pre->right == NULL)
		{
			pre->rtag = 1;
			pre->right = p;
			
		}
		//��preԪ�ر���Ϊ�գ��������Һ���Ϊ�յ�ʱ����preԪ�ص�rtag����1��Ȼ���Һ��Ӻ��ӵ�λ�ô洢��һ��Ҫ���ʵĽڵ�Ҳ����p
		pre = p;//ÿ��pre��������ݸ������֮�󣬾���preָ�����ڵ�ָ��p��Ȼ���p���Һ��ӽ�����һ�β�����
		//��Ϊpreָ�����p��ǰ���һ��ָ�룬��p���ʼ��ʱ����Ѿ�������һ�Σ�����p������һ��ָ�룬��p��right������һ��ָ�롣
		midthreaded(p->right);
	}
}//�������
//���������ͨ���ݹ�ķ�ʽ
void ordthreaded(BiTree p)
{
	//(
	//����������һ����       A
	//						/ \
	//					   B   C
	//				      / \   \
	//					 D   E   F
	//�ʼ��ʱ��pָ��A�������ʱ���pΪp1��pre����NULL����ʼ����p����Ϊp�����Ӳ�Ϊ�գ����Բ������в���
	// ��ΪpreΪ�գ����Բ������в�����Ȼ����preָ��A�����A������������������ӣ�Ҳ����ltag=0��ô��pָ��B��
	// �����pΪp2���ݹ����B����һ�� )
	//������B������Ҳ��Ϊ�գ����Բ���B�����κβ���������pre��A�����Һ��Ӳ�Ϊ�գ����Բ������в�����
	// Ȼ����preָ��B�����B������������������ӣ���pָ��D�������pΪp3���ݹ���뵽D����һ�㡣Ȼ����D������Ϊ��
	// ������D�����Ӵ洢����ǰ����㣬Ҳ������������pre��B����
	// Ȼ����pre��B�����Һ��Ӳ�Ϊ�գ����Բ��������в�����     Ȼ����pre�ĵ���D��      ��ȻD�����ӽ��洢��
	// ��ΪNULL,����D��ltag=1�����Բ����������ӽ��б�����ִ��	ordthreaded(p->right);�������Ҳ�ǿյģ����Ա����
	// �ݹ��������Ҳ�ǵ�һ�������ĵݹ飩��Ȼ��ͻص�����һ��ĵݹ飬���ʱ���pΪp2Ҳ����B����ʼ����B���Һ���
	// ��p����E������һ���pΪp4����ʱ��pre����D,����E������Ϊ�գ��������������ӵ���pre��D��,Ȼ����pre���Һ���Ϊ��
	// �����������Һ��ӵ���p��Ҳ����p4��E����    Ȼ����pre����E��         �ټ���������p��E����ltag����1��
	// ���Բ����������ӽ��в�����
	// p���Һ���Ϊ�գ����Բ��������Һ��ӽ��в��������˶���p4��һ��ı�����ᡣ������һ���������
	//��������p4��һ��ı�����ʱ�򣬷��ص�p2��һ��ı�����Ȼ����p2ҲҪִ������ˣ�����������һ�����
	//�����ڵ�pָ�����p1��A�����Ѿ�ִ�е���	ordthreaded(p->right);��һ������ʼ��A�����������б�������pָ��C
	// �����pΪp5����������������Ϊ�գ�����������������ָ��pre��E����Ȼ����E��������Ϊ�գ���������������������
	// p��p5��C��,Ȼ��pre����C��Ȼ������p����F�������pΪp6���������F�ı����ĵݹ飬Ȼ����F��������Ϊ�գ�
	// �����������������ĵ���pre��C����pre����������Ϊ�գ����Բ���pre���в�����
	// Ȼ����pre����F��Ȼ����Ϊp��F����ltag����1�����Բ����������������б�����
	// ��Ϊp��������Ϊ�գ����Բ��������б�����ѭ����������
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
//���������ͨ���ݹ�ķ�ʽ
void faithreaded(BiTree p)
{
	if (p)
	{
		//����������һ����       A
		//						/ \
		//					   B   C
		//				      / \   \
		//					 D   E   F
		//(����pָ��A���������pΪp1��Ȼ��preָ�����NULL����ʼ��A�����ӵݹ飬����B��һ��ĵݹ�
		// ��ʱ����pָ��B������һ���pΪp2.Ȼ���ٴν����p�����ӣ�����D��һ��ĵݹ飬��ʱ����pָ��D��
		// ����һ���pΪp3.Ȼ����p������Ϊ�գ���������һ���ı�������ʼ��D���Һ��ӽ��б���
		// ����B���Һ���Ϊ�գ����������б�����������ִ�С�p������Ϊ�գ�����������left����pre��NULL��
		// ��ΪpreΪ�գ����Բ���pre��ʲô������Ȼ����pre����p��p3��D����Ȼ����һ������Ĵ���������
		// ������һ��ĵݹ飬��ʱ��pΪp2��B����Ȼ��ʼִ��  faithreaded(p->right);  �������
		// ��pָ��B��������������������֮����E��������������Ϊ�գ����Բ��������б���������
		// �Һ���ҲΪ�գ����Բ��������б���������Ȼ����ΪE������Ϊ�գ��������������Ӵ洢����
		// ǰ����㡣left����pre��D������Ϊpre��Ϊ�գ�����pre��������Ϊ�գ�������pre����������Ϊp
		// ��E����Ȼ����pre����p��E����������εĵݹ飬�˳���һ��ĵݹ顣p����p2��B����Ȼ��B����������Ϊ�գ�
		// ���Բ����κβ�����pre��Ϊ����pre���Һ��ӽ��Ϊ�գ����ԣ���pre���Һ��ӵ���p��E����
		// Ȼ����pre����p��B����һ��ı���������������һ�㡣p����A��p1��.��ʼ��A���Һ��ӽ��б�����
		// ������һ��ı�����p����C�������pΪp5.����p5��������Ϊ�գ����Բ���p5�����������б���
		// Ȼ����p5����������Ϊ�գ������C���������ı�������pָ��f�������pΪp6.
		// �����F�ı���������F����������������Ϊ�ա���ΪF��������Ϊ�գ�����������F��������
		// ����pre��B��Ȼ����Ϊpre���Һ��Ӳ�Ϊ�գ����Բ���������������pre����p��F��������һ�����
		// Ȼ�����ڻص�p5��һ��ĵݹ顣���е�    if (!p->left)   ��һ������������leftΪ�գ�������C��������
		// ����pre��F����pre��������Ϊ�գ�������pre������������p��C����Ȼ����pre����p��������һ��ĵݹ顣
		// �ص�p1��A������һ��ĵݹ顣����A����������Ϊ�գ����Բ����в�����Ȼ����Ϊpre��C������������Ϊ�գ�
		// ���Բ����в�������pre����A��������������)
		if(p->ltag==0)
		{
			//ֻ�е����Ԫ�������ŵĺ��ӽڵ㲻������Ԫ�ص�ʱ�򣬲��ܽ�����һ���ݹ飬����Ͳ�ִ�С�
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
		//��gen��Ϊ�յ�ʱ�����a��Ϊ�յ�ʱ�򣬽���
		//��genΪ�յ�ʱ��aҲΪ�յ�ʱ�򣬳�ȥ
		//��һ�ν����ʱ������Ϊgen������gen����NULL�ˣ�����a��Ϊ�գ������ܼ���ѭ��
		//����ʱ��gen�ֵ���NULL������a���������Ҳɾ������ˣ������˳�ѭ��
		//!IsEmpty(&a)��������һ�ν�������������Ǻ���gen=NULL��ʱ�����ܼ�����ȥ��������
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
				StractPop(&a);//���pop���õ�λ������νֻҪ�������else������С�
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
				gen = NULL;//��󣬰�gen��Ϊnull��Ϊ�˷����ٴν���ѭ����ʱ���ٴεõ�ջ��Ԫ�أ���Ϊ��������Ѿ��������ˡ�
			}
		}
	}
}


void real_mid(BiTree p)
{
	midthreaded(p);
	pre->right = NULL;
	pre->rtag = 1;
	pre = NULL;//������һ�ε�ʹ��
}
void real_ord(BiTree p)
{
	ordthreaded(p);
	//����֮��pre����F����F��rtagΪ1����ʾ���к�̽��
	//��������right����NULL����ʾ���ĺ��Ϊ�գ�Ҳ����˵�����ǽ�β��
	pre->right = NULL;
	pre->rtag = 1;
	//�ͷ�pre1�Ա��´�ʹ�á�
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
	//�ҵ�������������·��������㡣while�������������˼��
	//��p��ltagΪ0��ʱ�����ӵĽ������������ӡ���ltagΪ1��ʱ�򣬾ʹ���
	//������һ��Ԫ�أ������ͻ�ѭ����ȥ����Ҳ����ѭ����ȥ�����ǵ���ĵط���
	// ����������ǵ�����Ѱ��p���������·��Ľ��
	//�ʼ������Ѱ�������������̵ĵ�һ����ʼ����ʱ�������·���Ԫ�ص�p��ltag����1������left����NULL��
}
BiTree next(BiTree p)//�����������Ѱ��pԪ����һ��Ҫ������Ԫ�ص�
{
	if (p->rtag == 1)
	{
		return p->right;
		//���p��rtag����1��˵�������Һ��ӽ���ŵ����Ԫ�صĺ�̽�㣻ֱ�ӷ��������̽ڵ���С�
	}
	else
	{
		//����ΪʲôҪ����p��right������p��left
		//��Ϊ��pָ�����ڵĽ���ʱ��p����һ�������ȥѰ�����Ԫ����һ���ӽڵ�ģ����ڸ���㱻����֮ǰ���������ӽ���
		//�Ѿ��������ˣ�����ֱ�ӱ����Һ��ӽ�㡣����������Ǹ���㣬����һ�����ʵĽ��һ���������������������档
		return first(p->right);
		//�����������û����ߵ���һ���ֵ�ʱ�򣬾ͻ�ֱ�ӷ���p->right�����㱾��
		//���p��rtag����0��˵�������Һ��ӽ���ŵ������Ԫ�ص��������Һ��ӡ���Ҫ�������Ԫ�ص��������������½ǵ�Ԫ�أ�
		// ������һ��Ҫ������Ԫ�ء����p��right��������Ϊ�գ��ͻ�ֱ�ӷ������p��right�����������һ������Ҫ���ʵ�Ԫ��
	}
}
void midrun(BiTree p)
{
	for (BiTree gen = first(p); gen != NULL; gen = next(gen))
	{
		//�ʼBiTree gen = midfirst(p)�ҵ����Ԫ�ص��ʼҪ���ʵ�Ԫ��
		//Ȼ��ʼ���ʣ���ӡ�����֮��gen������һ��Ҫ���ʵ�ֵ��ֱ��gen����NULLΪֹ��
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
{	//����ж�Ҫͨ��˫�׽�㣬����������
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
				//�����gen�ڵ����������Ϊ�գ�����������������Ϊ�գ�
				// //������������Ϊ�յ�ʱ�򣬼������ѭ����
				//�����������ڵ㲻Ϊ�յ�ʱ��ͷ���������ڵ㡣
				if (gen->left != NULL && gen->ltag == 0)
				{
					gen = gen->left;
				}
				//�������������ڵ�Ϊ�գ��������ҽڵ㲻Ϊ�յ�ʱ�򣬷��������ҽڵ�
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
			//������Ԫ�ص�rtagΪ1����ô���Ԫ�ص�right�������ĺ�̽��
			gen = gen->right;
		}
		else 
		{
			//�������Ԫ�صĺ�̽���Ҫ��
			if (((gen == gen->parent->left)&&(gen->parent->right==NULL))||gen==gen->parent->right)
			{
				//������Ԫ��Ϊ����˫�׽�����������������˫�׽���������Ϊ�գ�������͵�������
				//˫�׽����ҽڵ㣬��ô��̽��������˫�׽��
				gen = gen->parent;
			}
			else if ((gen == gen->parent->left) && gen->parent->right != NULL)
			{
				//�����Ԫ��Ϊ��˫�׽����ڵ��������˫�׽����ҽڵ㲻Ϊ�յ�ʱ��
				//��ô������ĺ�̽���������˫�׽����������ǲ���Ѱ��
				gen = gen->parent->right;
				while ((gen->left!=NULL&&gen->ltag==0)||(gen->right!=NULL&&gen->rtag==0))
				{
					//�����gen�ڵ����������Ϊ�գ�����������������Ϊ�գ�
					// //������������Ϊ�յ�ʱ�򣬼������ѭ����
					//�����������ڵ㲻Ϊ�յ�ʱ��ͷ���������ڵ㡣
					if (gen->left != NULL && gen->ltag == 0)
					{
						gen = gen->left;
					}
					//�������������ڵ�Ϊ�գ��������ҽڵ㲻Ϊ�յ�ʱ�򣬷��������ҽڵ�
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