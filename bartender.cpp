#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(vector<int> q1, vector<int> q2, int x, int y)
{
    int temp;
    temp = q1[x];
    q1[x] = q2[y];
    q2[y] = temp;
    sort(q1.begin(), q1.end());
    sort(q2.begin(), q2.end());
    return q1 == q2;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    bool ans = false;
    int test, n, m, x, y,z;
    vector<int> q1(n,0);
    vector<int> q2(n,0);
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> n >> m;
        cout <<"n is "<< n;
        cout << endl
             << m << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << endl;
            cin>>z;
            q1.push_back(z);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> q2[i];
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     cin >> x >> y;
        //     if (compare(q1, q2, x, y))
        //     {
        //         ans = true;
        //     }
        // }
        // if (ans)
        // {
        //     cout << "YES" << endl;
        // }
    }
    return 0;
}