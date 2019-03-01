/*
������
*********************************************************************
ʱ�临�Ӷȣ�O(nlogn)��//log��2Ϊ��
�ռ临�Ӷȣ�O(1)��
���ȶ�
˼�룺�����������й���ɶ�������������������Ѻ󽻻�ͷ��β��������ȥ���һ��������ʣ�µ������ֵ���������
Ȼ�󽻻�ͷ��β����������ѭ�����������򣺴������ϣ���������
*********************************************************************
*/

#include <stdio.h>

//����һ�Σ�����parentΪ�±�ĸ��ڵ�Ķ���������������
void Once_Adjust(int *arr, int len, int parent)
{
	int tmp = arr[parent];//�Ȱ���˵ĸ��ڵ��ֵ��������
	int child = parent * 2 + 1;//ͨ�����ڵ��õ��ø��ڵ�����ӵ�ֵ
	while(child < len)//ֻҪ���ӻ��к��ӣ���ѭ���Ƚϵ���
	{
		if(child + 1 < len && arr[child] < arr[child + 1]  )//�������ӵ������£��ñ���child������Ӻ��Һ����нϴ�һ�����±�
		{
			child++;
		}
		if(tmp > arr[child])//�����˵ĸ��ڵ�ֵ�������к��ӣ���ֱ������ѭ�����ɲο������ص���⣩
		{
			break;
		}
		arr[parent] = arr[child];//��ֵ��ĺ��ӷ��ڸ��ڵ㴦
		parent = child;//�����޸ĳɸ��ڵ㣬������һ��ѭ���Ƚϵ���
		child = 2 * parent + 1;//Ѱ�Һ��ӵ�����
	}
	arr[parent] = tmp;//����˸��ڵ�ŵ�����Ŀ�λ����
}

//����������������ʹ���Ϊ����
void Heap_Adjust(int *arr, int len)
{
	int start = (len - 2)/2;//�ҵ����һ�����ڵ�
	while( start >= 0)//�����һ�����ڵ���ѭ��������һ��һ����ǰ�ߣ�һ��һ������
	{
		Once_Adjust(arr, len, start);//ÿ�ε�������һ�ε�������
		start--;
	}
}

//����������
void Swap( int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//�������ʵ��
void Heap(int *arr, int len)
{
	Heap_Adjust(arr, len);//�Ƚ������������������
	int length = len - 1;
	while( length > 0)
	{
		Swap(&arr[0], &arr[length]);//��������ͷ��β��ֵ����Ϊÿ�ε��������Ѻ������ͷһ������������
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