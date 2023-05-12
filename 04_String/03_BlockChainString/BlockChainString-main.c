/******************************************
 *		                						      	*
 * 文件夹：04_String/03_BlockChainString	*
 *								      	                *
 * 文件名：BlockChainString-main.c	 	    *
 *								      	                *
 * 内  容：块链串相关函数测试	      	    *
 *								      	                *
 ******************************************/
 
#include "BlockChainString.c"			/*04 串*/

int main(void)
{
	char *chars = "kuai-lian-chuan";
	char *t = "***";
	char *v = "^^^^";
	LString S, Tmp, T, V, Sub;
	int i;
	char ch;
	
	printf("函数：初始化块链串。测试...\n");
	PressEnter;
	printf("初始化空串 Tmp ...\n");
	InitString_L(&Tmp);
	printf("串 Tmp 的地址为0x%x\n", &Tmp);
	printf("串 Tmp 的头指针为0x%x，尾指针为0x%x\n", Tmp.head, Tmp.tail);
	printf("串 Tmp 的长度为%d\n", Tmp.curlen);
	printf("\n\n");
	
	
	printf("函数：生成一个其值等于常量chars的串T。测试...\n");
	PressEnter;
	printf("为 Tmp 赋值 %s ...\n", chars);
	StrAssign_L(&Tmp, chars);		//用debug查看内存单元，自行判断结果是否正确
	printf("\n\n");
	
	
	printf("函数：若S为空串，返回TRUE，否则返回FALSE。测试...\n");
	PressEnter;
	StrEmpty_L(Tmp) ? printf("Tmp 为空！！\n") : printf("Tmp 不为空！\n");
	printf("\n\n");
	
	
	printf("函数：求串长。测试...\n");
	PressEnter;
	i = StrLength_L(Tmp);
	printf("Tmp 的长度为 %d \n", i);
	printf("\n\n");
	
	
	printf("函数：输出串S。测试...\n");
	PressEnter;
	printf("Tmp 中的元素为：Tmp = ");
	StrPrint_L(Tmp);
	printf("\n\n\n");
	
	
	printf("函数：由串S复制得到串T。测试...\n");
	PressEnter;
	printf("复制 Tmp 到 S ...\n");
	StrCopy_L(&S, Tmp);
	printf("S 中的元素为：S = ");
	StrPrint_L(S);
	printf("\n\n\n");
	
	
	printf("函数：比较字符串Tmp和S。测试...\n");
	PressEnter;
	i = StrCompare_L(Tmp, S);
	i==0 ? printf("Tmp==S！！\n") : (i<0 ? printf("Tmp<S！！\n") : printf("Tmp>S！！\n"));
	printf("\n\n");
	
	
	printf("函数：在串S的第pos个字符之前插入串T。测试...\n");	//参见00 Note\14_块链串插入串操作调试过程.jpg 
	PressEnter;
	printf("将 \"***\" 赋给 T ...\n");
	StrAssign_L(&T, t);
	printf("在 S 的第5个字符前插入 T ...\n");
	StrInsert_L(&S, 5, T);
	printf("S 中的元素为：S = ");						 
	StrPrint_L(S);
	printf("\n\n");
	
	
	
	printf("函数：返回T在S中从第pos个字符算起的第一次出现的位置。测试...\n");
	PressEnter;
	printf("获取字符串 \"***\" 在 S 中从第 1 个字符算起的第一次出现的位置...\n");
	i = Index_L(S, T, 1);
	printf("\"***\" 在 S 中第1个字符后第一次出现的位置为 %d \n", i);
	printf("\n\n");
	
	
	printf("函数：用Sub返回串S的第pos个字符起长度为len的子串。测试...\n");
	PressEnter;
	printf("用 Sub 返回 S 中第 5 个字符起的 3 个字符...\n");
	SubString_L(&Sub, S, 5 ,3);
	printf("Sub 中的元素为：Sub = ");
	StrPrint_L(Sub);
	printf("\n\n\n");
	
	

	printf("函数：用V替换主串S中出现的所有与T相等的不重叠的子串。测试...\n");
	PressEnter;
	printf("将 \"^^^^\" 赋给 V ...\n");
	StrAssign_L(&V, v);
	printf("用 \"^^^^\" 替换 S 中的 \"***\" ...\n");
	Replace_L(&S, T, V);
	printf("S 中的元素为：S = ");						 
	StrPrint_L(S);
	printf("\n\n\n");
	
	
	printf("函数：从串S中删除第pos个字符起长度为len的子串。测试...\n");
	PressEnter;
	printf("删除 S 中第 5 个字符起的 4 个字符...\n");
	StrDelete_L(&S, 5 ,4);
	printf("S 中的元素为：S = ");						 
	StrPrint_L(S);
	printf("\n\n\n");
	
	
	printf("函数：清空S。测试...\n");
	PressEnter;
	printf("清空 S 前：");
	StrEmpty_L(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	ClearString_L(&S);
	printf("清空 S 后：");
	StrEmpty_L(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	printf("\n\n");
	
	
	printf("函数：用T返回由S1和S2联接而成的新串。测试...\n");
	PressEnter;
	printf("联接 T 和 V 形成Tmp...\n");
	Concat_L(&Tmp, T, V);
	printf("Tmp 中的元素为：Tmp = ");						 
	StrPrint_L(Tmp);
	printf("\n\n");
	
	
	printf("函数：获取串 S 中第i个字符。测试...\n");
	PressEnter;
	printf("为串 S 赋值 %s ...\n", chars);
	StrAssign_L(&S, chars);
	printf("获取串 S 中第5个字符...\n");
	GetChar_L(S, &ch, 5);
	printf("串 S 中第5个字符为%c\n", ch);
	printf("\n\n");
		
	return 0;
} 
