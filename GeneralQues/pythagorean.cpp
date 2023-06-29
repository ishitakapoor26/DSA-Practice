#include <iostream>
#include <math.h>
using namespace std;

bool triplets(int a, int b, int c){
if(a>b && a>c){
    return pow(b,2)+pow(c,2)==pow(a,2);
}

if(b>a && b>c){
    return pow(a,2)+pow(c,2)==pow(b,2);
}

if(c>b && c>a){
    return pow(b,2)+pow(a,2)==pow(c,2);
}
return false;
}

int main(){
    int a,b,c;
    cout<<"Enter the length of the slide of a right angled triangle:\n";
    cin>>a>>b>>c;
    string result= triplets(a,b,c)?"Pythagorean Triplet!":"Not a pythagorean triplet";
    cout<<result;
    return 0;
}