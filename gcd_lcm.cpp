#include <iostream>
using namespace std;

int gcd(int n1, int n2){
    int n3;
    while(n1%n2>0){
        n3=n1%n2;
        n1= n2;
        n2=n3;
        // cout<<n2<<"\n";
    }
    // cout<<n2<<"\n";
    return n2;
}

int lcm(int n1, int n2, int gcd){
    return (n1*n2)/gcd;
}

int main(){
    int n1,n2;
    cout<<"Enter the numbers:\n";
    cin>>n1>>n2;
    int gc;
    gc= gcd(n1,n2);
    cout<<gc;
    cout<<"\nLCM is: "<<lcm(n1,n2,gc);
    return 0;
}