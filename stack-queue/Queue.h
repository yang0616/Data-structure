#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int ElemType;

#define SIZE 5
#define TRUE 1
#define FALSE 0

typedef struct Queue
{
	ElemType *data;
	int head;
	int tail;
}Queue, *PQueue;

//��ʼ������
void InitQueue(PQueue queue);

//�ڶ���ͷ��������
int PushQueue(PQueue queue, ElemType val);

//��ͷ����ֵ��res��������Ȼ��ɾ��
int PopQueue(PQueue queue, ElemType *res);

//���ٶ���
void Destroy(PQueue queue);

void Show(PQueue queue);
#endif