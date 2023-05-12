/******************************************
 *								      	                *
 * 文件夹：04_String/03_BlockChainString	*
 *								      	                *
 * 文件名：BlockChainString.c		  	      *
 *								      	                *
 ******************************************/

#ifndef BLOCKCHAINSTRING_C
#define BLOCKCHAINSTRING_C

#include "BlockChainString.h"			/*04 串*/

/*(01)初始化块链串T。*/
void InitString_L(LString *T)
{
	(*T).head = NULL;
	(*T).tail = NULL;
	(*T).curlen = 0;
}

/*(02)生成一个其值等于常量chars的串T。*/
Status StrAssign_L(LString *T, char *chars)
{
	int len, i, j, k, count;
	Chunk *r;
	
	InitString_L(T);
	
	len = strlen(chars);
	if(!len)				//chars为空字符时错误 
		return ERROR;
		
	i = len / CHUNKSIZE;	//i为整块数 
	j = len % CHUNKSIZE; 	//j为整块数之外多余的字符数
	if(j)
		i++;
	
	for(k=1; k<=i; k++)
	{
		r = (Chunk*)malloc(sizeof(Chunk));
		if(!r)
			exit(OVERFLOW);
		r->next = NULL;
		
		if(k==1)						//第一个块 
			(*T).head = (*T).tail = r;
		else							//联接起之后的块 
		{
			(*T).tail->next = r;
			(*T).tail = r;	
		}
		
		for(count=0; count<CHUNKSIZE&&count+(k-1)*CHUNKSIZE<len; count++)
			(*T).tail->ch[count] = chars[count+(k-1)*CHUNKSIZE];	//复制chars到T 
	}
	
	while(count<CHUNKSIZE)
	{
		(*T).tail->ch[count] = '\0';	//T中多余空间补上'\0'
		count++;	
	}
		
	(*T).curlen = len;
	
	return OK; 
}

/*(03)由串S复制得到串T。*/
Status StrCopy_L(LString *T, LString S)
{
	int i;
	Chunk *r, *p;
	
	InitString_L(T);
	
	for(p=S.head; p; p=p->next)
	{
		r = (Chunk*)malloc(sizeof(Chunk));
		if(!r)
			exit(OVERFLOW);
		r->next = NULL;
		
		if(p==S.head)
			(*T).head = (*T).tail = r;
		else
		{
			(*T).tail->next = r;
			(*T).tail = r;		
		}
		
		for(i=0; i<CHUNKSIZE; i++)
			(*T).tail->ch[i] = p->ch[i];	//复制S到T，如果S中有多余空间的'\0'，连同'\0'一块复制过去 
	}
			
	(*T).curlen = S.curlen;
	
	return OK; 
		
} 

/*(04)若S为空串，返回TRUE，否则返回FALSE。*/
Status StrEmpty_L(LString S)
{
	if(S.head==NULL && S.tail==NULL && S.curlen==0)
		return TRUE;
	else
		return FALSE;
}

/*(05)若S>T，返回值>0；若S<T，返回值<0；否则，返回值=0。*/
int StrCompare_L(LString S, LString T)
{
	int i;
	int s = S.curlen;
	int t = T.curlen;
	Chunk *p = S.head;
	Chunk *q = T.head;
	
	while(p && q)						//p、q均不为空
	{
		for(i=0; i<CHUNKSIZE; i++)
		{
			if(p->ch[i]!=q->ch[i])
				return p->ch[i]-q->ch[i];
		}
		
		p = p->next;
		q = q->next;	
	} 
					
	return s-t;
}

/*(06)求串长。*/
int StrLength_L(LString S)
{
	return S.curlen;
}

/*(07)清空S。*/
void ClearString_L(LString *S)
{
	Chunk *p, *q;
	
	p = (*S).head;
	
	while(p)
	{
		q = p->next;
		free(p);
		p = q;	
	} 
	
	(*S).head = NULL;
	(*S).tail = NULL;
	(*S).curlen = 0;	
}

/*(08)用T返回由S1和S2联接而成的新串。*/
void Concat_L(LString *T, LString S1, LString S2)
{
	int i, j, k, count;
	Chunk *r, *p, *q;
	
	InitString_L(T);
	
	r = (*T).head;
	p = S1.head;
	q = S2.head;
	i = j = k = 0;		//i、j、k分别遍历T、S1、S2
	
	while(p || q)		//跳出循环时，S1和S2联接完成 
	{
		if(!r)
		{
			r = (Chunk*)malloc(sizeof(Chunk));
			if(!r)
				exit(OVERFLOW);
			r->next = NULL;
			
			if(!(*T).head)
				(*T).head = (*T).tail = r;
			else
			{
				(*T).tail->next = r;
				(*T).tail = r;
			}
		}
		
		if(p)
		{
			while(p && p->ch[j])
			{
				r->ch[i] = p->ch[j];
				i = (i+1) % CHUNKSIZE;
				j = (j+1) % CHUNKSIZE;
				
				if(!j || !(p->ch[j]))
					p = p->next;
				if(!i)
				{
					r = r->next;
					break;
				}		
			}
		}
		else
		{
			while(q && q->ch[k])
			{
				r->ch[i] = q->ch[k];
				i = (i+1) % CHUNKSIZE;
				k = (k+1) % CHUNKSIZE;
				
				if(!k || !(q->ch[k]))
					q = q->next;
				if(!i)
				{
					r = r->next;
					break;
				}	
			}	
		}
	}
	
	(*T).curlen = S1.curlen + S2.curlen;
	
	count = ((*T).curlen-1) % CHUNKSIZE + 1;
	while(count<CHUNKSIZE)
	{
		(*T).tail->ch[count] = '\0';
		count++;
	}  
}

/*(09)用Sub返回串S的第pos个字符起长度为len的子串。*/
Status SubString_L(LString *Sub, LString S, int pos, int len)
{
	int i, j, k, count;
	Chunk *r, *p;
	
	InitString_L(Sub);
	
	if(StrEmpty_L(S))
		return ERROR;
		
	if(pos<1 || pos>S.curlen || len<0 || pos+len-1>S.curlen)
		return ERROR;
		
	for(count=1,p=S.head; pos>count*CHUNKSIZE; count++,p=p->next)
		;						//p指向第pos个元素所在的块 
	
	r = (*Sub).head;
	i = 0;						//i控制变量元素个数 
	j = 0;						//j遍历Sub 
	k = (pos%CHUNKSIZE) - 1;	//k遍历S，计算第pos个元素在p所指向结点中的索引
	
	while(i<len)
	{
		if(!r)
		{
			r = (Chunk*)malloc(sizeof(Chunk));
			if(!r)
				exit(OVERFLOW);
			r->next = NULL;
			
			if(!(*Sub).head)
				(*Sub).head = (*Sub).tail = r;
			else
			{
				(*Sub).tail->next = r;
				(*Sub).tail = r;	
			}
		}
		
		while(i<len)
		{
			(*r).ch[j] = (*p).ch[k];
			j = (j+1) % CHUNKSIZE;
			k = (k+1) % CHUNKSIZE;
			i++;
			
			if(!k)
				p = p->next;
			if(!j)
			{
				r = r->next;
				break;
			}
		} 
	}
	
	(*Sub).curlen = len;
	
	count = ((*Sub).curlen-1) % CHUNKSIZE + 1;		//计算块中补'\0'的位置 
	while(count<CHUNKSIZE)
	{
		(*Sub).tail->ch[count] = '\0';
		count++;
	}
	
	return OK;
}

/*(10)返回T在S中第pos个字符后第一次出现的位置，不存在则返回0。*/
int Index_L(LString S, LString T, int pos)
{
	int s, t;
	LString sub;
	
	InitString_L(&sub);
	
	if(pos>0 && pos<=S.curlen)
	{
		s = S.curlen;		//主串长度 
		t = T.curlen;		//T串长度 
		
		while(pos<=s-t+1)
		{
			SubString_L(&sub, S, pos, t);
			
			if(StrCompare_L(sub,T)!=0)
				pos++;
			else
				return pos;		//返回子串在主串中的位置 
		}
		
	}
	
	return 0;	//找不到匹配的串则返回0	
}

/*(11)用V替换主串S中出现的所有与T相等的不重叠的子串。*/
Status Replace_L(LString *S, LString T, LString V)
{
	int i;
	
	if(StrEmpty_L(T))
		return ERROR;
	
	i = Index_L(*S, T, 1);							//寻找第一个匹配的位置	
	
	while(i) 										//能找到与T匹配的字符串 
	{	
		StrDelete_L(S, i, StrLength_L(T));			//删除T
		
		StrInsert_L(S, i, V);						//插入V													

		i += StrLength_L(V); 						//i切换到下一个位置
	 	
	 	i = Index_L(*S, T, i);						//定位下一个匹配的字符串 
	}
	
	return OK;
}

/*(12)在串S的第pos个字符之前插入串T。*/
Status StrInsert_L(LString *S, int pos, LString T)
{
	Chunk *r, *p1, *p2, *q;
	int i, j, k, count;
	LString Tmp;
	
	if(pos<1 || pos>(*S).curlen+1)
		return ERROR;
	InitString_L(&Tmp);
	
	r = Tmp.head;
	p1 = (*S).head;
	p2 = NULL;
	q = T.head;
	i = j = k = 0;	//i用来索引串Tmp，j索引串S，k索引串T 
	count = 1;
	
	//当p1!=NULL，p2==NULL，q!=NULL，将串S中第pos个字符前面的字符放入串Tmp中。
	//当p1==NULL，p2!=NULL，q!=NULL，再将串T插入到串Tmp的当前待插入的位置上。
	//当p1==NULL，p2!=NULL，q==NULL，根据p2->ch[j]，找到先前串S的第pos个字符，从这个字符开始到串的末尾的有效字符（不包括'\0'），全部插入到串Tmp的当前待插入的位置上。
	//当p1==NULL，p2==NULL，q==NULL，代表“在串S的第pos个字符之前插入串T。”这个过程结束。
	
	while(p1 || p2 || q)		 
	{							 
		if(!r)
		{
			r = (Chunk*)malloc(sizeof(Chunk));
			if(!r)
				exit(OVERFLOW);
			r->next = NULL;
			
			if(!Tmp.head)
				Tmp.head = Tmp.tail = r;
			else
			{
				Tmp.tail->next = r;
				Tmp.tail = r;
			}
		}
		
		if(p1)		//这个分支发生在找到插入位置之前，将插入位置前面的字符放入Tmp中，只要找到待插入的位置，则p1=NULL。 
		{
			while(p1 && count<pos)
			{
				r->ch[i] = p1->ch[j];
				i = (i+1) % CHUNKSIZE;
				j = (j+1) % CHUNKSIZE;
				count++;
				
				if(!j || !(p1->ch[j]))		//若j==0或者p1->ch[j]=='\0'中有一个成立，结点指针向后移。表示当前结点已经处理完毕。 
					p1 = p1->next;
				if(!i)						//若i==0,Tmp串中的结点向后移，跳出while循环。这步相当于准备为Tmp串产生新结点  
				{
					r = r->next;
					break;
				}
			}
			
			if(count==pos)
			{
				p2 = p1;
				p1 = NULL;	
			}
		}
		else if(q)					//将串T插入到串Tmp的当前待插入的位置上。 
		{
			while(q && q->ch[k])
			{
				r->ch[i] = q->ch[k];
				i = (i+1) % CHUNKSIZE;
				k = (k+1) % CHUNKSIZE;
				
				if(!k || !(q->ch[k]))		//若k==0或者q->ch[k]=='\0'中有一个成立，结点指针向后移。表示当前结点已经处理完毕。 
					q = q->next;
				if(!i)						//若i==0,Tmp串中的结点向后移，跳出while循环。这步相当于准备为Tmp串产生新结点 
				{
					r = r->next;
					break;
				}
			}
		}
		else								//当把串T全部插入串S后，然后再回到原先串S的插入位置， 
		{									//这个位置用p2->ch[j]记录，然后把串S中剩下的字符全部插入Tmp串中。
			while(p2 && p2->ch[j])
			{
				r->ch[i] = p2->ch[j];
				i = (i+1) % CHUNKSIZE;
				j = (j+1) % CHUNKSIZE;
				
				if(!j || !(p2->ch[j]))		//若j==0或者p2->ch[j]=='\0'中有一个成立，结点指针向后移
					p2 = p2->next;
				if(!i)						//若i==0,Tmp串中的结点向后移，跳出while循环。这步相当于为Tmp串产生新结点
				{
					r = r->next;
					break;
				}
			}
		}
	}
	
	Tmp.curlen = (*S).curlen + T.curlen;
	
	count = (Tmp.curlen-1)%CHUNKSIZE+1;		//计算块中补'\0'的位置 
	while(count<CHUNKSIZE)
	{
		Tmp.tail->ch[count] = '\0';
		count++;
	}
	
	ClearString_L(S);
	
	(*S).curlen = Tmp.curlen;				//注意，用malloc为串Tmp生成的空间都是有效数据空间，并不需要将那些结点释放，因为他们现在被串S所使用。 
	(*S).head = Tmp.head;
	(*S).tail = Tmp.tail;
	
	return OK;	
}

/*(13)从串S中删除第pos个字符起长度为len的子串。*/
Status StrDelete_L(LString *S, int pos, int len)
{
	Chunk *p, *q, *r;
	int count, first, last, m, n;
	
	if(pos<1 || pos>(*S).curlen || len<0 || pos+len-1>(*S).curlen)
		return ERROR;
		
	if(pos==1 && len==(*S).curlen)
		ClearString_L(S);
	
	first = pos;
	last = pos+len-1;
	
	for(count=1,p=(*S).head; first>count*CHUNKSIZE; count++,p=p->next)
		;						//p指向第first个元素所在的块
	
	for(q=p; last>count*CHUNKSIZE; count++,q=q->next)
		;						//q指向第last个元素所在的块
	
	m = (first-1) % CHUNKSIZE;	//计算待删除的起始结点的序号（索引） 
	n = (last-1) % CHUNKSIZE; 	//计算待删除的终止结点的序号（索引）
	
	n = (n+1) % CHUNKSIZE;		//待删除的终止结点序号的下一个序号
	if(!n)
		q = q->next;
	
	while(q && q->ch[n])
	{
		p->ch[m] = q->ch[n];
		m = (m+1) % CHUNKSIZE;
		n = (n+1) % CHUNKSIZE;
		
		if(!m)
			p = p->next;
		if(!n)
			q = q->next;
	}
	
	(*S).curlen -= len;
	
	for(count=1,(*S).tail=(*S).head; (*S).curlen>count*CHUNKSIZE; count++,(*S).tail=(*S).tail->next)
		;						//(*S).tail指向删除完成后串的终点结点 
	
	count = ((*S).curlen-1) % CHUNKSIZE + 1;
	while(count<CHUNKSIZE)
	{
		(*S).tail->ch[count] = '\0';
		count++;
	}
	
	r = (*S).tail->next;		//删除空余结点 
	while(r)
	{
		(*S).tail->next = r->next;
		free(r);
		r = (*S).tail->next;
	}
	
	return OK;
}

/*(14)销毁串S。*/
void DestroyString_L(LString *S)
{
	//块链存储结构的串不能被销毁	
}

/*(15)输出串S。*/
void StrPrint_L(LString S)
{
	int i = 0;
	Chunk *p = S.head;
	
	if(S.head==NULL && S.tail==NULL && S.curlen==0)
		printf("S为空串，无法输出！\n");
		
	while(p)
	{
		if((*p).ch[i])
			printf("%c", (*p).ch[i]);
		i = (i+1) % CHUNKSIZE;
		if(!i)
			p = p->next;
	}
}

/*(16)用*c返回串S中第i个字符。*/
Status GetChar_L(LString S, char *c, int i)
{
	int m, n, count;
	Chunk *p;
	
	if(StrEmpty_L(S))
		return ERROR;
		
	if(i<1 || i>S.curlen)
		return ERROR;
		
	m = i / CHUNKSIZE;			//计算第i个元素在第几个块
	n = i % CHUNKSIZE;			//计算第i个元素是第m个块的第几个元素
	if(n)
		m++;
	
	for(count=1,p=S.head; count<m; count++)
		p = p->next; 			//p指向第i个元素所属的块
	
	if(n)
		*c = (*p).ch[n-1];		//注意每个块中最后一个字符的处理 
	else
		*c = (*p).ch[CHUNKSIZE-1];
	
	return OK; 
}

#endif
