#define _CRT_SECURE_NO_WARNINGS 1
#include"Binarytree.h"

int main()
{
	char a[] = "123###45##6##";
	int n = 0;
	int* pi = &n;
	BTNode* b = BinaryTreeCreate(a,sizeof(a)/sizeof(BTDataType),pi);
	printf("%d\n", BinaryTreeSize(b));
	printf("%d\n", BinaryTreeLeafSize(b));
	printf("%d\n", BinaryTreeLevelKSize(b,3));
	BinaryTreePrevOrder(b);
	printf("\n");
	BinaryTreeInOrder(b);
	printf("\n");
	BinaryTreePostOrder(b);
	printf("\n");

	BTNode* find = BinaryTreeFind(b, '3');
	printf("%c\n", find->data);

	BinaryTreeDestory(&b);
	return 0;
}