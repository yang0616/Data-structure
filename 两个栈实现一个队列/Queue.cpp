#include "Queue.h"

//初始化栈
void InitStack(Pstack stack)
{
	assert(stack != NULL);
	stack->data = (ElemType *)malloc(sizeof(ElemType) * SIZE);
	stack->size = SIZE;
	stack->top = 0;
}

//栈判满
static int IsFullStack(Pstack stack)
{
	assert(stack != NULL);
	if(stack->top == SIZE)
	{
		return TRUE;
	}
	return FALSE;
}

//栈判空
static int IsEmptyStack(Pstack stack)
{
	assert(stack != NULL);
	if( stack->top == 0)
	{
		return TRUE;
	}
	return FALSE;
}

//将val插入栈内
int PushStack(Pstack stack, ElemType val)
{
	assert(stack != NULL);
	if(IsFullStack(stack))
	{
		return FALSE;
	}
	stack->data[stack->top++] = val;
	return TRUE;
}

//将栈顶的数值用res带出来后删掉
int PopStack(Pstack stack, ElemType *res )
{
	assert(stack != NULL);
	if(IsEmptyStack(stack))
	{
		return FALSE;
	}
	*res = stack->data[--stack->top];
	return TRUE;
}

//销毁栈
void DestroyStack(Pstack stack)
{
	assert(stack != NULL);
	free(stack->data);
	stack->data = NULL;
	stack->top = 0;
	stack->size = 0;
}

//初始化队列
void InitQueue(Pqueue queue)
{
	assert(queue != NULL);
	InitStack(&queue->sta);
	InitStack(&queue->stb);
}

//队列判空
//两个栈都为空时，队列才为空
static int IsEmptyQueue(Pqueue queue)
{
	assert(queue != NULL);
	if(IsEmptyStack(&queue->sta) && IsEmptyStack(&queue->stb))
	{
		return TRUE;
	}
	return FALSE;
}

//队列判满
//一个栈满，另外一个非空则队列满
static int IsFullQueue(Pqueue queue)
{
	assert(queue != NULL);
	if(IsFullStack(&queue->sta) && !IsEmptyStack(&queue->stb))
	{
		return TRUE;
	}
	return FALSE;
}

//入队
int PushQueue(Pqueue queue, ElemType val)
{
	assert(queue != NULL);
	if(IsFullQueue(queue))
	{
		return FALSE;
	}
	if(IsFullStack(&queue->sta))//如果a满b空，就把a中的元素放到b中，再将数据放到a中
	{
		int tmp = 0;
		while(!IsEmptyStack(&queue->stb))
		{
			PopStack(&queue->sta, &tmp);//a栈出数据
			PushStack(&queue->stb,tmp);//出的数据放进b栈
		}
	}
	PushStack(&queue->sta, val);//将val入a栈
	return TRUE;
}

//出队
int PopQueue(Pqueue queue, ElemType *res)
{
	assert(queue != NULL);
	if(IsEmptyQueue(queue))
	{
		return FALSE;
	}
	if(IsEmptyStack(&queue->stb))
	{
		int tmp = 0;
		while(!IsEmptyStack(&queue->sta))
		{	
			PopStack(&queue->sta, &tmp);//a栈出数据
			PushStack(&queue->stb, tmp);//出的数据放进b栈
		}
	}
	PopStack(&queue->stb, res);
	return TRUE;
}

//销毁队
void DestroyQueue(Pqueue queue)
{
	assert(queue != NULL);
	DestroyStack(&queue->sta);
	DestroyStack(&queue->stb);
}
