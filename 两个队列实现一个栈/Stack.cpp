#include "Stack.h"

//��ʼ������
static void InitQueue(Pqueue queue)
{
	assert(queue != NULL);
	queue->data = (ElemType *)malloc(sizeof(ElemType) * SIZE);
	assert(queue->data);

	queue->head = 0;
	queue->tail = 0;
}

//����
 static int IsFullQueue(Pqueue queue)
{
	assert(queue != NULL);
	int tmp = queue->tail + 1;//ע�����ﲻҪ�ı�queue->tail��ֵ
	if(tmp % SIZE == queue->head )
	{
		return TRUE;
	}
	return FALSE;
}

//�п�
static int IsEmptyQueue(Pqueue queue)
{
	assert(queue != NULL);
	if(queue->head == queue->tail)
	{
		return TRUE;
	}
	return FALSE;
}

//�ڶ���ͷ��������
static int PushQueue(Pqueue queue, ElemType val)
{
	assert(queue != NULL);
	if(IsFullQueue(queue))
	{
		printf("Full\n");
		return FALSE;
	}
	//    ��β���������ݺ�β�±�������һ������ע����Ϊ�ڲ�������ʱҲ�п����ó����ݣ�����headҲ�����
	// ����headǰ��Ϊ�գ�����tail��֪��head��tail���� ��
	queue->data[queue->tail++] = val;
	queue->tail = queue->tail % SIZE;//��ͷβ����
	return TRUE;
}

//��ͷ����ֵ��res��������Ȼ��ɾ��
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

//���ٶ���
static void DestroyQueue(Pqueue queue)
{
	assert(queue != NULL);
	free(queue->data);
	queue->data = NULL;
	queue->head = 0;
	queue->tail = 0;
}

//��ʼ��ջ
void InitStack(Pstack stack)
{
	assert(stack != NULL);
	InitQueue(&stack->qua);
	InitQueue(&stack->qub);
}

//ջ�п�
//���ջ�е��������ж�Ϊ�գ���ջΪ��
static int IsEmptyStack(Pstack stack)
{
	assert(stack != NULL);
	if(IsEmptyQueue(&stack->qua) && IsEmptyQueue(&stack->qub))
	{
		return TRUE;
	}
	return FALSE;
}

//ջ����
//���ջ�е��������У�ֻҪ��һ������Ϊ������ջ��
static int IsFullStack(Pstack stack)
{
	assert(stack != NULL);
	if(IsFullQueue(&stack->qua) || IsFullQueue(&stack->qub))
	{
		return TRUE;
	}
	return FALSE;
}

//�ж�ջ������һ������Ϊ�գ���һ����Ϊ��
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

//��ջ
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

//��ջ
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

//����ջ
void DestroyStack(Pstack stack)
{
	assert(stack != NULL);
	DestroyQueue(&stack->qua);
	DestroyQueue(&stack->qua);
}








