/*
选择排序
*********************************************************************
时间复杂度（O(N^2)）
空间复杂度（O(1)）
不稳定
思想：在待排序数据中找到最小的数据，与待排序数据的第一个数据交换位置
*********************************************************************
*/
#include <stdio.h>
#include <string.h>

void SelectSort(int *arr, int len)
{
	int tmp = 0;//标记待排序中第一个数据
	int min = 0;//标记待排序的数据中，除第一个数后剩下的数据中最小数的下标
	for(int i = 0; i < len - 1; i++)//i控制循环次数
	{
		min = i;
		for( int j = i + 1; j < len ; j++ )//待排序数列中第一个数与后面的数开始挨个比较大小
		{
			if(arr[min] > arr[j]) //如果后面有一个数比第一个数小，就用min标记这个数的下标
			{
				min = j;
			}
		}//一直到j遍历完整个带排序数列，找到最小数的下标
        tmp = arr[i];//待排序中最小数与第一个数交换位置
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}
int main()//测试
{
	int arr[] = {12, 128,74, 2, 3,8, 47, 239, 2323,23232,45,565};
	int len = sizeof(arr)/sizeof(arr[0]);
	SelectSort(arr, len);
	printf("len = %d\n",len);
	printf("arr =");
	for( int i = 0; i < len ; i++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
	return 0;
}