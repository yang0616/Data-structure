#include"DoubleList.h"

int main()
{
	Doublelist list;
	Doublelist *p = &list;
	InitDoublelist(&list); //初始化链表 

	printf("count3 =  %d\n",p->count);
	for( int i = 0; i < 5; i++ )
	{
		InsertDoublelist(&list,i * 10 ,i);  //插入节点函数
		Show1(&list);//顺序输出结点数据函数
	}
	Show1(&list);//顺序输出结点数据函数

	InsertTailDoublelist(&list,88);
	InsertHeadDoublelist (&list,99);
	Show2(&list);
	Reverseshow(&list);//逆序输出结点数据函数

	for( int i = 4; i > 0; i--)//删除前四个结点
	{
		DeleteDoublelist(&list,i);//删除结点函数
		Show2(&list);//顺序输出结点数据函数
	}
	Show2(&list);//顺序输出结点数据函数
	return 0;
}



