#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//int main()
//{
//	long long int n = 0;
//	scanf("%lld", &n);
//	char arr[20] = { 0 };
//	int index = 0;
//	int count = 0;
//	while (n)
//	{
//		if (count % 3 == 0)
//		{
//			arr[index++] = ',';
//			count = 0;
//		}
//		arr[index++] = (n % 10)+'0';
//		n /= 10;
//		count++;
//	}
//
//	for (int i = index - 1; i >= 1; i--)
//	{
//		printf("%c", arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr1[100] = { 0 };
//	char arr2[100] = { 0 };
//	gets(arr1);
//	gets(arr2);
//
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	int i = 0, j = 0;
//	while (i < len1)
//	{
//		j = 0;
//		while (j < len2)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				for (int k = i; k < len1; k++)
//				{
//					arr1[k] = arr1[k + 1];
//				}
//				i--;
//				break;
//			}
//			j++;
//		}
//		i++;
//	}
//
//	puts(arr1);
//	/*for (int i = 0; i < len1; i++)
//	{
//		if (arr1[i] != '0')
//			printf("%c", arr1[i]);
//	}*/
//
//
//	return 0;
//}


struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};
typedef struct Node Node;
Node* Buynewnode(int val)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->val = val;
	newnode->next = NULL;
	newnode->random = NULL;

	return newnode;
}



struct Node* copyRandomList(struct Node* head)
{
	Node* copyhead = Buynewnode(1);
	Node* cur = head;

	while (cur->next)
	{
		copyhead->val = cur->val;
		copyhead->next = Buynewnode(1);

		cur = cur->next;
	}
	copyhead->val = cur->val;


}

