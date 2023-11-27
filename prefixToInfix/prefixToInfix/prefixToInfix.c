#include"prefixToInfix.h"
void Initializes(Stracts* pa)//��ʼ��ջ
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void StractPush(Stracts* pa, stractdata x)//ջֻ��β��βɾ
{
	assert(pa);

	Stract* newnode = (Stract*)malloc(sizeof(Stract));
	newnode->a = x;
	newnode->next = NULL;
	if (pa->head == NULL)
	{
		//printf("3");
		pa->head = pa->tail = newnode;
		pa->head->next = pa->tail;
		pa->tail->prev = pa->head;
	}
	else
	{
		newnode->prev = pa->tail;
		pa->tail->next = newnode;
		pa->tail = newnode;
	}
}

void StractPop(Stracts* pa)//ɾ����ԭ����ɾ����ȱ�ݣ���ջ��ֻʣ�����һ��Ԫ�ص�ʱ���޷�ɾ����
//���Ѹ���
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

void intInitializes(intStracts* pa)
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void intStractPush(intStracts* pa, intstractdata x)//ջֻ��β��βɾ
{
	assert(pa);
	intStract* newnode = (intStract*)malloc(sizeof(intStract));
	newnode->a = x;
	newnode->next = NULL;
	if (pa->head == NULL)
	{
		//printf("3");
		pa->head = pa->tail = newnode;
		pa->head->next = pa->tail;
		pa->tail->prev = pa->head;
	}
	else
	{
		newnode->prev = pa->tail;
		pa->tail->next = newnode;
		pa->tail = newnode;
	}
}

void intStractPop(intStracts* pa)
{
	if (intIsEmpty(pa) == 1)
	{
		printf("ջ�ڿռ�Ϊ�����ڣ�����ɾ��");
		return;
	}
	if (pa->head != pa->tail)
	{
		intStract* pop = pa->tail;
		intStract* prev = pa->tail->prev;
		prev->next = NULL;
		pa->tail = prev;
		free(pop);
	}
	else
	{
		intStract* pop = pa->tail;
		free(pop);
		pa->head = pa->tail = NULL;
	}

}

bool intIsEmpty(intStracts* pa)
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

void change(char* middle, char* last)//����׺���ʽת��Ϊ��׺���ʽ
{
	Stracts a;
	//�����a���������������ŵ�ջ
	Initializes(&a);
	int i = 0;
	int j = 0;
	while (middle[i]!='\0'&&i<100)
	{
		//������ַ�����Ԫ�ػ�û�е��õ����һλ�ͼ���ѭ����
		switch (middle[i])
		{
			//����Ĳ�����+-*/^���ʶ���ࡣ���Ծ͵�һ��+��д����ϸ��ע��
		case '+':
			if (IsEmpty(&a)==1)
			{//��ջΪ�յ�ʱ��ֱ����ջ�����ù�ǰ���Ԫ����ʲô��
				StractPush(&a, '+');
				i++;
				break;
			}
			else
			{
				while (a.tail->a == '+' || a.tail->a == '-' || a.tail->a == '*' || a.tail->a == '/' || a.tail->a == '^')
				{
					//�����Ԫ����ջ֮�����ǰ���Ԫ�ص�����ȼ������߻��ߵ�����������ȼ�����ô�Ͱѱ����ߵĺ�������ͬ���뵽�ַ������档
					//�ٰ����Ԫ����ջ��
					char ch = a.tail->a;
					StractPop(&a);
					last[j] = ch;
					j++;	
					if (IsEmpty(&a) == 1)
					{
						break;
					}
				}
				//��ѭ������֮���ٰ����������Ų��뵽���ջ����ȥ
				StractPush(&a, '+');
				i++;
				//���i++ֻҪ��һ�ξ��У���if (IsEmpty(&a) == 1)�������������ط�����������if (IsEmpty(&a) == 1)����i++һ��
				//����ͻ��i++һ�Σ���������i++ÿ�ζ���ִ��һ�Ρ�
				break;
			}
			//�������Щ�������������������ơ�
		case '-':
			if (IsEmpty(&a) == 1)
			{
				StractPush(&a, '-');
				i++;
				break;
			}
			else
			{
				while (a.tail->a == '+' || a.tail->a == '-' || a.tail->a == '*' || a.tail->a == '/' || a.tail->a == '^')
				{
					char ch = a.tail->a;
					StractPop(&a);
					last[j] = ch;
					j++;
					if (IsEmpty(&a) == 1)
					{
						break;
					}
				}
				StractPush(&a, '-');
				i++;
				//���i++ֻҪ��һ�ξ��У���if (IsEmpty(&a) == 1)�������������ط�����������if (IsEmpty(&a) == 1)����i++һ��
				//����ͻ��i++һ�Σ���������i++ÿ�ζ���ִ��һ�Ρ�
				break;
			}
		case '/':
			if (IsEmpty(&a) == 1)
			{
				StractPush(&a, '/');
				i++;
				break;
			}
			else
			{
				while ( a.tail->a == '*' || a.tail->a == '/' || a.tail->a == '^')
				{
					char ch = a.tail->a;
					StractPop(&a);
					last[j] = ch;
					j++;
					if (IsEmpty(&a)==1)
					{
						break;
					}
				}
				StractPush(&a, '/');
				i++;
				//���i++ֻҪ��һ�ξ��У���if (IsEmpty(&a) == 1)�������������ط�����������if (IsEmpty(&a) == 1)����i++һ��
				//����ͻ��i++һ�Σ���������i++ÿ�ζ���ִ��һ�Ρ�
				break;
			}
		case '*':
			if (IsEmpty(&a) == 1)
			{
				StractPush(&a, '*');
				i++;
				break;
			}
			else
			{
				while (a.tail->a == '*' || a.tail->a == '/' || a.tail->a == '^')
				{
					char ch = a.tail->a;
					StractPop(&a);	
					last[j] = ch;
					j++;
					if (IsEmpty(&a) == 1)
					{
						break;
					}
				}
				StractPush(&a, '*');
				i++;
				//���i++ֻҪ��һ�ξ��У���if (IsEmpty(&a) == 1)�������������ط�����������if (IsEmpty(&a) == 1)����i++һ��
				//����ͻ��i++һ�Σ���������i++ÿ�ζ���ִ��һ�Ρ�
				break;
			}
		case '^':
			if (IsEmpty(&a) == 1)
			{
				StractPush(&a, '^');
				i++;
				break;
			}
			else
			{
				while (a.tail->a == '^')
				{
					char ch = a.tail->a;
					StractPop(&a);
					last[j] = ch;
					j++;
					if (IsEmpty(&a) == 1)
					{
						break;
					}
				}
				StractPush(&a, '^');
				i++;
				//���i++ֻҪ��һ�ξ��У���if (IsEmpty(&a) == 1)�������������ط�����������if (IsEmpty(&a) == 1)����i++һ��
				//����ͻ��i++һ�Σ���������i++ÿ�ζ���ִ��һ�Ρ�
				break;
			}
		case '(':
				StractPush(&a, '(');
				i++;
				break;
		case ')':
			while (a.tail->a != '(')
			{
				char ch = a.tail->a;
				StractPop(&a);
				last[j] = ch;
				j++;
				if (IsEmpty(&a) == 1)
				{
					break;
				}
			}
			StractPop(&a);
			i++;
			//���i++ֻҪ��һ�ξ��У���if (IsEmpty(&a) == 1)�������������ط�����������if (IsEmpty(&a) == 1)����i++һ��
				//����ͻ��i++һ�Σ���������i++ÿ�ζ���ִ��һ�Ρ�
			break;
		default:
			while((middle[i]>='0')&&(middle[i]<='9'))
			{
				last[j] = middle[i];
				i++;
				j++;
				//�������ѭ�������Խ�������Ԫ���ǵ�λ�����Ƕ�λ�������⡣
			}
			//�����һ���ո������ϱȽϺÿ�
			last[j] = ' ';
			j++;
			break;
		}
	
	}
	//��middle�ַ����Ѿ�����������ˣ��Ϳ��԰�ջ�����е�Ԫ�ض���ȡ������
	while (IsEmpty(&a) == 0)
	{
		if (a.tail->a != '(')
		{
			last[j] = a.tail->a;
			StractPop(&a);
			j++;
		}
		//�������if esle����Ϊ�˵��Ǹ������ֵ�ʱ�򣬲������Ԫ�أ������룬���ǻ�Ҫ��֤�����ų�ջ
		else
		{
			StractPop(&a);
		}
		/*last[j] = a.tail->a;
		StractPop(&a);
		j++;*/
	}
	last[j] = '\0';
}

bool IsEmpty(Stracts* pa)//����Ƿ�Ϊ��
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

int char_to_int(char* last)
{
	int i = 0;
	int num = 0;
	int sign = 1;//����������
	if (last[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (last[i] != '\0')
	{
		num = num * 10 + (last[i] - '0');
		i++;
	}
	return num * sign;
}

int caculate(char* last)
{
	intStracts a;
	//�����a���������������ŵ�ջ
	intInitializes(&a);
	int i = 0;
	char timefu[10];
	int j = 0;
	while (last[i] != '\0')
	{
	loop:
		while (last[i] >= '0' && last[i] <= '9')
		{
			timefu[j] = last[i];
			j++;
			i++;
		}
		timefu[j] = '\0';
		int number = char_to_int(timefu);
		j = 0;
		intStractPush(&a, number);
		i++;
		if (last[i] >= '0' && last[i] <= '9')
		{
			goto loop;
		}
		while (last[i] == '+' ||last[i] == '-' || last[i] == '/' || last[i] == '*' || last[i] == '^')
		{
			int number1 = a.tail->a;
			intStractPop(&a);
			int number2 = a.tail->a;
			intStractPop(&a);
			int newnumber = 0;
			switch (last[i])
			{
				//����Ĳ�����+-*/^���ʶ���ࡣ���Ծ͵�һ��+��д����ϸ��ע��
			case '+':
				newnumber = number1 + number2;
				intStractPush(&a, newnumber);
				//����ΪʲôҪ����newnumber�أ���Ϊ����ԭ���������Ԫ�ص�֮��ɾ���ٰѵõ��Ľṹѹ��ջ��
				i++;
				break;
			case '-':
				newnumber = number1 - number2;
				intStractPush(&a, newnumber);
				i++;
				break;
			case '*':
				newnumber = number1 * number2;
				intStractPush(&a, newnumber);
				i++;
				break;
			case '/':
				newnumber = number1 / number2;
				intStractPush(&a, newnumber);
				i++;
				break;
			case '^':
				newnumber = pow(number1, number2);
				intStractPush(&a, newnumber);
				i++;
				break;
			}
		}
	}
	int lastnumber = a.tail->a;
	intStractPop(&a);
	return lastnumber;
}