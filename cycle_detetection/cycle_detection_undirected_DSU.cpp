#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x); // this method returns which group x belong to

bool Union(vector<int> &parent, vector<int> &rank, int a, int b);

int main(){
    
    int n,m;
    cout<<"enter no of elements: ";   cin>>n;
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++) parent[i] = i;
    vector<int> rank(n+1,0);
    
    cout<<"Enter queries: ";   cin>>m;  // no of edges 
    while(m--){
        int x,y;
        cin>>x>>y;
        bool b = Union(parent,rank,x,y);
        if(b == true){
            cout<<"Cycle detetcted"<<endl;
            break;
        }
    }
    
    return 0;
}

int find(vector<int> &parent, int x){
    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);  // path compression 
}

bool Union(vector<int> &parent, vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a == b) return true;  // a and b are the same set.. means parent of a and b are same 
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
    return false;
}