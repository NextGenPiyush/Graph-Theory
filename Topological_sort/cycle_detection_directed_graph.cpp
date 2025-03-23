#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // adjacency List
int v; // no of vertices
int e; // no of edges
vector<bool> path;
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

bool cycle_detection_dfs();
bool dfs(int src);

bool cycle_detection_bfs(); //khan's algorithm

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
    
    
    return 0;
} 

bool cycle_detection_dfs(){
    path.resize(v,false);
    visited.resize(v,false);    
    for(int i=0; i<graph.size(); i++) if(!visited[i] and dfs(i)) return true;
    return false;
}

bool dfs(int src){
    path[src] = 1;
    visited[src] = 1;
    for(auto neighbour : graph[src]){
        if(path[neighbour]) return true; // make sure this statement comes before the next statement
        // if(visited[neighbour]) continue;  // this statement cannot be come before the upper statement 
        // if(dfs(neighbour)) return true; 
        if(!visited[neighbour] and dfs(neighbour)) return true;  // we can also write like this 
    }
    path[src] = 0;  // Backtrack so that another time the node traversed again, otherwise it will detect cycle
    return false;
}

bool cycle_detection_bfs(){  // kahn's algorithm
    vector<int> ans;  // we can also maintain count instead of taking extra space for storing
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

    if(ans.size() != v) return true; // cycle detected
    return false;
}



// ******************************** cycle detection using topodfs *******************************
vector<int> visited, ans;
vector<vector<int>> graph;
bool hasCycle = false;

void dfs(int src, stack<int> &st, vector<int> &state) {
    state[src] = 1;  // Mark node as "in recursion stack"

    for (auto neighbour : graph[src]) {
        if (state[neighbour] == 1) { // Cycle detected
            hasCycle = true;
            return;
        }
        if (state[neighbour] == 0) { // Not visited
            dfs(neighbour, st, state);
        }
    }

    state[src] = 2;  // Mark node as "fully processed"
    st.push(src);
}

vector<int> toposort_dfs() {
    int v = graph.size();
    visited.assign(v, false);
    vector<int> state(v, 0); // 0 = unvisited, 1 = in recursion, 2 = processed
    stack<int> st;

    for (int i = 0; i < v; i++) {
        if (state[i] == 0) dfs(i, st, state);
    }

    if (hasCycle) return {};  // Return empty vector if cycle is detected

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

