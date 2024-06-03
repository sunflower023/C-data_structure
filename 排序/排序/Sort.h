#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"

//��ӡ
void PrintArray(int* arr, int n);

//ð������
void BubbleSort(int* arr, int n);

//��������
void InsertSort(int* arr, int n);

//ѡ������
void SelectSort(int* arr, int n);

//������
void HeapSort(int* arr, int n);

//ϣ������
void ShellSort(int* arr, int n);

//��������
void QuickSort(int* arr, int left, int right);

//��������-ǰ��ָ�뷨
void QuickSort_2(int* arr, int left, int right);

//��������-�ǵݹ�汾
void QuickSort_3(int* arr, int left, int right);