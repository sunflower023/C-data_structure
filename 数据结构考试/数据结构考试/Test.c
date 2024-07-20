#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Quick(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = left;
	int begin = left;
	int end = right;

	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}

		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[begin]);
	Print(a, 7);
	Quick(a, left, begin - 1);
	Quick(a, begin + 1, right);
}

// hoare
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		// �ұ���С
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		// ����Ҵ�
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[begin]);
	Print(a, 7);
	return begin;
}

int PartSort2(int* a, int left, int right)
{
	
	int keyi = left;

	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	Print(a, 7);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = PartSort2(a, left, right);

	// [left, keyi-1] keyi [keyi+1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

void QuickSort222(int array[], int low, int high) {
	int i = low;
	int j = high;
	if (i >= j) {
		return;
	}

	int temp = array[low];
	while (i != j) {
		while (array[j] >= temp && i < j) {
			j--;
		}
		while (array[i] <= temp && i < j) {
			i++;
		}
		if (i < j) {
			Swap(&array[i], &array[j]);
		}
	}

	//����׼temp�����Լ���λ�ã�����i��λ�ã�
	Swap(&array[low], &array[i]);
	Print(array, 9);
	QuickSort(array, low, i - 1);
	QuickSort(array, i + 1, high);
}

//��������
void Quick111(int* a, int left, int right)
{
	//��ֹ����
	if (left >= right)
		return;

	//keyi��Key���±�
	int keyi = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//����С��ǰһ���жϱ�֤��������������������
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}

		//���Ҵ�
		while (begin < end && a[begin] < a[keyi])
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[begin]);

	//[left,keyi-1]keyi[keyi+1,right]
	Quick111(a, left, keyi - 1);
	Quick111(a, keyi + 1, right);
}
//��������-�ڿӷ�
void Quick_pit(int* a, int left, int right)
{
	if (left >= right)
		return;

	int pit = left;
	int key = a[left];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//�����������end���ǵ�����pit��λ�ã�֮��key�Ḳ�ǵ�
		while (begin<end && a[end] > key)
		{
			end--;
		}
		a[pit] = a[end];
		pit = end;

		while (begin < end && a[begin] < key)
		{
			begin++;
		}
		a[pit] = a[begin];
		pit = begin;
	}
	a[pit] = key;
	Print(a, 7);
	Quick_pit(a, left, pit - 1);
	Quick_pit(a, pit + 1, right);
}

int main()
{
	int a[] = { 30,15,40,28,50,10,70 };
	int n = sizeof(a) / sizeof(a[0]);
	//Print(a, 9);
	//Quick(a, 0, n - 1);
	//Quick111(a, 0, n - 1);
	//QuickSort(a, 0, n - 1);
	//QuickSort222(a, 0, n - 1);
	Quick_pit(a, 0, n - 1);
	Print(a, n);
	return 0;
}