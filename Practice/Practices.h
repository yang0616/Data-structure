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

//��ʼ����������
void InitLinkList(Plist list);

//����������㺯��
void InsertLinkList(Plist list, ElemType val, int pos);

//˳�������������
void Show(Plist list);

//����һ�������ĵ�����,�뻷���Ϊ��k�����
void HasRingLinkList(Plist list,int k);

//���������ҵ�����K�����  ʱ�临�Ӷ�ΪO(n)
ElemType FindNode(Plist list, int k);//����ֵΪ��k����������
//����
int FindNode2(Plist list, int k, ElemType* res);//�ɹ����ء�1����ʧ�ܷ��ء�0����ָ�롰res�����ص����ڡ�K��������ֵ

//�жϵ������Ƿ��л��������ҵ��뻷�ĵ�һ����� ʱ�临�Ӷ�ΪO(n)
/*
	���ж������Ƿ��л�����������ָ��p��q��pָ��ÿ��һ����qָ�����������������ָ���������ʹ��������л����������ָ������һ��;��ΪNULL�����û�л�
	���뻷�������˼�� ��
	    1�����л��Ļ������ٶ���һ��ָ��mָ��p��q��λ�ã�Ȼ��p��һ��p���Լ���λ�ñ���һ�κ��ٵ��Լ���λ�ã��Ƚ�p��q����ͬ������뻷�Ľ��
		2�����л��Ļ����Ͻ������������ָ��pq������λ�öϿ���������������ཻ��������
		3�����л��Ļ���������ѧ��ʽ������⣬����˼·�ڴ���������
*/
void IsRing(Plist list);//����ֵΪ�뻷�Ľ��λ��
//������
Node *IsRing2(Plist list);//����˼·2�ҽ��
Node *IsRing3(Plist list);//����˼·3�ҽ��

//�ж������������Ƿ��ཻ  ʱ�临�Ӷ�ΪO(n)
int  IsIntresect(Plist firstlist,Plist secondlist);//����ཻ����ֵΪ�棬������ཻ����ֵΪ��
//����
int IsIntresect2(Plist firstlist,Plist secondlist);//����ཻ����ֵΪ�棬������ཻ����ֵΪ��

//���������ཻ������,�ཻ�Ľ�����Ϊk 
void IsIntresectLinklist(Plist firstlist,Plist secondlist,int k);

//������������
void InversionLinkList(Plist list);
//����
void InversionLinkList1(Plist list);

//O(1)ɾ�����p
int DeleteNode(Plist list,Node *p);//pָ��������ĳ����㣬ɾ���ɹ�ʱ���ء�1����ʧ�ܷ��ء�0��
//����
int DeleteNode1(Plist list,Node *p);
#endif