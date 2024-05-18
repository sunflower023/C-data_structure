#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int HPDatatype;
typedef struct Heap
{
	HPDatatype* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPush(HP* php, HPDatatype x);
void HPPop(HP* php);
HPDatatype HPTop(HP* php);
int HPEmpty(HP* php);
int HPSize(HP* php);

void swap(HPDatatype* p1, HPDatatype* p2);
void HeapSort(int* a, int n);