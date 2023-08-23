#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string value;
    vector<Node *> links;

    Node(string value)
    {
        this->value = value;
    }

    void addLinks(vector<Node *> &v)
    {
        for (auto &it : v)
            links.push_back(it);
    }
};

Node *createTree(Node *root, int m)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        vector<Node *> v;

        for (int i = 0; i < m; i++)
        {
            string p;
            cout << "Enter value of " << i + 1 << " child of " << temp->value << " : " << endl;
            cin >> p;
            if (p != "no")
                v.push_back(new Node(p));
        }

        if (v.size() != 0)
            temp->addLinks(v);

        for (auto it : temp->links)
            q.push(it);
    }

    return root;
}

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
    string temp;
    int m;
    cout << "Enter No. of childs per Node : ";
    cin >> m;
    cout << "Enter root Node data : ";
    cin >> temp;

    root = new Node(temp);
    root = createTree(root, m);

    print(root);

    return 0;
}
