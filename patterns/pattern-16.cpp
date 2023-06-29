#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sp=2*n-3,st=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=st;j++){
            cout<<j;
        }
        for(int j=1;j<=sp;j++){
            cout<<" ";
        }
        if(sp<= -1 && i>=n-1){
            st--;
        }
        for(int j=st;j>0;j--){
            cout<<j;
        }
        sp-=2;
        st++;
        cout<<endl;
    }
    return 0;
}