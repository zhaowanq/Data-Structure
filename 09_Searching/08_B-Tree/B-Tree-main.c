/******************************
 *						                *
 * 文件夹: 09_Searching       *
 * 						                *
 * 文件名: B-Tree-main.c      *
 * 						                *
 * 内  容: B树相关函数测试    *
 *                            *
 ******************************/

#include <stdio.h>
#include "B-Tree.c" 							/* 09_Searching */

/* 宏定义 */
#define Max 15									// 查找表中元素个数

int main(int argc, char *argv[])
{
  Table T;
	BTree BT;

  printf("创建并输出一个查找表...\n");
  PressEnter; 
  {
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);
		printf("\n\n");
	}

  printf("函数： CreateBTree等 测试...\n");
  PressEnter;
  printf("构造B树...\n");
  CreateBTree(&BT, T);
  printf("\n\n");
  

  printf("函数： PrintBT_InOreder 测试...\n");
  PressEnter;
  printf("中序输出B树关键字：");
  PrintBT_InOrder(BT); 
  printf("\n\n");


  printf("函数： PrintBT_Level 测试...\n");
  PressEnter;
  printf("层序输出B树关键字：\n");
  PrintBT_Level(BT); 
  printf("\n\n");


  printf("函数： DeleteKey等 测试...\n");
  PressEnter;
  int K = 45;
  printf("删除关键字 %d ...\n", K);
  DeleteKey(&BT, K);
  printf("中序输出B树关键字：");
  PrintBT_InOrder(BT);
  printf("\n");
  printf("层序输出B树关键字：\n");
  PrintBT_Level(BT);
  printf("\n\n");


/*  printf("删除关键字 %d ...\n", 21);
  DeleteKey(&BT, 21);
  DeleteKey(&BT, 27);
  DeleteKey(&BT, 32);
  DeleteKey(&BT, 40);
  printf("中序输出B树关键字：");
  PrintBT_InOrder(BT);
  printf("\n");
  printf("层序输出B树关键字：\n");
  PrintBT_Level(BT);*/
  
  return 0;
}