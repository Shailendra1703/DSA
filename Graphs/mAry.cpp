#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string value;
    Node *parent;
    int an = 0, dec = 0;
    bool islocked = false;
    vector<Node *> links;

    Node(string value, Node *parent)
    {
        this->value = value;
        this->parent = parent;
        an = 0;
        dec = 0;
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
    Tree()
    {
        root = NULL;
    }
}

void
print(Node *root)
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
    cout << "Enter No. of node : ";
    cin >> n;
    cout << "Enter No. of childs per Node : ";
    cin >> m;

    vector<string> temp(n);

    for (int i = 0; i < n; i++)
        cin >> temp[i];

    root = new Node(temp[0], nullptr);
    root = createTree(root, m, temp);

    print(root);

    return 0;
}
