#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> vis, par, tmp;

int dfs(int i, int p = -1)
{
    vis[i] = 1;
    par[i] = p;
    tmp.push_back(i);

    for (auto x : v[i])
    {
        if (vis[x] == 0)
        {
            int z = dfs(x, i);
            if (z != -1)
                return z;
        }
        else if (vis[x] == 1)
        {
            int sum = x;
            while (i != x)
            {
                sum += i;
                i = par[i];
            }
            if (i == x)
                return sum;
            return -1;
        }
    }
    return -1;
}

int largestSumCycle(int n, vector<int> g)
{

    int ans = -1;
    vis = vector<int>(n);
    par = vector<int>(n);
    v = vector<vector<int>>(n);

    for (int i = 0; i < n; i++)
    {
        if (g[i] != -1)
            v[i].push_back(g[i]);
    }
    // evry node check dfs
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans = max(ans, dfs(i));
            for (auto j : tmp)
            {
                vis[j] = 2;
            }
            tmp.clear();
        }
    }
    return ans;
}

int main()
{
    int n;
    vector<int> pr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        pr.push_back(q);
    }

    cout << largestSumCycle(n, pr);

    return 0;
}
// 23
// 4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21