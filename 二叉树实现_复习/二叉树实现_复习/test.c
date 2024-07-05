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

	printf("�ܽڵ����Ϊ��%d\n", BinaryTreeSize(b));
	printf("��Ҷ�ڵ����Ϊ��%d\n", BinaryTreeLeafSize(b));
	printf("��K��ڵ����Ϊ��%d\n",BinaryTreeLevelKSize(b,3));

	printf("�ҵ��ýڵ��ˣ�%c\n", BinaryTreeFind(b, '6')->val);

	BinaryTreeLevelOrder(b);

	if (BinaryTreeComplete(b))
	{
		printf("�ö���������ȫ��������\n");
	}
	else
	{
		printf("�ö�����������ȫ��������\n");
	}

	BinaryTreeDestory(b);
	return 0;
}