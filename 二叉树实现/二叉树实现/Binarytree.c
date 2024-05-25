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

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//a���������ƣ�n��������ĳ��ȣ�pi�����鵱ǰ�±�
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
//	//ÿ��Ľڵ���������һ��ڵ������+�Һ���
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
	//����root��˵�ĵ�k�㣬���Ƕ���root->left�ĵ�k-1��
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
	//�жϳ��ӵ��Ƿ�Ϊ��
	while (front)
	{
		QueuePop(&q);
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		front = QueueFront(&q);
	}

	//������Ϊ�պ�����жϣ�����Ϊ����Ϊ��ȫ������
	//��Ҳ�����ڶ����У�����ʹ��empty�жϣ������ж�
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