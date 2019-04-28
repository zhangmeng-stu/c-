#define _CRT_SECURE_NO_WARNINGS 1//预处理器定义

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//调用头文件，生成随机数

#define ROW 3//使用宏定义，方便修改棋盘大小
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col); 
void ComputerMove(char board[ROW][COL], int row, int col);
char WinCheck(char board[ROW][COL], int row, int col);


