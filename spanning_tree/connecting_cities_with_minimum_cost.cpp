#include<bits/stdc++.h>
using namespace std;

//  coonnections[i] = {u,v,cost}
int minimumCost(int n, vector<vector<int>> &connections); // Leeetcode-1135

int main(){

    // return the minimum cost to connect all the n cities.    
    // if not possible to connect then return -1.
    // this problem is direct application of minimum spanning tree

    // first we need to find no of connected components
    // if connected component more than 1 then print -1 as it will not be possible to connect all nodes
    // else apply dsu to find the mimimum cost as we have done in kruskal algorithm


    return 0;
}