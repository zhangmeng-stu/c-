#ifndef __GAME_H__
#define __GAME_H__

# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define ROW 9 //��������
# define COL 9
#define ROWS ROW+2 //���̵�ʵ������
#define COLS COL+2
#define EASY_COUNT 10//�׵ĸ���

void InitBoard(char board[ROWS][COLS], int row, int col, char set);//��ʼ������
void DisplayBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
void SetMine(char mine[ROWS][COLS], int row, int col);//������
int GetMineCount(char mine[ROWS][COLS], int x, int y);//ͳ������
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);//չ��һƬ
void FirstMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);// ȷ����һ�ε㿪������
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col);//����



#endif