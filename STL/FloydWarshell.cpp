#include <bits/stdc++.h>
using namespace std;

int graph[][4] = {
    {0, 1, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
    {1, 0, 1, 0},
};

void Warshall(int g[][4], int n, int p)
{
    int k = p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == k || j == k || g[i][j] == 1)
                continue;
            else
            {
                if (g[i][k] == 1 && g[k][i] == 1)
                    g[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}

int main()
{

    for (int p = 0; p < 4; p++)
    {

        cout << "\nR[" << p + 1 << "]" << endl;
        Warshall(graph, 4, p);
    }
    return 0;
}