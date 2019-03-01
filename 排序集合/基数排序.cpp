/*
��������
*********************************************************************
ʱ�临�Ӷȣ�O(d(n+rd))---O(d(n+r))��
�ռ临�Ӷȣ�O(rd+n)��
�ȶ�
˼�룺����һ��Ϊ������������Ҳ�������������鷳һ�㣩���ҵ������������������λ������ѭ��������Ӧ��λ����ֵ�����ݷŽ���Ӧ�Ķ�����
�ٰ��ն���˳�����ж����е�˳�������ѭ���Ĵ������������λ�����Ӹ�λ����λѭ������
��ע��������ʱ�临�ӶȺͿռ临�Ӷ���r����ؼ��ֵĻ�����d�����ȣ�n����ؼ��ֵĸ�����
*********************************************************************
*/

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0

typedef struct Queue
{
	int *data;
	int head;
	int tail;
}Queue, *PQueue;

//���������������λ��
int Max_Digit( int *arr, int len)
{
	int max = arr[0];
	int count= 0;
	for( int i = 1; i < len; i++)//�ҵ������е������
	{
		if( max < arr[i])
		{
			max = arr[i];
		}
	}
	while( max > 0)//���������λ��
	{
		max /= 10;
		count++;
	}
	return count;//�����������λ��
}

//������a�ĵ�digitλ����������������ֵ
int Digit(int a , int digit)
{
	int tmp = 0;
	while(digit > 0)
	{
		tmp = a % 10;
		a /= 10;
		digit--;
	}
	return tmp;
}

//��������
//(����Ҫ������ĳ�����Ϊ��������ȥ����Ϊ����ĳ����Ƕ��еĴ�С������Ϊ�˹��컷�ö��е�ͷβ������Ҫ���������)
static int IsFull(PQueue queue,int len)
{
	assert(queue != NULL);
	int tmp = queue->tail + 1;//ע�����ﲻҪ�ı�queue->tail��ֵ
	if(tmp % len == queue->head )
	{
		return TRUE;
	}
	return FALSE;
}

//�����п�
static int IsEmpty(PQueue queue)
{
	assert(queue != NULL);
	if(queue->head == queue->tail)
	{
		return TRUE;
	}
	return FALSE;
}

//������
//(����Ҫ������ĳ�����Ϊ��������ȥ����Ϊ����ĳ����Ƕ��еĴ�С������Ϊ�˹��컷�ö��е�ͷβ������Ҫ���������)
static int PushQueue(PQueue queue, int val, int len)
{
	assert(queue != NULL);
	if(IsFull(queue,len))
	{
		return FALSE;
	}
	//    ��β���������ݺ�β�±�������һ������ע����Ϊ�ڲ�������ʱҲ�п����ó����ݣ�����headҲ�����
	// ����headǰ��Ϊ�գ�����tail��֪��head��tail���� ��
	queue->data[queue->tail++] = val;
	queue->tail %= len;//��ͷβ����
	return TRUE;
}

//�����У���ͷ����ֵ��res��������Ȼ��ɾ����
static int PopQueue(PQueue queue, int  *res, int len)
{
	assert(queue != NULL);
	if(IsEmpty(queue))
	{
		return FALSE;
	}
	*res = queue->data[queue->head++];
	queue->head %= len;
	return TRUE;
}

//����һ��
void Digit_Queue(int *arr, int len,int digit)
{
	Queue queue[10];//����ʮ������
	for(int i = 0; i < 10; i++ )//��ʼ��10������
	{
		queue[i].data = (int *)malloc(sizeof(int) * len);
		queue[i].head = 0;
		queue[i].tail = 0;
	}
	for( int i = 0; i < len; i++)//�����������飬��������ÿ��Ԫ�ص�digitλ����Ȼ���뵽����Ӧ�Ķ�����
	{
		int tmp = Digit(arr[i], digit);//��arr[i]�ĵ�digitλ��ֵ
		PushQueue(&queue[tmp], arr[i],len);//��ŵ���Ӧ�Ķ�����
	}
	int i = 0;
	for(int j = 0; j < 10; j++)//����10�����г���������
	{
		while(!IsEmpty(&queue[j]))//ֻҪ���в�Ϊ�վ�����˶��е�����Ԫ��
		{
			PopQueue(&queue[j], &arr[i++],len);
		}
	}
	for( int i = 0; i < 10; i++)//�ͷ�10�����еĿռ�
	{
		free(queue[i].data);
		queue[i].data = NULL;

		queue[i].head = 0;
		queue[i].tail = 0;
	}
}

//��������ʵ��
void RedixSort(int *arr, int len)
{
	int count =  Max_Digit(arr, len);
	for( int i = 1; i <= count; i++)//����ѭ������
	{
		Digit_Queue(arr, len, i);
	}
}

//���Ժ���
int main()
{
	int arr[] = {89,4513,564,37,0,561,347,65,134,75,67,435,1034,765130,456130};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("len = %d\n",len);
	int max =  Max_Digit( arr, len);
	printf("max = %3d\n",max);

	//Digit_Queue(arr, len, 3);
	RedixSort(arr, len);
	printf("arr = "); 
	for( int i = 0; i < len; i++)
	{
		printf("%10d",arr[i]);
	}
	printf("\n");

	return 0;
}