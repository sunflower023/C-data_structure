#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void CountSort(int* arr, int n)
{
	//找出最大和最小值，求极值
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	int range = max - min + 1;
	int* tmp = (int*)calloc(range, sizeof(int));
	if (tmp == NULL)
	{
		perror("calloc fail");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		tmp[arr[i] - min]++;
	}
}

void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 4,6,7,3,1,5,2,9,8 };
	int n = sizeof(a) / sizeof(a[0]);
	CountSort(a, n);
	Print(a, n);

	return 0;
}