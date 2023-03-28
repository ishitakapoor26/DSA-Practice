#include<iostream>
using namespace std;

class Stack{
    private:
        int top;
        int *arr{new int[5]};
    public:

    Stack(){
        top=-1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }    
    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
    bool isFull(){
        if(top==4)
            return true;
        else    
            return false;    
    }
    void push(int val){
        if(isFull){
            int *array{new int[(top+1)*2]};
            for(int i=0;i<top+1;i++){
                array[i]=arr[i];
            }
            arr=array;
            top++;
            arr[top]=val;

        }else{
            top++;
            arr[top]=val;
        }
    }
    int pop(){
        if(isEmpty){
            cout<<"Stack Underflow";
            return 0;
        }else{
            int popValue= arr[top];
            arr[top]=0;
            top--;
            return popValue;
        }
    }
    int count(){
        return top+1;
    }
    int peek(int pos){
        if(isEmpty){
            cout<<"Stack Underflow";
            return 0;
        }else{
            return arr[pos];
        }
    }
    void change(int pos, int val){
        arr[pos]=val;
    }
    void display(){
        for(int i=4;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    return 0;
}