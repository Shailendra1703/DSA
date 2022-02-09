#include <stdio.h>
#include <stdlib.h>
#define n 10
struct queue
{
    int front = -1, back = -1;
    int *arr;
};


void push(int x)
{
    if (back == n - 1)
    {

        printf("\nOverflow\n");
        return;
    }
    back++;
    struct queue *temp = (struct queue *)malloc(n * sizeof(int));
    temp->arr[back] = x;
    if (front == -1)
        front++;
}

int pop()
{
    struct queue *temp;
    temp = front;
    return (temp->arr[front]);
    front++;
}

int main()
{
    push(30);
    push(20);
    push(10);

    printf("%d ", pop());
    return 0;
}