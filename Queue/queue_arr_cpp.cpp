#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue()
    {
        front = rear = -1;
        size = 5;
        arr = new int[size];
    }

    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = new int[size];
    }

    void enqueue(int);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << endl
             << "List is Full" << endl;
    else
    {
        rear++;
        arr[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "List Is Empty\n";
    else
    {
        front++;
        x = arr[front];
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
        cout << arr[i] << "-->";
    cout << endl;
}

int main()
{
    Queue Q;
    Q.enqueue(34);
    Q.enqueue(24);
    Q.enqueue(30);
    Q.enqueue(3);

    Q.display();

    cout << "Dequeued " << Q.dequeue() << endl;
    cout << "Dequeued " << Q.dequeue() << endl;

    Q.display();
    return 0;
}
