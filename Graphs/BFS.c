#include <stdio.h>
#include <stdlib.h>
#define N 9
int BFS[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0}};

int front = -1, rear = -1;
int queue[N];
void enqueue(int i)
{
    if (rear == N - 1)
    {
        printf("\tFUll\n");
        return;
    }
    else
        queue[++rear] = i;
}

int dequeue()
{
    if (front == rear)
        printf("Empty\n");
    else
        return queue[++front];
}

int isEmpty()
{
    return front == rear;
}

void BFSfx(int i, int *visted)
{
    int u;
    printf("%d ", i);
    visted[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        u = dequeue();
        for (int v = 1; v <= 7; v++)
        {
            if (BFS[u][v] == 1 && visted[v] == 0)
            {
                printf("%d ", v);
                visted[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main()
{
    int visited[N];

    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
    BFSfx(2, visited);
}