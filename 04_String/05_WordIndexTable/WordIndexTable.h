/****************************************
 *									                    *
 * 文件夹: 04_String/05_WordIndexTable  *
 *									                    *
 * 文件名: WordIndexTable.h			        *
 *									                    *
 * 内  容: 创建索引表相关操作列表	      *
 *                                      *
 ****************************************/
 
#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#include <stdio.h>					//提供fopen、fclose、feof、fgets原型
#include <stdlib.h>					//提供exit、strtol、system原型
#include <string.h>					//提供strlen、strcmpi、strlwr原型
#include "../../01_Preface/Status.h"										/*01 绪论*/
#include "../../02_LinearList/09_ExtenLinkedList/ExtenLinkedList.c"			/*02 线性表*/
#include "../02_HeapString/HeapString.c"								/*04 串*/

/* 宏定义 */
#define MaxBookNum 1000				//假设只对1000本书建索引表 
#define MaxKeyNum  2500				//关键词索引表最大容量
#define MaxLineLen 500				//书目串的最大长度。例如："005  Computer Data Structures" 就是一个书目串，长度是29。 
#define MaxWordNum 10				//词表的最大容量

/* 类型定义 */
typedef Status Bool;
typedef struct						//词表类型（顺序表） 			例如：{{"computer","data","structures"},3} 就是一个词表。 
{
	char *str[MaxWordNum];			//字符串数组
	int last;						//词表的长度 
}WordListType;
typedef struct						//索引项类型		例如：{"data",{005,010,023}} 就是一个索引项。 
{
	HString key;					//索引关键词
	ELinkList bnolist;				//存放书号索引的链表 
}IdxTermType;
typedef struct						//索引表类型（有序表），由索引项构成。例如：{{{"computer",{005,034}},{"data",{005,010,023}}},2} 
{
	IdxTermType item[MaxKeyNum+1];	//索引表
	int num;						//索引表中包含的索引项数目 
}IdxListType;

/* 全局变量 */
char gBuf[MaxLineLen];				//书目串缓冲区，例如："005  Computer Data Structures" 就是一个书目串。 
WordListType gWordList = {{"a","an","the","of","and","is","to","as","in","for"},10};	//常用词词表 
WordListType gWdList;				//关键词词表（普通词表）

/* 创建索引表函数列表 */
/*(01)算法4.9：读取书目文件，并创建相应的关键词索引表到另一文件。*/
void Main(char *bookinfo, char *bookidx);

/*(02)初始化索引表，且在idxlist.item[0]设置一表头。*/
void InitIdxList(IdxListType *idxlist); 

/*(03)从文件f中读取一条书目信息存入书目缓冲区gBuf。*/
void GetLine(FILE *f);

/*(04)从gBuf中提取书名关键词到词表gWdList，书号存入bno。*/
void ExtractKeyWord(int *bno);

/*(05)算法4.10：将书号bno对应的书名关键词按词典顺序插入索引表idxlist。*/
Status InsIdxList(IdxListType *idxlist, int bno);

/*(06)将生成的索引表idxlist输出到文件g。*/
void PutText(FILE *g, IdxListType idxlist);

/*(07)算法4.11：用wd返回词表gWdList中第i个关键词。*/
void GetWord(int i, HString *wd);

/*(08)算法4.12：查询在索引表idxlist中是否存在与wd相等的关键词。 
	  若存在，则返回wd在词表中的位置，并置b为TRUE，否则返回wd应插入的位置并置b为FALSE。*/
int Locate(IdxListType idxlist, HString wd, Bool *b); 

/*(09)算法4.13：在索引表第i项插入关键词wd，并初始化书号索引的链表为空表。*/
void InsertNewKey(IdxListType *idxlist, int i, HString wd);

/*(10)算法4.14：在索引表的第i项中插入书号为bno的索引。*/
Status InsertBook(IdxListType *idxlist, int i, int bno);

/*(11)判断S包含的关键词是否为常用词。*/
Status isCommonWords(HString S);
 
#endif
 
