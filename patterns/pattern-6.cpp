#include <iostream>
using namespace std;

int main(){
    int n,sp=1;
    cout<<"Enter value of n:";
    cin>>n;
    int  st1= n/2+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=st1;j++){
            cout<<"*";
        }
        for(int k=1;k<=sp;k++){
            cout<<" ";
        }
        for(int l=1;l<=st1;l++){
            cout<<"*";
        }
        if(i<=n/2){
            sp+=2;
            st1--;
        }else{
            sp-=2;
            st1++;
        }
        cout<<endl;
    }
    return 0;
}