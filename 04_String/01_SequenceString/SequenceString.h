/****************************************
 *								                      *
 * 文件夹：04_String/01_SequenceString  *
 *								                      *
 * 文件名：SequenceString.h		          *
 *								                      *
 * 内  容：顺序串相关操作列表	          *
 *								                      *
 ****************************************/

#ifndef SEQUENCESTRING_H
#define SEQUENCESTRING_H

#include <stdio.h>
#include <string.h>						//提供strlen原型 
#include "../../01_Preface/Status.h"		/*01 绪论*/

/* 宏定义 */
#define MAXSTRLEN 255					//顺序串的最大串长

/* 串的顺序存储类型定义 */
typedef unsigned char SString[MAXSTRLEN + 1]; 	//0号单元存放串的长度
 
/* 顺序串函数列表 */
/*(01)生成一个其值等于常量chars的串T（串赋值）。*/
Status StrAssign_Sq(SString T, const char *chars);

/*(02)由串S复制得到串T。*/
void StrCopy_Sq(SString T, SString S);

/*(03)若S为空串，返回TRUE，否则返回FALSE。*/
Status StrEmpty_Sq(SString S);

/*(04)若S>T，返回值>0；若S<T，返回值<0；否则，返回值=0。*/
int StrCompare_Sq(SString S, SString T);

/*(05)求串长。*/
int StrLength_Sq(SString S);

/*(06)清空S。*/ 
void ClearString_Sq(SString S);

/*(07)算法4.2：用T返回有S1和S2联接而成的新串。*/
Status Concat_Sq(SString T, SString S1, SString S2);

/*(08)算法4.3：用Sub返回串S的第pos个字符起长度为len的子串。*/
Status SubString_Sq(SString Sub, SString S, int pos, int len);

/*(09-1)算法4.1：返回T在S中第pos个字符后第一次出现的位置，不存在则返回0。*/
int Index_Sq_1(SString S, SString T, int pos);

/*(09-2)算法4.5：返回T在S中第pos个字符后第一次出现的位置，不存在则返回0。*/
int Index_Sq_2(SString S, SString T, int pos);

/*(10)用V替换主串S中出现的所有与T相等的不重叠的子串，可以被完全替换才返回OK。*/
Status Replace_Sq(SString S, SString T, SString V);

/*(11)在串S的第pos个字符之前插入串T。可以完全插入返回OK，否则返回ERROR。*/
Status StrInsert_Sq(SString S, int pos, SString T);

/*(12)从串S中删除第pos个字符起长度为len的子串。*/
Status StrDelete_Sq(SString S, int pos, int len);

/*(13)销毁串S。*/
void DestroyString_Sq(SString S);

/*(14)输出串S。*/
void StrPrint_Sq(SString S);
 
#endif
