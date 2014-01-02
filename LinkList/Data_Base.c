﻿#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

PLINKLIST InitList(void)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));	/*生成一个头指针.*/
	if (!pHead)
	{
		printf("头结点动态内存分配错误!\n");
		exit(ERROR);
	}
	
	pHead->data = NULL;	/*初始时,单链表为空,头结点指针域为空.*/
	
	return pHead;

}



void DestroyList(PLINKLIST *ppL)
{
	/*函数参数不能是PLINKLIST pL, 因为这样会导致pL不能修改,而在本函数中,头指针最后必须为NULL.*/
	PNODE q = NULL;
	
	while (*ppL)
	{
		q = (*ppL)->pNext;
		free(*ppL);
		*ppL = q;
	}/*退出while()循环时, *ppL一定为NULL.*/

	/*不需要再设定(*ppL)为空,因为此时*ppL已经为NULL,这是与ClearList()的区别.*/
	
	return;

}



void ClearList(PLINKLIST pL)
{
	PNODE p = pL->pNext;	/*指向首节点(如果存在的话).*/
	PNODE q = NULL;

	while (p)
	{
		q = p->pNext;
		free(p);
		p = q;
	}

	pL->pNext = NULL;	/*必须将pL->pNext设置为NULL,因为头指针存在,链表为空(相当于回到了初始化后(InitList()后)状态).*/

	return;

}



BOOL ListEmpty(PLINKLIST pL)
{
	if (!(pL->pNext))	/*只需判断头结点指针域是否为NULL就行,不必求得单链表长度是否为0.*/
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}



size_t ListLength(PLINKLIST pL)
{
	/*不能使用头结点数据域存放链式线性表长度,因为当且仅当数据域类型为int时,才能使用首节点的数据域存储链式线性表的长度.*/
	
	PNODE p = pL->pNext;
	size_t length = 0;

	while (p)
	{
		++length;
		p = p->pNext;
	}

	return length;

}



STATUS GetElem(PLINKLIST pL, size_t pos, int *e)
{
	size_t cur = 1;			/*位序计数.*/
	PNODE p = pL->pNext;	/*指向首节点(如果存在的话).*/

	while (p)
	{
		if (cur == pos)	/*若当前位序计数与所需位序相同,则代表成功找到结点.*/
		{
			*e = p->data;
			return OK;
		}

		p = p->pNext;
		++cur;
	}

	return FAILE;

}



size_t LocateElem(PLINKLIST pL, int v)
{
	size_t pos = 1;
	PNODE p  = pL->pNext;

	while (p)
	{
		if (p->data == v)
		{
			return pos;
		}

		++pos;
		p = p->pNext;
	}

	return 0;

}



STATUS InsertList(PLINKLIST pL, size_t pos, int v)
{
	PNODE p = pL;
	PNODE q = NULL;
	PNODE pNew = NULL;
	size_t cur = 1;

	if (pos<1)	/*判断插入点是否合理.*/
	{
		return FAILE;
	}

	/*
	**寻找插入点.
	*/
	while (p)
	{
		if (pos == cur)
		{
			q = p->pNext;
			break;	/*在此处跳出while循环,p指向插入点*/
		}

		p = p->pNext;
		++cur;
	}

	if (!p)	/*当p为NULL时,表示寻找插入点时,没有找到插入点,即pos>LengthList(pL)+1.*/
	{
		return FAILE;
	}

	/*
	**插入数据.
	*/
	pNew = (PNODE)malloc(sizeof(NODE));
	if (!pNew)
	{
		printf("新结点插入失败!\n");
		exit(ERROR);
	}

	pNew->data = v;

	pNew->pNext = q;
	p->pNext = pNew;

	return OK;

}



STATUS DeleteList(PLINKLIST pL, size_t pos, int *e)
{
	PNODE p = pL->pNext;
	PNODE q = pL;
	size_t cur = 1;

	if (pos < 1)	/*判断插入点是否合理.*/
	{
		return FAILE;
	}

	while (p)
	{
		if (cur == pos)	/*找到删除结点,此时p指向删除结点,q指向删除结点的前一个结.*/
		{
			*e = p->data;
			q->pNext = p->pNext;
			free(p);
			
			return OK;
		}

		q = p;
		p = p->pNext;
		++cur;
	}

	return FAILE;

	}



void TraveList(PLINKLIST pL)
{
	PNODE p = pL->pNext;

	while (p)
	{
		printf("%d ", p->data);
	}

	return;
	
}




