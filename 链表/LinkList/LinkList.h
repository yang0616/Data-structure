#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;
 
//�����ͷ���ĵ�����
typedef struct Node //������
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Linklist //��������
{
	int count;
	struct Node head;
}Linklist, *Plist;

//��ʼ����������
void InitLinkList(Plist list);

//�����㺯��
void InsertLinkList(Plist list, ElemType val, int pos);

//��ͷ��㺯��
void InsertHeadLinkList(Plist list, ElemType val);

//��β��㺯��
void InsertTailLinkList(Plist list, ElemType val);

//ɾ����㺯��
void DeleteLinkList(Plist list, int pos);

//ɾͷ��㺯��
void DeleteHeadLinkList(Plist list);

//ɾβ��㺯��
void DeleteTailLinkList(Plist list);

//˳���������
void Show(Plist list);

//������������
void InversionLinkList(Plist list);

//���ٺ���
void Destroy(Plist list);

#endif