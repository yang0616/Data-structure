#include "LinkList.h"

//初始化单链表函数
void InitLinkList(Plist list)
{
	list->count = 0;
	list->head.next = NULL;
}

//插入结点函数
static Node *BuyNode(ElemType val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;
	s->next = next;
	return s;
}
void InsertLinkList(Plist list, ElemType val, int pos)
{
	assert(list != NULL);

	if( pos < 0 || pos > list->count)
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
	Node *s = BuyNode(val, p->next);
	p->next = s;
	list->count ++;
}

//插头结点函数
void InsertHeadLinkList(Plist list, ElemType val)
{
	InsertLinkList(list, val, 0);
}

//插尾结点函数
void InsertTailLinkList(Plist list, ElemType val)
{
	InsertLinkList(list, val, list->count);
}

//删除结点函数
void DeleteLinkList(Plist list, int pos)
{
	assert(list != NULL);
	if( pos < 1 || pos > list->count)
	{
		printf("pos is error\n");
		return;
	}
	Node *p = &list->head;
	while( pos > 1)
	{
		p = p->next;
		pos --;
	}
	Node *s = p->next;
	p->next = s ->next;
	free(s);
	list->count--;
}

//删头结点函数
void DeleteHeadLinkList(Plist list)
{
	DeleteLinkList(list, 1);
}

//删尾结点函数
void DeleteTailLinkList(Plist list)
{
	DeleteLinkList(list, list->count);
}

//顺序输出函数
void Show(Plist list)
{
	assert(list != NULL);
	Node *p = &list->head;
	while( p->next!= NULL)
	{
		p = p->next;
		printf("%3d",p->data);	
	}	
	printf("\n");
}

//将单链表逆置
void InversionLinkList(Plist list)
{
	assert(list != NULL);
	Node *first = list->head.next;
	Node *middle = first->next;
	Node *last = middle->next;

	while(last->next != NULL)
	{
		if(first == list->head.next)
		{
			first->next = NULL;
		}
		middle->next = first;
		first = middle;
		middle = last;
		last = last->next;
	}
	middle->next = first;
	last->next = middle;
	list->head.next = last;
}

//销毁函数
void Destroy(Plist list)
{
	assert(list != NULL);
	Node *p = &list->head;
	//while(p->next != NULL)//采用指针遍历循环会出错，因为每次删除头结点会把指针释放掉（存在问题 继续调试）
	//{
	//    p = p->next;
	// 	  DeleteHeadLinkList(list);		
	//}

	while( list->count > 0)  //采用count遍历循环
	{
		DeleteHeadLinkList(list);
	}
	printf("OK\n");
}