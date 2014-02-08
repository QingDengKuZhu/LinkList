﻿#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"
#include "Data_Expand.h"

PNODE FindMidNode(PLINKLIST pL)
{
	/*法一
	**首先遍历一遍单链表以确定单链表的长度L.
	**然后再次从头结点出发循环L/2次找到单链
	**表的中间结点.
	**算法复杂度为:O(L+L/2) = O(3L/2).
	
	PNODE p = pL->pNext;
	size_t i = 1;
	size_t length = ListLength(pL);

	while (p && i<(leng+1)/2)
	{
		p = p->pNext;
		++i;
	}

	return p;
	*/
	
	/*法二(推荐)
	**利用快慢指针
	*/
	PNODE mid = pL;
	PNODE p = pL;

	while(p && p->pNext) /*p和p->pNext的顺序绝对不能调换!!!*/
	{
		mid = mid->pNext;
		p = p->pNext->pNext;
	}

	if (p == pL)
	{
		return NULL;
	}

	return mid;
}