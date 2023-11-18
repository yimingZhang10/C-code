//
// Created by yiming Zhang on 11/2/23.
//
#include "game.h"
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
    int i = 0;
    int j = 0;
    for (i = 0;i <rows;i++)
    {
        for (j=0;j<cols;j++)
        {
            board[i][j]=set;
        }
    }
}
void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
    int i,j;
    printf("******* 扫雷 *******\n");
    for (j=0;j<=col;j++)
    {
        printf("%d ",j);
    }
    printf("\n");
    for (i=1;i<=row;i++)
    {
        printf("%d ",i);
        for (j=1;j<=col;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
void SetMine(char mine[ROWS][COLS],int row,int col)
{
    int count=EASY_COUNT;
    while (count)
    {
        int x,y;
        x=rand()%row+1;
        y=rand()%col+1;
        if (mine[x][y]=='0')
        {
            mine[x][y]='1';
            count--;
        }

    }
}
int GetMineCount(char mine[ROWS][COLS],int x,int y)
{
    return (mine[x-1][y]+
            mine[x-1][y-1]+
            mine[x][y-1]+
            mine[x+1][y-1]+
            mine[x+1][y]+
            mine[x+1][y+1]+
            mine[x][y+1]+
            mine[x-1][y+1]-8*'0');
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x,y;
    int win=0;
    while (win<row*col-EASY_COUNT)
    {
        printf("请输入要排查的坐标:>");
        scanf("%d %d",&x,&y);
        if (x>=1 && x<=row && y>=1 && y<=col)
        {
            if(show[x][y]=='*')
            {
                if (mine[x][y]=='1')
                {
                    printf("炸\n");
                    DisplayBoard(mine,ROW,COL);
                    break;
                }else
                {
                    //如果该坐标不是雷，就要统计这个坐标周围有几个雷
                    int count = GetMineCount(mine,x,y);
                    show[x][y]=count+'0';
                    DisplayBoard(show,ROW,COL);
                    win++;
                }
            }
            else
            {
                printf("已经排查过了\n");
            }

        } else
        {
            printf("排查坐标非法，请重新输入\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("赢了\n");
        DisplayBoard(mine, ROW, COL);
    }
}