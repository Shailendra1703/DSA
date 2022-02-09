#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}
char stack[20];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
void main()
{
    char infix[20], postfix[20];
    int i, j = 0, length, t;

    printf("Enter Expression : ");  //abc/+de*-f*+a-
    gets(infix);

    length = strlen(infix);
    for (i = 0; i < length; i++)
    {
        t = precedence(infix[i]);
        if (t == 0)
            postfix[j++] = infix[i];
        else
        {
            if((top==-1) || precedence(infix[i])>precedence(stack[top]))
               push(infix[i]);
            else
            {
                while((top!=-1) && precedence(infix[i])<=precedence(stack[top]))
                {
                    postfix[j++] = pop();
                }
                push(infix[i]);
            }
            
        }
    }
    while(top!=-1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Post_Fix Expression : %s",postfix);

}