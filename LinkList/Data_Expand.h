/*************************************
**单链表的扩展操作
**************************************/
#ifndef DATA_EXPAND_H
#define DATA_EXPAND_H

#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"


/*快速找到未知长度单链表的中间结点.若找到该结点,返回地址;否则,返回NULL.*/
NODE *FindMidNode(const LINKLIST *pL);

#endif