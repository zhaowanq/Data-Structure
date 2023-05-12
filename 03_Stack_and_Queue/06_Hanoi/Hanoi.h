/****************************************
 *                                      *
 * 文件夹：03_Stack_and_Queue/06_Hanoi  *
 *                                      *
 * 文件名：Hanoi.h                      *
 *                                      *
 * 内容：汉诺塔相关操作列表             *
 *                                      * 
 ****************************************/
 
#ifndef HANOI_H
#define HANOI_H

#include <stdio.h>

/* 全局变量 */
int gStep;

/* 汉诺塔函数列表 */
/*(01)算法3.5：汉诺塔求解。以y为辅助，将x上前n个圆盘移动到z。*/
void hanoi(int n, char x, char y, char z);

/*(02)将第n个圆盘从x移到z。*/
void move(char x, int n, char z);

#endif
