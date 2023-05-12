/****************************************
 *									                    *
 * 文件夹: 04_String/05_WordIndexTable  *
 *									                    *
 * 文件名: WordIndexTable-main.c	      *
 *									                    *
 * 内  容: 创建索引表相关函数测试	      *
 *                                      *
 ****************************************/
 
#include "WordIndexTable.c"				/*04 串*/

int main(void)
{
	FILE *fp;
	char line[MaxLineLen];
	 
	char *bookinfo = "BookInfo.txt";	//书目文件名 
	char *bookidx = "BookIdx.txt";		//关键词索引文件名 
	
	Main(bookinfo, bookidx);			//创建索引表
	 
	if(fp = fopen(bookidx, "r"))		//显示索引表到屏幕 
		printf("---------创建索引表成功！---------\n\n");
	while(!feof(fp))
	{
		fgets(line, MaxLineLen, fp);
		printf("%s", line);
	}
	
	printf("\n\n-------------------------------\n\n");
	
	Wait(50);
	system("mousepad BookInfo.txt");		//打开书目文件
	Wait(50);
	system("mousepad BookIdx.txt");		//打开上面生成的索引表
	
	return 0;
} 
