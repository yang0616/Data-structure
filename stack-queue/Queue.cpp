#include "Queue.h"

//初始化队列
void InitQueue(PQueue queue)
{
	assert(queue != NULL);
	queue->data = (ElemType *)malloc(sizeof(ElemType) * SIZE);
	assert(queue->data);

	queue->head = 0;
	queue->tail = 0;
}

//判满
static int IsFull(PQueue queue)
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
static int IsEmpty(PQueue queue)
{
	assert(queue != NULL);
	if(queue->head == queue->tail)
	{
		return TRUE;
	}
	return FALSE;
}

//在队列头插入数据
int PushQueue(PQueue queue, ElemType val)
{
	assert(queue != NULL);
	if(IsFull(queue))
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
int PopQueue(PQueue queue, ElemType *res)
{
	assert(queue != NULL);
	if(IsEmpty(queue))
	{
		return FALSE;
	}
	*res = queue->data[queue->head++];
	queue->head %= SIZE;
	return TRUE;
}

//销毁队列
void Destroy(PQueue queue)
{
	assert(queue != NULL);
	free(queue->data);
	queue->data = NULL;
	queue->head = 0;
	queue->tail = 0;
}

void Show(PQueue queue)
{
	assert(queue != NULL);
	if(IsEmpty(queue))
	{
		printf("empty\n");
		return ;
	}
	printf("QUEUE'DATA =");
	int i = 0;
	for( i = queue->head; i % SIZE != queue->tail ; i %= SIZE)
	{
		printf("%3d",queue->data[i]);		
		i++;
	}
	printf("\n");
	printf("head= %d\n",queue->head);
	printf("tail= %d\n",queue->tail);
}