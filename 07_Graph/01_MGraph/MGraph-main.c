/******************************************************
 *						                                        *
 * 文件夹: 07_Graph/01_MGraph                         *
 * 						                                        *
 * 文件名: MGraph-main.c                              *
 * 							                                      *
 * 内  容: 图、表的数组（邻接矩阵）表示法相关函数测试 *
 *                                                    *
 ******************************************************/

#include <stdio.h>
#include "MGraph.c" 											/* 07_Graph */
#include <time.h>

void PrintElem(char c);

int main(int argc, char *argv[])
{
	MGraph G;
	
	printf("函数： 1、2、3、4、5 测试...\n");
	printf("函数： CreateGraph_M等 测试...\n");	// 1、2、3、4、5.函数CreateGraph_M等测试
	PressEnter;
	{
		FILE *fp;
		int r;
		
		srand((unsigned)time(NULL));							// 用系统时间做随机数种子 
		r = rand()%4;															// 生成随机数
		
		switch(r)
		{
			case DG:
				printf("初始化有向图 G ...\n");
				fp = fopen("TestData_DG_M.txt", "r");
				break;
			case DN:
				printf("初始化有向网 G ...\n");
				fp = fopen("TestData_DN_M.txt", "r");
				break;
			case UDG:
				printf("初始化无向图 G ...\n");
				fp = fopen("TestData_UDG_M.txt", "r");
				break;	
			case UDN:
				printf("初始化无向网 G ...\n");
				fp = fopen("TestData_UDN_M.txt", "r");
				break;				
		}
		CreateGraph_M(fp, &G); 
		fclose(fp);
		printf("\n\n");
	}


	printf("函数： OutputMGraph 测试...\n");
	PressEnter;
	printf("输出图（网）的邻接矩阵 G = \n");
	OutputMGraph(G);
	printf("\n\n");


	printf("函数： LocateVex_M 测试...\n");
	PressEnter;
	printf("顶点 '%c' 的位置为 %d\n", 'C', LocateVex_M(G, 'C'));
	printf("\n\n");


	printf("函数： GetVex_M 测试...\n");
	PressEnter;
	printf("第 %d 个顶点的值为 '%c'\n", 3, GetVex_M(G, 3));
	printf("\n\n");


	printf("函数： FirstAdjVex_M 测试...\n");
	PressEnter;
	printf(" '%c' 的第一个邻接顶点的序号为 %d\n", 'B', FirstAdjVex_M(G, 'B'));
	printf("\n\n");


	printf("函数： NextAdjVex_M 测试...\n");
	PressEnter;
	printf(" '%c' 相对于 '%c' 的下一个邻接顶点序号为 %d\n", 'A', 'B', NextAdjVex_M(G, 'A', 'B'));
	printf("\n\n");


	printf("函数： PutVex_M 测试...\n");
	PressEnter;
	printf("对顶点 '%c' 赋值 '%c' 后，G = \n", 'A', 'X');
	PutVex_M(&G, 'A', 'X');
	OutputMGraph(G);	
	printf("\n\n");


	printf("函数： InsertVex_M 测试...\n");
	PressEnter;
	printf("插入顶点 '%c' 后，G = \n", 'H');
	InsertVex_M(&G, 'H');
	OutputMGraph(G);	
	printf("\n\n");


	printf("函数： InsertArc_M 测试...\n");
	PressEnter;
	printf("顺次插入弧 <%c, %c, 1>、", 'H', 'X');
	printf("<%c, %c, 1>、", 'H', 'C');
	printf("<%c, %c, 1> 后，G = \n", 'D', 'H');
	InsertArc_M(&G, 'H', 'X', 1);
	InsertArc_M(&G, 'H', 'C', 1);
	InsertArc_M(&G, 'D', 'H', 1);
	OutputMGraph(G);	
	printf("\n\n");


	printf("函数： DeleteArc_M 测试...\n");
	PressEnter;
	printf("删除弧 <%c, %c> 后，G = \n", 'H', 'X');
	DeleteArc_M(&G, 'H', 'X');
	OutputMGraph(G);
	printf("\n\n");


	printf("函数： DeleteVex_M 测试...\n");
	PressEnter;
	printf("删除顶点 '%c' 后，G = \n", 'B');
	DeleteVex_M(&G, 'B');
	OutputMGraph(G);
	printf("\n");


	printf("函数： DFSTraverse_M等 测试...\n");
	PressEnter;
	printf("深度优先遍历图（表）G = ");
	DFSTraverse_M(G, PrintElem);
	printf("\n\n");


	printf("函数： BFSTraverse_M 测试...\n");
	PressEnter;
	printf("广度优先遍历图（表）G = ");
	BFSTraverse_M(G, PrintElem);	
	printf("\n\n");


	printf("函数： ClearGraph_M 测试...\n");
	PressEnter;
	printf("清空图（网）G ...\n");
	ClearGraph_M(&G);
	OutputMGraph(G);	
	printf("\n\n");

}


void PrintElem(char c)
{
	printf("%c ", c);
}