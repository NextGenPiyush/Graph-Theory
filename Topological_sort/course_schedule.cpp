#include<bits/stdc++.h>
using namespace std;

// prerequisite --> {course,prerequisite}
bool canFinish(int numCourses, vector<vector<int>> &prerequisite);  // Leetcode-207

int main(){
    
    
    
    

    return 0;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisite){
    vector<list<int>> graph(numCourses);
    for(auto ele : prerequisite) graph[ele[1]].push_back(ele[0]);
    // now apply khans algorithm 
}