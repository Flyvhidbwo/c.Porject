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
	//��ʼ������
	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);///��ӡ����
	while(1)
	{
		///��ҳ���
		PlayerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//�ж��Ƿ����
		ret = Iswin(board,ROW,COL);
		if(ret != 'C')
		{
			break;
		}
		///���������
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//�ж��Ƿ����
		ret = Iswin(board,ROW,COL);
		if(ret != 'C')
		{
			break;
		}
	}
	if(ret == '*')
	{
		printf("���Ӯ\n");
	}
	if(ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if(ret == 'Q')
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
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