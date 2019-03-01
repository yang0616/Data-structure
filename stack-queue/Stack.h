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

//栈判空
int IsEmpty(Pstack stack);

//栈判满
int IsFull(Pstack stack);

//栈扩容
void Expand(Pstack stack);

//初始化栈
void InitStack(Pstack stack);

//将val插入栈内
int PushStack(Pstack stack, ElemType val);

//将栈顶的数值用res带出来后删掉
int PopStack(Pstack stack, ElemType *res );

//销毁栈
void Destroy(Pstack stack);

//输出栈
void ShowStack(Pstack stack);

#endif