#include <iostream>
using namespace std;
const int SIZE=5;

class CQueue{
    private:
    int front;
    int rear;
    int arr[SIZE];
    public:
    CQueue(){
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        return (front==-1 && rear==-1);
    }

    bool isFull(){
        return (rear+1)%SIZE==front;
    }

    void enq(int elem){
        if(isFull()){
            cout<<"Queue Full"<<endl;
            return;
        }  
        if(isEmpty())
            front++;
        rear=(rear+1)%SIZE;
        arr[rear]=elem;
    }

    int deq(){
        if(isEmpty()){
            cout<<"Empty queue"<<endl;
            return -1;
        }
        int elem=arr[front];
        if (front==rear)
            front=rear=-1;
        else
            front=(front+1)%SIZE;
        return elem;
        
    }

    void display(){
        int i;
        for (i=front;i!=rear;i=(i+1)%SIZE){
            cout<<arr[i]<<' ';
        }
        cout<<arr[i]<<endl;
    }
};

int main(){
    CQueue cq;
    cq.enq(1);
    cq.enq(5);
    cq.enq(6);
    cq.enq(9);
    cq.display();
        
    return 0;

}