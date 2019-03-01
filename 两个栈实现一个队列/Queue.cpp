#include "Queue.h"

//��ʼ��ջ
void InitStack(Pstack stack)
{
	assert(stack != NULL);
	stack->data = (ElemType *)malloc(sizeof(ElemType) * SIZE);
	stack->size = SIZE;
	stack->top = 0;
}

//ջ����
static int IsFullStack(Pstack stack)
{
	assert(stack != NULL);
	if(stack->top == SIZE)
	{
		return TRUE;
	}
	return FALSE;
}

//ջ�п�
static int IsEmptyStack(Pstack stack)
{
	assert(stack != NULL);
	if( stack->top == 0)
	{
		return TRUE;
	}
	return FALSE;
}

//��val����ջ��
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

//��ջ������ֵ��res��������ɾ��
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

//����ջ
void DestroyStack(Pstack stack)
{
	assert(stack != NULL);
	free(stack->data);
	stack->data = NULL;
	stack->top = 0;
	stack->size = 0;
}

//��ʼ������
void InitQueue(Pqueue queue)
{
	assert(queue != NULL);
	InitStack(&queue->sta);
	InitStack(&queue->stb);
}

//�����п�
//����ջ��Ϊ��ʱ�����в�Ϊ��
static int IsEmptyQueue(Pqueue queue)
{
	assert(queue != NULL);
	if(IsEmptyStack(&queue->sta) && IsEmptyStack(&queue->stb))
	{
		return TRUE;
	}
	return FALSE;
}

//��������
//һ��ջ��������һ���ǿ��������
static int IsFullQueue(Pqueue queue)
{
	assert(queue != NULL);
	if(IsFullStack(&queue->sta) && !IsEmptyStack(&queue->stb))
	{
		return TRUE;
	}
	return FALSE;
}

//���
int PushQueue(Pqueue queue, ElemType val)
{
	assert(queue != NULL);
	if(IsFullQueue(queue))
	{
		return FALSE;
	}
	if(IsFullStack(&queue->sta))//���a��b�գ��Ͱ�a�е�Ԫ�طŵ�b�У��ٽ����ݷŵ�a��
	{
		int tmp = 0;
		while(!IsEmptyStack(&queue->stb))
		{
			PopStack(&queue->sta, &tmp);//aջ������
			PushStack(&queue->stb,tmp);//�������ݷŽ�bջ
		}
	}
	PushStack(&queue->sta, val);//��val��aջ
	return TRUE;
}

//����
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
			PopStack(&queue->sta, &tmp);//aջ������
			PushStack(&queue->stb, tmp);//�������ݷŽ�bջ
		}
	}
	PopStack(&queue->stb, res);
	return TRUE;
}

//���ٶ�
void DestroyQueue(Pqueue queue)
{
	assert(queue != NULL);
	DestroyStack(&queue->sta);
	DestroyStack(&queue->stb);
}
