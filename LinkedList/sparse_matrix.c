#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row, col, data;
    struct Node *next;
} node;

void create(node **head, int r, int c, int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->row = r;
    temp->col = c;
    temp->data = val;
    temp->next = NULL;

    if (*head == NULL)
        *head = temp;
    else
    {
        node *t = *head;
        while (t->next!=NULL)
            t = t->next;

        t->next = temp;
    }
}

void print(node *head)
{
    node *r, *c, *t;
    r = c = t = head;

    printf("Row position : ");
    while (r != NULL)
    {
        printf("%d ", r->row);
        r = r->next;
    }
    printf("\n");

    printf("Column position : ");
    while (c != NULL)
    {
        printf("%d ", c->col);
        c = c->next;
    }
    printf("\n");

    printf("Data : ");
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
int main()
{
    node *head = NULL;
    int arr[10][10];
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("arr[%d][%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
                create(&head, i, j, arr[i][j]);
        }

    print(head);
    return 0;
}