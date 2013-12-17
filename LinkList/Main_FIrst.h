/**********************
**程序需要的一些数据定义
***********************/

#ifndef MAIN_FIRST_H
#define MAIN_FIRST_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stddef.h>	/*size_t*/

/*真假*/
typedef enum Bool
{
	FALSE = 0,	/*假*/ 
	TRUE = 1	/*真*/

} BOOL;


/*状态*/
typedef enum Status
{
	FAILE = 0,	/*失败*/
	OK = 1,		/*成功*/	
	ERROR = -1	/*错误*/

}STATUS;

#endif
