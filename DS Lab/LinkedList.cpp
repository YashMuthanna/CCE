#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class LL{
    private:
    node *head;
    public:

    LL(){
        head=NULL;
    }

    void append(int elem){
        node *temp= new node;
        temp->data=elem;
        temp->next=head;
        head=temp;
    }

    void insert_after(int elem, int value){
        // elem= element to insert
        // value= element after which insertion is to be done
        // NO EDGE CASES EXIST.*
        node *temp=new node;
        temp->data=elem;
        node *trav=head;
        bool found=false;
        while(trav!=NULL){
            if(trav->data==value){
                temp->next=trav->next;
                trav->next=temp;
                found=true;
                break;
            }
            trav=trav->next;
        }
        if(!found){
            cout<<"Element not found!"<<endl;
        }
    }
/*insert_before() and remove() are implemented using look ahead technique,
and hence edges cases are always at head because it has no element which can look ahead to head*/
    void insert_before(int elem, int value){
        node *temp= new node;
        temp->data=elem;
        node *trav=head;
        bool found=false;
        //EDGE CASE:Element is at head
        if(trav->data==value){
            head=temp;
            temp->next=trav;
            return;
        }
        while(trav->next!=NULL){
            if(trav->next->data==value){
                temp->next=trav->next;
                trav->next=temp;
                found=true;
                break;
            }
            trav=trav->next;
        }
        if(!found){
            cout<<"Element not found"<<endl;
        }
    }

    void remove(int elem){
        node *trav=head;
        bool found=false;

        // EDGE CASE:ELement at head
        if(trav->data==elem){
            head=trav->next;
            return;
        }

        while(trav->next!=NULL){
            if(trav->next->data==elem){
                trav->next=trav->next->next;
                found=true;
                break;
            }
            trav=trav->next;
        }
        // Element at Tail
        if(trav->next==NULL){
            delete trav->next;
            trav->next=NULL;
            found=true;
        }
            
        if(!found){
            cout<<"Element not found in the list"<<endl;
        }
    }

    void traverse(){
        node *trav= new node;
        trav=head;
        while(trav!=NULL){
            cout<<trav->data<<' ';
            trav=trav->next;
        }
        cout<<endl;
    }

    void reverse(){
        node *prev=NULL, *next=NULL, *curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    } 

    void sort(bool rev=false){
        // By selection sort
        node *t=head, *t2, *min;
        int temp;
        while(t){
            min=t;
            t2=t->next;
            while(t2){
                if(t2->data<min->data)
                    min=t2;
                t2=t2->next;
            }
            if(min!=t)
                swap(min->data,t->data);
            t=t->next;
        }
    if(rev)
        reverse();
    }

    void delete_alternate(){
        node *temp=head;
        node *temp2=temp->next;
        while(temp && temp2){
            temp->next=temp2->next;
            delete temp2;
            temp=temp->next;
            if(temp)
                temp2=temp->next;
        }
        
    }

    void insert_sort(int elem){
        node *temp=new node;
        node *trav=head;
        temp->data=elem;
        //EDGE CASE:List Empty
        if(head==NULL){
            append(elem);
            return;
        }

        // Insertion by look ahead technique

        // EDGE CASE:Element at head
        if(trav->data>elem){
            temp->next=head;
            head=temp;
            return;
        }
        while(trav->next!=NULL){
            if(trav->next->data>elem){
                temp->next=trav->next;
                trav->next=temp;
                break;
            }
            trav=trav->next;
        }
        // EDGE CASE: Element at tail
        if(trav->next==NULL){
            trav->next=temp;
            temp->next=NULL;
        }
    }
};
int main(){
    LL L;
    int choice;
    int loc,elem;
    L.append(1);
    L.append(3);
    L.append(6);
    L.append(9);
    cout<<"pick an operation:"<<endl;
    cout<<"1.insert before"<<endl;
    cout<<"2.insert after"<<endl;
    cout<<"3.delete"<<endl;
    cout<<"4.traverse"<<endl;
    cout<<"5.reverse"<<endl;
    cout<<"6.sort"<<endl;
    cout<<"7.delete alternate elements"<<endl;
    cout<<"8.insert in an order"<<endl;
    cout<<"9.exit"<<endl;
    while(true){
        cout<<">";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to insert before:";
                cin>>loc;
                cout<<"Enter the element to insert:";
                cin>>elem;
                L.insert_before(elem, loc);
                break;
            case 2:
                cout<<"Enter the element to insert after:";
                cin>>loc;
                cout<<"Enter the element to insert:";
                cin>>elem;
                L.insert_after(elem, loc);
                break;
            case 3:
                cout<<"Enter the element to delete:";
                cin>>elem;
                L.remove(elem);
                break;
            case 4:
                L.traverse();
                break;
            case 5:
                L.reverse();
                break;
            case 6:
                cout<<"0 for Ascending\n1 for Descending";
                cin>>elem;
                L.sort(elem);
                break;
            case 7:
                L.delete_alternate();
                break;
            case 8:
                cout<<"Enter the element to insert:";
                cin>>elem;
                L.insert_sort(elem);
                break;
            case 9:
                return 0;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }
}