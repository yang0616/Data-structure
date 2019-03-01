#include "Stack.h"

//初始化栈
void InitStack(Pstack stack)
{
	assert(stack != NULL);
	stack->data = (ElemType *)malloc(sizeof(ElemType) * SIZE);
	stack->size = SIZE;
	stack->top = 0;
}

int IsFull(Pstack stack)
{
	assert(stack != NULL);
	if(stack->top == SIZE)
	{
		return TRUE;
	}
	return FALSE;
}

void Expand(Pstack stack)
{
	assert(stack != NULL);

	stack->size = 2 * SIZE;
	ElemType *new_data = (ElemType *)malloc(sizeof(ElemType) * stack->size);
	assert(new_data != NULL);

	for( int i = 0; i < stack->top; i++)
	{
		new_data[i] = stack->data[i];
	}
	free(stack->data);
	stack->data = new_data;
}

//将val插入栈内
int PushStack(Pstack stack, ElemType val)
{
	assert(stack != NULL);
	if(IsFull(stack))
	{
		Expand(stack);
		if(IsFull(stack))
		{
			return FALSE;
		}
	}
	stack->data[stack->top++] = val;
	printf("top = %d\n",stack->top);
	return TRUE;
}
int IsEmpty(Pstack stack)
{
	assert(stack != NULL);
	if( stack->top == 0)
	{
		return TRUE;
	}
	return FALSE;
}

//将栈顶的数值用res带出来后删掉
int PopStack(Pstack stack, ElemType *res )
{
	assert(stack != NULL);
	if(IsEmpty(stack))
	{
		return FALSE;
	}
	*res = stack->data[--stack->top];
	return TRUE;
}

//销毁栈
void Destroy(Pstack stack)
{
	assert(stack != NULL);
	free(stack->data);
	stack->data = NULL;
	stack->top = 0;
	stack->size = 0;
}

void ShowStack(Pstack stack)
{
	assert(stack != NULL);
	for(int i = 0; i < stack->top; i++)
	{
		printf("%c",stack->data[i]);
	}
	printf("\n");
}
