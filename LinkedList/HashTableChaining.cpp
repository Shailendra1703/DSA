#include<iostream>
using namespace std;
#define size 10
class Node
{
    public:
      int data;
      Node* next;
};

class HashTable
{
    public:

         Node** h;
         HashTable()
         {
             h = new Node*[size];
             for(int i = 0 ; i < size ; i++)
             {
                 h[i] = NULL;
             }
         }

        int hash(int);
        void Insert(int);
        int search(int);
        ~HashTable();
};

int HashTable::hash(int key)
{
    return key%size;
}

void HashTable::Insert(int key)
{
    int hid = hash(key);
    Node *t = new Node;
    t->data = key;
    t->next = NULL;

    if(h[hid]==NULL)
    {
        h[hid] = t;
    }
    else
    {
        Node*p = h[hid];
        Node*q = h[hid];

        while(p && p->data < key)
        {
            q = p;
            p = p->next;
        }

        if(q == h[hid])
        {
            t->next = h[hid];
            h[hid] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::search(int key)
{
    int hid = hash(key);
    Node*p = h[hid];
    while(p)
    {
        if(p->data == key)
        return p->data;
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable()
{
    for(int i = 0 ; i < size ; i++)
    {
        Node*p = h[i];
        while(h[i])
        {
            h[i] = h[i]->next;
            delete p;
            p = h[i];
        }
    }
    delete[] h;
}

int main()
{
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);

    HashTable h;

    for(int i = 0 ; i < n ; i++)
    {
        h.Insert(A[i]);
    }

    int key = 6;
    int value = h.search(key);
    cout<<key<<"  "<<value<<endl;

    return 0;

}