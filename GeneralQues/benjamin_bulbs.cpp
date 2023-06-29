#include <iostream>
using namespace std;

void toggle(int n){
for(int i=1;i*i<=n;i++){
    cout<<i*i<<" ";
}
}

int main(){
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    toggle(n);
    return 0;
}

// Perfect sqaures have 2n+1 number of factors: hence they will remain on.