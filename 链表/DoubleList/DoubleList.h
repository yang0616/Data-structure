#ifndef __DOUBLELIST_H
#define __DOUBLELIST_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int ElemType;

//定义每一个结点的结构
typedef struct Node
{
	struct Node *prev; //每个结点的前驱
	ElemType data;     //结点的值
	struct Node *next; //每个结点的后继	
}Node;

//定义双向链表结构
typedef struct Doublelist
{
	Node head;  //头结点
	int count;  //记录一个双向链表的结点的数目
}Doublelist, *pDoulist;

//初始化链表函数
void InitDoublelist(pDoulist list);    
//插入节点函数
void InsertDoublelist(pDoulist list, ElemType val , int pos);
//头插函数
void  InsertHeadDoublelist (pDoulist list,ElemType val);
//尾插函数
void InsertTailDoublelist(pDoulist list,ElemType val);
//删除结点函数
void DeleteDoublelist(pDoulist list,int pos);
//删除头结点的函数
void DeleteHeadDoublelist(pDoulist list);
//删除尾结点的函数
void DeleteTailDoublelist(pDoulist list);
//销毁链表函数
void DestroyDoublelist(pDoulist list);
//顺序输出结点数据函数1
void Show1(pDoulist list);
//顺序输出结点数据函数2
void Show2(pDoulist list);
//逆序输出结点数据函数
void Reverseshow(pDoulist list);

#endif
