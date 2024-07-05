#define _CRT_SECURE_NO_WARNINGS 1
#include"Binarytree.h"

//�����½ڵ�
BTNode* BuyNode(Datatype x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

// ͨ��ǰ�����������"123NNN45NN6NN"����������
//n������ĳ��ȣ�*pi�������±�
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


// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	//��������
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	//���ʸ��ڵ�
	printf("%c ", root->val);

	//����������
	BinaryTreePrevOrder(root->left);
	//����������
	BinaryTreePrevOrder(root->right);
}

// �������������
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

// �������������
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

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// ������Ҷ�ӽڵ����
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

// ��������k��ڵ����
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

// ����������ֵΪx�Ľڵ�
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

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	//��Ҫ���ǳ�ʼ��
	QueueInit(&q);

	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		//���ʸýڵ��ֵ
		printf("%c ", front->val);

		//�����Һ��Ӳ�Ϊ�������
		if (front->left != NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}

		//�ýڵ����
		QueuePop(&q);
	}

	QueueDestroy(&q);
}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root != NULL)
	{
		QueuePush(&q, root);
	}

	//ֱ������λNULLΪֹ
	BTNode* front = QueueFront(&q);
	while (front != NULL)
	{
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		QueuePop(&q);
		front = QueueFront(&q);
	}

	//�ж϶����Ƿ�ȫΪ��
	//ע���ʱ����ֱ��ʹ��QueueEmpty����ΪNULLҲ�ڶ����У��������
	while (!QueueEmpty(&q))
	{
		//��ʱ��һ����ΪNULL������ֱ��ɾ
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

// ����������
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