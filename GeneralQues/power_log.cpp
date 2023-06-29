#include<iostream>
using namespace std;

int power_log(int x, int n){
    if(n==0){
        return 1;
    }else{
        if(n%2==0){
            int xn= power_log(x,n/2);
            return xn*xn;
        }else{
            return x*power_log(x,n-1);
        }
    }
}

int main(){
    int x,n;
    cout<<"Enter the value of x and n"<<endl;
    cin>>x>>n;
    cout<<power_log(x,n);
    return 0;
}