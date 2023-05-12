/****************************************************
 *							                                    *
 * 文件夹: 06_Tree_and_BinTree/04_ThreadBinaryTree  *
 *							                                    *
 * 文件名: ThreadBinaryTree.h                       *
 *							                                    *
 * 内  容: 线索二叉树相关操作列表                   *
 *                                                  *
 ****************************************************/
 
#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>							//提供malloc、realloc、free、exit原型
#include "../../01_Preface/Status.h"			/*01 绪论*/
#include "../../01_Preface/Scanf.c"			/*01 绪论*/ 

/* 线索二叉树类型定义 */
typedef char TElemType_Thr;					//假设二叉树元素均为字符	
typedef enum {Link, Thread} PointerTag;		//Link==0：指针；Thread==1：线索
typedef struct ThrBiNode
{
	TElemType_Thr data;
	struct ThrBiNode *lchild;				//左右孩子指针 
	struct ThrBiNode *rchild;
	PointerTag LTag;						//左右标志 
	PointerTag RTag;
	
	struct ThrBiNode *parent;				//双亲结点指针，仅在非递归后序遍历后继线索二叉树时使用 
}ThrBiNode;
typedef ThrBiNode* ThrBiTree;

/*全局变量*/
ThrBiTree pre;								//指向当前访问结点的上一个结点，由于变量作用域的原因，pre需定义为全局变量 

/* 线索二叉树函数列表 */
/*(01)按先序序列构造二叉树，并建立孩子标志(无线索化)。*/
Status CreateBiTree_Thr(FILE *fp, ThrBiTree *T);

/*(02)算法6.7：中序全线索化。*/
void InThreading_Thr(ThrBiTree p);

/*(03)算法6.6：中序遍历二叉树T，并将其全线索化。*/
Status InOrderThreading_Thr(ThrBiTree *Thrt, ThrBiTree T);

/*(04)算法6.5：中序遍历中序全线索二叉树。（非递归算法）。*/
Status InOrderTraverse_Thr(ThrBiTree Thrt, void(Visit)(TElemType_Thr)); 
 
#endif
