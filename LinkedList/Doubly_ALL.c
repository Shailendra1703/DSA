#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *header, *last;

/**************************CREATING LIST*****************/
void create()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if (header == NULL)
    {
        header = last = temp;
        return;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}
/*********************DISPLAY LIST*************************/
void Display(void)
{
    struct Node *temp;
    temp = header;
    if (header == NULL)
    {
        printf("List Not Created\n");
        return;
    }
    printf("\n-----------------List In Forward Direction-----------------\n\n");
    while (temp != NULL)
    {
        printf("-->%d", temp->data);
        temp = temp->next;
    }
    temp = last;

    printf("\n-----------------List In Backward Direction-----------------\n\n");
    while (temp != NULL)
    {
        printf("-->%d", temp->data);
        temp = temp->prev;
    }
}

void Insertion(void)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *temp2;
    int val;
    int choice;

    printf("\nWhere you want to insert Node press :\n1. To Insert At Head\n2. To Insert Between\n\nPlease Enter Your choice \n");
    scanf("%d", &choice);
    printf("\n\nEnter Data : ");
    scanf("%d", &temp->data);
    /******************INSERTION AT HEAD******************/
    if (choice == 1)
    {
        temp->prev = NULL;
        temp->next = header;
        if (header != NULL)
            header->prev = temp;
        header = temp;
    }
    /***************INSERTION BETWEEN NODES*******************/

    if (choice == 2)
    {
        printf("Enter Node After which you want to insert : ");
        scanf("%d", &val);

        temp2 = header;
        if (temp2 == NULL)
        {
            printf("List Not Created\n");
            return;
        }

        while (temp2 != NULL)
        {
            if (temp2->data == val && temp2->next != NULL)
            {
                temp->prev = temp2;
                temp->next = temp2->next;

                temp2->next->prev = temp;
                temp2->next = temp;
                return;
            }
            /*****************INSERTION AT END*************/
            else if (temp2->data == val && temp2->next == NULL)
            {
                temp->prev = temp2;
                temp->next = NULL;
                temp2->next = temp;
                last = temp;
            }
            temp2 = temp2->next;
        }
    }
}
void Deletion(void)
{
    struct Node *temp, *t;
    int val;
    printf("\n\nEnter Node Data which you want to delete : ");
    scanf("%d", &val);

    temp = header;
    if (temp->data == val)
    {
        header = temp->next;
        header->prev = NULL;
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == val && temp->next != NULL)
        {
            // t = temp->next;
            // temp->next = t->next;
            // t->next->prev = temp;

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // free(t);
            return;
        }
        else if (temp->data == val && temp->next == NULL)
        {
            last = temp->prev;
            last->next = NULL;

            return;
        }
        temp = temp->next;
    }

    printf("\nNode value Not Found .......Try Again\n");
}
void reverse()
{
    struct Node *temp, *curr;
    curr = header;
    if (curr == NULL)
        return;

    while (curr != NULL)
    {
        temp = curr->prev;
        if (temp == NULL)
            last = curr;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        header = temp->prev;
}
int main()
{
    int n;
    printf("\n\nTotal No. of Nodes you want to create :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        create();
    Display();
    Insertion();
    Display();
    Deletion();
    Display();
    reverse();
    Display();
    return 0;
}

