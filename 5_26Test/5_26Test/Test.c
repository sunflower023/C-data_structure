#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char StackDataType;
typedef struct Stack
{
    StackDataType* a;
    int size;
    int capacity;
}Stack;

//��ʼ��
void StackInit(Stack* pst)
{
    pst->a = NULL;
    pst->size = pst->capacity = 0;
}

//�������
void check(Stack* pst)
{
    if (pst->size == pst->capacity)
    {
        int newcapacity = (pst->capacity == 0) ? 4 : (pst->capacity) * 2;
        StackDataType* new = (StackDataType*)realloc(pst->a, newcapacity * sizeof(StackDataType));
        pst->a = new;
        //pst->capacity = newcapacity;
    }
}

//��ջ
void Push(Stack* pst, StackDataType x)
{
    check(pst);
    pst->a[pst->size] = x;
    pst->size++;
}

//��ջ
void Pop(Stack* pst)
{
    pst->size--;
}

//ջ��
StackDataType Top(Stack* pst)
{
    return pst->a[pst->size - 1];
}

//�п�
bool Isempty(Stack* pst)
{
    return (pst->size == 0);
}


bool isValid(char* s) {
    // write code here
    Stack p;
    StackInit(&p);
    while (*s)
    {
        //��������ջ
        if ((*s) == '(' || (*s) == '{' || (*s) == '[')
        {
            Push(&p, *s);
        }

        //��������ջΪ��
        if (((*s) == ')' || (*s) == '}' || (*s) == ']') && (Isempty(&p)))
        {
            return false;
        }

        //��������ջ��Ϊ�գ�����ƥ��
        if (((*s) == ')' && (Top(&p)) != '(') ||
            ((*s) == '}' && (Top(&p)) != '{') ||
            ((*s) == ']' && (Top(&p)) != '['))
        {
            return false;
        }

        //�����ţ�ƥ��ɹ�
        if ((*s) == ')' || (*s) == '}' || (*s) == ']')
        {
            Pop(&p);
        }

        s++;
    }

    //��ֹ"{"
    if (!(Isempty(&p)))
    {
        return false;
    }

    return true;
}

int main()
{
    char a[] = "{{{{{{}}}}}}";
    printf("%d\n", isValid(a));
    return 0;
}