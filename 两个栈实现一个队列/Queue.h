#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define ElemType int
#define SIZE 10
#define TRUE 1
#define FALSE 0

//����ջ
typedef struct stack
{
	ElemType *data;
	int size;
	int top;
}Stack, *Pstack;

//�������
typedef struct Queue
{
	Stack sta;
	Stack stb;
}Queue,*Pqueue;

//��ʼ��ջ
void InitStack(Pstack stack);

//��val����ջ��
int PushStack(Pstack stack, ElemType val);

//��ջ������ֵ��res��������ɾ��
int PopStack(Pstack stack, ElemType *res );

//����ջ
void DestroyStack(Pstack stack);

//��ʼ������
void InitQueue(Pqueue queue);

//���
int PushQueue(Pqueue queue, ElemType val);

//����
int PopQueue(Pqueue queue, ElemType *res);

//���ٶ�
void DestroyQueue(Pqueue queue);

#endif