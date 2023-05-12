/****************************************
 *								                      *
 * 文件夹：04_String/01_SequenceString  *
 *								                      *
 * 文件名：SequenceString-main.c        *
 *								                      *
 * 内  容：顺序串相关函数测试	          *
 *								                      *
 ****************************************/

#include "SequenceString.c" 		/*04 串*/

int main(void)
{
	char *chars = "abcdefg";
	char *t = "***";
	char *v = "^^^^";
	SString S, Tmp, T, V, Sub;
	int i;
	
	printf("函数：生成一个其值等于串常量chars的串Tmp。测试...\n");
	PressEnter;
	StrAssign_Sq(Tmp, chars);
	printf("串Tmp的地址为0x%x",&Tmp);
	printf("\n\n");
	
	
	printf("函数：判断串Tmp是否为空串。测试...\n");
	PressEnter;
	StrEmpty_Sq(Tmp) ? printf("Tmp 为空！！\n") : printf("Tmp 不为空！\n");
	printf("\n");
	
	
	printf("函数：求串Tmp的长度。测试...\n");
	PressEnter;
	i = StrLength_Sq(Tmp);
	printf("Tmp 的长度为 %d \n", i);
	printf("\n");
	
	
	printf("函数：打印串Tmp。测试...\n");
	PressEnter;
	printf("Tmp 中的元素为：Tmp = ");
	StrPrint_Sq(Tmp); 
	printf("\n\n");
	
	
	printf("函数：复制串Tmp到串S。测试...\n");
	PressEnter;
	StrCopy_Sq(S, Tmp);
	printf("S 中的元素为：S = ");
	StrPrint_Sq(S); 
	printf("\n\n");
	
	/*	与字符串的长度无关。从两个字符串的头开始比，相应位的字符进行对比。实际上是比较相应位字符的ASCII码大小。
		例如：char *s1="abc";char *s2="bd";执行strcmp(s1,s2),其结果是负的，从两个字符串的头开始比,因为字符串s1中的'a'小于s2中的'b'，所以s1<s2。
		再如：char *s1="abc";char *s2="ad";其结果也是负的，因为s1中的'b'<s2中的'd'。
		再如：char *s1="abc";char *s2="ab";其结果就是正的，因为s1中的'c'大于s2中的'\0';因为字符串的最后一个字符是\0。
		再如：char *s1="abc";char *s2="abcd";其结果是负的，因为s1中的'\0'小于s2中的'd'。
	*/
	printf("函数：比较字符串Tmp和S。测试...\n");
	PressEnter;
	i = StrCompare_Sq(Tmp, S);
	i==0 ? printf("Tmp==S！！\n") : (i<0 ? printf("Tmp<S！！\n") : printf("Tmp>S！！\n"));
	printf("\n");
	
	
	printf("函数：在串S的第pos个字符之前插入串T。测试...\n");
	PressEnter;
	printf("将\"***\" 赋给T...\n");
	StrAssign_Sq(T, t);
	printf("在 S 的第5个字符前插入T...\n");
	StrInsert_Sq(S, 5, T);
	printf("S 中的元素为：S = ");
	StrPrint_Sq(S);
	printf("\n\n");
	
	
	printf("算法4.1：返回T在S中第pos个字符后第一次出现的位置。测试...\n");
	PressEnter;
	printf("获取字符串 \"***\" 在 S 中从第1个字符算起的第一次出现的位置...\n");
	i = Index_Sq_1(S, T, 1);
	printf("\"***\" 在 S 中从第1个字符算起的第一次出现的位置为%d\n", i);
	printf("\n");
	
	
	printf("算法4.3：用Sub返回串S的第pos个字符起长度为len的子串。测试...\n");
	PressEnter;
	printf("用 Sub 返回 S 中第 5 个字符起的 3 个字符...\n");
	SubString_Sq(Sub, S, 5, 3);
	printf("Sub 中的元素为：Sub = ");
	StrPrint_Sq(Sub);
	printf("\n\n");
	
	
	printf("函数：用V替换主串S中出现的所有与T相等的不重叠的子串，可以被完全替换才返回OK。测试...\n");
	PressEnter;
	printf("将\"^^^^\" 赋给V...\n");
	StrAssign_Sq(V, v);
	printf("用\"^^^^\" 替换S中的\"***\" ...\n");
	printf("替换之前，S 中的元素为：S = ");
	StrPrint_Sq(S);
	printf("\n");
	Replace_Sq(S, T, V);
	printf("替换之后，S 中的元素为：S = ");
	StrPrint_Sq(S);
	printf("\n\n");
	
	
	printf("函数：从串S中删除第pos个字符起长度为len的子串。测试...\n");
	PressEnter;
	printf("删除 S 中第 5 个字符起的 4 个字符...\n");
	StrDelete_Sq(S, 5, 4);
	printf("S 中的元素为：S = ");
	StrPrint_Sq(S);
	printf("\n\n");
	
	printf("函数：清空S。测试...\n");
	PressEnter;
	printf("清空 S 前：");
	StrEmpty_Sq(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	ClearString_Sq(S);
	printf("清空 S 后：");
	StrEmpty_Sq(S) ? printf("S 为空！！\n") : printf("S 不为空！\n");
	printf("\n");
	
	
	printf("算法4.2：用T返回有S1和S2联接而成的新串。测试...\n");
	PressEnter;
	printf("联接 T 和 V 形成 Tmp ...\n");
	Concat_Sq(Tmp, T, V);
	printf("Tmp 中的元素为：Tmp = ");
	StrPrint_Sq(Tmp);
	printf("\n\n");
	 
	return 0;
} 
