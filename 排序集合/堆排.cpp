/*
堆排序
*********************************************************************
时间复杂度（O(nlogn)）//log以2为底
空间复杂度（O(1)）
不稳定
思想：将待排序数列构造成二叉树，将其调整成最大堆后交换头和尾的数，减去最后一个数，将剩下的数据又调整成最大堆
然后交换头和尾的数，依此循环（调整规则：从下往上，从右往左）
*********************************************************************
*/

#include <stdio.h>

//调整一次，把以parent为下标的父节点的二叉树调整成最大堆
void Once_Adjust(int *arr, int len, int parent)
{
	int tmp = arr[parent];//先把最顶端的父节点的值保存下来
	int child = parent * 2 + 1;//通过父节点拿到该父节点的左孩子的值
	while(child < len)//只要孩子还有孩子，就循环比较调整
	{
		if(child + 1 < len && arr[child] < arr[child + 1]  )//在右左孩子的条件下，让变量child标记左孩子和右孩子中较大一个的下标
		{
			child++;
		}
		if(tmp > arr[child])//如果最顶端的父节点值大于所有孩子，就直接跳出循环（可参考最大堆特点理解）
		{
			break;
		}
		arr[parent] = arr[child];//把值大的孩子放在父节点处
		parent = child;//孩子修改成父节点，进行下一趟循环比较调整
		child = 2 * parent + 1;//寻找孩子的左孩子
	}
	arr[parent] = tmp;//将最顶端父节点放到后面的空位置上
}

//调整整个二叉树，使其成为最大堆
void Heap_Adjust(int *arr, int len)
{
	int start = (len - 2)/2;//找到最后一个父节点
	while( start >= 0)//从最后一个父节点遵循调整规则一个一个往前走，一个一个调整
	{
		Once_Adjust(arr, len, start);//每次调整都调一次调整函数
		start--;
	}
}

//交换两个数
void Swap( int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//堆排序的实现
void Heap(int *arr, int len)
{
	Heap_Adjust(arr, len);//先将整个数组调整成最大堆
	int length = len - 1;
	while( length > 0)
	{
		Swap(&arr[0], &arr[length]);//交换数组头和尾的值（因为每次调整成最大堆后，数组的头一定是最大的数）
		Once_Adjust(arr, length, 0);
		length--;		
	}
}

int main()
{
	int arr[] = {83,5,0,3,4,7,6,51,34,51,374,856,143,765,1307,4865,7435};
	int len = sizeof(arr)/sizeof(arr[0]);
	Heap(arr, len);
	printf("len = %d\n",len);
	printf("arr =");
	for( int i = 0; i < len; i++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
	return 0;
}