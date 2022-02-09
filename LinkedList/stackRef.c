#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

void push(struct stack **top, int val)
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    if (temp == NULL)
    {
        printf("Stack Underflow");
        return;
    }
    temp->data = val;
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
void display(struct stack *top)
{
    while (top != NULL)
    {
        printf("-->%d", top->data);
        top = top->next;
    }
}
int pop(struct stack **top)
{
    struct stack *temp;
    temp = *top;
    if (temp == NULL)
    {
        printf("Stack Underflow\n");
        return 10;
    }
    int p = temp->data;
    *top = temp->next;
    return p;
}
int main()
{
    struct stack *top = NULL;
    push(&top, 19);
    push(&top, 49);
    push(&top, 39);

  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));
    // display(top);
    return 0;
}