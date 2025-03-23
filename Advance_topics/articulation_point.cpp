#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int v;

vector<int> aarticulationPoint(); 
void dfs(int node, int parent, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artpoint, int &timer);

int main(){
    
    
    return 0;
}

vector<int> aarticulationPoint(){  // Tarzan's Algorithm
    vector<bool> artpoint(v,false);
    vector<int> disc(v);
    vector<int> low(v);                 // Time complexity: O(v+e)
    vector<bool> visited(v,false);      // space complexity: O(v)
    int timer = 0;
    dfs(0,-1,visited,disc,low,artpoint,timer);
    vector<int> ans;
    for(int i=0; i<v; i++) if(artpoint[i]) ans.push_back(i);
    if(ans.size() == 0) ans.push_back(-1);
    return ans;
}

void dfs(int node, int parent, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artpoint, int &timer){
    visited[node] = 1;
    disc[node] = low[node] = timer;
    int child = 0;
    for(auto neighbour : graph[node]){
        if(neighbour == parent) continue;
        else if(visited[neighbour]) low[node] = min(low[node],disc[neighbour]);
        else{
            child++;
            timer++;
            dfs(neighbour,node,visited,disc,low,artpoint,timer);
            if(disc[node]<=low[neighbour] && parent!=-1) artpoint[node] = 1;
            low[node] = min(low[node],low[neighbour]);
        }
    }
    if(child>1 && parent==-1) artpoint[node] = 1; // root node
}
