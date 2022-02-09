// // { Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

// struct Node
// {
// 	int data;
// 	struct Node *next;

// 	Node(int x){
// 	    int data = x;
// 	    next = NULL;
// 	}
// };

// void deleteAlt(struct Node *head);

// /* Given a reference (pointer to pointer) to the head
//    of a list and an int, appends a new node at the end  */
// void append(struct Node** head_ref, int new_data)
// {
//     /* 1. allocate node */
//     struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

//     struct Node *last = *head_ref;  /* used in step 5*/

//     /* 2. put in the data  */
//     new_node->data  = new_data;

//     /* 3. This new node is going to be the last node, so make next
//           of it as NULL*/
//     new_node->next = NULL;

//     /* 4. If the Linked List is empty, then make the new node as head */
//     if (*head_ref == NULL)
//     {
//        *head_ref = new_node;
//        return;
//     }

//     /* 5. Else traverse till the last node */
//     while (last->next != NULL)
//         last = last->next;

//     /* 6. Change the next of last node */
//     last->next = new_node;
//     return;
// }

// void printList(struct Node *node)
// {
// 	while (node != NULL)
// 	{
// 		cout<<node->data<<' ';
// 		node = node->next;
// 	}
// 	cout<<endl;
// }

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--){
//         int n, tmp;
//         struct Node* head = NULL;
//         cin>>n;
//         while(n--){
//             cin>>tmp;
//             append(&head, tmp);
//         }
//         deleteAlt(head);
//         printList(head);
//     }
// 	return 0;
// }
// // } Driver Code Ends

// /*
// Structure of the node of the binary tree
// struct Node
// {
// 	int data;
// 	struct Node *next;

// 	Node(int x){
// 	    int data = x;
// 	    next = NULL;
// 	}
// };
// */
// // Complete this function
// void deleteAlt(struct Node *head){
//     // Code here
//     if(head==NULL && head->next == NULL)
//     return;

//     struct Node * alt , *prev= head;
//     struct Node *curr = head->next;

//     while(prev->next!=NULL)
//     {
//         prev->next = curr->next;
//         prev = prev->next;

//         curr = prev->next;

//     }
// }

// { Driver Code Starts

#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(struct Node **headRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

void alternatingSplitList(struct Node *);

struct Node *a;
struct Node *b;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        a = b = NULL;
        struct Node *head = NULL;

        int n, k;
        cin >> n;

        while (n--)
        {
            cin >> k;
            append(&head, k);
        }

        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}

// } Driver Code Ends

/*
structure of node is as
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/

// { Driver Code Starts

#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(struct Node **headRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

void alternatingSplitList(struct Node *);

struct Node *a;
struct Node *b;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        a = b = NULL;
        struct Node *head = NULL;

        int n, k;
        cin >> n;

        while (n--)
        {
            cin >> k;
            append(&head, k);
        }

        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}

// } Driver Code Ends

/*
structure of node is as
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/

void alternatingSplitList(struct Node *head)
{
    //Your code here
    if (head == NULL || head->next == NULL)
        return;

    struct Node *tail1, *tail2;
    a = tail1 = head;
    b = tail2 = head->next;

    while (tail1 && tail2 && tail1->next && tail2->next != NULL)
    {
        tail1->next = tail2->next;

        tail1 = tail1->next;

        tail2->next = tail1->next;

        tail2 = tail2->next;
    }

    tail1->next = NULL;
}
