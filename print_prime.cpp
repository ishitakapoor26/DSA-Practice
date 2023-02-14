#include <iostream>
using namespace std;

void check_prime(int low, int high){
    for(int i=low; i<high; i++){
    int count=0;
        for(int j=1;j<=high;j++){
            if(i%j==0){
                count+=1;
            }
        }
        if(count==2){
            cout<<i<<"\n";
        }
    }
}

int main(){
    int low, high;
    cout<<"Enter the range- low and high:\n";
    cin>>low>>high;
    check_prime(low,high);
}