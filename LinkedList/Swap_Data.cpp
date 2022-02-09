#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insert(Node **head)
{
    Node *temp = new Node;
    cout << "Enter Data : ";
    cin >> temp->data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    Node *t;
    t = *head;
    while (t->next != NULL)
        t = t->next;

    t->next = temp;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << "--> " << head->data;
        head = head->next;
    }
    cout << endl
         << endl;
}

void swapNodes(Node **head)
{
    int x, y;
    cout << "Enter Datas to swap \n";
    cin >> x >> y;

    if (x == y)
        return;

    Node *temp, *p1=NULL, *p2=NULL, *s1, *s2;
    s1 = *head;

    while (s1 != NULL && s1->data != x)
    {
        p1 = s1;
        s1 = s1->next;
    }
    
    s2 = *head;

    while (s2 != NULL && s2->data != y)
    {
        p2 = s2;
        s2 = s2->next;
    }
    //for head Node......

    //------------------------------------------------------------------------------------------------------
    if (s1 == NULL || s2 == NULL)
        return;

    if (p1 != NULL)
        p1->next = s2;
    else
        *head = s2;

    if (p2 != NULL)
        p2->next = s1;
    else
        *head = s1;

    temp = s2->next;
    s2->next = s1->next;
    s1->next = temp;
  
  //-----------------------------------------------------------------------------------------------------
    //    for adjacent Nodes.....

    // if (s1->next = s2)
    // {
    //     p1->next = s2;
    //     s1->next = s2->next;
    //     s2->next = s1;
    //     return;
    // }

    // //for between swap
    // Node *save1, *save2;
    // save1 = s1->next;
    // save2 = s2->next;
    // p1->next = s2;
    // s2->next = save1;

    // p2->next = s1;
    // s1->next = save2;
}

int main()
{
    Node *start = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        insert(&start);
    }
    print(start);

    swapNodes(&start);
    print(start);

    return 0;
}
