/****************************************************
 *							                                    *
 * 文件夹: 06_Tree_and_BinTree/04_ThreadBinaryTree  *
 *							                                    *
 * 文件名: ThreadBinaryTree-main.c                  *
 *							                                    *
 * 内  容: 线索二叉树相关函数测试                   *
 *                                                  *
 ****************************************************/
 
#include "ThreadBinaryTree.c"					/*06 树和二叉树*/

void PrintElem(TElemType_Thr e);

int main(void)
{
	ThrBiTree Thrt1;
	ThrBiTree T1; 
		
	printf("函数：按先序序列构造二叉树，并建立孩子标志(无线索化)。测试...\n");
	PressEnter;
	FILE *fp;
	printf("按先序序列创建二叉树...\n");
	printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
	fp = fopen("TestData_T.txt", "r");
	CreateBiTree_Thr(fp, &T1);
	fclose(fp);
	printf("\n");
	
	
	//线索化过程请自行debug调试 
	printf("函数：中序全线索二叉树。测试...\n");
	PressEnter;
	printf("将 T1 中序全线索化为 Thrt1 ...\n");
	InOrderThreading_Thr(&Thrt1, T1);
	printf("\n");
	
	
	printf("函数：中序遍历中序全线索二叉树。测试...\n");
	PressEnter;
	InOrderTraverse_Thr(Thrt1, PrintElem);
	printf("\n\n");
		 
	return 0;
}

void PrintElem(TElemType_Thr e)
{
	printf("%c ",e);
}
