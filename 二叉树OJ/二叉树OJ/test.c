#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BTNode
{
    char val;
    struct BTNode* left;
    struct BTNode* right;
}Node;

Node* CreateBinaryTree(char* a, int* pi, int size)
{
    if ((*pi) < size && a[(*pi)] != '#')
    {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->val = a[(*pi)++];
        newnode->left = CreateBinaryTree(a, pi, size);
        newnode->right = CreateBinaryTree(a, pi, size);
        return newnode;
    }
    else
    {
        (*pi)++;
        return NULL;
    }
}

void BinaryTreeInOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryTreeInOrder(root->left);
    printf("%c ", root->val);
    BinaryTreeInOrder(root->right);
}

int main() {
    char a[100] = "abc##de#g##f###";
    //gets(a);

    int n = 0;
    int* pi = &n;
    Node* ret = CreateBinaryTree(a, pi, strlen(a));
    BinaryTreeInOrder(ret);

    return 0;
}