#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define ElemType int
#define SIZE 10
#define TRUE 1
#define FALSE 0

//定义栈
typedef struct stack
{
	ElemType *data;
	int size;
	int top;
}Stack, *Pstack;

//定义队列
typedef struct Queue
{
	Stack sta;
	Stack stb;
}Queue,*Pqueue;

//初始化栈
void InitStack(Pstack stack);

//将val插入栈内
int PushStack(Pstack stack, ElemType val);

//将栈顶的数值用res带出来后删掉
int PopStack(Pstack stack, ElemType *res );

//销毁栈
void DestroyStack(Pstack stack);

//初始化队列
void InitQueue(Pqueue queue);

//入队
int PushQueue(Pqueue queue, ElemType val);

//出队
int PopQueue(Pqueue queue, ElemType *res);

//销毁队
void DestroyQueue(Pqueue queue);

#endif