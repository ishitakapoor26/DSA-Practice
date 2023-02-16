#include <iostream>
using namespace std;

void prime_factors(int n){
    for(int i=2; i*i<=n;i++){
        while(n%i==0){
            n=n/i;
            cout<<i<<" ";
        }
    }
    if(n!=1){
        cout<<n;
    }
}

int main(){
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    prime_factors(n);
    return 0;
}