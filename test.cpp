// what is you name ?
// tahw si

#include <bits/stdc++.h>
using namespace std;

string rev(string temp)
{

    int n = temp.length();

    string s = "";
    for (int i = n - 1; i >= 0; i--)
        s += temp[i];

    // cout << s << endl;
    return s;
}

int main()
{

    // char s[2000];
    // cin.getline(s, 2000);
    string s;
    getline(cin, s);

    int i = 0;
    int n = s.length();
    cout << n << endl;
    string temp = "";
    while (i < n)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            cout << rev(temp) << " ";
            temp = "";
        }
        i++;
    }
    cout << rev(temp);

    return 0;
}

// ["mango" + "organge" + "fruit"]
// {}[6-9]{10}