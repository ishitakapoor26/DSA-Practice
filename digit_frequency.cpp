#include <iostream>
using namespace std;

int main(){
int n,d,count=0;
cout<<"Enter the number\n";
cin>>n;
cout<<"Enter the digit\n";
cin>>d;
while(n>0){
    if(n%10==d){
        count+=1;
    }
    n=n/10;
}
cout<<endl<<count;
return 0;
}