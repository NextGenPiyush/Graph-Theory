#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // adjacency List
int v; // no of vertices
int e; // no of edges
vector<bool> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src); // undirected graph
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(auto ele : graph[i]) cout<<ele<<" , ";
        cout<<endl;
    }
}

vector<int> toposort_dfs();
void dfs(int src, stack<int> &st);

vector<int> toposort_bfs();    // kahn's algorithm

int main(){
    
    cin>>v;
    graph.resize(v, list<int> ());
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        // add_edge(s,d);
        add_edge(s,d,false);  // directed graph
    }
    
    display();
    
    vector<int> ans = toposort_bfs();  // Toposort can be applied on directed acyclic graph 
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
} 

vector<int> toposort_dfs(){
    visited.resize(v,false);
    stack<int> st;
    for(int i=0; i<graph.size(); i++) if(!visited[i]) dfs(i,st);
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}
void dfs(int src, stack<int> &st){
    visited[src] = 1;
    for(auto neighbour : graph[src]) if(!visited[neighbour]) dfs(neighbour,st);
    st.push(src);
}

vector<int> toposort_bfs(){  // kahn's algorithm
    vector<int> ans;
    vector<int> indegree(v,0);

    for(int i=0; i<graph.size(); i++) for(auto neighbour : graph[i]) indegree[neighbour]++;

    queue<int> q; 
    for(int i=0; i<v; i++) if(indegree[i] == 0) q.push(i);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto neighbour : graph[temp]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }

    if(ans.size() != v) return {}; // it means there is a cycle in the DAG
    return ans;
}
