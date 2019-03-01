#include"DoubleList.h"

//初始化双向链表
void InitDoublelist(pDoulist list)
{
	assert(list != NULL);

	list->head.next  = NULL;   //初始化尾指针
	list->head.prev  = NULL;   //初始化头指针
	list->count = 0;           //初始化结点个数i

}

//在双向链表中插入一个结点
	//1：先考虑普通情况下的结点插入
/*
void InsertDoublelist(pDoulist list, ElemType val, int pos)
{
	assert(list != NULL);
	if( pos < 0 | pos > list->count )
	{
		printf("pos is error\n");
		return ;
	}
	Node *p = &list->head;
	Node *s = ( Node *)malloc(sizeof(Node));
	while( pos > 0)
	{
		p = p->next;
		pos--;
	}
	s->data = val;
	if( p->next != NULL)
	{
		p->next->prev = s;
	}
	s->next = p->next;
	s->prev = p;
	p->next = s;
	list->count++;
}
*/
	//2：考虑特殊情况的结点插入优化代码（list->count == 0  和 pos == list->count ）
static Node *BuyNode(ElemType val, Node *prev, Node *next )//购买结点
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert( s != NULL);

	s->data = val;
	s->prev = prev;
	s->next = next;

	return s;
}
void InsertDoublelist(pDoulist list, ElemType val, int pos)
{
	assert( list != NULL);
	if( (pos < 0) || (pos > list->count))
	{
		printf("pos is error\n");
		return ;
	}
	Node *p = &list->head;
	while( pos > 0)
	{
		p = p->next;
		pos --;
	}
	Node *s = BuyNode( val, p, p->next);//插入结点
	if( p->next != NULL)//考虑尾插
	{
		p->next->prev = s;
	}
	p->next = s;
	list->count++;
}

//头插函数
void  InsertHeadDoublelist (pDoulist list,ElemType val)
{
	InsertDoublelist(list, val, 0);//头插函数可以调用插入函数，将插入函数的pos参数设置为0
}

//尾插函数
void InsertTailDoublelist(pDoulist list,ElemType val)
{
	InsertDoublelist(list, val, list->count);//尾插函数可以调用插入函数，将插入函数的pos参数设置为list->count
}

//删除双向链表中的一个结点
void DeleteDoublelist(pDoulist list,int pos)
{
	assert(list != NULL);
	if((pos < 1) ||(pos > list->count))
	{
		printf("pos is error\n");
		return ;
	}
	Node * p = &list->head;
	while( pos > 0)
	{
		p = p->next;
		pos --;
	}
	p->prev->next = p->next;
	if ( p->next != NULL)
	{
		p->next->prev = p->prev;
	}
	free(p);
	list->count--;
}

//删除头结点的函数
void DeleteHeadDoublelist(pDoulist list)
{
	DeleteDoublelist(list,1);//头结点的删除可以调用删除函数，将删除函数的pos参数设置为1
}

//删除尾结点的函数
void DeleteTailDoublelist(pDoulist list)
{
	DeleteDoublelist(list,list->count);//尾结点的删除可以调用删除函数，将删除函数的pos参数设置为list->count
}

//输出双向链表中的数据1
void Show1(pDoulist list)
{
	assert(list != NULL);
	Node *p = list->head.next;
	while( p != NULL)//用指针遍历整个链表，指针跑一个输出一个
	{
		printf("%3d",p->data);
		p = p->next;
	}
	printf("\n");
}

void Show2(pDoulist list)
{
	assert( list != NULL);
	Node *p = list->head.next;
	int tmp = list->count;
	while( tmp > 0)
	{
		printf("%3d",p->data);
		p = p->next;
		tmp --;
	}
	printf("\n");	
}

//逆序输出双向链表中的数据
void Reverseshow(pDoulist list)
{
	assert( list != NULL);
	Node *p = &list->head;
	while( p->next != NULL)//先让指针跑到最后一个结点
	{
		p = p->next;
	}
	while( p->prev != NULL)//指针开始往前跑，指针跑一个输出一个值
	{
		printf("%3d",p->data);
		p = p->prev;
	}
	printf("\n");
}
//销毁一个双向链表
void DestroyDoublelist(pDoulist list)
{
	assert(list != NULL);
	while( list->count > 0)
	{
		DeleteHeadDoublelist(list); //调用删除头结点的函数，采用循环的方式每次删除头结点
	}
}