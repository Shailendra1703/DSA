// #include<stdio.h>
// #include<stdlib.h>

// typedef struct queueNode{
// 	int data;
// 	int priority;
// 	struct queueNode* next;
// } queue;

// struct queueNode* front;

// void insert(int val, int pr){
// 	queue* newnode= (queue* )malloc(sizeof(queue));
// 	queue *ptr=front, *prev= NULL;
// 	newnode->data=val;
// 	newnode->priority= pr;
// 	newnode->next=NULL;

// 	if(front==NULL){
// 		front =newnode;
// 	}
// 	else if(ptr->priority>newnode->priority){
// 		newnode->next=ptr;
// 		front=newnode;
// 	}
// 	else{

// 		while(ptr!=NULL && ptr->priority<= newnode->priority){
// 			prev=ptr;
// 			ptr=ptr->next;
// 		}
// 		newnode->next=ptr;
// 		prev->next=newnode;
// 	}

// }

// void display(){
// 	queue *ptr=front;
// 	while(ptr!=NULL){
// 		printf("%d ", ptr->data);
// 		ptr=ptr->next;
// 	}
// }

// int main(){
// 	insert(1,6);
// 	insert(3,2);
// 	insert(5,4);
// 	insert(2,1);
// 	insert(4,5);
// 	display();

// 	return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data, priority;
    struct queue *next;
} queue;

queue *front = NULL;

void insert(int d, int p)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    queue *ptr = front, *prev = NULL;
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    if (front == NULL)
        front = temp;

    else if (ptr->priority > temp->priority)
    {
        temp->next = ptr;
        front = temp;
    }

    else
    {
        while (ptr != NULL && ptr->priority <= temp->priority)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = temp;
        temp->next = ptr;
    }
}

void display()
{
    queue *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insert(4, 3);
    insert(5, 2);
    insert(1, 9);
    insert(8, 0);

    display();
    return 0;
}