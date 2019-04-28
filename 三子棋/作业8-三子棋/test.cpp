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
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)//����Ϸ
	{
		PlayerMove(board, ROW, COL);//�����
		DisplayBoard(board, ROW, COL);
		ret = WinCheck(board, ROW, COL);
		if (ret != 'C')//�ж���Ӯ
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = WinCheck(board, ROW, COL);
		if (ret != 'C')//�ж���Ӯ
			break;
	}
		if (ret == '*')
		{
			printf("��ϲ�㣬��Ӯ�ˣ�\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ!\n");
		}
		else if (ret == 'Q')
		{
			printf("ƽ��!\n");
		}
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