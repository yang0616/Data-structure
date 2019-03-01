/*
��·�鲢����
*********************************************************************
ʱ�临�Ӷȣ�O(nlogn)��//log��2Ϊ��
�ռ临�Ӷȣ�O(1)��
�ȶ�
˼�룺�ֽ��������ڵ�����Ԫ�ط�Ϊһ�飬Ȼ������ڵ������������������ٽ��������ڵ��ĸ�Ԫ�ط�Ϊһ�����Ϊ
�������У�Ȼ���ڽ����ڵ�8��Ԫ�ط�Ϊһ�������ֱ��l2Խ�磨�������򣺽�ÿ���ε�ͷ��L��ʾ��β��H��ʾ������
���ڵ������ε�ͷ�ֱ�ΪL1��L2��β�ֱ�ΪH1��H2���Ƚ�L1��L2������Ԫ�صĴ�С��˭С˭����һ��������С�����洢
�¿��ٵĿռ��ϣ�Ȼ���ٴαȽ�L1��L2������Ԫ�صĴ�С��ֱ��L1Խ�����L1Խ��ֹͣѭ����
*********************************************************************
*/

#include <stdio.h>
#include <malloc.h>

void Adjust_Merge(int *arr, int len, int width)//����width�������ڵ�width��Ԫ�غϲ�Ϊһ��С��
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
