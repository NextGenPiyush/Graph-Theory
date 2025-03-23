#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> critialConnection(int n, vector<vector<int>> &connections);  // Leetcode-1192
void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &bridge, int &count);

int main(){
    
    // bridge: if I romove edge then graph will be divided into 2 components then the edge will the bridge
    // we have to count the number of bridges in the graph 
    
    return 0;
}   

vector<vector<int>> critialConnection(int n, vector<vector<int>> &connections){ // Leetcode-1192
    vector<vector<int>> adj(n);
    for(int i=0; i<connections.size(); i++){
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }
    vector<vector<int>> bridge;
    vector<int> disc(n);
    vector<int> low(n);
    vector<bool> visited(n,false);
    int count = 0;
    dfs(0,-1,adj,disc,low,visited,bridge,count);
    return bridge;
}

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &bridge, int &count){
    disc[node] = low[node] = count;
    visited[node] = true;
    for(auto neighbour: adj[node]){
        if(neighbour == parent) continue;
        else if(visited[neighbour]) low[node] = min(low[node],low[neighbour]);
        else{
            count++;
            dfs(neighbour,node,adj,disc,low,visited,bridge,count);
            low[node] = min(low[node],low[neighbour]);
            if(low[neighbour]>disc[node]){
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(neighbour);
                bridge.push_back(temp);
            }
        }
    }
}
