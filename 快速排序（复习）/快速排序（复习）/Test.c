#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

int main()
{
	srand(time(0));
	int n = 20;
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + i;
	}
	Print(a, n);
	//Bubble(a, n);
	//printf("%d\n", a[Getmid(a, 0, n - 1)]);
	//Quick_pit(a, 0, n - 1);
	//Quick_pointer(a, 0, n - 1);
	//Quick_NorR(a, 0, n - 1);
	Merge(a, n);
	Print(a, n);

	return 0;
}