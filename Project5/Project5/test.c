#include "game.h"

void menu()
{
	printf("**********************\n");
	printf("******  1.play  ******\n");
	printf("******  0.exit  ******\n");
	printf("**********************\n");
}

void game()
{
	//����������̣�����ʼ��
	char show[ROWS][COLS];
	chushihua(show, ROWS, COLS, '*');
	//�����������̣�����ʼ��
	char mine[ROWS][ROWS];
	chushihua(mine, ROWS, COLS, '0');
	//��ӡ����
	display(show, ROWS, COLS);
	//���������
	buzhi(mine, ROWS, COLS, geshu);
	/*display(mine, ROWS, COLS);*/
	//��ʼɨ�ף���������Ϸ�ڵĹ���
	saolei(show, mine, ROWS, COLS, geshu);
	//�����Ƿ�ʤ��
	//��Ϊsaolei����д����while��1��ѭ��
	//���Լ����Ƿ�ʤ��Ӧ�������ں���saolei����

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("��Ϸ��ʼ\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}