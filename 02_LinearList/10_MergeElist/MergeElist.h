/****************************************
 *							                        *
 * 文件夹: 02_LinearList/10_MergeElist  *
 * 							                        *
 * 文件名: MergeEList.h                 *
 * 							                        *
 * 内  容: 归并扩展的单链表相关操作列表 *
 *                                      *
 ***************************************/
 
#ifndef MERGEELIST_H
#define MERGEELIST_H

#include "../09_ExtenLinkedList/ExtenLinkedList.c"		/*02 线性表*/

/* 归并扩展的单链表函数列表 */
/*(01)算法2.21：La与Lb均非递减排列，将其归并为一个非递减排列的单链表Lc。*/
Status MergeEList_L(ELinkList La, ELinkList Lb, ELinkList *Lc, int(Compare)(LElemType_E c1, LElemType_E c2));

/*(02)比较c1、c2大小，返回c1-c2。*/
int Cmp(LElemType_E c1, LElemType_E c2);

/*(03)按非降序序列创建元素个数为count的扩展单链表L。*/
Status CreateList_ascend(FILE *fp, ELinkList *L, int count);


#endif
