#include<bits/stdc++.h>
using namespace std;

vector<list<pair<int,int>>> graph;
int v; // no of vertices
int e; // no of edges

vector<int> visited;
vector<int> dist;
vector<int> parent;

void add_edge(int src, int dest, int weight, bool bi_dir = true){
    graph[src].push_back({dest,weight});
    if(bi_dir) graph[dest].push_back({src,weight});
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(auto ele : graph[i]) cout<<"{"<<ele.first<<","<<ele.second<<"} , ";
        cout<<endl;
    }
} 

int min_idx(){
    int mini = INT_MAX;
    int min_idx = -1;
    for(int i=0; i<dist.size(); i++) if(!visited[i] and mini>dist[i]){  // O(v)
        mini = dist[i];
        min_idx = i;
    }
    return min_idx;  // return idx of minimum distance which has not visited yet
}

void shortest_path_without_pq(int src);
void shortest_path_with_pq(int src);
void print_shortest_path(int d);

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
    
    display();  
    
    // algorithm can be applied to both directed or undirected graph but the weights should not be nagative 

    int src;
    cout<<"Enter the source node: "<<endl;
    cin>>src;
    shortest_path_without_pq(src);
    cout<<"distance from source node to all other node: ";
    for(auto ele: dist) cout<<ele<<" ";
    cout<<endl;

    int d;
    cout<<"Enter destination to get the shortest path between: ";
    cin>>d;
    print_shortest_path(d);

        
    return 0;
}

void shortest_path_without_pq(int src){  // Dijkstar Algorithm
    visited.resize(v,false);
    dist.resize(v,INT_MAX);
    parent.resize(v,-1);  // To print the shortes path from source to the desired destination
    dist[src] = 0;  // distance to the source node will always be zero
    parent[src] = -1; // set initial parent to be -1
    int node = min_idx();  // except source all have distance INT_MAX
    while(node!=-1){ 
        visited[node] = 1;
        for(auto nghb : graph[node]){  // Relax the edges 
            int next = nghb.first;
            int weight = nghb.second;
            if(!visited[next] && dist[node] + weight < dist[next]){
                dist[next] = dist[node] + weight;
                parent[next] = node; // update the parent when weigh is updated
            }
        }
        node = min_idx();
    }
}

void shortest_path_with_pq(int src){
    visited.resize(v,false);
    dist.resize(v,INT_MAX);
    parent.resize(v,-1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  // min heap
    pq.push({0,src}); // distance to the source node is always zero {weight,node}
    dist[src] = 0;
    parent[src] = -1; // set initial parent to be -1
    while(!pq.empty()){
        int node = pq.top().second;  // now there is no need of traversal to find the minimum weighted node
        pq.pop();
        if(visited[node]) continue; 
        visited[node] = 1;
        for(auto neighbour : graph[node]){  // Release all the edges
            int temp = neighbour.first;
            int weight = neighbour.second;
            if(dist[temp] > dist[node]+weight){
                dist[temp] = dist[node]+weight;
                parent[temp] = node; 
                pq.push({dist[temp],temp});
            }
        }
    }
}

void print_shortest_path(int d){
    vector<int> path;
    if(parent[d] == -1) cout<<"No path exist between them"<<endl;
    else{
        int p = d;
        while(p!=-1){
            path.push_back(p);
            p = parent[p];
        }
    }
    reverse(path.begin(),path.end());
    for(auto ele : path) cout<<ele<<" ";
    cout<<endl;
}