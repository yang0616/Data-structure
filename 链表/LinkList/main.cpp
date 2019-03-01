#include "LinkList.h"

int main()
{
	Linklist list;
	InitLinkList(&list);
	Show(&list);
	for( int i = 0; i < 5; i++)
	{
		InsertLinkList(&list, i * 10, i);
	}
	Show(&list);
	DeleteLinkList(&list,1);
	Show(&list);
	Destroy(&list);
	return 0;
}