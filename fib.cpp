#include <bits/stdc++.h>
using namespace std;
void fib(int n)
{
    int a = 0, b = 1;
    int temp;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
        cout << temp << " ";
    }
}

int main()
{

    int n;
    cout << "Enter number :";
    cin >> n;

    fib(n);
    return 0;
}