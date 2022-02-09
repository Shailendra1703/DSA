#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top;

void push(int val)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = val;
    temp->next = NULL;
    if (top == NULL)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack has no elements yet......\n");
        return 0;
    }
    int p = top->data;
    top = top->next;
    return p;
}
void show()
{
    struct stack *print;
    print = top;
    if (print == NULL)
    {
        printf("\nStack underflow");
        return;
    }
    while (print != NULL)
    {
        printf("%d-->", print->data);
        print = print->next;
    }
    printf("NULL\n");
}
int main()
{
    push(10);
    push(13);
    push(14);
    push(15);
    printf("\nStack Is\n");
    show();
    printf("\nTop value is popped : %d\n",pop());
    printf("\nTop value is popped : %d\n",pop());
    printf("\nNow Stack is\n");
    show();
    return 0;
}