
/********************SINGLY LINK LIST*********************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *header, *last;

/************************CREATING LIST*******************/

void create(void)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (header == NULL)
    {
        header = last = temp;
        return;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

/************************PRINTING LIST*******************/

void show(void)
{
    struct Node *t;
    t = header;
    printf("\n\n");
    while (t != NULL)
    {
        printf("-->%d", t->data);
        t = t->next;
    }
    printf("\n\n");
}

/**************************INSERTION**********************/

void Insertion(void)
{
    int val, choice;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Where you want to insert Node press :\n1. To Insert At Head\n2. To Insert Between\n3.To Insert At Last\n\nPlease Enter Your choice \n");
    scanf("%d", &choice);
    printf("Enter Data :");
    scanf("%d", &temp->data);
    /******** INSERTION AT HEAD********/
    if (choice == 1)
    {
        temp->next = header;
        header = temp;
        return;
    }

    /**********INSERTION BETWEEN**************/
    else if (choice == 2)
    {
        printf("Enter the data after which you want to insert the Node : ");
        scanf("%d", &val);
        struct Node *tractor = header;
        if (tractor == NULL)
        {
            printf("List not created\n");
            return;
        }
        while (tractor != NULL)
        {
            if (tractor->data == val)
            {
                if (tractor->next != NULL)
                    temp->next = tractor->next;
                else
                    temp->next = NULL;
                tractor->next = temp;

                return;
            }
            tractor = tractor->next;
        }
        printf("Node Not Found.......Try Again\n");
    }
    /*********INSERTION AT LAST*********/
    else if (choice == 3)
    {
        last->next = temp;
        last = temp;
        temp->next = NULL;
        return;
        /////if last node pointer is not present then use a node pointer for traversing the list and find the last node the perform the above step///////
    }
    else
        printf("Please Enter a valid choice\n");
}
/*********************DELETION******************/
void Deletion(void)
{
    struct Node *temp, *temp2;
    int val;
    temp = header;
    /******LIST IS EMPTY*******/
    if (temp == NULL)
    {
        printf("List Not Created.....\n");
        return;
    }
    printf("Enter Node value which you want to Delete : ");
    scanf("%d", &val);

    /*****FOR FIRST NODE********/
    if (header->data == val)
    {
        header = header->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != val)
    {
        temp2 = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node Not Found......Try again\n");
        return;
    }

    temp2->next = temp->next;
    
    
}


/********************PAIR-WISE-SWAPPING********************/
void PairWiseSwapping()
{
    struct Node *p1, *p2, *p3;
    p1 = header;
    p2 = p1->next;
    if (header == NULL)
    {
        printf("List Not Created\n");
        return;
    }
    else if (header->next == NULL)
    {
        printf("There is only one Node......Swapping NOt possible\n");
        return;
    }
    header = p2;
    p3 = p2->next;
    p2->next = p1;
    for (;;)
    {
        if (p3 == NULL || p3->next == NULL)
        {
            p1->next = p3;
            return;
        }
        p1->next = p3->next;
        p1 = p3;
        p2 = p1->next;
        p3 = p2->next;
        p2->next = p1;
    }
}


/***********************REVERSING THE LIST****************/
void Reverse(void)
{
    struct Node *prev, *current, *_next;
    prev = NULL;
    current = header;
    if (current == NULL)
    {
        printf("List Not created\n");
        return;
    }
    while (current != NULL)
    {
        _next = current->next;
        current->next = prev;
        prev = current;

        if (_next == NULL)
        {
            header = prev;
            return;
        }
        current = _next;
    }
}                  
      


void ReverseII()
{
    struct Node* curr = header,*nxt;

    while(curr->next!=NULL)
    {
        nxt = curr->next;
        curr->next = nxt->next;
        nxt->next = header;
        header = nxt;

    }
}

int main()
{
    int n;
    printf("\n\nTotal No. of Nodes you want to create :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        create();
    show();
    // printf("Performing Deletion...\n");
    // Deletion();
    // show();
    // printf("Performing Insertion...\n");

    // Insertion();
    // show();
    printf("Performing Reverse...\n");
    Reverse();
    show();
    printf("Performing PairWiseSwapping...\n");
    PairWiseSwapping();
    show();

    ReverseII();
    show();
    return 0;
}