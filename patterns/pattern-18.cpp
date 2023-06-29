#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int st=n,sp=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sp;j++){
            cout<<" ";
        }
        for(int j=1;j<=st;j++){
            if(i>1 && i<=n/2 && j>1 && j<st){
                cout<<" ";
            }else{
            cout<<"*";
            }
        }
       if(i<=n/2){
        sp++;
        st-=2;
       }else{
        sp--;
        st+=2;
       }
       cout<<endl;
    }
    return 0;
}