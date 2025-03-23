#include<bits/stdc++.h>
using namespace std;

vector<list<pair<int,int>>> graph;
int v; // no of vertices
int e; // no of edges

vector<bool> isMST;
vector<int> parent;

void add_edge(int src, int dest, int weight, bool bi_dir = true){
    graph[src].push_back({dest,weight});
    if(bi_dir) graph[dest].push_back({src,weight});
}

int Minimum_spanning_tree();

int main(){
    
    cin>>v;
    cin>>e;
    graph.resize(v,list<pair<int,int>>());
    while(e--){
        int src, dest, weight;
        cin>>src>>dest>>weight;
        add_edge(src,dest,weight);  // by default bi_dir == true;
        // add_edge(src,dest,weight,false); 
    }
    
    // to calculate minimum spanning tree graph must be connected otherwise we can't find MST

    return 0;
}

int Minimum_spanning_tree(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    isMST.resize(v,false);
    parent.resize(v,-1);
    int cost = 0;
    pq.push({0,{0,-1}});  // {weight,{node,parent}}
    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if(!isMST[node]){
            isMST[node] = true;
            cost += weight;
            parent[node] = par;
            for(auto ngh : graph[node]) if(!isMST[ngh.first]) pq.push({ngh.second,{ngh.first,node}});
        }
    }
    return cost;
}

