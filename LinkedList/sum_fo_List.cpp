// // { Driver Code Starts
// // driver

// #include <bits/stdc++.h>
// using namespace std;

// /* Linked list Node */
// struct Node {
//     int data;
//     struct Node* next;
//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };

// struct Node* buildList(int size)
// {
//     int val;
//     cin>> val;
    
//     Node* head = new Node(val);
//     Node* tail = head;
    
//     for(int i=0; i<size-1; i++)
//     {
//         cin>> val;
//         tail->next = new Node(val);
//         tail = tail->next;
//     }
    
//     return head;
// }

// void printList(Node* n)
// {
//     while(n)
//     {
//         cout<< n->data << " ";
//         n = n->next;
//     }
//     cout<< endl;
// }


//  // } Driver Code Ends
// /* node for linked list:

// struct Node {
//     int data;
//     struct Node* next;
//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };

// */
// int getLength(struct Node *head)
// {
//   int length = 0;
//     while(head!=NULL)
//     {
//         length++;
//         head = head->next;
//     }
    
//     return length;
// }

// void reverse(struct Node** head)
// {
//     struct Node* curr = *head , *nxt = NULL;
    
//     while(curr->next!=NULL)
//     {
//         nxt = curr->next;
//         curr->next = nxt->next;
//         nxt->next = *head;
//         *head = nxt;
//     }
// }


// class Solution
// {
//     public:
//     //Function to add two numbers represented by linked list.
//     struct Node* addTwoLists(struct Node* first, struct Node* second)
//     {
//         // code here
//         int sum1 = 0, sum2 = 0 , result = 0;
//         int l1 = getLength(first);
//         int l2 = getLength(second);
        
//         while(first!=NULL)
//         {
//             sum1= sum1+ first->data*pow(10,--l1);
//             first = first->next;
//         }
//         while(second!=NULL)
//         {
//             sum2= sum2+ second->data*pow(10,--l2);
//             second = second->next;
//         }
        
//         result = sum1+sum2;
        
//         struct Node* new_head=NULL,*tail=NULL;
        
//         while(result>0)
//         {
            
//             int d = result%10;
            
//             struct Node *temp = new Node(d);
            
//             if(new_head==NULL)
//             {
//                 new_head = tail = temp;
//             }
//             else
//             {
//                 tail->next = temp;
//                 tail = tail->next;
//             }
            
//             result = result/10;
//         }
     
//          reverse(&new_head);
        
//         return new_head;
//     }
// };


// // { Driver Code Starts.

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n, m;
        
//         cin>>n;
//         Node* first = buildList(n);
        
//         cin>>m;
//         Node* second = buildList(m);
//         Solution ob;
//         Node* res = ob.addTwoLists(first,second);
//         printList(res);
//     }
//     return 0;
// }
//   // } Driver Code Ends



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/
struct Node* reverse(struct Node *new_head)
{
struct Node *curr=new_head,*nxt;
    while(curr->next!=NULL)
    {
         nxt = curr->next;
        curr->next = nxt->next;
        nxt->next = new_head;
        new_head = nxt;
    }
    return new_head;
}



struct Node * mergeResult(Node *node1,Node *node2)
{
    // struct Node*head1 , *head2 , *new_head=NULL,*tail;
    
    // head1 = reverse(node1);
    // head2 = reverse(node2);
    
    // while(head1!=NULL && head2!=NULL)
    // {
    //     if(head1->data > head2->data)
    //     {
    //         if(new_head==NULL)
    //         {
    //             new_head = tail = head1;
    //         }
    //         else
    //         {
    //             tail->next = head1;
    //             tail = tail->next;
    //         }
    //         head1 = head1->next;
    //     }
    //     else
    //     {
    //         if(new_head==NULL)
    //         {
    //             new_head = tail = head2;
    //         }
    //         else
    //         {
    //             tail->next = head2;
    //             tail = tail->next;
    //         }
    //         head2 = head2->next;
    //     }
    // }
        
    //     while(head1)
    //     {
    //         tail->next = head1;
    //         tail = tail->next;
    //         head1 = head1->next;
    //     }
    //     while(head2)
    //     {
    //         tail->next = head2;
    //         tail = tail->next;
    //         head2 = head2->next;
    //     }
        
    //     return new_head;
    // }
    struct Node *t1 = node1, *t2 = node2,*head = NULL;
    while(t1!=NULL && t2!=NULL)
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        struct Node *temp = head;
        node->next = NULL;
        if(t1->data<t2->data)
        {
            // node->data = t1->data;
            if(head==NULL)
            {
                head = temp = node;
                
            }
            else
            {
                temp->next = t1;
                temp = t1;
            }
            
            t1 = t1->next;
        }
        else if(t2->data<t1->data)
        {
            // node->data = t2->data;
            if(head==NULL)
            {
                head = temp = node;
                // t1 = t1->next;
            }
            else
            {
                // while(node->next!=NULL)
                temp->next = t2;
                temp = t2;
            }
            t2 = t2->next;
        }
         head = reverse(head);
    }
    return head;
}
    
    
    


    // your code goes here
//     struct Node * new_head= NULL;
//     while(node1!=NULL && node2!=NULL)
//     {
//         if(node1->data>node2->data)
//         {
//             new_head = create(node2->data);
//             node2 = node2->next;
//         }
//         else if(node1->data<node2->data)
//         {
//             new_head = create(node1->data);
//             node1 = node1->next;
//         }
//         //  else if(node1->data==node2->data)
//         // {
//         //     new_head = create(node2->data);
//         //     node2 = node2->next;
//         //     node1 = node1->next;
//         // }
        
//         else
//         {
//             if(node1->data == node2->data){
//             new_head = create(node2->data);
//             node2 = node2->next;}
            
//             new_head = create(node1->data);
//             node1 = node1->next;
//         }
//     }
//     while(node1!=NULL)
//     {
//         new_head = create(node1->data);
//             node1 = node1->next;
//     }
//     while(node2!=NULL)
//     {
//         new_head = create(node2->data);
//             node2 = node2->next;
//     }
    
//     // Reversing......
    
// }