#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *lc, *rc;
} Tree;

typedef struct cir_queue
{
    int front;
    int rear;
    int size;
    Tree **arr;
} cqueue;

void create(cqueue *temp, int k)
{
    temp->front = temp->rear = 0;
    temp->size = k;
    temp->arr = (Tree **)malloc(temp->size * (sizeof(Tree)));
}

void enqueue(cqueue *q, Tree *k)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("List Full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = k;
}

Tree *dequeue(cqueue *q)
{
    Tree *x = NULL;
    if (q->front == q->rear)
    {
        printf("LF");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

int isEmpty(cqueue q)
{
    return q.rear == q.front;
}
void show(cqueue q)
{
    if (q.front == q.rear)
        printf("NULL");
    else
    {
        int i = q.front + 1;
        do
        {
            printf("%d ", q.arr[i]);
            i = (i + 1) % q.size;
        } while (i != (q.rear + 1) % q.size);
        printf("\n");
    }
}

Tree * root = NULL;
void createTree()
{
    Tree *p , *t;
    cqueue q;int data;
    create(&q, 100);

    root = (Tree *)malloc(sizeof(Tree));
    printf("Enter Root : ");
    scanf("%d", &root->data);
    root->lc = root->rc = NULL;

    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter Lc of %d : ",p->data);
        scanf("%d",&data);

        if(data!=-1)
        {
            t = malloc(sizeof(Tree));
            t->data = data;
            t->lc = NULL;
            t->rc = NULL;
            p->lc = t;
            enqueue(&q,t);
        }
        printf("Enter rc of %d : ",p->data);
        scanf("%d",&data);

        if(data!=-1)
        {
            t = malloc(sizeof(Tree));
            t->data = data;
            t->lc = NULL;
            t->rc = NULL;
            p->rc = t;
            enqueue(&q,t);
        }
    }
}

void Inorder(Tree *temp)
{
    if (temp == NULL)
        return;

    Inorder(temp->lc);
    printf("%d-->", temp->data);
    Inorder(temp->rc);
}


int main()
{
    createTree();
    Inorder(root);
    return 0;
}

// int main()
// {
//     cqueue Q;
//     create(&Q, 10);
//     enqueue(&Q, 6);
//     enqueue(&Q, 62);
//     enqueue(&Q, 16);

//     show(Q);

//     printf("\nDequeued %d", dequeue(&Q));
//     printf("\nDequeued %d\n", dequeue(&Q));
//     show(Q);

//     enqueue(&Q, 16);
//     enqueue(&Q, 56);
//     show(Q);
// }