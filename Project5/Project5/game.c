#include "game.h"
//��ʼ��һ�����̣����������char sets��0����*��������ʼ��������
void chushihua(char str[ROWS][COLS], int rows, int cols, char sets)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			//������ʵ�ǳ�ʼ��������飬����������������������
			str[i][j] = sets;
		}
	}
}
//��ӡ���̵ĺ���
void display(char str[ROWS][COLS], int rows, int cols)
{
	printf("--------���Ƿֽ���--------\n");
	int i = 0;
	int a = 0;
	int j = 0;
	for (i = 0; i < rows - 1; i++)
	{
		printf("%d ", i);
	}
	//����Ҫ�ȵȵ���һ�е����ִ�ӡ�����ȥ����
	printf("\n");
	//Ȼ��ʼ��ӡ�����չʾ������
	for (a = 1; a < rows - 1; a++)
	{
		printf("%d ", a);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%c ", str[a][j]);
		}
		printf("\n");
	}
	printf("--------���Ƿֽ���--------\n");
}

void buzhi(char str[ROWS][COLS], int rows, int cols, int cishu)
{
	int count = 0;
	while (count < geshu)
	{
		//���������test.c�ļ��������
		//srand((unsigned int)time(NULL));
		int a = (rand() % (rows - 2)) + 1;
		int b = (rand() % (cols - 2)) + 1;
		if (str[a][b] == '0')
		{
			str[a][b] = '1';
			count++;
		}
	}
}

void saolei(char show[ROWS][COLS], char mine[ROWS][COLS], int rows, int cols, int cishu)
{
	int xunhuan = 1;
	while (1)
	{
		int a = 0, b = 0, c = 0;
		printf("����������ɨ��������>\n");
		scanf("%d %d", &a, &b);
		if (show[a][b] == '*')
		{
			printf("1.ɨ��\n2.���\n");
			scanf("%d", &c);
			if (c == 1)
			{
				if (mine[a][b] == '1')
				{
					printf("�ȵ����ˣ�������\n");
					break;
				}
				if (mine[a][b] == '0')
				{
					int c = 0, d = 0, geeshu = 0;
					//������Χ������
					//�����geeshu��ö����������棬����һ��ѭ�����֮��geeshu�ֱ��0
					for (c = 0; c < 3; c++)
					{
						for (d = 0; d < 3; d++)
						{
							if (mine[a + c - 1][b + d - 1] == '1')
							{
								geeshu++;
							}
						}
					}
					//�����geeshuָ���ǣ�������������ڣ��Ź����ڵ��׵�����
					char ch = geeshu + '0';
					//�������������0��ASCII��ֵ����geeshu��Ȼ����ܵõ�geeshu����ֵ�������ASCII��ֵ��Ȼ����ܰ����ascii��ֵת��Ϊ�Զ��
					//char���͵����ݡ�
					show[a][b] = ch;
					display(show, ROWS, COLS);
					xunhuan++;
					//xunhuan++������Ϸ������һ��
				}
				//��ȷ�ߵĲ���
				if (xunhuan == ((ROWS - 2) * (COLS - 2) - cishu + 1))
				{
					printf("ɨ����ϣ�������Ϸ\n");
					//��ѭ���Ĵ������ڸ����ܸ�����ȥ�Ѿ��׵ĸ�����ʱ��.cishuָ�����׵��ܸ���
					break;
				}

			}
			else if (c == 2)
			{
				show[a][b] = '#';
				display(show, ROWS, COLS);
			}
		}

		else if (show[a][b] == '#')
		{
			printf("�����Ѿ�����ע�ˣ����ڽ⿪��ע\n");
			show[a][b] = '*';
		}
		else
		{
			printf("�����Ѿ���ɨ���ˣ���������");
			display(show, ROWS, COLS);
		}
	}
}