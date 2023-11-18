#include "game.h"

void menu()
{
    printf("***************************************\n");
    printf("***********   1. play       ***********\n");
    printf("***********   0. exit       ***********\n");
    printf("***************************************\n");
}

void game()
{
    char mine[ROWS][COLS] = {0};//布置雷的样子，我们看不见
    char show[ROWS][COLS] = {0};//我们能看到的显示
    //初始化棋盘
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');
    //打印棋盘
    DisplayBoard(show,ROW,COL);
    //设置雷
    SetMine(mine,ROW,COL);
    //DisplayBoard(mine,ROW,COL);
    //排查雷
    FindMine(mine,show,ROW,COL);
}
int main()
{
    int input=0;
    srand((unsigned int ) time(NULL));
    do {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (input);
    return 0;
}