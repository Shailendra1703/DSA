#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, digit;
    cout << "Enter the no. : ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> digit;
        arr.push_back(digit);
    }

    vector<int> neg;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);

        else
            neg.push_back(arr[i]);
    }
    int k = 0;
    int i = 0, j = 0, flag = 0;
    while (i < pos.size() || j < neg.size())
    {
        if (flag = 0)
        {
            arr[k++] = pos[i++];
            flag = 1;
        }
        else
        {
            arr[k++] = neg[j++];