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
	//��ʼ�����ͨѶ¼
	begincon(&con);
	//Ȼ���ȡͨѶ¼
	do
	{
		menu();
		printf("���������ѡ��>\n");
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
			//�����ȼ�¼���Ѿ������ͨѶ¼���Ա��´δ򿪵�ʱ���м�¼
			//��¼�ĺ���
			connnn(&con);
			free(con.data);
			con.data = NULL;
			con.capacity = 0;
			con.sz = 0;
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}