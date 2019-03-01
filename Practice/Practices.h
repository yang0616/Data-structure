#ifndef __PRACTICE_H
#define __PRACTICE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Linklist
{
	int count;
	struct Node head;
}Linklist, *Plist;

//初始化单链表函数
void InitLinkList(Plist list);

//单链表插入结点函数
void InsertLinkList(Plist list, ElemType val, int pos);

//顺序输出单链表函数
void Show(Plist list);

//构建一个带环的单链表,入环结点为第k个结点
void HasRingLinkList(Plist list,int k);

//单链表中找到数第K个结点  时间复杂度为O(n)
ElemType FindNode(Plist list, int k);//返回值为第k个结点的数据
//改正
int FindNode2(Plist list, int k, ElemType* res);//成功返回“1”，失败返回“0”，指针“res”带回倒数第“K”个结点的值

//判断单链表是否有环，并且找到入环的第一个结点 时间复杂度为O(n)
/*
	先判断链表是否有环：定义两个指针p和q，p指针每走一步，q指针走两步，如果两个指针相遇，就代表链表有环，如果两个指针任意一个途中为NULL则代表没有环
	找入环点的三种思想 ：
	    1：在有环的基础上再定义一个指针m指向p或q的位置，然后p走一步p从自己的位置遍历一次后再到自己的位置，比较p和q，相同后就是入环的结点
		2：在有环的基础上将带环的链表从指针pq相遇的位置断开，变成两个链表相交的问题解决
		3：在有环的基础利用数学公式解决问题，具体思路在代码中体现
*/
void IsRing(Plist list);//返回值为入环的结点位置
//改正：
Node *IsRing2(Plist list);//利用思路2找结点
Node *IsRing3(Plist list);//利用思路3找结点

//判断两个单链表是否相交  时间复杂度为O(n)
int  IsIntresect(Plist firstlist,Plist secondlist);//如果相交返回值为真，如果不相交返回值为假
//改正
int IsIntresect2(Plist firstlist,Plist secondlist);//如果相交返回值为真，如果不相交返回值为假

//构建两个相交的链表,相交的结点个数为k 
void IsIntresectLinklist(Plist firstlist,Plist secondlist,int k);

//将单链表逆置
void InversionLinkList(Plist list);
//改正
void InversionLinkList1(Plist list);

//O(1)删除结点p
int DeleteNode(Plist list,Node *p);//p指向链表中某个结点，删除成功时返回“1”，失败返回“0”
//改正
int DeleteNode1(Plist list,Node *p);
#endif