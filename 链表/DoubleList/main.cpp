#include"DoubleList.h"

int main()
{
	Doublelist list;
	Doublelist *p = &list;
	InitDoublelist(&list); //��ʼ������ 

	printf("count3 =  %d\n",p->count);
	for( int i = 0; i < 5; i++ )
	{
		InsertDoublelist(&list,i * 10 ,i);  //����ڵ㺯��
		Show1(&list);//˳�����������ݺ���
	}
	Show1(&list);//˳�����������ݺ���

	InsertTailDoublelist(&list,88);
	InsertHeadDoublelist (&list,99);
	Show2(&list);
	Reverseshow(&list);//�������������ݺ���

	for( int i = 4; i > 0; i--)//ɾ��ǰ�ĸ����
	{
		DeleteDoublelist(&list,i);//ɾ����㺯��
		Show2(&list);//˳�����������ݺ���
	}
	Show2(&list);//˳�����������ݺ���
	return 0;
}



