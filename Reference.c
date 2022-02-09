#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void create(struct Node **temp, int val)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node)), *current;

    t->data = val;
    t->next = NULL;
    if (*temp == NULL)
    {
        *temp = t;
        return;
    }
       
        current = *temp;

        while (current->next!= NULL)
        {
            current = current->next;
        }
        current->next = t;
    
}

void show(struct Node *t)
{
    struct Node *tp = t;
    while (tp != NULL)
    {
        printf("-->%d", tp->data);
        tp = tp->next;
    }
}
int main()
{
    struct Node *head2,*head1;
    head1=head2=NULL;

    printf("\nFirst Node\n");
    create(&head1, 23);
    create(&head1, 13);
    create(&head1, 43);
    create(&head1, 53);
    show(head1);
    printf("\nSecond Node\n");
    create(&head2, 94);
    create(&head2, 92);
    create(&head2, 94);
    create(&head2, 97);
    show(head2);
}
