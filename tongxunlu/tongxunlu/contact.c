#include "contact.h"



//静态版本
//void begincon(contactt* pc)
//{
//	pc->sz = 0;
//
//	memset(pc->data, 0, sizeof(pc->data));
//}
//动态版本


void zengrong(contactt* pc)
{
	if (pc->sz == pc->capacity)//当现在的sz和现在的最大容量相同时，考虑增加容量
	{
		people* ptr = (people*)realloc(pc->data, (pc->capacity + incc) * sizeof(people));//增加incc个元素的内存
		if (ptr != NULL)
		{
			pc->data = ptr;//上面那个realloc函数已经增容了，所以这里赋值相当于增容
			//realloc函数的作用是重新分配内存，如果原来的内存块够大，它会直接返回原来的指针
			//如果原来的内存块太小，它会分配一个新的内存块，把原来的数据复制过去，然后释放原来的内存块，返回新的指针
			pc->capacity += incc;

			printf("增容成功\n");
			if (pc->capacity >= max)
			{
				printf("通讯录已经增容到达极限%d,请珍惜剩余的名额\n", max);
			}
		}
		else
		{
			perror("addcon");
			printf("增加联系人失败\n");
			return;
		}
	}
}

void readcon(contactt* pc)
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("perror");
		return;	
	}
	//读入文件到程序
	people tmp = { 0 };
	while (fread(&tmp, sizeof(people), 1, pf))
	{
		//这里要先检查是否要增容
		zengrong(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//删除pf
	fclose(pf);
	pf = NULL;
}

void begincon(contactt* pc)
{
	pc->data = (people*)malloc(defulat * sizeof(people));//申请的空间的大小是defulat✖people类型的大小
	//强制转化为一个poeple*的大小，然后data接收的时候每次接收一个
	if (pc->data == NULL)
	{
		perror("begincon");
		return;
	}
	pc->sz = 0;
	pc->capacity = defulat;
	readcon(pc);
}



//静态版本
//void addcon(contactt* pc)
//{
//	if (pc->sz == max)
//	{
//		printf("通讯录已满，无法输入\n");
//		return;
//	}
//	else
//	{
//		printf("请输入名字：");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("请输入年龄：");
//		scanf("%d", &pc->data[pc->sz].age);
//		//注意，输入要取地址。其他的都是字符形式，所以不需要取地址，int类型要取地址
//		printf("请输入性别：");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("请输入电话号码：");
//		scanf("%s", pc->data[pc->sz].numeber);
//		printf("请输入地址：");
//		scanf("%s", pc->data[pc->sz].address);
//		pc->sz++;
//		printf("增加成功\n");
//	}
//}
//动态版本
void addcon(contactt* pc)
{
	if (pc->sz >= max)
	{
		printf("通讯录已经到达上限了，无法再增加\n");
			return;
	}
	zengrong(pc);
	//这里判断是否要增容，以及增容的操作（增容的操作时要进行的，不是要判断的）
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	//注意，输入要取地址。其他的都是字符形式，所以不需要取地址，int类型要取地址
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话号码：");
	scanf("%s", pc->data[pc->sz].numeber);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].address);
	pc->sz++;
	printf("增加成功\n");
}

int findd(contactt* pc, char *name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void delcon(contactt* pc)
{
	char name2[20] = "mingzi";
	printf("请输入你想要删除的人：");
	scanf("%s", name2);
	int ret = findd(pc, name2);
	if (ret == -1)
	{
		printf("没有你想删除的人，无法删除\n");
		return;
	}
	int i = 0;
	for(i=ret;i<pc->sz;i++)
	{
		pc->data[i] = pc->data[i+1];
	}
	pc->sz--;
}

void seacon(contactt* pc)
{
		char name2[20] = "mingzi";
		printf("请输入你想要寻找的人：");
		scanf("%s", name2);
		int ret = findd(pc, name2);	
		if (ret == -1)
		{
			printf("没有你要寻找的人，寻找不到\n");
		}
		else
		{
			printf("%-20s\t%-5s\t%-5s\t%-16s\t%-15s\n\n", "名字", "年龄", "性别", "电话号码", "地址");
				printf("%-20s\t%-5d\t%-5s\t%-16s\t%-15s\n",
					pc->data[ret].name,
					pc->data[ret].age,
					pc->data[ret].sex,
					pc->data[ret].numeber,
					pc->data[ret].address);
			
		}
}

void modcon(contactt*pc)
{
	char name2[20] = "mingzi";
	printf("请输入你想要修改信息的人：");
	scanf("%s", name2);
	int ret = findd(pc, name2);
	if (ret == -1)
	{
		printf("没有你要修改信息的人，寻找不到\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄：");
		scanf("%d", &pc->data[pc->sz].age);
		//注意，输入要取地址。其他的都是字符形式，所以不需要取地址，int类型要取地址
		printf("请输入性别：");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话号码：");
		scanf("%s", pc->data[pc->sz].numeber);
		printf("请输入地址：");
		scanf("%s", pc->data[pc->sz].address);
		pc->sz++;
		printf("修改成功\n");

		printf("%-20s\t%-5s\t%-5s\t%-16s\t%-15s\n\n", "名字", "年龄", "性别", "电话号码", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-16s\t%-15s\n",
			pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].numeber,
			pc->data[ret].address);

	}
}

void sorcon(contactt*pc)//给通讯录排序
{
	int a = 0;
	a:
	printf("请输入你想要按照什么排序：\n");
	printf("*********************************\n");
	printf("******  1.name  2.age  **********\n");
	printf("******  3.number  4.address *****\n");
	printf("*********************************\n");
	scanf("%d", &a);
	switch(a)
	{
	case 1:
	{
		int i = 0, a = 0;
		for (i = 0; i < pc->sz; i++)
		{
			for (a = 0; a < pc->sz - i-1; a++)
			{
				int result = strcmp(pc->data[a].name, pc->data[a+1].name);
				if (result>0)
				{
					people beifen;
					beifen = pc->data[a];
					pc->data[a] = pc->data[a + 1];
					pc->data[a + 1] = beifen;
				}
			}
		}
		break;
	}
	case 2:
	{
		int i = 0, a = 0;
		for (i = 0; i < pc->sz; i++)
		{
			for (a = 0; a < pc->sz - i-1; a++)
			{
				if (pc->data[a].age > pc->data[a + 1].age)
				{
					people beifen;
					beifen = pc->data[a];
					pc->data[a] = pc->data[a + 1];
					pc->data[a + 1] = beifen;
				}
			}
		}
		break;
	}
	case 3:
	{
		int i = 0, a = 0;
		for (i = 0; i < pc->sz; i++)
		{
			for (a = 0; a < pc->sz - i-1; a++)
			{
				int result = strcmp(pc->data[a].numeber, pc->data[a + 1].numeber);
				if (result > 0)
				{
					people beifen;
					beifen = pc->data[a];
					pc->data[a] = pc->data[a + 1];
					pc->data[a + 1] = beifen;
				}
			}
		}
		break;
	}
	case 4:
	{
		int i = 0, a = 0;
		for (i = 0; i < pc->sz; i++)
		{
			for (a = 0; a < pc->sz - i-1; a++)
			{
				int result = strcmp(pc->data[a].address, pc->data[a + 1].address);
				if (result > 0)
				{
					people beifen;
					beifen = pc->data[a];
					pc->data[a] = pc->data[a + 1];
					pc->data[a + 1] = beifen;
				}
			}
		}
		break;
	}
	default:
		printf("输入错误，请重新输入\n");
		goto a;
	}
	pricon(pc);
}

void pricon(contactt* pc)
{
	if (pc->sz == 0) // 检查通讯录是否为空
	{
		printf("通讯录为空，请先添加联系人\n");
		return;
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-5s\t%-5s\t%-16s\t%-15s\n\n","名字", "年龄", "性别", "电话号码", "地址");

		for (i = 0; i < pc->sz; i++)
		{
			printf("%-20s\t%-5d\t%-5s\t%-16s\t%-15s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].numeber,
				pc->data[i].address);
		}
	}
}


void connnn(contactt* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("connnn");
		return;
	}
	//写入文件
	int i = 0;
	for(i=0;i<pc->sz;i++)
	{
		fwrite(pc->data + i, sizeof(people), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}