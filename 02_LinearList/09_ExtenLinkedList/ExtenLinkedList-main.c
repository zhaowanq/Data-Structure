/**********************************************
*									       	                    *
*	文件夹: 02_LinearList/09_ExtenLinkedList    * 
*									   		                      *							
*	文件名: ExtenLinkedList-main.c 		  	      *
*								  	 		                      *
*	内  容:	扩展的单链表相关函数测试		        *
*									   		                      *
**********************************************/

#include <stdio.h>
#include "ExtenLinkedList.c"		/*02 线性表*/

/* 函数原型 */
Status CmpGreater(LElemType_E e, LElemType_E data);
void PrintElem(LElemType_E e);

int main(void)
{
	ELinkList L;
	Link p, q, s;
	PositionPtr r;
	int i;
	LElemType_E e;
	
	printf("函数：初始化扩展的单链表 L 测试...\n");
	PressEnter;
	InitList_E(&L);
	printf("初始化成功，扩展的单链表 L 的内存单元为%#x\n",&L);
	printf("L 的头指针为%#x\n",L.head); 
	printf("\n\n");
	
	printf("函数：L 是否为空测试...\n");
	PressEnter;
	ListEmpty_E(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	printf("\n\n");
	
	printf("函数：在扩展的单链表 L 第i个位置之前插入e。测试...\n");
	PressEnter;
	for(i=1;i<=6;i++)
	{
		printf("在 L 第 %d 个位置插入 \"%d\"\n",i,2*i);
		ListInsert_L_E(&L,i,2*i);
	}
	printf("\n\n");
	
	printf("函数：遍历扩展的单链表 L 。测试...\n");
	PressEnter;
	printf("L 中的元素为：L = ");
	ListTraverse_E(L,PrintElem); 
 	printf("\n\n");
	
	printf("函数：扩展的单链表 L 的长度测试...\n");
	PressEnter;
	i = ListLength_E(L);
	printf("L 的长度为 %d \n", i);
	printf("\n");
	
	printf("函数：删除扩展的单链表 L 第i个位置的结点，并用e接收。测试...\n");
	PressEnter;
	ListDelete_L_E(&L,6,&e);
	printf("删除扩展的单链表 L 第6个位置的结点，被删除的元素为%d\n",e);
	printf("L 中的元素为：L = ");
	ListTraverse_E(L,PrintElem);
	printf("\n\n");
	
	printf("函数：获取 L 中第i个元素的地址测试...\n");
	PressEnter;
	LocatePos_E(L, 3, &p);
	printf("L 中第 3 个元素 \"%d\" 的地址为 %#x \n", p->data, p);
	printf("\n");
	
	printf("函数：返回p指向的结点的前驱 测试...\n");
	PressEnter;	
	r = PriorPos_E(L, p);
	printf("指针 p = %#x 指向的元素 \"%d\" 的前驱元素为 \"%d\" \n",p, p->data, r->data);
	printf("\n");
	
	printf("函数：返回p指向的结点的后继 测试...\n");
	PressEnter;	
	r = NextPos_E(p); 
	printf("指针 p = %#x 指向的元素 \"%d\" 的后继元素为 \"%d\" \n",p, p->data, r->data);
	printf("\n");
	
	printf("函数：作为示范，返回链表 L 中首个比7大的元素的地址。\n");
	PressEnter;
	r = LocateElem_E(L, 7, CmpGreater);
	if(r)
		printf("链表 L 中首个比7大的元素的地址为%#x,它是元素\"%d\"\n\n",r,r->data);
	else
		printf("L中没有元素比7大！\n");
	
	printf("函数：创建结点测试...\n");
	PressEnter;
	MakeNode_E(&p,101);
	printf("创建的结点p的地址为%#x,它的值为\"%d\"\n",p, p->data);
	MakeNode_E(&q,202);
	printf("创建的结点q的地址为%#x,它的值为\"%d\"\n",q, q->data);
	printf("\n");
	
	printf("函数：返回指针 p 所指向的结点中的值。测试...\n");
	PressEnter;
	e = GetCurElem_E(p);
	printf("指针 p(%#x) 所指向的结点的值为 \"%d\" \n",p, e);
	e = GetCurElem_E(q);
	printf("指针 q(%#x) 所指向的结点的值为 \"%d\" \n",q, e);
	printf("\n");
	
	printf("函数：修改指针 p 所指向的结点中的值。测试...\n");
	printf("作为示范，用 888 替换指针 p(%#x) 所指向的结点中的值...\n",p);
	PressEnter;
	printf("替换之前，指针 p(%#x) 所指向的结点中的值为 \"%d\" \n",p, p->data);
	SetCurElem_E(p, 888);
	printf("替换之后，指针 p(%#x) 所指向的结点中的值为 \"%d\" \n",p, p->data);
	printf("\n");
	
	printf("函数：销毁p指向的结点测试...\n");
	PressEnter;
	printf("销毁结点 p 前：");
	p ? printf(" p 存在！\n") : printf(" p 不存在！！\n");
	FreeNode_E(&p);
	printf("销毁结点 p 后：");
	p ? printf(" p 存在！\n") : printf(" p 不存在！！\n");
	printf("\n");

	printf("函数：将s所指向的一串结点链接在 L 之后。测试...\n");
	printf("作为示范，将 q 指向的结点插在 L 之后...\n");
	PressEnter;
	Append_E(&L, q);
	printf("L 中的元素为：L = ");						 
	ListTraverse_E(L, PrintElem);
	printf("\n\n");
	
	printf("函数：删除 L 的尾结点并用p接收，改变尾指针。 测试...\n");
	PressEnter;
	Remove_E(&L,&p);
	printf("L 中的元素为：L = ");						 
	ListTraverse_E(L, PrintElem);
	printf("\n");
	printf("删除之前， L 的尾结点的值为%d",p->data);
	printf("\n\n");
	 
	printf("函数：q指向L中的一个结点，将q当做头结点，将p插入到“第一个结点”之前。 测试...\n");
	PressEnter;
	printf("创建值为 303 的结点 p ...\n");
	MakeNode_E(&p, 303);
	printf("令 q 指向 L 中第 4 个元素...\n");
	LocatePos_E(L, 4, &q);
	printf("将 p 结点插入到以 q 作头结点的链表的第一个结点之前...\n");
	InsFirst_E(&L, q, p);
	printf(" L 中的元素为：L = ");						 
	ListTraverse_E(L, PrintElem);
	printf("\n\n"); 
	
	printf("函数：q指向L中的一个结点，将q当做头结点，删除“第一个结点”，并用p接收。 测试...\n");
	PressEnter;
	printf("令 q 指向 L 中第 4 个元素...\n");
	LocatePos_E(L, 4, &q);
	printf("删除以 q 作头结点的链表的\"第一个结点\"...\n");
	DelFirst_E(&L, q, &p);
	printf("L 中的元素为：L = ");						 
	ListTraverse_E(L, PrintElem);
	printf("\n");
	printf("被删除的结点为%d\n",p->data); 
	printf("\n\n");
	
	printf("函数：以指针形式返回L头结点的位置。测试...\n");
	PressEnter;
	p = GetHead_E(L);
	printf("L 头指针为 p = L.head = %#x \n", p);
	printf("\n\n"); 
	
	printf("函数：以指针形式返回L尾结点的位置。测试...\n");
	PressEnter;
	q = GetLast_E(L);
	printf("L 尾指针为 q = L.tail = %#x \n", q);
	printf("\n\n");
	
	printf("函数：将s所指向结点插入q所指向结点之前，并将q指向新插入的结点。 测试...\n");
	PressEnter;				
	printf("创建值为 404 的结点 s ...\n");						
	MakeNode_E(&s, 404);
	printf("将结点 s 插入到尾结点 q 之前...\n");
	InsBefore_E(&L, &q, s);
	printf("当前 L 的值为：L = ");						 
	ListTraverse_E(L, PrintElem);
	printf("\n\n");
	
	printf("函数：将s所指向结点插入q所指向结点之后，并将q指向新插入的结点。 测试...\n");
	PressEnter;				
	printf("创建值为 505 的结点 s ...\n");						
	MakeNode_E(&s, 505);
	printf("将结点 s 插入到头结点 p 之后...\n");
	InsAfter_E(&L, &p, s);
	printf("当前 L 的值为：L = ");					 
	ListTraverse_E(L, PrintElem);
	printf("\n\n");
	
	printf("函数：清空扩展的单链表 L 测试...\n");
	PressEnter;	
	printf("清空 L 前：");
	ListEmpty_E(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	ClearList_E(&L);
	printf("清空 L 后：");
	ListEmpty_E(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
	printf("\n");	
	
	printf("函数：销毁扩展的单链表 L 测试...\n");
	PressEnter;
	printf("销毁 L 前：");
	L.head!=NULL && L.tail!=NULL ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	DestroyList_E(&L);
	printf("销毁 L 后：");
	L.head!=NULL && L.tail!=NULL ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
	printf("\n");
	
	return 0;
}

Status CmpGreater(LElemType_E e, LElemType_E data)
{
	return data>e ? TRUE : FALSE;
}

void PrintElem(LElemType_E e)
{
	printf("%d ", e);
}
