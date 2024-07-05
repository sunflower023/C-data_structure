#define _CRT_SECURE_NO_WARNINGS 1
#include"Binarytree.h"

int main()
{
	char arr[] = "123NNN45NN6NN";
	int n = sizeof(arr) / sizeof(arr[0]);
	int pi = 0;
	BTNode* b = BinaryTreeCreate(arr, n, &pi);

	BinaryTreePrevOrder(b);
	printf("\n");
	BinaryTreeInOrder(b);
	printf("\n");
	BinaryTreePostOrder(b);
	printf("\n");

	printf("总节点个数为：%d\n", BinaryTreeSize(b));
	printf("总叶节点个数为：%d\n", BinaryTreeLeafSize(b));
	printf("第K层节点个数为：%d\n",BinaryTreeLevelKSize(b,3));

	printf("找到该节点了：%c\n", BinaryTreeFind(b, '6')->val);

	BinaryTreeLevelOrder(b);

	if (BinaryTreeComplete(b))
	{
		printf("该二叉树是完全二叉树！\n");
	}
	else
	{
		printf("该二叉树不是完全二叉树！\n");
	}

	BinaryTreeDestory(b);
	return 0;
}