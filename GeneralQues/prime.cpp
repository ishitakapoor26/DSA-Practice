#include <iostream>
using namespace std;

void prime(int num){
    int count=0;
   for(int i=1;i<=num;i++){
    if(num%i==0){
        count+=1;
    }
   }
   if(count>2){
    cout<<num<<" is not prime\n";
   }
   else{
    cout<<num<<" is prime\n";
   }
}

int main(){
    int n, num;
    cout<<"Enter the number of test cases\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the number to be verified:\n";
        cin>>num;
        prime(num);
    }
}