#define _CRT_SECURE_NO_WARNINGS 1
#include"Binarytree.h"

//建立新节点
BTNode* BuyNode(Datatype x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

// 通过前序遍历的数组"123NNN45NN6NN"构建二叉树
//n是数组的长度，*pi是数组下标
BTNode* BinaryTreeCreate(Datatype* a, int n, int* pi)
{
	if (*pi < n && a[*pi] != 'N')
	{
		BTNode* newnode = BuyNode(a[(*pi)++]);
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


// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	//结束条件
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//访问根节点
	printf("%c ", root->val);

	//遍历左子树
	BinaryTreePrevOrder(root->left);
	//遍历右子树
	BinaryTreePrevOrder(root->right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	BinaryTreeInOrder(root->left);
	printf("%c ", root->val);
	BinaryTreeInOrder(root->right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->val);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// 二叉树叶子节点个数
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

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
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

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, Datatype x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val == x)
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

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	//不要忘记初始化
	QueueInit(&q);

	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		//访问该节点的值
		printf("%c ", front->val);

		//若左、右孩子不为空则入队
		if (front->left != NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}

		//该节点出队
		QueuePop(&q);
	}

	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	//直到队首位NULL为止
	BTNode* front = QueueFront(&q);
	while (front != NULL)
	{
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		QueuePop(&q);
		front = QueueFront(&q);
	}

	//判断队列是否全为空
	//注意此时不能直接使用QueueEmpty，因为NULL也在队列中，不能算空
	while (!QueueEmpty(&q))
	{
		//此时第一个都为NULL，可以直接删
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

// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}