#ifndef __CYCLINKLIST_H
#define __CYCLINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef  int ElemType;

//定义结点
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

/*
//定义带头结点的链表
typedef struct Linklist
{
	struct Node head; //头结点
	int count;
}Linklist, *pList;
*/

//定义不带头结点的链表
typedef struct Linklist
{
	struct Node *head; //头指针
	int count;
}Linklist, *pList;

//初始化链表
void InitLinkList(pList list);

//插入函数
void InsertLinkList(pList list, ElemType val, int pos);

//头插函数
void InsertHeadLinkList(pList list, ElemType val);

//尾插函数
void InsertTailLinkList(pList list, ElemType val);

//删除结点函数
void DeleteLinkList(pList list, int pos);

//删头函数
void DeleteHeadLinkList(pList list);

//删尾函数
void DeleteTailLinkList(pList list);

//顺序输出函数
void ShowLinkLIst1(pList list);
void ShowLinkLIst2(pList list);


#endif