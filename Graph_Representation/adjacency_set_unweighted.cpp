#include<bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> graph;
int v; // no of vertices
int e; // no of edges

vector<bool> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].insert(dest);
    if(bi_dir) graph[dest].insert(src);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(auto ele : graph[i]) cout<<ele<<", ";
        cout<<endl;
    }
}

void bfs(int src){  // Breadth First Search Algorithm
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto neighbour : graph[temp]) if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour] = 1;
        }
    }
    cout<<endl;
}

void dfs(int src){  // Deapth First Search Algorithm
    stack<int> st;
    st.push(src);
    visited[src] = 1;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        cout<<temp<<" ";
        for(auto neighbour : graph[temp]) if(!visited[neighbour]){
            st.push(neighbour);
            visited[neighbour]  = 1;
        }
    }
    cout<<endl;
}

void dfs_recursive(int src){  
    cout<<src<<" ";
    visited[src] = 1;
    for(auto neighbour : graph[src]) if(!visited[neighbour]) dfs_recursive(neighbour);  // using recursion
}

int main(){

    cin>>v>>e;
    graph.resize(v, unordered_set<int> ());
    while(e--){
        int src, dest;
        cin>>src>>dest;
        add_edge(src,dest); // by default bi_dir = true
        // add_edge(src,dest,false);
    }

    display();

    int src;
    cout<<"Enter source node: "; 
    cin>>src;

    visited.resize(v,false);
    cout<<"Bfs traversal: ";  
    bfs(src);

    fill(visited.begin(), visited.end(), false); // Reset for DFS
    cout<<"Dfs traversal: ";
    dfs(src);
    // dfs_recursive(src);

    return 0;
}