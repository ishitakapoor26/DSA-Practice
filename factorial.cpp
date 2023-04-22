#include<iostream>
using namespace std;

int fac(int n){
    if(n==1 || n==0){
        return 1;
    }else{
        return n*fac(n-1);
    }
}

int main(){
    cout<<fac(7);
    return 0;
}