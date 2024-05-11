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

//���ں������޸�ָ��phead,ptail��ͬʱ���ڴ��������
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//��ʼ��������
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//β���ͷɾ
void QueuePush(Queue* pq, QDatatype x);
void QueuePop(Queue* pq);

//ȡͷ��ȡβ��ֵ
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);

//�п�
bool QueueEmpty(Queue* pq);

//Ԫ�ظ���
int QueueSize(Queue* pq);