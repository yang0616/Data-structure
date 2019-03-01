#include"CycDoublelist.h"

//初始化链表函数
void InitCycDoublelist(pCycDouList list)
{
	assert( list != NULL);
	list->head = NULL;
	list->count = 0;
}

//（将共用的功能进行函数封装，有利于减少代码的重复出现，提高代码的利用率， 使代码更加美观的作用）
// 购买新结点空间函数            
static Node *BuyNode( ElemType val, Node *prev, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));   //为新结点申请新空间
	assert( s != NULL);

	s->data = val;    //给新结点赋值

	if( (prev == NULL) | (next == NULL))//考虑插入的是第一个结点时的情况
	{
		s->prev = s->next = s; //如果链表中只有一个结点也要成环
	}
	else
	{
		s->prev = prev;
		s->next = next;
	}
	return s;
}

//插入结点函数
static void Insert(pCycDouList list, ElemType val, Node *p)
{
	Node *s = BuyNode(val, p, p->next);
	p->next->prev = s;
	p->next = s;
	list->count++;
}

void InsertCycDoublelist(pCycDouList list, ElemType val , int pos)
{
	assert( list != NULL);
	if( list->head == NULL)//考虑链表中无结点时的插入
	{
		Node *s = BuyNode( val, NULL, NULL);
		list->head = s;
		list->count++;
		return;
	}
	if( ( pos < 0 ) | ( pos > list->count))//判断pos的值是否有效
	{
		printf("pos is error\n");    
		return;
	}
	Node *p = list->head;
	if( pos == 0)       //    如果在双向循环链表头位置插入结点，就相当于在链表的末尾插入节点后	          
	{                   //将链表的头指针指向最后一i个结点的位置
		p = p->prev;    //找到最后一个结点的位置
		Insert(list, val, p); //将新结点插到最后一个结点的后面
		list->head = list->head->prev;  //把头指针指向新插入的结点
		return;
	}
	else
	{
		while( pos > 1)//一般情况下的结点插入
		{
			p = p->next;  //找到pos位置的结点的地址
			pos --;
		}
		Insert(list, val, p);//引用插入函数插入新结点
		return;
	}
}

//头插函数
void  InsertHeadCycDoublelist (pCycDouList list,ElemType val)
{
	InsertCycDoublelist( list, val , 0);
}
//尾插函数
void InsertTailCycDoublelist(pCycDouList list,ElemType val)
{
	InsertCycDoublelist( list,  val ,list->count);
}

//删除结点函数
void DeleteDouCycblelist(pCycDouList list,int pos)
{
	if(pos < 0 || pos > list->count)
	{
		printf("pos is error\n");
		return;
	}
	Node *p = list->head;
	if( pos == 1)//考虑如果删除的是第一个结点就得改变头指针
	{
		list->head = list->head->next; //将头指针指向删除结点前的第二个结点
	}
	while( pos > 1)
	{
		p = p->next;
		pos --;
	}
	p->next->prev = p->prev;
	p->prev->next = p->next;

	free(p);
	list->count--;
}
//删除头结点的函数
void DeleteHeadCycDoublelist(pCycDouList list)
{
	assert(list != NULL);
	DeleteDouCycblelist(list,0);
}

//删除尾结点的函数
void DeleteTailCycDoublelist(pCycDouList list)
{
	assert(list != NULL);
	DeleteDouCycblelist(list,list->count);
}

//顺序输出结点数据函数
void Show1(pCycDouList list)
{
	assert( list != NULL);
	Node *p = list->head;
	int tmp = list->count;
	while(list->count > 0)
	{
		printf("%3d",p->data);
		p = p->next;
		list->count--;
	}
	list->count = tmp;
	printf("\n");
}

void Show2(pCycDouList list)
{
	assert( list!= NULL);
	int tmp = list->count;
	Node *p = list->head;
	while( tmp > 0)
	{
		printf("%3d",p->data);
		tmp --;
	}
	printf("%3d\n",p->data);
}

//逆序输出结点数据函数
void Reverseshow(pCycDouList list)
{
	assert( list != NULL);
	Node *p = list->head;
	int tmp = list->count;
	while( list->count > 1)
	{
		p = p->next;
		list->count--;
	}
	while( list->count != tmp)
	{
		printf("%3d",p->data);
		p = p->prev;
		list->count++;
	}
	printf("%3d",p->data);
	printf("\n");
}

//销毁链表函数
void DestroyCycDoublelist(pCycDouList list)
{
	assert(list != NULL);
	while(list->count != 0)
	{
		DeleteHeadCycDoublelist(list);
	}
}