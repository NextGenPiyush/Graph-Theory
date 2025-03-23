#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // adjacency list representation 
int v; // no of vertices
int e; // no of edges
vector<bool> visited;

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

bool cycle_detection_dfs(int src, int parent);
bool cycle_detection_dfs_recursion(int src, int parent);
bool cycle_detection_bfs(int src);

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

    for(int i=0; i<graph.size(); i++){  // cheking all the components of the graph
        if(!visited[i] and cycle_detection_dfs_recursion(i,-1)){
            cout<<"Cycle detected"<<endl;
            break;  
        }
    }
    
    return 0;
}

bool cycle_detection_dfs_recursion(int src, int parent){
    if(visited[src]) return true;  // it means we have reached to the visited node
    visited[src] = 1;  // visiting the node for the first time
    for(auto neighbour : graph[src]){
        if(parent == neighbour) continue;  // do not consider parent node
        // if(visited[neighbour]) return true; // this line can also be written in the base case
        if(cycle_detection_dfs_recursion(neighbour,src)) return true;
    }
    return false;
}

bool cycle_detection_dfs(int src){
    stack<pair<int,int>> st;
    st.push({src,-1});
    visited[src] = 1;
    while(!st.empty()){
        auto temp = st.top();
        st.pop();
        for(auto neighbour : graph[temp.first]){
            if(neighbour == temp.second) continue;
            if(visited[neighbour]) return true;  // cycle detected
            st.push({neighbour,temp.first});
            visited[neighbour] = 1;
        }
    }
    return false;
}

bool cycle_detection_bfs(int src){
    queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src] = 1;
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        for(auto neighbour : graph[temp.first]){
            if(neighbour == temp.second) continue;
            if(visited[neighbour]) return true;
            q.push({neighbour,temp.first});
            visited[neighbour] = 1;
        }
    }
    return false;
}
