#include "Practices.h"

int main()
{
	//��������������뻷���3
	Linklist list;
	InitLinkList(&list);

	for( int i = 0; i < 10; i++)
	{
		InsertLinkList(&list, i * 10, i);
	}
	Show(&list);
	HasRingLinkList(&list,1);
	Node *p = IsRing3(&list);;
	printf("�뻷��������Ϊ%d\n",p->data);
	


	//���������������뻷���2
/*	Linklist list;
	InitLinkList(&list);

	for( int i = 0; i < 10; i++)
	{
		InsertLinkList(&list, i * 10, i);
	}
	Show(&list);
	HasRingLinkList(&list,5);
	Node *p = IsRing2(&list);
	printf("�뻷��������Ϊ%d\n",p->data);
*/	


	//�������õ�����
/*	Linklist list;
	InitLinkList(&list);

	for( int i = 0; i < 4; i++)
	{
		InsertLinkList(&list, i * 10, i);
	}
	Show(&list);
	InversionLinkList1(&list);
	Show(&list);
*/


	//����O(1)ɾ�����p
/*	Linklist list1;
	Plist list2 = &list1;
	InitLinkList(&list1);

	for( int i = 0; i < 6; i++)
	{
		InsertLinkList(&list1, i * 10, i);
	}
	Show(&list1);

	Node *p = list2->head.next;
	DeleteNode(list2, p);

	Show(&list1);
*/	


//�������������Ƿ��ཻ
/*	Linklist list1;
	Linklist list2;
	InitLinkList(&list1);
	InitLinkList(&list2);
	for( int i = 0; i < 6; i++)
	{
		InsertLinkList(&list1, i * 10, i);
		InsertLinkList(&list2, i, i);
	}
	Show(&list1);
	Show(&list2);
	IsIntresectLinklist(&list1, &list2, 2);
	Show(&list1);
	Show(&list2);

	if(IsIntresect2(&list1,&list2))
	{
		printf("Is true\n");
	}
	else
	{
		printf("Is false\n");
	}
*/


//���Ե��������ҵ�����K�����
/*	ElemType res;
	if(FindNode2(&list, 3, &res))
	{
		printf("Looking for successful\n");
	}
	for(int i = 1; i < 6; i++)
	{
		if(FindNode2(&list, i, &res))
		{
			printf("������%d��������ֵΪ%d\n",i,res);
		}		
	}
*/
	return 0;
}