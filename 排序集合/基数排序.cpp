/*
基数排序
*********************************************************************
时间复杂度（O(d(n+rd))---O(d(n+r))）
空间复杂度（O(rd+n)）
稳定
思想：数据一般为正整数（负数也可以做，但是麻烦一点），找到其中最大的数据求出其位数，再循环根据相应的位数的值将数据放进相应的队列中
再按照队列顺序将所有队列中的顺序输出，循环的次数是最大数的位数，从个位往高位循环调整
（注：在讨论时间复杂度和空间复杂度中r代表关键字的基数，d代表长度，n代表关键字的个数）
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

//求数列中最大数的位数
int Max_Digit( int *arr, int len)
{
	int max = arr[0];
	int count= 0;
	for( int i = 1; i < len; i++)//找到数组中的最大数
	{
		if( max < arr[i])
		{
			max = arr[i];
		}
	}
	while( max > 0)//求最大数的位数
	{
		max /= 10;
		count++;
	}
	return count;//返回最大数的位数
}

//求数字a的第digit位（从右往左数）的值
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

//队列判满
//(这里要把数组的长度作为参数传进去，因为数组的长度是队列的大小，函数为了构造环让队列的头尾相连，要用这个参数)
static int IsFull(PQueue queue,int len)
{
	assert(queue != NULL);
	int tmp = queue->tail + 1;//注意这里不要改变queue->tail的值
	if(tmp % len == queue->head )
	{
		return TRUE;
	}
	return FALSE;
}

//队列判空
static int IsEmpty(PQueue queue)
{
	assert(queue != NULL);
	if(queue->head == queue->tail)
	{
		return TRUE;
	}
	return FALSE;
}

//进队列
//(这里要把数组的长度作为参数传进去，因为数组的长度是队列的大小，函数为了构造环让队列的头尾相连，要用这个参数)
static int PushQueue(PQueue queue, int val, int len)
{
	assert(queue != NULL);
	if(IsFull(queue,len))
	{
		return FALSE;
	}
	//    在尾部插入数据后尾下标会向后走一步，（注意因为在插入数据时也有可能拿出数据，所以head也会后移
	// 导致head前面为空，所以tail，知道head和tail相遇 ）
	queue->data[queue->tail++] = val;
	queue->tail %= len;//让头尾相连
	return TRUE;
}

//出队列（将头部的值用res带出来，然后删掉）
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

//调整一次
void Digit_Queue(int *arr, int len,int digit)
{
	Queue queue[10];//定义十个队列
	for(int i = 0; i < 10; i++ )//初始化10个队列
	{
		queue[i].data = (int *)malloc(sizeof(int) * len);
		queue[i].head = 0;
		queue[i].tail = 0;
	}
	for( int i = 0; i < len; i++)//遍历整个数组，求数列中每个元素第digit位的数然后入到在相应的队列中
	{
		int tmp = Digit(arr[i], digit);//求arr[i]的第digit位的值
		PushQueue(&queue[tmp], arr[i],len);//存放到对应的队列中
	}
	int i = 0;
	for(int j = 0; j < 10; j++)//遍历10个队列出所有数据
	{
		while(!IsEmpty(&queue[j]))//只要队列不为空就输出此队列的所有元素
		{
			PopQueue(&queue[j], &arr[i++],len);
		}
	}
	for( int i = 0; i < 10; i++)//释放10个队列的空间
	{
		free(queue[i].data);
		queue[i].data = NULL;

		queue[i].head = 0;
		queue[i].tail = 0;
	}
}

//基数排序实现
void RedixSort(int *arr, int len)
{
	int count =  Max_Digit(arr, len);
	for( int i = 1; i <= count; i++)//控制循环次数
	{
		Digit_Queue(arr, len, i);
	}
}

//测试函数
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