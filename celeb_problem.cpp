#include<iostream>
using namespace std;

class Stack{
    private:
    int top;
    int *row{new int[5]};
    int *col{new int[5]};
    public:

    Stack(){
        top=-1;
    }

    

    void push(int i){
        if(isFull()){
            return;
        }else{
            top++;
            
        }
    }

    int celebrity_problem(int arr[5][5]){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){

            }
        }
    }
};

int main(){
    int arr[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;i<5;i++){
            cin>>arr[i][j];
        }
    }
    Stack st;
    st.celebrity_problem(arr);
    return 0;
}