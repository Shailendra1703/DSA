#include <bits/stdc++.h>
using namespace std;

// 1. using fuction pointer/
/*
void fun(int x)
{
    while (x-- > 0)
        cout << x << " ";
}

int main()
{
    thread t(fun, 10);
    t.join();

    return 0;
}
*/

// 2. using lambda function

// int main()
// {
//     auto fun = [](int x)
//     {
//         while (x-- > 0)
//             cout << x << " ";
//     };
//     thread t(fun, 10);
//     t.join();

//     return 0;
// }

// 3. using functor fucntion object

// class Base
// {
// public:
//     void operator()(int x)
//     {
//         while (x-- > 0)
//             cout << x << " ";
//     }
// };

// int main()
// {
//     thread t((Base()), 10);
//     t.join();
//     return 0;
// }

// 4. non static member function

// class Base
// {
// public:
//     void fun(int x)
//     {
//         while (x-- > 0)
//             cout << x << " ";
//     }
// };

// int main()
// {
//     Base b;
//     thread t(&Base::fun, &b, 10);
//     t.join();
//     return 0;
// }

// 5 static member function

class Base
{
public:
    static void fun(int x)
    {
        while (x-- > 0)
            cout << x << " ";
    }
};

int main()
{
    thread t(&Base::fun, 10);
    t.join();
    return 0;
}