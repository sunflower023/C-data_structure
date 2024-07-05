#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化和销毁
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	//assert(pq->phead);
	QNode* pcur = pq->phead;
	while (pcur)
	{
		QNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//尾插和头删
void QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;

	//空队列
	if (pq->ptail == NULL)
	{
		pq->ptail = pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->size++;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	//assert(pq->phead);//报错不清晰
	assert(pq->size != 0);

	//一个节点
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	//多个节点
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	
	pq->size--;
}

//取头，取尾数值
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

//判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}

//元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}