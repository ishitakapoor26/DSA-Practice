#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            pq.push(arr[i]);
        }
        else
        {
            if (pq.top() < arr[i])
            {
                cout<<pq.top()<<" , ";
                pq.pop();
                pq.push(arr[i]);
            }
        }   
    }
    for(int i=0;i<=k;i++){
        cout<<pq.top()<<" , ";
        pq.pop();
    }

    return 0;
}