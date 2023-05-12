/**********************************
 *                                *
 * 文件夹: 09_Searching           *
 *                                *
 * 文件名: BinarySortTree.c       *
 *                                *
 * 算  法: 9.5、9.6、9.7、9.8     *
 *                                *
 **********************************/

#ifndef BINARYSORTTREE_C
#define BINARYSORTTREE_C

#include "BinarySortTree.h"           /* 09_Searching */

/*(01)创建二叉排序树。*/
Status CreateBSTree(BSTree *BST, Table T)
{
  int i;

  *BST = NULL;

  if(T.length)
  {
    for(i=1; i<=T.length; i++)
      InsertBST(BST, T.elem[i]);
  }

  return OK;
}

/*(02)算法9.5(a)：查找，返回指向key的指针，若不存在返回MULL。*/
BSTree SearchBST_1(BSTree BST, KeyType key)
{
  if(!BST || EQ(key, BST->data.key))
    return BST;
  else if(LT(key, BST->data.key))
    return SearchBST_1(BST->lchild, key);
  else 
    return SearchBST_1(BST->rchild, key);
}

/*(03)算法9.5(b)：查找，若不存在key，则插入到正确的位置。*/
Status SearchBST_2(BSTree BST, KeyType key, BSTree f, BSTree *p)
{
  // 在根指针BST所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找成功，
  // 则指针p指向该数据元素结点，并返回TRUE，否则指针p指向查找路径上访问的
  // 最后一个结点并返回FALSE，指针f指向BST的双亲，其初始调用值为NULL
  
  if(!BST)
  {
    *p = f;
    return FALSE;
  }
  else if(EQ(key, BST->data.key))
  {
    *p = BST;
    return TRUE;
  }
  else if(LT(key, BST->data.key))
    return SearchBST_2(BST->lchild, key, BST, p);
  else
    return SearchBST_2(BST->rchild, key, BST, p);
}

/*(04)算法9.6：插入e到二叉排序树。*/
Status InsertBST(BSTree *BST, BSTElemType e)
{
  // 当二叉排序树BST中不存在关键字等于e.key的数据元素时，插入e并返回TRUE，
  // 否则返回FALSE
  BSTree p, s;

  if(!SearchBST_2(*BST, e.key, NULL, &p))     // 查找不成功
  {
    s = (BSTree)malloc(sizeof(BSTNode));
    s->data = e;
    s->lchild = s->rchild = NULL;

    if(!p)
      *BST = s;           // 被插结点*s为新的根结点
    else if(LT(e.key, p->data.key))
      p->lchild = s;      // 被插结点*s为左孩子
    else
      p->rchild = s;      // 被插结点*s为右孩子
    
    return TRUE;          // 插入e.key
  }
  else
    return FALSE;         // 树中已有关键字相同的结点，不再插入
}

/*(05)中序遍历二叉排序树，生成关键字序列。*/
void InOrderTraverse_BST(BSTree BST, void(Visit)(ElemType_Search))
{
  if(BST)
  {
    InOrderTraverse_BST(BST->lchild, Visit);
    Visit(BST->data);
    InOrderTraverse_BST(BST->rchild, Visit);
  }
}

/*(06)算法9.7：删除。*/
Status DeleteBST(BSTree *BST, KeyType key)
{
  // 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点，
  // 并返回TRUE；否则返回FALSE
  if(!(*BST))             // 不存在与关键字相等的数据元素
    return FALSE;
  else
  {
		if(EQ(key, (*BST)->data.key))
			return Delete(BST);
		else if(LT(key, (*BST)->data.key))
			return DeleteBST(&(*BST)->lchild, key);
		else
			return DeleteBST(&(*BST)->rchild, key);
	}
}

/*(07)算法9.8：删除p指向的结点。*/
Status Delete(BSTree *p)
{
  // 从二叉排序树中删除结点p，并重接它的左或右子树
  BSTree q, s;
  
  if(!(*p)->rchild)       // 右子树空则只需重接它的左子树
  {
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
  else if(!(*p)->lchild)  // 只需重接它的右子树
  {
		q = *p;
		*p = (*p)->rchild;
		free(q);		
	}
  else                    // 左右子树均不空
  {
    q = *p;
		s = (*p)->lchild;

    while(s->rchild)        // 转左，然后向右到尽头，寻找p的直接前驱
    {
			q = s;
			s = s->rchild;
		}

    (*p)->data = s->data;   // s指向被删结点的“前驱”，用p的直接前驱取代p

    if(q!=*p)
      q->rchild = s->lchild;    // 重接*q的右子树 
    else
      q->lchild = s->lchild;    // 重接*q的左子树

    free(s);
  }

  return TRUE;
}

#endif