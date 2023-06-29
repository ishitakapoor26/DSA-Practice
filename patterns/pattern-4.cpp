#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int j=0,k=0;
    for(int i=0;i<n;i++){
        while(j<i){
            cout<<" ";
            j++;
        }
        j=0;
        while (k<n-i){
            cout<<"*";
            k++;
        }
        k=0;
        cout<<endl;
    }
    return 0;
}