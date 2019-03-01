#ifndef __CYCDOUBLELISH_H
#define __CYCDOUBLELISH_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int ElemType;

//定义双向循环链表的结点
typedef struct Node
{
	struct Node *prev;
	ElemType data;
	struct Node *next;
}Node;

typedef struct CycDoubleList
{
	Node *head; //指向头结点的指针
	int count;  //保存指针个数的变量
}CycDoubleList, *pCycDouList;



//初始化链表函数
void InitCycDoublelist(pCycDouList list);    
//插入节点函数
void InsertCycDoublelist(pCycDouList list, ElemType val , int pos);
//头插函数
void  InsertHeadCycDoublelist (pCycDouList list,ElemType val);
//尾插函数
void InsertTailCycDoublelist(pCycDouList list,ElemType val);
//删除结点函数
void DeleteDouCycblelist(pCycDouList list,int pos);
//删除头结点的函数
void DeleteHeadCycDoublelist(pCycDouList list);
//删除尾结点的函数
void DeleteTailCycDoublelist(pCycDouList list);
//销毁链表函数
void DestroyCycDoublelist(pCycDouList list);
//顺序输出结点数据函数
void Show1(pCycDouList list);
void Show2(pCycDouList list);
//逆序输出结点数据函数
void Reverseshow(pCycDouList list);

#endif