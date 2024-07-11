#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Stack.h"

void Print(int* a, int n);

//ð������
void Bubble(int* a, int n);

//��������
void Quick(int* a, int left, int right);

//����ȡ��
int Getmid(int* a, int left, int right);

//��������-�ڿӷ�
void Quick_pit(int* a, int left, int right);

//��������-ǰ��ָ�뷨
void Quick_pointer(int* a, int left, int right);

//��������-�ǵݹ�汾
void Quick_NorR(int* a, int left, int right);

//�鲢����
void Merge(int* a, int n);

//�鲢����-����-(�ǵݹ飩
void Merge_NonR(int* a, int n);