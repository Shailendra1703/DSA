#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *lc, *rc;
    Node(int v)
    {
        val = v;
        lc = NULL;
        rc = NULL;
    }
};

Node *InsertInBST(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);

    if (data > root->val)
    {
        root->rc = InsertInBST(root->rc, data);
    }

    else
    {
        root->lc = InsertInBST(root->lc, data);
    }

    return root;
}

void Inorder(Node *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->lc);
    printf("%d ", temp->val);
    Inorder(temp->rc);
}
void Preorder(Node *temp)
{
    if (temp == NULL)
        return;
    printf("%d ", temp->val);
    Preorder(temp->lc);
    Preorder(temp->rc);
}
void Postorder(Node *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->lc);
    Postorder(temp->rc);
    printf("%d ", temp->val);
}
int main()
{
    Node *root = NULL;
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
//Inorder
// 1 2 3 4 5 7 
// Preorder
// 5 1 2 3 4 7 
// Postorder
// 1 2 3 4 7 5


// Inorder
// 1-->2-->3-->4-->5-->7-->
// Inorder using Stack.....
// 1-->2-->3-->4-->5-->7-->
// Preorder
// 5-->1-->3-->2-->4-->7-->
// Preorder Using stack....
// 5-->1-->3-->2-->4-->7-->
// Postorder
// 2-->4-->3-->1-->7-->5-->
// Postorder using stack.....
// -->2-->4-->3-->1-->7-->5