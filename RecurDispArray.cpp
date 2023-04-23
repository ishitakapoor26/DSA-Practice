#include<iostream>
#include<vector>
using namespace std;

void reverseArrayPrint(int n, vector<int> vec){
    if(n==-1){
        return;
    }
    cout<<vec[n]<<endl;
    reverseArrayPrint(n-1,vec);
}

void displayArray(int index, vector<int> vec){
    if(index==vec.size()) return;
    cout<<vec[index]<<endl;
    displayArray(index+1, vec);
}

int main(){
vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
vec.push_back(4);
vec.push_back(5);
vec.push_back(6);
reverseArrayPrint(vec.size()-1,vec);
displayArray(0, vec);
}