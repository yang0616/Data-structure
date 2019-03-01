#include "Queue.h"

//��ʼ������
void InitQueue(PQueue queue)
{
	assert(queue != NULL);
	queue->data = (ElemType *)malloc(sizeof(ElemType) * SIZE);
	assert(queue->data);

	queue->head = 0;
	queue->tail = 0;
}

//����
static int IsFull(PQueue queue)
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
static int IsEmpty(PQueue queue)
{
	assert(queue != NULL);
	if(queue->head == queue->tail)
	{
		return TRUE;
	}
	return FALSE;
}

//�ڶ���ͷ��������
int PushQueue(PQueue queue, ElemType val)
{
	assert(queue != NULL);
	if(IsFull(queue))
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

//���ٶ���
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