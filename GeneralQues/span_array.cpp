#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;
    int *arr= new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<endl<<arr[n-1]-arr[0];
    return 0;
}