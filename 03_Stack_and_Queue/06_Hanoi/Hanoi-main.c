/****************************************
 *                                      *
 * 文件夹：03_Stack_and_Queue/06_Hanoi  *
 *                                      *
 * 文件名：Hanoi.c                      *
 *                                      *
 * 内容：汉诺塔相关函数测试             *
 *                                      * 
 ****************************************/
 
#include <stdio.h>
#include "Hanoi.c"		/*03 栈和队列*/

int main(void)
{
	int n = 3; 
	printf("作为示例，假设圆盘个数为 %d ，操作步骤如下...\n", n);
	hanoi(n,'x', 'y', 'z');
	
	return 0;
}
