#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> graph;
int v; // no of vertices
int e; // no of edges
vector<bool> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src][dest] = 1;
    if(bi_dir) graph[dest][src] = 1;
}

void display(){
    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++) cout<<graph[i][j]<<" ";
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
        for(int j=0; j<v; j++){
            if(graph[temp][j] == 1 and !visited[j]){
                q.push(j);
                visited[j] = 1;
            }
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
        for(int j=v-1; j>=0; j--){ // traverse in oppsite order to match recursive solution
        // for(int j=0; j<v; j++){
            if(graph[temp][j] and !visited[j]){
                st.push(j);
                visited[j] = 1;
            }
        }
    }
    cout<<endl;
}

void dfs_recursive(int src){
    cout<<src<<" ";
    visited[src] = 1;
    for(int j=0; j<v; j++) if(graph[src][j] and !visited[j]) dfs_recursive(j);  // using recursion
}

int main(){

    cin>>v>>e;
    graph.resize(v,vector<bool>(v,false));
    while(e--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest);  // by default bi_dir == true
        // add_edge(src,dest,false);
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