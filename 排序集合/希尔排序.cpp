/*
希尔排序(缩小增量排序)
*********************************************************************
时间复杂度（O(n)---O(N^2)）
空间复杂度（O(1)）
不稳定
思想：将待排序数列按序分组，然后将每组数列按照直接插入的方式排序
*********************************************************************
*/
#include <stdio.h>

#define  INCREMENT  5

static void Once_Sort(int *arr, int len, int increment)//采用直接插入法排序，但是增量在改变
{
	int tmp = 0;
	int j = 0;
	for( int i = increment; i < len; i++)
	{
		tmp = arr[i];
		for(j = i - increment; arr[j] > tmp && j >= 0; )
		{
			arr[ j + increment] = arr[j];
			j  = j - increment;
		}
		arr[ j + increment] = tmp;
	}
}
void Shell(int *arr, int len)
{
	for(int i = INCREMENT; i > 0; i--)//i用来控制循环次数
	{
		Once_Sort(arr, len, i);//注意最后一次排序一定要将增量设置为“1”
	}
}
int main()
{
	int arr[] = {6,5,73,84,56,34,7,53,1056,1307};
	int len = sizeof(arr)/sizeof(arr[0]);
	Shell(arr, len);
	printf("len = %d\n",len);
	printf("arr =");
	for( int i = 0 ; i < len; i ++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
	return 0;
}