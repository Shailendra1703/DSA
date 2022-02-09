#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front, rear;
    int *arr;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int val)
{
    if (q->rear == q->size - 1)
    {
        printf("QUEUE IS FULL\n");
        return;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue *q)
{
    int x;
    if (q->rear == q->front)
        printf("QUEUE IS EMPTY");
    else
    {
        q->front++;
        x = q->arr[q->front];
        return x;
    }
}

void display(struct queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d-->", q.arr[i]);
    }
}
int main()
{
    struct queue Q;
    create(&Q, 6);
    enqueue(&Q, 67);
    enqueue(&Q, 6);
    enqueue(&Q, 5);
    enqueue(&Q, 7);

    display(Q);
    printf("\nDequeued %d",dequeue(&Q));
    printf("\nDequeued %d\n",dequeue(&Q));
    display(Q);

    return 0;
}