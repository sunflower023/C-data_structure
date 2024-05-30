#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);

// 二叉树销毁
void BinaryTreeDestory(BTNode** root);

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//a是数组名称，n就是数组的长度，pi是数组当前下标
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if ((*pi) < n && a[(*pi)] != '#')
	{
		BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
		newnode->val = a[(*pi)++];
		newnode->left = BinaryTreeCreate(a, n, pi);
		newnode->right = BinaryTreeCreate(a, n, pi);
		return newnode;
	}
	else
	{
		(*pi)++;
		return NULL;
	}
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BTNode* tmp = *root;
	*root = NULL;

	BinaryTreeDestory(&(tmp->left));
	BinaryTreeDestory(&(tmp->right));
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%c ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

bool isSameTree(BTNode* p, BTNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(BTNode* root, BTNode* subRoot) {
	if (root == NULL)
	{
		return false;
	}
	bool ret1 = isSameTree(root, subRoot);
	if (ret1)
	{
		return true;
	}
	bool ret2 = isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
	return ret2;
}

int main()
{
	char a1[] = "1#1#12###";
	int n = 0;
	int* pi = &n;
	BTNode* p1 = BinaryTreeCreate(a1, strlen(a1), pi);
	//BinaryTreePrevOrder(p1);
	//printf("\n");

	n = 0;
	char a2[] = "12###";
	BTNode* p2 = BinaryTreeCreate(a2, strlen(a2), pi);
	//BinaryTreePrevOrder(p2);

	printf("%s",isSubtree(p1, p2));
	return 0;
}