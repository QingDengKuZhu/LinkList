﻿#include "Test.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void gotoxy(short x, short y)
{
	COORD pos;	/*COORD在windows.h中定义*/
	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); /* 设置光标位置 */

	return;
}


void Menu(void)
{
	system("cls");
	gotoxy(10, 5);                        /*在文本窗口中设置光标*/
	cprintf("			单链表测试			");
	gotoxy(8, 8);
	cprintf("-----------------------------Menu-----------------------------\n");
	gotoxy(8, 9);
	cprintf("| 1.插入结点                     2.整表输出                  |\n");
	gotoxy(8, 10);
	cprintf("| 3.删除结点                     4.输出表长                  |\n");
	gotoxy(8, 11);
	cprintf("| 5.清空整表                     6.判断链表是否存在特定结点  |\n");
	gotoxy(8, 12);
	cprintf("| 7.返回特定位序结点             8.判断表是否为空            |\n");
	gotoxy(8, 13);
	cprintf("| 9.删除整表                                                 |\n");
//	gotoxy(8, 14);
//	cprintf("| 11.求前驱元素                  12.求后驱元素               |\n");
//	gotoxy(8, 15);
//	cprintf("| 13.退出                                                  |\n");
	gotoxy(8, 16);
	cprintf("--------------------------------------------------------------\n");
	
    return;
}

size_t InputPos(char notice[])
{
	int pos;		/*保存待输入的位序*/
	unsigned n;		/*保存scanf的返回值*/
	
	do 
	{
		printf(notice);
		n = scanf("%d", &pos);
		fflush(stdin);

		/*判断输入的位序是否在合理的范围内*/
		if (pos<1 || n!=1)
		{
			printf("位序必须大于0!!!\n");
		}
	} while (pos<1 || n!=1);

	return (size_t)pos;
}

int InputValue(char notice[])
{	
	int e;
	unsigned n;

	do 
	{
		printf(notice);
		n = scanf("%d", &e);
		fflush(stdin);

		if (n != 1)
		{
			printf("请输入满足条件的数值!\n");
		}

	} while (n!=1);
	
	return e;
}