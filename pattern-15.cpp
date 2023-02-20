#include <iostream>
using namespace std;

int main(){
    int n,l,m=1;
    cin>>n;
    int sp=n/2, st=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sp;j++){
            cout<<" ";
        }
        l=m;
        for(int k=1;k<=st;k++){
            cout<<l;
            if(k<=st/2){
                l++;
            }else{
                l--;
            }
        }
        if(i<=n/2){
            sp--;
            st+=2;
            m++;
        }else{
            sp++;
            st-=2;
            m--;
        }
        cout<<endl;
    }
    return 0;
}
// Nice question