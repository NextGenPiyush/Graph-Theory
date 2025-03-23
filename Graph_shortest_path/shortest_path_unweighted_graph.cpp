#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // adjacency list representation 
int v; // no of vertices
int e; // no of edges

vector<int> dist;
vector<bool> visited;
vector<int> parent;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(auto ele : graph[i]) cout<<ele<<" , ";
        cout<<endl;
    }
}

void bfs(int src);

int main() {
    
    cin>>v;
    graph.resize(v, list<int> ());
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }

    display();

    dist.resize(v,-1);
    visited.resize(v,false);
    parent.resize(v,-1);
    
    int src;
    cout<<"Enter the source node: ";
    cin>>src;
    bfs(src);

    cout<<"Shortest distances from node"<<src<<": ";
    for(int i=0; i<v; i++) cout<<dist[i]<<" ";
    cout<<endl;

    int d;
    cout<<"Enter the destination to get the shortest path between: "<<endl;
    cin>>d;
    vector<int> path;
    while(d != -1){  // i think -1 is from printing shortes path from 0 to destination node 
        path.push_back(d);
        d = parent[d];
    }
    reverse(path.begin(),path.end());
    for(auto ele : path) cout<<ele<<" ";
    cout<<endl;


    return 0;
}

void bfs(int src){  // lgorithm works for directed unweighted along with undirected unweighted graph
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src] = 1;
    while(!q.empty()){ 
        int temp = q.front();
        q.pop();
        for(auto neighbour : graph[temp]) if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour] = 1;
            dist[neighbour] = dist[temp] + 1; 
            parent[neighbour] = temp;  // To print the shortest path we have to maintain parent vector
        }
    }
}



