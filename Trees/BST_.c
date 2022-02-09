#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lc, *rc;
    int data;
};

struct Node *create(int data)
{
    struct Node *temp ;
    temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = data;
    temp->lc = temp->rc = NULL;
    return temp;
}

struct Node *InsertInBST(struct Node *root, int v)
{

    if (root == NULL)
        return create(v);
    if (v > root->data)
    {
        // root->lc = InsertInBST(root->lc, v);
        root->rc = InsertInBST(root->rc, v);
    }
    else
    {
        // root->rc = InsertInBST(root->rc, v);
        root->lc = InsertInBST(root->lc, v);
    }
    return root;
}
void Inorder(struct Node *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->lc);
    printf("%d ", temp->data);
    Inorder(temp->rc);
}
void Preorder(struct Node *temp)
{
    if (temp == NULL)
        return;
    printf("%d ", temp->data);
    Preorder(temp->lc);
    Preorder(temp->rc);
}
void Postorder(struct Node *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->lc);
    Postorder(temp->rc);
    printf("%d ", temp->data);
}
int main()
{
    struct Node *root = NULL;
    root = InsertInBST(root, 5);
    InsertInBST(root, 1);
    InsertInBST(root, 3);
    InsertInBST(root, 4);
    InsertInBST(root, 2);
    InsertInBST(root, 7);

    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPostorder\n");
    Postorder(root);
    return 0;
}