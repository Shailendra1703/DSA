#include <stdlib.h>
#include <stdio.h>

struct Poly
{
    int coefficent, power;
    struct Poly *next;
} * head, *last;

void create(int c, int p)
{
    struct Poly *temp = (struct Poly *)malloc(sizeof(struct Poly));
    temp->coefficent = c;
    temp->power = p;

    if (head == NULL)
    {
        head = last = temp;
        return;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

void show()
{
    struct Poly *tp;
    tp = head;

    if (tp == NULL)
        return;

    while (tp != NULL)
    {
        if (tp != head)
        {
            if (tp->coefficent > 0)
                printf(" + %dX^%d ", tp->coefficent, tp->power);
            else
                printf("  %dX^%d ", tp->coefficent, tp->power);
        }

        else if ( tp->next == NULL && tp->power == 0)
        {
            printf("%d", tp->coefficent);break;
        }
        else if (tp->next == NULL && tp->power != 0)
        {
            printf("%dX^%d", tp->coefficent, tp->power);
            break;
        }
        else
            printf(" %dX^%d", tp->coefficent, tp->power);

        tp = tp->next;
    }
}
int main()
{
    create(7, 3);
    create(-3, -2);
    create(-12, 0);
    show();
    return 0;
}