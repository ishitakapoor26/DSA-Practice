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
        void largest_area_histogram(int *array){
            // nse index on the right
            int *rb =new int[size];
            push(size-1);
            rb[size-1]=size;
            for(int i=size-2;i>=0;i--){
                while(!isEmpty() && array[i]<arr[top]){
                    pop();
                }
                if(isEmpty()){
                    rb[i]=size;
                }else{
                rb[i]=arr[top];
                }
                push(i);
            }
            // nse index on the left
            int *lb =new int[size];
            push(0);
            rb[0]=-1;
            for(int i=1;i<size;i++){
                while(!isEmpty() && array[i]<arr[top]){
                    pop();
                }
                if(isEmpty()){
                    lb[i]=-1;
                }else{
                lb[i]=arr[top];
                }
                push(i);
            }
            int maxarea=0;
            for(int i=0;i<size;i++){
                int width =rb[i]-lb[i]-1;
                int area = arr[i]*width;
                if(area>maxarea){
                    maxarea=area;
                }
            }
        }

};

int main(){
    int n;
    cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Stack st(n);
    st.largest_area_histogram(arr);
    return 0;
}

// Great question: Practice again: stock span, greatest element to right and this question