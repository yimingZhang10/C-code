//
// Created by yiming Zhang on 11/2/23.
//

#ifndef SAOLEI_GAME_H
#define SAOLEI_GAME_H
#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include <stdlib.h>
#include <time.h>
#define EASY_COUNT 10
#endif //SAOLEI_GAME_H
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char mine[ROWS][COLS],int row,int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);