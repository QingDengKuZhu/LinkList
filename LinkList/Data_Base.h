/**********************
**单链表的基本操作.
***********************/
#ifndef DATA_BASE_H
#define DATA_BASE_H

#include "Main_First.h"
#include "Data.h"
/*
pL为指向单链表的指针,且pL不为NULL.
*/

/*构造一个空的单链表.*/
PLINKLIST InitList(void);

/*销毁单链表.*/
void DestroyList(PLINKLIST pL);

/*将单链表清空.*/
void ClearList(PLINKLIST pL);

/*判断单链表是否为空.若为空,函数返回TRUE;否者函数返回FALSE.*/
BOOL ListEmpty(PLINKLIST pL);

/*返回单链表的长度*/
size_t ListLength(PLINKLIST pL);

/*获取单链表中第pos个元素.若操作成功,函数返回OK,*e保存满足条件的结点的值;若操作失败,函数返回FAILE,*e为垃圾值.*/
STATUS GetElem(PLINKLIST pL, size_t pos, int *e);

/*返回单链表中第一个与e相等的元素的位序(从1开始).若成功函数返回相应的位序;否者返回0*/
size_t LocateElem(PLINKLIST pL, int e);

/*在单链表中第pos个位置之前插入新的数据元素e(1 <= pos <= ListLength(pL)+1).若成功,函数返回OK;否者返回FAILE.*/
STATUS InsertList(PLINKLIST pL, size_t pos, int e);

/*删除单链表中第pos个元素.若成功删除,函数返回OK,*e保存被删除元素的值;否者函数返回FAILE,*e为垃圾值.*/
STATUS DeleteList(PLINKLIST pL, size_t pos, int *e);

/*遍历输出单链表*/
void TraveList(PLINKLIST pL);

#endif