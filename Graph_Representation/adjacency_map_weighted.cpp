#include<bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>> graph;
int v; // no of vertices
int e; // no of edges

vector<bool> visited;

void add_edge(int src, int dest, int weight, bool bi_dir = true){
    graph[src][dest] = weight;
    if(bi_dir) graph[dest][src] = weight;
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(auto ele : graph[i]) cout<<"{"<<ele.first<<","<<ele.second<<"} , ";
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
        for(auto neighbour : graph[temp]) if(!visited[neighbour.first]){
            q.push(neighbour.first);
            visited[neighbour.first] = 1;
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
        for(auto neighbour : graph[temp]) if(!visited[neighbour.first]){
            st.push(neighbour.first);
            visited[neighbour.first]  = 1;
        }
    }
    cout<<endl;
}

void dfs_recursive(int src){  // Using recursion 
    cout<<src<<" ";
    visited[src] = 1;
    for(auto neighbour : graph[src]) if(!visited[neighbour.first]) dfs_recursive(neighbour.first); 
}

int main(){

    cin>>v>>e;
    graph.resize(v,unordered_map<int,int> ());
    while(e--){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        add_edge(src,dest,weight); // by default bi_dir == true;
        // add_edge(src,dest,weight,false);
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