#include <stdio.h>
#include <stdlib.h>

#define N 9
int DFS[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0}};

void DFSfx(int i)
{
    static int visited[8] = {0};
    if (visited[i] == 0)
    {
        printf("%d ", i);
        visited[i] = 1;
        for (int v = 1; v <= 7; v++)
        {
            if (DFS[i][v] == 1 && visited[v] == 0)
                DFSfx(v);
        }
    }
}

int main()
{

    printf("The DFS Traversal Is : ");
    DFSfx(4);
    return 0;
}
