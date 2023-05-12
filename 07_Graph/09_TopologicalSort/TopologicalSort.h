/******************************************
 *					                              *
 * 文件夹: 07_Graph/09_TopologicalSort    *
 * 					                              *
 * 文件名: TopologicalSort.h              *
 *                                        *
 * 内  容: 有向图拓扑排序相关操作列表     *
 *                                        *
 ******************************************/

#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <stdio.h>
#include "../../01_Preface/Status.h"								/* 01_Preface */
#include "../../03_Stack_and_Queue/01_SequenceStack/SequenceStack.c"	/* 03_Stack_and_Queue */
#include "../02_ALGraph/ALGraph.c" 								/* 07_Graph */

/* 有向图拓扑排序函数列表 */
/*(01)算法7.12：求有向图拓扑排序。*/
Status TopologicalSort(ALGraph G, int Topo[]);

/*(02)对有向图各顶点求入度。*/
void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM+1]);

#endif