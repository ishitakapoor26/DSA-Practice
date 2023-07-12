#include <iostream>
#include<vector>
using namespace std;
// Undirected graph:
// Adjacency matrix

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int** adj= new int*[n+1];
//     for(int i=0;i<n+1;i++){
//         adj[i]= new int[m+1];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }
//     return 0;
// }

// Adjacency Matrix

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>* adj= new vector<int>[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}