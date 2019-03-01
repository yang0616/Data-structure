#include"CycLinkList.h"


//����ͷ����ѭ������
//��ʼ������
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
	if( next == NULL)//����������û�н��ʱ�����
	{
		p->next = p;
		return p;
	}
	p->next = next;
	return p;
}
//���뺯��
void InsertLinkList(pList list, ElemType val, int pos)
{
	if( pos < 0 || pos > list->count)
	{
		printf("pos is error\n");
		return ;
	}

	if(list->head == NULL)//����������û�н��ʱ�Ĳ���
	{
		list->head = BuyNode(val, NULL); //��ͷ��㸳ֵ
		list->count++;
		return;
	}
	Node *p = list->head;
	int tmpos = pos == 0 ? list->count : pos;//���ʱͷ����൱��β���ǰ��ͷָ��
	while( tmpos > 1)//��ָ���Ƶ�pos(tmpos)����λ��
	{
		p =p->next;
		tmpos --;
	}
	Node *s = BuyNode(val, p->next); //���½�������¿ռ�
	p->next = s;
	if(pos == 0) //���posΪ0�ʹ�����ͷ��,����Ҫ�ı�ͷָ���λ��
	{
		list->head = s;
	}
	list->count++; //���ӽ�����
}

//ͷ�庯��
void InsertHeadLinkList(pList list, ElemType val)
{
	InsertLinkList(list, val, 0);
}

//β�庯��
void InsertTailLinkList(pList list, ElemType val)
{
	InsertLinkList(list, val, list->count);
}

//ɾ����㺯��
void DeleteLinkList(pList list, int pos)
{
	assert(list != NULL);
	if(pos < 1 || pos > list->count)
	{
		printf("pos is error\n");
		return ;
	}
	if(list->count == 1) //ֻ��һ�����ʱ��ɾ��
	{
		free(list->head); //ֱ���ͷſռ�
		list->head = NULL;
		list->count--; //�������һ
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

//ɾͷ����
void DeleteHeadLinkList(pList list)
{
	DeleteLinkList(list, 1);
}

//ɾβ����
void DeleteTailLinkList(pList list)
{
	DeleteLinkList(list, list->count);
}

//˳���������
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
