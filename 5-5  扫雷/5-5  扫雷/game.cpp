# define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int row, int col, char set)//��ʼ������
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

void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	system("CLS");//ÿ�δ�ӡ����֮ǰ����һ��
	int i = 0;
	int j = 0;
	
	for (i = 0; i <= row; i++)
		printf("%d ", i);//��ӡ������1 2 3 4 5 6 7 8 9 
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ������1 2 3 4 5 6 7 8 9 
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
		x = rand() % row + 1;//��֤��������1��9֮��
		y = rand() % col + 1;
		if (mine[x][y] = '0')//�жϸ�λ���Ƿ��ù���
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
		mine[x - 1][y + 1] - 8 * '0';//����λ����Χ�˸�λ�õ�������Ƿ����ף�����
}
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//չ��һƬ
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
	printf("������Ҫ�Ų�����꣺");
	scanf("%d,%d", &x, &y);
	if (mine[x][y] == '1')
	{
		mine[x][y] = '0';
		count = GetMineCount(mine, x, y);
		show[x][y] = count + '0';
		while (ret)//�������һ����
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
		printf("��������Ҫ�Ų�����꣺");
		scanf("%d,%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ף��㱻ը����!\n");
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
			printf("����Ƿ�!");
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�!");
		DisplayBoard(mine, row, col);
	}
}



