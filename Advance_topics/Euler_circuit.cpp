#include<bits/stdc++.h>
using namespace std;

int v;
vector<int> degree;
vector<bool> visited;
vector<list<int>> graph;

void dfs(int src);
int IsEulerCircuit();

int main(){
    
    // Euler Circuit:  --> return 2
    // 1. all node must have even degree
    // 2. all zero degree noodes muat be connected with each other
    
    // Euler Path:  --> return 1
    // 1. zero od two nodes can have odd degree and remaining have even degree
    // 2. all non degree node must be connected
    
    // if it is neighter euler path or circuit  --> return 0
    
    
    return 0;
}

int IsEulerCircuit(){
    degree.resize(v,0);
    visited.resize(v,false);   // time complexity: O(v+e)
    int odd_degree;            // space complexity: O(v)
    for(int i=0; i<v; i++){
        degree[i] = graph[i].size();
        if(degree[i]%2) odd_degree++;
    }
    if(odd_degree!=0 and odd_degree!=2) return 0; // euler path and circuit is not possible
    for(int i=0; i<v; i++){
        if(degree[i]){  // apply dfs only one time for a node which have non zero degree
            dfs(i);
            break;
        }
    }
    for(int i=0; i<v; i++) if(degree[i] and !visited[i]) return 0; // if the non zero degree node is not visited then return 0 
    if(odd_degree == 0) return 2;  // euler circuit
    else return 1;  // euler path
}

void dfs(int src){
    visited[src] = 1;
    for(auto neighbour: graph[src]) if(!visited[neighbour]) dfs(neighbour);
}
