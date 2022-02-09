#include <stdlib.h>
#include <stdio.h>
typedef struct Node Node;
struct Node
{
    int data;
    Node *next;
};

typedef struct queue
{
    Node *front, *rear;
} queue;

queue *createqueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node *newNode(int k)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

void enqueue(queue *q, int k)
{
    Node *node = newNode(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = node;
        return;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
}

void dequeue(queue *q)
{
    if (q->front == NULL)
        return;
    else
    {
        Node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
    }
}

void show(queue *q)
{
    if (q->rear == NULL)
        printf("Nothing\n");
    else
    {
        Node *temp = q->front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    queue *q = createqueue();
    enqueue(q, 10);
    enqueue(q, 20);
    show(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    dequeue(q);
    printf("Queue Front : %d \n", q->front->data);
    printf("Queue Rear : %d", q->rear->data);
    return 0;
}
