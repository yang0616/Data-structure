#include "CycLinkLIst.h"

int main()
{
	Linklist list;
	InitLinkList(&list);
	for( int i = 0; i < 5; i++)
	{
		InsertLinkList(&list, i * 10, i); //�൱��5��β����
	}
	ShowLinkLIst1(&list);
	
	for( int j = 3; j > 0; j--)
	{
		DeleteLinkList(&list, j);
		ShowLinkLIst1(&list);
	}
	ShowLinkLIst2(&list);

	return 0;
}