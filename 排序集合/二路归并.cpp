/*
二路归并排序
*********************************************************************
时间复杂度（O(nlogn)）//log以2为底
空间复杂度（O(1)）
稳定
思想：现将数列相邻的两个元素分为一组，然后把相邻的两个组调整的有序后再将数列相邻的四个元素分为一组调整为
有序数列，然后在将相邻的8个元素分为一组调整，直到l2越界（调整规则：将每个段的头用L表示，尾用H表示，假设
相邻的两个段的头分别为L1和L2，尾分别为H1和H2，比较L1和L2所代表元素的大小，谁小谁先走一步，将较小的数存储
新开辟的空间上，然后再次比较L1和L2所代表元素的大小，直到L1越界或者L1越界停止循环）
*********************************************************************
*/

#include <stdio.h>
#include <malloc.h>

void Adjust_Merge(int *arr, int len, int width)//参数width代表将相邻的width个元素合并为一个小段
{
	int L1 = 0;
	int H1 = L1 + width - 1 < len ?  L1 + width - 1 : len - 1;
	int L2 = H1 + 1;
	int H2 = L2 + width - 1 < len ? L2 + width - 1 : len - 1;

	int *tmp = (int *)malloc(sizeof(int) * len);
	int subscript = 0;
	while(L1 < len)
	{
		while(L1 <= H1 && L2 <= H2)
		{
			if(arr[L1] <= arr[L2])
			{
				tmp[subscript++] = arr[L1++];
			}
			else
			{
				tmp[subscript++] = arr[L2++];
			}	
		}
		while(L1 <= H1)
		{
			tmp[subscript++] = arr[L1++];
		}
		while(L2 <= H2)
		{
			tmp[subscript++] = arr[L2++];
		}
		L1 = H2 + 1 ;
		H1 = L1 + width - 1 < len ? L1 + width - 1 : len - 1;
		L2 = H1 + 1 ;
		H2 = L2 + width - 1 < len ? L2 + width - 1 : len - 1;
	}
	for( int i = 0; i < len; i++)
	{
		arr[i] = tmp[i];
	}
	free(tmp);
}

void Merge( int *arr, int len)
{
	int i = 1;
	while( i < len)
	{
		Adjust_Merge(arr, len, i);
		i *= 2;
	}
}

int main()
{
	int arr[] = {89,314,5138,51,34,97,5314,4358,13465,431765,435,134,987,5431,561};
	int len = sizeof(arr)/sizeof(arr[0]);
	Merge(arr, len);
	printf("len = %d\n",len);
	printf("arr = ");
	for(int i = 0; i < len; i++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
	return 0;
}
