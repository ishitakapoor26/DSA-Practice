#include <iostream>
#include <math.h>
using namespace std;

int any_base_addition(int n1,int n2,int b){
    int i=0,num=0;
    while(n1>0 && n2>0){
        if((n1%10)+(n2%10)>=b){
        num+= (((n1%10)+(n2%10))-b)*pow(10,i);
        n1=n1/10+1;
        n2=n2/10;
        i++;
        }else{
            num+=(((n1%10)+(n2%10))-b)*pow(10,i);
            n1=n1/10;
            n2=n2/10;
            i++;
        }
    }
    num+= n1*pow(10,i);
    return num;
}

int Product(int n1, int n2, int b){
    int rv=0,p=1;
    while(n2>0){
        int d2 = n2%10;
        n2=n2/10;
        int sprd = getProductWithSingledigit(n1,d2,b);
        rv = any_base_addition(rv,sprd*p,b);
        p=p*10;
    }
    return rv;
}

int getProductWithSingledigit(int n1, int d2, int b){
    int rv=0;
    int c=0,p=1;
    while(n1>0 || c>0){
        int d1 = n1%10;
        n1=n1/10;
        int d = d1*d2 + c;
        c=d/b;
        d=d%b;
        rv = rv+d*p;
        p=p*10;
    }
    return rv;
}

int any_base_subtraction(int n1, int n2, int b){
    int rv=0;
    int c=0;
    int p=1;
    while(n2>0){
        int d1=n1%10;
        n1=n1/10;
        int d2=n2%10;
        n2=n2/10;
        int d=0;
        d2=d2+c;
        if(d2>=d1){
            c=0;
            d=d2-d1;
        }else{
            c=-1;
            d=d2+b-d1;
        }
        rv=rv+d*p;
        p=p*10;
    }
    return rv;
}

int main(){
    int n1,n2,b;
    cin>>n1>>n2>>b;
    cout<<any_base_subtraction(n1,n2,b);
    // cout<<any_base_addition(n1,n2,b);
    return 0;
}
// Try again, subtraction and multiplication