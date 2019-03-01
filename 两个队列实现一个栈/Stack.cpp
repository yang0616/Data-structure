#include "Stack.h"

//初始化队列
static void InitQueue(Pqueue queue)
{
	assert(queue != NULL);
	queue->data = (ElemType *)malloc(sizeof(ElemType) * SIZE);
	assert(queue->data);

	queue->head = 0;
	queue->tail = 0;
}

//判满
 static int IsFullQueue(Pqueue queue)
{
	assert(queue != NULL);
	int tmp = queue->tail + 1;//注意这里不要改变queue->tail的值
	if(tmp % SIZE == queue->head )
	{
		return TRUE;
	}
	return FALSE;
}

//判空
static int IsEmptyQueue(Pqueue queue)
{
	assert(queue != NULL);
	if(queue->head == queue->tail)
	{
		return TRUE;
	}
	return FALSE;
}

//在队列头插入数据
static int PushQueue(Pqueue queue, ElemType val)
{
	assert(queue != NULL);
	if(IsFullQueue(queue))
	{
		printf("Full\n");
		return FALSE;
	}
	//    在尾部插入数据后尾下标会向后走一步，（注意因为在插入数据时也有可能拿出数据，所以head也会后移
	// 导致head前面为空，所以tail，知道head和tail相遇 ）
	queue->data[queue->tail++] = val;
	queue->tail = queue->tail % SIZE;//让头尾相连
	return TRUE;
}

//将头部的值用res带出来，然后删掉
static int PopQueue(Pqueue queue, ElemType *res)
{
	assert(queue != NULL);
	if(IsEmptyQueue(queue))
	{
		printf("queue empty!\n");
		return FALSE;
	}
	*res = queue->data[queue->head++];
	queue->head %= SIZE;
	return TRUE;
}

//销毁队列
static void DestroyQueue(Pqueue queue)
{
	assert(queue != NULL);
	free(queue->data);
	queue->data = NULL;
	queue->head = 0;
	queue->tail = 0;
}

//初始化栈
void InitStack(Pstack stack)
{
	assert(stack != NULL);
	InitQueue(&stack->qua);
	InitQueue(&stack->qub);
}

//栈判空
//如果栈中的两个队列都为空，则栈为空
static int IsEmptyStack(Pstack stack)
{
	assert(stack != NULL);
	if(IsEmptyQueue(&stack->qua) && IsEmptyQueue(&stack->qub))
	{
		return TRUE;
	}
	return FALSE;
}

//栈判满
//如果栈中的两个队列，只要有一个队列为满，则栈满
static int IsFullStack(Pstack stack)
{
	assert(stack != NULL);
	if(IsFullQueue(&stack->qua) || IsFullQueue(&stack->qub))
	{
		return TRUE;
	}
	return FALSE;
}

//判断栈里面哪一个队列为空，哪一个不为空
static void Compare(Pstack stack, Pqueue *empty_queue, Pqueue *nonempty_queue)
{
	assert(stack != NULL);
	if(IsEmptyQueue(&stack->qua))
	{
		*empty_queue = &stack->qua;
		*nonempty_queue = &stack->qub;
	}
	else
	{
		*empty_queue = &stack->qub;
		*nonempty_queue = &stack->qua;
	}
}

//入栈
int PushStack(Pstack stack, ElemType val)
{
	assert(stack != NULL);
	if(IsFullStack(stack))
	{
		return FALSE;
	}
	Pqueue empty_queue = NULL;
	Pqueue nonempty_queue = NULL;
	Compare(stack, &empty_queue, &nonempty_queue);
	PushQueue(nonempty_queue, val);
	return TRUE;
}

//出栈
int PopStack(Pstack stack, ElemType *res)
{
	assert(stack != NULL);
	if(IsEmptyStack(stack))
	{
		return FALSE;
	}
	ElemType tmp;
	Pqueue empty_queue = NULL;
	Pqueue nonempty_queue = NULL;
	Compare(stack, &empty_queue, &nonempty_queue);
	while((nonempty_queue->head + 1) % SIZE != nonempty_queue->tail)
	{
		PopQueue(nonempty_queue, &tmp);
		PushQueue(empty_queue, tmp);
	}
	PopQueue(nonempty_queue, res);
	return TRUE;
}

//销毁栈
void DestroyStack(Pstack stack)
{
	assert(stack != NULL);
	DestroyQueue(&stack->qua);
	DestroyQueue(&stack->qua);
}








