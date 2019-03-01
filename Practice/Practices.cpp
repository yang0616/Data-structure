#include "Practices.h"

//��ʼ����������
void InitLinkList(Plist list)
{
	list->count = 0;
	list->head.next = NULL;
}

//�����㺯��
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

//˳�������������
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

//����һ�������ĵ�����,�뻷���Ϊ��k�����
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

	while(i > 0)//��ͷָ������
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

//���������ҵ�����K�����  ʱ�临�Ӷ�ΪO(n)������ֵΪ��k���������ݣ�
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
}//û���жϡ�K���Ƿ�Ϊ��Чֵ
//������
int FindNode2(Plist list, int k, ElemType* res)//��ָ�롰res���ѵڡ�K��������ֵ������
{
	assert(list != NULL);
	if(k < 0 || k > list->count) //�жϡ�K���Ƿ�Ϊ��Чֵ�����ʧ�ܷ���0
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
	*res = last->data; //��ָ���������
	return 1; //�ɹ�����1
}

//�жϵ������Ƿ��л��������ҵ��뻷�ĵ�һ����� ʱ�临�Ӷ�ΪO(n)��������ֵΪ�뻷�Ľ��λ�ã�
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
	if( p->next != NULL)//���һ������next��Ϊ�գ������������л�
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
//����
Node * IsRing2(Plist list)//����˼·2�ҽ��
{
	assert(list != NULL);

	//���ж��Ƿ��л�
	struct Node *fast = list->head.next;  //��ָ�룬ÿ��������
	struct Node *slow = fast; //��ָ�룬ÿ����һ��
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
		return NULL; //����������if�жϾ䣬��֤������û�л�������һ����ָ��
	}

	//����Ĵ��뿪ʼ���뻷�ڵ�
	fast = fast->next; //�ÿ�ָ������һ������Ϊ��ֺ�������ͷ
	slow->next = NULL;//������ָ�������Ľ�㿪ʼ�Ͽ�
	slow = list->head.next; //����ָ����Ϊ��ֺ���һ�������ͷ

	int f_count = 0; //�ֱ������������ĳ���
	int s_count = 0;

	struct Node *new_fast = fast; //    ����ĩβ�����Ϊ�ձ�����������������������Ҫע����ǣ�
	struct Node *new_slow = slow;//��Ϊ��������ͷָ����ߣ����Ե���ǰ��ס���������ͷλ��

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
	if( f_count > s_count)// �Ƚ���������Ĵ�С���ýϳ���һ���������߽���ֵ
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

	while( 1 ) //��Ϊǰ���Ѿ�ȷ��������������ཻ�����Ե�����ָ�����������뻷���
	{
		new_fast = new_fast->next;
		new_slow = new_slow->next;
		if( new_fast == new_slow)
		{
			return new_fast;
		}
	}
}

Node *IsRing3(Plist list)//����˼·3�ҽ��
{
	assert(list != NULL);

	//���ж��Ƿ��л�
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
	while( fast != slow)//�󻷵Ĵ�С
	{
		circle_count++;
		fast = fast->next;
	}
	fast = list->head.next; //�ѿ���ָ�붼ָ�������ͷ
	slow = fast;

	while( circle_count > 0)//�ÿ�ָ������һ�����Ĵ�С
	{
		fast = fast->next;
		circle_count--;
	}

	while(1)//Ȼ������ָ��һ��������
	{
		if(fast == slow)
		{
				return fast;
		}
		fast = fast->next;
		slow = slow->next;
	}
}

//���������ཻ������,�ཻ�Ľ�����Ϊk 
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

//�ж������������Ƿ��ཻ  ʱ�临�Ӷ�ΪO(n)��������ཻ����ֵΪ�棬������ཻ����ֵΪ�٣�
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
}//˼·��ȷ�������ڸ���
//����
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

//������������
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
}//û�п���ֻ��һ��ͷ���ʱ����������Ҫ��
//������
void InversionLinkList1(Plist list)
{
	assert(list != NULL);
	struct Node *m = list->head.next;
	struct Node *f = NULL;

	if( m == NULL) //�ж������Ƿ�ֻ��һ��ͷ��㣬���ֻ��һ������ֱ�ӷ���
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

//O(1)ɾ�����p
int DeleteNode(Plist list,Node *p)
{
	assert(list != NULL);
	struct Node *q = p->next;  //���qָ��������һ�����ʱ����һ����ʹ�����������
	p->data = q->data;
	p->next = q->next;
	free(q);
	list->count--;
	return 1;
}//Ϊ������������µĽ��ɾ��
//����
int DeleteNode1(Plist list,Node *p)
{
	assert(list != NULL);
		
	if(p->next == NULL)//����������ֻ��һ����㣬����ɾ���Ľ�������һ���������
	{
		struct Node *q = list->head.next;
		while(q->next != p)//ע�����ﲻ���á�q->next = NULL������������Ѱ��p����ǰ������Ϊ��q->next == NULLʱ��q�Ѿ�ָ���ʱ���һ�������
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

