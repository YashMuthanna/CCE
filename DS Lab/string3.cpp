#include <iostream>
using namespace std;
int main(){
    char a[50],b[50];
    int i;
    cout<<"Enter String 1:";
    cin>>a;
    cout<<"Enter String 2:";
    cin>>b;
    for (i=0;a[i]==b[i]&& a[i]!='\0';i++);
    if(a[i]<b[i]){
        cout<<"String 2 greater";
    }
    else if (a[i]>b[i]){
        cout<<"String 1 greater";
    }
    else{
        cout<<"Equal strings";
    }

}
