#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"

//打印
void PrintArray(int* arr, int n);

//冒泡排序
void BubbleSort(int* arr, int n);

//插入排序
void InsertSort(int* arr, int n);

//选择排序
void SelectSort(int* arr, int n);

//堆排序
void HeapSort(int* arr, int n);

//希尔排序
void ShellSort(int* arr, int n);

//快速排序
void QuickSort(int* arr, int left, int right);

//快速排序-前后指针法
void QuickSort_2(int* arr, int left, int right);

//快速排序-非递归版本
void QuickSort_3(int* arr, int left, int right);