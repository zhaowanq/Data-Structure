/****************************************
 *				                              *
 * 文件夹: 07_Graph/07_MiniSpanningTree *
 * 				                              *
 * 文件名: MST.h                        *
 *                                      *
 * 内  容: 最小生成树相关操作列表       *
 *                                      *
 ****************************************/

#ifndef MST_H
#define MST_H

#include <stdio.h>
#include "../../06_Tree_and_BinTree/08_MFSet/MFSet.c"			/* 06_Tree_and_BinTree */
#include "../01_MGraph/MGraph.c"													/* 07_Graph */

/* 最小生成树类型定义 */
typedef struct
{
	VertexType_M adjvex;				// 较早加入当前边的端点
	VRType lowcost;							// 当前边的权值
}Edge;												// 辅助数组
typedef struct
{
	int a, b;										// 端点
	int w;											// 权值
}EdgeSetType;

/* 最小生成树函数列表 */
/*(01)算法7.9：用普里姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边。*/
void MinSpanTree_PRIM_1(MGraph G, VertexType_M u);

/*(02)返回最小边联接的端点序号。*/
int Minimum_1(Edge closedge[], int n);

/*(03)普里姆算法，与教材算法只在形式上有所区别。*/
void MinSpanTree_PRIM_2(MGraph G, VertexType_M u);

/*(04)返回最小边联接的端点序号。*/
int Minimum_2(MGraph G, int start[], int mark[], int n);

/*(05)用克鲁斯卡尔算法构造网G的最小生成树T，并输出T的各条边。*/
void MinSpanTree_KRUSKAL(MGraph G);

/*(06)按权值从小到大排列各边。*/
void sort(EdgeSetType EdgeSet[], int left, int right);

/*(07)将网中各顶点初始化为一个并查集S。*/
void Initial(MGraph G, MFSet *S);

/*(08)建立一个二元关系R。*/
void BuildRelation(Relation *R, int a, int b);

#endif