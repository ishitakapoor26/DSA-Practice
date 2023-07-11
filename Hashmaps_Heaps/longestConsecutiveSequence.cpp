#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n1;
    cin >> n1;
    int *arr = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, bool> map;
    for (int i = 0; i < n1; i++)
    {
        if (map.find(arr[i]) == map.end())
        {
            map[arr[i]] = true;
        }
    }
    for (int i = 0; i < n1; i++)
    {
        if (!(map.find(arr[i] - 1) == map.end()))
        {
            map.at(arr[i]) = false;
        }
    }
    int max_val = 0;
    vector<int> max_idx;
    for (pair<int, bool> p : map)
    {
        if (p.second == true)
        {
            vector<int> v;
            int key = p.first;
            v.push_back(key);
            while (!(map.find(++key) == map.end()))
            {
                v.push_back(key);
            }
            if (v.size() > max_val)
            {
                max_val = v.size();
                max_idx = v;
            }
            // else if (v.size() == max_val)
            // {
            // }
        }
    }
    for (int i : max_idx)
    {
        cout << i << " , ";
    }
    return 0;
}