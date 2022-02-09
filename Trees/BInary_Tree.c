#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct B_Tree Tree;
struct B_Tree
{
    int data;
    Tree *lc, *rc;
    bool visited;
};

Tree *createTree(int val)
{
    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->data = val;
    temp->lc = temp->rc = NULL;
    temp->visited = false;
    return temp;
}

void Inorder(Tree *root)
{

    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp = root;
    if (root == NULL)
        return;

    Inorder(temp->lc);
    printf("%d-->", temp->data);
    Inorder(temp->rc);
}
void preorder(Tree *root)
{

    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp = root;
    if (root == NULL)
        return;

    printf("%d-->", temp->data);
    preorder(temp->lc);
    preorder(temp->rc);
}
void postorder(Tree *root)
{

    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp = root;
    if (root == NULL)
        return;

    preorder(temp->lc);
    preorder(temp->rc);
    printf("%d-->", temp->data);
}

//Preorder Using Moris....Traversal.................

void MorrisPreorder(Tree *root)
{
    while (root)
    {
        if (root->lc == NULL)
        {
            printf("%d ", root->data);
            root = root->rc;
        }
        else
        {
            Tree *current = root->lc;
            while (current->rc != NULL && current->rc != root)
                current = current->rc;

            if (current->rc == NULL)
            {
                printf("%d ", root->data);
                current->rc = root;
                root = root->lc;
            }
            else
            {
                current->rc = NULL;
                root = root->rc;
            }
        }
    }
}

//Inorder.....using Morris traversal..... Only Difference is of print Statement
// For preorder  ....parent->lc->rc;
//For Inorder ....lc->parent or root ->rc;

void MorrisInorder(Tree *root)
{
    while (root)
    {
        if (root->lc == NULL)
        {
            printf("%d ", root->data);
            root = root->rc;
        }
        else
        {
            Tree *curr = root->lc;
            while (curr->rc != NULL && curr->rc != root)
                curr = curr->rc;
            if (curr->rc == NULL)
            {
                curr->rc = root;
                root = root->lc;
            }
            else
            {
                curr->rc = NULL;
                printf("%d ", root->data);
                root = root->rc;
            }
        }
    }
}

//Post Order Traversal......using Morris
void MorrisPostorder(Tree *head)
{
    Tree *root = head;
    while (root && root->visited == false)
    {
        if (root->lc  && root->lc->visited == false)
            root = root->lc;

        else if (root->rc && root->rc->visited == false)
            root = root->rc;

        else
        {
            printf("%d ", root->data);
            root->visited = true;
            root = head;
        }
    }
}

int main()
{
    Tree *root;
    root = createTree(42);
    root->lc = createTree(90);
    root->rc = createTree(34);
    root->lc->lc = createTree(32);
    root->lc->rc = createTree(78);
    root->rc->lc = createTree(31);
    root->rc->rc = createTree(33);

    printf("\n\t INORDER TRAVERSING......\n");
    Inorder(root);
    printf("\n\n");
    MorrisInorder(root);
    printf("\n\n\t PREORDER TRAVERSING......\n");
    preorder(root);
    printf("\n\n");
    MorrisPreorder(root);
    printf("\n\n\t POSTORDER TRAVERSING......\n");
    postorder(root);
    printf("\n\n");
    MorrisPostorder(root);
    return 0;
}