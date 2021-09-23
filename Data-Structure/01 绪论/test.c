#include "Status.h"
#include <stdio.h>
#include "Scanf.c" 
int main(void)
{
	int shuzi;
	FILE *fp;
	fp = fopen("TestData.txt", "r");				//文件指针，指向数据源
	Scanf(fp, "%d",&shuzi);
	printf("%d\n",shuzi);	
	return 0;
}
																	