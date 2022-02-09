
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_AVL
{
    int data;
    struct Node_AVL *lc, *rc;
    int height;
} AVL;

AVL *root = NULL;

AVL *insertion(AVL *temp, int key)
{
    AVL *newNode = (AVL *)malloc(sizeof(AVL)), *prev = NULL;
    newNode->data = key;
    newNode->lc = newNode->rc = NULL;
    newNode->height = 1;

    while (temp != NULL)
    {
        prev = temp;
        if (key > temp->data)
        {
            temp = temp->rc;
        }
        else
        {
            temp = temp->lc;
        }
    }

    //root Node...........

    if (prev == NULL)
        prev = newNode;

    else if (key < prev->data)
    {
        prev->lc = newNode;
    }

    else
    {
        prev->rc = newNode;
    }

    return prev;
}
void Inorder(AVL *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->lc);
    printf("%d ", temp->data);
    Inorder(temp->rc);
}
void Preorder(AVL *temp)
{
    if (temp == NULL)
        return;
    printf("%d ", temp->data);
    Preorder(temp->lc);
    Preorder(temp->rc);
}

int main()
{

    root = insertion(root, 5);
    insertion(root, 1);
    insertion(root, 3);
    insertion(root, 4);
    insertion(root, 2);
    insertion(root, 7);
    insertion(root, 6);

    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    return 0;
}