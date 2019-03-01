#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef char ElemType;

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct stack
{
	ElemType *data;
	int size;
	int top;
}Stack, *Pstack;

//ջ�п�
int IsEmpty(Pstack stack);

//ջ����
int IsFull(Pstack stack);

//ջ����
void Expand(Pstack stack);

//��ʼ��ջ
void InitStack(Pstack stack);

//��val����ջ��
int PushStack(Pstack stack, ElemType val);

//��ջ������ֵ��res��������ɾ��
int PopStack(Pstack stack, ElemType *res );

//����ջ
void Destroy(Pstack stack);

//���ջ
void ShowStack(Pstack stack);

#endif