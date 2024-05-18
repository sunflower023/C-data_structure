#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void testHeap()
{
	int a[] = { 4,6,7,8,9,1,2,3 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	HPPop(&hp);
	HPPop(&hp);

	HPDestroy(&hp);
}
void testHeapsort()
{
	int a[] = { 4,5,6,7,1,2,3,9,8 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));

}


int main()
{
	//testHeap();
	testHeapsort();


	return 0;
}