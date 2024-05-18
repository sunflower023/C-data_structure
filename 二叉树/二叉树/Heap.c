#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void swap(HPDatatype* p1, HPDatatype* p2)
{
	HPDatatype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDatatype* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDatatype x)
{
	assert(php);
	//����
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDatatype* tmp = (HPDatatype*)realloc(php->a, sizeof(HPDatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDatatype* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ�������С��һ��
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	swap(&php->a[0], &php->a[php->size-1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

HPDatatype HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

int HPEmpty(HP* php)
{
	assert(php);
	return (php->size == 0);
}

int HPSize(HP* php)
{
	assert(php);
	return php->size;
}

void HeapSort(int* a, int n)
{
	//���򣺽�С��
	//���ϵ�������
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	//���µ�������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

}