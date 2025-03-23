#include<bits/stdc++.h>
using namespace std;

vector<list<pair<int,int>>> graph;
int v; // no of vertices
int e; // no of edges
vector<int> visited;
vector<int> dist;

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

void dfs(int src, stack<int> &st);
vector<int> toposort_dfs();
vector<int> shortest_distance(vector<int> ans);

int main(){

    cin>>v;
    cin>>e;
    graph.resize(v,list<pair<int,int>>());
    while(e--){
        int src, dest, weight;
        cin>>src>>dest>>weight;
        // add_edge(src,dest,weight);  // by default bi_dir == true;
        add_edge(src,dest,weight,false);  // it is a directed weighted graph 
    }

    display();  

    dist.resize(v,INT_MAX);
    for(auto ele : shortest_distance(toposort_dfs())) cout<<ele<<" ";

    // can we find shortest distance usnig simple bfs and dfs and if possible find the time complexity
    // can we get the exact path from source to desired destination 

    return 0;
}

void dfs(int src, stack<int> &st){
    visited[src] = 1;
    for(auto neighbour : graph[src]) if(!visited[neighbour.first]) dfs(neighbour.first,st);
    st.push(src);
}

vector<int> toposort_dfs(){
    visited.resize(v,false);
    stack<int> st;
    int src;
    cout<<"Enter source node: ";
    cin>>src;
    dfs(src,st);
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> shortest_distance(vector<int> ans){
    int src;
    cout<<"Enter the source node to find the shortest distance from source node to all the node: ";
    cin>>src;
    dist[src] = 0;  // distance to the sourec node will be 0 
    for(int i=0; i<ans.size(); i++){
        int temp = ans[i];  // relase all the edges of the node 
        for(auto nghb : graph[temp]) dist[nghb.first] = min(dist[nghb.first],dist[temp]+nghb.second);
    }
    return dist; 
}