#define _CRT_SECURE_NO_WARNINGS 1//Ԥ����������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//����ͷ�ļ������������

#define ROW 3//ʹ�ú궨�壬�����޸����̴�С
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col); 
void ComputerMove(char board[ROW][COL], int row, int col);
char WinCheck(char board[ROW][COL], int row, int col);


