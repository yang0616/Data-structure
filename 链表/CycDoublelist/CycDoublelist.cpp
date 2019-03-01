#include"CycDoublelist.h"

//��ʼ��������
void InitCycDoublelist(pCycDouList list)
{
	assert( list != NULL);
	list->head = NULL;
	list->count = 0;
}

//�������õĹ��ܽ��к�����װ�������ڼ��ٴ�����ظ����֣���ߴ���������ʣ� ʹ����������۵����ã�
// �����½��ռ亯��            
static Node *BuyNode( ElemType val, Node *prev, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));   //Ϊ�½�������¿ռ�
	assert( s != NULL);

	s->data = val;    //���½�㸳ֵ

	if( (prev == NULL) | (next == NULL))//���ǲ�����ǵ�һ�����ʱ�����
	{
		s->prev = s->next = s; //���������ֻ��һ�����ҲҪ�ɻ�
	}
	else
	{
		s->prev = prev;
		s->next = next;
	}
	return s;
}

//�����㺯��
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
	if( list->head == NULL)//�����������޽��ʱ�Ĳ���
	{
		Node *s = BuyNode( val, NULL, NULL);
		list->head = s;
		list->count++;
		return;
	}
	if( ( pos < 0 ) | ( pos > list->count))//�ж�pos��ֵ�Ƿ���Ч
	{
		printf("pos is error\n");    
		return;
	}
	Node *p = list->head;
	if( pos == 0)       //    �����˫��ѭ������ͷλ�ò����㣬���൱���������ĩβ����ڵ��	          
	{                   //�������ͷָ��ָ�����һi������λ��
		p = p->prev;    //�ҵ����һ������λ��
		Insert(list, val, p); //���½��嵽���һ�����ĺ���
		list->head = list->head->prev;  //��ͷָ��ָ���²���Ľ��
		return;
	}
	else
	{
		while( pos > 1)//һ������µĽ�����
		{
			p = p->next;  //�ҵ�posλ�õĽ��ĵ�ַ
			pos --;
		}
		Insert(list, val, p);//���ò��뺯�������½��
		return;
	}
}

//ͷ�庯��
void  InsertHeadCycDoublelist (pCycDouList list,ElemType val)
{
	InsertCycDoublelist( list, val , 0);
}
//β�庯��
void InsertTailCycDoublelist(pCycDouList list,ElemType val)
{
	InsertCycDoublelist( list,  val ,list->count);
}

//ɾ����㺯��
void DeleteDouCycblelist(pCycDouList list,int pos)
{
	if(pos < 0 || pos > list->count)
	{
		printf("pos is error\n");
		return;
	}
	Node *p = list->head;
	if( pos == 1)//�������ɾ�����ǵ�һ�����͵øı�ͷָ��
	{
		list->head = list->head->next; //��ͷָ��ָ��ɾ�����ǰ�ĵڶ������
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
//ɾ��ͷ���ĺ���
void DeleteHeadCycDoublelist(pCycDouList list)
{
	assert(list != NULL);
	DeleteDouCycblelist(list,0);
}

//ɾ��β���ĺ���
void DeleteTailCycDoublelist(pCycDouList list)
{
	assert(list != NULL);
	DeleteDouCycblelist(list,list->count);
}

//˳�����������ݺ���
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

//�������������ݺ���
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

//����������
void DestroyCycDoublelist(pCycDouList list)
{
	assert(list != NULL);
	while(list->count != 0)
	{
		DeleteHeadCycDoublelist(list);
	}
}