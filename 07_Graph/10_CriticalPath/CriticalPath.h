/**************************************
 *					                          *
 * 文件夹: 07_Graph/10_CriticalPath   *
 * 					                          *
 * 文件名: CriticalPath.h             *
 *                                    *
 * 内  容: AOE-网关键路径相关操作列表 *
 *                                    *
 **************************************/

#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include <stdio.h>
#include "../../01_Preface/Status.h"								/* 01_Preface */
#include "../../03_Stack_and_Queue/01_SequenceStack/SequenceStack.c"	/* 03_Stack_and_Queue */
#include "../02_ALGraph/ALGraph.c" 									/* 07_Graph */

/* 全局变量 */
SqStack T;												// 拓扑序列顶点栈
int ve[MAX_VERTEX_NUM+1];					// 各事件（顶点）的最早发生时间
int vl[MAX_VERTEX_NUM+1];					// 各事件（顶点）的最迟发生时间

/* AOE-网关键路径函数列表 */
/*(01)算法7.13：求有向网拓扑排序，并求各事件最早发生时间。*/
Status TopologicalOrder(ALGraph G, SqStack *T);

/*(02)算法7.14：求有向网关键活动。*/
Status CriticalPath(ALGraph G);

/*(03)对有向图各顶点求入度。*/
void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM+1]);

#endif