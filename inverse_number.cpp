#include <iostream>
#include <math.h>
using namespace std;

int count_digits(int n){
    int count=0,i=0;
    while((n/(pow(10,i)))>1){
        count+=1;
        i+=1;
    }
    return count;
}

void inverse(int n, int count){
    int sum =0, x, power;
    while(count!=0){
        power=pow(10,count-1);
        x= n/power;
        sum+= pow(10,x-1)*count;
        n= n%power;
        count-=1;
    }
    cout<<"Inverse is: "<<sum;
}

int main(){
 int n, count;
 cout<<"Enter the digit\n";
 cin>>n;
count= count_digits(n);
cout<<count;
inverse(n, count);
}