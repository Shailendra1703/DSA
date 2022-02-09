#include<iostream>
#include<stack>

using namespace std;

void insert_bottom(stack<int> &s , int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
     
     int top = s.top();
     s.pop();
     insert_bottom(s,x);
     s.push(top);
}


void reverse(stack<int> &s)
{
    if(s.empty())
    return;

    int x = s.top();
    s.pop();

    reverse(s);
    insert_bottom(s,x);
}

void show(stack<int> s)
{
    if(s.empty())
    return;

    int x = s.top(); s.pop();
    cout<<x<<" ";
    show(s);
    s.push(x);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    show(s);
    cout<<endl;
    reverse(s);
    show(s);
    cout<<endl;
    return 0;
}