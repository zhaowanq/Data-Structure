/**********************************
 *						                    *
 * 文件夹: 04_String/04_KMP       *
 * 							                  *
 * 文件名: KMP.h                  *
 * 							                  *
 * 内  容: KMP算法相关操作列表    *
 *                                *
 **********************************/
 
#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include "../01_SequenceString/SequenceString.c"	/*04 串*/

/* KMP算法函数列表 */
/*(01)算法4.6：KMP匹配算法。*/
int Index_KMP(SString S, SString T, int pos, int next[]);

/*(02)算法4.7：求next函数值的算法。*/
void get_next(SString T, int next[]);

/*(03)算法4.8：改进后的求next函数值的算法。*/
void get_nextval(SString T, int nextval[]);

#endif
