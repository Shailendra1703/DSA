#include <iostream>
#include <thread>
#include <mutex>

std::mutex mt;
int counter = 0;

using namespace std;

void function()
{
    for (int i = 0; i < 100000; i++)
    {
        if (mt.try_lock()) // tryloc is a non blocking call which tries to lock a  mutex is returns true if yes else false while lock() is a blocking call
        {
            ++counter;
            mt.unlock();
        }
    }
}

int main()
{
    thread t1(function);
    thread t2(function);
    t1.join();
    t2.join();

    cout << counter << endl;
    return 0;
}