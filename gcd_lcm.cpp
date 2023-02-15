#include <iostream>
using namespace std;

int gcd(int n1, int n2){
    int n3=n1,n4=n2;
    while(n3%n4>0){
        n3=n1%n2;
        n4= n2;
        cout<<n3<<"\n";
    }
    cout<<n3<<"\n";
    return n3;
}

int main(){
    int n1,n2;
    cout<<"Enter the numbers:\n";
    cin>>n1>>n2;
    cout<<"\n"<<gcd(n1,n2);
    return 0;
}