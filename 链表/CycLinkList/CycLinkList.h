#ifndef __CYCLINKLIST_H
#define __CYCLINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef  int ElemType;

//������
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

/*
//�����ͷ��������
typedef struct Linklist
{
	struct Node head; //ͷ���
	int count;
}Linklist, *pList;
*/

//���岻��ͷ��������
typedef struct Linklist
{
	struct Node *head; //ͷָ��
	int count;
}Linklist, *pList;

//��ʼ������
void InitLinkList(pList list);

//���뺯��
void InsertLinkList(pList list, ElemType val, int pos);

//ͷ�庯��
void InsertHeadLinkList(pList list, ElemType val);

//β�庯��
void InsertTailLinkList(pList list, ElemType val);

//ɾ����㺯��
void DeleteLinkList(pList list, int pos);

//ɾͷ����
void DeleteHeadLinkList(pList list);

//ɾβ����
void DeleteTailLinkList(pList list);

//˳���������
void ShowLinkLIst1(pList list);
void ShowLinkLIst2(pList list);


#endif