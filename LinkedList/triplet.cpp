// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    struct Node* t = head,*t2,*t1;
    int count = 0;
    int sum = 0;
    while(t!=NULL)
    {
        t1 = t->next;
        while(t1!=NULL)
        {
            t2 = t1->next;
            while(t2!=NULL)
            {
                sum = t->data + t1->data + t2->data;
                if(sum==x){
                count++;
                }
                t2 = t2->next;
                sum = 0;
            }
            t1 = t1->next;
        }
        t = t->next;
    }
    return count;
} 