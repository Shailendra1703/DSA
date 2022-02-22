#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *XOR(node *a, node *b)
{
    return (node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insert(node **head, int val)
{
    node *temp = (node *)malloc(sizeof(node)), *t, *prev;
    temp->data = val;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        t = *head;
        while (t->next != NULL)
        {
            prev = t;
            t = t->next;
        }

        t->next = XOR(temp, t->next);
    }
}

void printList(node *head)
{
    node *curr = head, *prev = NULL, *next = NULL;

    while (curr != NULL)
    {
        printf("%d ", curr->data);

        next = XOR(prev, curr->next);
        prev = curr;
        curr = next;
    }
}

int main()
{

    node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printList(head);
    //
    return (0);
}