/*
��������
*********************************************************************
ʱ�临�Ӷȣ�O(nlogn)---O(N^2)��//log��2Ϊ��
�ռ临�Ӷȣ�O(nlogn)��//log��2Ϊ��
���ȶ�
˼�룺��ѡȡһ�����������������еĵ�һ�����ݣ��ó�����Ϊ�ȽϵĻ�׼��Ȼ��Ӻ���ǰ�ұȻ�׼С�Ľ������ǰ���ȱ��λ�ô�Ž�ȥ��
��δ�ǰ�����ұȻ�׼������ݷŵ������ȱ��λ�ã�ֱ��i��j�����󽫻�׼�Ž�������λ�á�����һ��������׼ǰ��������Ȼ�׼С����
׼����������Ȼ�׼�󣬻�׼��Ϊ����ġ�������ͬ�ķ�����������λ�÷�Ϊ����������֣�һֱ�ݹ���ȥ��ֱ���������ݱ������
(ע������������������ַ�ʽʵ��
                               1���ݹ�ʵ��--�ݹ�ʵ������ڷǵݹ�ʵ�ֲ��ȶ�������������Ĵ����п��Է��֣�������Ĺ����в���
Ҫ���ú���������ɲ��Ͽ��ٴ�СΪ48H�Ŀռ䣨ջĬ�ϵĿ��ٿռ䣩���������;�пռ䲻���Ż᷵�ش�����Ϣ�����ݻ�������״̬
������߼�����
							   2���ǵݹ�ʵ��--�ǵݹ�����ջʵ�ֵģ�����ڵݹ�ʵ�ָ��ȶ������һ�������ǰ�Ͱ���Ҫ�Ŀռ俪�ٺ�
����ռ䲻���� ��������ǰֱ�ӷ��ش�����Ϣ�����븴���߼�����)
*********************************************************************
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

static int Once_Sort(int *arr, int left, int right)
{
	int tmp = arr[left];//��ȡһ������Ϊ��׼�����������е�һ������
	while( left < right)//ֻҪǰ���±겻�����͵ý�ѭ��
	{
		while(left < right)//��û��������ǰ����right������ǰ��
		{
			if(arr[right] < tmp)//�������һ��Ԫ�رȻ�׼С���ͽ����ֵ�ŵ�ǰ���ȱ��λ�ã�arr[left]��λ�ã�Ȼ���˳�ѭ��
			{
				arr[left] = arr[right];
				break;
			}
			right--;
		}
		while( left < right)//   ��right�˳�ѭ����Ϳ�ʼ��left��ǰ���󲻶��ߣ�ֱ������һ��Ԫ�رȻ�׼�󣬾ͽ����ֵ�ŵ�����
		{                  //��ȱ��λ�ã�arr[right]��λ�ã�Ȼ���˳�ѭ��
			if(arr[left] > tmp)
			{
				arr[right] = arr[left];
				break;
			}
			left++;
		}		 
	}
	arr[left] = tmp;//����׼�ŵ�������λ��
	return left;//��������λ�÷��أ��Ա�Ѱ�ұ�����λ�÷ֿ���������
}

//�õݹ�����������У�ʹ��������
void Recursion_Once_Sort1(int *arr, int left, int right)
{
	int pos = Once_Sort(arr, left, right);//�ȵ�Once_Sort�����ҵ�һ�ε����󱻷�Ϊ�����ֵ�λ��(�ݹ�Ļ���)

	/*�����һ��������ֻ��һ��������������о�����������*/

	if(pos - left > 1)//�������Ϊ�����ֵ������ݶ���һ����������û�򣬾͵����Լ��ݹ����
	{
		Recursion_Once_Sort1(arr, left, pos - 1);
	}
	if(right - pos > 1)//�������Ϊ�����ֵ������ݶ���һ����������û�򣬾͵����Լ��ݹ����
	{
		Recursion_Once_Sort1(arr,pos + 1, right);
	}
}

void QuickSort1(int *arr, int len)
{
	Recursion_Once_Sort1(arr, 0, len - 1);//  ��һ��ʼ�������л�û�е�������������Ϊһ�����崫��ȥ��
	                                     //��ֵΪͷ�����ǡ�0������ֵΪβ����Ϊ��len - 1��
}

//�÷ǵݹ�����������У�ʹ��������
//�ǵݹ����ջʵ�֣���ջ����ű���׼�ֳ������ֵ�����λ��

typedef struct Stack//����ջ�ṹ
{
	int *data;
	int top;
}Stack;

void Recursion_Once_Sort2(int *arr, int left, int right)
{
	Stack stack;
	int size = (int )(log10(double(right - left))/log10(double(2)) + 1);//   �����size�Ϳ��������ʱ�临�Ӷ��й��ں�����ܽᣬ�һ���ϸ�����������
	                                                                 //sizeֻ��Ϊ�˼��ٿռ��˷ѣ���������Ϊʲô���������Խ�size��ʱ��ֵΪlen
	stack.data = (int *)malloc(sizeof(int) * 2 * size);//��Ϊÿ�δ����ݶ����������ݵ�ͷ��β--�������ݣ�����size��2��
	assert(stack.data != NULL);

	stack.top = 0;

	stack.data[stack.top++] = left; //�Ȱ��������ݶε�ͷ��β���ȥ����Ϊ�����ѭ�����ж�ջ�Ƿ�Ϊ��Ϊѭ������
	stack.data[stack.top++] = right;
	while(stack.top > 0)//ֻҪջ��Ϊ�գ��ʹ��������ݶ�������ģ��͵ý���ѭ������ʹ������
	{
		right = stack.data[--stack.top];//ע�⣬ջ���ص�Ϊ�Ƚ������ݾ͵��ȳ�����Ҫ�����ݶ�ǰ���±���
		left = stack.data[--stack.top];

		int pos = Once_Sort(arr, left, right);//������һ�ε���һ��

		if(pos - left > 1)//����󲿷ֵ����ݶ�û��ͽ���
		{
			stack.data[stack.top++] = left;
			stack.data[stack.top++] = pos - 1;
		}
		if(right - pos > 1)//����Ҳ��ֵ����ݶ�û��ͽ���
		{
			stack.data[stack.top++] = pos + 1;
			stack.data[stack.top++] = right;
		}		
	}
	free(stack.data);//ע��Ҫ�ͷ�ջ�ռ�
}

void QuickSort2(int *arr, int len)
{
	Recursion_Once_Sort2(arr, 0, len -  1);
}

int main()
{
	int arr[] = {34,65,148,756,103,4756,3417,564};
	int len = sizeof(arr) / sizeof(arr[0]);

	//QuickSort1(arr, len);//���Եݹ��¿�������

	QuickSort2(arr, len);//���Էǵݹ��¿�������

	printf("len = %d\n",len);
	printf("arr =");
	for( int i = 0; i < len; i++)
	{
		printf("%6d",arr[i]);
	}
	printf("\n");
}




















