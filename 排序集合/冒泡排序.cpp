/*
冒泡排序
*********************************************************************
时间复杂度（O(N)--O(N^2)）
空间复杂度（O(1)）
稳定
思想：带排序数据按照顺序次次两两相比较，将较大的数据依此往后挪
*********************************************************************
*/
#include <stdio.h>
#include <string.h>

void BubbleSort(int *arr, int len)
{
	int tmp = 0;
	for(int i = 0; i < len - 1; i++)//  因为n个数进行n - 1 趟循环就可以变得有序所以只需要
	{                               //len - 1趟循环
		for(int j = 0; j < len - 1 - i; j++)//   因为每一趟循环都会让最大的数交换到最后，所以
		{                                   //每一趟循环只需要对前len - 1 - i 个数排序
			if(arr[j] > arr[j + 1]) //比较两个相邻的数
			{
				tmp = arr[j];   //如果前一个数比后一个数就交换两个数的位置
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = {3,47,3,8,4,72,38,49,2,74,2,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	BubbleSort(arr, len);
	printf("len = %d\n",len);
	printf("arr =");
	for( int i = 0; i < len ; i++)
	{
		printf("%3d",arr[i]);
	}
	return 0;
}
