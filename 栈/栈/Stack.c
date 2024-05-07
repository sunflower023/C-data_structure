#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//创建和销毁
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

//入栈和出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//扩容
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

//取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->a[pst->top - 1];
}

//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return (pst->top == 0);
}

//获取数据个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}