/****************************************************
 *							                                    *
 * 文件夹: 06_Tree_and_BinTree/02_BinaryTree        *
 * 							                                    *
 * 文件名: BinaryTree.h                             *
 *    	    				                                *
 * 内  容: 二叉树（二叉链表存储）相关操作列表       *
 *                                                  *
 ****************************************************/
 
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>				
#include <stdlib.h>						//提供malloc、realloc、free、exit原型 
#include <math.h>						//提供pow、log原型 
#include "../../01_Preface/Status.h"		/*01 绪论*/
#include "../../01_Preface/Scanf.c"		/*01 绪论*/

/* 二叉树的二叉链表存储表示 */
typedef char TElemType;					//假设二叉树元素均为字符
typedef struct BiTNode
{
	TElemType data;						//结点元素 
	struct BiTNode* lchild;				//左孩子指针 
	struct BiTNode* rchild;				//右孩子指针 
}BiTNode;								//二叉树结点 
typedef BiTNode* BiTree;				//指向二叉树结点的指针

/* 栈元素类型 */
typedef BiTree SElemType_Sq;			//重新定义栈元素类型
#include "../../03_Stack_and_Queue/01_SequenceStack/SequenceStack.c"	/*03 栈和队列*/

/* 存储当前结点信息 */
/* 在按树结构打印树的时候使用 */
typedef struct
{
	BiTree left;						//当前结点的左指针 
	BiTree right;						//当前结点的右指针 
	int n;								//当前结点的次序 
}Node;

/* 二叉树（二叉链表存储）函数列表 */
/*(01)构造空二叉树T（初始化二叉树）。*/
void InitBiTree(BiTree *T);

/*(02)清空二叉树T。*/
void ClearBiTree(BiTree *T);

/*(03)销毁二叉树T。*/
void DestroyBiTree(BiTree *T);

/*(04)判断二叉树T是否为空。*/
Status BiTreeEmpty(BiTree T);

/*(05)算法6.4：按先序序列构造二叉树。*/
Status CreateBiTree(FILE *fp, BiTree *T);

/*(06)返回二叉树长度（按完全二叉树计算）。*/
int BiTreeLength(BiTree T);

/*(07)返回二叉树深度（层数）。*/
int BiTreeDepth(BiTree T);

/*(08)用e返回二叉树的根结点值。*/
Status Root(BiTree T, TElemType *e);

/*(09)返回某结点的值，p为结点指针。*/
TElemType Value(BiTree p);

/*(10)为某结点赋值，p为结点指针。*/
void Assign(BiTree p, TElemType value);

/*(11)返回某结点的双亲结点值。*/
TElemType Parent(BiTree T, TElemType e);

/*(12)返回某结点的左孩子结点值。*/
TElemType LeftChild(BiTree T, TElemType e);

/*(13)返回某结点的右孩子结点值。*/
TElemType RightChild(BiTree T, TElemType e);

/*(14)返回某结点的左兄弟结点值。*/
TElemType LeftSibling(BiTree T, TElemType e);

/*(15)返回某结点的右兄弟结点值。*/
TElemType RightSibling(BiTree T, TElemType e);

/*(16-1)获取指向结点e的指针。*/
BiTree LocationBiTree_1(BiTree T, TElemType e);

/*(16-2)获取指向结点e的指针。*/
BiTree LocationBiTree_2(BiTree T, TElemType e);

/*(17)将树T0插入到树T中成为结点e的子树，LR为插入标记，T0只有左子树。*/
Status InsertBiTree(BiTree T, TElemType e, BiTree T0, int LR);

/*(18)删除e结点的左子树或右子树，LR为删除标记。*/
Status DeleteBiTree(BiTree T, TElemType e, int LR);

/*(19)层序遍历二叉树。*/
void LevelOrderTraverse(BiTree T, void(Visit)(TElemType));

/*(20-1)先序遍历二叉树。*/
void PreOrderTraverse_1(BiTree T, void(Visit)(TElemType));

/*(20-2)算法6.1：先序遍历二叉树。*/
Status PreOrderTraverse_2(BiTree T, Status(Visit)(TElemType));

/*(21-1)中序遍历二叉树。*/
void InOrderTraverse_1(BiTree T, void(Visit)(TElemType));

/*(21-2)算法6.2：中序遍历二叉树。*/
Status InOrderTraverse_2(BiTree T, Status(Visit)(TElemType));

/*(21-3)算法6.3：中序遍历二叉树。*/
Status InOrderTraverse_3(BiTree T, Status(Visit)(TElemType));

/*(22)后序遍历二叉树。*/
void PostOrderTraverse(BiTree T, void(Visit)(TElemType));

/*(23)按二叉树的结构打印树。*/
void PrintTree(BiTree T);
 
#endif
