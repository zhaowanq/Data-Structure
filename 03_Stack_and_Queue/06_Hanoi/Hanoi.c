/****************************************
 *                                      *
 * 文件夹：03_Stack_and_Queue/06_Hanoi  *
 *                                      *
 * 文件名：Hanoi.c                      *
 *                                      *
 * 内容：算法3.5		                    *
 *                                      * 
 ****************************************/
 
#ifndef HANOI_C 
#define HANOI_C

#include "Hanoi.h"		/*03 栈和队列*/
 
/*(01)算法3.5：汉诺塔求解。以y为辅助，将x上前n个圆盘移动到z。*/
void hanoi(int n, char x, char y, char z)
{
	// 将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘按规则搬到
	// 塔座z上，y可用作辅助塔座。
	// 搬动操作move(x, n, z)可定义为（c是初值为0的全局变量，对搬动计数）
	
	
	
	if(n == 1)
		move(x, 1, z);	//将编号为1的圆盘从x移到z
	else
	{
		hanoi(n-1, x, z, y);	//将x上编号为1至n-1的圆盘移到y，z作辅助塔
		move(x, n, z);	//将编号为n的圆盘从x移到z
		hanoi(n-1, y, x, z);	//将y上编号为1至n-1的圆盘移到z，x作辅助塔 
	} 
}


/*(02)将第n个圆盘从x移到z。*/
void move(char x, int n, char z)
{
	printf("第%2d步：将第 %d 个圆盘从 %c 移到 %c \n",++gStep, n, x, z);
} 

#endif
