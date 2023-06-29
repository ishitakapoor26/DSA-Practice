#include <iostream>
#include <math.h>
using namespace std;

int count_digit(int n){
    int count=0;
    int i=0;
    while(n/(pow(10,i))>1){
        count+=1;
        i+=1;
    }
    return count;
}

void rotate(int n, int count, int k){
    int newd,x,y;
    if(k<0){
        k=k+count;
    }
    k=k%count;
    y=pow(10,k);
    x= n/y;
    newd= n%y;
    newd= newd*pow(10, count-k)+x;
    cout<<newd<<"\n";
}

int main(){
 int count,n,k;
 cout<<"Enter the number to be rotated:\n";
 cin>>n;
 cout<<"Enter the number of positions to be rotated";
 cin>>k;   
 count= count_digit(n);
 rotate(n, count,k);
 return 0;
}