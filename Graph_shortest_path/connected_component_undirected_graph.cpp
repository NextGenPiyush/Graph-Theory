#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // adjacency list representation 
int v; // no of vertices
int e; // no of edges

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

void dfs_recursive(int node, unordered_set<int> &visited);
void bfs(int curr, unordered_set<int> &visited);
void dfs(int curr, unordered_set<int> &visited);

int connected_components(){
    int result = 0;
    unordered_set<int> visited;
    for(int i=0; i<v; i++){ //O(v) run algorithm for each node
        if(!visited.count(i)){  
            result++;  // every time when new node is not visited means its a part of another component
            dfs_recursive(i, visited); //total O(v+E)
            // dfs(i, visited); 
            // bfs(i, visited); 
        }  
    }
    return result;
}

int main() {

    cin>>v;
    graph.resize(v, list<int> ());
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }

    cout<<"Number of connected components: "<<connected_components()<<endl;

    return 0;
}

void dfs_recursive(int node, unordered_set<int> &visited){
    visited.insert(node);
    for(int neighbor : graph[node]) if(visited.count(neighbor) == 0) dfs_recursive(neighbor, visited);
}

void bfs(int curr, unordered_set<int> &visited){
    queue<int> q;
    q.push(curr);
    visited.insert(curr);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto neighbour : graph[temp]) if(!visited.count(neighbour)){
            q.push(neighbour);
            visited.insert(neighbour);
        }
    }
}

void dfs(int curr, unordered_set<int> &visited){
    stack<int> st;
    st.push(curr);
    visited.insert(curr);
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        for(auto neighbour : graph[temp]) if(!visited.count(neighbour)){
            st.push(neighbour);
            visited.insert(neighbour);
        }
    }
}
