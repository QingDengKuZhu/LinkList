/**********************
**主函数, 测试
***********************/

#include "Main_First.h"
#include "Data.h"
#include "Data_Base.h"
#include "Test.h"
#include <time.h> /*随机数*/

int main(void)
{
	int select;		/*保存选择变量*/
	size_t pos;		/*位序*/
	Elem e;			/*保存从函数返回的结点的值*/
	Elem v;			/*保存传递给函数的结点的值*/
	
	size_t i= 0;
	PLINKLIST pL = InitList();
	srand((int)time(NULL));
	while (i < 10)
	{

		InsertList(pL, i, rand()%20);
		++i;
	}

	while (1)	/*while_@1*/
	{
		if (!pL)
		{
			printf("表不存在!\n");
			break;
		}

		system("cls");
		Menu();

		printf("请输入您的选择(1~10):");
		scanf("%d", &select);
		getchar();

		switch (select)	/*switch_@1*/
		{
		case 1:			/*插入数据*/
			pos = InputPos("插入位置为:");
			v = InputValue("结点元素为:");
			if (FAILE == InsertList(pL, pos, v))
			{
				printf("插入失败!\n");
			}
			else
			{
				printf("插入成功!\n");
			}
			
			getchar();
			break;
		case 2:			/*整表输出*/
			printf("整表为:");
			TraveList(pL);
			
			getchar();
			break;
		case 3:			/*删除结点*/
			pos = InputPos("删除的结点位置是:");
			if (OK == DeleteList(pL, pos, &e))
			{
				printf("删除成功,删除的元素是%d!\n", e);
			}
			else
			{
				printf("删除失败!\n");
			}

			getchar();
			break;

		case 4:			/*输出表的长度*/
			printf("表长为: %d \n", ListLength(pL));
			
			getchar();
			break;

		case 5:			/*清空表*/
			ClearList(pL);
			printf("该表已经清空!\n");
			
			getchar();
			break;

		case 6:			/*判断链表是否存在特定结点*/
			v =InputValue("要查找的数值为:");
			printf("要查找的元素在链表的第%d位!(第0位表示不存在)\n", LocateElem(pL, v));

			getchar();
			break;

		case 7:			/*返回特定位序结点*/
			pos = InputPos("获取位置为:");
			if (OK == GetElem(pL, pos, &e))
			{
				printf("该结点为:%d\n", e);
			}
			else
			{
				printf("不存在!\n");
			}

			getchar();	
			break;

		case 8:			/*判断链表*/
			if (ListEmpty(pL) == TRUE)
			{
				printf("表为空!\n");
			}
			else
			{
				printf("表非空!\n");
			}

			getchar();	
			break;
		
		case 9:			/*销毁整表*/
			DestroyList(&pL);
			printf("表已删除!\n");

			getchar();	
			break;
		
//		case 10:		/*合并链表*/
//			{
//				SQLIST La;
//				size_t i = 0;
//				InitList(&La);
//				srand((int)time(NULL));
//				for (i=1; i<=10; ++i)
//				{
//					InsertList(&La, i, rand()%15);
//				}
//				printf("待求并集的表为: ");
//				TraveList(&La);
//				UnionList(&pL, &La);
//
//				DestroyList(&La);/*避免内存泄漏*/
//				printf("操作完成!\n");
//
//				getchar();
//				break;
//			}
//
//		case 11:		/*求前驱结点*/
//			v = InputValue("寻找哪个元素的前驱结点: ");
//			
//			if (OK == PriorELem(&pL, v , &e))
//			{
//				printf("前驱结点元素为: %d", e);
//			}
//			else
//			{
//				printf("未找到!\n");
//			}
//
//			getchar();
//			break;
//			
//		case 12:	/*求后去结点*/
//			v = InputValue("寻找哪个元素的后驱结点: ");
//			
//			if (OK == NextELem(&pL, v , &e))
//			{
//				printf("后驱结点元素为: %d", e);
//			}
//			else
//			{
//				printf("未找到!\n");
//			}
//			
//			getchar();
//			break;
//			
		default:
			printf("请重新选择!\n");
			
			getchar();
			break;
		}/*switch_@1*/

	}	/*while_@1*/
	
	return EXIT_SUCCESS;
}