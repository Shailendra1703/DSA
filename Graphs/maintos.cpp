#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<string> nodes;
unordered_map<string, int> indexof;
unordered_map<string, int> lockedBy;
unordered_map<string, set<string>> lockedChildList;

int getParent(int i)
{
    if (i == 0)
        return -1;
    return (i - 1) / m;
}

bool lock(string nodeName, int id)
{
    // already locked
    if (lockedBy.find(nodeName) != lockedBy.end())
        return false;

    // descendants are locked
    if (lockedChildList[nodeName].size() > 0)
        return false;

    // check ancestors
    int i = getParent(indexof[nodeName]);
    while (i != -1)
    {
        if (lockedBy.find(nodes[i]) != lockedBy.end())
            return false;
        i = getParent(i);
    }

    i = getParent(indexof[nodeName]);
    while (i != -1)
    {
        lockedChildList[nodes[i]].insert(nodeName);
        i = getParent(i);
    }
    lockedBy[nodeName] = id;
    return true;
}

bool unlock(string nodename, int id)
{
    // already locked
    if (lockedBy.find(nodename) == lockedBy.end())
        return false;

    // ids are not same
    if (lockedBy[nodename] != id)
        return false;

    int i = getParent(indexof[nodename]);
    while (i != -1)
    {
        lockedChildList[nodes[i]].erase(nodename);
        i = getParent(i);
    }

    lockedBy.erase(nodename);
    return true;
}

bool upgrade(string nodeName, int id)
{
    // already locked
    if (lockedBy.find(nodeName) != lockedBy.end())
        return false;

    int i = indexof[nodeName];
    i = getParent(i);

    set<int> ids;
    // getting ids of locked childs
    for (auto it = lockedChildList[nodeName].begin(); it != lockedChildList[nodeName].end(); it++)
    {
        ids.insert(lockedBy[*it]);
    }
    if (ids.size() > 1)
        return false;
    if (ids.size() == 0)
        return false;

    set<string> temp(lockedChildList[nodeName]);

    for (auto it = temp.begin(); it != temp.end(); it++)
    {
        if (!unlock(*it, id))
            return false;
    }
    return lock(nodeName, id);
}
int main()
{
    cin >> n >> m >> q;
    nodes.assign(n, "");
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
        indexof[nodes[i]] = i;
    }

    for (int i = 0; i < q; i++)
    {
        int op, id;
        string nodename;

        cin >> op;
        cin >> nodename;
        cin >> id;

        switch (op)
        {
        case 1:
            if (lock(nodename, id))
                cout << "true" << endl;
            else
                cout << "false" << endl;
            break;
        case 2:
            if (unlock(nodename, id))
                cout << "true" << endl;
            else
                cout << "false" << endl;
            break;
        case 3:
            if (upgrade(nodename, id))
                cout << "true" << endl;
            else
                cout << "false" << endl;

        default:
            break;
        }
    }
}