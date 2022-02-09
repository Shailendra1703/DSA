#include <stdio.h>
#define M 100
typedef struct DEqueue
{
    int arr[M];
    int front, rear, size;
} Deq;

void createqueue(Deq q, int k)
{
    q.front = -1;
    q.rear = 0;
    q.size = k;
}

void InsertFront(Deq q, int k)
{
    if (q.front == -1)
    {
        q.front = q.rear = 0;
    }
    else if (q.front == 0)
        q.front = q.size - 1;

    else
        q.front = q.front - 1;

    q.arr[q.front] = k;
}

void InsertRear(Deq q, int j)
{
    if (q.front == -1)
    {
        q.front = q.rear = 0;
    }
    else if (q.rear == q.size - 1)
        q.rear = 0;
    else
        q.rear = q.rear + 1;

        q.arr[q.rear] = j;
}

void DeleteFront(Deq q)

