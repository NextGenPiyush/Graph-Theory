#include<bits/stdc++.h>
using namespace std;

bool check(int n, int m, vector<vector<int>> &edges);
bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int &count, int n);

int main(){
    
    

    return 0;
}

bool check(int n, int m, vector<vector<int>> &edges){
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        adj[edges[i][0]-1].push_back(edges[i][1]-1);
        adj[edges[i][1]-1].push_back(edges[i][0]-1);
    }
    vector<bool> visited(n,false);
    int count = 0;
    for(int i=0; i<n; i++) if(dfs(i,adj,visited,count,n)) return 1;
    return 0; 
}

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int &count, int n){
    visited[node] = 1;
    count++;
    if(count == n) return 1;
    for(auto neighbour : adj[node]) if(!visited[neighbour] && dfs(neighbour,adj,visited,count,n)) return 1;
    visited[node] = 0;
    count--;
    return 0;
}