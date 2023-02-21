#include <iostream>
#include <math.h>
using namespace std;

int any_base_addition(int n1,int n2,int b){
    int i=0,num=0;
    while(n1>0 && n2>0){
        if((n1%10)+(n2%10)>=b){
        num+= (((n1%10)+(n2%10))-b)*pow(10,i);
        n1=n1/10;
        n2=n2/10;
        i++;
        }
    }
    return num;
}

int main(){
    int n1,n2,b;
    cin>>n1>>n2>>b;
    cout<<any_base_addition(n1,n2,b);
    return 0;
}