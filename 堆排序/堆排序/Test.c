#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef int HPDatatype;
void Swap(HPDatatype* p1, HPDatatype* p2)
{
	HPDatatype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(HPDatatype* a, int n, int parent)
{
	int child = parent * 2 + 1;
	if (child + 1 < n && a[child] > a[child + 1])
	{
		child++;
	}
	while (child < n)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Heapsort(HPDatatype* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i++)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void CreatNDate()
{
	int n = 1000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void PrintTopK(int k)
{
	HPDatatype* a = (HPDatatype*)malloc(sizeof(HPDatatype) * k);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	//取前k个数入数组
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &a[i]);
	}
	//向下调整建堆
	for (int i = (k - 1 - 1) / 2; i < k; i++)
	{
		AdjustDown(a, k, i);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > a[0])
		{
			a[0] = x;
			AdjustDown(a, k, 0);
		}
	}

	printf("最大的K个数为：");
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	//CreatNDate();
	PrintTopK(10);
	return 0;
}