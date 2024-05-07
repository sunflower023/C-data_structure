#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//����������
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//��ջ�ͳ�ջ
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//����
	if (pst->capacity == pst->top)
	{
		int newcapacity = (pst->capacity == 0) ? 4 : (pst->capacity) * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

//ȡջ������
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->a[pst->top - 1];
}

//�п�
bool STEmpty(ST* pst)
{
	assert(pst);
	return (pst->top == 0);
}

//��ȡ���ݸ���
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}