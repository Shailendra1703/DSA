#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *lc, *rc;
} T;

T *insert(T *root, int data)
{
    T *prev = NULL;
    T *temp = (T *)malloc(sizeof(T));
    temp->data = data;
    temp->lc = temp->rc = NULL;

    while (root != NULL)
    {
        prev = root;
        if (data > root->data)
            root = root->rc;

        else
            root = root->lc;
    }

    if (prev == NULL)
        return temp;

    if (data > prev->data)
        prev->rc = temp;
    else
        prev->lc = temp;

    return prev;
}

int get_right_min(T *temp)
{
    while (temp->lc != NULL)
    {
        temp = temp->lc;
    }
    return temp->data;
}

T *remove_node(T *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data < val)
        root->rc = remove_node(root->rc, val);

    else if (root->data > val)
        root->lc = remove_node(root->lc, val);

    else
    {
        // leaf node..........

        if (root->lc == NULL && root->rc == NULL)
        {
            free(root);
            return NULL;
        }

        // right child........

        else if (root->rc == NULL)
        {
            T *temp = root->lc;
            free(root);
            return temp;
        }

        else if (root->lc == NULL)
        {
            T *temp = root->rc;
            free(root);
            return temp;
        }
        else
        {
            int min = get_right_min(root->rc);
            root->data = min;
            root->rc = remove_node(root->rc, min);
        }
    }
    return root;
}

void Inorder(T *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->lc);
    printf("%d ", temp->data);
    Inorder(temp->rc);
}
void Preorder(T *temp)
{
    if (temp == NULL)
        return;
    printf("%d ", temp->data);
    Preorder(temp->lc);
    Preorder(temp->rc);
}
void Postorder(T *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->lc);
    Postorder(temp->rc);
    printf("%d ", temp->data);
}

int main()
{
    T *root = NULL;
    root = insert(root, 5);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);

    insert(root, 2);
    insert(root, 7);
    insert(root, 6);

    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPostorder\n");
    Postorder(root);

    int val;
    printf("\n\tEnter value to be deleted : ");
    scanf("%d", &val);

    root = remove_node(root, val);

    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPostorder\n");
    Postorder(root);
    return 0;
}
