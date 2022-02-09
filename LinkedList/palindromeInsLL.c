#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct stack
{
    int d;
    struct stack *nx;
};
void push(struct stack **top, int n)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->d = n;
    s->nx = NULL;
    if (*top == NULL)
    {
        *top = s;
        return;
    }
    else
    {
        s->nx = *top;
        *top = s;
    }
}
int pop(struct stack **p)
{
    if (*p == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    struct stack *s = *p;
    int n = s->d;

    *p = s->nx;
    return n;
}
void create(struct Node **temp, int val)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node)), *c;
    t->data = val;
    t->next = NULL;
    if (*temp == NULL)
    {
        *temp = t;
        return;
    }
    c = *temp;
    while (c->next != NULL)
    {
        c = c->next;
    }
    c->next = t;
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
void show_Stack(struct stack *t)
{
    struct stack *tp = t;
    while (tp != NULL)
    {
        printf("-->%d", tp->d);
        tp = tp->nx;
    }
}

void checkPalindrome(struct Node *tp)
{
    struct Node *t;
    t = tp;
    struct stack *s = NULL;
    while (t != NULL)
    {
        push(&s, t->data);
        t = t->next;
    }

    t = tp;
    while (t != NULL)
    {
        int i = pop(&s);
        if (t->data == i)
        {
            t = t->next;
        }
        else
        {
            printf("\n\nList Not Palindrome\n");
            return;
        }
    }
    printf("\nList is Plaindrome\n");
    // printf("\n\nStack Is\n\n");
    // show_Stack(s);
}
int main()
{
    struct Node *head2, *head1;
    head1 = head2 = NULL;

    printf("\nFirst Node\n");
    create(&head1, 23);
    create(&head1, 23);
    create(&head1, 43);
    create(&head1, 43);
    create(&head1, 13);
    create(&head1, 23);
    show(head1);
    checkPalindrome(head1);
    return 0;
}