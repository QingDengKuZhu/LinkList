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
LINKLIST *InitList(void);

/*销毁单链表.*/
void DestroyList(LINKLIST **ppL);

/*将单链表清空.*/
void ClearList(LINKLIST *pL);

/*判断单链表是否为空.若为空,函数返回TRUE;否者函数返回FALSE.*/
BOOL ListEmpty(const LINKLIST *pL);

/*返回单链表的长度*/
size_t ListLength(const LINKLIST *pL);

/*获取单链表中第pos个元素.若操作成功,函数返回OK,*e保存满足条件的结点的值;若操作失败,函数返回FAILE,*e为垃圾值.*/
STATUS GetElem(const LINKLIST *pL, const size_t pos, Elem *e);

/*返回单链表中第一个与v相等的元素的位序(从1开始).若成功函数返回相应的位序;否者返回0.*/
size_t LocateElem(const LINKLIST *pL, const Elem v);

/*在单链表中第pos个位置之前插入新的数据元素v(1 <= pos <= ListLength(pL)+1).若成功,函数返回OK;否者返回FAILE.*/
STATUS InsertList(LINKLIST *pL, const size_t pos, const Elem v);

/*删除单链表中第pos个元素.若成功删除,函数返回OK,*e保存被删除元素的值;否者函数返回FAILE,*e为垃圾值.*/
STATUS DeleteList(LINKLIST *pL, const size_t pos, Elem *e);

/*遍历输出单链表.*/
void TraveList(const LINKLIST *pL);

#endif