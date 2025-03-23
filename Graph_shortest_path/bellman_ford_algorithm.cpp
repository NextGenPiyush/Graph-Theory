#include<bits/stdc++.h>
using namespace std;

int v;

vector<vector<int>> edges; // Here we consider edges not nodes
vector<int> dist;

vector<int> bellman_ford(int src);

int main(){
    
    // apply bellman ford algorithm in directed graph only when negative weight is given

    // we know that it is impossible to find the shortest path in negative weight cycle so bellman ford
    // algorithm also help to detect the negative weight cycle

    // also when there is negative weight in undirected graph, it is not possible to find the shortest path

    return 0;
}

vector<int> bellman_ford(int src){
    dist.resize(v,INT_MAX);
    dist[src] = 0;  // distance to the source node is always zero
    int e = edges.size();
    for(int i=0; i<v-1; i++){  //relax all the edges for v-1 times
        bool flag = false;
        for(int j=0; j<e; j++){  // traverse all the edges
            int u = edges[j][0]; 
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] == INT_MAX) continue;
            if(dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
                flag = true;
            }
        }
        if(!flag) return dist; // resturn distance because there will be no negative cycle for sure 
    }
    for(int j=0; j<e; j++){  // to detect the cycle traverse all the eddges one more time
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if(dist[u] == INT_MAX) continue;
        if(dist[u]+wt < dist[v]) return {-1};
    }
    return dist; // if there is no negative cycle then return the distance vector which stores our ans 
}

