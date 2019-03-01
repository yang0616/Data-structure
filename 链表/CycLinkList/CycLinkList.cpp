#include"CycLinkList.h"


//不带头结点的循环链表
//初始化链表
void  InitLinkList(pList list)
{
	list->count = 0;
	list->head = NULL;
}

static Node *BuyNode(ElemType val, Node *next)
{
	Node *p = ( Node *)malloc(sizeof(Node));
	assert( p != NULL);

	p->data = val;
	if( next == NULL)//考虑链表中没有结点时的情况
	{
		p->next = p;
		return p;
	}
	p->next = next;
	return p;
}
//插入函数
void InsertLinkList(pList list, ElemType val, int pos)
{
	if( pos < 0 || pos > list->count)
	{
		printf("pos is error\n");
		return ;
	}

	if(list->head == NULL)//考虑链表中没有结点时的插入
	{
		list->head = BuyNode(val, NULL); //给头结点赋值
		list->count++;
		return;
	}
	Node *p = list->head;
	int tmpos = pos == 0 ? list->count : pos;//如果时头插就相当于尾插后前移头指针
	while( tmpos > 1)//将指针移到pos(tmpos)结点的位置
	{
		p =p->next;
		tmpos --;
	}
	Node *s = BuyNode(val, p->next); //给新结点申请新空间
	p->next = s;
	if(pos == 0) //如果pos为0就代表是头插,所以要改变头指针的位置
	{
		list->head = s;
	}
	list->count++; //增加结点个数
}

//头插函数
void InsertHeadLinkList(pList list, ElemType val)
{
	InsertLinkList(list, val, 0);
}

//尾插函数
void InsertTailLinkList(pList list, ElemType val)
{
	InsertLinkList(list, val, list->count);
}

//删除结点函数
void DeleteLinkList(pList list, int pos)
{
	assert(list != NULL);
	if(pos < 1 || pos > list->count)
	{
		printf("pos is error\n");
		return ;
	}
	if(list->count == 1) //只有一个结点时的删除
	{
		free(list->head); //直接释放空间
		list->head = NULL;
		list->count--; //结点数减一
	}
	Node *p = list->head;
	if( pos == 1)
	{
		while( p->next != list->head)
		{
			p = p->next;
		}
		list->head = list->head->next;
	}
	else
	{
		while( pos > 2)
		{
			p = p->next;
			pos --;
		}
	}	
		Node *q = p->next;
		p->next = q->next;
		free(q);
		list->count--;
	
}

//删头函数
void DeleteHeadLinkList(pList list)
{
	DeleteLinkList(list, 1);
}

//删尾函数
void DeleteTailLinkList(pList list)
{
	DeleteLinkList(list, list->count);
}

//顺序输出函数
void ShowLinkLIst1(pList list)
{
	assert(list != NULL);
	Node *p = list->head;
	while( p->next != list->head)
	{
		printf("%3d",p->data);
		p = p->next;
	}
	printf("%3d\n",p->data);
}

void ShowLinkLIst2(pList list)
{
	assert(list != NULL);
	Node *p = list->head;
	int tmp = list->count;
	while(tmp > 0)
	{
		printf("%3d",p->data);
		p =p->next;
		tmp --;
	}
	printf("\n");
}
