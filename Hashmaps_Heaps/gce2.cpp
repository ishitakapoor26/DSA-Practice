#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int *arr1 = new int[n1];
    int *arr2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    unordered_map<int, int> map1;
    for (int i = 0; i < n1; i++)
    {
        if (map1.find(arr1[i]) == map1.end())
        {
            map1[arr1[i]] = 1;
        }
        else
        {
            map1[arr1[i]] += 1;
        }
    }
    for(int i=0;i<n2;i++){
        if(!(map1.find(arr2[i])==map1.end()) && map1.at(arr2[i])>0){
            map1.at(arr2[i])-=1;
            cout<<arr2[i]<<" , ";
        }
    }
    return 0;
}