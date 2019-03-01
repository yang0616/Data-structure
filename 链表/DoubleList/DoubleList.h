#ifndef __DOUBLELIST_H
#define __DOUBLELIST_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int ElemType;

//����ÿһ�����Ľṹ
typedef struct Node
{
	struct Node *prev; //ÿ������ǰ��
	ElemType data;     //����ֵ
	struct Node *next; //ÿ�����ĺ��	
}Node;

//����˫������ṹ
typedef struct Doublelist
{
	Node head;  //ͷ���
	int count;  //��¼һ��˫������Ľ�����Ŀ
}Doublelist, *pDoulist;

//��ʼ��������
void InitDoublelist(pDoulist list);    
//����ڵ㺯��
void InsertDoublelist(pDoulist list, ElemType val , int pos);
//ͷ�庯��
void  InsertHeadDoublelist (pDoulist list,ElemType val);
//β�庯��
void InsertTailDoublelist(pDoulist list,ElemType val);
//ɾ����㺯��
void DeleteDoublelist(pDoulist list,int pos);
//ɾ��ͷ���ĺ���
void DeleteHeadDoublelist(pDoulist list);
//ɾ��β���ĺ���
void DeleteTailDoublelist(pDoulist list);
//����������
void DestroyDoublelist(pDoulist list);
//˳�����������ݺ���1
void Show1(pDoulist list);
//˳�����������ݺ���2
void Show2(pDoulist list);
//�������������ݺ���
void Reverseshow(pDoulist list);

#endif
