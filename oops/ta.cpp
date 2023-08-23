// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, digit;
//     cout << "Enter the no. : ";
//     cin >> n;
//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> digit;
//         arr.push_back(digit);
//     }

//     vector<int> neg;
//     vector<int> pos;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= 0)
//             pos.push_back(arr[i]);

//         else
//             neg.push_back(arr[i]);
//     }

//     for (auto i : pos)
//         cout << i << " ";
//     cout << endl;
//     for (auto i : neg)
//         cout << i << " ";
//     cout << endl;

//     int k = 0;
//     int i = 0, j = 0, flag = 0;
//     while (i < pos.size() && j < neg.size())
//     {
//         if (flag = 0)
//         {
//             arr[k++] = pos[i++];
//             flag = 1;
//         }
//         else
//         {
//             arr[k++] = neg[j++];
//             flag = 0;
//         }
//     }

//     while (i < pos.size())
//         arr[k++] = pos[i++];

//     while (j < neg.size())
//         arr[k++] = neg[j++];

//     for (auto i : arr)
//         cout << i << " ";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void alternateOrder(int arr[], int n)
{
    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int i = 0, j = 0, k = 0;
    int p = pos.size();
    int q = neg.size();

    vector<int> res;

    bool flag = true;
    while (i < p && j < q)
    {
        flag ? res.push_back(pos[i++]) : res.push_back(neg[j++]);

        flag = !flag;
    }

    while (i < p)
        res.push_back(pos[i++]);

    while (j < q)
        res.push_back(neg[j++]);

    cout << "======ORIGINAL ARRAY======" << endl;
    for (int it = 0; it < n; it++)
        cout << arr[it] << " ";
    cout << endl
         << endl;

    cout << "======ALTERNATE ARRAY======" << endl;
    for (auto m : res)
        cout << m << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter no. of elements in your array : ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    alternateOrder(arr, n);

    return 0;
}

// output

// Enter no. of elements in your array : 8
// -3 1 2 4 -6 8 -8 -1
// ======ORIGINAL ARRAY======
// -3 1 2 4 -6 8 -8 -1

// ======ALTERNATE ARRAY======
// 1 -3 2 -6 4 -8 8 -1

/*

This is a program that takes as input an array of numbers – positive and negative.
This code is an implementation of a solution to print an array such that it
arranged in an alternate order  every positive number is followed by a negative number throughout.

Complexity:

Time Complexity: This approach takes O(n) time complexity in worst case.
Space Complexity: This approach takes O(n) auxilary space ,
 as we created 2 arrays positives and negatives with positive.length + negative.length = size of array. 
*/
