#include <iostream>
using namespace std;

int main(){
    int n,sp=n/2,st=1;
    cout<<"Enter the value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<sp;j++){
            cout<<" ";
        }
        for(int k=1;k<=st;k++){
            cout<<"*";
        }
        if(i<=n/2){
            sp--;
            st+=2;
        }
        else{
            sp++;
            st-=2;
        }
        cout<<endl;
    }
    return 0;
}