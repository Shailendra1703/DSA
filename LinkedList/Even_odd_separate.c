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

    while (current->next != NULL)
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
    printf("\n");
}

// void checkNode(struct Node *t)
// {
//     struct Node *Ehead=NULL,*Ohead=NULL;
//     while (t!=NULL)
//     {
//         /* code */
//         if(t->data%2==0)
//         {
//             create(&Ehead,t->data);
//         }
//         else
//         {
//            create(&Ohead,t->data);
//         }
//         t = t->next;
//     }
//     show(Ehead);
//     show(Ohead);
// }

// void checkNode(struct Node **head)
// {
//     struct Node *temp = *head, *p1 = NULL, *p2 = NULL, *last = NULL, *prev = NULL;
//     int count = 0;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     last = temp;
//     temp = *head;
//     p2 = last;
//     // printf("%d",temp->data);

//     while (temp != last)
//     {
//         if ((temp->data) % 2 != 0)
//         {
//             if (prev == NULL)
//                 *head = temp->next;
//             else
//                 prev->next = temp->next;

//             p2->next = temp;
//             p2 = temp;
//             // p2->next = NULL;
//             temp = temp->next;
//         }
//         else
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//     }
//     if (temp->data % 2 != 0)
//     {
//         prev->next = temp->next;
//         p2->next = temp;
//         p2 = p2->next;
//     }
//     p2->next = NULL;
// }
void seg(struct Node ** head)
{
    struct node *temp = *head, *prev = NULL, *stop = last;

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    while (temp != stop)
    {

        if ((temp->a) % 2 != 0)
        {
            if (prev == NULL)
            {
                header = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            last->next = temp;
            last = last->next;
            temp = temp->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    if (temp->a % 2 != 0)
    {
        prev->next = temp->next;
        last->next = temp;
        last = last->next;
    }
    last->next = NULL;
}
int main()
{
    struct Node *head2, *head1;
    head1 = head2 = NULL;

    printf("\nFirst Node\n");
    create(&head1, 1);
    create(&head1, 21);
    create(&head1, 2);
    // create(&head1, 3);
    // create(&head1, 41);
    // create(&head1, 5);
    // create(&head1, 5);
    // create(&head1, 6);
    show(head1);
    checkNode(&head1);
    show(head1);
    return 0;
}

