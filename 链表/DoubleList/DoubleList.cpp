#include"DoubleList.h"

//��ʼ��˫������
void InitDoublelist(pDoulist list)
{
	assert(list != NULL);

	list->head.next  = NULL;   //��ʼ��βָ��
	list->head.prev  = NULL;   //��ʼ��ͷָ��
	list->count = 0;           //��ʼ��������i

}

//��˫�������в���һ�����
	//1���ȿ�����ͨ����µĽ�����
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
	//2��������������Ľ������Ż����루list->count == 0  �� pos == list->count ��
static Node *BuyNode(ElemType val, Node *prev, Node *next )//������
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
	Node *s = BuyNode( val, p, p->next);//������
	if( p->next != NULL)//����β��
	{
		p->next->prev = s;
	}
	p->next = s;
	list->count++;
}

//ͷ�庯��
void  InsertHeadDoublelist (pDoulist list,ElemType val)
{
	InsertDoublelist(list, val, 0);//ͷ�庯�����Ե��ò��뺯���������뺯����pos��������Ϊ0
}

//β�庯��
void InsertTailDoublelist(pDoulist list,ElemType val)
{
	InsertDoublelist(list, val, list->count);//β�庯�����Ե��ò��뺯���������뺯����pos��������Ϊlist->count
}

//ɾ��˫�������е�һ�����
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

//ɾ��ͷ���ĺ���
void DeleteHeadDoublelist(pDoulist list)
{
	DeleteDoublelist(list,1);//ͷ����ɾ�����Ե���ɾ����������ɾ��������pos��������Ϊ1
}

//ɾ��β���ĺ���
void DeleteTailDoublelist(pDoulist list)
{
	DeleteDoublelist(list,list->count);//β����ɾ�����Ե���ɾ����������ɾ��������pos��������Ϊlist->count
}

//���˫�������е�����1
void Show1(pDoulist list)
{
	assert(list != NULL);
	Node *p = list->head.next;
	while( p != NULL)//��ָ�������������ָ����һ�����һ��
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

//�������˫�������е�����
void Reverseshow(pDoulist list)
{
	assert( list != NULL);
	Node *p = &list->head;
	while( p->next != NULL)//����ָ���ܵ����һ�����
	{
		p = p->next;
	}
	while( p->prev != NULL)//ָ�뿪ʼ��ǰ�ܣ�ָ����һ�����һ��ֵ
	{
		printf("%3d",p->data);
		p = p->prev;
	}
	printf("\n");
}
//����һ��˫������
void DestroyDoublelist(pDoulist list)
{
	assert(list != NULL);
	while( list->count > 0)
	{
		DeleteHeadDoublelist(list); //����ɾ��ͷ���ĺ���������ѭ���ķ�ʽÿ��ɾ��ͷ���
	}
}