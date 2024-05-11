#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//��ʼ��������
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

//β���ͷɾ
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

	//�ն���
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
	//assert(pq->phead);//��������
	assert(pq->size != 0);

	//һ���ڵ�
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	//����ڵ�
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	
	pq->size--;
}

//ȡͷ��ȡβ��ֵ
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

//�п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}

//Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}