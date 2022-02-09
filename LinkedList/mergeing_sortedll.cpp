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
// struct Node *head_2=NULL,*tail_2=NULL;
// struct Node*create(int data)
// {
//     // temp->data = data;
//     // temp->next = NULL;
    
//     if(head_2==NULL)
//     {
//         head_2 = tail_2 = newNode(data);
//         return head_2;
//     }
    
//     tail_2->next = newNode(data);
//     tail_2 = tail_2->next;
//     return head_2;
// }


struct Node * mergeResult(Node *node1,Node *node2)
{
    struct Node*head1 , *head2 , *prev;
    
    head1 = reverse(node1);
    print(head1);

    head2 = reverse(node2);
    print(head2);
    
    // if(head1->data>head2->data)
    // {
    //     while(head1->next!=NULL)
    //     {
    //         prev = head1;
    //         head1 = head1->next;
    //     }
    //     prev->next = head2;
    //     return head1;
    // }
    // else if(head1->data<=head2->data)
    // {
    //     while(head2->next!=NULL)
    //     {
    //         prev = head2;
    //         head2 = head2->next;
    //     }
    //     prev->next = head1;
        return head2;
    // }
    
    
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