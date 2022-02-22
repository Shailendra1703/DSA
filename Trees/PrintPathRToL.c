#include <stdio.h>
#include <stdlib.h>
#define N 10
int top = -1;
int arr[N];
typedef struct Node
{
    int data;
    struct Node *lc, *rc;
} node;

node *CreateTree(int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->lc = temp->rc = NULL;
    return temp;
}
void push(int val)
{
    if (top == N - 1)
        return;
    arr[++top] = val;
}

void pop()
{
    if (top == -1)
        return;
    top--;
}
void DisplayPath()
{
    for (int i = top; i > -1; i--)
        printf("%d ", arr[i]);
    printf("\n\n");
}
void Inorder(node *root)
{
    if (root == NULL)
        return;

    push(root->data);
    Inorder(root->lc);
    if (root->lc == NULL && root->rc == NULL)
        DisplayPath();
    Inorder(root->rc);
    pop();
}


int height(node *root)
{
    int t1 = 0, t2 = 0;
    if (root == NULL)
        return 0;

    t1 = height(root->lc);
    t2 = height(root->rc);

    if (t1 > t2)
        return t1 + 1;
    else
        return t2 + 1;
}

int main()
{
    node *root = NULL;
    root = CreateTree(5);
    root->lc = CreateTree(10);
    root->rc = CreateTree(25);
    root->lc->lc = CreateTree(19);
    root->lc->lc->lc = CreateTree(23);
    root->lc->rc = CreateTree(13);
    root->rc->lc = CreateTree(12);
    Inorder(root);

    printf("\nHeight Of Tree Is %d ", height(root));
    return 0;
}