#include<bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>> &isConnected);  // Leetcode-547

int main(){
    
    
    
    return 0;
}

int findCircleNum(vector<vector<int>> &isConnected){
    int n = isConnected.size();
    vector<list<int>> graph(n);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(isConnected[i][j] == 1) graph[i].push_back(j);
    // Now apply DSU to find the no of components 
}