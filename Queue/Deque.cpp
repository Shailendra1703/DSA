#include <iostream>
using namespace std;

#define M 100

class deque
{
    int arr[M], front, rear, size;

public:
    deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isfull();
    bool isEmpty();
    int getfront();
    int getrear();
};

bool deque::isfull()
{
    return ((front == 0 && rear == size - 1) ||
            front == rear + 1);
}

bool deque::isEmpty()
{
    return (front == -1);
}

void deque::insertfront(int key)
{
    if (isfull())
    {
        cout << "overflow";
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = size - 1;

    else
        front = front - 1;

    arr[front] = key;
}
void deque::insertrear(int key)
{
    if (isfull())
    {
        cout << "Overflow";
        return;
    }
    if (front == -1)
    {
        rear = front = 0;
    }

    else if (rear == size - 1)
        rear = 0;
    else
        rear = rear + 1;

    arr[rear] = key;
}

void deque::deletefront()
{
    if (isEmpty())
    {
        cout << "Underflow";
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void deque::deleterear()
{
    if(isEmpty())
    {
        cout << "Underflow";
        return;
    }
    if(front==rear)
    {
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    rear = size-1;
    else
    rear = rear-1;

}
int deque::getfront()
{
    if(isEmpty())
    {
        cout<<"Underforw"<<endl;
        return -1;
    }
    return arr[front];
}
int deque::getrear()
{
    if(isEmpty() || rear < 0)
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[rear];
}



int main()
{
    deque dq(5);
    dq.insertrear(30);
    dq.insertrear(20);
    dq.insertrear(10);

    dq.insertfront(5);

    cout<<dq.getrear()<<endl;
    cout<<dq.getfront()<<endl;
    return 0;

}