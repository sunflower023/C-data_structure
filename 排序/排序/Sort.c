#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//打印
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//冒泡排序
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				/*int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;*/
				Swap(&arr[j + 1], &arr[j]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

//选择排序
//错误示范，对“9,1,2,5,7,4,6,3”进行排序
void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{

		int min = begin;
		int max = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] > arr[max])
			{
				max = i;
			}
			if (arr[i] < arr[min])
			{
				min = i;
			}
		}
		Swap(&arr[begin], &arr[min]);
		//添加这里就对了
		if (begin == max)
			max = min;
		Swap(&arr[end], &arr[max]);

		begin++;
		end--;
	}
}


//插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
			}
			else
			{
				break;
			}
			end--;
		}
		arr[end + 1] = tmp;
	}
}

//堆排序
void AdjustDown(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			child++;
		}

		if (arr[parent] < arr[child])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}
	//PrintArray(arr, n);

	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

//希尔排序
void ShellSort(int* arr, int n)
{
	int gap = n;

	//gap等于1就是插入排序,%3+1最终都会到gap = 1
	while (gap > 1)
	{
		gap = gap % 3 + 1;
		//三个循环的写法
		/*for (int i = 0; i < gap; i++)
		{
			int end = i;
			for (end = i; end < n - gap; end += gap)
			{
				int tmp = arr[end + gap];
				while (end >= 0)
				{
					if (arr[end] > tmp)
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				arr[end + gap] = tmp;
			}
		}*/

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
	//InsertSort(arr, n);
}

//快速排序
//优化一：三数取中
int GetMid(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	//先mid与left对比
	if (arr[mid] > arr[left])
	{
		if (arr[right] > arr[mid])
		{
			return mid;
		}
		else if (arr[right] < arr[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//arr[mid] < arr[left]
	{
		if (arr[right] < arr[mid])
		{
			return mid;
		}
		else if (arr[right] < arr[left])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}


void QuickSort(int* arr, int left, int right)
{
	//递归终止条件
	if (left >= right)
		return;

	//优化二：小区间优化
	if (right - left < 10)
	{
		InsertSort(arr, right - left + 1);
	}

	//三数取中
	int mid = GetMid(arr, left, right);
	Swap(&arr[left], &arr[mid]);

	int key = left;
	int begin = left, end = right;

	//直到左右相遇为止
	while (begin < end)
	{
		//右先找小于arr[key]的
		while (begin < end && arr[end] >= arr[key])
		{
			end--;
		}

		//左找大于arr[key]的
		while (begin < end && arr[begin] <= arr[key])
		{
			begin++;
		}

		Swap(&arr[end], &arr[begin]);

	}
	Swap(&arr[key], &arr[begin]);
	key = begin;

	QuickSort(arr, left, key - 1);
	QuickSort(arr, key + 1, right);
}