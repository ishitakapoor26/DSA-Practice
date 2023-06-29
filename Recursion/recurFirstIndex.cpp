#include <iostream>
#include <vector>
using namespace std;

int firstIndex(int n, vector<int> vec, int idx)
{
    if (idx == vec.size())
        return -1;
    if (vec[idx] == n)
        return idx;
    else
        return firstIndex(n, vec, idx + 1);
    return -1;
}

int lastIndex(int n, vector<int> vec, int idx)
{
    if (idx == vec.size())
        return -1;
    int lastidx = lastIndex(n, vec, idx + 1);
    if (lastidx == -1)
    {
        if (vec[idx] == n)
            return idx;
        else
            return -1;
    }
    else
    {
        return lastidx;
    }
}

// Approach 1
// void allIndices(int n, vector<int> vec, int idx){
//     if (idx == vec.size())
//         return;
//     allIndices(n, vec, idx+1);
//     if(vec[idx]==n) cout<<idx<<endl;
// }

// Approach 2

vector<int> allIndices(int n, vector<int> vec, int idx, int fsf)
{
    if (idx == vec.size())
    {
        vector<int> v(fsf);
        return v;
    }
    if (vec[idx] == n)
    {
        vector<int> v = allIndices(n, vec, idx + 1, fsf + 1);
        v[fsf] = idx;
        return v;
    }
    else
    {
        vector<int> v = allIndices(n, vec, idx + 1, fsf);
        return v;
    }
}

int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    vec.push_back(1);
    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(8);
    vec.push_back(1);
    cout << firstIndex(n, vec, 0) << endl;
    cout << lastIndex(n, vec, 0) << endl;
    vector<int> v = allIndices(n, vec, 0, 0);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}