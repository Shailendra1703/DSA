#include <bits/stdc++.h>
using namespace std;

int main()
{

    int w, n;

    multimap<double, int> m;
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

    for (int i = 0; i < n; i++)
    {
        m.insert(pair<double, int>((price[i] / (double)weight[i]), i));
    }

    for (auto i = m.rbegin(); i != m.rend(); i++)
    {

        if (weight[i->second] <= w)
        {
            cout << i->second << " : "
                 << "1" << endl;
            profit += 1 * price[i->second];
            w -= weight[i->second];
        }
        else if (weight[i->second] > w)
        {
            cout << i->second << " : " << (w / double(weight[i->second])) << endl;
            profit += (w / double(weight[i->second])) * price[i->second];
            w -= (w / double(weight[i->second])) * weight[i->second];
        }
    }
    // cout << i->first << " : " << i->second << endl;

    cout << "\n\nProfit is of $ " << profit << endl;

    return 0;
}