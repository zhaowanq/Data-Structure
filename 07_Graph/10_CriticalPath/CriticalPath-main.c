/**************************************
 *					                          *
 * 文件夹: 07_Graph/10_CriticalPath   *
 * 					                          *
 * 文件名: CriticalPath-main.c        *
 * 							                      *
 * 内  容: AOE-网关键路径相关函数测试 *
 *                                    *
 **************************************/

#include <stdio.h>
#include "CriticalPath.c" 									    /* 07_Graph */

int main(int argc, char *argv[])
{
	ALGraph G;

	printf("创建并输出有向图(带权)...\n");
	PressEnter;
	{
		FILE *fp;
		
		fp = fopen("TestData_DG_AL.txt", "r");	
		CreateGraph_AL(fp, &G); 
		fclose(fp);
		OutputALGraph(G);
		printf("\n\n");
	}

	printf("函数： CriticalPath等 测试...\n");
  PressEnter;
	printf("输出并标记AOV-网中的关键路径...\n");
	CriticalPath(G);
	printf("\n\n");

	return 0;	
}