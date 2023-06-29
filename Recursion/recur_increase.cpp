#include<iostream>
using namespace std;

void print_increasing(int n){
    if(n==0){
        return;
    }else{
        print_increasing(n-1);
        cout<<n<<endl;
    }
}


int main(){
    print_increasing(5);
    return 0;
}