#include "Queue.h"

int main()
{
	Queue queue;
	InitQueue(&queue);
	for(int i = 0; i < 10; i++)
	{
		PushQueue(&queue, i * 10 +2);
	}
	int tmp = 0;
	for( int j = 0; j < 10; j++)  
	{
		PopQueue(&queue, &tmp);
		printf("%3d",tmp);
	}
	printf("\n");
	DestroyQueue(&queue);
	return 0;
}