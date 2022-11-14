#include<iostream>
#include<queue>
using namespace std;

int G[100][100];
int n;

void bfs(int x)
{
    int visited[n] = {0};
    queue<int> q;
    cout<<x<<" ";
    q.push(x);
    visited[x]=1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 1 ; i<=n ; i++)
        {
            if(G[u][i]==1 && visited[i]==0)
            {
                cout<<i<<" ";
                q.push(i);
                visited[i] = 1;
            }

        }
    }
}

int main()
{
   
    cin>>n;
    for(int i = 0; i<=n ; i++)
    {
        for(int j = 0 ; j<=n ; j++)
        cin>>G[i][j];
    }

    bfs(4);
    return 0;
}
// 7
// 0 0 0 0 0 0 0 0
// 0 0 1 1 1 0 0 0
// 0 1 0 1 0 0 0 0
// 0 1 1 0 1 1 0 0
// 0 1 0 1 0 1 0 0
// 0 0 0 1 1 0 1 1
// 0 0 0 0 0 1 0 0
// 0 0 0 0 0 1 0 00.