#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> vec, int idx)
{
    if (idx == vec.size() - 1)
        return vec[idx];
    int misa = max(vec, idx + 1);
    if (misa > vec[idx])
    {
        return misa;
    }
    else
    {
        return vec[idx];
    }
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(0);
    max(vec, 0);
    return 0;
}