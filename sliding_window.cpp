#include<iostream>
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

    void sliding_window(int *array, int k){
        int *nge= new int[size];
        push(size-1);
        nge[size-1]=size;
        for(int i=size-2;i>=0;i--){
            while(size>0 && arr[i]>arr[top]){
                pop();
            }
            if(isEmpty()){
                nge[i]= size;
            }else{
                nge[i]=arr[top];
            }
            push(i);
        }
        int j=0;
        for(int i=0;i<=size-k;i++){
            if(j<i){
            j=i;
            }
            while(nge[j]<i+k){
                j=nge[j];
            }
            cout<<arr[j]<<endl;
        }
    }
};

int main(){
    int n,k;
    cin>>n;
    cout<<"Enter number of windows:"<<endl;
    cin>>k;
    Stack st(n);
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    st.sliding_window(arr,k);
    return 0;
}