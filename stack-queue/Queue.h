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

//初始化队列
void InitQueue(PQueue queue);

//在队列头插入数据
int PushQueue(PQueue queue, ElemType val);

//将头部的值用res带出来，然后删掉
int PopQueue(PQueue queue, ElemType *res);

//销毁队列
void Destroy(PQueue queue);

void Show(PQueue queue);
#endif