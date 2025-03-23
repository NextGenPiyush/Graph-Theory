#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix);

int main(){
    
    // only applicable to directed graph no matter the weights are positive or negative        
    
    // if there is negative number in the diagonal of ans matrix then there will be negative cycle 
    
    
    return 0;
}

void shortest_distance(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(matrix[i][j]==-1) matrix[i][j] = INT_MAX;
    for(int k=0; k<n; k++){      // Time complexity: O(v^3)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
            }
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(matrix[i][j]==INT_MAX) matrix[i][j] = -1;
}

bool negative_cycle(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++) if(matrix[i][i]<0) return false;
    return true;
}

