/****************************************
 *								                      *
 * 文件夹：04_String/01_SequenceString  *
 *								                      *
 * 文件名：SequenceString.c		          *
 *								                      *
 * 算  法：4.1、4.2、4.3、4.5   	      *
 *								                      *
 ****************************************/

#ifndef SEQUENCESTRING_C
#define SEQUENCESTRING_C

#include "SequenceString.h"				/*04 串*/

/*(01)生成一个其值等于常量chars的串T（串赋值）。*/
Status StrAssign_Sq(SString T, const char *chars)	//属于最小操作子集 
{
	int i, len;
	
	len = strlen(chars);
	
	if(len>MAXSTRLEN)				//chars过长 
		return ERROR;	
	else
	{
		T[0] = len;
		for(i=1; i<=len; i++)
			T[i] = chars[i-1];		//chars为常量
		return OK;
	}
}

/*(02)由串S复制得到串T。*/
void StrCopy_Sq(SString T, SString S)
{
	int i;
		
	for(i=0; i<=S[0]; i++)
		T[i] = S[i];			 
} 

/*(03)若S为空串，返回TRUE，否则返回FALSE。*/
Status StrEmpty_Sq(SString S)
{
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;	
}

/*(04)若S>T，返回值>0；若S<T，返回值<0；否则，返回值=0。*/
int StrCompare_Sq(SString S, SString T)		//属于最小操作子集
{
	int i = 1;
	
	while(i<=S[0] && i<=T[0])
	{
		if(S[i]==T[i])
			i++;
		else
			return S[i]-T[i];
	}
	
	return S[0]-T[0];
}

/*(05)求串长。*/
int StrLength_Sq(SString S)		//属于最小操作子集
{
	return S[0]; 
} 

/*(06)清空S。*/ 
void ClearString_Sq(SString S)
{
	S[0] = 0;	
}

/*(07)算法4.2：用T返回有S1和S2联接而成的新串。*/
Status Concat_Sq(SString T, SString S1, SString S2)		//属于最小操作子集 
{
	//用T返回由S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE。
	int i;
	
	for(i=1; i<=S1[0]; i++)
		T[i] = S1[i];
	
	if(S1[0]+S2[0]<=MAXSTRLEN) 		//未截断
	{
		for(i=1; i<=S2[0]; i++)
			T[S1[0]+i] = S2[i];
		
		T[0] = S1[0]+S2[0];
		
		return TRUE;
	}
	else 	//截断
	{	
		for(i=1; S1[0]+i<=MAXSTRLEN; i++)
			T[S1[0]+i] = S2[i];
		
		T[0] = MAXSTRLEN;
		
		return FALSE;
	}
}

/*(08)算法4.3：用Sub返回串S的第pos个字符起长度为len的子串。*/
Status SubString_Sq(SString Sub, SString S, int pos, int len)	//属于最小操作子集
{
	int i;
	
	if(pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
		return ERROR;		//输入不合法
		 
	for(i=1; i<=len; i++)
		Sub[i] = S[i+pos-1];
		
	Sub[0] = len;
	
	return OK;
} 

/*(09-1)算法4.1：返回T在S中第pos个字符后第一次出现的位置（包括第pos个字符），不存在则返回0。*/
int Index_Sq_1(SString S, SString T, int pos)	//用到串类型的最小操作子集
{
	int m, n;
	SString Sub;
	
	if(pos > 0)
	{
		n = StrLength_Sq(S);
		m = StrLength_Sq(T);
		
		if(n && m)
		{
			while(pos<=n-m+1)
			{
				SubString_Sq(Sub, S, pos, m);
				if(StrCompare_Sq(Sub,T)!=0)
					pos++;
				else
					return pos;	//返回子串在主串中的位置 
			}
		}
	}
	
	return 0;	//S中不存在与T相等的子串 
}

/*(09-2)算法4.5：返回T在S中第pos个字符后第一次出现的位置（包括第pos个字符），不存在则返回0。*/
int Index_Sq_2(SString S, SString T, int pos)	//不依赖于其他串操作的匹配算法 
{
	int i, j;
	
	i = pos;
	j = 1;
	
	while(i<=S[0] && j<=T[0])
	{
		if(S[i] == T[j])		//继续比较后续字符 
		{
			++i;
			++j;
		}
		else					//指针后退重新开始匹配 
		{
			i = i - (j-1) +1;	//j-1代表 i和j同时徒劳地向前匹配了j-1步 
			j = 1;				//因此，i需要回到原来位置的下一个位置,j回到T的第一个位置 
		}
	}
	
	if(j>T[0] && T[0])			//如果是因为子串的结束而导致while循环的退出，则匹配成功 
		return i-T[0];			
	else
		return 0; 
}

/*(10)用V替换主串S中出现的所有与T相等的不重叠的子串，可以被完全替换才返回OK。*/
Status Replace_Sq(SString S, SString T, SString V)
{
	int i;
	
	i = Index_Sq_2(S, T, 1);						//寻找第一个匹配的位置
	
	while(S[0]-T[0]+V[0]<=MAXSTRLEN && i) 			//有匹配的字符串且可以被完全替换 
	{
		StrDelete_Sq(S, i, T[0]);					//删除T
		StrInsert_Sq(S, i, V); 						//插入V

		i += V[0]; 									//i切换到下一个位置
	 	
	 	i = Index_Sq_2(S, T, i);					//定位下一个匹配的字符串 
	}
	
	if(i==0)										//S中的T已全部被替换 
		return OK;
	else											//S中尚有T，但是V已经插不进去了 
		return ERROR; 
}

/*(11)在串S的第pos个字符之前插入串T。可以完全插入返回OK，否则返回ERROR。*/
Status StrInsert_Sq(SString S, int pos, SString T)
{
	int i;
	
	if(pos<1 || pos>S[0]+1 || S[0]+T[0]>MAXSTRLEN)
		return ERROR;		//插入不合法
	
	//将从第pos个字符到末尾的所有字符依次向后移动串T长度个位置 
	for(i=S[0]; i>=pos; i--)
		S[i+T[0]] = S[i];
		
	//再将T中字符按位插入到S中从pos位置开始的位置
	for(i=pos; i<=pos+T[0]-1; i++)
		S[i] = T[i-pos+1];
		
	S[0] += T[0];
	
	return OK;	
}

/*(12)从串S中删除第pos个字符起长度为len的子串。*/
Status StrDelete_Sq(SString S, int pos, int len)
{
	int i;
	
	if(pos<1 || pos+len-1>S[0] || len<0)
		return ERROR;		//插入不合法
	
	//将从第pos+len个字符到末尾的所有字符依次向前移动len个位置 
	for(i=pos+len; i<=S[0]; i++)
		S[i-len] = S[i];
		
	S[0] -= len;
	
	return OK;
} 

/*(13)销毁串S。*/
void DestroyString_Sq(SString S)
{
	//顺序串不能被销毁
}

/*(14)输出串S。*/
void StrPrint_Sq(SString S)
{
	int i;
	
	for(i=1; i<=S[0]; i++)
		printf("%c",S[i]);
}

#endif
