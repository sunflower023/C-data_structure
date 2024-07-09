#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSort(int* arr, int n)
{
	//[0,end]有序，end+1是插入值下标
	//最后一个插入的值下标为n-1,即end+1=n-1,end=n-2
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

//void SheerSort(int* arr, int n)
//{
//	int gap = 3;
//
//	//总共有gap组，每组都进行插入排序
//	//注意i = j，每组的开始不同
//	for (int j = 0; j < gap; j++)
//	{
//		//一组的插入排序
//		//注意end+gap是插入值下标，i<n-gap
//		for (int i = j; i < n - gap; i += gap)
//		{
//			int end = i;
//			int tmp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < arr[end])
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			arr[end + gap] = tmp;
//		}
//	}
//	
//	//最后进行直接插入排序
//	InsertSort(arr, n);
//}

void SheerSort(int* arr, int n)
{
	int gap = 3;

	//多组同时进行
	for (int i = 0; i < n - gap; i++)
	{
		int end = i;
		int tmp = arr[end + gap];
		while (end >= 0)
		{
			if (tmp < arr[end])
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

	Print(arr, n);
	//最后进行直接插入排序
	InsertSort(arr, n);
}