#include"CycDoublelist.h"
int main()
{
	CycDoubleList list;
	InitCycDoublelist(&list);
	CycDoubleList *p = &list;

	//�������
	
	for( int i = 0; i < 5; i++)
	{ 
		 InsertCycDoublelist(&list, i, i);	
	}	
	printf("count1 = %d\n",p->count);

	//˳���������
	Show1(&list);

	//ɾ������
	for( int i = 5; i > 0; i--)
	{ 
		 DeleteDouCycblelist(&list,i);	
	}	
	printf("count1 = %d\n",p->count);
	Show1(&list);
/*
	//�����������
	Reverseshow(&list);

	//ͷ�����
	InsertHeadCycDoublelist (&list, 99);
	Show(&list);
	printf("count2 = %d\n",p->count);

	//β�����
	InsertTailCycDoublelist(&list, 88);
	Show(&list);
	Reverseshow(&list);
	printf("count3 = %d\n",p->count);
*/



	return 0;
}