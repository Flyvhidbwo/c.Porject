#define _CRT_SECURE_NO_WARRNINGS 1
#include<stdio.h>
#include<string.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("*****************************\n");
	printf("****  1.paly     0.exit  ****\n");
	printf("*****************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);///打印棋盘
	while(1)
	{
		///玩家出棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//判断是否继续
		ret = Iswin(board,ROW,COL);
		if(ret != 'C')
		{
			break;
		}
		///计算机出棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//判断是否继续
		ret = Iswin(board,ROW,COL);
		if(ret != 'C')
		{
			break;
		}
	}
	if(ret == '*')
	{
		printf("玩家赢\n");
	}
	if(ret == '#')
	{
		printf("电脑赢\n");
	}
	else if(ret == 'Q')
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} 
	while(input);
}

int main()
{
	test();
	return 0;
}