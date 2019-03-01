/*
直接插入排序
*********************************************************************
时间复杂度（O(n)---O(N^2)）
空间复杂度（O(1)）
稳定
思想：将待排序数列中第一个数据在前面已有序数列中找到合适的位置直接插进去
*********************************************************************
*/
#include <stdio.h>

void InsertSort(int *arr, int len)
{
	int j = 0;
	int tmp = 0;
	for( int i = 1; i < len; i++)//i用来控制循环次数，同时用i来标记待排序数列中第一个数据的下标
	{
		tmp = arr[i];
		for(j = i - 1; arr[j] > tmp && j >= 0; j--)//   j用来标记已有序数列中元素的下标，只要已有序数
		{                                  //列中的元素大于下标为i的元素，就将该数后移一个位置
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
		printf("j = %d\n",j);
	}

}
int main()
{
	int arr[] = {4, 15,13,454,315,41,3951,438,971,4836,743,86};
	int len = sizeof(arr)/sizeof(arr[0]);
	InsertSort(arr,len);
	printf("len = %d\n",len);
	printf("arr =");
	for( int i = 0; i < len; i++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
	return 0;
}
