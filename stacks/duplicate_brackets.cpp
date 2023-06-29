#include <iostream>
using namespace std;

class Stack{
    private:
        int top;
        int size;
        char *arr{ new char[size]};
    public:
        Stack(int strlen){
            top= -1;
            size= strlen;
        }

        bool isEmpty(){
            if(top==-1){
                cout<<"Expression Stack is empty"<<endl;
                return true;
            }
            return false;
        }

        bool isFull(){
            if(top==size-1){
                cout<<"Expression stack is full"<<endl;
                return true;
            }
            return false;
        }

        void push(char ch){
            if(isFull()){
                cout<<"Stack Overflow";
                return;
            }else{
                top++;
                arr[top]=ch;
        }
        }

        char pop(){
            char ch;
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return ' ';
            }else{
                ch=arr[top];
                top--;
            }
            return ch;
        }

        bool duplicate_brackets(string str){
            for(int i=0;i<size;i++){
                if(str[i]!=')'){
                    push(str[i]);
                }else{
                    while(arr[top]!='('){
                    if(!isEmpty()){
                        pop();
                    }
                    }
                    pop();
                }
            }
            if(isEmpty()){
                return false;
            }else{
                return true;
            }
        }

};

int main(){
    string str;
    cout<<"Enter the expression:"<<endl;
    cin>>str;
    Stack st= Stack(str.length());
    if(st.duplicate_brackets(str)){
        cout<<"Duplicate brackets exist."<<endl;
    }else{
        cout<<"No Duplicate brackets";
    }
    return 0;
}
// Nice question in terms of practice