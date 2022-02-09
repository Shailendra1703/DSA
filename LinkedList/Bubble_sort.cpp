#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter Total array Elements:";
    cin>>n;
    int arr[n],temp;
    for(i=0;i<n;i++)
    cin>>arr[i];
    
    // Now using the bubble sort technique
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    cout<<arr[i]<<endl;
    return 0;

}