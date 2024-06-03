#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

int main()
{
	/*int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int n = sizeof(a) / sizeof(a[0]);*/
	srand(time(0));
	int n = 20;
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + i;
	}

	PrintArray(a, n);

	//int len = sizeof(a) / sizeof(a[0]);
	//BubbleSort(a, n);
	//InsertSort(a, n);
	//SelectSort(a, n);
	//HeapSort(a, n);
	//ShellSort(a, n);
	//QuickSort(a, 0, n - 1);
	QuickSort_3(a, 0, n - 1);

	PrintArray(a, n);

	return 0;
}