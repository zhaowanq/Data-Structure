/**********************************
 *						                    *
 * 文件夹: 09_Searching           *
 * 						                    *
 * 文件名: HashTable-main.c       *
 * 						                    *
 * 内  容: 哈希表查找相关函数测试 *
 *                                *
 **********************************/

#include <stdio.h>
#include "HashTable.c" 						/* 09_Searching */

#define Max 20								// 查找表中元素个数

int main(int args, char *argv[])
{
	Table T;
	HashTable H;

	printf("创建并输出一个查找表...\n");
	PressEnter;
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}
	

	printf("函数： CreateHash等 测试...\n");		//1、2、3、4、5、6、7、8.函数CreateHash等测试
	PressEnter;
	{
		printf("创建一个哈希表，并输出其中的关键字：\n");	
		CreateHash(&H, T);	
		PrintHash(H);	
		printf("\n");
	}


	printf("查找测试...\n");
	PressEnter;
	{ 
		Status r;
		KeyType key = 132;
		int p = 0;
		
		printf("查找关键字 %d ...\n", key);
		r = SearchHash(H, key, &p);
		if(r==DUPLICATE)			// 由于建表是根据查表生成的，r一定不等于FULL
			printf("查找成功，%d 在哈希表下标为 %d 的位置。\n", key, p);
		else
			printf("查找失败！\n");
		printf("\n");
	}	
	
	return 0;
}
