#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev, *next;
    int data;
};
struct Node *head, *last;
void create(void);
void show(void);
void insertFirst(void);
void insertLast(void);
void insertBetween(void);
void Reverse(void);
void shortedList(void);
int main()
{
    int n, i;
    printf("\nEnter Number of Node You Want to create : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        create();
    show();
    insertFirst();
    show();
    insertLast();
    show();
    Reverse();
    show();
    insertBetween();
    show();
}

void create(void)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("\t\tEnter Data : ");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = last = temp;
        return;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}
void show(void)
{
    struct Node *temp;
    temp = head;
    printf("\t\t\t\t---------List in Forward Direction-----------\n");
    while (temp!= NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
    printf("\t\t\t\t---------List in Backrward Direction-----------\n");
    temp = last;
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n\n");
}
void insertFirst(void)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\t\tEnter Data to insert At First : ");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        printf("List Not Created\n");
        return;
    }
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertLast(void)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\t\tEnter Data to inser at Last : ");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        printf("List Not Created\n");
        return;
    }
    temp->next = NULL;
    temp->prev = last;
    last->next = temp;
    last = temp;
}
void insertBetween(void)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    current = head;
    int val;
    printf("\t\tEnter Data to insert Between : ");
    scanf("%d", &temp->data);
    printf("\t\tEnter Data to after which you want to insert : ");
    scanf("%d", &val);
    if (head == NULL)
    {
        printf("List Not Created\n");
        return;
    }
    while (current != NULL)
    {

        if (current->data == val)
        {
            temp->prev = current;
            temp->next = current->next;
            if (current != last)
                current->next->prev = temp;
            else
                last = temp;
            current->next = temp;
            return;
        }
        else
            current = current->next;
    }
    printf("Value Not Found.....Try Again\n");
}
void Reverse(void)
{
    struct Node *temp, *temp2;
    temp = head;
    while (temp != NULL)
    {
        temp2 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp2;
        temp = temp->prev;
    }
    temp=last;
    last = head;
    if(temp!=NULL)
    head = temp;

}
