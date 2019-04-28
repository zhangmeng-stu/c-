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
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);//初始化数组
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)//玩游戏
	{
		PlayerMove(board, ROW, COL);//玩家走
		DisplayBoard(board, ROW, COL);
		ret = WinCheck(board, ROW, COL);
		if (ret != 'C')//判断输赢
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = WinCheck(board, ROW, COL);
		if (ret != 'C')//判断输赢
			break;
	}
		if (ret == '*')
		{
			printf("恭喜你，你赢了！\n");
		}
		else if (ret == '#')
		{
			printf("电脑赢!\n");
		}
		else if (ret == 'Q')
		{
			printf("平局!\n");
		}
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