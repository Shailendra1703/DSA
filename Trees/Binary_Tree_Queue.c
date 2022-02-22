
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lc, *rc;
    int data;
} node;

typedef struct Queue
{
    int size;
    int front;
    int rear;
    node **arr;
} queue;

void create(queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->arr = (node **)malloc(q->size * sizeof(node *));
}

void enqueue(queue *q, node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue Is Full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
    }
}

node *dequeue(queue *q)
{
    node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

int isEmpty(queue q)
{
    return q.front == q.rear;
}

node *root = NULL;

void createTree()
{
    node *p, *t;
    queue q;
    int data;
    create(&q, 100);

    printf("Enter Root value : ");
    scanf("%d", &data);
    root = (node *)malloc(sizeof(node));
    root->data = data;
    root->lc = root->rc = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter Left Child of %d ", p->data);
        scanf("%d", &data);

        if (data != -1)
        {
            t = (node *)malloc(sizeof(node));
            t->data = data;
            t->lc = t->rc = NULL;
            p->lc = t;
            enqueue(&q, t);
        }

        printf("Enter Right Child %d ", p->data);
        scanf("%d", &data);

        if (data != -1)
        {
            t = (node *)malloc(sizeof(node));
            t->data = data;
            t->lc = t->rc = NULL;
            p->rc = t;
            enqueue(&q, t);
        }
    }
}
////Stack..................
struct stack
{
    node *data;
    struct stack *next;
} *top = NULL;

void push(node *c)
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

node *pop()
{
    node *temp = NULL;
    if (top == NULL)
    {
        // printf("\nStack UnderFlow\n");
        return NULL;
    }

    else
    {
        temp = top->data;

        top = top->next;
    }
    return temp;
}

int isempty()
{
    if(top==NULL)
    return 0;
    else
    return 1;
}
//////////////////////////
void Inorder(node *temp)
{
    if (temp == NULL)
        return;

    Inorder(temp->lc);
    printf("%d-->", temp->data);
    Inorder(temp->rc);
}

void Preorder(node *temp)
{
    if (temp == NULL)
        return;
    printf("%d-->", temp->data);
    Preorder(temp->lc);
    Preorder(temp->rc);
}
void Postorder(node *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->lc);
    Postorder(temp->rc);
    printf("%d-->", temp->data);
}

// PreOrder Traversal using stack or array.........

void preOrderStack(node *temp)
{
    // node **arr = (node **)malloc(50 * sizeof(node *));
    // int top = 0;
    // arr[top++] = NULL;
    node *ptr = temp, *x;
    while (ptr != NULL)
    {
        if (ptr->rc != NULL)
        {
            push(ptr->rc);
        }
        printf("%d-->", ptr->data);
        if (ptr->lc != NULL)
        {
            ptr = ptr->lc;
        }
        else
        {
            x = pop();
            ptr = x;
        }
    }
}

// void PostorderStack(node *temp)
// {
//     node *t = NULL;
//     while (1)
//     {

//         while (temp->lc != NULL)
//         {
//             push(temp);
//             temp = temp->lc;
//         }
//         while (temp->rc == NULL || temp->rc == t)
//         {
//             printf("-->%d", temp->data);
//             t = temp;
//             temp = pop();
//             if (temp == NULL)
//                 return;
//         }
//         push(temp);
//         temp = temp->rc;
//     }
// }

void PostorderStack(node* temp)
{
    push(temp);
    node* t = NULL;
    int arr[50],count=0;
    while(isempty())
    {
              t = pop();
              
              arr[count++] = t->data;

              if(t->lc!=NULL)
              push(t->lc);

              if(t->rc!=NULL)
              push(t->rc);
    }

    for(int i = count-1 ; i>-1 ; i--)
    printf("%d-->",arr[i]);
    printf("\n");
}
void InorderStack(node *temp)
{
    if (temp == NULL)
        return;
    while (1)
    {

        while (temp->lc != NULL)
        {
            push(temp);
            temp = temp->lc;
        }
        while (temp->rc == NULL)
        {
            printf("-->%d", temp->data);
            temp = pop();
            if (temp == NULL)
                return;
        }
        printf("-->%d", temp->data);
        temp = temp->rc;
    }
}

int main()
{
    createTree();
    printf("\nInorder\n");
    Inorder(root);
    printf("\nInorder using Stack.....\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPreorder Using stack....\n");
    preOrderStack(root);
    printf("\nPostorder\n");
    Postorder(root);
    printf("\nPostorder using stack.....\n");
    PostorderStack(root);

    return 0;
}