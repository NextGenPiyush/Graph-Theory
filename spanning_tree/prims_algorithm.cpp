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
int prism(int src, int n);

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
    
    // to calculate minimum spanning tree graph must be connected otherwise we can't find MST as there will be no edge between two different components 

    return 0;
}

int Minimum_spanning_tree(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    isMST.resize(v,false);
    parent.resize(v,-1);  // we are maintaining parent so that we can get the tree in the end 
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

int prism(int src, int n){   // implementation by sanket sir 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    unordered_set<int> vis;
    vector<int> par(n);
    unordered_map<int,int> mp;
    for(int i=1; i<=n; i++) mp[i] = INT_MAX;   // make sure to check whether it is 0 based or 1 based indexing
    mp[src] = 0;
    pq.push({0,src});
    int total_count = 0;
    int result = 0;
    while(total_count < n && !pq.empty()){
        auto curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();
        for(auto neighbour : graph[curr.second]){
            if(!vis.count(neighbour.first) and mp[neighbour.first]>neighbour.second){
                pq.push({neighbour.first,neighbour.second});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }   
    return result;
}

