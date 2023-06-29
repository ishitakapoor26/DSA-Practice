#include <iostream>
#include <math.h>
using namespace std;

int decimal_to_any_base(int n, int b){
    int i=0,num=0;
    while(n>0){
        num+= (n%b)*pow(10,i);
        n=n/b;
        i++;
    }
    return num;
}

int any_base_to_decimal(int n, int b){
    int i=0,num=0;
    while(n>0){
        num+= (n%10)*pow(b,i);
        n=n/10;
        i++;
    }
    return num;
}

int any_base_to_any_base(int n, int b1, int b2){
    int num=0,i=0,num1;
    num1= any_base_to_decimal(n,b1);
    num= decimal_to_any_base(num1,b2);
    return num;
}

int main(){
    int num,n,b1,b2;
    cin>>n>>b1>>b2;
    // num=decimal_to_any_base(n,b);
    // cout<<num;
    cout<<any_base_to_any_base(n,b1,b2);
    // cout<<any_base_to_decimal(n,b);
    return 0;
}