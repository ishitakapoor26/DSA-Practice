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

    return 0;
}