#include <iostream>
#include <algorithm>
using namespace std;

void bar_chart(int *arr, int n){
    int max= *max_element(arr, arr+n);
    for(int i=max;i>0;i--){
        for(int j=0;j<n;j++){
            if(arr[j]>=i){
                cout<<"*\t";
            }else{
                cout<<"\t";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr= new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bar_chart(arr,n);
    return 0;
}
// nice questions