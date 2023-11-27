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
	//创造可视棋盘，并初始化
	char show[ROWS][COLS];
	chushihua(show, ROWS, COLS, '*');
	//创造内置棋盘，并初始化
	char mine[ROWS][ROWS];
	chushihua(mine, ROWS, COLS, '0');
	//打印棋盘
	display(show, ROWS, COLS);
	//随机布置雷
	buzhi(mine, ROWS, COLS, geshu);
	/*display(mine, ROWS, COLS);*/
	//开始扫雷，并进行游戏内的规则
	saolei(show, mine, ROWS, COLS, geshu);
	//计量是否胜利
	//因为saolei里面写的是while（1）循环
	//所以计量是否胜利应该运用在函数saolei里面

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("游戏开始\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}