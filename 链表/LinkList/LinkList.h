#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;
 
//定义带头结点的单链表
typedef struct Node //定义结点
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Linklist //定义链表
{
	int count;
	struct Node head;
}Linklist, *Plist;

//初始化单链表函数
void InitLinkList(Plist list);

//插入结点函数
void InsertLinkList(Plist list, ElemType val, int pos);

//插头结点函数
void InsertHeadLinkList(Plist list, ElemType val);

//插尾结点函数
void InsertTailLinkList(Plist list, ElemType val);

//删除结点函数
void DeleteLinkList(Plist list, int pos);

//删头结点函数
void DeleteHeadLinkList(Plist list);

//删尾结点函数
void DeleteTailLinkList(Plist list);

//顺序输出函数
void Show(Plist list);

//将单链表逆置
void InversionLinkList(Plist list);

//销毁函数
void Destroy(Plist list);

#endif