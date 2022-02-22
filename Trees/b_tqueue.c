#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *lc, *rc;
} tree;

typedef struct queue
{
    int front, rear, size;
    tree **arr;
} queue;

void create_queue(queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->arr = (tree **)malloc(q->size * sizeof(tree *));
}

void enqueue(queue *q, tree *t)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = t;
}

tree *dequeue(queue *q)
{
    tree *x = NULL;
    if (q->front == q->rear)
      printf("Queue is empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

int isempty(queue q)
{
    return (q.front == q.rear);
}


tree *create_tree()
{
    queue q;
    create_queue(&q, 100);

    tree *root = (tree*)malloc(sizeof(tree));
    printf("Enter the root node : ");
    scanf("%d", &root->data);
    root->lc = root->rc = NULL;
    enqueue(&q, root);

    tree *p;
    int val;

    while (!isempty(q))
    {
        p = dequeue(&q);
        printf("Enter lc of %d ", p->data);
        scanf("%d", &val);

        if (val != -1)
        {
            tree *temp = (tree *)malloc(sizeof(tree));
            temp->data = val;
            temp->lc = temp->rc = NULL;
            p->lc = temp;
            enqueue(&q, temp);
        }
        printf("Enter rc of %d ", p->data);
        scanf("%d", &val);

        if (val != -1)
        {
            tree *temp = (tree *)malloc(sizeof(tree));
            temp->data = val;
            temp->lc = temp->rc = NULL;
            p->rc = temp;
            enqueue(&q, temp);
        }
    }
    return root;
}

void Inorder(tree *temp)
{
    if (temp == NULL)
        return;

    Inorder(temp->lc);
    printf("%d-->", temp->data);
    Inorder(temp->rc);
}

void Preorder(tree *temp)
{
    if (temp == NULL)
        return;
    printf("%d-->", temp->data);
    Preorder(temp->lc);
    Preorder(temp->rc);
}
void Postorder(tree *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->lc);
    Postorder(temp->rc);
    printf("%d-->", temp->data);
}

int main()
{
    tree *root = create_tree();
    printf("\nInorder\n");
    Inorder(root);
    printf("\nPreorder\n");
    Preorder(root);
    printf("\nPostorder\n");
    Postorder(root);
    return 0;
}