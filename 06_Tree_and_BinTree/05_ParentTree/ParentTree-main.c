/**********************************************
 *						                                *
 * 文件夹: 06_Tree_and_BinTree/05_ParentTree  *
 *						                                *
 * 文件名: ParentTree-main.c                  *
 * 										                        *
 * 内  容: 树的双亲表示法相关函数测试         *
 *                                            *
 **********************************************/

#include <stdio.h>
#include "ParentTree.c" 									/* 06_Tree_and_BinTree */

void PrintElem(TElemType_P e);

int main(int argc, char *argv[])
{
  PTree T, T0;

  printf("函数： InitTree_P 测试...\n");
  PressEnter;
  InitTree_P(&T);
  printf("初始化空树 T ，根结点位置默认设为 0 ...\n");
	printf("\n\n");


  printf("函数： TreeEmpty_P 测试...\n");
  PressEnter;
  TreeEmpty_P(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
	printf("\n\n");


  printf("函数： CreateTree_P 测试...\n");
  PressEnter;
  FILE *fp;	
  fp = fopen("TestData_T.txt", "r");
  CreateTree_P(fp, &T);
  fclose(fp);
  printf("\n");
  printf("树 T (双亲表示法)的地址为 0x%x\n", &T);
  printf("\n\n");


  printf("函数： LevelOrderTraverse_P 测试...\n");
  PressEnter;
  printf("层序遍历树 T = ");
  LevelOrderTraverse_P(T, PrintElem); 
  printf("\n\n");


  printf("函数： Print_P 测试...\n");
  PressEnter;
  printf("打印树 T = \n");
  Print_P(T); 
  printf("\n");


  printf("函数： TreeDegree_P 测试...\n");
  PressEnter;
  printf(" T 的度为：%d\n", TreeDegree_P(T)); 
	printf("\n");


  printf("函数： TreeDepth_P 测试...\n");
  PressEnter;
  printf(" T 共有 %d 层\n", TreeDepth_P(T)); 
	printf("\n");


  printf("函数： Root_P 测试...\n");
  PressEnter;
  printf(" T 的根结点为：%c \n", Root_P(T)); 
	printf("\n");


  printf("函数： Value_P 测试...\n");
  PressEnter;
  printf(" T 中第 %d 个结点值为：%c \n", 2, Value_P(T, 2)); 
	printf("\n");


  printf("函数： Order_P 测试...\n");
  PressEnter;
  printf(" T 中元素 %c 的位置为：%d\n", 'A', Order_P(T, 'A')); 
	printf("\n");


  printf("函数： Assign_P 测试...\n");
  PressEnter;
  printf("将结点 'B' 赋值为 'X' 后，T = \n");
	Assign_P(&T, 'B', 'X');
	Print_P(T);
	printf("\n");


  printf("函数： ChildValue_P 测试...\n");
  PressEnter;
  printf(" %c 的第 %d 个孩子为：%c \n", 'A', 2, ChildValue_P(T, 'A', 2)); 
	printf("\n");


  printf("函数： Sibling_P 测试...\n");
  PressEnter;
  printf(" %c 的左兄弟为：%c，%c 的右兄弟为：%c \n", 'E', Sibling_P(T, 'E', 0), 'D', Sibling_P(T, 'D', 1));
	printf("\n");


  printf("函数： InsertTree_P 测试...\n");    //14、15、16、17.函数ChildCount_P、ChildSeat_P、InsertChild_P、InsertTree_P测试
  PressEnter;
  {
		FILE *fp;
		
		printf("创建并打印树 T0 ...\n");
		InitTree_P(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateTree_P(fp, &T0);
		fclose(fp);	
		Print_P(T0);
		printf("将树 T0 插入为树 T 中结点 %c 的第 %d 棵子树后，T = \n", 'X', 1);
		InsertTree_P(&T, 'X', 1, T0);
		Print_P(T);
		printf("\n");
	}


  printf("函数： DeleteTree_P 测试...\n");
  PressEnter;
  {
		printf("删除 T 中结点 %c 的第 %d 棵子树后，T = \n", '0', 3);
		DeleteTree_P(&T, '0', 3);
		Print_P(T);	
		printf("\n");
	}


  printf("函数： ClearTree_P 测试...\n");
  PressEnter;
  {
		ClearTree_P(&T);
		TreeEmpty_P(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
		printf("\n");
	}
  
  return 0;
}

void PrintElem(TElemType_P e)
{
	printf("%c ",e);
}
