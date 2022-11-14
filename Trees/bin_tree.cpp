#include <bits/stdc++.h>
using namespace std;

typedef struct tree
{
    int data;
    struct tree *lc, *rc;
} tree;
tree *root = NULL;

void create()
{
    tree *p;
    root = new tree;
    cout << "Root Value : ";
    cin >> root->data;

    root->lc = root->rc = NULL;
    queue<tree *> q;
    q.push(root);

    while (!q.empty())
    {
        int d;
        p = q.front();
        q.pop();

        cout << "Enter lc of " << p->data<<" ";
        cin >> d;

        if (d != -1)
        {
            tree *child = new tree;
            child->data = d;
            child->lc = child->rc = NULL;
            p->lc = child;
            q.push(child);
        }
        cout << "Enter rc of " << p->data<<" ";
        cin >> d;

        if (d != -1)
        {
            tree *child = new tree;
            child->data = d;
            child->lc = child->rc = NULL;
            p->rc = child;
            q.push(child);
        }
    }
}

void inorder(tree *head)
{
    if(head==NULL)
    return;
    inorder(head->lc);
    cout << head->data << " ";
    inorder(head->rc);
}

void preorder(tree *head)
{
    if(head==NULL)
    return;
    cout << head->data << " ";
    preorder(head->lc);
    preorder(head->rc);
}

int main()
{
    create();

    cout << "INORDER\n";
    inorder(root);

    cout << "\nPREORDER\n";
    preorder(root);
    return 0;
}