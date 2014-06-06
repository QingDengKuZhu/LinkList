#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

LINKLIST * InitList(void)
{
	NODE *pHead = (NODE *)malloc(sizeof(NODE));	/*生成一个头指针.*/
	if (!pHead)
	{
		printf("头结点动态内存分配错误!\n");
		exit(ERROR);
	}
	
	pHead->pNext = NULL;	/*初始时,单链表为空,头结点指针域为空.*/
	
	return pHead;
}



void DestroyList(LINKLIST **ppL)
{
	/*函数参数不能是LINKLIST * pL, 因为这样会导致pL不能修改,而在本函数中,头指针最后必须为NULL.*/
	NODE *q = NULL;
	
	while (*ppL)
	{
		q = (*ppL)->pNext;
		free(*ppL);
		*ppL = q;
	}/*退出while()循环时, *ppL一定为NULL.*/

	/*不需要再设定(*ppL)为空,因为此时*ppL已经为NULL,这是与ClearList()的区别.*/
	
	return;
}



void ClearList(LINKLIST *pL)
{
	NODE *p = pL->pNext;	/*指向首节点(如果存在的话).*/
	NODE *q = NULL;

	while (p)
	{
		q = p->pNext;
		free(p);
		p = q;
	}

	pL->pNext = NULL;	/*必须将pL->pNext设置为NULL,因为头指针存在,链表为空(相当于回到了初始化后(InitList()后)状态).*/

	return;
}



BOOL ListEmpty(const LINKLIST *pL)
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



size_t ListLength(const LINKLIST *pL)
{
	/*不能使用头结点数据域存放链式线性表长度,因为当且仅当数据域类型为int时,才能使用首节点的数据域存储链式线性表的长度.*/
	
	NODE *p = pL->pNext;
	size_t length = 0;

	while (p)
	{
		++length;
		p = p->pNext;
	}

	return length;
}



STATUS GetElem(const LINKLIST *pL, const size_t pos, Elem *e)
{
	size_t cur = 1;			/*位序计数.*/
	NODE *p = pL->pNext;	/*指向首节点(如果存在的话).*/

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



size_t LocateElem(const LINKLIST *pL, const Elem v)
{
	size_t pos = 1;
	NODE *p  = pL->pNext;

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



STATUS InsertList(LINKLIST *pL, const size_t pos, const Elem v)
{
	NODE *p = pL;
	NODE *pNew = NULL;
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
		if (pos == cur)	/*找到插入点.*/
		{
				/*
				**插入数据.
				*/
				pNew = (NODE *)malloc(sizeof(NODE));
				if (!pNew)
				{
					printf("动态生成新结点失败!\n");
					exit(ERROR);
				}

				pNew->data = v;

				pNew->pNext = p->pNext;
				p->pNext = pNew;

				return OK;

		}

		p = p->pNext;
		++cur;
	}

	/*
	**未找到插入点.
	*/
	return FAILE;
}



STATUS DeleteList(LINKLIST *pL, const size_t pos, Elem *e)
{
	NODE *p = pL->pNext;
	NODE *q = pL;
	size_t cur = 1;

	if (pos < 1)	/*判断删除点是否合理.*/
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



void TraveList(const LINKLIST *pL)
{
	NODE *p = pL->pNext;

	while (p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}

	return;
}




