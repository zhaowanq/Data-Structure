/****************************
 *                          *
 * 文件夹: 09_Searching     *
 *                          *
 * 文件名: B-Tree.h         *
 *                          *
 * 内  容: B树相关操作列表  *
 *                          *
 ****************************/

#ifndef B_TREE_H
#define B_TREE_H

#include <stdlib.h>
#include <math.h>							          //提供ceil原型 
#include "../00_Base/Base.c" 	          /* 09_Searching */

/* 宏定义 */
#define M 3                             // B树的阶，暂设为3
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a) < (b))

/* 类型定义 */
typedef ElemType_Search BTElemType;     // B树元素类型
typedef struct BTNode                   // B树存储表示
{
  int keynum;                           // 结点中关键字个数
  struct BTNode* parent;                // 指向双亲结点
  // Record *recptr[m+1];               // 记录指针向量，0号单元未用
  KeyType key[M+1];                     // 关键字向量，0号单元未用
  struct BTNode* ptr[M+1];              // 子树指针向量
}BTNode;                                // B树结点
typedef BTNode* BTree;                  // 指向B树结点的指针

/* B树的查找结果类型 */
typedef struct
{
  BTree pt;                             // 指向找到的结点
  int i;                                // 1...m, 关键字在结点中的序号（插入位置）
  int tag;                              // 1:查找成功, 0:查找失败
}Result;

/* B树函数列表 */
/*(01)创建B树。*/
Status CreateBTree(BTree *BT, Table T);

/*(02)算法9.13：查找，返回查找信息。*/
Result SearchBTree(BTree BT, KeyType K);

/*(03)返回K在结点p中的次序，若不存在，返回0。*/
int Search(BTree p, KeyType K);

/*(04)将关键字K插入B树。*/
Status InsertKey(BTree *BT, KeyType K);

/*(05)算法9.14：插入，在结点*q的key[i]和key[i+1]之间插入关键字K。*/
Status InsertBTree(BTree *BT, KeyType K, BTree q, int i);

/*(06)将x和ap分别插入到q->key[i+1]和q->ptr[i+1]。*/
void Insert(BTree q, KeyType i, KeyType x, BTree ap);

/*(07)以s为界，将q指向的结点分裂成q和ap指向的两部分。*/
void split(BTree q, int s, BTree *ap);

/*(08)生成含信息(BT,x,ap)的新的根结点*BT，原BT和ap为子树指针，q初值为NULL。*/
void NewRoot(BTree *BT, BTree q, int x, BTree ap);

/*(09)从B树中删除关键字K。*/
Status DeleteKey(BTree *BT, KeyType K);

/*(10)从B树中删除结点q中第i个关键字。*/
Status DeleteBTree(BTree *BT, BTree q, int i);

/*(11)从B树中删除结点q中第i个关键字(特殊)。*/
void Delete(BTree *BT, BTree q, int i);

/*(12)找出BT中最小的关键字。*/
Status SearchMinKey(BTree BT, Result *R);

/*(13)寻找双亲结点：q为p的第j个孩子。*/
Status FoundParent(BTree q, BTree *p, int *order);

/*(14)向左移动关键字和指针。*/
Status LeftMove(BTree old_ptr, int m, BTree new_ptr, int n, int len);

/*(15)向右移动关键字和指针。*/
Status RightMove(BTree old_ptr, int m, BTree new_ptr, int n, int len);

/*(16)层序输出B树。*/
void PrintBT_Level(BTree BT);

/*(17)中序输出B树。*/
void PrintBT_InOrder(BTree BT);

#endif
