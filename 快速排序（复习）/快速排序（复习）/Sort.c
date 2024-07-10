#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//冒泡排序
void Bubble(int* a, int n)
{
	//n个数进行n-1趟排序
	for (int i = 0; i < n - 1; i++)
	{
		//冒泡排序的优化：若一轮没有交换则序列已有序
		int flag = 1;

		//单趟排序，每次排序终止的地方都要-1
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//快速排序
void Quick(int* a, int left, int right)
{
	//终止条件
	if (left >= right)
		return;

	//小区间优化:不再递归分割序列，减少递归次数
	//if ((right - left + 1) < 10)
	//{
		//序列首元素地址，序列个数
		//InsertSort(a + left, right - left + 1);
	//}

	//三数取中
	int mid = Getmid(a, left, right);
	Swap(&a[left], &a[mid]);

	//keyi是Key的下标
	int keyi = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//右找小
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}

		//左找大
		while (begin < end && a[begin] < a[keyi])
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[begin]);

	//[left,keyi-1]keyi[keyi+1,right]
	Quick(a, left, keyi - 1);
	Quick(a, keyi + 1, right);
}

//三数取中
int Getmid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//a[left]>a[mid]
	{
		if (a[right] > a[left])
		{
			return left;
		}
		else if (a[mid] > a[right])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}

}

//快速排序-挖坑法
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
		while (begin<end && a[end]>key)
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
	Quick_pit(a, left, pit - 1);
	Quick_pit(a, pit + 1, right);
}

//快速排序-前后指针法
void Quick_pointer(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		//若prev++后与cur位置相同，则没交换的必要
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	Quick_pointer(a, left, prev - 1);
	Quick_pointer(a, prev + 1, right);
}




int QuickSort_1(int* arr, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[left] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}

		cur++;
	}
	Swap(&arr[left], &arr[prev]);

	return prev;
}


//快速排序-非递归版本
void Quick_NorR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	//先入后出，先入的right等会先出栈的就是left
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		//之前的无论哪种版本都能得到key
		int key = QuickSort_1(a, begin, end);
		
		//保证left<right才入栈
		if (key - 1 > begin)
		{
			STPush(&st, key - 1);
			STPush(&st, begin);
		}
		
		if (end > key + 1)
		{
			STPush(&st, end);
			STPush(&st, key + 1);
		}
	}
}

//归并排序-主体
void _Merge(int* a, int* tmp, int begin, int end)
{
	//结束条件
	if (begin >= end)
		return;

	//拆分
	int mid = (begin + end) / 2;
	_Merge(a, tmp, begin, mid);
	_Merge(a, tmp, mid + 1, end);

	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//归并排序
void Merge(int* a, int n)
{
	//创建临时数组
	int* tmp = (int*)malloc(sizeof(int) * n);

	_Merge(a, tmp, 0, n - 1);
	free(tmp);
	tmp == NULL;
}