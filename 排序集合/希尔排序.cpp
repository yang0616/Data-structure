/*
ϣ������(��С��������)
*********************************************************************
ʱ�临�Ӷȣ�O(n)---O(N^2)��
�ռ临�Ӷȣ�O(1)��
���ȶ�
˼�룺�����������а�����飬Ȼ��ÿ�����а���ֱ�Ӳ���ķ�ʽ����
*********************************************************************
*/
#include <stdio.h>

#define  INCREMENT  5

static void Once_Sort(int *arr, int len, int increment)//����ֱ�Ӳ��뷨���򣬵��������ڸı�
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
	for(int i = INCREMENT; i > 0; i--)//i��������ѭ������
	{
		Once_Sort(arr, len, i);//ע�����һ������һ��Ҫ����������Ϊ��1��
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