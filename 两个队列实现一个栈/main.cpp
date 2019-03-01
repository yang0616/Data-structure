#include "Stack.h"


int main()
{
	Stack stack;
	InitStack(&stack);
	int res;

	for( int i = 0; i < 10; i++)
	{
		PushStack(&stack, i);
	}
	for(int i = 0; i < 9; i++)
	{
		PopStack(&stack, &res);
		printf("%3d",res);		
	}
	printf("\n");
	DestroyStack(&stack);
	return 0;
}