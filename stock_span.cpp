#include<iostream>
using namespace std;

class Stack{
    private: 
        int top;
        int size;
        int *arr{new int [size]};

    public:
        Stack(int n){
            int ele;
            top=-1;
            size=n;
        }    

        bool isFull(){
            if(top==size-1){
                return true;
            }else{
                return false;
            }
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }else{
                return false;
            }
        }

        void push(int n){
            if(isFull()){
                cout<<"Stack Overflow";
                return;
            }else{
                top++;
                arr[top]=n;
            }
        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack Underflow";
                return;
            }else{
                top--;
            }
        }

        void stock_span(int *array){
            for(int i=0;i<size;i++){
                if(i==0){
                    push(i);
                    cout<<"Stock Span for "<<array[i]<<" is "<<i+1<<endl;
                }else{
                    while(!isEmpty() && array[i]>array[arr[top]]){
                            pop();
                    }
                    
                    if(isEmpty()){
                        cout<<"Stock Span for "<<array[i]<<" is "<<i+1<<endl;
                    }else{
                        cout<<"Stock Span for "<<array[i]<<" is "<<i-arr[top]<<endl;
                        
                    }
                    push(i);
                }
            }

        }
};

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Stack st(n);
    st.stock_span(arr);
    return 0;
}