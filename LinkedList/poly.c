#include <stdio.h>
#include <stdlib.h>

struct term
{

    int coef, exp;
    struct term *next;
};

void create(struct term **, int, int);
void show(struct term *);
void Addition(struct term *, struct term *);
int main()
{
    struct term *poly1 = NULL, *poly2 = NULL;
    // poly1 = poly2 = NULL;
    create(&poly1, 5, 3);
    create(&poly1, 5, 4);
    create(&poly1, 51, 3);
    create(&poly1, 5, 0);

    printf("\n --------First Polynomial-------\n");
    show(poly1);
    create(&poly2, 45, 3);
    create(&poly2, 4, 3);
    create(&poly2, 1, 3);
    create(&poly2, 5, 13);

    printf("\n --------Second Polynomial-------\n");
    show(poly2);

    Addition(poly1, poly2);
    return 0;
}

void create(struct term **poly, int c, int e)
{
    struct term *temp = malloc(sizeof(struct term)), *tp;
    temp->coef = c;
    temp->exp = e;
    temp->next = NULL;

    if (*poly == NULL)
    {
        *poly = temp;
        return;
    }
    else
    {
        tp = *poly;
        while (tp->next != NULL)
        {
            tp = tp->next;
        }
        tp->next = temp;
    }
}

void Addition(struct term *poly1, struct term *poly2)
{
    struct term *New_poly = NULL, *t1, *t2;
    t1 = poly1;
    t2 = poly2;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp == t2->exp)
        {
            create(&New_poly, (t1->coef * t2->coef), t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->exp > t2->exp)
        {
            create(&New_poly, t1->coef, t1->exp);
            t1 = t1->next;
        }
        else
        {
            create(&New_poly, t2->coef, t2->exp);
            t2 = t2->next;
        }
    }
    while (t1 != NULL)
    {
        create(&New_poly, t1->coef, t1->exp);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        create(&New_poly, t2->coef, t2->exp);
        t2 = t2->next;
    }

    printf("\n\nThe Resultant Polynomial Is : ");
    show(New_poly);
}

void show(struct term *t)
{
    if (t == NULL)
    {
        printf("\nPolynomial Empty\n");
        return;
    }
    while (t != NULL)
    {
        if (t->exp == 0)
            printf("%d", t->coef);
        else if (t->next == NULL)
            printf("%dX^%d", t->coef, t->exp);
        else
            printf("%dX^%d + ", t->coef, t->exp);
        t = t->next;
    }
}

/*
void add(struct node *p1,struct node *p2,struct node **p3)
{
	if(p1==NULL && p2==NULL)
	{
		printf("\n Poly empty\n");
		return;
	}
	while(p1!=NULL && p2!=NULL)
	{
		if(*p3==NULL)
		{
			temp=malloc(sizeof(struct node));
			*p3=temp;
		}
		else
		{
			temp->next=malloc(sizeof(struct node));
			temp=temp->next;
		}
	if(p1->exp>p2->exp)
		{
			temp->coef=p1->coef;
			temp->exp=p1->exp;
			p1=p1->next;
		}
		else
		{
		if(p2->exp>p1->exp)
		{
			temp->coef=p2->coef;
			temp->exp=p2->exp;
			p2=p2->next;
		}	
		else
	{
			temp->coef=p2->coef + p1->coef;
			temp->exp=p2->exp;
			p2=p2->next;
			p1=p1->next;
		}
		}
	}
	while(p1!=NULL)
	{
	  	temp->next=malloc(sizeof(struct node));
		  temp=temp->next;
		  temp->coef=p1->coef;
			temp->exp=p1->exp;
			p1=p1->next;

	}
		while(p2!=NULL)
	{
	  	temp->next=malloc(sizeof(struct node));
		  temp=temp->next;
		  temp->coef=p2->coef;
			temp->exp=p2->exp;
			p2=p2->next;
		  	
	}
	temp->next=NULL;
}
*/