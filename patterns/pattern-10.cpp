#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sp1=n/2,sp2=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sp1;j++){
            cout<<" ";
        }
        cout<<"*";
        if(i>1 && i<n){
            for(int k=1;k<=sp2;k++){
                cout<<" ";
            }
            sp2= i<=n/2? sp2+2:sp2-2;
        cout<<"*";
        }
    if(i<=n/2){
        sp1--;
    }else{
        sp1++;
    }
    cout<< endl;
    }
}