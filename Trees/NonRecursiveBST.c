#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *lc, *rc;

} Tree;

/*----------------------------------------------------************************------------------------------------------------------*/

// searching....................................
void searchNode(Tree *root)
{
    int num;
    printf("\nEnter Node data to Find : ");
    scanf("%d", &num);
    Tree *temp = root;

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            printf("\nNode with %d data Found\n", num);
            return;
        }
        if (num > temp->data)
        {
            temp = temp->rc;
        }
        else
        {
            temp = temp->lc;
        }
    }
    printf("\nNode with %d data Not Found\n", num);
}

/*----------------------------------------------------************************------------------------------------------------------*/

//creation ...............................
Tree *InsertInBST(Tree *root, int num)
{
    Tree *temp = root, *temp2 = NULL, *y = NULL;
    temp2 = (Tree *)malloc(sizeof(Tree));
    temp2->data = num;
    temp2->lc = temp2->rc = NULL;

    while (temp != NULL)
    {
        y = temp;
        if (num > temp->data)
        {
            temp = temp->rc;
        }
        else
        {
            temp = temp->lc;
        }
    }

    
    if (y == NULL)
    {
        y = temp2;
    }
    else if (num > y->data)
    {
        y->rc = temp2;
    }
    else
        y->lc = temp2;

    return y;
}

/*----------------------------------------------------************************------------------------------------------------------*/

void Deltion(Tree *root)
{
    int num;
    printf("Enter Node data you want to delete\n");
    scanf("%d", &num);
    Tree *temp = root, *x = NULL;
    while (temp != NULL)
    {
        x = temp;

        if (num > temp->data)
            temp = temp->rc;
        else
            temp = temp->lc;

        //1 . For leaf Node..........
        if (temp->lc == NULL && temp->rc == NULL)
        {
            if (x->lc == temp && x->lc->data == num)
            {
                printf("\nDeleted Node with %d data\n\n", num);
                x->lc = NULL;
                return;
            }
            if (x->rc == temp && x->lc->data == num)
            {
                printf("\nDeleted Node with %d data\n\n", num);
                x->rc = NULL;
                return;
            }
        }

        //2. for node with one child....

        // For only left child
        if (temp->lc != NULL && temp->rc == NULL)
        {
            if (x->lc == temp && x->lc->data == num)
            {
                printf("\nDeleted Node with %d data\n\n", num);
                x->lc = temp->lc;
            }
            else
            {
                printf("\nDeleted Node with %d data\n\n", num);
                x->rc = temp->lc;
            }

            return;
        }

        // for only right child

        if (temp->lc == NULL && temp->rc != NULL)
        {
            if (x->lc == temp && x->lc->data == num)
            {
                printf("\nDeleted Node with %d data\n\n", num);
                x->lc = temp->rc;
            }
            else
            {
                printf("\nDeleted Node with %d data\n\n", num);
                x->rc = temp->rc;
            }
            return;
        }

        //for node having both child.....

        if (temp->lc != NULL && temp->rc != NULL)
        {
            Tree *Succesor = temp->rc;

            while (Succesor->lc != NULL)
            {
                x = Succesor;
                Succesor = Succesor->lc;
            }
            
            temp->data = Succesor->data;
            temp = Succesor;
        }
    }
}

void Inorder(Tree *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->lc);
    printf("%d ", temp->data);
    Inorder(temp->rc);
}
void Preorder(Tree *temp)
{
    if (temp == NULL)
        return;
    printf("%d ", temp->data);
    Preorder(temp->lc);
    Preorder(temp->rc);
}
void Postorder(Tree *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->lc);
    Postorder(temp->rc);
    printf("%d ", temp->data);
}
int main()
{
    Tree *root = NULL;
    root = InsertInBST(root, 5);
    InsertInBST(root, 1);
    InsertInBST(root, 3);
    InsertInBST(root, 4);
    InsertInBST(root, 2);
    InsertInBST(root, 7);
    InsertInBST(root, 6);

    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPostorder\n");
    Postorder(root);

    searchNode(root);
    Deltion(root);
    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPostorder\n");
    Postorder(root);

    return 0;
}
