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

// Above approach takes time of O(n^2)
// Below approach takes O(n)

//    int celebrity(vector<vector<int> >& M, int n) 
//     {
//        int Cel = -1;
//         stack<int> stack;
        
//         for(int x = 0;x<n;x++){
//             stack.push(x);
//         }
        
//         while(stack.size()>1){
            
//             int A = stack.top();
//             stack.pop();
//             int B = stack.top();
//             stack.pop();
            
//             if(M[A][B] == 1){
//             stack.push(B);
//             }
//             else{
//                 stack.push(A);
//             }
//         }
        
//         Cel = stack.top();
        
//         int count0 = 0; 
//         for(int y = 0;y<n;y++){
//             if(M[Cel][y] == 0){
//                 count0++;
//             }
            
//         }
//         int count1 = 0;
//         for(int y = 0;y<n;y++){
//             if(M[y][Cel] == 1){
//                 count1++;
//             }
//         }
        
//         if(count0==n&&count1==n-1){
//             return Cel;
//         }
//         return -1;
        
//     }