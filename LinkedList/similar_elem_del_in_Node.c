#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head, *last;

void create(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = last = temp;
        return;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}
void print()
{
    struct Node *h = head;
    while (h != NULL)
    {
        printf("%d-->", h->data);
        h = h->next;
    }
    printf("NULL\n");
}
void deleteDuplicate()
{
    struct Node *t1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node *)malloc(sizeof(struct Node));
    t1 = head;
    if (head == NULL)
        printf("List Not created yet.....\n");

    while (t1->next != NULL)
    {
        if (t1->data == t1->next->data)
        {
            prev = t1->next->next;
            free(t1->next);
            t1->next = prev;
        }
        else
            t1 = t1->next;
    }
}
void delete ()
{
    struct Node *t1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t2 = (struct Node *)malloc(sizeof(struct Node));

    t1 = head;
    while (t1->next != NULL)
    {
        t2 = t1;
        while (t2->next != NULL)
        {
            if (t1->data == t2->next->data)
            {
                prev = t2->next->next;
                free(t2->next);
                t2->next = prev;
            }
            else
                t2 = t2->next;
        }
        t1 = t1->next;
    }
}
int main()
{
    create(12);
    create(12);
    create(5);
    create(45);
    create(45);
    create(5);
    create(55);
    print();
    delete ();
    printf("\n________________After Deletion_______________\n");
    print();
    return 0;
}