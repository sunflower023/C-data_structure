#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

//使用链式结构定义二叉树
typedef char Datatype;
typedef struct BinaryTreeNode
{
	Datatype val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

// 通过前序遍历的数组"123NNN45NN6NN"构建二叉树
BTNode* BinaryTreeCreate(Datatype* a, int n, int* pi);

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);

// 二叉树节点个数
int BinaryTreeSize(BTNode* root);

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, Datatype x);

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);

// 二叉树销毁
void BinaryTreeDestory(BTNode* root);