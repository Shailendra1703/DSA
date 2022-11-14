#include <iostream>
using namespace std;

typedef struct tree
{
    int data;
    struct tree *lc, *rc;
} tree;

tree *create(tree *head, int val)
{
    tree *root = head;
    tree *temp = new tree, *prev = NULL;
    temp->data = val;
    temp->lc = temp->rc = NULL;

    while (root != NULL)
    {
        prev = root;
        if (root->data < val)
            root = root->rc;
        else
            root = root->lc;
    }

    if (prev == NULL)
        return temp;

    if (prev->data > val)
    {
        prev->lc = temp;
    }
    else
    {
        prev->rc = temp;
    }

    return head;
}

void inorder(tree *tree)
{
    if (tree == NULL)
        return;
    inorder(tree->lc);
    cout << tree->data << " ";
    inorder(tree->rc);
}
void preorder(tree *tree)
{
    if (tree == NULL)
        return;
    cout << tree->data << " ";
    preorder(tree->lc);
    preorder(tree->rc);
}

int get_min(tree *r)
{
    while (r->lc != NULL)
        r = r->lc;
    return r->data;
}
tree *deletion(tree *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data > val)
        root->lc = deletion(root->lc, val);
    else if (root->data < val)
        root->rc = deletion(root->rc, val);

    else
    {
        if (root->lc == NULL && root->rc == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->lc == NULL)
        {
            tree *temp = root->rc;
            free(root);
            return temp;
        }
        else if (root->rc == NULL)
        {
            tree *temp = root->lc;
            free(root);
            return temp;
        }
        else
        {
            int min = get_min(root->rc);
            root->data = min;
            root->rc = deletion(root->rc, min);
        }
    }
    return root;
}

int main()
{
    tree *root = NULL;
    root = create(root, 45);
    create(root, 89);
    create(root, 16);
    create(root, 6);
    create(root, 12);
    create(root, 90);

    inorder(root);
    cout << "\n";
    preorder(root);
    cout << endl;
    deletion(root, 12);
    inorder(root);
    cout << "\n";
    preorder(root);
    return 0;
}