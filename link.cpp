#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    void reverse()
    {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void print()
    {
        struct Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{

    // int n;
    // cout << "How many node you want: ";
    // cin >> n;

    LinkedList l;

    l.push(3);
    l.push(4);
    l.push(5);
    l.push(6);

    l.print();
    cout << endl;

    l.reverse();

    l.print();
    return 0;
}