#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph; // adjacency List
int v; // no of vertices
int e; // no of edges
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true){
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

bool any_path(int src, int dest);
bool dfs(int curr, int end);
bool bfs(int curr, int end);
bool dfs_recursive(int curr, int end);

int main(){

    cin>>v;
    graph.resize(v, list<int> ());
    visited.clear(); 
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
        // add_edge(s,d,false);
    }

    display();

    int x,y;
    cin>>x>>y;
    if(any_path(x,y)) cout<<"Yes path exist from "<<x<<" to "<<y<<endl;
    else cout<<"No path exist between "<<x<<" and "<<y<<endl;

    return 0;
} 

bool any_path(int src, int dest){
    visited.clear();
    return bfs(src,dest);
    // return dfs(src,dest);
    // return dfs_recursive(src,dest);
}

bool dfs_recursive(int curr, int end){
    if(curr == end) return true;
    visited.insert(curr); // mark visited
    for(int neighbour : graph[curr]){
        if(!visited.count(neighbour)){ 
            bool result = dfs_recursive(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}

bool bfs(int curr, int end){
    if(curr == end) return true;
    queue<int> q;
    q.push(curr);
    visited.clear();
    visited.insert(curr);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto neighbour : graph[temp]) if(!visited.count(neighbour)){
            if(neighbour == end) return true;
            q.push(neighbour);
            visited.insert(neighbour);
        }
    }
    return false;
}

bool dfs(int curr, int end){
    if(curr == end) return true;
    stack<int> st;
    st.push(curr);
    visited.clear();
    visited.insert(curr);
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        for(auto neighbour : graph[temp]) if(!visited.count(neighbour)){
            if(neighbour == end) return true;
            st.push(neighbour);
            visited.insert(neighbour);
        }
    }
    return false;
}




