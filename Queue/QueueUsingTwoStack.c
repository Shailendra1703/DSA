
// queue using two pointers................

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *s1 = NULL, *s2;

void push(struct stack **top, int x)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = x;
    temp->next = NULL;

    if (*top == NULL)
    {
        *top = temp;
        return;
    }
    else
    {
        temp->next = *top;
        *top = temp;
    }
}

int pop(struct stack **top)
{
    int x = -1;
    struct stack *temp = *top;
    if (*top == NULL)
        printf("Empty\n");
    else
    {
        x = temp->data;
        *top = temp->next;
    }
    printf("\n");
    return x;
}

int IsEmpty(struct stack *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void display(struct stack *top)
{
    if (top == NULL)
        printf("Empty Queue\n");
    while (top != NULL)
    {
        printf("%d<--", top->data);
        top = top->next;
    }
    printf("\n");
}

int Dequeue()
{
    int x = -1;
    if (IsEmpty(s2))
    {
        if (IsEmpty(s1))
        {
            printf("Queue Underflow\n");
            return x;
        }
        else
        {
            while (!IsEmpty(s1))
            {
                push(&s2, pop(&s1));
            }
        }
    }
    x = pop(&s2);
    return x;
}
int main()
{

    push(&s1, 78);
    push(&s1, 8);
    push(&s1, 90);
    push(&s1, 76);
    display(s1);

    printf("%d ", Dequeue());
    printf("\n");
    display(s1);
    push(&s1, 90);
    display(s1);
    display(s2);
    printf("%d ", Dequeue());
    printf("%d ", Dequeue());
    printf("%d ", Dequeue());
    printf("%d ", Dequeue());
    display(s1);
    display(s2);

    return 0;
}