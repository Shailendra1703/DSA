#include <iostream>
#include <vector>
using namespace std;
#define N 4

void dijkistra(int graph[N][N], int V, int src)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> fin(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        fin[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && fin[v] == false)
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
        }
    }

    cout << "Shortest paths are\n";
    for (int i = 0; i < V; i++)
        cout
            << dist[i] << " ";
}

int main()
{
    int graph[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    }

    dijkistra(graph, N, 0);
    return 0;
}