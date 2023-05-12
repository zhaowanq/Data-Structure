/**************************************
 *								                    *
 * 文件夹：04_String/02_HeapString		*
 *								                    *
 * 文件名：HeapString-main.c	        *
 *								                    *
 * 内  容：堆串相关函数测试		        *
 *								                    *
 **************************************/
 
#include "HeapString.c"				/*04 串*/

int main(void)
{	
	char *chars = "abcdefg";
	char *t = "***";
	char *v = "^^^^";
	HString S, Tmp, T, V, Sub;
	int i;
	
	
	printf("函数：初始化堆串为空串。测试...\n");
	PressEnter;
	printf("初始化空串Tmp...\n");
	InitString_H(&Tmp);
	printf("堆串Tmp的地址为0x%x\n",&Tmp);
	printf("\n\n");
	
	
	printf("函数：生成一个其值等于常量chars的串T。测试...\n");
	PressEnter;
	printf("为 Tmp 赋值 %s ...\n", chars);
	StrAssign_H(&Tmp, chars);			//用debug查看内存单元，判断结果是否正确 
	printf("\n\n");
	
	
	printf("函数：判断堆串是否为空串。测试...\n");
	PressEnter;
	StrEmpty_H(Tmp) ? printf("Tmp 为空！！\n") : printf("Tmp 不为空！\n");
	printf("\n\n");
	
	
	printf("函数：求串长。测试...\n");
	PressEnter;
	i = StrLength_H(Tmp);
	printf("Tmp 的长度为 %d \n", i);
	printf("\n\n");
	
	
	printf("函数：输出串。测试...\n");
	PressEnter;
	printf("Tmp 中的元素为：Tmp = ");
	StrPrint_H(Tmp);
	printf("\n\n\n");
	
	
	printf("函数：由串S复制得到串T。测试...\n");
	PressEnter;
	printf("复制 Tmp 到 S ...\n");
	StrCopy_H(&S, Tmp);
	printf("S 中的元素为：S = ");
	StrPrint_H(S);
	printf("\n\n\n");
	
	
	printf("函数：比较字符串Tmp和S。测试...\n");
	PressEnter;
	i = StrCompare_H(Tmp, S);
	i==0 ? printf("Tmp==S！！\n") : (i<0 ? printf("Tmp<S！！\n") : printf("Tmp>S！！\n"));
	printf("\n\n");
	
	
	printf("函数：在串S的第pos个字符之前插入串T。测试...\n");
	PressEnter;
	printf("将\"***\" 赋给 T ...\n");
	StrAssign_H(&T, t);
	printf("在 S 的第 5 个字符前插入 T ...\n");
	StrInsert_H(&S, 5, T);
	printf("S 中的元素为：S = ");
	StrPrint_H(S);
	printf("\n\n\n");
	
	
	printf("函数：返回T在S中从第pos个字符算起的第一次出现的位置。测试...\n");
	PressEnter;
	printf("获取字符串 \"***\" 在 S 中从第 1 个字符算起的第一次出现的位置...\n");
	i = Index_H(S, T, 1);
	printf("\"***\" 在 S 中第1个字符后第一次出现的位置为 %d \n", i);
	printf("\n\n");
	
	
	printf("函数：用Sub返回串S的第pos个字符起长度为len的子串。测试...\n");
	PressEnter;
	printf("用 Sub 返回 S 中第 5 个字符起的 3 个字符...\n");
	SubString_H(&Sub, S, 5, 3);
	printf("Sub 中的元素为：Sub = ");
	StrPrint_H(Sub);
	printf("\n\n\n"); 
	
	
	printf("函数：用V替换主串S中出现的所有与T相等的不重叠的子串。测试...\n");
	PressEnter;
	printf("将 \"^^^^\" 赋给 V ...\n");
	StrAssign_H(&V, v);
	printf("用 \"^^^^\" 替换 S 中的 \"***\" ...\n");
	Replace_H(&S, T, V);
	printf("S 中的元素为：S = ");						 
	StrPrint_H(S);
	printf("\n\n\n"); 
	

	printf("函数：从串S中删除第pos个字符起长度为len的子串。测试...\n");
	PressEnter;
	printf("删除 S 中第 5 个字符起的 4 个字符...\n");
	StrDelete_H(&S, 5 ,4);
	printf("S 中的元素为：S = ");						 
	StrPrint_H(S);
	printf("\n\n\n");
	
	
	printf("函数：清空S。测试...\n");
	PressEnter;
	printf("清空 S 前：");
	StrEmpty_H(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	ClearString_H(&S);
	printf("清空 S 后：");
	StrEmpty_H(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	printf("\n\n");
	
	
	printf("函数：用T返回由S1和S2联接而成的新串。测试...\n");
	PressEnter;
	printf("联接 T 和 V 形成Tmp...\n");
	Concat_H(&Tmp, T, V);
	printf("Tmp 中的元素为：Tmp = ");						 
	StrPrint_H(Tmp);
	printf("\n\n");
	
	return 0;
}
