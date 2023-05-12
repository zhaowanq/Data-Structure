/*****************************************
 *						                           *
 * 文件夹: 02_LinearList/11_Polynomial   *
 * 							                         *
 * 文件名: Polynomial-main.c             *
 * 							                         *
 * 内  容: 一元多项式相关操作测试        *
 *                                       *
 * 注  意: 本节缺少多项式减法和乘法      *
 *                                       *
 *****************************************/
 
#include <stdio.h>
#include "Polynomial.c"
 
int main(void)
{
	FILE *fp;
	Polynomial Pa, Pb;
	int m, n, i;
		
	m = 5;
	n = 6;
	
	printf("函数：创建多项式可扩展单链表 测试...\n");
	printf("作为示范，创建项数为 %d 的多项式Pa...\n", m);
	PressEnter;
	fp = fopen("TestData_Pa.txt", "r");
	CreatPolyn_P(fp, &Pa, m);
	fclose(fp);
	printf("多项式链表Pa创建成功，Pa的地址为%#x\n",&Pa);
	printf("多项式链表Pa头结点的地址为%#x\n",Pa.head);
	printf("\n");
	printf("作为示范，创建项数为 %d 的多项式Pb...\n", n);
	PressEnter;
	fp = fopen("TestData_Pb.txt", "r");
	CreatPolyn_P(fp, &Pb, n);
	fclose(fp);
	printf("多项式链表Pb创建成功，Pb的地址为%#x\n",&Pb);
	printf("多项式链表Pb头结点的地址为%#x\n",Pb.head);
	printf("\n\n");
	
	printf("函数：输出一元多项式 测试...\n");
	PressEnter;
	printf("一元多项式 Pa = ");
	PrintPolyn_P(Pa);
	printf("\n");
	printf("一元多项式 Pb = ");
	PrintPolyn_P(Pb);
	printf("\n\n");
	
	printf("函数：返回一元多项式的项数。测试...\n");
	PressEnter;	
	printf(" La 的项数为 %d ，Lb 的项数为 %d\n", PolynLength_P(Pa), PolynLength_P(Pb));
	printf("\n\n");
		
	printf("函数：一元多项式加法Pa = Pa + Pb 测试...\n");
	PressEnter;
	AddPolyn_P(&Pa, &Pb);
	printf("一元多项式 Pa = Pa + Pb = ");
	PrintPolyn_P(Pa);
	printf("\n\n");
	
	printf("函数：销毁一元多项式。测试...\n");
	PressEnter;	
	printf("销毁 Pa 前：");
	(Pa.head && Pa.tail && Pa.len) ? printf(" Pa 存在！\n") : printf(" Pa 不存在！！\n");
	DestroyPolyn_P(&Pa);
	printf("销毁 Pa 后：");
	(Pa.head && Pa.tail && Pa.len) ? printf(" Pa 存在！\n") : printf(" Pa 不存在！！\n");
	printf("\n");
		
	return 0;	
}
