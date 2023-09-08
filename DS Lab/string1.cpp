#include<iostream>
using namespace std;

int main(){
    char str[10];
    char str1[10];
    cin>>str;
    //Finding length of string
    int len=0;
    for(int i=0;str[i]!='\0';i++)len++;
    cout<<len<<endl;
    return 0;
}
