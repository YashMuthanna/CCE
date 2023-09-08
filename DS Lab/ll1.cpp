#include<iostream>
using namespace std;

class node{
    int data;
    node *next;
public:

    void create_list();
    void insert_beg(int elem);
    void insert_pos(int elem, int pos);
    void del_beg();
    void del_pos(int pos);
    void display();
}*head;

void node::create_list(){
    node *cur = head;
    node *temp = new node;
    cout<<"Enter data"<<endl;
    cin>>temp->data;
    temp->next=NULL;
    if(head==NULL){
        head = temp;
    }
    else{
        while(cur->next!=NULL){
            cur->next = temp;
        }
    }
}
void node::insert_beg(int elem){
    node *temp = new node;
    temp->data = elem;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
    }
    else{
        temp->next=head;
        head = temp;

    }
}
void node::del_beg(){
    node *temp = head;
    head=head->next;
    cout<<"Deleted "<<temp->data;
    cout<<endl;
    delete(temp);
}
void node::insert_pos(int elem, int value){
    node *temp= new node;
    temp->data=elem;
    temp->next=NULL;
    node *t = head;
    if(head==NULL){
        head=temp;
    }
    else{
        while(t->data!=value){
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
    }
}
void node::del_pos(int value){
    node *cur=head;
    node *prev;
    while(cur->data!=value && cur!=NULL){
        prev=cur;
        cur=cur->next;
    }

    prev->next=cur->next;
    cout<<"Deleted "<<cur->data;
    cout<<endl;
    delete(cur);
}
void node::display(){
    node *h = head;
    if(h==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(h!=NULL){
        cout<<" -> "<<h->data;
        h=h->next;
    }
    cout<<endl;
}

int main(){
    node list1;
    list1.create_list();
    list1.insert_beg(7);
    list1.insert_beg(6);
    list1.insert_beg(4);
    list1.insert_pos(8,7);
    list1.del_beg();
    list1.display();
    list1.del_pos(8);
    list1.display();
    return 0;
}
