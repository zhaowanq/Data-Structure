/****************************************
 *				                              *
 * 文件夹: 07_Graph/07_MiniSpanningTree *
 * 				                              *
 * 文件名: MST-main.c                   *
 *				                              *
 * 内  容: 最小生成树相关函数测试       *
 *				                              *
 ****************************************/

#include <stdio.h>
#include "MST.c" 												/* 07_Graph */

int main(int argc, char *argv[])
{
	MGraph G;

	printf("初始化并输出无向网...\n");
	PressEnter;
	{
		FILE *fp;
		
		fp = fopen("TestData_UDN_M.txt", "r");	
		CreateGraph_M(fp, &G); 
		fclose(fp);
		OutputMGraph(G);
		printf("\n");
	}


	printf("函数： MinSpanTree_PRIM_1等 测试...\n");
	PressEnter;
	printf("普里姆算法...\n");	
	printf("先后加入最小生成树的各结点及其对应的最小边的权值分别为：\n");
	MinSpanTree_PRIM_1(G, 'A');
	printf("\n");


	printf("函数： MinSpanTree_PRIM_2等 测试...\n");
	PressEnter;
	printf("普里姆算法...\n");			
	printf("最小生成树的各边及其对应的权值分别为：\n");	
	MinSpanTree_PRIM_2(G, 'A');
	printf("\n");


	printf("函数： MinSpanTree_KRUSKAL等 测试...\n");			// 5、6、7、8.函数MinSpanTree_KRUSKAL等测试
	PressEnter;
	printf("克鲁斯卡尔算法...\n");	
	printf("最小生成树的各边及其对应的权值分别为：\n");		
	MinSpanTree_KRUSKAL(G);
	printf("\n");

	return 0;
}