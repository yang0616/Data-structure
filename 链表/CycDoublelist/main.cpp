#include"CycDoublelist.h"
int main()
{
	CycDoubleList list;
	InitCycDoublelist(&list);
	CycDoubleList *p = &list;

	//≤Â»Î≤‚ ‘
	
	for( int i = 0; i < 5; i++)
	{ 
		 InsertCycDoublelist(&list, i, i);	
	}	
	printf("count1 = %d\n",p->count);

	//À≥–Ú ‰≥ˆ≤‚ ‘
	Show1(&list);

	//…æ≥˝≤‚ ‘
	for( int i = 5; i > 0; i--)
	{ 
		 DeleteDouCycblelist(&list,i);	
	}	
	printf("count1 = %d\n",p->count);
	Show1(&list);
/*
	//ƒÊ–Ú ‰≥ˆ≤‚ ‘
	Reverseshow(&list);

	//Õ∑≤Â≤‚ ‘
	InsertHeadCycDoublelist (&list, 99);
	Show(&list);
	printf("count2 = %d\n",p->count);

	//Œ≤≤Â≤‚ ‘
	InsertTailCycDoublelist(&list, 88);
	Show(&list);
	Reverseshow(&list);
	printf("count3 = %d\n",p->count);
*/



	return 0;
}