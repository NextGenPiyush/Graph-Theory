#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int v; // no of vertices
int e; // no of edges

vector<bool> visited;

void add_edge(int src, int dest, int weight, bool bi_dir = true){
    graph[src][dest] = weight;
    if(bi_dir) graph[dest][src] = weight;
}

void display(){
    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++) cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}

void bfs(int src){   // Breadth first search Algorithm
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0; i<v; i++){
            if(graph[temp][i] != 0 and !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout<<endl;
}

void dfs(int src){  // Deapth first search Algorithm
    stack<int> st;
    st.push(src);
    visited[src] = 1;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        cout<<temp<<" ";
        for(int i=0; i<v; i++){
            if(graph[temp][i] != 0 and !visited[i]){
                st.push(i);
                visited[i] = 1;
            }
        }
    }
    cout<<endl;
}

void dfs_recursive(int src){  // using recursion
    cout<<src<<" ";
    visited[src] = 1;
    for(int j=0; j<v; j++) if(graph[src][j] != 0 and !visited[j]) dfs_recursive(j); 
}

int main(){

    cin>>v>>e;
    graph.resize(v,vector<int>());
    while(e--){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        add_edge(src,dest,weight);  // by default bi_dir == true
        // add_edge(src,dest,weight,false);
    }

    display();

    int src;
    cout<<"Enter source: ";
    cin>>src;

    visited.resize(v,0);
    bfs(src);

    fill(visited.begin(), visited.end(), false); // Reset for DFS
    dfs(src);
    // dfs_recursive(src);

    return 0;
}