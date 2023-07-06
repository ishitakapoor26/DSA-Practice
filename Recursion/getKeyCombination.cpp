#include <iostream>
#include <vector>
using namespace std;

string codes[10] = {"?!", "abc", "def", "ghi", "jkl", "mnop", "qrst", "uv", "wxyz", ".;"};

vector<string> getKPC(string str)
{
    if (str.length() == 0)
    {
        vector<string> res;
        res.push_back("");
        return res; 
    }
    char ch = str[0];
    string ros = str.substr(1);
    vector<string> rres = getKPC(ros);
    vector<string> mres;
    string coderforch = codes[ch - '0'];
    for (int i = 0; i < coderforch.length(); i++)
    {
        char chcode = coderforch[i];
        for (string rstr : rres)
        {
            mres.push_back(chcode + rstr);
        }
    }
    return mres;
}

int main()
{
    string str;
    cin >> str;
    vector<string> words = getKPC(str);
    for(string i : words){
        cout<<i<<endl;
    }
}
