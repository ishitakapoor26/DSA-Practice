#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    void dfsHelper(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node]=1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfsHelper(it, adj,vis, ls);
            }
        }
    }

public:
    vector<int> dfs(int v, vector<int> adj[])
    {
        int* vis= new int[v];
        int start =0;
        vector<int> ls;
        dfsHelper(start, adj, vis, ls);
        return ls;
    }
};

int main()
{
    return 0;
}