#include <bits/stdc++.h>
using namespace std;

// join is used to wait for the completion of the thread
// joinable is used to check weither a thread is joinable or not , double join results in system error
// detach is used to detach the thread from the main thread;

void fun(int x)
{
    while (x-- > 0)
        cout << x << " ";

    this_thread::sleep_for(chrono::seconds(3));
}

int main()
{
    thread t(fun, 10);
    cout << "main" << endl;
    t.join();
    cout << "yes after" << endl;
    return 0;
}