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

//≥ı ºªØ
void StackInit(Stack* pst)
{
    pst->a = NULL;
    pst->size = pst->capacity = 0;
}

//ºÏ≤È¿©»›
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

//»Î’ª
void Push(Stack* pst, StackDataType x)
{
    check(pst);
    pst->a[pst->size] = x;
    pst->size++;
}

//≥ˆ’ª
void Pop(Stack* pst)
{
    pst->size--;
}

//’ª∂•
StackDataType Top(Stack* pst)
{
    return pst->a[pst->size - 1];
}

//≈–ø’
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
        //◊Û¿®∫≈»Î’ª
        if ((*s) == '(' || (*s) == '{' || (*s) == '[')
        {
            Push(&p, *s);
        }

        //”“¿®∫≈«“’ªŒ™ø’
        if (((*s) == ')' || (*s) == '}' || (*s) == ']') && (Isempty(&p)))
        {
            return false;
        }

        //”“¿®∫≈«“’ª≤ªŒ™ø’£¨≤ªƒ‹∆•≈‰
        if (((*s) == ')' && (Top(&p)) != '(') ||
            ((*s) == '}' && (Top(&p)) != '{') ||
            ((*s) == ']' && (Top(&p)) != '['))
        {
            return false;
        }

        //”“¿®∫≈£¨∆•≈‰≥…π¶
        if ((*s) == ')' || (*s) == '}' || (*s) == ']')
        {
            Pop(&p);
        }

        s++;
    }

    //∑¿÷π"{"
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