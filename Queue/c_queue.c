#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front, rear, size;
    int *arr;
} queue;

void create(queue *c, int s)
{
    c->size = s;
    c->front = c->rear = 0;
    c->arr = (int *)malloc(s * sizeof(int));
}

void enqueue(queue *c, int val)
{
    if ((c->rear + 1) % c->size == c->front)
        printf("FULL\n");
    else
    {
        c->rear = (c->rear + 1) % c->size;
        c->arr[c->rear] = val;
    }
}

int dequeue(queue *c)
{
    int x = -1;
    if (c->rear == c->front)
        printf("Empty\n");
    else
    {
        c->front = (c->front + 1) % c->size;
        x = c->arr[c->front];
    }
    return x;
}

void print(queue *c)
{
    int i = c->front + 1;

    do
    {

        printf("%d ", c->arr[i]);
        i = (i + 1) % c->size;
    } while (i != (c->rear + 1) % c->size);

    printf("\n");
}

int main()
{
    queue *c;
    create(c, 10);
    enqueue(c, 45);
    enqueue(c, 78);
    enqueue(c, 78);

    print(c);
    printf("%d",dequeue(c));
    return 0;
}