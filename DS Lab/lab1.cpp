#include<iostream>
using namespace std;

int main(){
    int n=6;
    int flag;
    int arr[6];
    //Enter array of 6 elements
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key; //ask user for key
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            flag=1;
            cout<<"Found at index "<<i<<endl;
            break;
        }
    }
    if(flag!=1){
        cout<<"Not found"<<endl;
    }
    return 0;
}
