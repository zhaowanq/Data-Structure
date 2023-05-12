/******************************************
 *					                              *
 * 文件夹: 07_Graph/09_TopologicalSort    *
 * 					                              *
 * 文件名: TopologicalSort-main.c         *
 * 							                          *
 * 内  容: 有向图拓扑排序相关函数测试     *
 *                                        *
 ******************************************/

#include <stdio.h> 
#include "TopologicalSort.c" 	/* 07_Graph */

int main(int argc, char *argv[])
{
	ALGraph G;

	printf("创建并输出有向图...\n");
  PressEnter; 
  {
		FILE *fp;
		
		fp = fopen("TestData_DG_AL.txt", "r");
		CreateGraph_AL(fp, &G);
		fclose(fp);
		OutputALGraph(G);
		printf("\n\n");
	}

	printf("函数： TopologicalSort等 测试...\n");
  PressEnter;
  int k;
	int Topo[MAX_VERTEX_NUM+1];								// 存储拓扑序列
	printf("对有向图进行拓扑排序...\n");
	if(!TopologicalSort(G, Topo))
		printf("该有向图有回路！！\n");
	else
	{
		printf("该有向图的拓扑序列为：");
		for(k=1; k<=G.vexnum; k++)
			printf("%c ", G.vertices[Topo[k]].data);
	}
  printf("\n\n");

	return 0;
}