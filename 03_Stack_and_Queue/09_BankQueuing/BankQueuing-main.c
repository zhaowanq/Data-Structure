/**********************************************
 *                                            *
 * 文件夹: 03_Stack_and_Queue/09_BankQueuing  *
 *                                            *
 * 文件名: BankQueuing-main.c                 *
 *                                            *
 * 内  容: 模拟银行排队相关函数测试	          *
 *                                            *
 **********************************************/

#include "BankQueuing.c"		/*03 栈和队列*/

int main(void)
{
	printf("按任意键开始：");
	getchar();
	
	Bank_Simulation_1();		//算法3.6 
//	Bank_Simulation_2();		//算法3.7，另一种算法
	
	return 0;
}
