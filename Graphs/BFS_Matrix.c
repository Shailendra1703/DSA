#include <stdio.h>

#define N 9

int G[10][10];
int n;
int visited[10] = {0};

int front = -1, rear = -1, queue[N];
void enqueue(int i)
{
    if (front == N - 1)
        printf("full\n");
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

void BFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    int u;
    while (!isEmpty())
    {
        u = dequeue();

        for (int v = 1; v <= n; v++)
        {
            if (G[u][v] == 1 && visited[v] == 0)
            {
                printf("%d ", v);
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main()
{
    printf("Enter Number of vertex : ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%d", &G[i][j]);

    printf("BFS Traversal is :");
    BFS(2);
    return 0;
}