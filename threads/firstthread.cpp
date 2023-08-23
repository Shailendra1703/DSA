#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
using std::chrono::duration_cast;
using std::chrono::microseconds;

ull odd = 0;
ull even = 0;
void evenSum(ull start, ull end)
{
    for (ull i = start; i < end; i++)
        if ((i & 0) == 0)
            even += i;
}

void oddSum(ull start, ull end)
{
    for (ull i = start; i < end; i++)
        if ((i & 1) == 1)
            odd += i;
}
int main()
{
    typedef std::chrono::high_resolution_clock Clock;

    ull start = 1, end = 1900000000;
    auto startTime = Clock::now();

    thread t1(oddSum, start, end);
    thread t2(evenSum, start, end);

    t1.join();
    t2.join();
    // evenSum(start, end);
    // oddSum(start, end);
    cout << even << endl;
    cout << odd << endl;
    auto endTime = Clock::now();

    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Total Time : " << (duration.count() / 1000000) << "sec";
    return 0;
}