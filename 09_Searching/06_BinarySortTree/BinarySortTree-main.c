/**********************************
 *						                    *
 * 文件夹: 09_Searching           *
 * 						                    *
 * 文件名: BinarySortTree-main.c  *
 * 							                  *
 * 内  容: 二叉排序树相关函数测试 *
 *                                *
 **********************************/

#include <stdio.h>
#include "BinarySortTree.c" 								/* 09_Searching */

#define Max 7												// 查找表中元素个数

int main(int argc, char *argv[])
{
  Table T;
  BSTree BST;

  printf("创建并输出一个查找表...\n");
  PressEnter;
  FILE *fp;	
	fp = fopen("TestData_Table.txt", "r");	
  Create(fp, &T, Max);	
  Traverse(T, PrintKey);	
  printf("\n\n");


  printf("函数： CreateBSTree等 测试...\n");
  PressEnter;
  printf("构造二叉排序树，并输出其关键字...\n");
  CreateBSTree(&BST, T);
  printf("二叉排序树 BST 的基址为：0x%x,其根结点的地址为：0x%x\n", &BST, BST);
  printf("二叉排序树 BST 关键字为：");
  InOrderTraverse_BST(BST, PrintKey);
  printf("\n\n");


  printf("函数： SearchBST_1 测试...\n");
  PressEnter;
  printf("关键字 24 ");
  SearchBST_1(BST, 24)==NULL ? printf("不在") : printf("在");
  printf("二叉排序树中！"); 
  printf("\n\n");	


  printf("函数： DeleteBST等 测试...\n");
  PressEnter;
  printf("删除关键字 24 后的关键字序列为：");	
  DeleteBST(&BST, 24);
  InOrderTraverse_BST(BST, PrintKey);
  printf("\n\n");	
  
  return 0;
}