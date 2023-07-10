#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string str;
    cin>>str;
    unordered_map<char,int> map;
    for(auto i: str){
        if(map.find(i)==map.end()){
            map[i]=1;
        }else{
            map[i]+=1;
        }
    }
    pair<char,int> freq;
    freq.second=0;
    for(pair<char,int> p:map){
        if(freq.second<p.second){
            freq=p;
        }
    }
    cout<<"Highest frequency character is: "<<freq.first<<" with frequency of: "<<freq.second;
    return 0;
}
