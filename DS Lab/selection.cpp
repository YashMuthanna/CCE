#include<iostream>
using namespace std;

int main(){
    int n=6;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
            int small = arr[i];
            int pos = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<small){
                pos = j;
            }
            int t=arr[pos];
            arr[pos]=arr[i];
            arr[i]= t;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
