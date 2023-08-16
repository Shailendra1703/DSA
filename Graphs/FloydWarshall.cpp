#include <bits/stdc++.h>
using namespace std;

void Warshall(int *g, int n, int p)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // g[i][j] = min(g[i][j], g[i][p] + g[p][j]);
            *((g + i * n) + j) = min(*((g + i * n) + j), *((g + i * n) + p) + *((g + p * n) + j));
        }
    }
}

void printResult(int n, int *graph, int p)
{
    cout << "Result for " << p << " as an intermediate node"
         << endl;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[k] << " ";
            k++;
        }
        cout << endl;
    }

    cout << endl
         << endl;
}
int main()
{

    int n;
    cout << "Enter No. of rows and columns : ";
    cin >> n;

    int graph[n][n];

    //  taking input

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int p = 0; p < n; p++)
    {
        Warshall((int *)graph, n, p);
        printResult(n, *graph, p);
    }

    return 0;
}