#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    string value;
    vector<TreeNode *> links;
    TreeNode *father;
    int ances_locked = 0;
    int desc_locked = 0;
    int uid;
    bool isLocked;

    TreeNode(string v, TreeNode *p)
    {
        value = v;
        father = p;
        ances_locked = 0;
        desc_locked = 0;
        uid = 0;
        isLocked = false;
    }

    void addLinks(vector<string> link, TreeNode *p)
    {
        for (auto &i : link)
            links.push_back(new TreeNode(i, p));
    }
};

struct TreeNode *createTree(TreeNode *root, int &n, vector<string> &s)
{
    queue<TreeNode *> que;
    que.push(root);
    int st = 1;

    while (!que.empty())
    {
        TreeNode *r = que.front();
        que.pop();

        if (st >= s.size())
            continue;

        vector<string> temp;
        for (int i = st; i < st + n; i++)
            temp.push_back(s[i]);

        r->addLinks(temp, r);
        st += n;

        for (auto k : r->links)
            que.push(k);
    }
    return root;
}

class Tree
{
private:
    TreeNode *root;
    unordered_map<string, TreeNode *> valueToNode;

public:
    Tree(TreeNode *r)
    {
        root = r;
    }

    TreeNode *getRoot() { return root; }

    void fillNodeToValue(TreeNode *r)
    {
        if (!r)
            return;

        valueToNode[r->value] = r;
        for (auto k : r->links)
        {
            fillNodeToValue(k);
        }
    }

    bool verify(TreeNode *r, int &id, vector<TreeNode *> &v)
    {
        if (r->isLocked)
        {
            if (r->uid != id)
                return false;
            v.push_back(r);
        }

        if (r->desc_locked == 0)
            return true;

        bool ans = true;

        for (auto k : r->links)
        {
            ans &= verify(k, id, v);
            if (ans == false)
                return false;
        }
        return ans;
    }

    void inform(TreeNode *r, int val)
    {
        for (auto k : r->links)
        {
            k->ances_locked += val;
            inform(k, val);
        }
    }

    bool lock(string v, int id)
    {
        TreeNode *t = valueToNode[v];

        if (t->isLocked)
            return false;

        if (t->ances_locked != 0)
            return false;

        if (t->desc_locked != 0)
            return false;

        TreeNode *current = t->father;

        while (current)
        {
            current->desc_locked++;
            current = current->father;
        }

        inform(t, 1);
        t->isLocked = true;
        t->uid = id;
        return true;
    }

    bool unlock(string x, int id)
    {
        TreeNode *t = valueToNode[x];

        // already unlocked
        if (!t->isLocked)
            return false;

        // user is not same
        if (t->isLocked && t->uid != id)
            return false;
        TreeNode *current = t->father;

        while (current)
        {
            current->desc_locked--;
            current = current->father;
        }

        inform(t, -1);
        t->isLocked = false;
        return true;
    }

    bool upgrade(string x, int id)
    {
        TreeNode *t = valueToNode[x];
        if (t->isLocked)
            return false;

        if (t->ances_locked != 0)
            return false;

        if (t->desc_locked == 0)
            return false;

        vector<TreeNode *> vec;

        if (verify(t, id, vec))
        {
            // collected all descendants in vec and unlocking them
            for (auto k : vec)
            {
                unlock(k->value, id);
            }
        }
        else
        {
            return false;
        }

        lock(x, id);
        return true;
    }
};

int main()
{
    int nodes, m, queries;
    cin >> nodes;
    cin >> m;
    cin >> queries;

    vector<string> s(nodes);
    for (int i = 0; i < nodes; i++)
        cin >> s[i];

    // creating root node first
    TreeNode *r = new TreeNode(TreeNode(s[0], nullptr));

    r = createTree(r, m, s);

    Tree t(r);
    t.fillNodeToValue(t.getRoot());

    int opcode, uid;
    string str;

    for (int i = 0; i < queries; i++)
    {
        cin >> opcode >> str >> uid;

        switch (opcode)
        {
        case 1:
            if (t.lock(str, uid))
            {
                cout << "true\n";
            }
            else
                cout << "false\n";
            break;
        case 2:
            if (t.unlock(str, uid))
                cout << "true\n";
            else
                cout << "false\n";
            break;
        case 3:
            if (t.upgrade(str, uid))
                cout << "true\n";
            else
                cout << "false\n";
            break;
        }
    }
    return 0;
}