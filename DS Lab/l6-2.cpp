#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#define MAX 10
using namespace std;

class stack{
private:
    int top;
    int a[MAX];
public:
    stack(){top=-1;}

    bool isempty(){
        if(top==-1)
            return true;
        else
            return false;
    }

    void push(char x){
        if(top!=MAX-1)
            a[++top]=x;
        else
            cout<<"Stack Overflow."<<endl;
    }

    char pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else
            return a[top--];
    }

    int peek(){
        if(!isempty())
            return a[top];
        else
            cout<<"Stack Underflow."<<endl;
    }
};

int precedence(char c){
    int p;
    if(c=='+'||c=='-')
        p=1;
    else if(c=='*'||c=='/')
        p=2;
    else if(c=='^')
        p=3;
    return p;
}

int calculate(int x, int y, char op){
    if(op=='+')
        return x+y;
    else if(op=='-')
        return y-x;
    else if(op=='*')
        return x*y;
    else if(op=='/')
        return y/x;
    else if(op=='^')
        return pow(y,x);
}

void Prefix(){
    stack s;

    char prefix[30];
    char var;
    int i, val, x, y;

    cout<<"Enter Prefix Expression: "<<endl;
    cin.get(prefix,30);
    int l = strlen(prefix);
    reverse(prefix,prefix+l);

    for(i=0; i<l; i++){
        if(prefix[i]>=48 && prefix[i]<=57){
            s.push(prefix[i]-48);
        }
        else if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='/'||prefix[i]=='*'||prefix[i]=='^'){
            y = s.pop();
            x = s.pop();
            s.push(calculate(x,y,prefix[i]));
            //cout<<endl<<x<<" "<<prefix[i]<<" "<<y<<" "<<operate(x,y,prefix[i]);
        }
    }
    cout<<endl<<"Evaluated Prefix : "<<s.peek();
    s.pop();
}

int main(){
    Prefix();
}
