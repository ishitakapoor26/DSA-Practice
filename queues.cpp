#include<iostream>
using namespace std;

class Queue{
    private:

        int front;
        int rear;
        int size;
        int *arr{new int[size]};
        int *array{new int [size*2]};
    
    public:

    Queue(int n){
        front=rear=-1;
        size=n;
    }

    bool empty(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
            return true;
        }
        return false;
    }

    int count(){
        return rear+1;
    }

    bool isFull(){
        if(rear==size-1){
            cout<<"Queue is Full"<<endl;
            return true;
        }
        else return false;
    }

    void push(int x){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
            for(int i=0;i<size;i++){
                array[i]=arr[i];
            }
            arr=array;
            rear++;
            arr[rear]=x;

        }else{
            if(front==-1){
                front++;
            }
            rear++;
            arr[rear]=x;
            cout<<"Queue pushed "<<x<<endl;
        }
    }

    void pop(){
        if(empty()){
            cout<<"Queue Underflow"<<endl;
        }else{
            cout<<"Queue popped "<<arr[front]<<endl;
            front--;
        }
    }

    void display(){
        for(int i=front;i<=rear;i++){
            cout<< "Element at "<<i<<" index is "<<arr[i]<<endl;
        }
    }
};

int main(){
    int n;
    cin>>n;
    Queue q(n);
    q.push(1);
    q.push(4);
    q.push(8);
    q.push(5);
    q.push(9);
    q.push(10);
    q.pop();
    q.push(111);
    q.push(6);
    q.display();
    return 0;

}