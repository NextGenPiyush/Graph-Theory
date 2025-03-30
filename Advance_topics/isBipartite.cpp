#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // adjacency List
int v; // no of vertices
int e; // no of edges

vector<int> color;

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

bool isBipartite();

bool bfs(int src);
bool dfs(int src);
bool dfs_recursive(int src);

int main(){
    
    cin>>v;
    graph.resize(v, list<int> ());
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
        // add_edge(s,d,false);
    }
    
    display();

    // try Leetcode-785
    
    return 0;
} 

bool isBipartite(){
    color.resize(v,-1);  
    // for(int i=0; i<graph.size(); i++) if(color[i]==-1 and !bfs(i)) return false;  
    // for(int i=0; i<graph.size(); i++) if(color[i]==-1 and !dfs(i)) return false;  
    for(int i=0; i<graph.size(); i++) if(color[i]==-1){
        color[i] = 0;
        if(!dfs_recursive(i)) return false;
    }  
    return true;       
}

bool bfs(int src){
    queue<int> q;
    q.push(src);
    color[src] = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto neighbour : graph[temp]){
            if(color[neighbour] == -1){
                // color[neighbour] = (color[temp]+1)%2;
                color[neighbour] = 1 - color[temp];  // we can also write this
                q.push(neighbour); 
            }
            else if(color[neighbour] == color[temp]) return false;
        }
    }
    return true;
}

bool dfs_recursive(int src){
    for(auto neighbour : graph[src]){
        if(color[neighbour] == -1){
            color[neighbour] = (color[src]+1)%2;
            if(!dfs_recursive(neighbour)) return false;
        }
        else if(color[neighbour] == color[src]) return false;
    }
    return true;
}

bool dfs(int src){
    stack<int> st;
    st.push(src);
    color[src] = 0;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        for(auto neighbour : graph[temp]){
            if(color[neighbour] == -1){
                color[neighbour] = 1 - color[temp];  // we can also write this
                st.push(neighbour); 
            }
            else if(color[neighbour] == color[temp]) return false;
        }
    }
    return true;
}




