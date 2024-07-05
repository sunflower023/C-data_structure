#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

//ʹ����ʽ�ṹ���������
typedef char Datatype;
typedef struct BinaryTreeNode
{
	Datatype val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

// ͨ��ǰ�����������"123NNN45NN6NN"����������
BTNode* BinaryTreeCreate(Datatype* a, int n, int* pi);

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);

// �������������
void BinaryTreeInOrder(BTNode* root);

// �������������
void BinaryTreePostOrder(BTNode* root);

// �������ڵ����
int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, Datatype x);

// �������
void BinaryTreeLevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);

// ����������
void BinaryTreeDestory(BTNode* root);