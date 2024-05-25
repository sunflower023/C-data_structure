#define _CRT_SECURE_NO_WARNINGS 1
#include"Binarytree.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
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
		newnode->data = a[(*pi)++];
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

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->right) + BinaryTreeSize(root->left) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	//每层的节点数等于上一层节点的左孩子+右孩子
//	if (root == NULL)
//	{
//		return 0;
//	}
//	if (k == 1)
//	{
//		return 1;
//	}
//	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
//}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//对于root来说的第k层，就是对于root->left的第k-1层
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}

	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1 != NULL)
	{
		return ret1;
	}
	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2 != NULL)
	{
		return ret2;
	}

	return NULL;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}

	QueueDestroy(&q);
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	
	BTNode* front = QueueFront(&q);
	//判断出队的是否为空
	while (front)
	{
		QueuePop(&q);
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		front = QueueFront(&q);
	}

	//当出队为空后进行判断，队列为空则为完全二叉树
	//空也包含在队列中，不能使用empty判断，依次判断
	if (!(QueueEmpty(&q)))
	{
		QueuePop(&q);
		front = QueueFront(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}