#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sp=n/2,st=1;
    for(int i=1;i<=n;i++){
       
        for(int j=1;j<=sp;j++){
             if(i==(n/2)+1){
            sp=0;
            }else{
            cout<<" ";
        }
        }
        if(sp==0){
            for(int k=1;k<=n/2;k++){
                cout<<"*";
            }
        }
        for(int j=1;j<=st;j++){
            cout<<"*";
        }
        if(i<=n/2){
            st++;
        }
        else{
            sp=n/2;
            st--;
        }
        cout<<endl;
    }
    return 0;
}