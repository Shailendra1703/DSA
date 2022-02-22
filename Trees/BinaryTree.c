
// Creating a binary tree.................

#include <stdio.h>
#include <stdlib.h>
int count = 0;
typedef struct BT BT;
struct BT
{
    int data;
    BT *lc, *rc;
};

//Enter -1 to put null value and return to parent node//

BT *createTree()
{
    struct BT *temp;
    temp = (BT *)malloc(sizeof(BT));

    printf("\nEnter Node Value: ");
    scanf("%d", &temp->data);

    if (temp->data == -1)
        return NULL;

    printf("Enter Left of %d", temp->data);
    temp->lc = createTree();
    printf("Enter Right of %d", temp->data);
    temp->rc = createTree();
    return temp;
}


// BT *create(int n)
// {
//     BT *node = (BT *)malloc(sizeof(BT));
//     node->data = n;
//     node->lc = node->rc = NULL;
//     return node;
// }

// BT *InsertInBT(BT *root, int n)
// {
//     if (root == NULL)
//     {
//         count++;
//         return create(n);
//     }

//     else
//     {
//         if (count % 2 != 0)
//         {
//             if (root->lc == NULL)
//             {
//                 root->lc = create(n);
//                 return root;
//             }
//             root->rc = InsertInBT(root->rc, n);
//         }
//         else
//         {
//             if (root->rc == NULL)
//             {
//                 root->rc = create(n);
//                 return root;
//             }
//             root->lc = InsertInBT(root->lc, n);
//         }
//     }
// }

void Inorder(BT *root)
{
    if (root == NULL)
        return;

    Inorder(root->lc);
    printf("%d-->", root->data);
    Inorder(root->rc);
}

void Preorder(BT *temp)
{
    if (temp == NULL)
        return;
    printf("%d-->", temp->data);
    Inorder(temp->lc);
    Inorder(temp->rc);
}
void Postorder(BT *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->lc);
    Inorder(temp->rc);
    printf("%d ", temp->data);
}
int main()
{
    BT *root = NULL;
    root=createTree();
    // root = InsertInBT(root, 34);
    // InsertInBT(root, 17);
    // InsertInBT(root, 738);
    // InsertInBT(root, 73);
    // InsertInBT(root, 98);
    // InsertInBT(root, 7);
    // InsertInBT(root, 27);
    // InsertInBT(root, 74);

    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPostorder\n");
    Postorder(root);
    return 0;
}
