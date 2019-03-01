#ifndef __CYCDOUBLELISH_H
#define __CYCDOUBLELISH_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int ElemType;

//����˫��ѭ������Ľ��
typedef struct Node
{
	struct Node *prev;
	ElemType data;
	struct Node *next;
}Node;

typedef struct CycDoubleList
{
	Node *head; //ָ��ͷ����ָ��
	int count;  //����ָ������ı���
}CycDoubleList, *pCycDouList;



//��ʼ��������
void InitCycDoublelist(pCycDouList list);    
//����ڵ㺯��
void InsertCycDoublelist(pCycDouList list, ElemType val , int pos);
//ͷ�庯��
void  InsertHeadCycDoublelist (pCycDouList list,ElemType val);
//β�庯��
void InsertTailCycDoublelist(pCycDouList list,ElemType val);
//ɾ����㺯��
void DeleteDouCycblelist(pCycDouList list,int pos);
//ɾ��ͷ���ĺ���
void DeleteHeadCycDoublelist(pCycDouList list);
//ɾ��β���ĺ���
void DeleteTailCycDoublelist(pCycDouList list);
//����������
void DestroyCycDoublelist(pCycDouList list);
//˳�����������ݺ���
void Show1(pCycDouList list);
void Show2(pCycDouList list);
//�������������ݺ���
void Reverseshow(pCycDouList list);

#endif