#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDatatype;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype val;
}QNode;

//便于函数内修改指针phead,ptail，同时便于传多个参数
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化和销毁
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//尾插和头删
void QueuePush(Queue* pq, QDatatype x);
void QueuePop(Queue* pq);

//取头，取尾数值
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);

//元素个数
int QueueSize(Queue* pq);