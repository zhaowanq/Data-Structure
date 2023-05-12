/**********************************************
 *                                            *
 * 文件夹: 03_Stack_and_Queue/09_BankQueuing  *
 *                                            *
 * 文件名: BankQueuing.c                      *
 *                                            *
 * 算  法: 3.6、3.7					                  *
 *                                            *
 **********************************************/
 
#ifndef BANKQUEUING_C
#define BANKQUEUING_C

#include "BankQueuing.h"				/*03 栈和队列*/
 
/*(01)算法3.6：模拟银行排队事件。*/
void Bank_Simulation_1()
{
	//银行业务模拟，统计一天内客户在银行逗留的平均时间。
	char eventType; 
	OpenForDay();						//初始化 
	
	while(MoreEvent())
	{
		EventDrived(&eventType);		//事件驱动
		switch(eventType)
		{
			case 'A':					//处理客户到达事件 
				CustomerArrived();
				break;
			case 'D':					//处理客户离开事件
				CustomerDeparture();
				break;
			default :
				Invalid();
		} 
	}
	
	CloseForDay();						//计算平均逗留时间	
} 
 
/*(02)银行开门，初始化各变量。*/
void OpenForDay()
{
	int i;
	
	gTotalTime = 0;				//初始化累计时间和客户数为0 
	gCustomerNum = 0;			
	
	InitList_L(&gEv);			//初始化事件链表为空表 
	
	gEn.OccurTime = 0;			//设定第一个客户到达事件 
	gEn.NType = Arrive;
	
	OrderInsert(gEv,gEn,cmp);	//插入事件表 
	
	for(i=1; i<=4; i++)
		InitQueue_L(&gQ[i]);	//初始化4个客户队列为空队列
		
	printf("事件链表的地址为 0x%x,头指针为 0x%x\n",&gEv, gEv);	 
	
	for(i=1; i<=4; i++)
		printf("\"%d\"号客户窗口的地址为 0x%x,头指针为 0x%x\n",i, &gQ[i], gQ[i].front);
	
	Show();
} 

/*(03)判断事件表是否为空。*/
Status MoreEvent()
{
	if(!ListEmpty_L(gEv))
		return TRUE;			//事件表不空 
	else
		return FALSE;
}

/*(04)事件驱动，获取当前事件类型。*/
void EventDrived(char *event)
{
	ListDelete_L(gEv, 1, &gEn);
	Show();
	 
	if(gEn.NType==Arrive)
		*event = 'A';
	else
		*event = 'D';
}

/*(05)处理客户到达事件。*/
void CustomerArrived()
{
	int durtime, intertime, i;
	Event e;
	
	++gCustomerNum;									//客户数加一
	Random(&durtime, &intertime);					//生成当前客户办理业务需要的时间和下一个客户到达时间间隔
	//printf("请输入客户办理业务所需时间（1-20分钟）和下一客户到达时间间隔：\n");
	//scanf("%d %d",&durtime,&intertime);
	 
	e.OccurTime = gEn.OccurTime + intertime;		//下一客户到达时刻 
	e.NType = Arrive;
	
	if(e.OccurTime<gCloseTime)						//银行尚未关门，插入事件表
	{
		OrderInsert(gEv, e, cmp);
		Show();
	}
			
	i = Minimun();									//求长度最短队列
	gCustomerRcd.ArrivedTime = gEn.OccurTime;
	gCustomerRcd.Duration = durtime;
	gCustomerRcd.Count = gCustomerNum;
	EnQueue_L(&gQ[i], gCustomerRcd); 
	Show();
		
	if(QueueLength_L(gQ[i])==1)						//设定第i队列的1个离开事件并插入事件表 
	{
		e.OccurTime = gCustomerRcd.ArrivedTime + gCustomerRcd.Duration;			//当前客户离开时刻 
		e.NType = i;
		OrderInsert(gEv, e, cmp); 
		Show();
	}
			 
}

/*(06)处理客户离开事件。*/
void CustomerDeparture()
{
	//处理客户离开事件，gEn.NType>0。
	int i = gEn.NType;
	
	DeQueue_L(&gQ[i], &gCustomerRcd);		//删除第i队列的排头客户
	Show();
	
	gTotalTime += gEn.OccurTime - gCustomerRcd.ArrivedTime;		//累计客户逗留时间
	
	if(!QueueEmpty_L(gQ[i]))				//设定第i队列的一个离开事件并插入事件表 
	{
		GetHead_L(gQ[i], &gCustomerRcd);
		gEn.OccurTime += gCustomerRcd.Duration;		//注意这里的逻辑关系，虽然客户在gCustomerRcd.ArrivedTime时间到来，但是他前面有人，只能排队，
		gEn.NType = i;								//所以他实际的离开时间是他前面那个人的离开时间加上他处理事务所需的时间
		OrderInsert(gEv, gEn, cmp);					//即gEn.OccurTime += gCustomerRcd.Duration;，而不是gEn.OccurTime = gCustomerRcd.ArrivedTime + gCustomerRcd.Duration; 
		Show();
	}	 
}

/*(07)事件类型错误。*/
void Invalid()
{
	printf("运行错误！");
	exit(OVERFLOW);
}

/*(08)银行关门。*/
void CloseForDay()
{
	printf("当天总共有%d个客户，平均逗留时间为%.2f分钟。\n",gCustomerNum,gTotalTime*1.0/gCustomerNum);
}
 
/*(09)比较事件a和事件b发生的先后次序。*/
int cmp(Event a, Event b)
{
	if(a.OccurTime<b.OccurTime)				//链表中的事件晚于新事件发生 
		return -1;
	if(a.OccurTime==b.OccurTime)			//发生时间相等 
		return 0;
	if(a.OccurTime>b.OccurTime)				//链表中的事件早于新事件发生
		return 1;
}

/*(10)生成随机数，包括当前客户办理业务所需时间和下一客户到达间隔的时间。*/
void Random(int *durtime, int *intertime)
{
	srand((unsigned)time(NULL));			//用系统时间做随机数种子
	*durtime = rand()%DurationTime+1;		//办业务时间持续1到20分钟
	*intertime = rand()%IntervalTime+1;		//下一客户到达间隔的时间从1到10分钟
} 

/*(11)将事件插入事件表正确的位置。*/
Status OrderInsert(EventList gEv, Event gEn, int(cmp)(Event,Event))
{
	EventList p, pre, s;
	
	pre = gEv;
	p = gEv->next;							//p指向第一个事件 
	while(p && cmp(gEn, p->data)==1)		//查找gEn在事件表中应该插入的位置，注意这里是gEn，不是gEv
	{										//当p存在且当前事件链表的事件发生时间比新事件的发生时间早，继续迭代 
		pre = p;
		p = p->next; 
	}
	//循环跳出的两种情况：
	//		要么事件链表检索完毕，直接将新事件插入在链表尾			
	//	 	要么当前事件链表的事件发生时间晚于或等于新事件的时间，等于的话，新事件插在前面
	
	s = (LinkList)malloc(sizeof(LNode)); 	//LinkList=EventList
	if(!s)
		exit(OVERFLOW);
	
	s->data = gEn;							//将gEn插入事件表
	s->next = pre->next;
	pre->next = s;
	
	return OK;
} 

/*(12)求长度最短队列的序号。*/
int Minimun()
{
	int i1 = QueueLength_L(gQ[1]);
	int i2 = QueueLength_L(gQ[2]);
	int i3 = QueueLength_L(gQ[3]);
	int i4 = QueueLength_L(gQ[4]);
	
	if(i1<=i2 && i1<=i3 && i1<=i4)
		return 1;
	if(i2<=i1 && i2<=i3 && i2<=i4)
		return 2;
	if(i3<=i1 && i3<=i2 && i3<=i4)
		return 3;
	if(i4<=i1 && i4<=i2 && i4<=i3)
		return 4;
}

/*(13)显示当前队列的客户排队情况。*/
void Show()
{
	int i;
	QueuePtr p;		//记录到来的客户是第几个
	
	system("clear");
	
	printf("当前事件链表内容为◆：");
	ListTraverse_L(gEv,PrintEvElem);
	printf("\n");
	
	for(i=1; i<=4; i++)
	{
		for(p=gQ[i].front; p; p=p->next)
		{
			if(p==gQ[i].front)
			{
				if(i==1)
					printf("柜台①●");
				if(i==2)
					printf("柜台②●");
				if(i==3)
					printf("柜台③●");
				if(i==4)
					printf("柜台④●");
			}
			else
				printf("（%03d，%03d，%03d）",p->data.ArrivedTime, p->data.Duration, p->data.Count);
			
			if(p==gQ[i].rear)
				printf("\n");
		}
	}
	
	Wait(SleepTime);	
}

/*(14)算法3.7：模拟银行排队事件。*/
void Bank_Simulation_2()
{
	OpenForDay();
	
	while(!ListEmpty_L(gEv))
	{
		ListDelete_L(gEv, 1, &gEn);
		Show();
	 
		if(gEn.NType==Arrive)
			CustomerArrived();
		else
			CustomerDeparture();
	}
	
	printf("当天总共有%d个客户，平均逗留时间为%.2f分钟。\n",gCustomerNum,gTotalTime*1.0/gCustomerNum);
}

/*(15)打印事件链表。*/
void PrintEvElem(LElemType_L e)
{
	printf("（%d，%d） ",e.OccurTime, e.NType);
} 

#endif
