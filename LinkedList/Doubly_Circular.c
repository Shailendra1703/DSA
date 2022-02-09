//doubly circular
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};
struct Node *head, *last;
void create()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data :");
    scanf("%d", &temp->data);

    temp->prev = NULL;
    temp->next = NULL;
    if (head == NULL)
    {
        head = last = temp;
        last->prev = head;
        last->next = head;
        return;
    }

    else
    {
        last->next = temp;
        temp->prev = last;
        temp->next = last;
        last = temp;
    }
    head->prev = last;
    last->next = head;
}
void show()
{
    struct Node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("List Not Created\n");
        return;
    }
    else
    {
        do
        {
            printf("-->%d", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void InsertAtFirst(void)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\n\nEnter Data You Want to insert at First : ");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        printf("List Not created\n");
        return;
    }
    head->prev = temp;
    temp->prev = last;
    temp->next = head;
    last->next = temp;
    head = temp;
}
void InsertAtLast()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\n\nEnter the Element You want to insert At Last : ");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        printf("\nList Not Created\n");
        return;
    }
    last->next = temp;
    temp->prev = last;
    temp->next = head;
    head->prev = temp;
    last = temp;
}
void InsertBetween()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *back, *current;
    current = head;
    int val;
    printf("\n\nEnter the Element You want to insert Between : ");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        printf("\nList Not Created\n");
        return;
    }
    printf("Enter The value after which you want To insert: ");
    scanf("%d", &val);
    do
    {
        if (current->data == val)
        {
            back = current;
            if (back->next != head)
                temp->next = back->next;
            else
            {
                back->next = temp;
                temp->prev = back;
                temp->next = head;
                head->prev = temp;
                last = temp;
                return;
            }
            back->next = temp;
            temp->prev = back;
        }
        current = current->next;
    } while (current != head);
}
void deletion(void)
{
    int value;
    printf("\nEnter value you want to delete : ");
    scanf("%d", &value);
    struct Node *temp, *del;
    temp = head;
    if (temp == NULL)
    {
        printf("\nList Not created..");
        return;
    }
    else
    {
        if (temp->data == value)
        {
            del = temp->next;
            temp->next->prev = last;
            head = del;
            last->next = head;
            return;
        }
        // else
        // {
        //     do
        //     {
        //         if (temp->next->data == value)
        //         {
        //             del = temp->next;
        //             if (temp->next->next != head)
        //                 temp->next->next->prev = temp;
        //             else
        //             {
        //                 head->prev = temp;
        //                 temp->next = head;
        //                 last = temp;
        //                 free(del);
        //                 return;
        //             }
        //             temp->next = temp->next->next;
        //             free(del);
        //             return;
        //         }
        //         temp = temp->next;
        //     } while (temp != head);
        // }

        else
        {
            temp = temp->next;

            do
            {
                if (temp->data == value)
                {
                    //For tackling last.....
                    if (temp->next == head)
                    {
                        last = temp->prev;
                        last->next = head;
                        head->prev = last;
                        return;
                    }
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                temp = temp->next;
            } while (temp != head);
        }
    }
}
int main()
{
    for (int i = 0; i < 4; i++)
        create();
    show();
    InsertAtFirst();
    show();
    deletion();
    show();
    InsertBetween();
    show();
    InsertAtLast();
    show();
    return 0;
}