#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} queue;

queue *front = NULL, *rear = NULL;

void enqueue(int val)
{
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->data = val;
    temp->next = NULL;

    if (front == NULL)
    {
        front = rear = temp;
        return;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue()
{
    int p = -1;

    if (front == NULL)
    {
        printf("Underflow\n");
        return p;
    }
    else
    {
        p = front->data;
        front = front->next;
    }
    return p;
}

int getfront()
{
    if (front == NULL)
        return -1;
    else
        return front->data;
}
int getrear()
{
    if (rear == NULL)
        return -1;
    else
        return rear->data;
}


void show()
{
    queue* temp = front;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    queue *q;
    enqueue(23);
    enqueue(22);
    enqueue(21);

    show();
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    return 0;
}