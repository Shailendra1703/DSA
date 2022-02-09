#include<iostream>
#define MAX 10
using namespace std;
 class Stack{
     int stk[MAX];
     int top;
    public:
    Stack(){
        top=-1;
    }

    bool push(int t){
        if(top>=MAX-1){
        cout<<"Stack Overflow"<<endl;
        return false;
        }
        else
        {
            stk[++top]=t;
            return true;
        }
    }
    int pop(){
        if(top<0)
        {
            cout<<"Stack Underflow"<<endl;
            return false;
        }
        else
        {
            int l= stk[top];
            top--;
           // cout<<l<<" "<<endl;
            return l;
        }
    }
  bool isEmpty(){
      return (top<0);
  }
  bool peek(){
      return stk[top];
  }
 };
 int main(){
     Stack st;
     st.push(1);
     st.push(2);
     st.push(3);
     st.push(4);
     st.push(5);
     st.push(6);
     while(!st.isEmpty()){
         cout<<st.pop()<<" ";
     }
     if(st.isEmpty())
     cout<<"Stack is Empty";
     return 0;
 }