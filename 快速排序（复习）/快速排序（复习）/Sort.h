#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Stack.h"

void Print(int* a, int n);

//冒泡排序
void Bubble(int* a, int n);

//快速排序
void Quick(int* a, int left, int right);

//三数取中
int Getmid(int* a, int left, int right);

//快速排序-挖坑法
void Quick_pit(int* a, int left, int right);

//快速排序-前后指针法
void Quick_pointer(int* a, int left, int right);

//快速排序-非递归版本
void Quick_NorR(int* a, int left, int right);

//归并排序
void Merge(int* a, int n);

//归并排序-主体-(非递归）
void Merge_NonR(int* a, int n);