/**********************************************
 *							    	                        *
 * 文件夹: 03_Stack_and_Queue/02_Conversion   *
 * 							    	                        *
 * 文件名: Conversion-main.c       	          *
 * 							    	                        *
 * 内  容: 进制转换函数测试		 	              *
 *                              	            *
 **********************************************/
 
#include <stdio.h>
#include "Conversion.c"

int main(void)
{
	int i = 1348;
	
	printf("将十进制数转换为八进制数。测试...\n");
	
	conversion(i);
	
	printf("\n\n");	
}
 
