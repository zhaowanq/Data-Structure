/****************************************************
 *											                            *
 * 文件夹： 06_Tree_and_BinTree/03_Tri_BinaryTree	  *
 *											                            *
 * 文件名：	Tri_BinaryTree-main.c			              *
 *											                            *
 * 内  容：	二叉树（三叉链表存储）相关函数测试      *
 *											                            *
 ****************************************************/
 
#include "Tri_BinaryTree.c"			 			/*06 树和二叉树*/

void PrintElem(TElemType_Tri e);

int main(void)
{
	TBiTree T;
	
	
	printf("函数：初始化空二叉树。测试...\n");
	PressEnter;
	printf("初始化一个空二叉树 T ...\n");
	InitBiTree_Tri(&T);
	printf("二叉树 T 的地址为 0x%x\n", &T);
	printf("\n\n");
	
		
	printf("函数：判断二叉树T是否为空。测试...\n");
	PressEnter;
	BiTreeEmpty_Tri(T) ? printf(" T 为空！\n") : printf(" T 不为空！\n");
	printf("\n\n");
	
	
	printf("函数：按先序序列构造二叉树。测试...\n");
	PressEnter;
	printf("按先序序列创建二叉树 T ...\n");
	FILE *fp;
	printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
	fp = fopen("TestData_T.txt", "r");
	CreateBiTree_Tri(fp, &T);
	fclose(fp);
	printf("\n\n");


	printf("函数：按二叉树的结构打印树。测试...\n");	
	PressEnter;
	printf("按二叉树的结构打印树：T = \n");
	Print_Tri(T);
	printf("\n");
	
	
	printf("函数：获取二叉树长度、深度。测试...\n");	 
	PressEnter;
	printf("T 的长度为：%d，深度为：%d。\n", BiTreeLength_Tri(T), BiTreeDepth_Tri(T));
	printf("\n\n");
	
	
	printf("函数：层序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("层序遍历二叉树 T = ");
	LevelOrderTraverse_Tri(T, PrintElem);
	printf("\n\n\n");
	
	
	printf("函数：先序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("先序遍历二叉树 T = ");
	PreOrderTraverse_Tri(T, PrintElem);
	printf("\n\n\n");
	
	
	printf("函数：中序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("中序遍历二叉树 T = ");
	InOrderTraverse_Tri(T, PrintElem);
	printf("\n\n\n");
	
	
	printf("函数：后序遍历二叉树。测试...\n");	 
	PressEnter;
	printf("后序遍历二叉树 T = ");
	PostOrderTraverse_Tri(T, PrintElem);
	printf("\n\n\n");
	
	
	printf("函数：返回二叉树的根结点值。测试...\n");	 
	PressEnter;
	TElemType_Tri e;
	Root_Tri(T, &e);
	printf(" T 的根结点为：%c \n", e);
	printf("\n\n");
	
	
	printf("函数：返回某结点的值，p为结点指针。测试...\n");	 
	PressEnter;
	TBiTree p = T->lchild->rchild->lchild;
	printf("指针 p 指向的结点值为 %c \n", Value_Tri(p));
	printf("\n\n");
	
	
	printf("函数：为某结点赋值，p为结点指针。测试...\n");	 
	PressEnter;
	{TBiTree p = T->lchild->rchild->lchild;}
	Assign_Tri(p, 'X');
	printf("将 'X' 赋给 p 指向的结点后，T = \n");
	Print_Tri(T);
	printf("\n\n");
	
	
	printf("函数：返回某结点的双亲结点值。测试...\n");	 
	PressEnter;
	printf(" 'X' 结点的双亲为：%c\n", Parent_Tri(T, 'X'));
	printf("\n\n");
	
	
	printf("函数：返回某结点的左、右孩子结点值。测试...\n");	 
	PressEnter;
	printf(" 'E' 的左孩子结点值为：%c ，右孩子结点值为：%c\n", LeftChild_Tri(T, 'E'), RightChild_Tri(T, 'E'));
	printf("\n\n");
	
	
	printf("函数：返回某结点的左兄弟结点值。测试...\n");	 
	PressEnter;
	printf(" 'I' 的左兄弟为：%c \n", LeftSibling_Tri(T, 'I'));
	printf("\n\n");
	
	
	printf("函数：返回某结点的右兄弟结点值。测试...\n");	 
	PressEnter;
	printf(" 'X' 的右兄弟为：%c \n", RightSibling_Tri(T, 'X'));
	printf("\n\n");
	
	
	
	printf("函数：将树T0插入到树T中成为结点e的子树，LR为插入标记。测试...\n");	 
	PressEnter;
	{
		FILE *fp;
		TBiTree T0;
		
		printf("创建并打印二叉树 T0 = \n");
		InitBiTree_Tri(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateBiTree_Tri(fp, &T0);
		fclose(fp);
		Print_Tri(T0);
		printf("将 T0 插入到 T 中成为结点‘E’的左子树后，T = \n");
		InsertBiTree_Tri(T, 'E', &T0, 0);
		Print_Tri(T);
		printf("\n\n\n");
	}
	
	
	printf("函数：删除e结点的左子树或右子树，LR为删除标记。测试...\n");	 
	PressEnter;	
	printf("删除结点 '1' 的右孩子结点后，T = \n");
	DeleteBiTree_Tri(T, '1', 1);
	Print_Tri(T);
	printf("\n\n\n");
	
	
	printf("函数：清空二叉树T。测试...\n");	 
	PressEnter;
	ClearBiTree_Tri(&T);
	if(BiTreeEmpty_Tri(T))
		printf(" T 已被清空!\n");
	printf("\n\n");
	
	return 0;
}

void PrintElem(TElemType_Tri e)
{
	printf("%c ", e);
}
