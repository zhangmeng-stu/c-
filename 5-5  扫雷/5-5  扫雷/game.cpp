# define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int row, int col, char set)//初始化雷盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)//打印雷盘
{
	system("CLS");//每次打印雷盘之前清屏一次
	int i = 0;
	int j = 0;
	
	for (i = 0; i <= row; i++)
		printf("%d ", i);//打印列坐标1 2 3 4 5 6 7 8 9 
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行坐标1 2 3 4 5 6 7 8 9 
		for (j = 1; j <= row; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}	
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x;
		int y;
		x = rand() % row + 1;//保证行坐标在1到9之间
		y = rand() % col + 1;
		if (mine[x][y] = '0')//判断该位置是否布置过雷
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';//将该位置周围八个位置的情况（是否有雷）计数
}
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//展开一片
{
		int ret = 0;
		ret = GetMineCount(mine, x, y);
		if (ret == 0)
		{
			show[x][y] = ' ';
			if (x > 0 && y + 1 <= col && show[x][y + 1] == '*')
				OpenMine(mine, show, row, col, x, y + 1);
			if (x - 1 > 0 && y + 1 <= col && show[x - 1][y + 1] == '*')
				OpenMine(mine, show, row, col, x - 1, y + 1);
			if (x - 1 > 0 && y > 0 && show[x - 1][y] == '*')
				OpenMine(mine, show, row, col, x - 1, y);
			if (x - 1>0 && y - 1 > 0 && show[x - 1][y - 1] == '*')
				OpenMine(mine, show, row, col, x - 1, y - 1);
			if (x >0 && y - 1 > 0 && show[x][y - 1] == '*')
				OpenMine(mine, show, row, col, x, y - 1);
			if (x + 1 <= row && y - 1 > 0 && show[x + 1][y - 1] == '*')
				OpenMine(mine, show, row, col, x + 1, y - 1);
			if (x + 1 <= row && y > 0 && show[x + 1][y] == '*')
				OpenMine(mine, show, row, col, x + 1, y);
			if (x + 1 <= row && y + 1 <= col&& show[x + 1][y + 1] == '*')
				OpenMine(mine, show, row, col, x + 1, y + 1);
		}
		else
		{
			show[x][y] = GetMineCount(mine, x, y) + '0';
		}
}

void FirstMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	int ret = 0;
	int count = 0;
	printf("请输入要排查的坐标：");
	scanf("%d,%d", &x, &y);
	if (mine[x][y] == '1')
	{
		mine[x][y] = '0';
		count = GetMineCount(mine, x, y);
		show[x][y] = count + '0';
		while (ret)//随机生成一个雷
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
			}
			ret--;
		}
	}
	OpenMine(mine, show, row, col, x, y);
	DisplayBoard(show, row,col);
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0; 
	int y = 0;
	int win = 0;
	while (win < row*col - EASY_COUNT)
	{
		printf("请输入你要排查的坐标：");
		scanf("%d,%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("有雷，你被炸死了!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine, show, row, col, x, y);
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("坐标非法!");
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜，排雷成功!");
		DisplayBoard(mine, row, col);
	}
}



