#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



void AdjustDown(int* a, int parent, int n)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		//这个if要加到while内部否则出错
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Heapsort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}

	int end = n - 1;

	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		end--;
	}
}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 3,6,7,8,1,2,9};
	int n = sizeof(a) / sizeof(a[0]);
	/*printf("%d\n", n);
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}*/

	Heapsort(a, n);
	Print(a, n);

	return 0;
}