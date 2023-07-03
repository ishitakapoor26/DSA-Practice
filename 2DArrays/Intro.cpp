#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter number of rows: "<<endl;
    cin>>m;
    cout<<"Enter number of columuns: "<<endl;
    cin>>n;
    int** arr= new int*[m];
    for(int i=0;i<m;i++){
        arr[i]= new int[n];
    }
    // taking input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // output the matrix
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}