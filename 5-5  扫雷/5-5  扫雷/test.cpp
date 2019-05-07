# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h>
# include "game.h"


void menu()
{
	printf("***********************************************\n");
	printf("*******     1.play         0.exit        ******\n");
	printf("***********************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');//初始化'0',存雷的数字
	InitBoard(show, ROWS, COLS, '*');//初始化'*',
	SetMine(mine, ROW, COL);//布置雷
	DisplayBoard(show, ROW, COL);//打印雷盘
	FirstMine(mine, show, ROW, COL);//保证第一次点开没有雷
	FindMine(mine, show, ROW, COL);//排雷
}

void test()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));//生成随机数
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	system("pause");
	return 0;
}