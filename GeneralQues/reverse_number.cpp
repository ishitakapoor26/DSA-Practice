#include <iostream>
using namespace std;


void reverse_digits(int num){
    while(num/10 !=0){
        cout<<(num%10)<<" ";
        num= num/10;
    }
    cout<<num;
    }

int main(){
    int n, count;
    cout<<"Enter any digit\n";
    cin>>n;
    reverse_digits(n);
}