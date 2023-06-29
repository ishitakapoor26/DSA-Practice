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

void print_digits(int count, int num){
    int power;
    while(count !=0){
        power= pow(10,count-1);
        cout<< (num/power)<<" ";
        num= num%power;
        count-=1;
    }
}

int main(){
    int n, count;
    cout<<"Enter any digit\n";
    cin>>n;
    count= count_digit(n);
    print_digits(count, n);
    cout<<"\nNumber of digits in given number are: "<<count;
}