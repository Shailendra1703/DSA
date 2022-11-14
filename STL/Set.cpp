#include <bits/stdc++.h>
using namespace std;

void print(int x)
{
    cout << x << " ";
}

int main()
{

    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(23);

    // find method returns the pointer to the element which is to be searched else it will return iterator or pointer to the end of the set
    // lower bound method return the iterator to the element if it is found else it willl return the address to the next greater the that element or
    //  if the element is greater then the greatest number than it will return iterator to the end;

    //upper bound returns the pointer to the next greater element rest are same as 

    // auto it = s.find(31);
    auto it = s.lower_bound(55);
    if (it == s.end())
        cout << "Not Found" << endl;
    else
        cout << *it << "Found" << endl;

    // first method
    // for (auto x : s)
    //     cout << x << endl;

    // second method
    // for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // third method

    for_each(s.begin(), s.end(), print);
}