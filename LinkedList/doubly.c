#include<stdio.h>
#include<conio.h>

#include<stdlib.h>
struct node 
{
	struct node *prev;
	int data;
    struct node *next;	
};
struct node *header,*last;
void create(void);
void show(void);


void main()
{
	int number,i;
	printf("\nEnter the number of node you want to create\n");
	scanf("%d",&number);
	for(i=1;i<=number;i++)
	 create();
	 printf("\n Now finally list is :\n");
	 show();

}

void create()
{
	struct node *temp;
	temp=malloc(sizeof(struct node));
	printf("\n Enter the data\n");
	
scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	if(header==NULL)
	{
		header=last=temp;
		return;
	}
	else
	{
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}
void show()
{
	struct node *temp=header;
	printf("\n Now in forward direction\n");
	while(temp!=NULL)
	{
		printf("->%d",temp->data);
		temp=temp->next;
	}
	temp=last;
	printf("\n Now in Backward direction\n");
	while(temp!=NULL)
	{
		printf("->%d",temp->data);
		temp=temp->prev;
	}
	
	
}