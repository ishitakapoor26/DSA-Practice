#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        vector<int> knows(n, 0);
        vector<int> known(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] != 0)
                {
                    knows[i]++;
                }
                if (M[j][i] == 1 && j != i)
                {
                    known[i]++;
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (knows[i] == 0 && known[i] == n - 1)
            {
                ans = i;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}