// #include <bits/stdc++.h>
// using namespace std;

// /* structure for a node */
// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// /* Function to insert a node at the beginning
// of a Circular linked list */
// void push(Node **head_ref, int data)
// {
//     Node *ptr = new Node();

//     ptr->data = data;
//     ptr->next = NULL;

//     if (*head_ref == NULL)
//     {
//         *head_ref = ptr;
//     }
//     else
//     {
//         Node *temp = *head_ref;
//         if (temp->next = *head_ref)
//             temp->next = ptr;
//         else
//         {
//             while (temp->next != *head_ref)
//                 temp = temp->next;

//             ptr = temp;
//         }
//     }
//     ptr->next = *head_ref;
// }

// /* Function to print nodes in
// a given Circular linked list */
// void printList(Node *head)
// {
//     Node *temp = head;
//     if (head != NULL)
//     {
//         do
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         } while (temp != head);
//     }
// }

// /* Driver program to test above functions */
// int main()
// {
//     int val, n;
//     /* Initialize lists as empty */
//     cin >> n;
//     Node *head = NULL;

//     /* Created linked list will be 11->2->56->12 */
//     for (int i = 0; i < n; i++)
//     {
//         cin >> val;
//         push(&head, val);
//     }
//     cout << "Contents of Circular Linked List\n ";
//     printList(head);

//     return 0;
// }
// { Driver Code Starts
// #include <bits/stdc++.h>

// using namespace std;
// /* Link list Node */
// struct Node
// {
//     int data;
//     struct Node *next;
//     Node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };

// struct Node *start = NULL;

// // } Driver Code Ends
// /*
 
//   Node is defined as
//   struct Node {
//     int data;
//     struct Node *next;
//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };

// */
// struct Node *res = NULL, *tail = NULL;

// void create(int val)
// {
//     struct Node *temp = new Node(val);
//     temp->next = NULL;

//     if (res == NULL)
//     {
//         res = tail = temp;
//     }
//     else
//     {
//         tail->next = temp;
//         tail = temp;
//     }
// }
// class Solution
// {
// public:
//     //Function to sort a linked list of 0s, 1s and 2s.
//     Node *segregate(Node *head)
//     {

//         // Add code here
//         long int c0 = 0, c1 = 0, c2 = 0, k = 0;

//         while (head != NULL)
//         {
//             if (head->data == 0)
//                 c0++;
//             else if (head->data == 1)
//                 c1++;
//             else
//                 c2++;

//             head = head->next;
//         }

//         while (k < c0)
//         {
//             create(0);
//             k++;
//         }

//         k = 0;

//         while (k < c1)
//         {
//             create(1);
//             k++;
//         }

//         k = 0;

//         while (k < c2)
//         {
//             create(2);
//             k++;
//         }

//         return res;
//     }
// };

// // { Driver Code Starts.

// // Function to sort a linked list of 0s, 1s and 2s
// void printList(struct Node *Node)
// {
//     while (Node != NULL)
//     {
//         printf("%d ", Node->data);
//         Node = Node->next;
//     }
//     printf("\n");
// }

// /* Drier program to test above function*/
// void insert(int n1)
// {
//     int n, value, i;
//     // scanf("%d",&n);
//     n = n1;
//     struct Node *temp;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &value);

//         if (i == 0)
//         {
//             start = new Node(value);
//             temp = start;
//             continue;
//         }
//         else
//         {
//             temp->next = new Node(value);
//             temp = temp->next;
//             temp->next = NULL;
//         }
//     }
// }

// int main()
// {

//     int n;

//     int t;
//     scanf("%d", &t);

//     while (t--)
//     {
//         scanf("%d", &n);

//         insert(n);
//         Solution ob;
//         struct Node *newHead = ob.segregate(start);
//         printList(newHead);
//     }

//     return 0;
// } // } Driver Code Ends


// { Driver Code Starts
//Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* next;
    
    Node(string x){
        data = x;
        next = NULL;
    }
};

Node *newNode(string str)
{
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

bool compute(struct Node* root);

void print(Node *root)
{
    Node *temp = root;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
                struct Node *temp = head;
		
		for(int i=0;i<K;i++){
		string str="";
		cin>>str;
			if(head==NULL)
			head=temp=new Node(str);
			else
			{
				temp->next = new Node(str);
				temp=temp->next;
			}
		}
		if(compute(head))
			cout<<"True"<<endl;
		else 
			cout<<"False"<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
struct Node* reverse(struct Node * ref)
{
    struct Node * prev = NULL , *nxt = NULL;
    
    while(ref!=NULL)
    {
        nxt = ref->next;
        
        ref->next = prev;
        
        prev = ref;
        ref = nxt;
    }
    return prev;
}
bool compute(Node* root)
{
   //Your code goes here
   struct Node *temp = root ;
   struct Node* rev = reverse(temp);
   
   while(root!=NULL && rev!=NULL)
   {
       if(strcmp(root->data.c_str(),rev->data.c_str()))
       {
       return false;
       }
      
       root = root->next;
       rev = rev->next;
   }
   
   return true;
   
}
