#include <iostream>
#include <vector>
using namespace std;
#define N 4

void prims(int graph[N][N], int V, int src)
{
    vector<int> key(V, INT_MAX);
    vector<bool> fin(V, false);
    int result = 0;

    key[src] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!fin[i] && (u == -1 || key[i] < key[u]))
                u = i;

        fin[u] = true;
        result += key[u];

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && !fin[v] && graph[u][v] < key[v])
                key[v] = graph[u][v];
        }
    }

    cout << "Total cost " << result << endl;
    for (int i = 0; i < V; i++)
        cout
            << key[i] << " ";
}

int main()
{
    int graph[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    }

    prims(graph, N, 0);
    return 0;
}