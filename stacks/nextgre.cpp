#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *arr {new int[size]};
    public:
        Stack(int n){
            int ele;
            size=n;
            top=-1;
            for(int i=0;i<n;i++){
                cin>>ele;
                push(ele);
            }
        }   
        bool isFull(){
            if(top==size-1){
                cout<<"Stack is Full";
                return true;
            }
            return false;
        } 
        bool isEmpty(){
            if(top==-1){
                cout<<"Stack is Empty";
                return true;
            }
            return false;
        } 
        void push(int x){
            if(top==size-1){
                cout<<"Stack Overflow"<<endl;
            }else{    
            top++;
            arr[top]=x;
            }
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
            }else{
            top--;
            }
        }
        void next_gre(){
            int above=arr[top];
            int max=-1;
           while(top>-1){
            
            if(top==size-1){
            cout<<"Next greater for "<<arr[top]<<" is "<<max<<endl;
            }else{
            if(max>arr[top] && arr[top]<above){
                max=above;
            }else if(max<arr[top]){
                max=-1;
                if(above>arr[top]){
                max=above;
            }
            }else if(max>arr[top]){
                
            }
            cout<<"Next greater for "<<arr[top]<<" is "<<max<<endl;
            }
            above=arr[top];
            pop();
           }
        }
};

int main(){
    int n;
    cin>>n;
    Stack st(n);
    st.next_gre();
    return 0;
}

// Alternative Approach:
// Run the loop in reverse order. Push the first element. Pop if the elements present in the stack are smaller than incoming element. Now print the answer at the top. Now push this element and so on..
// -
// a
// +

// (Revisit): Good question