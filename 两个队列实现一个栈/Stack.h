#ifndef __STACK_H
#define __STACK_H

#define ElemType int
#define SIZE 10
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//定义队列
typedef struct Queue
{
	ElemType *data;
	int head;
	int tail;
}Queue, *Pqueue;


//定义栈
typedef struct Stack
{
	Queue qua;
	Queue qub;
}Stack, *Pstack;


//初始化栈
void InitStack(Pstack stack);

//入栈
int PushStack(Pstack stack, ElemType val);

//出栈
int PopStack(Pstack stack, ElemType *res);

//销毁栈
void DestroyStack(Pstack stack);
#endif








