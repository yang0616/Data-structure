#include "Practices.h"

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

//顺序输出单链表函数
void Show(Plist list)
{
	assert(list != NULL);
	Node *p = list->head.next;
	printf("The data of this single linked list is:");
	while( p != NULL)
	{
		printf("%3d",p->data);
		p = p->next;
	}
	printf("\n");
}

//构建一个带环的单链表,入环结点为第k个结点
void HasRingLinkList(Plist list,int k)
{
	assert(list != NULL);
	if( k < 1 || k > (list->count - 1))
	{
		printf("pos is error\n");
	}
	int i = list->count - k;
	Node *head = &list->head;
	Node *tail = &list->head;

	while(i > 0)//让头指针先跑
	{
		head = head->next;
		i--;
	}
	while( head->next != NULL)
	{
		head = head->next;
		tail = tail->next;
	}
	printf("last node'data:%d\n",head->data);
	head->next = tail;
	printf("ring node 'data:%d\n",head->next->data);
}

//单链表中找到数第K个结点  时间复杂度为O(n)（返回值为第k个结点的数据）
ElemType FindNode(Plist list, int k)
{
	assert(list != NULL);

	Node *first = &list->head;
	Node *last = &list->head;
	while( k > 0)
	{
		first = first->next;
		k--;
	}
	while( first->next != NULL)
	{
		first = first->next;
		last = last->next;
	}
	return last->next->data;
}//没有判断“K”是否为有效值
//改正：
int FindNode2(Plist list, int k, ElemType* res)//用指针“res”把第“K”个结点的值带出来
{
	assert(list != NULL);
	if(k < 0 || k > list->count) //判断“K”是否为有效值，如果失败返回0
	{
		return 0; 
	}

	Node *first = list->head.next;
	Node *last = first;
	while( k > 0)
	{
		first = first->next;
		k--;
	}
	while(first != NULL)
	{
		first = first->next;
		last = last->next;
	}
	*res = last->data; //用指针带回数据
	return 1; //成功返回1
}

//判断单链表是否有环，并且找到入环的第一个结点 时间复杂度为O(n)，（返回值为入环的结点位置）
void IsRing(Plist list)
{
	assert( list!= NULL);
	int tmpos = list->count;
	int i = 0;
	Node *p = &list->head;
	Node *s = &list->head;
	while( tmpos > 0)
	{
		p = p->next;
		tmpos --;
	}
	if( p->next != NULL)//最后一个结点的next域不为空，则代表此链表有环
	{
		p = p->next;
		while( 1 )
		{
			if( p->data == s->data )
			{
				printf("This list has a ring,the node of the entry loop is: %d\n",i);
				break;
			}
			s = s->next;
			i++;
		}		
	}
	else
	{
		printf("This list has no rings\n");
	}
}//
//改正
Node * IsRing2(Plist list)//利用思路2找结点
{
	assert(list != NULL);

	//先判断是否有环
	struct Node *fast = list->head.next;  //快指针，每次走两步
	struct Node *slow = fast; //慢指针，每次走一步
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if( fast == slow)
		{
			break;
		}
	}
	if(fast == NULL || fast->next == NULL)
	{
		return NULL; //如果进入这个if判断句，就证明链表没有环，返回一个空指针
	}

	//下面的代码开始找入环节点
	fast = fast->next; //让快指针先走一步，作为拆分后的链表的头
	slow->next = NULL;//从两个指针相遇的结点开始断开
	slow = list->head.next; //让慢指针作为拆分后另一个链表的头

	int f_count = 0; //分别求出两个链表的长度
	int s_count = 0;

	struct Node *new_fast = fast; //    利用末尾结点后继为空遍历两个链表求出结点数，但要注意的是，
	struct Node *new_slow = slow;//因为遍历链表头指针会走，所以得提前记住两个链表的头位置

	while( fast != NULL)
	{
		f_count++;
		fast = fast->next;
	}

	while( slow != NULL)
	{
		s_count++;
		slow = slow->next;
	}

	int count = 0; 
	if( f_count > s_count)// 比较两个链表的大小，让较长的一个链表先走结点差值
	{
		count = f_count - s_count;
		while(count > 0)
		{
			new_fast = new_fast->next;
			count --;
		}
	}
	else
	{
		count = s_count - f_count;
		while( count > 0)
		{
			new_slow = new_slow->next;
			count --;
		}
	}

	while( 1 ) //因为前面已经确定这两个链表会相交，所以当两个指针相遇就是入环结点
	{
		new_fast = new_fast->next;
		new_slow = new_slow->next;
		if( new_fast == new_slow)
		{
			return new_fast;
		}
	}
}

Node *IsRing3(Plist list)//利用思路3找结点
{
	assert(list != NULL);

	//先判断是否有环
	struct Node *fast = list->head.next; 
	struct Node *slow = fast; 
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if( fast == slow)
		{
			break;
		}
	}
	if(fast == NULL || fast->next == NULL)
	{
		return NULL; 

	}

	fast = fast->next;
	int circle_count = 1;
	while( fast != slow)//求环的大小
	{
		circle_count++;
		fast = fast->next;
	}
	fast = list->head.next; //把快慢指针都指向链表的头
	slow = fast;

	while( circle_count > 0)//让快指针先走一个环的大小
	{
		fast = fast->next;
		circle_count--;
	}

	while(1)//然后两个指针一起往后走
	{
		if(fast == slow)
		{
				return fast;
		}
		fast = fast->next;
		slow = slow->next;
	}
}

//构建两个相交的链表,相交的结点个数为k 
void IsIntresectLinklist(Plist firstlist,Plist secondlist,int k)
{
	assert(firstlist != NULL);
	assert(secondlist != NULL);

	int count = firstlist->count > secondlist->count ? secondlist->count : firstlist->count;
	if( k > count)
	{
		printf("pos is error\n");
	}
	int firstcoount = firstlist->count - k;
	int secondcount = secondlist->count - k;
	Node *firsrnode = &firstlist->head;
	Node *secondnode = &secondlist->head;
	while(firstcoount > 0)
	{
		firsrnode = firsrnode->next;
		firstcoount--;
	}
	while(secondcount > 0)
	{
		secondnode = secondnode->next;
		secondcount--;
	}
	secondnode->next = firsrnode->next;
}

//判断两个单链表是否相交  时间复杂度为O(n)，（如果相交返回值为真，如果不相交返回值为假）
int IsIntresect(Plist firstlist,Plist secondlist)
{
	assert(firstlist != NULL);
	assert(secondlist != NULL);

	int count = firstlist->count > secondlist->count ? secondlist->count : firstlist->count;
	printf("count = %d\n",count);
	int firstcount = firstlist->count - count;
	int secondcount = secondlist->count - count;
	Node *firstnode = &firstlist->head;
	Node *secondnode = &secondlist->head;
	while( firstcount > 0)
	{
		firstnode = firstnode->next;
		firstcount--;
	}
	while( secondcount > 0)
	{
		secondnode = secondnode->next;
		secondnode--;
	}
	
	while( firstnode->next != NULL)
	{
		if(firstnode->next == secondnode->next)
		{
			return 1;
		}
		firstnode = firstnode->next;
		secondnode = secondnode->next;
	}
	return 0;
}//思路正确但语句过于复杂
//改正
int IsIntresect2(Plist list1,Plist list2)
{
	assert( list1 != NULL);
	assert( list2 != NULL);
	struct Node *p = list1->head.next;
	struct Node *q = list2->head.next;

	if(list1->count > list2->count)
	{
		for( int i = 0; i < list1->count - list2->count; i++)
		{
			p = p->next;
		}
	}
	else
	{
		for( int i = 0; i < list2->count - list1->count; i++)
		{
			q = q->next;
		}
	}
	while( p != NULL)
	{
		if( p == q)
		{
			return 1;
		}
		p = p->next;
		q = q->next;
	}
	return 0;
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
}//没有考虑只有一个头结点时的情况，语句要简单
//改正：
void InversionLinkList1(Plist list)
{
	assert(list != NULL);
	struct Node *m = list->head.next;
	struct Node *f = NULL;

	if( m == NULL) //判断链表是否只有一个头结点，如果只有一个结点就直接返回
	{
		printf("error\n");
		return ;
	}
	struct Node *l = m->next;
	while(1)
	{
		m->next = f;
		f = m;
		m = l;
		if( m == NULL)
		{
			break;
		}
		l = l->next;
	}
	list->head.next = f;
}

//O(1)删除结点p
int DeleteNode(Plist list,Node *p)
{
	assert(list != NULL);
	struct Node *q = p->next;  //如果q指向的是最后一个结点时，这一步会使下面的语句崩掉
	p->data = q->data;
	p->next = q->next;
	free(q);
	list->count--;
	return 1;
}//为考虑特殊情况下的结点删除
//改正
int DeleteNode1(Plist list,Node *p)
{
	assert(list != NULL);
		
	if(p->next == NULL)//考虑链表中只有一个结点，或者删除的结点是最后一个结点的情况
	{
		struct Node *q = list->head.next;
		while(q->next != p)//注意这里不能用“q->next = NULL”来遍历链表寻找p结点的前驱，因为等q->next == NULL时，q已经指向的时最后一个结点了
		{
			q = q->next;
		}
		q->next = NULL;
		free(p);
		list->count--;
		return 1;
	}
	struct Node *q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	list->count--;
	return 1;
}

