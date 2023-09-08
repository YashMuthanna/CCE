#include<iostream>
using namespace std;

int main(){
    int opt;
    cout<<"Select one of the options:\n1. Find length\n2. concatenate\n3. strcmp\n4. insert sub str\n5. delete sub str"<<endl;
    cin>>opt;
    if (opt==1){
        char str1[10];
        cin>>str1;
        int len =0;
        for(int i=0;str1[i]!='\0';i++)len++;
        cout<<len<<endl;
    }
    else if(opt==2){
        char str2[10];
        char str3[10];
        cout<<"Enter two strings to concatenate"<<endl;
        cin>>str2;
        cin>>str3;
        char str4[20];
        int i=0,j=0;
        while(str2[i]!='\0'){
            str4[i]=str2[i];
            i++;
        }
        while(str3[j]!='\0'){
            str4[i]=str3[j];
            i++;
            j++;
        }
        cout<<str4<<endl;
    }
    else if(opt==3){
        char str5[10];
        char str6[10];
        cout<<"enter two strings to compare"<<endl;
        cin>>str5;
        cin>>str6;
        int k=0;
        int flag=0;
        while(str5[k]!='\0' || str6[k]!='\0'){
            if(str5[k]!=str6[k]){
                flag =1;
                break;
            }
            k++;
        }
        if(flag==1){
            cout<<"Not equal"<<endl;
        }
        else cout<<"Equal"<<endl;
    }
    else if(opt==4){

    }
}
