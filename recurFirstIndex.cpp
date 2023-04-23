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
    }else{
        return lastidx;
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
    cout << lastIndex(n, vec, 0);
    return 0;
}