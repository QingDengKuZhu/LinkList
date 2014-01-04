/**********************
**与测试有关的声明
***********************/
#ifndef TEST_H
#define TEST_H

#include <stddef.h>

/*系统主菜单函数,显示系统的主菜单界面,提示用户进行相应的操作*/
void Menu(void);


/*光标定位*/
void gotoxy(const short x, const short y);


/*输入的位序*/
size_t InputPos(const char notice[]);


/*输入结点数据*/
int InputValue(const char notice[]);


#endif