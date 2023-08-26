#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string value;
    Node *parent;
    int an = 0, dec = 0;
    bool islocked = false;
    vector<Node *> links;
    int uid;

    Node(string value, Node *parent)
    {
        this->value = value;
        this->parent = parent;
        an = 0;
        dec = 0;
        uid = 0;
        islocked = false;
    }

    void addLinks(vector<string> &v, Node *p)
    {
        for (auto &it : v)
            links.push_back(new Node(it, p));
    }
};

Node *createTree(Node *root, int m, vector<string> &s)
{

    queue<Node *> q;
    q.push(root);

    int stop = 1;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (stop >= s.size())
            continue;

        vector<string> v;
        for (int i = stop; i < stop + m; i++)
            v.push_back(s[i]);
        temp->addLinks(v, temp);
        stop += m;

        for (auto it : temp->links)
            q.push(it);
    }

    return root;
}

class Tree
{
private:
    Node *root;
    unordered_map<string, Node *> mp;

public:
    Tree(Node *r)
    {
        root = r;
    }

    void fillvToN(Node *r)
    {
        if (!r)
            return;
        mp[r->value] = r;

        for (auto it : r->links)
            fillvToN(it);
    }

    void informDec(Node *t, int val)
    {
        for (auto it : t->links)
        {
            it->an += val;
            informDec(it, 1);
        }
    }

    // getting all nodes which will be unlocked
    bool verify(Node *t, int id, vector<Node *> &v)
    {
        if (t->islocked)
        {
            if (t->uid != id)
                return false;

            v.push_back(t);
        }

        if (t->dec == 0)
            return true;

        bool ans = true;
        for (auto it : t->links)
        {
            ans &= verify(it, id, v);
            if (ans == false)
                return false;
        }

        return ans;
    }

    bool lock(string sq, int id)
    {
        Node *r = mp[sq];

        if (r->islocked)
            return false;

        if (r->an != 0 || r->dec != 0)
            return false;

        Node *curr = r->parent;
        while (curr)
        {
            curr->dec++;
            curr = curr->parent;
        }

        informDec(r, 1);

        r->uid = id;
        r->islocked = true;

        return true;
    }

    bool unlock(string s, int id)
    {
        Node *t = mp[s];

        if (!t->islocked)
            return false;

        if (t->uid != id)
            return false;

        Node *curr = t->parent;

        while (curr)
        {
            curr->dec--;
            curr = curr->parent;
        }

        informDec(t, -1);
        t->islocked = false;
        return true;
    }

    bool upgrade(string s, int id)
    {
        Node *t = mp[s];
        if (t->islocked)
            return false;

        if (t->an != 0)
            return false;
        if (t->dec == 0)
            return false;

        vector<Node *> vec;
        if (verify(t, id, vec))
        {
            for (auto it : vec)
                unlock(it->value, it->uid);
        }
        else
        {
            return false;
        }

        return lock(s, id);
    }
};

void print(Node *root)
{
    cout << root->value << " : ";
    for (auto it : root->links)
        cout << it->value << " ";
    cout << endl;
    for (auto it : root->links)
        print(it);
}

int main()
{
    Node *root;
    int m, n;
    cin >> n;
    cin >> m;

    vector<string> temp(n);

    for (int i = 0; i < n; i++)
        cin >> temp[i];

    root = new Node(temp[0], nullptr);
    root = createTree(root, m, temp);

    Tree t(root);
    t.fillvToN(root);

    int op, sq, uid;

    cout << t.lock("China", 9) << endl;

    cout << t.lock("India", 9) << endl;
    cout << t.upgrade("Asia", 9) << endl;

    cout << t.unlock("India", 9);

    return 0;
}

/*
The number of iterations is roughly O(m^h).
The work done within each iteration is constant, except for the addLinks operation, which is O(m).
Therefore, the overall time complexity of the createTree function is roughly O(m^(log_m(n))) * O(m), which simplifies to O(m^(log_m(n) + 1)).

In Big O notation, this can be further simplified to O(m^(log_m(n)))
*/
