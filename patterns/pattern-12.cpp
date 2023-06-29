#include <iostream>
using namespace std;

int main(){
    int n,x=0,y=1,sum;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1){
            cout<<x<<endl;
        }
        else if(i>1){
        for(int j=1;j<=i;j++){
            cout<<y<<" ";
            sum=x+y;
            x=y;
            y=sum;
        }
        cout<<endl;
        }
    }
    return 0;
}