#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct edge{
    int src, dest, weight;
};
bool cmp(edge e1, edge e2){
    return e1.weight < e2.weight;
}
ll kruskal(vector<edge> &input, int n, int e);

int spanningTree(int v, vector<vector<int>> adj[]);  
int findParent(int u, vector<int> &parent);
void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank);

int main(){
    
    // Krukal algorithm is implemented using Disjoint set union data structure 
    
    int n,e;
    cin>>n>>e;
    vector<edge> v(e);
    for(int i=0; i<e; i++) cin>>v[i].src>>v[i].dest>>v[i].weight;
    cout<<kruskal(v,n,e)<<endl; 
    
    return 0;
}

int spanningTree(int v, vector<vector<int>> adj[]){
    vector<int> parent(v);
    vector<int> rank(v,0);
    for(int i=0; i<v; i++) parent[i] = i;
    vector<pair<int,pair<int,int>>> temp;
    for(int i=0; i<v; i++) for(int j=0; j<adj[i].size(); j++) temp.push_back({adj[i][j][1],{i,adj[i][j][0]}});
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());
    int cost = 0;
    int edges = 0;
    while(!pq.empty()){
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        if(findParent(v,parent) != findParent(u,parent)){
            cost += wt;
            UnionByRank(u,v,parent,rank);
            edges++;
        }
        if(edges == v-1) break;
    }
    return cost;
}

int findParent(int u, vector<int> &parent){
    if(u == parent[u]) return u;
    return parent[u] = findParent(parent[u],parent);  // path compression
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(u,parent);
    v = findParent(v,parent);
    if(rank[u] >= rank[v]){
        parent[v] = u;
        rank[u]++;
    }
    else{
        parent[u] = v;
        rank[v]++;
    } 
}

ll kruskal(vector<edge> &input, int n, int e){  // another implementation of Kruskal Algorithm
    sort(input.begin(),input.end(),cmp);
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    for(int i=0; i<=n; i++) parent[i] = i;
    int edgeCount = 0;
    int i=0;
    ll ans;
    while(edgeCount < n-1 and i < input.size()){
        edge curr = input[i];
        int srcPar = findParent(curr.src,parent);
        int destPar = findParent(curr.dest,parent);
        if(srcPar != destPar){
            UnionByRank(srcPar,destPar,parent,rank);
            ans += curr.weight;
            edgeCount++;
        }
        i++;  // does'nt matter you picked the last edge or not, we still need to go to next edge
    }
    return ans;
}