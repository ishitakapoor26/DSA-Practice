#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=0, j=0,k=0;
    while(i<n){
        while(k<n-i-1){
            cout<<" ";
            k++;
        }
        k=0;
        while(j<=i){
            cout<<"* ";
            j++;
        }
        j=0;
        i++;
        cout<<endl;
    }
    return 0;
}