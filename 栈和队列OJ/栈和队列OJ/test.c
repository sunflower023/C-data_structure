#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


//typedef int STDataType;
//typedef struct Stack
//{
//    STDataType* a;
//    int top;
//    int capacity;
//}ST;
//
////创建和销毁
//void STInit(ST* pst)
//{
//    assert(pst);
//    pst->a = NULL;
//    pst->top = 0;
//    pst->capacity = 0;
//}
//void STDestroy(ST* pst)
//{
//    assert(pst);
//    free(pst->a);
//    pst->a = NULL;
//    pst->capacity = pst->top = 0;
//}
//
////入栈和出栈
//void STPush(ST* pst, STDataType x)
//{
//    assert(pst);
//    //扩容
//    if (pst->capacity == pst->top)
//    {
//        int newcapacity = (pst->capacity == 0) ? 4 : (pst->capacity) * 2;
//        STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
//        if (tmp == NULL)
//        {
//            perror("realloc fail");
//            return;
//        }
//        pst->a = tmp;
//        pst->capacity = newcapacity;
//    }
//
//    pst->a[pst->top] = x;
//    pst->top++;
//}
//void STPop(ST* pst)
//{
//    assert(pst);
//    assert(pst->top > 0);
//    pst->top--;
//}
//
////取栈顶数据
//STDataType STTop(ST* pst)
//{
//    assert(pst);
//    assert(pst->top > 0);
//    return pst->a[pst->top - 1];
//}
//
////判空
//bool STEmpty(ST* pst)
//{
//    assert(pst);
//    return (pst->top == 0);
//}
//
////获取数据个数
//int STSize(ST* pst)
//{
//    assert(pst);
//    return pst->top;
//}
//
//typedef struct {
//    ST s1;
//    ST s2;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//    MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
//    STInit(&pq->s1);
//    STInit(&pq->s2);
//    return pq;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    if (!STEmpty(&obj->s1))
//    {
//        STPush(&obj->s1, x);
//    }
//    else
//    {
//        STPush(&obj->s2, x);
//    }
//}
//
//int myQueuePop(MyQueue* obj) {
//    ST* empty = &obj->s1;
//    ST* notempty = &obj->s2;
//    if (!STEmpty(&obj->s1))
//    {
//        notempty = &obj->s1;
//        empty = &obj->s2;
//    }
//    int size = notempty->top;
//    for (int i = 1; i < size; i++)
//    {
//        STPush(empty, notempty->a[i]);
//    }
//    int ret = notempty->a[0];
//    for (int i = 0; i < size; i++)
//    {
//        STPop(notempty);
//    }
//    return ret;
//}
//
//int myQueuePeek(MyQueue* obj) {
//    if (!STEmpty(&obj->s1))
//    {
//        return obj->s1.a[0];
//    }
//    else
//    {
//        return obj->s2.a[0];
//    }
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    return STEmpty(&obj->s1) && STEmpty(&obj->s2);
//}
//
//void myQueueFree(MyQueue* obj) {
//    STDestroy(&obj->s1);
//    STDestroy(&obj->s2);
//}
//
//int main()
//{
//    MyQueue* pq = myQueueCreate();
//    myQueuePush(pq, 1);
//    myQueuePush(pq, 2);
//    myQueuePeek(pq);
//    myQueuePop(pq);
//    myQueueEmpty(pq);
//    return 0;
//}

//typedef struct {
//    int* a;
//    int head;
//    int tail;
//    int k;
//} MyCircularQueue;
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    pq->a = (int*)malloc(sizeof(int) * (k + 1));
//    pq->head = pq->tail = 0;
//    return pq;
//}
//
////bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
////    return (obj->head == obj->tail);
////}
////
////bool myCircularQueueIsFull(MyCircularQueue* obj) {
////    return ((obj->tail + 1) % (obj->k + 1) == obj->head);
////}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    if (myCircularQueueIsFull(obj)) {
//        return false;
//    }
//    obj->a[obj->tail] = value;
//    obj->tail++;
//    obj->tail %= (obj->k + 1);
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj)) {
//        return false;
//    }
//    obj->head++;
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj)) {
//        return -1;
//    }
//    else {
//        return obj->a[obj->head];
//    }
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj)) {
//        return -1;
//    }
//    else {
//        return obj->a[(obj->tail - 1 + obj->k + 1) % (obj->k + 1)];
//    }
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return (obj->head == obj->tail);
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    return ((obj->tail + 1) % (obj->k + 1) == obj->head);
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    free(obj->a);
//    free(obj);
//}
//

typedef struct {
    int* a;
    int head;
    int tail;
    int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->head == obj->tail);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->tail + 1) % (obj->k + 1) == obj->head);
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    pq->a = (int*)malloc(sizeof(int) * (k + 1));
    pq->head = pq->tail = 0;
    pq->k = k;
    return pq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    obj->a[obj->tail] = value;
    obj->tail++;
    obj->tail %= (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    obj->head++;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        return obj->a[obj->head];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        //return obj->a[(obj->tail - 1 + obj->k + 1) % (obj->k + 1)];
        return (obj->tail == 0) ? obj->a[obj->k] : obj->a[obj->tail - 1];
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

int main()
{
    MyCircularQueue* pq = myCircularQueueCreate(2);
    myCircularQueueEnQueue(pq, 1);
    myCircularQueueEnQueue(pq, 2);
    myCircularQueueDeQueue(pq);
    myCircularQueueEnQueue(pq, 3);
    myCircularQueueDeQueue(pq);
    myCircularQueueEnQueue(pq, 3);
    myCircularQueueDeQueue(pq);
    myCircularQueueEnQueue(pq, 3);
    myCircularQueueDeQueue(pq);
    myCircularQueueFront(pq);
    return 0;
}