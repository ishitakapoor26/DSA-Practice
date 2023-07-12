#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int v, vector<int> adj[])
{
    int *vis = new int[v];
    vis = {0};
    queue<int> q;
    vis[0] = 1;
    vector<int> bfs;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}