/**************************************************
 *										                            *
 * 文件夹: 06_Tree_and_BinTree/01_SeqBinaryTree   *
 * 									                              *
 * 文件名: SeqBinaryTree-main.c                   *
 * 										                            *
 * 内  容: 二叉树顺序存储结构相关函数测试         *
 *                                                *
 **************************************************/
 
#include "SeqBinaryTree.c" 					/*06 树和二叉树*/

void PrintElem(char c);

int main(void)
{
	SqBiTree T;
	
	printf("函数：初始化空二叉树。测试...\n");
	PressEnter;
	printf("初始化空二叉树 T ...\n");
	InitBiTree_Sq(T);
	printf("二叉树 T 的地址为 0x%x\n", &T);
	printf("\n");
	
	
	printf("函数：判断二叉树T是否为空。测试...\n");
	PressEnter;
	BiTreeEmpty_Sq(T) ? printf("T 为空！！\n") : printf("T 不为空！\n");
	printf("\n");
	
	
	printf("函数：按层序序列创建二叉树。测试...\n");	//debug查看测试结果 
	PressEnter;
	FILE *fp;
	printf("按层序序列创建二叉树 T ...\n");
	fp = fopen("TestData_Le.txt", "r");
	CreateBiTree_Le_Sq(fp, T);
	fclose(fp);
	printf("\n\n");


/*
	printf("函数：按先序序列创建二叉树。测试...\n");	 
	PressEnter;
	FILE *fp;
	printf("按先序序列创建二叉树 T ...\n");
	fp = fopen("TestData_Pre.txt", "r");
	CreateBiTree_Pre_Sq(fp, T, 0);		//i从0开始 
	fclose(fp);
	printf("\n\n");
*/	
	
	printf("函数：按二叉树的结构打印树。测试...\n");	 
	PressEnter;
	printf("按二叉树的结构打印树 T ...\n");
	Print_Sq(T);
	printf("\n\n");
	
	
	printf("函数：获取二叉树长度、深度。测试...\n");	 
	PressEnter;
	printf("T 的长度为：%d，深度为：%d。\n", BiTreeLength_Sq(T), BiTreeDepth_Sq(T));
	printf("\n\n");
	
	
	printf("函数：层序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("层序遍历二叉树 T = ");
	LevelOrderTraverse_Sq(T, PrintElem);
	printf("\n\n");
	
	
	printf("函数：前序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("前序遍历二叉树 T = ");
	PreOrderTraverse_Sq(T, PrintElem, 0);
	printf("\n\n");
	
	
	printf("函数：中序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("中序遍历二叉树 T = ");
	InOrderTraverse_Sq(T, PrintElem, 0);
	printf("\n\n");
	
	
	printf("函数：后序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("后序遍历二叉树 T = ");
	PostOrderTraverse_Sq(T, PrintElem, 0);
	printf("\n\n");
	
	
	printf("函数：用e返回二叉树的根。测试...\n");	 
	PressEnter;
	TElemType_Sq r;
	Root_Sq(T, &r);
	printf("T 的根节点为 %c\n", r);
	printf("\n");
	
	
	printf("函数：返回树中某位置的结点值（包含空结点）。测试...\n");	 
	PressEnter;
	Position p = {4,3};					//第4层第3个结点
	printf("T 中第 %d 层第 %d 个结点的值为 %c\n", p.level, p.order, Value_Sq(T, p));
	printf("\n");
	
	
	printf("函数：为树中某位置的结点赋值。测试...\n");	 
	PressEnter;
 	{Position p = {4,3};}				//放入代码块中，不然报变量重复定义
	printf("将第 %d 层第 %d 个结点赋值为 'X' 后，T = \n", p.level, p.order); 
	Assign_Sq(T, p, 'X');
	Print_Sq(T);
	printf("\n\n");
	 
	
	printf("函数：返回某结点的双亲结点值。测试...\n");	 
	PressEnter;
	printf("'X' 结点的双亲为： %c \n", Parent_Sq(T, 'X'));
	printf("\n");
	
	
	printf("函数：返回某结点的左、右孩子结点值。测试...\n");	 
	PressEnter;
	printf("'E' 的左孩子结点值为：%c ，右孩子结点值为：%c\n", LeftChild_Sq(T, 'E'), RightChild_Sq(T, 'E'));
	printf("\n");
	
	
	printf("函数：返回某结点的左兄弟结点值。测试...\n");	 
	PressEnter;
	printf(" 'I' 的左兄弟为：%c\n", LeftSibling_Sq(T, 'I'));
	printf("\n");
	
	
	printf("函数：返回某结点的右兄弟结点值。测试...\n");	 
	PressEnter;
	printf(" 'X' 的右兄弟为：%c\n", RightSibling_Sq(T, 'X'));
	printf("\n");
	
	
	printf("函数：清空二叉树T。测试...\n");	 
	PressEnter;
	ClearBiTree_Sq(T);
	if(BiTreeEmpty_Sq(T))
		printf("T 已被清空！\n");
	printf("\n");
	
	return 0;
}

void PrintElem(char c)
{
	printf("%c ", c);
}
