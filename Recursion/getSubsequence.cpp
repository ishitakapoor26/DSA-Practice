#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s)
{
    if (s == "")
    {
        vector<string> res;
        res.push_back("");
        return res;
    }
    // a
    char ch = s[0];
    // bc
    string ros = s.substr(1);
    vector<string> ans = gss(ros);
    vector<string> myans;
    for (string str : ans)
    {
        myans.push_back(str);
    }
    for (string str : ans)
    {
        myans.push_back(ch + str);
    }
    return myans;
}

int main()
{
    string s;
    cin>>s;
    vector<string> ans= gss(s);
    int count=0;
    cout<<"[";
    for(string str: ans){
        if(count!=ans.size()-1){
            cout<<str<<" , ";
        }else{
            cout<<str;
        }
        count++;
    }
    cout<<"]";
    return 0;
}