#ifndef __STACK_H
#define __STACK_H

#define ElemType int
#define SIZE 10
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//�������
typedef struct Queue
{
	ElemType *data;
	int head;
	int tail;
}Queue, *Pqueue;


//����ջ
typedef struct Stack
{
	Queue qua;
	Queue qub;
}Stack, *Pstack;


//��ʼ��ջ
void InitStack(Pstack stack);

//��ջ
int PushStack(Pstack stack, ElemType val);

//��ջ
int PopStack(Pstack stack, ElemType *res);

//����ջ
void DestroyStack(Pstack stack);
#endif








