#ifndef SCANF_C
#define SCANF_C

#include <stdio.h>
#include <string.h>
#include <stdarg.h>			//提供宏va_list、va_start、va_arg、va_end
#include <ctype.h>			//提供isprint原型

/*
    自定义的数据录入函数，用于从文件fp
中读取格式化的输入。

    与fscanf不同之处在于此函数只会读取
西文字符，对于中文字符，则会跳过。 
*/

int Scanf(FILE *fp,char *format,...)	//format是一个用来存放格式化类型的地址 
{
	int *i;				//存放文件中整型变量的地址
	char *ch;			//存放文件中字符型变量的地址
	char *s;			//存放字符串变量的地址
	float *f;			//存放文件中浮点型变量的地址
	int count;			//统计一轮输入中接收到变量的个数 
	int k;				//用来索引变量的类型 
	int len;			//len用来计算格式输入的参数的个数，比如%d%d 
	int n;				//统计字符串中字符的个数 
	int tmp;			//存放临时变量 
	va_list ap;
	
	len = strlen(format);
	
	va_start(ap,format);
	
	for(count=0,k=2;k<=len;k=k+2)	//k表示的是%c %d %f 他们分别占用字符的个数，即k=2，用来判断您一共输入了多少个格式输入符
	{
		while((tmp=getc(fp))!=EOF)	//跳过所有非西文字符
		{
			if(tmp>=0 && tmp<=127)	 //遇到首个西文字符，将此西文字符放入输入流
			{
				ungetc(tmp,fp);		// int ungetc(int char, FILE *stream) 把字符char（一个无符号字符）
									// 推入到指定的流 stream 中，以便它是下一个被读取到的字符。读出来，再放回去 
				break;
			} 
		}
		if(tmp==EOF)	//当读到文件末尾，跳出循环。 
			break;
		if(format[k-1]=='c')		//读取字符
		{
			ch = va_arg(ap,char*);	//获取Scanf函数中的第三个参数，并将其赋值给ch变量 
			
			if(tmp!=EOF)
				count += fscanf(fp,"%c",ch);	//从fp输入流中读取一个字符放入以ch内容为地址的内存单元中
		}
		
		if(format[k-1]=='d')				//筛选整型的西文字符 
		{
			i = va_arg(ap, int*);			//获取Scanf函数中的第三个参数，并将其赋值给i变量 
			
			while((tmp=getc(fp))!=EOF)
			{
				if((tmp>='0' && tmp<='9') || tmp=='-' || tmp=='+')
				{
					ungetc(tmp, fp);
					break;
				}
			}
			
			if(tmp!=EOF)
				count += fscanf(fp, "%d", i);	//从fp输入流中读取一个整型数据放入以i内容为地址的内存单元中
		}
		
		if(format[k-1]=='f')				//读取浮点型 
		{
			f = va_arg(ap, float*);
			
			while((tmp=getc(fp))!=EOF)
			{
				if((tmp>='0' && tmp<='9') || tmp=='-' || tmp=='+'|| tmp=='.' )
				{
					ungetc(tmp, fp);
					break;
				}
			}
			
			if(tmp!=EOF)
				count += fscanf(fp, "%f", f);	////从fp输入流中读取一个浮点型数据放入以f内容为地址的内存单元中
		}
		
		if(format[k-1]=='s')				//读取字符串
		{
			s = va_arg(ap, char*);
			
			while((tmp=getc(fp))!=EOF && (!isprint(tmp) || tmp==' '))	//循环读取输入流，直到为可打印字符或者文件结束 
				;
			n = 0;
			if(!feof(fp))	//若没有读到文件末尾
			{
				ungetc(tmp, fp);	//将字符放入输入流
				while((tmp=getc(fp))!=EOF)
				{
					if(isprint(tmp) && tmp!=' ')
						s[n++] = tmp;
					else
						break;	
				}
				ungetc(tmp, fp);
			}
			 
			s[n] = '\0';
			
			count++;
		}
	}
	
	va_end(ap);
	
	return count;
}

#endif
