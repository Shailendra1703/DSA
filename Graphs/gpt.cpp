#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <chrono>
#include <mutex>
using std::chrono::duration_cast;
using std::chrono::microseconds;
using namespace std;

class Node
{
public:
    string v;
    vector<Node *> links;
    Node *parent;
    int anc_locked, dec_locked, uid;
    bool isLocked;

    Node(string x, Node *p)
        : v(x), parent(p), anc_locked(0), dec_locked(0), uid(0), isLocked(false) {}

    void addLinks(vector<Node *> &l)
    {
        links = l;
    }
};

class Tree
{
private:
    Node *root;
    unordered_map<string, Node *> vton;
    mutex treemutex;

    void fillVtoN(Node *r)
    {
        if (!r)
            return;
        vton[r->v] = r;
        for (auto k : r->links)
            fillVtoN(k);
    }

    void informDecendants(Node *r, int val)
    {
        for (auto k : r->links)
        {
            k->anc_locked += val;
            informDecendants(k, val);
        }
    }

    bool verifyDescendants(Node *r, int &id, set<Node *> &lockedNodes)
    {
        if (r->isLocked)
        {
            if (r->uid != id)
                return false;
            lockedNodes.insert(r);
        }
        if (r->dec_locked == 0)
            return true;

        for (auto k : r->links)
        {
            if (!verifyDescendants(k, id, lockedNodes))
                return false;
        }
        return true;
    }

public:
    Tree(vector<string> &s, int m)
    {
        Node *r = new Node(s[0], nullptr);
        queue<Node *> q;
        q.push(r);

        int st = 1;
        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();

            vector<Node *> temp;
            for (int i = st; i < min(st + m, static_cast<int>(s.size())); i++)
                temp.push_back(new Node(s[i], cur));
            cur->addLinks(temp);
            st += m;

            for (auto k : cur->links)
                q.push(k);
        }

        root = r;
        fillVtoN(root);
    }

    Node *getRoot() { return root; }

    bool lock(string v, int id)
    {
        lock_guard<mutex> lock(treemutex);
        Node *t = vton[v];
        if (t->isLocked || t->anc_locked > 0 || t->dec_locked > 0)
            return false;

        Node *cur = t->parent;
        while (cur)
        {
            cur->dec_locked++;
            cur = cur->parent;
        }
        informDecendants(t, 1);
        t->isLocked = true;
        t->uid = id;
        return true;
    }

    bool unlock(string v, int id)
    {
        lock_guard<mutex> lock(treemutex);
        Node *t = vton[v];
        if (!t->isLocked || (t->uid != id))
            return false;

        Node *cur = t->parent;
        while (cur)
        {
            cur->dec_locked--;
            cur = cur->parent;
        }
        informDecendants(t, -1);
        t->isLocked = false;
        return true;
    }

    bool upgrade(string v, int id)
    {
        // lock_guard<mutex> lock(treemutex);
        Node *t = vton[v];
        if (t->isLocked || t->anc_locked > 0 || t->dec_locked == 0)
            return false;

        set<Node *> lockedDescendants;
        if (!verifyDescendants(t, id, lockedDescendants))
            return false;

        for (auto k : lockedDescendants)
        {
            unlock(k->v, id);
        }
        lock(v, id);
        return true;
    }
};

int main()
{
    typedef std::chrono::high_resolution_clock Clock;
    auto startTime = Clock::now();
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    Tree t(s, m);

    int op, uid;
    string sq;
    mutex coutMutex;

    for (int i = 0; i < q; i++)
    {
        lock_guard<mutex> coutLock(coutMutex);
        cin >> op >> sq >> uid;
        switch (op)
        {
        case 1:
            if (t.lock(sq, uid))
                cout << "true\n";
            else
                cout << "false\n";
            break;
        case 2:
            if (t.unlock(sq, uid))
                cout << "true\n";
            else
                cout << "false\n";
            break;
        case 3:
            if (t.upgrade(sq, uid))
                cout << "true\n";
            else
                cout << "false\n";
            break;
        }
    }
    auto endTime = Clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Total Time : " << (duration.count() / 1000000) << "sec";
    return 0;
}
