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
	InitBoard(mine, ROWS, COLS, '0');//��ʼ��'0',���׵�����
	InitBoard(show, ROWS, COLS, '*');//��ʼ��'*',
	SetMine(mine, ROW, COL);//������
	DisplayBoard(show, ROW, COL);//��ӡ����
	FirstMine(mine, show, ROW, COL);//��֤��һ�ε㿪û����
	FindMine(mine, show, ROW, COL);//����
}

void test()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));//���������
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
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