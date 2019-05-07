#ifndef __GAME_H__
#define __GAME_H__

# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define ROW 9 //雷盘行数
# define COL 9
#define ROWS ROW+2 //雷盘的实际行数
#define COLS COL+2
#define EASY_COUNT 10//雷的个数

void InitBoard(char board[ROWS][COLS], int row, int col, char set);//初始化雷盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);//打印雷盘
void SetMine(char mine[ROWS][COLS], int row, int col);//布置雷
int GetMineCount(char mine[ROWS][COLS], int x, int y);//统计雷数
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);//展开一片
void FirstMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);// 确定第一次点开不是雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col);//排雷



#endif