#include "game.h"
//初始化一个棋盘，根据输入的char sets是0还是*来决定初始化的内容
void chushihua(char str[ROWS][COLS], int rows, int cols, char sets)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			//这里其实是初始化这个数组，用这个数组来代表这个棋盘
			str[i][j] = sets;
		}
	}
}
//打印棋盘的函数
void display(char str[ROWS][COLS], int rows, int cols)
{
	printf("--------我是分界线--------\n");
	int i = 0;
	int a = 0;
	int j = 0;
	for (i = 0; i < rows - 1; i++)
	{
		printf("%d ", i);
	}
	//这里要先等到第一行的数字打印完才能去换行
	printf("\n");
	//然后开始打印向玩家展示的棋盘
	for (a = 1; a < rows - 1; a++)
	{
		printf("%d ", a);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%c ", str[a][j]);
		}
		printf("\n");
	}
	printf("--------我是分界线--------\n");
}

void buzhi(char str[ROWS][COLS], int rows, int cols, int cishu)
{
	int count = 0;
	while (count < geshu)
	{
		//随机种子在test.c文件布置完毕
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
		printf("请输入你想扫除的坐标>\n");
		scanf("%d %d", &a, &b);
		if (show[a][b] == '*')
		{
			printf("1.扫雷\n2.标记\n");
			scanf("%d", &c);
			if (c == 1)
			{
				if (mine[a][b] == '1')
				{
					printf("踩到雷了，你死了\n");
					break;
				}
				if (mine[a][b] == '0')
				{
					int c = 0, d = 0, geeshu = 0;
					//遍历周围的数组
					//这里的geeshu最好定义在最外面，以免一次循环完毕之后，geeshu又变成0
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
					//这里的geeshu指的是，所输入的坐标内，九宫格内的雷的数量
					char ch = geeshu + '0';
					//这里的运算是用0的ASCII码值加上geeshu，然后就能得到geeshu的数值所代表的ASCII码值，然后就能把这个ascii码值转化为以恶搞
					//char类型的数据。
					show[a][b] = ch;
					display(show, ROWS, COLS);
					xunhuan++;
					//xunhuan++代表游戏进行了一步
				}
				//正确走的步数
				if (xunhuan == ((ROWS - 2) * (COLS - 2) - cishu + 1))
				{
					printf("扫雷完毕，结束游戏\n");
					//当循环的次数等于格子总个数减去已经雷的个数的时候.cishu指的是雷的总个数
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
			printf("这里已经被标注了，现在解开标注\n");
			show[a][b] = '*';
		}
		else
		{
			printf("这里已经被扫过了，重新输入");
			display(show, ROWS, COLS);
		}
	}
}