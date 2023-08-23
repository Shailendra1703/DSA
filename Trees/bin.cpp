#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *lc, *rc;

    Node(int data)
    {
        this->data = data;
        lc = rc = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->lc);
    cout << root->data << " ";
    inorder(root->rc);
}

Node *create()
{
    int p;
    cout << "Enter root node";
    cin >> p;

    Node *root = new Node(p);

    queue<Node *> q;

    q.push(root);

    while (q.empty() != true)
    {
        Node *temp = q.front();
        q.pop();

        int lc, rc;
        cout << "Enter left child" << endl;
        cin >> lc;

        if (lc != -1)
        {
            Node *left = new Node(lc);
            temp->lc = left;
            q.push(left);
        }
        cout << "Enter right child" << endl;
        cin >> rc;

        if (rc != -1)
        {
            Node *right = new Node(rc);
            temp->rc = right;
            q.push(right);
        }
    }

    return root;
}
int main()
{

    Node *root = create();

    inorder(root);

    return 0;
}