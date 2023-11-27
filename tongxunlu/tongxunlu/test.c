#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void menu()
{
		printf("*********************************\n");
		printf("******  1.add  2.del  ***********\n");
		printf("******  3.search  4.modify  *****\n");
		printf("******  5.sort  6.print  ********\n");
		printf("******  0.exit  *****************\n");
}

int main()
{
	int input = 0;
	contactt con;
	//初始化这个通讯录
	begincon(&con);
	//然后读取通讯录
	do
	{
		menu();
		printf("请输入你的选择>\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			addcon(&con);
			break;
		case DEL:
			delcon(&con);
			break;
		case SEARCH:
			seacon(&con);
			break;
		case MODIFY:
			modcon(&con);
			break;
		case SORT:
			sorcon(&con);
			break;
		case PRINT:
			pricon(&con);
			break;
		case EXIT:
			//这里先记录下已经输入的通讯录，以便下次打开的时候还有记录
			//记录的函数
			connnn(&con);
			free(con.data);
			con.data = NULL;
			con.capacity = 0;
			con.sz = 0;
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}