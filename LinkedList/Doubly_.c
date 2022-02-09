
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *prev, *next;
} *head = NULL;

void createLL(int arr[], int n)
{
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    head->prev = NULL;
    struct Node *temp = head;
    int i;
    for (i = 1; i < n; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }
    return;
}

// // void insertfirst(int data){
// //         Node *newNode=new Node(data);
// //         if(head==NULL){
// //             head=newNode;
// //             return;
// //         }
// //         newNode->next=head;
// //         head->prev=newNode;
// //         head=newNode;
// //         return;
// // }

// //     void insertlast(int data){
// //         Node *newNode=new Node(data);
// //         if(head==NULL){
// //             head=newNode;
// //             return;
// //         }
// //         Node *temp;
// //         temp=head;
// //         while(temp->next!=NULL){
// //             temp=temp->next;
// //         }
// //         temp->next=newNode;
// //         newNode->prev=temp;
// //         return;
// //     }

// //     void insertafter(int val, int data){
// //         Node *newNode=new Node(data);
// //         if(head==NULL){
// //             head=newNode;
// //             return;
// //         }
// //         Node *temp=head;
// //         while(temp->data!=val && temp->next!=NULL){
// //             temp=temp->next;
// //         }
// //         newNode->next=temp->next;
// //         newNode->prev=temp;
// //         if(temp->next)
// //         temp->next->prev=newNode;
// //         temp->next=newNode;
// //         return;
// //     }

// // void insertbefore(int val, int data){
// //         Node *newNode=new Node(data);
// //         if(head==NULL){
// //             head=newNode;
// //             return;
// //         }
// //         else if(head->data==val){
// //             newNode->next=head;
// //             head->prev=newNode;
// //             head=newNode;
// //             return;
// //         }
// //         Node *temp=head;
// //         while(temp->next->data!=val && temp->next!=NULL){
// //             temp=temp->next;
// //         }
// //         newNode->next=temp->next;
// //         newNode->prev=temp;
// //         temp->next->prev=newNode;
// //         temp->next=newNode;
// //         return;
// //     }

// //     void deletefirst(){
// //         if(head==NULL){
// //             cout<<"List is Empty.";
// //             return;
// //         }
// //         else if(head->next==NULL){
// //             delete head;
// //             return;
// //         }
// //         Node *temp=head;
// //         head->next->prev=NULL;
// //         head=head->next;
// //         delete temp;
// //         return;
// //     }

// //     void deletelast(){
// //         if(head==NULL){
// //             cout<<"List is Empty.";
// //             return;
// //         }
// //         else if(head->next==NULL){
// //             delete head;
// //             return;
// //         }
// //         Node *temp=head;
// //         while(temp->next!=NULL){
// //             temp=temp->next;
// //         }
// //         temp->prev->next=NULL;
// //         delete temp;
// //         return;
// //     }

// //     void deleteany(int val){
// //         Node *temp1=head;
// //         if(head==NULL){
// //             cout<<"List is Empty.";
// //             return;
// //         }
// //         else if(head->data==val && head->next!=NULL){
// //             head=head->next;
// //             delete temp1;
// //             return;
// //         }
// //         else if(head->data==val && head->next==NULL){
// //             delete head;
// //             return;
// //         }

// //         while(temp1->data!=val && temp1->next!=NULL){
// //             temp1=temp1->next;
// //         }
// //         if(temp1->next==NULL && temp1->data!=val){
// //             cout<<"Element not FOUND.";
// //             return;
// //         }
// //         temp1->prev->next=temp1->next;
// //         temp1->next->prev=temp1->prev;
// //         delete temp1;
// //         return;
// //     }

// void display()
// {
//     if (head == NULL)
//     {
//         printf("List is Empty.");
//         return;
//     }
//     struct Node *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     return;
// }

int main()
{
    int n, i;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    createLL(arr, n);
    // list.insertlast(10);
    // list.insertlast(20);
    // list.insertlast(30);
    // list.insertfirst(40);
    // list.insertafter(40,50);
    // list.insertafter(30,60);
    // list.insertbefore(60,70);
    // list.insertbefore(40,80);
    // list.deletefirst();
    // list.deletelast();
    // list.deleteany(50);
    // list.deleteany(40);
    // list.deleteany(80);
    display();
    return 0;
}