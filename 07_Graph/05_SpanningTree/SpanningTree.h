/**************************************
 *                                    *
 * 文件夹: 07_Graph/05_SpanningTree   *
 *                                    *
 * 文件名: SpanningTree.h             *
 *                                    *
 * 内  容: 无向图生成树相关操作列表   *
 *                                    *
 **************************************/

#ifndef SPANNINGTREE_H
#define SPANNINGTREE_H

#include <stdlib.h>											//提供malloc、realloc、free、exit原型
#include "../01_MGraph/MGraph.c"				    /* 07_Graph */
#include "../../06_Tree_and_BinTree/07_ChildSiblingTree/ChildSiblingTree.c"   /* 06_Tree_and_BinTree */

/* 无向图生成树函数列表 */
/*(01)算法7.7：创建无向图的生成树（森林）。*/
void DFSForest(MGraph G, CSTree *T);

/*(02)算法7.8：生成结点v起始的树（森林）。*/
void DFSTree(MGraph G, int v, CSTree *T);

#endif
