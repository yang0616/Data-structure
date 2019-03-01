/*
快速排序
*********************************************************************
时间复杂度（O(nlogn)---O(N^2)）//log以2为底
空间复杂度（O(nlogn)）//log以2为底
不稳定
思想：先选取一个数（待排序数据中的第一个数据）拿出来作为比较的基准，然后从后往前找比基准小的将其放在前面空缺的位置存放进去，
其次从前往后找比基准大的数据放到后面空缺的位置，直到i和j相遇后将基准放进相遇的位置。这样一趟下来基准前面的数都比基准小，基
准后面的数都比基准大，基准成为有序的。再用相同的方法处理被相遇位置分为两半的两部分，一直递归下去，直到所有数据变得有序
(注：快速排序可以用两种方式实现
                               1、递归实现--递归实现相对于非递归实现不稳定，但是在下面的代码中可以发现，在排序的过程中不断
要调用函数自身，造成不断开辟大小为48H的空间（栈默认的开辟空间），如果排序途中空间不够才会返回错误信息，数据还是无序状态
代码简单逻辑清晰
							   2、非递归实现--非递归是用栈实现的，相对于递归实现更稳定，并且会在排序前就把需要的空间开辟好
如果空间不够， 就在排序前直接返回错误信息，代码复杂逻辑复杂)
*********************************************************************
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

static int Once_Sort(int *arr, int left, int right)
{
	int tmp = arr[left];//先取一个数作为基准（待排序数列第一个数）
	while( left < right)//只要前后下标不相遇就得进循环
	{
		while(left < right)//在没有相遇的前提下right不断向前走
		{
			if(arr[right] < tmp)//如果遇到一个元素比基准小，就将这个值放到前面空缺的位置（arr[left]的位置）然后退出循环
			{
				arr[left] = arr[right];
				break;
			}
			right--;
		}
		while( left < right)//   在right退出循环后就开始让left从前往后不断走，直到遇到一个元素比基准大，就将这个值放到后面
		{                  //空缺的位置（arr[right]的位置）然后退出循环
			if(arr[left] > tmp)
			{
				arr[right] = arr[left];
				break;
			}
			left++;
		}		 
	}
	arr[left] = tmp;//将基准放到相遇的位置
	return left;//将相遇的位置返回，以便寻找被相遇位置分开的两部分
}

//用递归调整整个数列，使其变得有序
void Recursion_Once_Sort1(int *arr, int left, int right)
{
	int pos = Once_Sort(arr, left, right);//先调Once_Sort函数找到一次调整后被分为两部分的位置(递归的基数)

	/*如果在一个数列中只右一个数，则这个数列就是有序数列*/

	if(pos - left > 1)//如果被分为两部分的左数据段有一个以上数据没序，就调用自己递归调整
	{
		Recursion_Once_Sort1(arr, left, pos - 1);
	}
	if(right - pos > 1)//如果被分为两部分的右数据段有一个以上数据没序，就调用自己递归调整
	{
		Recursion_Once_Sort1(arr,pos + 1, right);
	}
}

void QuickSort1(int *arr, int len)
{
	Recursion_Once_Sort1(arr, 0, len - 1);//  在一开始整个数列还没有调整过，所以作为一个整体传进去，
	                                     //左值为头所以是“0”，右值为尾所以为“len - 1”
}

//用非递归调整整个数列，使其变得有序
//非递归得用栈实现，用栈来存放被基准分成两部分的数据位置

typedef struct Stack//定义栈结构
{
	int *data;
	int top;
}Stack;

void Recursion_Once_Sort2(int *arr, int left, int right)
{
	Stack stack;
	int size = (int )(log10(double(right - left))/log10(double(2)) + 1);//   这里的size和快速排序的时间复杂度有关在后面的总结，我会详细分析，这里的
	                                                                 //size只是为了减少空间浪费，如果不清楚为什么这样做可以将size暂时赋值为len
	stack.data = (int *)malloc(sizeof(int) * 2 * size);//因为每次存数据都是两段数据的头和尾--两对数据，所以size是2倍
	assert(stack.data != NULL);

	stack.top = 0;

	stack.data[stack.top++] = left; //先把整个数据段的头和尾存进去，因为下面的循环是判断栈是否为空为循环条件
	stack.data[stack.top++] = right;
	while(stack.top > 0)//只要栈不为空，就代表还有数据段是无序的，就得进入循环调整使其有序
	{
		right = stack.data[--stack.top];//注意，栈的特点为先进的数据就得先出，不要把数据段前后下标搞混
		left = stack.data[--stack.top];

		int pos = Once_Sort(arr, left, right);//数据入一次调整一次

		if(pos - left > 1)//如果左部分的数据段没序就进入
		{
			stack.data[stack.top++] = left;
			stack.data[stack.top++] = pos - 1;
		}
		if(right - pos > 1)//如果右部分的数据段没序就进入
		{
			stack.data[stack.top++] = pos + 1;
			stack.data[stack.top++] = right;
		}		
	}
	free(stack.data);//注意要释放栈空间
}

void QuickSort2(int *arr, int len)
{
	Recursion_Once_Sort2(arr, 0, len -  1);
}

int main()
{
	int arr[] = {34,65,148,756,103,4756,3417,564};
	int len = sizeof(arr) / sizeof(arr[0]);

	//QuickSort1(arr, len);//测试递归下快速排序

	QuickSort2(arr, len);//测试非递归下快速排序

	printf("len = %d\n",len);
	printf("arr =");
	for( int i = 0; i < len; i++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
}




















