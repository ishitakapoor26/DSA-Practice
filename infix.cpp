#include <iostream>
using namespace std;

class Stack{
    private:
     int top;
        int size;
        int *arr{new int[size]};
    public:

    Stack(int n){
        top=-1;
        size=n;
    }

    bool isEmpty(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return true;
        }
        return false;
    }    

    bool isFull(){
        if(top==size-1){
            cout<<"Stack is full"<<endl;
            return true;
        }
        return false;
    }

    void push(int x){
        if(isFull()){
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        top--;
    }

    int infix(int *array){
        
    }
};

int main(){
    return 0;
}