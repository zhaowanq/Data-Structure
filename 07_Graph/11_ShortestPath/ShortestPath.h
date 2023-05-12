/**************************************
 *						                        *
 * 文件夹: 07_Graph/11_ShortestPath   *
 * 						                        *
 * 文件名: ShortestPath.h             *
 *                                    *
 * 内  容: 最短路径相关操作列表       *
 *                                    *
 **************************************/

#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <stdio.h>
#include "../../01_Preface/Status.h"					/* 01_Preface */
#include "../01_MGraph/MGraph.c" 							/* 07_Graph */

/* 最短路径类型定义 */
typedef int PathMatrix;
typedef int ShortPathTable;

/* 最短路径函数列表 */
/*(01)算法7.15：用Dijkstra算法求有向图G的v0顶点到其余顶点v的最短路径P[v]及其带权长度D[v]。*/
void ShortestPath_DIJ(MGraph G1, int v0, PathMatrix P1[][MAX_VERTEX_NUM+1], ShortPathTable D1[]);

/*(02)输出用Dijkstra算法求出的有向图路径。*/
void OutputPath_DIJ(MGraph G1, int v0, PathMatrix P1[][MAX_VERTEX_NUM+1], ShortPathTable D1[]);

/*(03)另一种写法：计算并输出用Dijkstra算法求出的有向图路径。*/
void Dijkstra(MGraph G1, int v0, PathMatrix path1[], ShortPathTable dist1[]);

/*(04)算法7.16：用Floyd算法求有向图G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w]。动态规划问题。*/  
void ShortestPath_FLOYD(MGraph G2, PathMatrix P2[][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1], ShortPathTable D2[][MAX_VERTEX_NUM+1]);

/*(05)输出用Floyd算法求出的有向图路径。*/
void OutputPath_FLOYD(MGraph G2, PathMatrix P2[][MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1], ShortPathTable D2[][MAX_VERTEX_NUM+1]);

/*(06)另一种写法：计算并输出用Floyd算法求出的有向图路径。*/
void Floyd(MGraph G2, PathMatrix path2[][MAX_VERTEX_NUM+1], ShortPathTable dist2[][MAX_VERTEX_NUM+1]);

#endif