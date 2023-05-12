/*******************************
 *                             *
 * 文件夹: 09_Searching         *
 *                             *
 * 文件名: Base-main.c          *
 *                             *
 * 内  容: 查找表相关函数测试      *
 *                             *
 *******************************/

#include <stdio.h>
#include "Base.c" 									/* 09_Searching */

/* 宏定义 */
#define Max 10										// 查找表中元素个数

// 输出有序表中的关键字和其他域
void Print(ElemType_Search e);
	
int main(int argc, char *argv[])
{
  FILE *fp;
	Table T;

  printf("函数： Create 测试...\n");			
	printf("创建一个查找表...\n");
  PressEnter;
  fp = fopen("TestData_Table.txt", "r");
  Create(fp, &T, Max);
  printf("\n\n");


  printf("函数： Traverse 测试...\n");			
	printf("输出查找表信息...\n");
  PressEnter;
	Traverse(T, Print);	
	printf("\n\n");
  
  
  printf("函数： PrintKey 测试...\n");			
	printf("输出查找表关键字...\n");
  PressEnter;	
	Traverse(T, PrintKey);
  printf("\n\n");

  printf("函数： Destory 测试...\n");			
  printf("销毁有序表...\n");
  PressEnter;
	Destory(&T);
	printf("有序表");
	T.elem==NULL&&T.length==0 ? printf("已被") : printf("未被");
	printf("销毁！\n");		
	printf("\n");
  
  return 0;
}

void Print(ElemType_Search e)
{
	printf("(%3d, %.1f) ", e.key, e.weight);
}
