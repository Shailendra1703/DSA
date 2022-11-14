#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, n;

    cout << "Enter capacity of bag : ";
    cin >> w;
    cout << "Enter number of items : ";
    cin >> n;

    int price[n];
    int weight[n];
    double profit = 0;

    cout << "Enter prices of objects\n";
    for (int i = 0; i < n; i++)
        cin >> price[i];

    cout << "Enter weights of objects\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    vector<vector<int>> v(n + 1, vector<int>(w + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (weight[i - 1] <= j)
            {
                v[i][j] = max(price[i - 1] + v[i - 1][j - weight[i - 1]], v[i - 1][j]);
            }
            else
                v[i][j] = v[i - 1][j];
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << "\n\nProfit : " << v[n][w];
    return 0;
}
// int arr[n + 1][w + 1] = {0};
// memset(arr, 0, sizeof(arr));

// for (int i = 1; i <= n; i++)
// {
//     for (int j = 1; j <= w; j++)
//     {
//         if (weight[i] <= w)
//         {
//             if ((price[i] + arr[i - 1][w - j]) > arr[i - 1][j])
//             {
//                 arr[i][j] = price[i] + arr[i - 1][w - j];
//             }
//             else
//             {
//                 arr[i][j] = arr[i - 1][j];
//             }
//         }
//         else
//         {
//             arr[i][j] = arr[i - 1][j];
//         }
//     }
// }
