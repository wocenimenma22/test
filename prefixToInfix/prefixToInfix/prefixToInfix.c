#include"prefixToInfix.h"
void Initializes(Stracts* pa)//初始化栈
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void StractPush(Stracts* pa, stractdata x)//栈只能尾插尾删
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

void StractPop(Stracts* pa)//删除，原来的删除有缺陷，当栈中只剩下最后一个元素的时候，无法删除。
//现已更正
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

void intInitializes(intStracts* pa)
{
	assert(pa);
	pa->head = NULL;
	pa->tail = NULL;
}

void intStractPush(intStracts* pa, intstractdata x)//栈只能尾插尾删
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
		printf("栈内空间为空现在，不能删除");
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

void change(char* middle, char* last)//从中缀表达式转换为后缀表达式
{
	Stracts a;
	//这里的a是用来存放运算符号的栈
	Initializes(&a);
	int i = 0;
	int j = 0;
	while (middle[i]!='\0'&&i<100)
	{
		//当这个字符串的元素还没有调用到最后一位就继续循环。
		switch (middle[i])
		{
			//后面的不论是+-*/^性质都差不多。所以就第一个+的写了详细的注释
		case '+':
			if (IsEmpty(&a)==1)
			{//当栈为空的时候，直接入栈。不用管前面的元素是什么。
				StractPush(&a, '+');
				i++;
				break;
			}
			else
			{
				while (a.tail->a == '+' || a.tail->a == '-' || a.tail->a == '*' || a.tail->a == '/' || a.tail->a == '^')
				{
					//当这个元素入栈之后，如果前面的元素的运算等级比他高或者等于他的运算等级。那么就把比他高的和与他相同的入到字符串里面。
					//再把这个元素入栈。
					char ch = a.tail->a;
					StractPop(&a);
					last[j] = ch;
					j++;	
					if (IsEmpty(&a) == 1)
					{
						break;
					}
				}
				//等循环结束之后，再把这个运算符号插入到这个栈里面去
				StractPush(&a, '+');
				i++;
				//这个i++只要加一次就行，从if (IsEmpty(&a) == 1)这个会跳到这个地方，如果上面的if (IsEmpty(&a) == 1)里再i++一次
				//这里就会多i++一次，放在这里i++每次都会执行一次。
				break;
			}
			//后面的这些情况都和上面的这种相似。
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
				//这个i++只要加一次就行，从if (IsEmpty(&a) == 1)这个会跳到这个地方，如果上面的if (IsEmpty(&a) == 1)里再i++一次
				//这里就会多i++一次，放在这里i++每次都会执行一次。
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
				//这个i++只要加一次就行，从if (IsEmpty(&a) == 1)这个会跳到这个地方，如果上面的if (IsEmpty(&a) == 1)里再i++一次
				//这里就会多i++一次，放在这里i++每次都会执行一次。
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
				//这个i++只要加一次就行，从if (IsEmpty(&a) == 1)这个会跳到这个地方，如果上面的if (IsEmpty(&a) == 1)里再i++一次
				//这里就会多i++一次，放在这里i++每次都会执行一次。
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
				//这个i++只要加一次就行，从if (IsEmpty(&a) == 1)这个会跳到这个地方，如果上面的if (IsEmpty(&a) == 1)里再i++一次
				//这里就会多i++一次，放在这里i++每次都会执行一次。
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
			//这个i++只要加一次就行，从if (IsEmpty(&a) == 1)这个会跳到这个地方，如果上面的if (IsEmpty(&a) == 1)里再i++一次
				//这里就会多i++一次，放在这里i++每次都会执行一次。
			break;
		default:
			while((middle[i]>='0')&&(middle[i]<='9'))
			{
				last[j] = middle[i];
				i++;
				j++;
				//这里采用循环，可以解决输入的元素是单位数还是多位数的问题。
			}
			//这里多一个空格内容上比较好看
			last[j] = ' ';
			j++;
			break;
		}
	
	}
	//当middle字符串已经被遍历完毕了，就可以把栈中所有的元素都提取出来了
	while (IsEmpty(&a) == 0)
	{
		if (a.tail->a != '(')
		{
			last[j] = a.tail->a;
			StractPop(&a);
			j++;
		}
		//这里加了if esle，是为了当那个（出现的时候，不管这个元素，不插入，但是还要保证把他放出栈
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

bool IsEmpty(Stracts* pa)//检查是否为空
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
	int sign = 1;//正负号问题
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
	//这里的a是用来存放运算符号的栈
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
				//后面的不论是+-*/^性质都差不多。所以就第一个+的写了详细的注释
			case '+':
				newnumber = number1 + number2;
				intStractPush(&a, newnumber);
				//这里为什么要加入newnumber呢，因为根据原则，算出两个元素的之后，删除再把得到的结构压入栈中
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