#include <stdio.h>
#include <stdlib.h>

#define size 10

int front = -1, rear = -1;
int pri_que[size];

void check(int data)
{
    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

void insert(int data)
{
    if (rear > size)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }

    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

void delete (int data)
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }

    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
            rear--;

            if (rear == -1)
                front == -1;
            return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}

void show()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", pri_que[i]);
    }
    printf("\n");
}

int main()
{

    int val;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter data: ");
        scanf("%d", &val);
        insert(val);
    }
    show();
    int d;
    scanf("%d", &d);
    delete (d);
    show();
    return 0;
}
