#include <iostream>
using namespace std;

void fibonacci(int n){
    int i=0, j=1, sum=0;
    cout<<i<<" "<<j<<" ";
    for(int k=0;k<n-1;k++){
        sum= i+j;
        i=j;
        j=sum;
        cout<<j<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the range";
    cin>>n;
    fibonacci(n);
}