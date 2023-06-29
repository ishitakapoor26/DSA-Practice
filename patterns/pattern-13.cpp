#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, j, multi=1, div=1, power;
    cin>>n;
    for(int i=0;i<n;i++){
        int icj=1;
        for(int j=0;j<=i;j++){
            cout<<icj<<" ";
            int icjp1 = icj * (i-j) / (j+1);
            icj= icjp1;
        }
        cout<<endl;
    }
    return 0;
}
// nCk+1 = (nCk *(n-k))/k+1
// Nice concept try again....