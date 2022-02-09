// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int precedence(char ch)
// {
//     if (ch == '+' || ch == '-')
//         return 1;
//     else if (ch == '*' || ch == '/')
//         return 2;
//     else if (ch == '^')
//         return 3;
//     else
//         return 0;
// }
// char stack[20];
// int top = -1;
// void push(char ch)
// {
//     stack[++top] = ch;
// }
// char pop()
// {
//     return stack[top--];
// }
// void main()
// {
//     char infix[20], postfix[20], revstr[20];  //  a+b/c-d*e+f*-a  //+a-/bc+*de-*fa
//     int i, j = 0, length, t;

//     printf("Enter Expression : ");
//     gets(infix);
//     strrev(infix);

//     length = strlen(infix);
//     for (i = 0; i < length; i++)
//     {
//         t = precedence(infix[i]);
//         if (t == 0)
//             postfix[j++] = infix[i];
//         else
//         {
//             if ((top == -1) || precedence(infix[i]) >= precedence(stack[top]))
//                 push(infix[i]);
//             else
//             {
//                 while ((top != -1) && precedence(infix[i]) < precedence(stack[top]))
//                 {
//                     postfix[j++] = pop();
//                 }
//                 push(infix[i]);
//             }
//         }
//     }
//     while (top != -1)
//     {
//         postfix[j++] = pop();
//     }
//     postfix[j] = '\0';
//     printf("Pre_Fix Expression : %s", strrev(postfix));
// }

// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*)
           malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity *
                                   sizeof(int));
 
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}


 // } Driver Code Ends
//User function Template for C

// create a stack of size capacity
// struct Stack* createStack( unsigned capacity );

// check if stack is empty
// int isEmpty(struct Stack* stack)

// return top character of stack
// char peek(struct Stack* stack)

// deletes top character of stack if stack is not empty
// char pop(struct Stack* stack)

// pushes character op in the stack
// void push(struct Stack* stack, char op)

//Function to convert an infix expression to a postfix expression.

int checkOperand(char s)
{
    if(s=='/' || s== '*' ||s=='+' ||s=='-' || s=='^' || s=='(' || s==')')
    return 0;
    else
    return 1;
}

int checkprec(char s)
{
    if(s=='+' || s=='-')
    return 1;
    else if(s=='*' || s=='/')
    return 2;
    else if(s == '^')
    return 3;
    else
    return -1;
}


char* infixToPostfix(char *exp)
{
    struct Stack *st;
    // Your code here
    int len = strlen(exp) , i = 0 , j =0;
    
    st = createStack(len);
    
    char *res = (char*)malloc((len+1)*sizeof(char));
    
    while(exp[i]!='\0')
    {
        if(checkOperand(exp[i]))
        {
            res[j++] = exp[i++];
        }
        else if(exp[i]=='(')
        push(st,exp[i++]);
        else if(exp[i]==')')
        {
            while(peek(st)!='(')
            {
                res[j++] = pop(st);
            }
            pop(st);i++;
        }
        else
        {
            if(checkprec(exp[i])>checkprec(peek(st)))
            push(st,exp[i++]);
            else
            {
                res[j++] = pop(st);
            }
        }
        
        while(!isEmpty(st))
        res[j++] = pop(st);
        
        res[j] = '\0';
        
        return res;
        
        
    }
    
}

// { Driver Code Starts.

int main() {
	
	int t;
	scanf("%d",&t);
    while(t--)
    {
        char *exp;
        scanf("%s",exp);
        int size=strlen(exp);
        int cnt=0,i=0;
        for(int i=0;i<size;i++)
        {
            if(exp[i]==')' || exp[i]=='(')
                cnt++;
        }
        exp=infixToPostfix(exp);
        while(i!=(size-cnt))
        {
            printf("%c",exp[i]);
            i++;
        }
        printf("\n");
    }
	return 0;
}
  // } Driver Code Ends