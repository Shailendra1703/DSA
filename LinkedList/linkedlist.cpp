#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

Node *reverse(Node *head)
{
    Node *curr = head, *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    return head;
}

int main()
{
    Node *head = NULL;
    Node *tail;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        if (head == NULL)
        {
            Node *temp = new Node(p);
            head = tail = temp;
        }
        else
        {
            Node *temp = new Node(p);
            tail->next = temp;
            tail = tail->next;
        }
    }
    print(head);
    cout << "after revers" << endl;
    print(reverse(head));
    return 0;
}