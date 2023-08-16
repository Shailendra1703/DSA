#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < rooms[u].size(); i++)
            {
                if (visited[rooms[u][i]] == 0)
                {
                    q.push(rooms[u][i]);
                    visited[rooms[u][i]] = 1;
                }
            }
        }

        for (auto it : visited)
            if (it == 0)
                return false;
        return true;
    }
};

int main()
{
    Solution myobj;
    vector<vector<int>> rooms;
    rooms = {{1}, {2}, {3}, {}};

    cout << myobj.canVisitAllRooms(rooms) << endl;
    return 0;
}