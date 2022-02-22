#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int sum = 0;
struct stack
{
    int data;
    struct stack *next;
} *top = NULL;

void push(char c)
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    if (temp == NULL)
    {
        printf("\nStack OverFlow\n");
        return;
    }

    else
    {
        temp->data = c;
        temp->next = top;
        top = temp;
    }
}

char pop()
{
    char x;
    struct stack *temp;
    if (top == NULL)
    {
        printf("\nStack UnderFlow\n");
    }

    else
    {
        temp = top;

        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

int checkPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}

int checkOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return 0;
    else if (ch == '(' || ch == ')')
        return 0;
    else

        return 1;
}

char *InToPostfix(char *inf)
{
    int i, j, len;
    len = strlen(inf);
    i = j = 0;
    char *postfix;
    postfix = (char *)malloc((len + 1) * sizeof(char));

    while (inf[i] != '\0')
    {
        if (checkOperand(inf[i]))
            postfix[j++] = inf[i++];
        else if (inf[i] == '(')
            push(inf[i++]);

        else if (inf[i] == ')')
        {
            while (top->data != '(')
            {
                postfix[j++] = pop();
            }
            pop();
            i++;
        }
        else
        {
            if (checkPrecedence(inf[i]) > checkPrecedence(top->data))
                push(inf[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while (top != NULL && top->data != '$')
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "(2+4)*(8/7 +3/2)";
    push('$');
    char *postfix = InToPostfix(infix);

    printf("Postfix Expression is : %s\n", postfix);

    // int i = 0;
    // while (postfix[i] != '\0')
    // {
    //     if (checkOperand(postfix[i]))
    //         push(postfix[i]);

    //     else
    //     {
    //         int val1 = (int)pop() - '0'; // converting char to int
    //         int val2 = (int)pop() - '0';
    //         printf("\nval1 = %d", val1);
    //         printf("\nval2 = %d", val2);
    //         switch (postfix[i])
    //         {
    //         case '+':

    //             push(val1 + val2 + '0'); // coverting int to char
    //             break;
    //         case '-':
    //             push(val1 - val2 + '0');
    //             break;
    //         case '/':
    //             push(val2 / val1 + '0');
    //             break;
    //         case '*':
    //             push(val1 * val2 + '0');
    //             break;

    //         default:
    //             printf("\nInvalid State..\n");
    //             break;
    //         }
    //     }
    //     i++;
    // }

    // printf("\nResult Is equal to : %d", (pop() - '0'));
    return 0;
}
