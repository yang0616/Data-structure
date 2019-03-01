#include "LinkList.h"

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

//��ͷ��㺯��
void InsertHeadLinkList(Plist list, ElemType val)
{
	InsertLinkList(list, val, 0);
}

//��β��㺯��
void InsertTailLinkList(Plist list, ElemType val)
{
	InsertLinkList(list, val, list->count);
}

//ɾ����㺯��
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

//ɾͷ��㺯��
void DeleteHeadLinkList(Plist list)
{
	DeleteLinkList(list, 1);
}

//ɾβ��㺯��
void DeleteTailLinkList(Plist list)
{
	DeleteLinkList(list, list->count);
}

//˳���������
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
}

//���ٺ���
void Destroy(Plist list)
{
	assert(list != NULL);
	Node *p = &list->head;
	//while(p->next != NULL)//����ָ�����ѭ���������Ϊÿ��ɾ��ͷ�����ָ���ͷŵ����������� �������ԣ�
	//{
	//    p = p->next;
	// 	  DeleteHeadLinkList(list);		
	//}

	while( list->count > 0)  //����count����ѭ��
	{
		DeleteHeadLinkList(list);
	}
	printf("OK\n");
}