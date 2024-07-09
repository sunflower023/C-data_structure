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
	//[0,end]����end+1�ǲ���ֵ�±�
	//���һ�������ֵ�±�Ϊn-1,��end+1=n-1,end=n-2
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
//	//�ܹ���gap�飬ÿ�鶼���в�������
//	//ע��i = j��ÿ��Ŀ�ʼ��ͬ
//	for (int j = 0; j < gap; j++)
//	{
//		//һ��Ĳ�������
//		//ע��end+gap�ǲ���ֵ�±꣬i<n-gap
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
//	//������ֱ�Ӳ�������
//	InsertSort(arr, n);
//}

void SheerSort(int* arr, int n)
{
	int gap = 3;

	//����ͬʱ����
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
	//������ֱ�Ӳ�������
	InsertSort(arr, n);
}