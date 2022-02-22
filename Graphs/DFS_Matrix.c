#include <stdio.h>

void DFS(int);
int G[10][10];

int n;

int main()
{
    printf("Enter Number of vertex : ");
    scanf("%d", &n);

    for (int i = 0; i <=n; i++)
        for (int j = 0; j <=n; j++)
            scanf("%d", &G[i][j]);

    printf("DFS Traversal is :");
    DFS(4);
    return 0;
}

void DFS(int i)
{
    static int visited[10] = {0};

    if (visited[i] == 0)
    {
        printf("%d ", i);
        visited[i] = 1;

        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == 0 && G[i][j] == 1)
                DFS(j);
        }
    }
}

