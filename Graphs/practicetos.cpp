#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string v;
    int uid, ac, des;
    Node *parent;
    bool isLocked;
    vector<Node *> childs;

    Node(string v, Node *p)
    {
        this->v = v;
        this->parent = p;
        isLocked = false;
        uid = 0;
        ac = 0;
        des = 0;
    }

    void addChilds(vector<string> l, Node *r)
    {
        for (auto it : l)
        {
            childs.push_back(new Node(it, r));
        }
    }
};

class Tree
{
private:
    Node *root;
    unordered_map<string, Node *> mp;

public:
    Tree() : root(NULL) {}
    Node *getRoot()
    {
        return root;
    }
    void printTree(Node *r)
    {
        cout << "Parent: " << r->v << "\n";
        cout << "Child: \n";
        for (auto k : r->childs)
        {
            cout << k->v << " anc_locked: " << k->ac
                 << " dec_locked:" << k->des << " isLocked:"
                 << k->isLocked << " uid:" << k->uid << "\n";
        }
        cout << "\n";
        for (auto k : r->childs)
        {
            printTree(k);
        }
    }
    void buildTree(vector<string> &s, int &m)
    {
        Node *r = new Node(s[0], nullptr);
        queue<Node *> que;

        que.push(r);
        int st = 1;
        while (!que.empty())
        {
            Node *temp = que.front();
            que.pop();
            if (st >= s.size())
                continue;

            vector<string> v;
            for (int i = st; i < st + m; i++)
            {
                v.push_back(s[i]);
            }
            st += m;
            temp->addChilds(v, temp);

            for (auto it : temp->childs)
                que.push(it);
        }

        root = r;
    }

    void fillvTon(Node *r)
    {
        if (!r)
            return;
        mp[r->v] = r;
        for (auto it : r->childs)
        {
            fillvTon(it);
        }
    }

    bool verify(Node *temp, vector<Node *> &v, int id)
    {
        if (temp->isLocked)
        {
            if (temp->uid != id)
                return false;
            v.push_back(temp);
        }

        if (temp->des == 0)
            return true;

        bool ans = true;
        for (auto it : temp->childs)
        {
            ans &= verify(it, v, id);
            if (ans == false)
                return false;
        }

        return ans;
    }

    void informdes(Node *r, int val)
    {
        for (auto it : r->childs)
        {
            it->ac += val;
            informdes(it, val);
        }
    }

    bool lock(string name, int id)
    {
        Node *temp = mp[name];
        if (temp->isLocked)
            return false;

        if (temp->ac != 0 || temp->des != 0)
            return false;

        Node *curr = temp->parent;
        while (curr)
        {
            curr->des++;
            curr = curr->parent;
        }

        informdes(temp, 1);

        temp->isLocked = true;
        temp->uid = id;
        return true;
    }
    bool unlock(string name, int id)
    {
        Node *temp = mp[name];

        if (!temp->isLocked)
            return false;

        if (temp->uid != id)
            return false;

        Node *curr = temp->parent;
        while (curr)
        {
            curr->des--;
            curr = curr->parent;
        }

        informdes(temp, -1);

        temp->isLocked = false;
        return true;
    }
    bool upgrade(string name, int id)
    {
        Node *temp = mp[name];
        if (temp->isLocked)
            return false;

        if (temp->ac != 0)
            return false;

        if (temp->des == 0)
            return false;

        vector<Node *> v;
        if (verify(temp, v, id))
        {
            for (auto it : v)
            {
                unlock(it->v, id);
            }
        }
        else
            return false;
        lock(name, id);
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

    Tree t;
    t.buildTree(s, m);
    t.fillvTon(t.getRoot());
    // t.printTree(t.getRoot());

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