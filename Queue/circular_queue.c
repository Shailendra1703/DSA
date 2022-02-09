#include <stdio.h>
#include <stdlib.h>

typedef struct circular_queue
{
    int size;
    int front, rear;
    int *arr;
} cqueue;

void create(cqueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->arr = (int *)malloc(q->size * (sizeof(int)));
}
void enqueue(cqueue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)   // modulo operation to achieve circularity.......
        printf("\nLIST IS FULL\n");

    else
    {
        q->rear = (q->rear + 1) % q->size; 
        q->arr[q->rear] = x;
    }
}

int dequeue(cqueue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("LIST IS EMPTY\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

void display(cqueue q)
{
    if (q.front == q.rear)
        printf("LIST IS EMPTY\n");

    int i = q.front + 1;
    printf("Queue Is...\n");
    do
    {
        printf("%d  ",q.arr[i]);
        i = (i+1)%q.size;
    } while (i!=(q.rear+1)%q.size);
    printf("\n");
}
int main()
{
    cqueue Q;
    create(&Q, 7);

    enqueue(&Q, 6);
    enqueue(&Q, 62);
    enqueue(&Q, 16);
    // enqueue(&Q, 16);
    // enqueue(&Q, 16);
    // enqueue(&Q, 1);
    // enqueue(&Q, 16);
    // enqueue(&Q, 56);

    display(Q);

    printf("\nDequeued %d", dequeue(&Q));
    printf("\nDequeued %d\n", dequeue(&Q));
    display(Q);
     
    enqueue(&Q, 16);
    enqueue(&Q, 56);
    display(Q);

    return 0;
}